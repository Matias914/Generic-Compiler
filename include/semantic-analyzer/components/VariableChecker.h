#ifndef GC_VARIABLECHECKER_H
#define GC_VARIABLECHECKER_H

#include "utils/SymbolTable.h"

#include <queue>

namespace SemanticAnalyzer
{
    /*
     * @brief clase que se encarga de verificar la integridad de las variables del programa.
     *
     * Verifica la integridad del nombre y tipo. Dado que múltiples asignaciones de variables pueden seguirse tras
     * la otra, se usa una cola. De esta manera, en asignaciones múltiples, puede llevarse registro de qué variable
     * es la activa.
     */
    class VariableChecker
    {
    public:
        VariableChecker();

        void notifyVariableName(const std::string& name);
        void notifyVariablePrefix(const std::string& new_name);

        std::string getCurrentVariableName();

        const SymbolTable::Entry* checkVariableDeclaration();
        const SymbolTable::Entry* checkVariableExistanceInScope();

    private:
        struct Variable
        {
            std::string name;
            std::string prefix;
        };
        std::queue<Variable> variables;
    };
}

#endif //GC_VARIABLECHECKER_H