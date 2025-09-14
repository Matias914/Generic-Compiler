#include "gtest/gtest.h"
#include "lexical-analyzer/components/states.h"
#include "lexical-analyzer/components/translator.h"

using namespace LexicalAnalyzer;
using namespace LexicalAnalyzer::States;
using namespace LexicalAnalyzer::SemanticActions;

/*
 * @biref por cada estado se comprueban sus transiciones. Más que nada,
 * el siguiente estado y si llego al estado final.
 */
using State = SemanticAction (*) (StateMachine* s, const unsigned int& value);

struct TestState
{
    StateMachine sm;
    State state;

    void test(const int& value, const State& next, const SemanticAction& sa, const bool& fs)
    {
        EXPECT_EQ(state(&sm, value), sa);
        EXPECT_EQ(sm.state, next);
        EXPECT_EQ(sm.finalState, fs);
    }
};

TEST(TestStates, state0)
{
    TestState ts = {StateMachine(), state0};
    ts.test(UPPER_CASE , state12 ,   SA1      , false);
    ts.test(F          , state12 ,   SA1      , false);
    ts.test(I          , state12 ,   SA1      , false);
    ts.test(U          , state12 ,   SA1      , false);
    ts.test(LOWER_CASE , state13 ,   SA1      , false);
    ts.test(NUMBER     , state1 ,    SA1      , false);
    ts.test(SPECIAL    , fstate ,    SA8      , true);
    ts.test(PERCENTAGE , state0 , Trap     , false);
    ts.test(QUOTE      , state8 ,    SA1      , false);
    ts.test(DOT        , state4 ,    SA1      , false);
    ts.test(EQUALS     , state14, DoNothing, false);
    ts.test(EXCLAMATION, state0 , Trap     , false);
    ts.test(GREATER    , state17, DoNothing, false);
    ts.test(LESS       , state16, DoNothing, false);
    ts.test(NUMERAL    , state9 , DoNothing, false);
    ts.test(COLON      , state15, DoNothing, false);
    ts.test(MINUS      , state18, DoNothing, false);
    ts.test(PLUS       , fstate ,    SA8      , true);
    ts.test(BLANK      , state0 , DoNothing, false);
    ts.test(ENDLINE    , state0 ,    SA7      , false);
    ts.test(OTHER      , state0 , Trap     , false);
}

TEST(TestStates, state1)
{
    TestState ts = {StateMachine(), state1};
    ts.test(UPPER_CASE , state0 , Trap, false);
    ts.test(F          , state0 , Trap, false);
    ts.test(I          , state0 , Trap, false);
    ts.test(U          , state2 ,    SA2 , false);
    ts.test(LOWER_CASE , state0 , Trap, false);
    ts.test(NUMBER     , state1 ,    SA2 , false);
    ts.test(SPECIAL    , state0 , Trap, false);
    ts.test(PERCENTAGE , state0 , Trap, false);
    ts.test(QUOTE      , state0 , Trap, false);
    ts.test(DOT        , state3 ,    SA2 , false);
    ts.test(EQUALS     , state0 , Trap, false);
    ts.test(EXCLAMATION, state0 , Trap, false);
    ts.test(GREATER    , state0 , Trap, false);
    ts.test(LESS       , state0 , Trap, false);
    ts.test(NUMERAL    , state0 , Trap, false);
    ts.test(COLON      , state0 , Trap, false);
    ts.test(MINUS      , state0 , Trap, false);
    ts.test(PLUS       , state0 , Trap, false);
    ts.test(BLANK      , state0 , Trap, false);
    ts.test(ENDLINE    , state0 , Trap, false);
    ts.test(OTHER      , state0 , Trap, false);
}

TEST(TestStates, state2)
{
    TestState ts = {StateMachine(), state2};
    ts.test(UPPER_CASE , state0 , Trap, false);
    ts.test(F          , state0 , Trap, false);
    ts.test(I          , fstate ,    SA3 , true );
    ts.test(U          , state0 , Trap, false);
    ts.test(LOWER_CASE , state0 , Trap, false);
    ts.test(NUMBER     , state0 , Trap, false);
    ts.test(SPECIAL    , state0 , Trap, false);
    ts.test(PERCENTAGE , state0 , Trap, false);
    ts.test(QUOTE      , state0 , Trap, false);
    ts.test(DOT        , state0 , Trap, false);
    ts.test(EQUALS     , state0 , Trap, false);
    ts.test(EXCLAMATION, state0 , Trap, false);
    ts.test(GREATER    , state0 , Trap, false);
    ts.test(LESS       , state0 , Trap, false);
    ts.test(NUMERAL    , state0 , Trap, false);
    ts.test(COLON      , state0 , Trap, false);
    ts.test(MINUS      , state0 , Trap, false);
    ts.test(PLUS       , state0 , Trap, false);
    ts.test(BLANK      , state0 , Trap, false);
    ts.test(ENDLINE    , state0 , Trap, false);
    ts.test(OTHER      , state0 , Trap, false);
}

