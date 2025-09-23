#include "utils/ErrorHandler.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "lexical-analyzer/components/reserved_words.h"
#include "lexical-analyzer/components/semantic_actions.h"

#include <fstream>
#include <limits>
#include <cmath>

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;
extern ErrorHandler ERROR_HANDLER;

using namespace LexicalAnalyzer;

LexemeData SemanticActions::DoNothing(std::string& lexeme, const char& character)
{
    return {INVALID_TOKEN, nullptr, nullptr};
}

LexemeData SemanticActions::EndOfFile(std::string& lexeme, const char& character)
{
    return {YYEOF, nullptr, nullptr};
}

/* ------------------------- SEMANTIC ACTIONS ------------------------- */

LexemeData SemanticActions::SA1(std::string& lexeme, const char& character)
{
    lexeme.clear();
    lexeme.reserve(32);
    lexeme += character;
    return {INVALID_TOKEN, nullptr, nullptr};
}

LexemeData SemanticActions::SA2(std::string& lexeme, const char& character)
{
    lexeme += character;
    return {INVALID_TOKEN, nullptr, nullptr};
}

LexemeData SemanticActions::SA3(std::string& lexeme, const char& character)
{
    lexeme += character;
    const unsigned int value = stoi(lexeme.substr(0, lexeme.size() - 2));
    if (value > std::numeric_limits<unsigned short>::max())
    {
        ErrorHandler::Log log;
        log.type = ERROR;
        log.line = YYLINENO;
        log.code = INTEGER_OUT_OF_RANGE;
        log.content = {lexeme};
        ERROR_HANDLER.add(log);
        return {INVALID_TOKEN, nullptr, nullptr};
    }
    const LiteralTable::Type val = {.i = value};
    return{
        INTEGER_LITERAL,
        nullptr,
        LITERAL_TABLE.add(lexeme, TYPE_UI, val)
    };
}

LexemeData SemanticActions::SA4(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    const int end = lexeme.size();
    int end_base = end;
    int exponent = 0;
    for (int i = 0; i < end && end_base == end; i++)
        if (lexeme[i] == 'F')
        {
            end_base = i;
            exponent = stoi(lexeme.substr(i + 2, end - i - 2));
            if (lexeme[i + 1] == '-')
                exponent = -exponent;
        }
    float value = stof(lexeme.substr(0, end_base));
    value *= std::pow(10, exponent);
    value = std::abs(value);
    if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
    {
        ErrorHandler::Log log;
        log.type = ERROR;
        log.line = YYLINENO;
        log.code = FLOAT_OUT_OF_RANGE;
        log.content = {lexeme};
        ERROR_HANDLER.add(log);
        return {INVALID_TOKEN, nullptr, nullptr};
    }
    const LiteralTable::Type val = {.f = value};
    return {
        FLOAT_LITERAL,
        nullptr,
        LITERAL_TABLE.add(lexeme, TYPE_FLOAT, val)
    };
}

LexemeData SemanticActions::SA5(std::string& lexeme, const char& character)
{
    lexeme += character;
    constexpr LiteralTable::Type val = {.i = 0};
    return {
        STRING_LITERAL,
        nullptr,
        LITERAL_TABLE.add(lexeme, TYPE_STRING, val)
    };
}

LexemeData SemanticActions::SA6(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    const int size = lexeme.size();
    if (size > 20)
    {
        const std::string new_lexeme = lexeme.substr(0, 20);
        ErrorHandler::Log log;
        log.type = WARNING;
        log.line = YYLINENO;
        log.code = TRUNCATED_VARIABLE;
        log.content = {lexeme, new_lexeme};
        ERROR_HANDLER.add(log);
        lexeme = new_lexeme;
    }
    return {
        IDENTIFIER,
        SYMBOL_TABLE.add(lexeme),
        nullptr
    };
}

LexemeData SemanticActions::SA7(std::string& lexeme, const char& character)
{
    YYLINENO++;
    return {INVALID_TOKEN, nullptr, nullptr};
}

LexemeData SemanticActions::SA8(std::string& lexeme, const char& character)
{
    return {character,nullptr, nullptr};
}

LexemeData SemanticActions::SA9(std::string& lexeme, const char& character)
{
    return {EQUAL_OP,nullptr, nullptr};
}

LexemeData SemanticActions::SA10(std::string& lexeme, const char& character)
{
    return {NOT_EQUAL_OP,nullptr, nullptr};
}

LexemeData SemanticActions::SA11(std::string& lexeme, const char& character)
{
    return {ASSIGN_OP,nullptr, nullptr};
}

LexemeData SemanticActions::SA12(std::string& lexeme, const char& character)
{
    return {LE_OP,nullptr, nullptr};
}

LexemeData SemanticActions::SA13(std::string& lexeme, const char& character)
{
    return {GE_OP,nullptr, nullptr};
}

LexemeData SemanticActions::SA14(std::string& lexeme, const char& character)
{
    return {POINTER_OP,nullptr, nullptr};
}

LexemeData SemanticActions::SA15(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    return {'=',nullptr, nullptr};
}

LexemeData SemanticActions::SA16(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    return {'<',nullptr, nullptr};
}

LexemeData SemanticActions::SA17(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    return {'>',nullptr, nullptr};
}

LexemeData SemanticActions::SA18(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    return {'-',nullptr, nullptr};
}

LexemeData SemanticActions::SA19(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    const int token = ReservedWordsTable::token(lexeme);
    if (token == -1)
    {
        ErrorHandler::Log log;
        log.type = ERROR;
        log.line = YYLINENO;
        log.code = INVALID_RESERVED_WORD;
        log.content = {lexeme};
        ERROR_HANDLER.add(log);
        return {INVALID_TOKEN, nullptr, nullptr};
    }
    return {token,nullptr, nullptr};
}

LexemeData SemanticActions::SA20(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    return {'.',nullptr, nullptr};
}

