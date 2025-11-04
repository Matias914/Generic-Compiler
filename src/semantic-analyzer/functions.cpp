#include <functional>

#include "utils/Log.h"
#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"

extern SymbolTable SYMBOL_TABLE;
extern ErrorHandler ERROR_HANDLER;

#define PARAMETERS_LIMIT 256

namespace SemanticAnalyzer
{
    struct Function
    {
        std::string name = "";
        std::string scope = "";
        int type;
        int params;
    };
    Function CURRENT_FUNCTION;

    struct Invocation
    {
        int args;
        std::bitset<PARAMETERS_LIMIT> flags;
    };
    Invocation CURRENT_INVOCATION;

    /*
     * @brief verifica que una función no exista en el ámbito declarado. Guarda temporalmente sus metadatos
     * en el contexto actual.
     *
     * Pregunta a la tabla de símbolos si la función existe y en caso contrario, loguea el error. Si no
     * existe, sus metadatos estarán vacíos.
     */
    void notifyFunctionDeclaration(const std::string& name)
    {
        if (SYMBOL_TABLE.get(name + SCOPE) != nullptr)
        {
            addInvalidScope();
            CURRENT_FUNCTION = {"", "", 0};

            Log l;
            l.type = ERROR;
            l.code = FUNCTION_REDECLARATION;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { name };
            ERROR_HANDLER.add(l);
            return;
        }
        CURRENT_FUNCTION = {name, SCOPE, CURRENT_TYPE, 0};
        addScope(name);
    }

    /*
     * @brief agrega un scope inválido y guarda temporalmente los metadatos de la función actual.
     *
     * Al tener nombre vacio no se va a agregar a la tabla de símbolos, lo cual no supone un problema porque no se
     * puede invocar. Solo se va a verificar el número de parámetros y su posible redeclaración.
     */
    void notifyUnnamedFunctionDeclaration()
    {
        CURRENT_FUNCTION = {"", SCOPE, CURRENT_TYPE, 0};
        addInvalidScope();
    }

    /*
     * @brief actualiza un símbolo como un parámetro asociado a la función del contexto actual.
     *
     * Verifica si ya fue declarado. En tal caso, se loguea el error. Además, aumenta la cantidad
     * de parámetros de la función del contexto actual. Verfica que la cantidad de parámetros no
     * supere el límite permitido.
     */
    const SymbolTable::Entry* updateParameterScope(const std::string& name)
    {
        if (CURRENT_FUNCTION.params >= PARAMETERS_LIMIT)
        {
            Log l;
            l.type = ERROR;
            l.code = PARAMETERS_LIMIT_EXCEEDED;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { name };
            ERROR_HANDLER.add(l);
            return nullptr;
        }
        const auto entry = SymbolTable::Entry({
            name + SCOPE,
            CURRENT_TYPE,
            PARAMETER,
            CURRENT_SEMANTIC,
            CURRENT_FUNCTION.params
        });
        CURRENT_FUNCTION.params++;
        const auto ref = SYMBOL_TABLE.update(name, &entry);
        if (ref == nullptr)
        {
            Log l;
            l.type = ERROR;
            l.code = PARAMETER_REDECLARATION;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { name };
            ERROR_HANDLER.add(l);
        }
        return ref;
    }

    /*
     * @brief agrega la función del contexto actual a la tabla de símbolos si no existe.
     *
     * La función se agrega luego de los parámetros porque es el único momento en el que se tiene toda la información
     * disponible sobre su definición. Si falla la adición es porque hubo un problema que no debería haber ocurrido.
     * Al fin y al cabo se sabe que la función no existe antes de la declaración de los parámetros.
     */
    const SymbolTable::Entry* notifyParametersDeclarationEnd()
    {
        if (CURRENT_FUNCTION.name == "")
            return nullptr;
        const auto entry = SymbolTable::Entry({
            CURRENT_FUNCTION.name + CURRENT_FUNCTION.scope,
            CURRENT_FUNCTION.type,
            FUNCTION,
            UNSUPPORTED,
            CURRENT_FUNCTION.params
        });
        const auto ref = SYMBOL_TABLE.update(CURRENT_FUNCTION.name, &entry);
        if (ref == nullptr)
            throw std::runtime_error("upsertFunctionScope: failed to add function");
        return ref;
    }

    /*
     * @brief verifica si una función está declarada en algún ámbito alcanzable. Guarda sus metadatos en el
     * contexto actual.
     *
     * La función se agrega luego de los parámetros porque es el único momento en el que se tiene toda la información
     * disponible sobre su definición. Si falla la adición es porque hubo un problema que no debería haber ocurrido.
     * Al fin y al cabo se sabe que la función no existe antes de la declaración de los parámetros.
     */
    const SymbolTable::Entry* checkFunctionExistanceInScopeAndBuffer(const std::string& name)
    {
        CURRENT_INVOCATION.flags.reset();
        CURRENT_INVOCATION.args = 0;

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
        if (ref == nullptr || ref->use != FUNCTION)
        {
            CURRENT_FUNCTION = {"", "", UNSUPPORTED, UNSUPPORTED};

            if (!SYMBOL_TABLE.remove(name))
                throw std::runtime_error("\ncheckFunctionExistanceInScope: failed to delete symbol");

            Log l;
            l.type = ERROR;
            l.code = UNDECLARED_FUNCTION;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { name };
            ERROR_HANDLER.add(l);
        }
        else
            CURRENT_FUNCTION = {name, temp_scope, ref->type, ref->params};
        return ref;
    }

    const SymbolTable::Entry* checkParameterExistanceInScope(const std::string& name)
    {
        if (CURRENT_FUNCTION.name.empty())
            return nullptr;
        CURRENT_INVOCATION.args++;
        const auto temp_scope = CURRENT_FUNCTION.scope + ":" + CURRENT_FUNCTION.name;
        const auto ref = SYMBOL_TABLE.get(name + temp_scope);
        if (ref == nullptr || ref->use != PARAMETER)
        {
            Log l;
            l.type = ERROR;
            l.code = UNDECLARED_PARAMETER;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { name, CURRENT_FUNCTION.name };
            ERROR_HANDLER.add(l);
            return nullptr;
        }
        if (CURRENT_INVOCATION.flags[ref->params])
        {
            Log l;
            l.type = ERROR;
            l.code = PARAMETER_ALREADY_INSTANTIATED;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { name };
            ERROR_HANDLER.add(l);
            return nullptr;
        }
        CURRENT_INVOCATION.flags[ref->params].flip();
        return ref;
    }

    void checkInvocationParametersNumber()
    {
        if (CURRENT_FUNCTION.name.empty())
            return;
        if (CURRENT_FUNCTION.params != CURRENT_INVOCATION.args)
        {
            Log l;
            l.type = ERROR;
            l.code = INVALID_ARGUMENTS_NUMBER;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { std::to_string(CURRENT_INVOCATION.args), std::to_string(CURRENT_FUNCTION.params) };
            ERROR_HANDLER.add(l);
        }
    }
}