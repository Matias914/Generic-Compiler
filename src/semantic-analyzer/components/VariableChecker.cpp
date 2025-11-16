#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"
#include "semantic-analyzer/components/VariableChecker.h"

extern SymbolTable SYMBOL_TABLE;

#define RUNTIME_E1 "\ncheckVariableDeclaration: failed to delete symbol with prefix"
#define RUNTIME_E2 "\ncheckVariableExistanceInScope: failed to delete symbol"

namespace SemanticAnalyzer
{
    VariableChecker::VariableChecker() : variable({"", ""}) {}

    void VariableChecker::notifyVariableName(const std::string& name)
    {
        variable.prefix.clear();
        variable.name = name;
    }

    void VariableChecker::notifyVariablePrefix(const std::string& name)
    {
        variable.prefix.append(":").append(variable.name);
        variable.name = name;
    }

    const SymbolTable::Entry* VariableChecker::checkVariableDeclaration()
    {
        if (variable.prefix.empty())
        {
            const auto entry = SymbolTable::Entry({
                variable.name + SCOPE,
                TYPE,
                ST_VARIABLE
            });
            const auto ref = SYMBOL_TABLE.upsert(variable.name, entry);
            if (ref == nullptr)
            {
                const Log l (
                    ERROR,
                    VARIABLE_REDECLARATION,
                    LexicalAnalyzer::YYLINENO,
                    {variable.name}
                );
                ERROR_HANDLER.add(l);
            }
            return ref;
        }
        const Log l (
            ERROR,
            VARIABLE_PREFIX_IN_DECLARATION,
            LexicalAnalyzer::YYLINENO,
            {variable.prefix}
        );
        ERROR_HANDLER.add(l);
        if (!SYMBOL_TABLE.remove(variable.name))
            throw std::runtime_error(RUNTIME_E1);
        return nullptr;
    }

    const SymbolTable::Entry* VariableChecker::checkVariableExistanceInScope()
    {
        if (!variable.prefix.empty())
        {
            if (const auto ref = SYMBOL_TABLE.get(variable.name + variable.prefix); ref != nullptr &&
                ref->type == ST_VARIABLE
            )
                return ref;
            const Log l(ERROR, UNDECLARED_VARIABLE, LexicalAnalyzer::YYLINENO, {variable.name});
            ERROR_HANDLER.add(l);
            return nullptr;
        }
        std::string temp_scope = SCOPE;
        auto ref = SYMBOL_TABLE.get(variable.name + temp_scope);
        while (ref == nullptr)
        {
            if (const size_t pos = temp_scope.rfind(':'); pos != std::string::npos && pos != 0)
            {
                temp_scope = temp_scope.substr(0, pos);
                ref = SYMBOL_TABLE.get(variable.name + temp_scope);
            }
            else break;
        }
        if (ref == nullptr || (ref->use != ST_VARIABLE && ref->use != ST_PARAMETER))
        {
            const Log l(ERROR, UNDECLARED_VARIABLE, LexicalAnalyzer::YYLINENO, {variable.name});
            ERROR_HANDLER.add(l);
            if (!SYMBOL_TABLE.remove(variable.name))
                throw std::runtime_error(RUNTIME_E2);
        }
        return ref;
    }
}
