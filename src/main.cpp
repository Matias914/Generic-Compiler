#include "utils/SymbolTable.h"
#include "utils/LiteralTable.h"
#include "utils/ReportHandler.h"
#include "utils/ErrorHandler.h"
#include "syntax-analyzer/syntax_analyzer.h"
#include "lexical-analyzer/lexical_analyzer.h"

#include <iostream>
#include <cstring>

bool VERBOSE_OPTION = false;

SymbolTable SYMBOL_TABLE;
LiteralTable LITERAL_TABLE;
ErrorHandler ERROR_HANDLER;
ReportHandler REPORT_HANDLER;

int main(const int argc, char* argv[])
{
    try
    {
        if (argc == 1)
            throw std::runtime_error("\nNo arguments were found");
        if (argc >= 5)
            throw std::runtime_error("\nToo many arguments were passed!");

        // Parsing Arguments
        auto target = "";
        bool infile, outfile = false;
        for (int i = 1; i < argc; ++i)
            if (!std::strcmp(argv[i], "-v"))
                VERBOSE_OPTION = true;
            else if (!outfile && VERBOSE_OPTION)
            {
                REPORT_HANDLER = ReportHandler(argv[i]);
                if (!REPORT_HANDLER.validOutput())
                    throw std::runtime_error("\nCouldn't generate report");
                outfile = true;
            }
            else if (!infile)
            {
                target = argv[i];
                infile = true;
            }
            else
                throw std::runtime_error("\nMore than one file was given");

        if (!infile)
            throw std::runtime_error("\nNo file was given");

        if (!LexicalAnalyzer::open(target))
            throw std::runtime_error("\nThe file could not be opened");

        // Calls Parser
        SyntaxAnalyzer::yyparsewrapper();
        if (VERBOSE_OPTION)
            REPORT_HANDLER.generateReport();

        // Compilation Errors Handling
        std::string mssg = ERROR_HANDLER.getLogs();
        if (ERROR_HANDLER.errorCount() != 0)
        {
            mssg = "\nCompilation Failed!. Errors were found:\n" + mssg;
            throw std::runtime_error(mssg);
        }
        if (ERROR_HANDLER.warningCount() != 0)
        {
            mssg = "\nCompiled with warnings:\n" + mssg;
            std::cerr << mssg << std::endl;
        }
        else
            std::cout << "\nCompilation Succesful!" << std::endl;
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
