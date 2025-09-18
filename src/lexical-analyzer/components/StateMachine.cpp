#include "lexical-analyzer/components/states.h"
#include "lexical-analyzer/components/StateMachine.h"

using namespace LexicalAnalyzer;

StateMachine::StateMachine()
{
    state = States::state0;
}

SemanticAction StateMachine::getSemanticAction(const unsigned int& value)
{
    return state(this, value);
}

bool StateMachine::endState() const
{
    return this->state == States::fstate;
}