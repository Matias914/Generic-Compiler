#include "utils/Log.h"
#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/components/TypeChecker.h"

#include <iostream>

extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    TypeChecker::TypeChecker() {}

    int TypeChecker::checkTruncate(const Expression& e)
    {
        switch (e.type)
        {
        case TC_UINT:
            {
                const Log l (
                    WARNING,
                    TRUNC_USELESS,
                    LexicalAnalyzer::YYLINENO,
                    {e.representation}
                );
                ERROR_HANDLER.add(l);
                return TC_UINT;
            }
        case TC_FLOAT:
            return TC_UINT;
        default:
            return TC_UNSUPPORTED;
        }
    }

    int TypeChecker::checkOperation(const Expression& e1, const Expression& e2)
    {
        if (e1.type == TC_UNSUPPORTED || e2.type == TC_UNSUPPORTED) {
            return TC_UNSUPPORTED;
        }
        if (e1.type != e2.type) {
            const Log l (
                ERROR,
                INCOMPATIBLE_TYPES,
                LexicalAnalyzer::YYLINENO,
                {e1.representation, e2.representation}
            );
            ERROR_HANDLER.add(l);
            return TC_UNSUPPORTED;
        }
        return e1.type;
    }

    int TypeChecker::checkSemantics(const Expression& e1, const Expression& e2)
    {
        if (e1.type == TC_UNSUPPORTED || e2.type == ST_UNSUPPORTED) {
            return TC_UNSUPPORTED;
        }
        if (!e1.assignable && e2.type == ST_CR)
        {
            const Log l (
                ERROR,
                INCOMPATIBLE_WITH_SEMANTIC,
                LexicalAnalyzer::YYLINENO,
                {e1.representation, e2.representation, " CR"}
            );
            ERROR_HANDLER.add(l);
            return TC_UNSUPPORTED;
        }
        return e2.type;
    }
}
