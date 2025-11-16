#ifndef GC_STATES_H
#define GC_STATES_H

#include "StateMachine.h"

/*
 * @brief estas funciones implementan los estados del autómata del analizador
 * lexico.
 *
 * Tienen la responsabilidad de conocer la transicion al estado final.
 * También conocen la accion semantica asociada a cada una de sus transiciones.
 */
namespace LexicalAnalyzer::States
{
    SemanticAction  fstate(StateMachine* s, unsigned int value);

    SemanticAction  state0(StateMachine* s, unsigned int value);
    SemanticAction  state1(StateMachine* s, unsigned int value);
    SemanticAction  state2(StateMachine* s, unsigned int value);
    SemanticAction  state3(StateMachine* s, unsigned int value);
    SemanticAction  state4(StateMachine* s, unsigned int value);
    SemanticAction  state5(StateMachine* s, unsigned int value);
    SemanticAction  state6(StateMachine* s, unsigned int value);
    SemanticAction  state7(StateMachine* s, unsigned int value);
    SemanticAction  state8(StateMachine* s, unsigned int value);
    SemanticAction  state9(StateMachine* s, unsigned int value);
    SemanticAction state10(StateMachine* s, unsigned int value);
    SemanticAction state11(StateMachine* s, unsigned int value);
    SemanticAction state12(StateMachine* s, unsigned int value);
    SemanticAction state13(StateMachine* s, unsigned int value);
    SemanticAction state14(StateMachine* s, unsigned int value);
    SemanticAction state15(StateMachine* s, unsigned int value);
    SemanticAction state16(StateMachine* s, unsigned int value);
    SemanticAction state17(StateMachine* s, unsigned int value);
    SemanticAction state18(StateMachine* s, unsigned int value);
}
#endif //GC_STATES_H
