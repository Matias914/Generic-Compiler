#include "lexical-analyzer/States.h"
#include "lexical-analyzer/Translator.h"

SemanticAction States::state0(StateMachine* s, const unsigned int& value)
{
    switch(value)
    {
    case UPPER_CASE:

    case LOWER_CASE:

    case NUMBER:

    case SPECIAL:

    case OPERATOR:

    case QUOTE:

    case DOT:

    case NUMERAL:

    case PLUS:

    case MINUS:

    case BLANK:
    // TODO: case ENDLINE: ya no hace falta XDDDD
    default: // OTHER
        return SemanticActions::SA1;
    }
}

SemanticAction  States::state1(StateMachine* s, const unsigned int& value)
{
    return SemanticActions::SA1;
}

SemanticAction  States::state2(StateMachine* s, const unsigned int& value)
{
    s->finalState = false;
    return SemanticActions::SA1;
}

SemanticAction  States::state3(StateMachine* s, const unsigned int& value)
{
    return SemanticActions::SA1;
}

SemanticAction  States::state4(StateMachine* s, const unsigned int& value)
{
    return SemanticActions::SA1;
}

SemanticAction  States::state5(StateMachine* s, const unsigned int& value)
{
    return SemanticActions::SA1;
}

SemanticAction  States::state6(StateMachine* s, const unsigned int& value)
{
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
    return SemanticActions::SA1;
}

SemanticAction States::state10(StateMachine* s, const unsigned int& value)
{
    return SemanticActions::SA1;
}

SemanticAction States::state11(StateMachine* s, const unsigned int& value)
{
    return SemanticActions::SA1;
}

SemanticAction States::state12(StateMachine* s, const unsigned int& value)
{
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
    return SemanticActions::SA1;
}

SemanticAction States::state15(StateMachine* s, const unsigned int& value)
{
    return SemanticActions::SA1;
}