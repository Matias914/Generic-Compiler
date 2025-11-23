#include "lexical-analyzer/components/SemanticActions.h"

#include <cmath>
#include <fstream>
#include <limits>

#include "lexical-analyzer/LexicalAnalyzer.h"
#include "lexical-analyzer/components/ReservedWordsTable.h"
#include "syntax-analyzer/components/Parser.h"
#include "utils/ErrorHandler.h"
#include "utils/resources/codes.h"

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;
extern ErrorHandler ERROR_HANDLER;

using namespace LexicalAnalyzer;

int SemanticActions::DoNothing(std::string& lexeme, const char character)
{
    return INVALID_TOKEN;
}

int SemanticActions::EndOfFile(std::string& lexeme, const char character)
{
    return YYEOF;
}

/* ------------------------- SEMANTIC ACTIONS ------------------------- */

int SemanticActions::SA1(std::string& lexeme, const char character)
{
    lexeme.clear();
    lexeme.reserve(32);
    lexeme += character;
    return INVALID_TOKEN;
}

int SemanticActions::SA2(std::string& lexeme, const char character)
{
    lexeme += character;
    return INVALID_TOKEN;
}

int SemanticActions::SA3(std::string& lexeme, const char character)
{
    lexeme += character;
    const unsigned int value = stoi(lexeme.substr(0, lexeme.size() - 2));
    if (value > std::numeric_limits<unsigned short>::max())
    {
        const Log log(ERROR, INTEGER_OUT_OF_RANGE, YYLINENO, {lexeme});
        ERROR_HANDLER.add(log);
        return INVALID_TOKEN;
    }
    const LiteralTable::TypeValue val = {.i = value};
    yylval.lref = LITERAL_TABLE.addAndGet(lexeme, UINT, val);
    if (yylval.lref == nullptr)
        throw std::runtime_error("SA3: failed to add new constant to table");
    return LITERAL_UINT;
}

int SemanticActions::SA4(std::string& lexeme, const char character)
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
    // Se usa long double para evitar problemas de precision
    long double ldvalue = stold(lexeme.substr(0, end_base));
    ldvalue *= std::pow(10.0L, exponent);
    if (ldvalue == 0.0L || (std::numeric_limits<float>::min() < ldvalue && ldvalue < std::numeric_limits<float>::max()))
    {
        const float value = static_cast<float>(ldvalue);
        const LiteralTable::TypeValue val = {.f = value};
        yylval.lref = LITERAL_TABLE.addAndGet(lexeme, FLOAT, val);
        if (yylval.lref == nullptr)
            throw std::runtime_error("SA4: failed to add new constant to table");
        return LITERAL_FLOAT;
    }
    const Log log(ERROR, FLOAT_OUT_OF_RANGE, YYLINENO, {lexeme});
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;

}

int SemanticActions::SA5(std::string& lexeme, const char character)
{
    lexeme += character;
    constexpr LiteralTable::TypeValue val = {.i = 0};
    yylval.lref = LITERAL_TABLE.addAndGet(lexeme, STRING, val);
    if (yylval.lref == nullptr)
        throw std::runtime_error("SA5: failed to add new constant to table");
    return LITERAL_STRING;
}

int SemanticActions::SA6(std::string& lexeme, const char character)
{
    SOURCE_FILE.unget();
    if (const int size = lexeme.size(); size > 20)
    {
        const std::string new_lexeme = lexeme.substr(0, 20);
        const Log log(WARNING, TRUNCATED_IDENTIFIER, YYLINENO, {lexeme, new_lexeme});
        ERROR_HANDLER.add(log);
        lexeme = std::move(new_lexeme);
    }
    yylval.sref = SYMBOL_TABLE.addAndGet(lexeme);
    return IDENTIFIER;
}

int SemanticActions::SA7(std::string& lexeme, const char character)
{
    YYLINENO++;
    return INVALID_TOKEN;
}

int SemanticActions::SA8(std::string& lexeme, const char character)
{
    lexeme += character;
    return character;
}

int SemanticActions::SA9(std::string& lexeme, const char character)
{
    lexeme += character;
    return OP_EQUAL;
}

int SemanticActions::SA10(std::string& lexeme, const char character)
{
    lexeme += character;
    return OP_NOT_EQUAL;
}

int SemanticActions::SA11(std::string& lexeme, const char character)
{
    lexeme += character;
    return OP_ASSIGN;
}

int SemanticActions::SA12(std::string& lexeme, const char character)
{
    lexeme += character;
    return OP_LE;
}

int SemanticActions::SA13(std::string& lexeme, const char character)
{
    lexeme += character;
    return OP_GE;
}

int SemanticActions::SA14(std::string& lexeme, const char character)
{
    lexeme += character;
    return OP_POINTER;
}

int SemanticActions::SA15(std::string& lexeme, const char character)
{
    SOURCE_FILE.unget();
    return lexeme.at(0);
}

int SemanticActions::SA16(std::string& lexeme, const char character)
{
    SOURCE_FILE.unget();
    const int token = ReservedWordsTable::token(lexeme);
    if (token == -1)
    {
        const Log log(ERROR, INVALID_RESERVED_WORD, YYLINENO, {lexeme});
        ERROR_HANDLER.add(log);
        return INVALID_RWORD;
    }
    return token;
}
