#ifndef TPE_LEXICALANALYZER_H
#define TPE_LEXICALANALYZER_H

/*
 * @brief representa el analizador lexico de un compilador.
 *
 * Su rol es la tokenizacion. Identifica los lexemas de un
 * archivo dado como fuente con filename(). El analizador
 * sintactico le pide tokens a demanda con yylex().
 */
namespace LexicalAnalyzer
{
    extern int YYLINENO;
    extern std::ifstream SOURCE_FILE;

    int yylex();
    void filename(const char* filename);
}

#endif //TPE_LEXICALANALYZER_H