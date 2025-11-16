#ifndef GC_VARIABLECHECKER_H
#define GC_VARIABLECHECKER_H

#include "utils/SymbolTable.h"

namespace SemanticAnalyzer
{
    class VariableChecker
    {
    public:
        VariableChecker();

        void notifyVariableName(const std::string& name);
        void notifyVariablePrefix(const std::string& name);

        const SymbolTable::Entry* checkVariableDeclaration();
        // TODO: Mover a assignments pero requiere que "variable: ;" tenga representation
        const SymbolTable::Entry* checkVariableExistanceInScope();

    private:
        struct Variable
        {
            std::string name;
            std::string prefix;
        };
        Variable variable;
    };
}

#endif //GC_VARIABLECHECKER_H