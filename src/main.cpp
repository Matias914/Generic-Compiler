#include <iostream>

#include "files/FileReader.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "tables/SymbolTable.h"

FileReader GFILE = FileReader();
SymbolTable SYMBOLS_TABLE = SymbolTable();

int main(const int argc, char* argv[])
{
    try
    {
        if (argc > 2)
            throw std::runtime_error("\nSolo se admite un archivo de compilacion");
        std::cout << argv[0] << "\n";
        GFILE.set(argv[1]);
        // Logica del main
        LexicalAnalyzer::yylex();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}