#include "utils/Log.h"
#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"

extern SymbolTable SYMBOL_TABLE;
extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    Variable CURRENT_VARIABLE;

    const SymbolTable::Entry* upsertVariableScope()
    {
        if (CURRENT_VARIABLE.prefix.empty())
        {
            const auto entry = SymbolTable::Entry({
                CURRENT_VARIABLE.name + SCOPE,
                CURRENT_TYPE,
                VARIABLE,
                UNSUPPORTED,
                UNSUPPORTED
            });
            const auto ref = SYMBOL_TABLE.upsert(CURRENT_VARIABLE.name, &entry);
            if (ref == nullptr)
            {
                Log l;
                l.type = ERROR;
                l.code = VARIABLE_REDECLARATION;
                l.line = LexicalAnalyzer::YYLINENO;
                l.content = { CURRENT_VARIABLE.name };
                ERROR_HANDLER.add(l);
            }
            return ref;
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

    const SymbolTable::Entry* checkVariableExistanceInScope()
    {
        if (!CURRENT_VARIABLE.prefix.empty())
        {
            const auto ref = SYMBOL_TABLE.get(CURRENT_VARIABLE.name + CURRENT_VARIABLE.prefix);
            if (ref == nullptr)
            {
                Log l;
                l.type = ERROR;
                l.code = UNDECLARED_VARIABLE;
                l.line = LexicalAnalyzer::YYLINENO;
                l.content = { CURRENT_VARIABLE.name };
                ERROR_HANDLER.add(l);
                // TODO: ver como borrar de la tabla
                return nullptr;
            }
            return ref;
        }
        std::string temp_scope = SCOPE;
        auto ref = SYMBOL_TABLE.get(CURRENT_VARIABLE.name + temp_scope);
        while (ref == nullptr)
        {
            if (const size_t pos = temp_scope.rfind(':'); pos != std::string::npos && pos != 0)
            {
                temp_scope = temp_scope.substr(0, pos);
                ref = SYMBOL_TABLE.get(CURRENT_VARIABLE.name + temp_scope);
            }
            else break;
        }
        if (ref == nullptr || (ref->use != VARIABLE && ref->use != PARAMETER))
        {
            Log l;
            l.type = ERROR;
            l.code = UNDECLARED_VARIABLE;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { CURRENT_VARIABLE.name };
            ERROR_HANDLER.add(l);
            if (!SYMBOL_TABLE.remove(CURRENT_VARIABLE.name))
                throw std::runtime_error("\ncheckVariableExistanceInScope: failed to delete symbol");
        }
        return ref;
    }
}
