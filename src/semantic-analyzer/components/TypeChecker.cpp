#include "semantic-analyzer/components/TypeChecker.h"

#include "lexical-analyzer/LexicalAnalyzer.h"
#include "utils/ErrorHandler.h"
#include "utils/Log.h"
#include "utils/resources/codes.h"
#include "utils/resources/types.h"

extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    TypeChecker::TypeChecker() {}

    bool TypeChecker::truncateNecessary(const Expression& e)
    {
        if (e.type != UINT)
            return true;
        const Log l (
            WARNING,
            TRUNC_USELESS,
            LexicalAnalyzer::YYLINENO,
            {e.representation}
        );
        ERROR_HANDLER.add(l);
        return false;
    }

    int TypeChecker::checkTruncate(const Expression& e)
    {
        switch (e.type)
        {
        case UINT:
            return UINT;
        case FLOAT:
            return UINT;
        default:
            return UNKNOWN;
        }
    }

    int TypeChecker::checkOperation(const Expression& e1, const Expression& e2)
    {
        if (e1.type == UNKNOWN || e2.type == UNKNOWN) {
            return UNKNOWN;
        }
        if (e1.type != e2.type) {
            const Log l (
                ERROR,
                INCOMPATIBLE_TYPES,
                LexicalAnalyzer::YYLINENO,
                {e1.representation, e2.representation}
            );
            ERROR_HANDLER.add(l);
            return UNKNOWN;
        }
        return e1.type;
    }

    int TypeChecker::checkSemantics(const Expression& e1, const Expression& e2)
    {
        if (e1.type == UNKNOWN || e2.type == UNKNOWN) {
            return UNKNOWN;
        }
        if (!e1.assignable && e2.type == CR)
        {
            const Log l (
                ERROR,
                INCOMPATIBLE_WITH_SEMANTIC,
                LexicalAnalyzer::YYLINENO,
                {e1.representation, e2.representation, "CR"}
            );
            ERROR_HANDLER.add(l);
            return UNKNOWN;
        }
        return e2.type;
    }

    int TypeChecker::checkAssignment(const Expression& e1, const Expression& e2)
    {
        if (e1.type == UNKNOWN || e2.type == UNKNOWN) {
            return UNKNOWN;
        }
        if (e1.type != e2.type) {
            const Log l (
                ERROR,
                INCOMPATIBLE_TYPES,
                LexicalAnalyzer::YYLINENO,
                {e1.representation, e2.representation}
            );
            ERROR_HANDLER.add(l);
            return UNKNOWN;
        }
        return e1.type;
    }
}
