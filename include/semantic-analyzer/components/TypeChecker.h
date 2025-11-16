#ifndef GC_COERTIONCHECKER_H
#define GC_COERTIONCHECKER_H

#include "utils/Log.h"
#include "utils/ErrorHandler.h"

#define TC_UNSUPPORTED (-1)
#define TC_UINT          0
#define TC_FLOAT         1

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
        };

        static int checkTruncate(const Expression& e);
        static int checkOperation(const Expression& e1, const Expression& e2);
    };
}

#endif //GC_COERTIONCHECKER_H