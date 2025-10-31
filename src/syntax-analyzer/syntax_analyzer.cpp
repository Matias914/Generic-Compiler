#include "syntax-analyzer/syntax_analyzer.h"
#include "syntax-analyzer/components/parser.h"

extern ErrorHandler ERROR_HANDLER;

namespace SyntaxAnalyzer
{
    ErrorBuffer BUFFER(&ERROR_HANDLER);

    void analyze()
    {
        if (yyparse() != 0)
            BUFFER.commit();
    }
}