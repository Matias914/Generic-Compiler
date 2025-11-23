#include "semantic-analyzer/components/ReturnChecker.h"

#include "lexical-analyzer/LexicalAnalyzer.h"
#include "semantic-analyzer/components/TypeChecker.h"
#include "utils/ErrorHandler.h"
#include "utils/Log.h"
#include "utils/resources/codes.h"
#include "utils/resources/types.h"

extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    void ReturnChecker::bufferFunction(const Element& func)
    {
        functions.push(func);
    }

    void ReturnChecker::removeFunction()
    {
        functions.pop();
    }

    int ReturnChecker::checkReturnWithBuffered(const Element& ret)
    {
        if (functions.empty())
        {
            const Log l (
                ERROR,
                RETURN_WITHOUT_SCOPE,
                LexicalAnalyzer::YYLINENO
            );
            ERROR_HANDLER.add(l);
            return false;
        }
        const auto& [type, representation] = functions.top();
        if (ret.type == UNKNOWN || type == UNKNOWN)
            return UNKNOWN;
        if (ret.type == type)
            return ret.type;
        const Log l (
            ERROR,
            RETURN_INCOMPATIBLE,
            LexicalAnalyzer::YYLINENO,
            {ret.representation, representation}
        );
        ERROR_HANDLER.add(l);
        return UNKNOWN;
    }

    bool ReturnChecker::checkIfHasReturn(const bool& returnable)
    {
        if (!functions.empty() && functions.top().type != UNKNOWN && !returnable)
        {
            const Log l (
                ERROR,
                MISSING_RETURN_STATEMENT,
                LexicalAnalyzer::YYLINENO,
                {functions.top().representation }
            );
            ERROR_HANDLER.add(l);
            return false;
        }
        return true;
    }
}
