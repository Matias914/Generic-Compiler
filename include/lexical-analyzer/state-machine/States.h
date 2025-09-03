#ifndef TPE_STATES_H
#define TPE_STATES_H

#include "StateMachine.h"

/*
 * @brief Estas funciones implementan los estados del autómata.
 *
 * Tienen la responsabilidad de conocer la transicion al estado final.
 * También conocen la accion semantica asociada a cada una de sus transiciones.
 *
 */

namespace State
{
    SemanticAction*  state0(StateMachine* s, const unsigned int& value);
    SemanticAction*  state1(StateMachine* s, const unsigned int& value);
    SemanticAction*  state2(StateMachine* s, const unsigned int& value);
    SemanticAction*  state3(StateMachine* s, const unsigned int& value);
    SemanticAction*  state4(StateMachine* s, const unsigned int& value);
    SemanticAction*  state5(StateMachine* s, const unsigned int& value);
    SemanticAction*  state6(StateMachine* s, const unsigned int& value);
    SemanticAction*  state7(StateMachine* s, const unsigned int& value);
    SemanticAction*  state8(StateMachine* s, const unsigned int& value);
    SemanticAction*  state9(StateMachine* s, const unsigned int& value);
    SemanticAction* state10(StateMachine* s, const unsigned int& value);
    SemanticAction* state11(StateMachine* s, const unsigned int& value);
    SemanticAction* state12(StateMachine* s, const unsigned int& value);
    SemanticAction* state13(StateMachine* s, const unsigned int& value);
    SemanticAction* state14(StateMachine* s, const unsigned int& value);
    SemanticAction* state15(StateMachine* s, const unsigned int& value);
}
#endif //TPE_STATES_H