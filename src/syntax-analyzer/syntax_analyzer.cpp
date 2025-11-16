#include "syntax-analyzer/syntax_analyzer.h"
#include "syntax-analyzer/components/parser.h"
#include "syntax-analyzer/components/semantic_actions.h"
#include "syntax-analyzer/components/string_pool.h"

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