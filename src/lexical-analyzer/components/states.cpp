#include "lexical-analyzer/components/states.h"

#include "lexical-analyzer/components/lexical_tokens.h"
#include "lexical-analyzer/components/semantic_actions.h"

using namespace LexicalAnalyzer;

/*
 * @brief Estado final (sumidero) de la máquina de estados.
 *
 * Se utiliza para simplificar el debugging y evitar comportamientos
 * inesperados. Si desde cualquier estado se llega al final, basta con
 * activar el flag `finalState` sin importar en qué estado estaba antes.
 *
 * Al entrar en este estado final, la máquina queda inutilizable hasta
 * que se reinicialice para volver a usarse.
 */
SemanticAction States::fstate(StateMachine* s, const unsigned int value)
{
    s->state = fstate;
    return SemanticActions::DoNothing;
}

/* ------------------------------ STATES ------------------------------ */

SemanticAction  States::state0(StateMachine* s, const unsigned int value)
{
    switch(value)
    {
    case UPPER_CASE:
    case F:
    case I:
    case U:
        s->state = state12;
        return SemanticActions::SA1;
    case LOWER_CASE:
        s->state = state13;
        return SemanticActions::SA1;
    case NUMBER:
        s->state = state1;
        return SemanticActions::SA1;
    case PLUS:
    case SPECIAL:
        s->state = fstate;
        return SemanticActions::SA8;
    case QUOTE:
        s->state = state8;
        return SemanticActions::SA1;
    case DOT:
        s->state = state4;
        return SemanticActions::SA1;
    case EQUALS:
        s->state = state14;
        return SemanticActions::SA1;
    case GREATER:
        s->state = state17;
        return SemanticActions::SA1;
    case LESS:
        s->state = state16;
        return SemanticActions::SA1;
    case NUMERAL:
        s->state = state9;
        return SemanticActions::DoNothing;
    case COLON:
        s->state = state15;
        return SemanticActions::SA1;
    case MINUS:
        s->state = state18;
        return SemanticActions::SA1;
    case BLANK:
        s->state = state0;
        return SemanticActions::DoNothing;
    case ENDLINE:
        s->state = state0;
        return SemanticActions::SA7;
    case END_OF_FILE:
        s->state = fstate;
        return SemanticActions::EndOfFile;
    default:
        s->state = fstate;
        return SemanticActions::UnexpectedCharTrap;
    }
}

SemanticAction  States::state1(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case U:
        s->state = state2;
        return SemanticActions::SA2;
    case NUMBER:
        s->state = state1;
        return SemanticActions::SA2;
    case DOT:
        s->state = state3;
        return SemanticActions::SA2;
    default:
        s->state = fstate;
        return SemanticActions::ExpectedUITrap;
    }
}

SemanticAction  States::state2(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case I:
        s->state = fstate;
        return SemanticActions::SA3;
    default:
        s->state = fstate;
        return SemanticActions::ExpectedUITrap;
    }
}

SemanticAction  States::state3(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case F:
        s->state = state5;
        return SemanticActions::SA2;
    case NUMBER:
        s->state = state3;
        return SemanticActions::SA2;
    default:
        s->state = fstate;
        return SemanticActions::SA4;
    }
}

SemanticAction  States::state4(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case NUMBER:
        s->state = state3;
        return SemanticActions::SA2;
    default:
        s->state = fstate;
        return SemanticActions::SA15;
    }
}

SemanticAction  States::state5(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case MINUS:
    case PLUS:
        s->state = state6;
        return SemanticActions::SA2;
    default:
        s->state = fstate;
        return SemanticActions::ExpectedSignTrap;
    }
}

SemanticAction  States::state6(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case NUMBER:
        s->state = state7;
        return SemanticActions::SA2;
    default:
        s->state = fstate;
        return SemanticActions::ExpectedNumberTrap;
    }
}

SemanticAction  States::state7(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case NUMBER:
        s->state = state7;
        return SemanticActions::SA2;
    default:
        s->state = fstate;
        return SemanticActions::SA4;
    }
}

SemanticAction  States::state8(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case QUOTE:
        s->state = fstate;
        return SemanticActions::SA5;
    case ENDLINE:
        s->state = fstate;
        return SemanticActions::ExpectedNoEndlTrap;
    case END_OF_FILE:
        s->state = fstate;
        return SemanticActions::ExpectedQuoteTrap;
    default:
        s->state = state8;
        return SemanticActions::SA2;
    }
}

SemanticAction  States::state9(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case NUMERAL:
        s->state = state10;
        return SemanticActions::DoNothing;
    default:
        s->state = fstate;
        return SemanticActions::ExpectedNumeralTrap;
    }
}

SemanticAction States::state10(StateMachine* s, const unsigned int value)
{

    switch (value)
    {
    case NUMERAL:
        s->state = state11;
        return SemanticActions::DoNothing;
    case ENDLINE:
        s->state = state10;
        return SemanticActions::SA7;
    case END_OF_FILE:
        s->state = state0;
        return SemanticActions::ExpectedCommentEndTrap;
    default:
        s->state = state10;
        return SemanticActions::DoNothing;
    }
}

SemanticAction States::state11(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case NUMERAL:
        s->state = state0;
        return SemanticActions::DoNothing;
    case ENDLINE:
        s->state = state10;
        return SemanticActions::SA7;
    case END_OF_FILE:
        s->state = state0;
        return SemanticActions::ExpectedCommentEndTrap;
    default:
        s->state = state10;
        return SemanticActions::DoNothing;
    }
}

SemanticAction States::state12(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case F:
    case U:
    case I:
    case UPPER_CASE:
    case NUMBER:
    case PERCENTAGE:
        s->state = state12;
        return SemanticActions::SA2;
    default:
        s->state = fstate;
        return SemanticActions::SA6;
    }
}

SemanticAction States::state13(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case LOWER_CASE:
        s->state = state13;
        return SemanticActions::SA2;
    default:
        s->state = fstate;
        return SemanticActions::SA16;
    }
}

SemanticAction States::state14(StateMachine* s, const unsigned int value)
{
    s->state = fstate;
    switch (value)
    {
    case EQUALS:
        return SemanticActions::SA9;
    case EXCLAMATION:
        return SemanticActions::SA10;
    default:
        return SemanticActions::SA15;
    }
}

SemanticAction States::state15(StateMachine* s, const unsigned int value)
{
    switch (value)
    {
    case EQUALS:
        s->state = fstate;
        return SemanticActions::SA11;
    default:
        s->state = fstate;
        return SemanticActions::ExpectedEqualsTrap;
    }
}

SemanticAction States::state16(StateMachine* s, const unsigned int value)
{
    s->state = fstate;
    switch (value)
    {
    case EQUALS:
        return SemanticActions::SA12;
    default:
        return SemanticActions::SA15;
    }
}

SemanticAction States::state17(StateMachine* s, const unsigned int value)
{
    s->state = fstate;
    switch (value)
    {
    case EQUALS:
        return SemanticActions::SA13;
    default:
        return SemanticActions::SA15;
    }
}

SemanticAction States::state18(StateMachine* s, const unsigned int value)
{
    s->state = fstate;
    switch (value)
    {
    case GREATER:
        return SemanticActions::SA14;
    default:
        return SemanticActions::SA15;
    }
}