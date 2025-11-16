#include "utils/ErrorHandler.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"

extern SymbolTable SYMBOL_TABLE;
extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    TypeChecker       CHK_TYPES;
    ProgramChecker    CHK_PROGRAMS;
    FunctionChecker   CHK_FUNCTIONS;
    VariableChecker   CHK_VARIABLES;
    InvocationChecker CHK_INVOCATIONS;

    std::string SCOPE = "";

    int TYPE = ST_UNSUPPORTED;

    static int INVALID_SERIAL = 0;
    static int LAMBDA_SERIAL = 0;

    void addScope(const std::string& scope)
    {
        SCOPE.append(":").append(scope);
    }

    void removeScope()
    {
        if (const size_t pos = SCOPE.rfind(':'); pos != std::string::npos)
            SCOPE = SCOPE.substr(0, pos);
        else
            SCOPE.clear();
    }

    void addLambdaScope()
    {
        SCOPE.append(":").append("lambda").append(std::to_string(LAMBDA_SERIAL++));
    }

    void addInvalidScope()
    {
        SCOPE.append(":").append("invalid").append(std::to_string(INVALID_SERIAL++));
    }
}
