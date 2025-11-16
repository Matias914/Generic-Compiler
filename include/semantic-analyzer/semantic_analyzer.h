#ifndef GC_SEMANTIC_ANALYZER_H
#define GC_SEMANTIC_ANALYZER_H

#include "components/TypeChecker.h"
#include "components/ProgramChecker.h"
#include "components/FunctionChecker.h"
#include "components/VariableChecker.h"
#include "components/InvocationChecker.h"

#include <string>


namespace SemanticAnalyzer
{
    extern std::string SCOPE;

    extern int TYPE;

    extern TypeChecker       CHK_TYPES;
    extern ProgramChecker    CHK_PROGRAMS;
    extern FunctionChecker   CHK_FUNCTIONS;
    extern VariableChecker   CHK_VARIABLES;
    extern InvocationChecker CHK_INVOCATIONS;

    void addScope(const std::string& scope);
    void removeScope();
    void addLambdaScope();
    void addInvalidScope();

};


#endif //GC_SEMANTIC_ANALYZER_H