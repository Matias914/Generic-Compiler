#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "syntax-analyzer/components/parser.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "lexical-analyzer/components/semantic_actions.h"

#include <fstream>

extern ErrorHandler ERROR_HANDLER;

using namespace LexicalAnalyzer;

/*
 * @brief estas acciones semanticas fueron hechas para tratar
 * errores.
 *
 * Conceptualmente, son las acciones semanticas asociadas a las
 * transiciones que llevan al estado de error.
 */
int SemanticActions::UnexpectedCharTrap(std::string& lexeme, const char& character)
{
    Log log;
    log.type = ERROR;
    log.line = YYLINENO;
    log.code = UNEXPECTED_CHARACTER;
    log.content = {std::string(1, character)};
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedUITrap(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    Log log;
    log.type = ERROR;
    log.line = YYLINENO;
    log.code = INTEGER_WITHOUT_SUFFIX;
    log.content = {lexeme};
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedSignTrap(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    Log log;
    log.type = ERROR;
    log.line = YYLINENO;
    log.code = EXPONENT_WITHOUT_SIGN;
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedNumberTrap(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    Log log;
    log.type = ERROR;
    log.line = YYLINENO;
    log.code = FLOAT_WITHOUT_NUMBERS;
    log.content.push_back(lexeme);
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedNoEndlTrap(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    Log log;
    log.type = ERROR;
    log.line = YYLINENO;
    log.code = STRING_LITERAL_WITH_ENDL;
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedQuoteTrap(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    Log log;
    log.type = ERROR;
    log.line = YYLINENO;
    log.code = UNCLOSED_STRING_LITERAL;
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedNumeralTrap(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    Log log;
    log.type = ERROR;
    log.line = YYLINENO;
    log.code = UNOPENED_COMMENT;
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedCommentEndTrap(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    Log log;
    log.type = ERROR;
    log.line = YYLINENO;
    log.code = UNCLOSED_COMMENT;
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}

int SemanticActions::ExpectedEqualsTrap(std::string& lexeme, const char& character)
{
    SOURCE_FILE.unget();
    Log log;
    log.type = ERROR;
    log.line = YYLINENO;
    log.code = INVALID_COLON;
    ERROR_HANDLER.add(log);
    return INVALID_TOKEN;
}