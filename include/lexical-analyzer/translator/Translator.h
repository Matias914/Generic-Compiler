#ifndef TPE_TRANSLATOR_H
#define TPE_TRANSLATOR_H

#define UPPER_CASE 0
#define LOWER_CASE 1
#define NUMBER     2
#define SPECIAL    3
#define OPERATOR   4
#define QUOTE      5
#define DOT        6
#define NUMERAL    7
#define PLUS       8
#define MINUS      9
#define BLANK      10
#define ENDLINE    11
#define OTHER      12

/*
 * @brief define como se traduce un char a entero
 *
 * Usando las macros definidas y a los valores ASCII de los char
 * es capaz de realizar la traduccion.
 *
 */
namespace Translator
{
    unsigned int translate(const char& c);
}

#endif //TPE_TRANSLATOR_H