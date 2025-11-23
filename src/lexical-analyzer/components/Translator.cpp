#include "lexical-analyzer/components/Translator.h"

#include "lexical-analyzer/components/lexical_tokens.h"

using namespace LexicalAnalyzer;

unsigned int Translator::translate(const char c)
{
    const unsigned int asc = static_cast<unsigned int>(c);
    if (asc == 70)
        return F;
    if (asc == 73)
        return I;
    if (asc == 85)
        return U;
    if (asc == 37)
        return PERCENTAGE;
    if (asc == 34)
        return QUOTE;
    if (asc == 46)
        return DOT;
    if (asc == 61)
        return EQUALS;
    if (asc == 33)
        return EXCLAMATION;
    if (asc == 62)
        return GREATER;
    if (asc == 60)
        return LESS;
    if (asc == 35)
        return NUMERAL;
    if (asc == 58)
        return COLON;
    if (asc == 45)
        return MINUS;
    if (asc == 43)
        return PLUS;
    if (asc == 9 || asc == 32)
        return BLANK;
    if (asc == 10)
        return ENDLINE;
    if (asc >= 65 && asc <= 90)
        return UPPER_CASE;
    if (asc >= 97 && asc <= 122)
        return LOWER_CASE;
    if (asc >= 48 && asc <= 57)
        return NUMBER;
    if (asc >= 40 && asc <= 42)
        return SPECIAL; // Special Character: ( ) *
    if (asc == 44 || asc == 47 || asc == 59 || asc == 123 || asc == 125)
        return SPECIAL; // Also Special Character: , /  ; {  }
    return OTHER;
}