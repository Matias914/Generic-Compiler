#include "lexical-analyzer/States.h"
#include "lexical-analyzer/Translator.h"
#include "lexical-analyzer/ErrorHandler.h"

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
SemanticAction States::fstate(StateMachine* s, const unsigned int& value)
{
    s->finalState = true;
    s->state = fstate;
    return SemanticActions::DoNothing;
}

/*
 * @brief Estado de error. Al igual que el anterior, se creó para facilitar
 * el debugging y evitar errores inesperados.
 */
SemanticAction States::tstate(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    s->state = tstate;
    return SemanticActions::Trap;
}

/* ------------------------------ STATES ------------------------------ */

SemanticAction States::state0(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    switch(value)
    {
    case UPPER_CASE:

    case LOWER_CASE:
        s->state = state13;
        return SemanticActions::SA1;
    case NUMBER:

    case SPECIAL:
        s->state = fstate;
        s->finalState = true;
        return SemanticActions::SA13;
    case OPERATOR:

    case QUOTE:

    case DOT:

    case NUMERAL:
        s->state = state9;
        return SemanticActions::DoNothing;
    case PLUS:

    case MINUS:

    case BLANK:
        s->state = state0;
        return SemanticActions::DoNothing;
    // TODO: case ENDLINE: ya no hace falta XDDDD
    case ENDLINE:
        s->state = state0;
        return SemanticActions::DoNothing;
    default:
        s->state = tstate;
        return SemanticActions::Trap;
    }
}

SemanticAction  States::state1(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction  States::state2(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction  States::state3(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction  States::state4(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction  States::state5(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction  States::state6(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction  States::state7(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction  States::state8(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction  States::state9(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    switch (value)
    {
    case NUMERAL:
        s->state = state10;
        return SemanticActions::DoNothing;
    default:
        // TODO: Error?
        s->state = tstate;
        return SemanticActions::Trap;
    }
}

SemanticAction States::state10(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    switch (value)
    {
    case NUMERAL:
        s->state = state11;
        return SemanticActions::DoNothing;
    case ENDLINE:
        // TODO: ver que hacer con el token de ENDLINE
        // return SemanticActions::SA12;
        s->state = state10;
        return SemanticActions::DoNothing;
    default:
        s->state = state10;
        return SemanticActions::DoNothing;
    }
}

SemanticAction States::state11(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    switch (value)
    {
    case NUMERAL:
        s->state = state0;
        return SemanticActions::DoNothing;
    default:
        s->state = state10;
        return SemanticActions::DoNothing;
    }
}

SemanticAction States::state12(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction States::state13(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    switch (value)
    {
    case LOWER_CASE:
        s->state = state13;
        return SemanticActions::SA2;
    default:
        s->finalState = true;
        s->state = fstate;
        return SemanticActions::SA16;
    }
}

SemanticAction States::state14(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction States::state15(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}