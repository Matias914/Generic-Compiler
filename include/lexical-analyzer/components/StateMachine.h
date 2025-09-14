#ifndef TPE_STATEMACHINE_H
#define TPE_STATEMACHINE_H

#include "semantic_actions.h"

/*
 * @brief clase que representa una State Machine.
 *
 * Implementa el State Pattern pero con Closures, evitando crear objetos
 * sin estado. Tiene la misma funcion que la matriz de transicion de estados.
 */
namespace LexicalAnalyzer
{
    class StateMachine
    {
    public:
        bool finalState;
        SemanticAction (*state) (StateMachine* s, const unsigned int& value);

        StateMachine();
        SemanticAction getSemanticAction(const unsigned int& value);
    };
}

#endif //TPE_STATEMACHINE_H