#include "utils/SymbolTable.h"
#include "utils/LiteralTable.h"
#include "utils/LogHandler.h"
#include "utils/ErrorHandler.h"
#include "syntax-analyzer/syntax_analyzer.h"
#include "lexical-analyzer/lexical_analyzer.h"

#include <iostream>
#include <cstring>

bool VERBOSE_OPTION = false;

SymbolTable SYMBOL_TABLE;
LiteralTable LITERAL_TABLE;

LogHandler LOG_HANDLER("../examples/output.txt");
ErrorHandler ERROR_HANDLER;

int main(const int argc, char* argv[])
{
    try
    {
        if (argc == 0)
            throw std::runtime_error("\nNo arguments were found");
        if (argc > 3)
            throw std::runtime_error("\nToo many arguments were passed!");

        auto file = "";
        bool file_given = false;
        for (int i = 1; i < argc; ++i)
            if (!std::strcmp(argv[i], "-v"))
                VERBOSE_OPTION = true;
            else if (!file_given)
            {
                file = argv[i];
                file_given = true;
            }
            else
                throw std::runtime_error("\nMore than one file was given");

        if (!file_given)
            throw std::runtime_error("\nNo file was given");

        if (!LexicalAnalyzer::open(file))
            throw std::runtime_error("\nThe file could not be opened");

        if (VERBOSE_OPTION)
        {
            if (!LOG_HANDLER.validOutput())
                throw std::runtime_error("\nCouldn't generate report");
            SyntaxAnalyzer::yyparsewrapper();
            LOG_HANDLER.generateReport();
        } else
            SyntaxAnalyzer::yyparsewrapper();

        // Compilation Errors Handling (non fatal)
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
