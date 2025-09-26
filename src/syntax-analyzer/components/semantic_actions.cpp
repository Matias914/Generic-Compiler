#include "utils/LogHandler.h"
#include "utils/ErrorHandler.h"
#include "utils/LiteralTable.h"
#include "utils/resources/macros.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/translator.h"
#include "syntax-analyzer/components/semantic_actions.h"

extern LogHandler   LOG_HANDLER;
extern ErrorHandler ERROR_HANDLER;
extern LiteralTable LITERAL_TABLE;

using namespace SyntaxAnalyzer;

extern int yychar;

void SemanticActions::announceSyntaxError()
{
    Log l;
    l.type = ERROR;
    l.code = SYNTAX_ERROR;
    l.line = LexicalAnalyzer::YYLINENO;
    switch (yychar)
    {
    case IDENTIFIER:
        l.content = {yylval.sref->symbol};
        break;
    case FLOAT_LITERAL:
    case STRING_LITERAL:
    case UINTEGER_LITERAL:
        l.content = {yylval.lref->constant};
        break;
    default:
        l.content = {Translator::translate(yychar)};
    }
    ERROR_HANDLER.add(l);
}

void SemanticActions::specifyExpectedError(const std::string& expected)
{
    auto l = *ERROR_HANDLER.getLastestLog();
    l.code = EXPECTED_BUT_FOUND;
    l.content.push_back(expected);
    ERROR_HANDLER.updateLatestLog(l);
}

void SemanticActions::logStructure(const std::string& structure)
{
    Log log;
    log.type = STRUCTURE;
    log.code = yychar;
    log.line = LexicalAnalyzer::YYLINENO;
    log.content = {structure};
    LOG_HANDLER.add(log);
}

void SemanticActions::addNegativeFloatToTable()
{
    const std::string new_constant = "-" + yylval.lref->constant;
    const LiteralTable::Type value = { .f = -yylval.lref->value.f};
    LITERAL_TABLE.decrementReferences(yylval.lref->constant);
    yylval.lref = LITERAL_TABLE.addAndGet(new_constant, FLOAT, value);
}

