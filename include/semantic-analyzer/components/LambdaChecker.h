#ifndef GC_LAMBDACHECKER_H
#define GC_LAMBDACHECKER_H

#include "utils/SymbolTable.h"

#include <stack>
#include <string>

namespace SemanticAnalyzer
{
    class LambdaChecker
    {
    public:
        struct Lambda
        {
            std::string fname;
            std::string pname;
            const SymbolTable::Entry* function;
            const SymbolTable::Entry* parameter;
        };
        LambdaChecker();

        void notifyDeclaration(const std::string& parameter);
        void notifyDeclarationEnd();

        const Lambda& getLambda() const;

    private:
        std::stack<Lambda> lambdas;

        int identifiers;
    };
}

#endif //GC_LAMBDACHECKER_H