TEST(TestStates, state3)
{
    TestState ts = {StateMachine(), state3};
    ts.test(UPPER_CASE , fstate ,    SA4 , true );
    ts.test(F          , state5 ,    SA2 , false);
    ts.test(I          , fstate ,    SA4 , true );
    ts.test(U          , fstate ,    SA4 , true );
    ts.test(LOWER_CASE , fstate ,    SA4 , true );
    ts.test(NUMBER     , state3 ,    SA2 , false);
    ts.test(SPECIAL    , fstate ,    SA4 , true );
    ts.test(PERCENTAGE , fstate ,    SA4 , true );
    ts.test(QUOTE      , fstate ,    SA4 , true );
    ts.test(DOT        , fstate ,    SA4 , true );
    ts.test(EQUALS     , fstate ,    SA4 , true );
    ts.test(EXCLAMATION, fstate ,    SA4 , true );
    ts.test(GREATER    , fstate ,    SA4 , true );
    ts.test(LESS       , fstate ,    SA4 , true );
    ts.test(NUMERAL    , fstate ,    SA4 , true );
    ts.test(COLON      , fstate ,    SA4 , true );
    ts.test(MINUS      , fstate ,    SA4 , true );
    ts.test(PLUS       , fstate ,    SA4 , true );
    ts.test(BLANK      , fstate ,    SA4 , true );
    ts.test(ENDLINE    , fstate ,    SA4 , true );
    ts.test(OTHER      , fstate ,    SA4,  true );
}

TEST(TestStates, state4)
{
    TestState ts = {StateMachine(), state4};
    ts.test(UPPER_CASE , state0 , Trap, false);
    ts.test(F          , state0 , Trap, false);
    ts.test(I          , state0 , Trap, false);
    ts.test(U          , state0 , Trap, false);
    ts.test(LOWER_CASE , state0 , Trap, false);
    ts.test(NUMBER     , state3 ,    SA2 , false);
    ts.test(SPECIAL    , state0 , Trap, false);
    ts.test(PERCENTAGE , state0 , Trap, false);
    ts.test(QUOTE      , state0 , Trap, false);
    ts.test(DOT        , state0 , Trap, false);
    ts.test(EQUALS     , state0 , Trap, false);
    ts.test(EXCLAMATION, state0 , Trap, false);
    ts.test(GREATER    , state0 , Trap, false);
    ts.test(LESS       , state0 , Trap, false);
    ts.test(NUMERAL    , state0 , Trap, false);
    ts.test(COLON      , state0 , Trap, false);
    ts.test(MINUS      , state0 , Trap, false);
    ts.test(PLUS       , state0 , Trap, false);
    ts.test(BLANK      , state0 , Trap, false);
    ts.test(ENDLINE    , state0 , Trap, false);
    ts.test(OTHER      , state0 , Trap, false);
}

TEST(TestStates, state5)
{
    TestState ts = {StateMachine(), state5};
    ts.test(UPPER_CASE , state0 , Trap, false);
    ts.test(F          , state0 , Trap, false);
    ts.test(I          , state0 , Trap, false);
    ts.test(U          , state0 , Trap, false);
    ts.test(LOWER_CASE , state0 , Trap, false);
    ts.test(NUMBER     , state0 , Trap, false);
    ts.test(SPECIAL    , state0 , Trap, false);
    ts.test(PERCENTAGE , state0 , Trap, false);
    ts.test(QUOTE      , state0 , Trap, false);
    ts.test(DOT        , state0 , Trap, false);
    ts.test(EQUALS     , state0 , Trap, false);
    ts.test(EXCLAMATION, state0 , Trap, false);
    ts.test(GREATER    , state0 , Trap, false);
    ts.test(LESS       , state0 , Trap, false);
    ts.test(NUMERAL    , state0 , Trap, false);
    ts.test(COLON      , state0 , Trap, false);
    ts.test(MINUS      , state6 ,    SA2 , false);
    ts.test(PLUS       , state6 ,    SA2 , false);
    ts.test(BLANK      , state0 , Trap, false);
    ts.test(ENDLINE    , state0 , Trap, false);
    ts.test(OTHER      , state0 , Trap, false);
}

