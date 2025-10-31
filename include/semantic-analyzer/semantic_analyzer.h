#ifndef GC_SEMANTIC_ANALYZER_H
#define GC_SEMANTIC_ANALYZER_H

#include "utils/SymbolTable.h"

#include <string>

namespace  SemanticAnalyzer
{
    extern std::string SCOPE;

    extern int SERIAL;
    extern int CURRENT_TYPE;

    struct Variable
    {
        std::string name;
        std::string prefix;
    };
    extern Variable CURRENT_VARIABLE;

    extern bool EXISTS_PROGRAM;

    void addScope(const std::string& scope);
    void removeScope();
    void addInvalidScope();

    void checkProgramRedeclaration(const std::string& program);
    const SymbolTable::Entry* updateSymbolAsProgram(const std::string& program);

    const SymbolTable::Entry* upsertVariableScope();
    const SymbolTable::Entry* upsertFunctionScope(const std::string& symbol);

    bool checkExistanceInScope();
};


#endif //GC_SEMANTIC_ANALYZER_H