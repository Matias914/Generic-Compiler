#include "utils/ErrorHandler.h"
#include "utils/LiteralTable.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/semantic_actions.h"

#include <iostream>

extern ErrorHandler ERROR_HANDLER;
extern LiteralTable LITERAL_TABLE;

using namespace SyntaxAnalyzer;

void SemanticActions::announceSyntaxError()
{
    ErrorHandler::Log l;
    l.type = ERROR;
    l.code = SYNTAX_ERROR;
    l.line = LexicalAnalyzer::YYLINENO;
    ERROR_HANDLER.add(l);
    if (yylval.symbol_reference != nullptr)
        std::cout << yylval.symbol_reference->symbol << std::endl;
}

void SemanticActions::specifySemicolonError()
{
    ErrorHandler::Log l;
    l.type = ERROR;
    l.code = STATEMENT_WITHOUT_SEMICOLON;
    l.line = LexicalAnalyzer::YYLINENO;
    ERROR_HANDLER.updateLatestLog(l);
    std::cout << yylval.symbol_reference->symbol << std::endl;
}

void SemanticActions::addNegativeFloatToTable()
{
    const std::string new_constant = "-" + yylval.constant_reference->constant;
    const LiteralTable::Type value = { .f = -yylval.constant_reference->value.f};
    LITERAL_TABLE.decrementReferences(yylval.constant_reference->constant);
    yylval.constant_reference = LITERAL_TABLE.addAndGet(new_constant, TYPE_FLOAT, value);
}

