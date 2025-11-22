#ifndef GC_LAMBDACHECKER_H
#define GC_LAMBDACHECKER_H

#include <stack>
#include <string>

#include "utils/SymbolTable.h"

namespace SemanticAnalyzer
{
    /*
     * @brief clase que se encarga de verificar la integridad de las declarciones de
     * funciones Lambda.
     *
     * Se encarga de declararle un nombre a la función usando el prefijo '@' y de actualizar
     * el parámetro en la tabla de símbolos. Dado que una declaración de función Lambda puede
     * anidar otras y que se necesita su información para verifcar la información de invocación,
     * es que utiliza una pila.
     */
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