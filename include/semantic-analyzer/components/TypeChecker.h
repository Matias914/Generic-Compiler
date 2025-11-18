#ifndef GC_COERTIONCHECKER_H
#define GC_COERTIONCHECKER_H

#include "utils/ErrorHandler.h"

#define TC_UNSUPPORTED (-1)
#define TC_UINT          0
#define TC_FLOAT         1
#define TC_CV            2
#define TC_CR            3

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

    };
}

#endif //GC_COERTIONCHECKER_H