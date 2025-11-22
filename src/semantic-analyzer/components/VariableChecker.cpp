#include "semantic-analyzer/components/VariableChecker.h"

#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"
#include "utils/resources/codes.h"

#define RUNTIME_E1 "\ncheckVariableDeclaration: 'variables' is empty"
#define RUNTIME_E2 "\ncheckVariableExistanceInScope: 'variables' is empty"

extern SymbolTable SYMBOL_TABLE;

namespace SemanticAnalyzer
{
    VariableChecker::VariableChecker() : variables(std::queue<Variable>()) {}

    void VariableChecker::notifyVariableName(const std::string& name)
    {
        variables.push(Variable{name, ""});
    }

    void VariableChecker::notifyVariablePrefix(const std::string& new_name)
    {
        auto& [name, prefix] = variables.back();
        prefix.append(":").append(name);
        name = new_name;
    }

    std::string VariableChecker::getCurrentVariableName()
    {
        return variables.front().name;
    }

    const SymbolTable::Entry* VariableChecker::checkVariableDeclaration()
    {
        if (variables.empty())
            throw std::runtime_error(RUNTIME_E1);
        auto& [name, prefix] = variables.front();
        if (prefix.empty())
        {
            const auto entry = SymbolTable::Entry({
                name + SCOPE,
                TYPE,
                VARIABLE
            });
            const auto ref = SYMBOL_TABLE.update(name, entry);
            if (ref == nullptr)
            {
                const Log l (
                    ERROR,
                    VARIABLE_REDECLARATION,
                    LexicalAnalyzer::YYLINENO,
                    {name}
                );
                ERROR_HANDLER.add(l);
            }
            variables.pop();
            return ref;
        }
        const Log l (
            ERROR,
            VARIABLE_PREFIX_IN_DECLARATION,
            LexicalAnalyzer::YYLINENO,
            {prefix}
        );
        ERROR_HANDLER.add(l);
        variables.pop();
        return nullptr;
    }

    const SymbolTable::Entry* VariableChecker::checkVariableExistanceInScope()
    {
        if (variables.empty())
            throw std::runtime_error(RUNTIME_E2);
        auto& [name, prefix] = variables.front();
        if (!prefix.empty())
        {
            if (const auto ref = SYMBOL_TABLE.get(name + prefix); ref != nullptr && ref->type == VARIABLE)
            {
                variables.pop();
                return ref;
            }
            const Log l(ERROR, UNDECLARED_VARIABLE, LexicalAnalyzer::YYLINENO, {name});
            ERROR_HANDLER.add(l);
            variables.pop();
            return nullptr;
        }
        std::string temp_scope = SCOPE;
        auto ref = SYMBOL_TABLE.get(name + temp_scope);
        while (ref == nullptr)
        {
            if (const size_t pos = temp_scope.rfind(':'); pos != std::string::npos && pos != 0)
            {
                temp_scope = temp_scope.substr(0, pos);
                ref = SYMBOL_TABLE.get(name + temp_scope);
            }
            else break;
        }
        if (ref == nullptr || (ref->use != VARIABLE && ref->use != PARAMETER))
        {
            const Log l(ERROR, UNDECLARED_VARIABLE, LexicalAnalyzer::YYLINENO, {name});
            ERROR_HANDLER.add(l);
        }
        variables.pop();
        return ref;
    }
}
