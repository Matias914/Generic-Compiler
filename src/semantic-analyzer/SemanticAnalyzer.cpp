#include "semantic-analyzer/SemanticAnalyzer.h"

#include "utils/ErrorHandler.h"

extern SymbolTable SYMBOL_TABLE;
extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    TypeChecker       CHK_TYPES;
    ReturnChecker     CHK_RETURNS;
    LambdaChecker     CHK_LAMBDAS;
    ProgramChecker    CHK_PROGRAMS;
    FunctionChecker   CHK_FUNCTIONS;
    VariableChecker   CHK_VARIABLES;
    InvocationChecker CHK_INVOCATIONS;

    std::string SCOPE = "";

    int TYPE = UNKNOWN;

    static int INVALID_SERIAL = 0;

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

    void addInvalidScope()
    {
        SCOPE.append(":").append("invalid").append(std::to_string(INVALID_SERIAL++));
    }
}
