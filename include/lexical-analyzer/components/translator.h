#ifndef TPE_TRANSLATOR_H
#define TPE_TRANSLATOR_H

#define UPPER_CASE   0
#define F            1
#define I            2
#define U            3
#define LOWER_CASE   4
#define NUMBER       5
#define SPECIAL      6
#define PERCENTAGE   7
#define QUOTE        8
#define DOT          9
#define EQUALS      10
#define EXCLAMATION 11
#define GREATER     12
#define LESS        13
#define NUMERAL     14
#define COLON       15
#define MINUS       16
#define PLUS        17
#define BLANK       18
#define ENDLINE     19
#define OTHER       20

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