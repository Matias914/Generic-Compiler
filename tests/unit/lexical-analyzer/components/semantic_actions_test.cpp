#include "gtest/gtest.h"
#include "utils/ErrorHandler.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "lexical-analyzer/components/semantic_actions.h"

using namespace LexicalAnalyzer;
using namespace LexicalAnalyzer::SemanticActions;

extern ErrorHandler ERROR_HANDLER;

// TODO: Chequear que anden todos los LOGS

TEST(TestSemanticActions, SA1)
{
    std::string lexeme = "a";
    constexpr char character = 'b';
    const LexemeData l = SA1(lexeme, character);
    EXPECT_EQ(l.token, INVALID_TOKEN);
    EXPECT_EQ(l.entry_reference, -1);
    EXPECT_EQ(lexeme, "b");
}

TEST(TestSemanticActions, SA2)
{
    std::string lexeme = "a";
    constexpr char character = 'b';
    const LexemeData l = SA2(lexeme, character);
    EXPECT_EQ(l.token, INVALID_TOKEN);
    EXPECT_EQ(l.entry_reference, -1);
    EXPECT_EQ(lexeme, "ab");
}

TEST(TestSemanticActions, SA3)
{
    std::string lexeme = "12U";
    constexpr char character = 'I';
    const LexemeData l1 = SA3(lexeme, character);
    EXPECT_EQ(l1.token, INTEGER_LITERAL);
    EXPECT_NE(l1.entry_reference, -1);
    EXPECT_EQ(lexeme, "12UI");
    lexeme = "12U";
    LexemeData l2 = SA3(lexeme, character);
    EXPECT_EQ(l1.entry_reference, l2.entry_reference);
    lexeme = "66300U";
    l2 = SA3(lexeme, character);
    EXPECT_EQ(l2.token, INVALID_TOKEN);
    EXPECT_EQ(l2.entry_reference, -1);
}

TEST(TestSemanticActions, SA4)
{
    std::string lexeme = "9.2F+37";
    constexpr char character = 'a';
    const LexemeData l1 = SA4(lexeme, character);
    EXPECT_EQ(l1.token, FLOAT_LITERAL);
    EXPECT_NE(l1.entry_reference, -1);
    EXPECT_EQ(lexeme, "9.2F+37");
    LexemeData l2 = SA4(lexeme, character);
    EXPECT_EQ(l1.entry_reference, l2.entry_reference);
    lexeme = "1.02F-39";
    l2 = SA4(lexeme, character);
    EXPECT_EQ(l2.token, INVALID_TOKEN);
    EXPECT_EQ(l2.entry_reference, -1);
    lexeme = "-0.1F-3";
    l2 = SA4(lexeme, character);
    EXPECT_EQ(l2.token, FLOAT_LITERAL);
    EXPECT_NE(l2.entry_reference, -1);
}

TEST(TestSemanticActions, SA5)
{
    std::string lexeme = "\"a";
    constexpr char character = '\"';
    const LexemeData l1 = SA5(lexeme, character);
    EXPECT_EQ(l1.token, STRING_LITERAL);
    EXPECT_NE(l1.entry_reference, -1);
    EXPECT_EQ(lexeme, "\"a\"");
    lexeme = "\"a";
    const LexemeData l2 = SA5(lexeme, character);
    EXPECT_EQ(l1.entry_reference, l2.entry_reference);
}

TEST(TestSemanticActions, SA6)
{
    std::string lexeme = "A";
    constexpr char character = 'B';
    const LexemeData l1 = SA6(lexeme, character);
    EXPECT_EQ(l1.token, IDENTIFIER);
    EXPECT_NE(l1.entry_reference, -1);
    EXPECT_EQ(lexeme, "A");
    const LexemeData l2 = SA6(lexeme, character);
    EXPECT_EQ(l1.entry_reference, l2.entry_reference);
    lexeme = "LONGVARIABLENAME%%%%%%";
    SA6(lexeme, character);
    const auto log = ERROR_HANDLER.getLastestLog();
    EXPECT_EQ(log->type, WARNING);
    EXPECT_EQ(log->code, TRUNCATED_VARIABLE);
}

