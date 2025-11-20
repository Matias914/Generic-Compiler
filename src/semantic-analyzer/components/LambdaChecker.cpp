#include "semantic-analyzer/semantic_analyzer.h"
#include "semantic-analyzer/components/LambdaChecker.h"

extern SymbolTable SYMBOL_TABLE;

namespace SemanticAnalyzer
{
    LambdaChecker::LambdaChecker() : lambdas(std::stack<Lambda>()), identifiers(0) {}

    void LambdaChecker::notifyDeclaration(const std::string& parameter)
    {
        Lambda lambda;
        lambda.fname = "$L" + std::to_string(++identifiers);
        lambda.function = SYMBOL_TABLE.addAndGet(lambda.fname + SCOPE);
        addScope(lambda.fname);
        lambda.pname = parameter;
        const auto entry = SymbolTable::Entry(parameter + SCOPE, TYPE, PARAMETER);
        lambda.parameter = SYMBOL_TABLE.update(parameter, entry);
        lambdas.push(lambda);
    }

    void LambdaChecker::notifyDeclarationEnd()
    {
        lambdas.pop();
    }

    const LambdaChecker::Lambda& LambdaChecker::getLambda() const
    {
        return lambdas.top();
    }
}

