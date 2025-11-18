#ifndef GC_PROGRAMCHECKER_H
#define GC_PROGRAMCHECKER_H

#include "utils/SymbolTable.h"

namespace SemanticAnalyzer
{
    class ProgramChecker
    {
    public:
        ProgramChecker();

        const SymbolTable::Entry* checkProgramDeclaration(const std::string& program);

    private:
        bool declared;
    };
}

#endif //GC_PROGRAMCHECKER_H