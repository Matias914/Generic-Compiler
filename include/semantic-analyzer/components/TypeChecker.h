#ifndef GC_COERTIONCHECKER_H
#define GC_COERTIONCHECKER_H

#include "utils/ErrorHandler.h"

extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
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

        static int checkTruncate(const Expression& e);
        static int checkOperation(const Expression& e1, const Expression& e2);
        static int checkSemantics(const Expression& e1, const Expression& e2);
        static int checkAssignment(const Expression& e1, const Expression& e2);

    };
}

#endif //GC_COERTIONCHECKER_H