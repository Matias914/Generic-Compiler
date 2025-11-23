#include "syntax-analyzer/SyntaxAnalyzer.h"

#include "syntax-analyzer/components/Parser.h"
#include "syntax-analyzer/components/SemanticActions.h"
#include "syntax-analyzer/components/StringPool.h"

extern ErrorHandler ERROR_HANDLER;

namespace SyntaxAnalyzer
{
    void analyze()
    {
        if (yyparse() != 0)
            SemanticActions::BUFFER.commit();
        StringPool::clear();
    }
}