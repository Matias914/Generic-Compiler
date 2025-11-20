#include "utils/Log.h"
#include "utils/ErrorHandler.h"
#include "utils/resources/codes.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"
#include "semantic-analyzer/components/InvocationChecker.h"

extern SymbolTable SYMBOL_TABLE;
extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    InvocationChecker::InvocationChecker() :
        invocations(std::stack<Invocation>()) {}

    /*
     * @brief verifica si una función está declarada en algún ámbito alcanzable. Guarda sus metadatos en el
     * contexto actual.
     *
     * La función se agrega luego de los parámetros porque es el único momento en el que se tiene toda la información
     * disponible sobre su definición. Si falla la adición es porque hubo un problema que no debería haber ocurrido.
     * Al fin y al cabo se sabe que la función no existe antes de la declaración de los parámetros.
     */
    const SymbolTable::Entry* InvocationChecker::checkFunctionInScope(const std::string& name)
    {
        auto invocation = Invocation();
        invocation.args = 0;
        invocation.flags.reset();

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
            invocation.function.clear();
            invocation.scope.clear();
            invocation.parameters = 0;

            const Log l(ERROR, UNDECLARED_FUNCTION, LexicalAnalyzer::YYLINENO, {name});
            ERROR_HANDLER.add(l);
        }
        else
        {
            invocation.function = std::move(name);
            invocation.scope = std::move(temp_scope);
            invocation.scope.append(":").append(invocation.function);
            invocation.parameters = ref->params;
        }

        invocations.push(invocation);
        return ref;
    }

    /*
     * @brief verifica si un parámetro está declarado en la firma de la función y si hubo reutilización del mismo.
     * Guarda sus metadatos en el contexto actual y depende de que primero se conozca la firma de la función.
     *
     * La cantidad de argumentos de los metadatos de la invocación se aumentan por cada llamado. Se busca en la tabla
     * de símbolos para verificar que exista y se obtiene su posición dentro de los parámetros. Esto es útil para
     * verificar su posición de un bitmap, donde un flag en alto indica que tal parámetro ya fue usado como argumento
     * para esa invocación.
     */
    const SymbolTable::Entry* InvocationChecker::checkParameterInScope(const std::string& name)
    {
        auto& [function, scope, parameters, args, flags] = invocations.top();
        if (function.empty())
            return nullptr;
        args++;
        const auto temp_scope = scope;
        const auto ref = SYMBOL_TABLE.get(name + scope);
        if (ref == nullptr || ref->use != PARAMETER)
        {
            const Log l (
                ERROR,
                UNDECLARED_PARAMETER,
                LexicalAnalyzer::YYLINENO,
                { name, function }
            );
            ERROR_HANDLER.add(l);
            return nullptr;
        }
        if (flags[ref->params])
        {
            const Log l (
                ERROR,
                PARAMETER_ALREADY_INSTANTIATED,
                LexicalAnalyzer::YYLINENO,
                {name}
            );
            ERROR_HANDLER.add(l);
            return nullptr;
        }
        flags[ref->params].flip();
        return ref;
    }

    /*
     * @brief verifica si la cantidad de parametros de una funcion es igual a la cantidad de argumentos de su
     * invocacion y quita una invocación de la stack.
     */
    void InvocationChecker::notifyInvocationEnd()
    {
        auto& [function, scope, parameters, args, flags] = invocations.top();
        if (function.empty())
            return;
        if (parameters != args)
        {
            const Log l(
                ERROR,
                INVALID_ARGUMENTS_NUMBER,
                LexicalAnalyzer::YYLINENO,
                { std::to_string(args), std::to_string(parameters) }
            );
            ERROR_HANDLER.add(l);
        }
        invocations.pop();
    }
}
