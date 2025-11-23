#ifndef GC_LEXICAL_ANALYZER_H
#define GC_LEXICAL_ANALYZER_H

#include <fstream>

/*
 * @brief representa el analizador lexico de un compilador.
 *
 * Su rol es la tokenizacion. Identifica los lexemas de un
 * archivo dado como fuente con open(). El analizador
 * sintactico le pide tokens a demanda con yylex().
 */
namespace LexicalAnalyzer
{
    extern unsigned int YYLINENO;
    extern std::ifstream SOURCE_FILE;

    int yylex();
    bool open(const std::string& filename);
}

#endif //GC_LEXICAL_ANALYZER_H