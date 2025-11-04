#ifndef GC_SEMANTIC_ANALYZER_H
#define GC_SEMANTIC_ANALYZER_H

#include "utils/SymbolTable.h"
#include "components/CoertionChecker.h"

#include <string>


namespace  SemanticAnalyzer
{
    extern std::string SCOPE;

    extern int CURRENT_TYPE;
    extern int CURRENT_SEMANTIC;

    struct Variable
    {
        std::string name;
        std::string prefix;
    };
    extern Variable CURRENT_VARIABLE;

    extern CoertionChecker COERTIONS;

    void addScope(const std::string& scope);
    void removeScope();
    void addLambdaScope();
    void addInvalidScope();

    void checkProgramRedeclaration(const std::string& program);

    const SymbolTable::Entry* updateSymbolAsProgram(const std::string& program);
    const SymbolTable::Entry* upsertVariableScope();

    void notifyFunctionDeclaration(const std::string& name);
    void notifyUnnamedFunctionDeclaration();
    void checkInvocationParametersNumber();

    const SymbolTable::Entry* updateParameterScope(const std::string& name);
    const SymbolTable::Entry* notifyParametersDeclarationEnd();
    const SymbolTable::Entry* checkFunctionExistanceInScopeAndBuffer(const std::string& name);
    const SymbolTable::Entry* checkParameterExistanceInScope(const std::string& name);

    const SymbolTable::Entry* checkVariableExistanceInScope();
    const SymbolTable::Entry* checkFunctionExistanceInScopeAndBuffer(const std::string& name);
    const SymbolTable::Entry* checkParameterExistanceInScope(const std::string& name);
};


#endif //GC_SEMANTIC_ANALYZER_H