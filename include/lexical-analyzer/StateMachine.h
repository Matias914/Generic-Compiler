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
class StateMachine
{
public:
    bool finalState;
    SemanticAction (*state) (StateMachine* s, const unsigned int& value);

    StateMachine();
    SemanticAction getSemanticAction(const unsigned int& value);
};

#endif //TPE_STATEMACHINE_H