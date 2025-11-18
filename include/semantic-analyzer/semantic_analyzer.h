#ifndef GC_SEMANTIC_ANALYZER_H
#define GC_SEMANTIC_ANALYZER_H

#include "components/TypeChecker.h"
#include "components/ReturnChecker.h"
#include "components/ProgramChecker.h"
#include "components/FunctionChecker.h"
#include "components/VariableChecker.h"
#include "components/InvocationChecker.h"

#include <string>

#include "components/LambdaChecker.h"


namespace SemanticAnalyzer
{
    extern std::string SCOPE;
    extern int TYPE;

    extern TypeChecker       CHK_TYPES;
    extern ReturnChecker     CHK_RETURNS;
    extern LambdaChecker     CHK_LAMBDAS;
    extern ProgramChecker    CHK_PROGRAMS;
    extern FunctionChecker   CHK_FUNCTIONS;
    extern VariableChecker   CHK_VARIABLES;
    extern InvocationChecker CHK_INVOCATIONS;

    void addScope(const std::string& scope);
    void removeScope();
    void addInvalidScope();

};


#endif //GC_SEMANTIC_ANALYZER_H