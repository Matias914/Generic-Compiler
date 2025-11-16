#ifndef GC_STATEMACHINE_H
#define GC_STATEMACHINE_H

#include "semantic_actions.h"

/*
 * @brief clase que representa una State Machine.
 *
 * Implementa el State Pattern pero con funciones. Tiene la misma funcion que
 * la matriz de transicion de estados.
 */
namespace LexicalAnalyzer
{
    class StateMachine
    {
    public:
        SemanticAction (*state) (StateMachine* s, unsigned int value);

        StateMachine();
        bool endState() const;
        SemanticAction getSemanticAction(unsigned int value);
    };
}

#endif //GC_STATEMACHINE_H