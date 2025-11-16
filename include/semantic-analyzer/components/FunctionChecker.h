#ifndef GC_FUNCTIONCHECKER_H
#define GC_FUNCTIONCHECKER_H

#include "utils/SymbolTable.h"

namespace SemanticAnalyzer
{
    class FunctionChecker
    {
    public:
        FunctionChecker();

        void notifyFunctionName(const std::string& name);
        void notifyFunctionWithoutName();
        void notifyParameterSemantic(int semantic);

        const SymbolTable::Entry* checkFunctionDeclaration();
        const SymbolTable::Entry* checkParameterDeclaration(const std::string& name);

    private:
        int semantic;

        struct Function
        {
            std::string name = "";
            std::string prefix = "";
            int type;
            int params;
        };
        Function function;
    };
}

#endif //GC_FUNCTIONCHECKER_H