TEST(TestSemanticActions, SA7)
{
    std::string lexeme = "a";
    constexpr char character = '\n';
    const int line = YYLINENO;
    const LexemeData l = SA7(lexeme, character);
    EXPECT_EQ(l.token, INVALID_TOKEN);
    EXPECT_EQ(l.entry_reference, -1);
    EXPECT_EQ(lexeme, "a");
    EXPECT_EQ(line + 1, YYLINENO);
}

TEST(TestSemanticActions, SA8)
{
    std::string lexeme = "";
    char character = '(';
    const LexemeData l1 = SA8(lexeme, character);
    EXPECT_EQ(l1.token, '(');
    EXPECT_EQ(l1.entry_reference, -1);
    EXPECT_EQ(lexeme, "");
    character = '+';
    const LexemeData l2 = SA8(lexeme, character);
    EXPECT_EQ(l2.token, '+');
}

TEST(TestSemanticActions, SA9)
{
    std::string lexeme = "";
    constexpr char character = '=';
    const LexemeData l = SA9(lexeme, character);
    EXPECT_EQ(l.token, EQUAL_OP);
    EXPECT_EQ(l.entry_reference, -1);
}

TEST(TestSemanticActions, SA10)
{
    std::string lexeme = "";
    constexpr char character = '!';
    const LexemeData l = SA10(lexeme, character);
    EXPECT_EQ(l.token, NOT_EQUAL_OP);
    EXPECT_EQ(l.entry_reference, -1);
}

TEST(TestSemanticActions, SA11)
{
    std::string lexeme = "";
    constexpr char character = '=';
    const LexemeData l = SA11(lexeme, character);
    EXPECT_EQ(l.token, ASSIGN_OP);
    EXPECT_EQ(l.entry_reference, -1);
}

TEST(TestSemanticActions, SA12)
{
    std::string lexeme = "";
    constexpr char character = '=';
    const LexemeData l = SA12(lexeme, character);
    EXPECT_EQ(l.token, LE_OP);
    EXPECT_EQ(l.entry_reference, -1);
}


TEST(TestSemanticActions, SA13)
{
    std::string lexeme = "";
    constexpr char character = '=';
    const LexemeData l = SA13(lexeme, character);
    EXPECT_EQ(l.token, GE_OP);
    EXPECT_EQ(l.entry_reference, -1);
}


TEST(TestSemanticActions, SA14)
{
    std::string lexeme = "";
    constexpr char character = '>';
    const LexemeData l = SA14(lexeme, character);
    EXPECT_EQ(l.token, POINTER_OP);
    EXPECT_EQ(l.entry_reference, -1);
}


TEST(TestSemanticActions, SA15)
{
    std::string lexeme = "";
    constexpr char character = 'a';
    const LexemeData l = SA15(lexeme, character);
    EXPECT_EQ(l.token, '=');
    EXPECT_EQ(l.entry_reference, -1);
}

TEST(TestSemanticActions, SA16)
{
    std::string lexeme = "";
    constexpr char character = 'a';
    const LexemeData l = SA16(lexeme, character);
    EXPECT_EQ(l.token, '<');
    EXPECT_EQ(l.entry_reference, -1);
}

TEST(TestSemanticActions, SA17)
{
    std::string lexeme = "";
    constexpr char character = 'a';
    const LexemeData l = SA17(lexeme, character);
    EXPECT_EQ(l.token, '>');
    EXPECT_EQ(l.entry_reference, -1);
}

TEST(TestSemanticActions, SA18)
{
    std::string lexeme = "";
    constexpr char character = 'a';
    const LexemeData l = SA18(lexeme, character);
    EXPECT_EQ(l.token, '-');
    EXPECT_EQ(l.entry_reference, -1);
}

TEST(TestSemanticActions, SA19)
{
    std::string lexeme = "if";
    constexpr char character = 'A';
    LexemeData l = SA19(lexeme, character);
    EXPECT_EQ(l.token, IF);
    EXPECT_EQ(l.entry_reference, -1);
    lexeme = "else";
    l = SA19(lexeme, character);
    EXPECT_EQ(l.token, ELSE);
    EXPECT_EQ(l.entry_reference, -1);
    lexeme = "ab";
    l = SA19(lexeme, character);
    EXPECT_EQ(l.token, INVALID_TOKEN);
    EXPECT_EQ(l.entry_reference, -1);
}