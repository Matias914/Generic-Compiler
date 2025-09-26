#include "utils/SymbolTable.h"
#include "utils/LiteralTable.h"
#include "utils/LogHandler.h"
#include "utils/ErrorHandler.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"

#include <iostream>

SymbolTable SYMBOL_TABLE;
LiteralTable LITERAL_TABLE;

LogHandler LOG_HANDLER;
ErrorHandler ERROR_HANDLER;

int main(const int argc, char* argv[])
{
    try
    {
        if (argc > 2)
            throw std::runtime_error("\nOnly one build file is supported");
        if (!LexicalAnalyzer::open(argv[1]))
            throw std::runtime_error("\nThe file could not be opened");

        yyparse();

        LOG_HANDLER.generateReport();

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
