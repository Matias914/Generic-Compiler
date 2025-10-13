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
        SemanticAction (*state) (StateMachine* s, const unsigned int& value);

        StateMachine();
        bool endState() const;
        SemanticAction getSemanticAction(const unsigned int& value);
    };
}

#endif //GC_STATEMACHINE_H