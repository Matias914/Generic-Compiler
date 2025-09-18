#ifndef TPE_TRANSLATOR_H
#define TPE_TRANSLATOR_H

/*
 * @brief define como se traduce un caracter a entero.
 *
 * Usando las macros definidas y los valores ASCII de los char
 * es capaz de realizar la traduccion.
 */
namespace LexicalAnalyzer
{
    namespace Translator
    {
        unsigned int translate(const char& c);
    }
}

#endif //TPE_TRANSLATOR_H