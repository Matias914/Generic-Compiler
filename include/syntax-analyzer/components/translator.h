#ifndef GC_SYNTAX_ANALYZER_TRANSLATOR_H
#define GC_SYNTAX_ANALYZER_TRANSLATOR_H

#include <string>

/*
 * @brief define como se traduce un token a string.
 *
 * Usando las macros definidas por el parser y los valores ASCII de los char
 * es capaz de realizar la traduccion.
 */
namespace SyntaxAnalyzer::Translator
{
    std::string translate(const int& token);
}

#endif //GC_SYNTAX_ANALYZER_TRANSLATOR_H
