#include "utils/ReportHandler.h"
#include "utils/ErrorHandler.h"
#include "utils/LiteralTable.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/parser.h"
#include "syntax-analyzer/components/translator.h"
#include "syntax-analyzer/components/semantic_actions.h"

// Usada por Bison, guarda el token obtenido del lexico.
extern int yychar;

extern bool VERBOSE_OPTION;
extern ReportHandler REPORT_HANDLER;
extern LiteralTable LITERAL_TABLE;

using namespace SyntaxAnalyzer;

void SemanticActions::logStructure(const std::string& structure)
{
    if (VERBOSE_OPTION)
    {
        Log log;
        log.type = STRUCTURE;
        log.code = yychar;
        log.line = LexicalAnalyzer::YYLINENO;
        log.content = {structure};
        REPORT_HANDLER.add(log);
    }
}

void SemanticActions::addNegativeFloatToTable()
{
    const std::string new_constant = "-" + yylval.lref->constant;
    const LiteralTable::TypeValue value = { .f = -yylval.lref->value.f};
    LITERAL_TABLE.decrementReferences(yylval.lref->constant);
    yylval.lref = LITERAL_TABLE.addAndGet(new_constant, FLOAT_LITERAL, value);
    if (yylval.lref == nullptr)
        throw std::runtime_error("addNegativeFloatToTable: failed to add new constant to table");
}