#ifndef TPE_LEXICAL_ANALYZER_TRANSLATOR_H
#define TPE_LEXICAL_ANALYZER_TRANSLATOR_H

/*
 * @brief define como se traduce un caracter a entero.
 *
 * Usando las macros definidas y los valores ASCII de los char
 * es capaz de realizar la traduccion.
 */
namespace LexicalAnalyzer::Translator
{
    unsigned int translate(const char& c);
}

#endif //TPE_LEXICAL_ANALYZER_TRANSLATOR_H
