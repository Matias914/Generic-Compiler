#include "lexical-analyzer/components/reserved_words.h"

#include "syntax-analyzer/components/parser.h"

using namespace LexicalAnalyzer;

int ReservedWordsTable::token(const std::string& word)
{
    if (word == "if")
        return WORD_IF;
    if (word == "else")
        return WORD_ELSE;
    if (word == "endif")
        return WORD_ENDIF;
    if (word == "do")
        return WORD_DO;
    if (word == "while")
        return WORD_WHILE;
    if (word == "return")
        return WORD_RETURN;
    if (word == "print")
        return WORD_PRINT;
    if (word == "uint")
        return WORD_UINT;
    if (word == "float")
        return WORD_FLOAT;
    if (word == "cr")
        return WORD_CR;
    if (word == "trunc")
        return WORD_TRUNC;
    return -1;
}