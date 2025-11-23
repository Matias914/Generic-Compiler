#include "syntax-analyzer/components/semantic_actions.h"

#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/translator.h"

#include "utils/LiteralTable.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

#define RUNTIME_E1 "\naddNegativeFloatToTable: failed to add new constant to table"

// Usada por Bison, guarda el token obtenido del lexico.
extern int yychar;

extern bool VERBOSE_OPTION;

extern LiteralTable  LITERAL_TABLE;
extern ReportHandler REPORT_HANDLER;

namespace SyntaxAnalyzer::SemanticActions
{
    const LiteralTable::Entry* turnNegative(const LiteralTable::Entry* lref)
    {
        const std::string new_constant = "-" + lref->constant;
        const LiteralTable::TypeValue value = { .f = -lref->value.f };
        LITERAL_TABLE.decrementReferences(lref->constant);
        const auto ref = LITERAL_TABLE.addAndGet(new_constant, lref->type, value);
        if (ref == nullptr)
            throw std::runtime_error(RUNTIME_E1);
        return ref;
    }

    void logStructure(const std::string& structure)
    {
        if (VERBOSE_OPTION)
        {
            const Log log(STRUCTURE, yychar, LexicalAnalyzer::YYLINENO, {structure});
            REPORT_HANDLER.add(log);
        }
    }

}
