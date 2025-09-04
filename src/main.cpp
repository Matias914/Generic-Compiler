#include <iostream>

#include "tables/SymbolTable.h"
#include "lexical-analyzer/LexicalAnalyzer.h"

SymbolTable SYMBOL_TABLE = SymbolTable();

int main(const int argc, char* argv[])
{
    try
    {
        if (argc > 2)
            throw std::runtime_error("\nSolo se admite un archivo de compilacion");
        std::cout << argv[0] << "\n";
        // Logica del main
        LexicalAnalyzer::setFileName(argv[1]);
        LexicalAnalyzer::yylex();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}