TEST(TestStates, state6)
{
    TestState ts = {StateMachine(), state6};
    ts.test(UPPER_CASE , state0 , Trap, false);
    ts.test(F          , state0 , Trap, false);
    ts.test(I          , state0 , Trap, false);
    ts.test(U          , state0 , Trap, false);
    ts.test(LOWER_CASE , state0 , Trap, false);
    ts.test(NUMBER     , state7 ,    SA2 , false);
    ts.test(SPECIAL    , state0 , Trap, false);
    ts.test(PERCENTAGE , state0 , Trap, false);
    ts.test(QUOTE      , state0 , Trap, false);
    ts.test(DOT        , state0 , Trap, false);
    ts.test(EQUALS     , state0 , Trap, false);
    ts.test(EXCLAMATION, state0 , Trap, false);
    ts.test(GREATER    , state0 , Trap, false);
    ts.test(LESS       , state0 , Trap, false);
    ts.test(NUMERAL    , state0 , Trap, false);
    ts.test(COLON      , state0 , Trap, false);
    ts.test(MINUS      , state0 , Trap, false);
    ts.test(PLUS       , state0 , Trap, false);
    ts.test(BLANK      , state0 , Trap, false);
    ts.test(ENDLINE    , state0 , Trap, false);
    ts.test(OTHER      , state0 , Trap, false);
}

TEST(TestStates, state7)
{
    TestState ts = {StateMachine(), state7};
    ts.test(UPPER_CASE , fstate ,    SA4 , true );
    ts.test(F          , fstate ,    SA4 , true );
    ts.test(I          , fstate ,    SA4 , true );
    ts.test(U          , fstate ,    SA4 , true );
    ts.test(LOWER_CASE , fstate ,    SA4 , true );
    ts.test(NUMBER     , state7 ,    SA2 , false);
    ts.test(SPECIAL    , fstate ,    SA4 , true );
    ts.test(PERCENTAGE , fstate ,    SA4 , true );
    ts.test(QUOTE      , fstate ,    SA4 , true );
    ts.test(DOT        , fstate ,    SA4 , true );
    ts.test(EQUALS     , fstate ,    SA4 , true );
    ts.test(EXCLAMATION, fstate ,    SA4 , true );
    ts.test(GREATER    , fstate ,    SA4 , true );
    ts.test(LESS       , fstate ,    SA4 , true );
    ts.test(NUMERAL    , fstate ,    SA4 , true );
    ts.test(COLON      , fstate ,    SA4 , true );
    ts.test(MINUS      , fstate ,    SA4 , true );
    ts.test(PLUS       , fstate ,    SA4 , true );
    ts.test(BLANK      , fstate ,    SA4 , true );
    ts.test(ENDLINE    , fstate ,    SA4 , true );
    ts.test(OTHER      , fstate ,    SA4,  true );
}

TEST(TestStates, state8)
{
    TestState ts = {StateMachine(), state8};
    ts.test(UPPER_CASE , state8,     SA2, false);
    ts.test(F          , state8,     SA2, false);
    ts.test(I          , state8,     SA2, false);
    ts.test(U          , state8,     SA2, false);
    ts.test(LOWER_CASE , state8,     SA2, false);
    ts.test(NUMBER     , state8,     SA2, false);
    ts.test(PERCENTAGE , state8,     SA2, false);
    ts.test(QUOTE      , fstate,     SA5, true);
    ts.test(SPECIAL    , state8,     SA2, false);
    ts.test(DOT        , state8,     SA2, false);
    ts.test(EQUALS     , state8,     SA2, false);
    ts.test(EXCLAMATION, state8,     SA2, false);
    ts.test(GREATER    , state8,     SA2, false);
    ts.test(LESS       , state8,     SA2, false);
    ts.test(NUMERAL    , state8,     SA2, false);
    ts.test(COLON      , state8,     SA2, false);
    ts.test(MINUS      , state8,     SA2, false);
    ts.test(PLUS       , state8,     SA2, false);
    ts.test(BLANK      , state8,     SA2, false);
    ts.test(ENDLINE    , state0, Trap, false);
    ts.test(OTHER      , state8,     SA2, false);
}

