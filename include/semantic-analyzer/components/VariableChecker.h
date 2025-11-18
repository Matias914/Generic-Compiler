#ifndef GC_VARIABLECHECKER_H
#define GC_VARIABLECHECKER_H

#include "utils/SymbolTable.h"

#include <queue>

namespace SemanticAnalyzer
{
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