#include "lexical-analyzer/StateMachine.h"
#include "lexical-analyzer/States.h"

StateMachine::StateMachine()
{
    finalState = false;
    state = States::state0;
}

SemanticAction StateMachine::getSemanticAction(const unsigned int& value)
{
    return state(this, value);
}