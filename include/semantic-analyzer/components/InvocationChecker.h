#ifndef GC_INVOCATIONCHECKER_H
#define GC_INVOCATIONCHECKER_H

#include <bitset>
#include <stack>

#include "utils/SymbolTable.h"

// Define la cantidad de parámetros que puede tener una función
#define PARAMETERS_LIMIT 256

namespace SemanticAnalyzer
{
    /*
     * @brief clase que se encarga de verificar la integridad de las invocaciones
     * a función.
     *
     * Verifica la integridad del nombre y la existencia de los parámetros formales. Dado que
     * una invocación puede anidar otras invocaciones, es que se necesita una stack para guardar
     * los metadatos.
     */
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