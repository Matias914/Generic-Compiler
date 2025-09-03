#ifndef TPE_STATEMACHINE_H
#define TPE_STATEMACHINE_H

#include "SemanticActions.h"

/*
 * @brief clase que representa una State Machine
 *
 * Implementa el State Pattern pero con Closures, evitando memory leaks
 * y el uso de objetos en memoria.
 *
 */
struct StateMachine
{
    bool finalState;
    SemanticAction (*state) (StateMachine* s, const unsigned int& value);

    SemanticAction getSemanticAction(const unsigned int& value)
    {
        return state(this, value);
    }
};

#endif //TPE_STATEMACHINE_H