TEST(TestStates, state9)
{
    TestState ts = {StateMachine(), state9};
    ts.test(UPPER_CASE , state0 , Trap     , false);
    ts.test(F          , state0 , Trap     , false);
    ts.test(I          , state0 , Trap     , false);
    ts.test(U          , state0 , Trap     , false);
    ts.test(LOWER_CASE , state0 , Trap     , false);
    ts.test(NUMBER     , state0 , Trap     , false);
    ts.test(SPECIAL    , state0 , Trap     , false);
    ts.test(PERCENTAGE , state0 , Trap     , false);
    ts.test(QUOTE      , state0 , Trap     , false);
    ts.test(DOT        , state0 , Trap     , false);
    ts.test(EQUALS     , state0 , Trap     , false);
    ts.test(EXCLAMATION, state0 , Trap     , false);
    ts.test(GREATER    , state0 , Trap     , false);
    ts.test(LESS       , state0 , Trap     , false);
    ts.test(NUMERAL    , state10, DoNothing, false);
    ts.test(COLON      , state0 , Trap     , false);
    ts.test(MINUS      , state0 , Trap     , false);
    ts.test(PLUS       , state0 , Trap     , false);
    ts.test(BLANK      , state0 , Trap     , false);
    ts.test(ENDLINE    , state0 , Trap     , false);
    ts.test(OTHER      , state0 , Trap     , false);
}

TEST(TestStates, state10)
{
    TestState ts = {StateMachine(), state10};
    ts.test(UPPER_CASE , state10, DoNothing, false);
    ts.test(F          , state10, DoNothing, false);
    ts.test(I          , state10, DoNothing, false);
    ts.test(U          , state10, DoNothing, false);
    ts.test(LOWER_CASE , state10, DoNothing, false);
    ts.test(NUMBER     , state10, DoNothing, false);
    ts.test(SPECIAL    , state10, DoNothing, false);
    ts.test(PERCENTAGE , state10, DoNothing, false);
    ts.test(QUOTE      , state10, DoNothing, false);
    ts.test(DOT        , state10, DoNothing, false);
    ts.test(EQUALS     , state10, DoNothing, false);
    ts.test(EXCLAMATION, state10, DoNothing, false);
    ts.test(GREATER    , state10, DoNothing, false);
    ts.test(LESS       , state10, DoNothing, false);
    ts.test(NUMERAL    , state11, DoNothing, false);
    ts.test(COLON      , state10, DoNothing, false);
    ts.test(MINUS      , state10, DoNothing, false);
    ts.test(PLUS       , state10, DoNothing, false);
    ts.test(BLANK      , state10, DoNothing, false);
    ts.test(ENDLINE    , state10,    SA7      , false);
    ts.test(OTHER      , state10, DoNothing, false);
}

TEST(TestStates, state11)
{
    TestState ts = {StateMachine(), state11};
    ts.test(UPPER_CASE , state10, DoNothing, false);
    ts.test(F          , state10, DoNothing, false);
    ts.test(I          , state10, DoNothing, false);
    ts.test(U          , state10, DoNothing, false);
    ts.test(LOWER_CASE , state10, DoNothing, false);
    ts.test(NUMBER     , state10, DoNothing, false);
    ts.test(SPECIAL    , state10, DoNothing, false);
    ts.test(PERCENTAGE , state10, DoNothing, false);
    ts.test(QUOTE      , state10, DoNothing, false);
    ts.test(DOT        , state10, DoNothing, false);
    ts.test(EQUALS     , state10, DoNothing, false);
    ts.test(EXCLAMATION, state10, DoNothing, false);
    ts.test(GREATER    , state10, DoNothing, false);
    ts.test(LESS       , state10, DoNothing, false);
    ts.test(NUMERAL    , state0 , DoNothing, false);
    ts.test(COLON      , state10, DoNothing, false);
    ts.test(MINUS      , state10, DoNothing, false);
    ts.test(PLUS       , state10, DoNothing, false);
    ts.test(BLANK      , state10, DoNothing, false);
    ts.test(ENDLINE    , state10, DoNothing, false);
    ts.test(OTHER      , state10, DoNothing, false);
}

