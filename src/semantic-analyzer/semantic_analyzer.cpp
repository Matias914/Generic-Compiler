#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"

extern SymbolTable SYMBOL_TABLE;
extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    std::string SCOPE = "";

    int INVALID_SERIAL = 0;
    int LAMBDA_SERIAL = 0;

    int CURRENT_TYPE = UNSUPPORTED;
    int CURRENT_SEMANTIC = UNSUPPORTED;

    void addScope(const std::string& scope)
    {
        SCOPE.append(":").append(scope);
    }

    void addLambdaScope()
    {
        SCOPE.append(":").append("lambda").append(std::to_string(INVALID_SERIAL++));
    }

    void removeScope()
    {
        if (const size_t pos = SCOPE.rfind(':'); pos != std::string::npos)
            SCOPE = SCOPE.substr(0, pos);
        else
            SCOPE.clear();
    }

    void addInvalidScope()
    {
        SCOPE.append(":").append("invalid").append(std::to_string(INVALID_SERIAL++));
    }
}
