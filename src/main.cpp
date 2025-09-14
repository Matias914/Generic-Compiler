#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"

#include <iostream>

int main(const int argc, char* argv[])
{
    try
    {
        if (argc > 2)
            throw std::runtime_error("\nSolo se admite un archivo de compilacion");
        std::cout << argv[0] << "\n";
        LexicalAnalyzer::filename(argv[1]);
        yyparse();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}