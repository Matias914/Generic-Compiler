#include "gtest/gtest.h"
#include "lexical-analyzer/States.h"
#include "lexical-analyzer/Translator.h"

// TODO: faltan estados

TEST(TestStates, state0)
{
    StateMachine sm;
    // Case LOWER CASE
    EXPECT_EQ(States::state0(&sm, Translator::translate('i')), SemanticActions::SA1);
    EXPECT_EQ(sm.state, States::state13);
    EXPECT_FALSE(sm.finalState);
    // Case SPECIAL
    EXPECT_EQ(States::state0(&sm, Translator::translate('(')), SemanticActions::SA13);
    EXPECT_EQ(sm.state, States::fstate);
    EXPECT_TRUE(sm.finalState);
    // Case NUMERAL
    EXPECT_EQ(States::state0(&sm, Translator::translate('#')), SemanticActions::DoNothing);
    EXPECT_EQ(sm.state, States::state9);
    EXPECT_FALSE(sm.finalState);
    // Case OTHER
    EXPECT_EQ(States::state0(&sm, Translator::translate('~')), SemanticActions::Trap);
    EXPECT_EQ(sm.state, States::tstate);
    EXPECT_FALSE(sm.finalState);
}

TEST(TestStates, state9)
{
    StateMachine sm;
    EXPECT_EQ(States::state9(&sm, Translator::translate('#')), SemanticActions::DoNothing);
    EXPECT_EQ(sm.state, States::state10);
    EXPECT_FALSE(sm.finalState);
    // TODO: Ver que hacer.
}

TEST(TestStates, state10)
{
    StateMachine sm;
    // Case NUMERAL
    EXPECT_EQ(States::state10(&sm, Translator::translate('#')), SemanticActions::DoNothing);
    EXPECT_EQ(sm.state, States::state11);
    EXPECT_FALSE(sm.finalState);
    // Case OTHER
    EXPECT_EQ(States::state10(&sm, Translator::translate('+')), SemanticActions::DoNothing);
    EXPECT_EQ(sm.state, States::state10);
    EXPECT_FALSE(sm.finalState);
}

TEST(TestStates, state11)
{
    StateMachine sm;
    // Case NUMERAL
    EXPECT_EQ(States::state11(&sm, Translator::translate('#')), SemanticActions::DoNothing);
    EXPECT_EQ(sm.state, States::state0);
    EXPECT_FALSE(sm.finalState);
    // Case OTHER
    EXPECT_EQ(States::state11(&sm, Translator::translate('+')), SemanticActions::DoNothing);
    EXPECT_EQ(sm.state, States::state10);
    EXPECT_FALSE(sm.finalState);
}

