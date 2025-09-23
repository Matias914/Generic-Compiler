#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/components/reserved_words.h"

using namespace LexicalAnalyzer;

int ReservedWordsTable::token(const std::string& word)
{
    if (word == "if")
        return IF;
    if (word == "else")
        return ELSE;
    if (word == "endif")
        return ENDIF;
    if (word == "do")
        return DO;
    if (word == "while")
        return WHILE;
    if (word == "return")
        return RETURN;
    if (word == "print")
        return PRINT;
    if (word == "uint")
        return UINT;
    if (word == "float")
        return FLOAT;
    if (word == "cr")
        return CR;
    if (word == "trunc")
        return TRUNC;
    return -1;
}