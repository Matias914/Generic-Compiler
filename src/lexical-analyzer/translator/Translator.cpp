#include "lexical-analyzer/translator/Translator.h"

// Utiliza los valores ASCII para determinar en que grupo se
// encuentra cada char. Cada grupo es un MACRO.
unsigned int Translator::translate(const char& c)
{
    const unsigned int asc = static_cast<unsigned int>(c);
    if (asc >= 65 && asc <= 90)
        return UPPER_CASE;
    if (asc >= 97 && asc <= 122)
        return LOWER_CASE;
    if (asc >= 48 && asc <= 57)
        return NUMBER;
    // Special Character: '( ) *'
    if (asc >= 40 && asc <= 42)
        return SPECIAL;
    // Also Special Character: '! % /  ;  _  {  }'
    if (asc == 33 || asc == 37 || asc == 47 || asc == 59 || asc == 95 || asc == 123 || asc == 125)
        return SPECIAL;
    if (asc >= 58  && asc <= 62)
        return OPERATOR;
    if (asc == 9 || asc == 32)
        return BLANK;
    if (asc == 10)
        return ENDLINE;
    if (asc == 34)
        return QUOTE;
    if (asc == 35)
        return NUMERAL;
    if (asc == 43)
        return PLUS;
    if (asc == 45)
        return MINUS;
    if (asc == 46)
        return DOT;
    return OTHER;
}