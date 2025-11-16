#ifndef GC_INVOCATIONCHECKER_H
#define GC_INVOCATIONCHECKER_H

#include "utils/SymbolTable.h"

// Define la cantidad de parámetros que puede tener una función
#define PARAMETERS_LIMIT 256

#include <bitset>
#include <stack>

namespace SemanticAnalyzer
{
    class InvocationChecker
    {
    public:
        InvocationChecker();

        const SymbolTable::Entry* checkFunctionInScope(const std::string& name);
        const SymbolTable::Entry* checkParameterInScope(const std::string& name);

        void notifyInvocationEnd();

    private:
        struct Invocation
        {
            std::string function;
            std::string scope;
            int parameters;
            int args;
            std::bitset<PARAMETERS_LIMIT> flags;
        };
        std::stack<Invocation> invocations;
    };
}

#endif //GC_INVOCATIONCHECKER_H