TEST(TestStates, state12)
{
    TestState ts = {StateMachine(), state12};
    ts.test(UPPER_CASE , state12, SA2, false);
    ts.test(F          , state12, SA2, false);
    ts.test(I          , state12, SA2, false);
    ts.test(U          , state12, SA2, false);
    ts.test(LOWER_CASE , fstate , SA6, true);
    ts.test(NUMBER     , state12, SA2, false);
    ts.test(PERCENTAGE , state12, SA2, false);
    ts.test(SPECIAL    , fstate , SA6, true);
    ts.test(QUOTE      , fstate , SA6, true);
    ts.test(DOT        , fstate , SA6, true);
    ts.test(EQUALS     , fstate , SA6, true);
    ts.test(EXCLAMATION, fstate , SA6, true);
    ts.test(GREATER    , fstate , SA6, true);
    ts.test(LESS       , fstate , SA6, true);
    ts.test(NUMERAL    , fstate , SA6, true);
    ts.test(COLON      , fstate , SA6, true);
    ts.test(MINUS      , fstate , SA6, true);
    ts.test(PLUS       , fstate , SA6, true);
    ts.test(BLANK      , fstate , SA6, true);
    ts.test(ENDLINE    , fstate , SA6, true);
    ts.test(OTHER      , fstate , SA6, true);
}

TEST(TestStates, state13)
{
    TestState ts = {StateMachine(), state13};
    ts.test(UPPER_CASE , fstate , SA19, true);
    ts.test(F          , fstate , SA19, true);
    ts.test(I          , fstate , SA19, true);
    ts.test(U          , fstate , SA19, true);
    ts.test(LOWER_CASE , state13, SA2 , false);
    ts.test(NUMBER     , fstate , SA19, true);
    ts.test(PERCENTAGE , fstate , SA19, true);
    ts.test(SPECIAL    , fstate , SA19, true);
    ts.test(QUOTE      , fstate , SA19, true);
    ts.test(DOT        , fstate , SA19, true);
    ts.test(EQUALS     , fstate , SA19, true);
    ts.test(EXCLAMATION, fstate , SA19, true);
    ts.test(GREATER    , fstate , SA19, true);
    ts.test(LESS       , fstate , SA19, true);
    ts.test(NUMERAL    , fstate , SA19, true);
    ts.test(COLON      , fstate , SA19, true);
    ts.test(MINUS      , fstate , SA19, true);
    ts.test(PLUS       , fstate , SA19, true);
    ts.test(BLANK      , fstate , SA19, true);
    ts.test(ENDLINE    , fstate , SA19, true);
    ts.test(OTHER      , fstate , SA19, true);
}

TEST(TestStates, state14)
{
    TestState ts = {StateMachine(), state14};
    ts.test(UPPER_CASE , fstate, SA15, true);
    ts.test(F          , fstate, SA15, true);
    ts.test(I          , fstate, SA15, true);
    ts.test(U          , fstate, SA15, true);
    ts.test(LOWER_CASE , fstate, SA15, true);
    ts.test(NUMBER     , fstate, SA15, true);
    ts.test(PERCENTAGE , fstate, SA15, true);
    ts.test(SPECIAL    , fstate, SA15, true);
    ts.test(QUOTE      , fstate, SA15, true);
    ts.test(DOT        , fstate, SA15, true);
    ts.test(EQUALS     , fstate, SA9 , true);
    ts.test(EXCLAMATION, fstate, SA10, true);
    ts.test(GREATER    , fstate, SA15, true);
    ts.test(LESS       , fstate, SA15, true);
    ts.test(NUMERAL    , fstate, SA15, true);
    ts.test(COLON      , fstate, SA15, true);
    ts.test(MINUS      , fstate, SA15, true);
    ts.test(PLUS       , fstate, SA15, true);
    ts.test(BLANK      , fstate, SA15, true);
    ts.test(ENDLINE    , fstate, SA15, true);
    ts.test(OTHER      , fstate, SA15, true);
}

TEST(TestStates, state15)
{
    TestState ts = {StateMachine(), state15};
    ts.test(UPPER_CASE , state0, Trap, false);
    ts.test(F          , state0, Trap, false);
    ts.test(I          , state0, Trap, false);
    ts.test(U          , state0, Trap, false);
    ts.test(LOWER_CASE , state0, Trap, false);
    ts.test(NUMBER     , state0, Trap, false);
    ts.test(PERCENTAGE , state0, Trap, false);
    ts.test(SPECIAL    , state0, Trap, false);
    ts.test(QUOTE      , state0, Trap, false);
    ts.test(DOT        , state0, Trap, false);
    ts.test(EQUALS     , fstate,    SA11, true);
    ts.test(EXCLAMATION, state0, Trap, false);
    ts.test(GREATER    , state0, Trap, false);
    ts.test(LESS       , state0, Trap, false);
    ts.test(NUMERAL    , state0, Trap, false);
    ts.test(COLON      , state0, Trap, false);
    ts.test(MINUS      , state0, Trap, false);
    ts.test(PLUS       , state0, Trap, false);
    ts.test(BLANK      , state0, Trap, false);
    ts.test(ENDLINE    , state0, Trap, false);
    ts.test(OTHER      , state0, Trap, false);
}

