#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/parser.h"
#include "lexical-analyzer/components/reserved_words.h"
#include "lexical-analyzer/components/semantic_actions.h"

#include <fstream>
#include <limits>
#include <cmath>

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;
extern ErrorHandler ERROR_HANDLER;

using namespace LexicalAnalyzer;

int SemanticActions::DoNothing(std::string& lexeme, const char& character)
{
    return INVALID_TOKEN;
}

int SemanticActions::EndOfFile(std::string& lexeme, const char& character)
{
    return YYEOF;
}

/* ------------------------- SEMANTIC ACTIONS ------------------------- */

int SemanticActions::SA1(std::string& lexeme, const char& character)
{
    lexeme.clear();
    lexeme.reserve(32);
    lexeme += character;
    return INVALID_TOKEN;
}

int SemanticActions::SA2(std::string& lexeme, const char& character)
{
    lexeme += character;
    return INVALID_TOKEN;
}

int SemanticActions::SA3(std::string& lexeme, const char& character)
{
    lexeme += character;
    const unsigned int value = stoi(lexeme.substr(0, lexeme.size() - 2));
    if (value > std::numeric_limits<unsigned short>::max())
    {
        Log log;
        log.type = ERROR;
        log.line = YYLINENO;
        log.code = INTEGER_OUT_OF_RANGE;
        log.content = {lexeme};
        ERROR_HANDLER.add(log);
        return INVALID_TOKEN;
    }
    const LiteralTable::Type val = {.i = value};
    yylval.lref = LITERAL_TABLE.addAndGet(lexeme, UINTEGER_LITERAL, val);
    if (yylval.lref == nullptr)
        throw std::runtime_error("SA3: failed to add new constant to table");
    return UINTEGER_LITERAL;
}

int SemanticActions::SA4(std::string& lexeme, const char& character)
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
    if (ldvalue > std::numeric_limits<float>::max() || ldvalue < std::numeric_limits<float>::min())
    {
        Log log;
        log.type = ERROR;
        log.line = YYLINENO;
        log.code = FLOAT_OUT_OF_RANGE;
        log.content = {lexeme};
        ERROR_HANDLER.add(log);
        return INVALID_TOKEN;
    }
    const float value = static_cast<float>(ldvalue);
    const LiteralTable::Type val = {.f = value};
    yylval.lref = LITERAL_TABLE.addAndGet(lexeme, FLOAT_LITERAL, val);
    if (yylval.lref == nullptr)
        throw std::runtime_error("SA4: failed to add new constant to table");
    return FLOAT_LITERAL;
}

int SemanticActions::SA5(std::string& lexeme, const char& character)
{
    lexeme += character;
    constexpr LiteralTable::Type val = {.i = 0};
    yylval.lref = LITERAL_TABLE.addAndGet(lexeme, STRING_LITERAL, val);
    if (yylval.lref == nullptr)
        throw std::runtime_error("SA5: failed to add new constant to table");
    return STRING_LITERAL;
}

int SemanticActions::SA6(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    if (const int size = lexeme.size(); size > 20)
    {
        const std::string new_lexeme = lexeme.substr(0, 20);
        Log log;
        log.type = WARNING;
        log.line = YYLINENO;
        log.code = TRUNCATED_VARIABLE;
        log.content = {lexeme, new_lexeme};
        ERROR_HANDLER.add(log);
        lexeme = new_lexeme;
    }
    yylval.sref = SYMBOL_TABLE.addAndGet(lexeme);
    return IDENTIFIER;
}

int SemanticActions::SA7(std::string& lexeme, const char& character)
{
    YYLINENO++;
    return INVALID_TOKEN;
}

int SemanticActions::SA8(std::string& lexeme, const char& character)
{
    lexeme += character;
    return character;
}

int SemanticActions::SA9(std::string& lexeme, const char& character)
{
    lexeme += character;
    return EQUAL_OP;
}

int SemanticActions::SA10(std::string& lexeme, const char& character)
{
    lexeme += character;
    return NOT_EQUAL_OP;
}

int SemanticActions::SA11(std::string& lexeme, const char& character)
{
    lexeme += character;
    return ASSIGN_OP;
}

int SemanticActions::SA12(std::string& lexeme, const char& character)
{
    lexeme += character;
    return LE_OP;
}

int SemanticActions::SA13(std::string& lexeme, const char& character)
{
    lexeme += character;
    return GE_OP;
}

int SemanticActions::SA14(std::string& lexeme, const char& character)
{
    lexeme += character;
    return POINTER_OP;
}

int SemanticActions::SA15(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    return lexeme.at(0);
}

int SemanticActions::SA16(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    const int token = ReservedWordsTable::token(lexeme);
    if (token == -1)
    {
        Log log;
        log.type = ERROR;
        log.line = YYLINENO;
        log.code = INVALID_RESERVED_WORD;
        log.content = {lexeme};
        ERROR_HANDLER.add(log);
        return INVALID_TOKEN;
    }
    return token;
}
