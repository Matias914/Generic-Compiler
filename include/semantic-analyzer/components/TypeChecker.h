#ifndef GC_COERTIONCHECKER_H
#define GC_COERTIONCHECKER_H

#include "utils/ErrorHandler.h"

extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    /*
     * @brief clase que se encarga de verificar la integridad de tipos de las operaciones aritméticas, de los
     * truncamientos explícitos y de las asignaciones.
     */
    class TypeChecker
    {
    public:
        struct Expression
        {
            int type;
            std::string representation;
            bool assignable;
        };
        TypeChecker();

        static bool truncateNecessary(const Expression& e);

        static int checkTruncate(const Expression& e);
        static int checkOperation(const Expression& e1, const Expression& e2);
        static int checkSemantics(const Expression& e1, const Expression& e2);
        static int checkAssignment(const Expression& e1, const Expression& e2);

    };
}

#endif //GC_COERTIONCHECKER_H