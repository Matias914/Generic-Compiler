#ifndef GC_SEMANTIC_ANALYZER_H
#define GC_SEMANTIC_ANALYZER_H

#include <string>

#include "components/FunctionChecker.h"
#include "components/InvocationChecker.h"
#include "components/LambdaChecker.h"
#include "components/ProgramChecker.h"
#include "components/ReturnChecker.h"
#include "components/TypeChecker.h"
#include "components/VariableChecker.h"

/*
 * @brief namespace que expone las funciones del análisis semántico y sus componentes.
 *
 * Se divide en clases que se encargan de diferentes tipos de restricciones, repartiendo la funcionalidad
 * en componentes.
 */
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