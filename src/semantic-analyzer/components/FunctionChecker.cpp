#include "semantic-analyzer/components/FunctionChecker.h"

#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"
#include "utils/ErrorHandler.h"
#include "utils/Log.h"
#include "utils/resources/codes.h"

#define RUNTIME_E1 "\ncheckFunctionDeclaration: failed to add function"

extern SymbolTable SYMBOL_TABLE;
extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    FunctionChecker::FunctionChecker() :
        semantic(CV),
        function({"", "", 0}) {}
    
    /*
     * @brief verifica que una función no exista en el ámbito declarado. Guarda temporalmente sus metadatos
     * en el contexto actual.
     *
     * Pregunta a la tabla de símbolos si la función existe y en caso contrario, loguea el error. Si no
     * existe, sus metadatos estarán vacíos.
     */
    void FunctionChecker::notifyFunctionName(const std::string& name)
    {
        if (SYMBOL_TABLE.get(name + SCOPE) != nullptr)
        {
            addInvalidScope();
            function = {"", "", 0};
            const Log l(ERROR, FUNCTION_REDECLARATION, LexicalAnalyzer::YYLINENO, {name});
            ERROR_HANDLER.add(l);
            return;
        }
        function = {name, SCOPE, TYPE, 0};
        addScope(name);
    }

    /*
     * @brief agrega un scope inválido y guarda temporalmente los metadatos de la función actual.
     *
     * Al tener nombre vacio no se va a agregar a la tabla de símbolos, lo cual no supone un problema porque no se
     * puede invocar. Solo se va a verificar el número de parámetros y su posible redeclaración.
     */
    void FunctionChecker::notifyFunctionWithoutName()
    {
        function = {"", SCOPE, TYPE, 0};
        addInvalidScope();
    }

    /*
     * @brief cambia el contexto actual de la semantica del parámetro.
     */
    void FunctionChecker::notifyParameterSemantic(const int semantic)
    {
        this->semantic = semantic;
    }

    /*
     * @brief agrega la función del contexto actual a la tabla de símbolos si no existe.
     *
     * La función se agrega luego de los parámetros porque es el único momento en el que se tiene toda la información
     * disponible sobre su definición. Si falla la adición es porque hubo un problema que no debería haber ocurrido.
     * Al fin y al cabo se sabe que la función no existe antes de la declaración de los parámetros.
     */
    const SymbolTable::Entry* FunctionChecker::checkFunctionDeclaration()
    {
        if (function.name == "")
            return nullptr;
        const auto entry = SymbolTable::Entry({
            function.name + function.prefix,
            function.type,
            FUNCTION,
            UNKNOWN,
            function.params
        });
        const auto ref = SYMBOL_TABLE.update(function.name, entry);
        if (ref == nullptr)
            throw std::runtime_error(RUNTIME_E1);
        return ref;
    }

    /*
     * @brief actualiza un símbolo como un parámetro asociado a la función del contexto actual.
     *
     * Verifica si ya fue declarado. En tal caso, se loguea el error. Además, aumenta la cantidad
     * de parámetros de la función del contexto actual. Verfica que la cantidad de parámetros no
     * supere el límite permitido.
     */
    const SymbolTable::Entry* FunctionChecker::checkParameterDeclaration(const std::string& name)
    {
        if (function.params >= PARAMETERS_LIMIT)
        {
            const Log l(ERROR, PARAMETERS_LIMIT_EXCEEDED, LexicalAnalyzer::YYLINENO, {name});
            ERROR_HANDLER.add(l);
            return nullptr;
        }
        const auto entry = SymbolTable::Entry({
            name + SCOPE,
            TYPE,
            PARAMETER,
            semantic,
            function.params
        });
        function.params++;
        const auto ref = SYMBOL_TABLE.update(name, entry);
        if (ref == nullptr)
        {
            const Log l(ERROR, PARAMETER_REDECLARATION, LexicalAnalyzer::YYLINENO, {name});
            ERROR_HANDLER.add(l);
        }
        return ref;
    }
}