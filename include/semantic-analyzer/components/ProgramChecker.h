#ifndef GC_PROGRAMCHECKER_H
#define GC_PROGRAMCHECKER_H

#include "utils/SymbolTable.h"

namespace SemanticAnalyzer
{
    /*
     * @brief clase que se encarga de verificar la integridad de los programas.
     *
     * Verifica redeclaraciones, nombres y actualiza la tabla de símbolos con la información
     * correspondiente.
     */
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