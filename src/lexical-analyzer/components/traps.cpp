#include "utils/ErrorHandler.h"
#include "utils/resources/codes.h"
#include "syntax-analyzer/components/parser.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "lexical-analyzer/components/semantic_actions.h"

#include <fstream>

extern ErrorHandler ERROR_HANDLER;

using namespace LexicalAnalyzer;

int SemanticActions::UnexpectedCharTrap(std::string& lexeme, const char character)
{
    const Log log(ERROR, UNEXPECTED_CHARACTER, YYLINENO, {std::string(1, character)});
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedUITrap(std::string& lexeme, const char character)
{
    SOURCE_FILE.unget();
    const Log log(ERROR, INTEGER_WITHOUT_SUFFIX, YYLINENO, {lexeme});
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedSignTrap(std::string& lexeme, const char character)
{
    SOURCE_FILE.unget();
    const Log log(ERROR, EXPONENT_WITHOUT_SIGN, YYLINENO);
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedNumberTrap(std::string& lexeme, const char character)
{
    SOURCE_FILE.unget();
    const Log log(ERROR, FLOAT_WITHOUT_NUMBERS, YYLINENO, {lexeme});
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedNoEndlTrap(std::string& lexeme, const char character)
{
    SOURCE_FILE.unget();
    const Log log(ERROR, STRING_LITERAL_WITH_ENDL, YYLINENO);
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedQuoteTrap(std::string& lexeme, const char character)
{
    SOURCE_FILE.unget();
    const Log log(ERROR, UNCLOSED_STRING_LITERAL, YYLINENO);
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedNumeralTrap(std::string& lexeme, const char character)
{
    lexeme = "#";
    SOURCE_FILE.unget();
    const Log log(ERROR, UNOPENED_COMMENT, YYLINENO);
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedCommentEndTrap(std::string& lexeme, const char character)
{
    SOURCE_FILE.unget();
    const Log log(ERROR, UNCLOSED_COMMENT, YYLINENO);
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedEqualsTrap(std::string& lexeme, const char character)
{
    SOURCE_FILE.unget();
    const Log log(ERROR, INVALID_COLON, YYLINENO);
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}