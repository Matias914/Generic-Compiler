#include "code-generator/code-generator.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/syntax_analyzer.h"
#include "utils/ErrorHandler.h"
#include "utils/LiteralTable.h"
#include "utils/ReportHandler.h"
#include "utils/SymbolTable.h"
#include "cxxopts.hpp"

#include <iostream>
#include <filesystem>

bool VERBOSE_OPTION = false;

SymbolTable   SYMBOL_TABLE;
LiteralTable  LITERAL_TABLE;
ErrorHandler  ERROR_HANDLER;
ReportHandler REPORT_HANDLER;

#define ERROR_MSG(X) "\n[[ ERROR ]]: " X "."

int main(const int argc, char* argv[])
{
    try
    {
        cxxopts::Options options (
            argv[0],
            " - A compiler for a custom language to WebAssembly"
        );

        options.add_options()
        ("i,input", "Input source file", cxxopts::value<std::string>())
        ("o,output", "Output WAT file path", cxxopts::value<std::string>())
        ("r,report", "Report output file path", cxxopts::value<std::string>())
        ("v,verbose", "Enable report generation", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print this usage help message");
        
        options.parse_positional({"input"});
        const auto result = options.parse(argc, argv);

        if (result.count("help"))
        {
            std::cout << options.help() << std::endl;
            return EXIT_SUCCESS;
        }

        VERBOSE_OPTION = result["verbose"].as<bool>();
        if (VERBOSE_OPTION && result.count("report"))
        {
            REPORT_HANDLER.setOutput(result["report"].as<std::string>());
            if (!REPORT_HANDLER.validOutput())
            {
                throw std::runtime_error(ERROR_MSG("Couldn't generate report file at the specified path"));
            }
        }

        if (!result.count("input"))
        {
            throw std::runtime_error(ERROR_MSG("No input file was provided to compile"));
        }

        const auto input_file = result["input"].as<std::string>();
        if (!LexicalAnalyzer::open(input_file))
        {
            throw std::runtime_error(ERROR_MSG("The file '" + input_file + "' could not be opened"));
        }

        // Llamada al Analizador Sintáctico
        SyntaxAnalyzer::analyze();
        if (VERBOSE_OPTION && result.count("report"))
        {
            REPORT_HANDLER.generateReport();
        }

        // Manejo de Errores de Compilación
        std::string mssg = ERROR_HANDLER.getLogs();
        if (ERROR_HANDLER.errorCount() != 0)
        {
            mssg = "\nCompilation failed. Errors were found:\n" + mssg;
            throw std::runtime_error(mssg);
        }

        // Generación del código si no hay errores
        std::string output_file;
        if (result.count("output")) {
            output_file = result["output"].as<std::string>();
        } else {
            output_file = std::filesystem::path(input_file).stem().string() + ".wat";
        }
        CodeGenerator::generateWebAssembly(output_file);

        if (ERROR_HANDLER.warningCount() != 0)
        {
            mssg = "\nCompiled with warnings:\n" + mssg;
            std::cerr << mssg << std::endl;
        }
        else
        {
            std::cout << "\nCompilation successful! File generated at: " << output_file << std::endl;
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
