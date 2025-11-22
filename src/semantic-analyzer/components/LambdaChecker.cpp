#include "semantic-analyzer/components/LambdaChecker.h"

#include <stdexcept>

#include "semantic-analyzer/semantic_analyzer.h"

#define RUNTIME_E1 "\nnotifyDeclaration: update of lambda failed"

extern SymbolTable SYMBOL_TABLE;

namespace SemanticAnalyzer
{
    LambdaChecker::LambdaChecker() : lambdas(std::stack<Lambda>()), identifiers(0) {}

    void LambdaChecker::notifyDeclaration(const std::string& parameter)
    {
        Lambda lambda;
        lambda.fname = "@L" + std::to_string(++identifiers);
        const std::string tmp = lambda.fname + SCOPE;
        lambda.function = SYMBOL_TABLE.addAndGet(tmp);
        lambda.function = SYMBOL_TABLE.update(tmp, {tmp, UNKNOWN, FUNCTION});
        if (lambda.function == nullptr)
            throw std::runtime_error(RUNTIME_E1);
        addScope(lambda.fname);
        lambda.pname = parameter;
        const auto new_param = SymbolTable::Entry(parameter + SCOPE, TYPE, PARAMETER);
        lambda.parameter = SYMBOL_TABLE.update(parameter, new_param);
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