TEST(TestStates, state16)
{
    TestState ts = {StateMachine(), state16};
    ts.test(UPPER_CASE , fstate, SA16, true);
    ts.test(F          , fstate, SA16, true);
    ts.test(I          , fstate, SA16, true);
    ts.test(U          , fstate, SA16, true);
    ts.test(LOWER_CASE , fstate, SA16, true);
    ts.test(NUMBER     , fstate, SA16, true);
    ts.test(PERCENTAGE , fstate, SA16, true);
    ts.test(SPECIAL    , fstate, SA16, true);
    ts.test(QUOTE      , fstate, SA16, true);
    ts.test(DOT        , fstate, SA16, true);
    ts.test(EQUALS     , fstate, SA12, true);
    ts.test(EXCLAMATION, fstate, SA16, true);
    ts.test(GREATER    , fstate, SA16, true);
    ts.test(LESS       , fstate, SA16, true);
    ts.test(NUMERAL    , fstate, SA16, true);
    ts.test(COLON      , fstate, SA16, true);
    ts.test(MINUS      , fstate, SA16, true);
    ts.test(PLUS       , fstate, SA16, true);
    ts.test(BLANK      , fstate, SA16, true);
    ts.test(ENDLINE    , fstate, SA16, true);
    ts.test(OTHER      , fstate, SA16, true);
}

TEST(TestStates, state17)
{
    TestState ts = {StateMachine(), state17};
    ts.test(UPPER_CASE , fstate, SA17, true);
    ts.test(F          , fstate, SA17, true);
    ts.test(I          , fstate, SA17, true);
    ts.test(U          , fstate, SA17, true);
    ts.test(LOWER_CASE , fstate, SA17, true);
    ts.test(NUMBER     , fstate, SA17, true);
    ts.test(PERCENTAGE , fstate, SA17, true);
    ts.test(SPECIAL    , fstate, SA17, true);
    ts.test(QUOTE      , fstate, SA17, true);
    ts.test(DOT        , fstate, SA17, true);
    ts.test(EQUALS     , fstate, SA13, true);
    ts.test(EXCLAMATION, fstate, SA17, true);
    ts.test(GREATER    , fstate, SA17, true);
    ts.test(LESS       , fstate, SA17, true);
    ts.test(NUMERAL    , fstate, SA17, true);
    ts.test(COLON      , fstate, SA17, true);
    ts.test(MINUS      , fstate, SA17, true);
    ts.test(PLUS       , fstate, SA17, true);
    ts.test(BLANK      , fstate, SA17, true);
    ts.test(ENDLINE    , fstate, SA17, true);
    ts.test(OTHER      , fstate, SA17, true);
}

TEST(TestStates, state18)
{
    TestState ts = {StateMachine(), state18};
    ts.test(UPPER_CASE , fstate, SA18, true);
    ts.test(F          , fstate, SA18, true);
    ts.test(I          , fstate, SA18, true);
    ts.test(U          , fstate, SA18, true);
    ts.test(LOWER_CASE , fstate, SA18, true);
    ts.test(NUMBER     , fstate, SA18, true);
    ts.test(PERCENTAGE , fstate, SA18, true);
    ts.test(SPECIAL    , fstate, SA18, true);
    ts.test(QUOTE      , fstate, SA18, true);
    ts.test(DOT        , fstate, SA18, true);
    ts.test(EQUALS     , fstate, SA18, true);
    ts.test(EXCLAMATION, fstate, SA18, true);
    ts.test(GREATER    , fstate, SA14, true);
    ts.test(LESS       , fstate, SA18, true);
    ts.test(NUMERAL    , fstate, SA18, true);
    ts.test(COLON      , fstate, SA18, true);
    ts.test(MINUS      , fstate, SA18, true);
    ts.test(PLUS       , fstate, SA18, true);
    ts.test(BLANK      , fstate, SA18, true);
    ts.test(ENDLINE    , fstate, SA18, true);
    ts.test(OTHER      , fstate, SA18, true);
}
