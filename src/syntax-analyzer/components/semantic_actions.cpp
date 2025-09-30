#include "utils/LogHandler.h"
#include "utils/ErrorHandler.h"
#include "utils/LiteralTable.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/syntax_analyzer.h"
#include "syntax-analyzer/components/parser.h"
#include "syntax-analyzer/components/translator.h"
#include "syntax-analyzer/components/semantic_actions.h"

// Usada por Bison, guarda el token obtenido del lexico.
extern int yychar;

extern LogHandler   LOG_HANDLER;
extern ErrorHandler ERROR_HANDLER;
extern LiteralTable LITERAL_TABLE;

using namespace SyntaxAnalyzer;

void SemanticActions::announceSyntaxError()
{
    BUFFER.commit();
    Log l;
    l.type = ERROR;
    l.code = SYNTAX_ERROR;
    l.line = LexicalAnalyzer::YYLINENO;
    l.content = {Translator::translate(yychar)};
    BUFFER.buffer(l);
}

void SemanticActions::specifyExpectedError(const std::string& expected)
{
    const auto ptr = BUFFER.get();
    if (ptr == nullptr)
        throw std::runtime_error("\nspecifyExpectedError: No log was buffered");
    ptr->code = EXPECTED_BUT_FOUND;
    ptr->content.push_back(expected);
    BUFFER.commit();
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