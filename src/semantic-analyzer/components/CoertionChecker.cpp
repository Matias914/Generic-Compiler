#include "utils/Log.h"
#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/parser.h"
#include "semantic-analyzer/components/CoertionChecker.h"

extern ErrorHandler ERROR_HANDLER;

bool CoertionChecker::truncable(const int& type)
{
    if (type == FLOAT || type == FLOAT_LITERAL)
        return true;
    if (type == UINT || type == UINTEGER_LITERAL)
    {
        Log l;
        l.type = WARNING;
        l.code = TRUNC_USELESS;
        l.line = LexicalAnalyzer::YYLINENO;
        ERROR_HANDLER.add(l);
        return true;
    }
    return false;
}
