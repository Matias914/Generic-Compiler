#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"

#include <algorithm>

extern SymbolTable SYMBOL_TABLE;
extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    std::string SCOPE = "";

    int SERIAL = 0;
    int CURRENT_TYPE = -1;

    bool EXISTS_PROGRAM = false;

    Variable CURRENT_VARIABLE;

    void addScope(const std::string& scope)
    {
        SCOPE.append(":").append(scope);
    }

    void removeScope()
    {
        if (const size_t pos = SCOPE.rfind(':'); pos != std::string::npos)
            SCOPE = SCOPE.substr(0, pos);
        else
            SCOPE.clear();
    }

    void addInvalidScope()
    {
        SCOPE.append(":").append("invalid-scope-").append(std::to_string(SERIAL++));
    }

    void checkProgramRedeclaration(const std::string& program)
    {
        if (EXISTS_PROGRAM)
        {
            Log l;
            l.type = ERROR;
            l.code = MULTIPLE_PROGRAMS_DECLARED;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { program };
            ERROR_HANDLER.add(l);
        } else
            EXISTS_PROGRAM = true;
    }

    const SymbolTable::Entry* updateSymbolAsProgram(const std::string& program)
    {
        const auto entry = SYMBOL_TABLE.get(program);
        if (entry == nullptr)
            throw std::runtime_error("\nupdateSymbolAsProgram: failed to get program");
        if (entry->use == PROGRAM)
            return nullptr;
        return SYMBOL_TABLE.update(program, -1, PROGRAM);
    }

    const SymbolTable::Entry* upsertVariableScope()
    {
        if (CURRENT_VARIABLE.prefix.empty())
        {
            const auto entry = SYMBOL_TABLE.upsert (
                CURRENT_VARIABLE.name,
                CURRENT_VARIABLE.name + SCOPE,
                CURRENT_TYPE,
                VARIABLE
            );
            if (entry == nullptr)
            {
                Log l;
                l.type = ERROR;
                l.code = VARIABLE_REDECLARATION;
                l.line = LexicalAnalyzer::YYLINENO;
                l.content = { CURRENT_VARIABLE.name };
                ERROR_HANDLER.add(l);
            }
            return entry;
        }
        Log l;
        l.type = ERROR;
        l.code = VARIABLE_PREFIX_IN_DECLARATION;
        l.line = LexicalAnalyzer::YYLINENO;
        l.content = { CURRENT_VARIABLE.prefix };
        ERROR_HANDLER.add(l);
        if (!SYMBOL_TABLE.remove(CURRENT_VARIABLE.name))
            throw std::runtime_error("\nupsertVariableScope: failed to delete symbol with prefix");
        return nullptr;
    }

    const SymbolTable::Entry* upsertFunctionScope(const std::string& symbol)
    {
        const auto entry = SYMBOL_TABLE.upsert(symbol, symbol + SCOPE, CURRENT_TYPE, FUNCTION);
        if (entry == nullptr)
        {
            Log l;
            l.type = ERROR;
            l.code = FUNCTION_REDECLARATION;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { symbol };
            ERROR_HANDLER.add(l);
        }
        return entry;
    }

    bool checkExistanceInScope()
    {
        if (!CURRENT_VARIABLE.prefix.empty())
        {
            if (SYMBOL_TABLE.get (CURRENT_VARIABLE.name + CURRENT_VARIABLE.prefix) == nullptr)
            {
                Log l;
                l.type = ERROR;
                l.code = UNDECLARED_VARIABLE;
                l.line = LexicalAnalyzer::YYLINENO;
                l.content = { CURRENT_VARIABLE.name };
                ERROR_HANDLER.add(l);
                return false;
            }
            return true;
        }
        bool exists = false;
        std::string temp_scope = SCOPE;
        while (!temp_scope.empty() && !exists)
        {
            if (SYMBOL_TABLE.get (CURRENT_VARIABLE.name + temp_scope) != nullptr)
                exists = true;
            if (const size_t pos = temp_scope.rfind(':'); pos != std::string::npos)
                temp_scope = temp_scope.substr(0, pos);
            else
                temp_scope.clear();
        }
        if (!exists)
        {
            Log l;
            l.type = ERROR;
            l.code = UNDECLARED_VARIABLE;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { CURRENT_VARIABLE.name };
            ERROR_HANDLER.add(l);
        }
        return exists;
    }
}
