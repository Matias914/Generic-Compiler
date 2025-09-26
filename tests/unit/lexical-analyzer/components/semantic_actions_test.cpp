#include "gtest/gtest.h"
#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "lexical-analyzer/components/semantic_actions.h"

using namespace LexicalAnalyzer;
using namespace LexicalAnalyzer::SemanticActions;

extern ErrorHandler ERROR_HANDLER;

TEST(TestSemanticActions, DoNothing)
{
    std::string lexeme = "a";
    constexpr char character = 'b';
    const LexemeData l = DoNothing(lexeme, character);
    EXPECT_EQ(l.token, INVALID_TOKEN);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
    EXPECT_EQ(lexeme, "a");
}

TEST(TestSemanticActions, EndOfFile)
{
    std::string lexeme = "a";
    constexpr char character = 'b';
    const LexemeData l = EndOfFile(lexeme, character);
    EXPECT_EQ(l.token, YYEOF);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
    EXPECT_EQ(lexeme, "a");
}

TEST(TestSemanticActions, SA1)
{
    std::string lexeme = "a";
    constexpr char character = 'b';
    const LexemeData l = SA1(lexeme, character);
    EXPECT_EQ(l.token, INVALID_TOKEN);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
    EXPECT_EQ(lexeme, "b");
}

TEST(TestSemanticActions, SA2)
{
    std::string lexeme = "a";
    constexpr char character = 'b';
    const LexemeData l = SA2(lexeme, character);
    EXPECT_EQ(l.token, INVALID_TOKEN);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
    EXPECT_EQ(lexeme, "ab");
}

TEST(TestSemanticActions, SA3)
{
    std::string lexeme = "12U";
    constexpr char character = 'I';
    const LexemeData l1 = SA3(lexeme, character);
    EXPECT_EQ(l1.token, UINTEGER_LITERAL);
    EXPECT_EQ(l1.symbol_reference, nullptr);
    EXPECT_NE(l1.constant_reference, nullptr);
    EXPECT_EQ(lexeme, "12UI");
    lexeme = "12U";
    LexemeData l2 = SA3(lexeme, character);
    EXPECT_EQ(l1.symbol_reference, nullptr);
    EXPECT_EQ(l1.constant_reference, l2.constant_reference);
    lexeme = "66300U";
    l2 = SA3(lexeme, character);
    EXPECT_EQ(l2.token, INVALID_TOKEN);
    EXPECT_EQ(l1.symbol_reference, nullptr);
    EXPECT_EQ(l2.constant_reference, nullptr);
    // Log Check
    const auto log = ERROR_HANDLER.getLastestLog();
    EXPECT_EQ(log->type, ERROR);
    EXPECT_EQ(log->code, INTEGER_OUT_OF_RANGE);
}

TEST(TestSemanticActions, SA4)
{
    std::string lexeme = "9.2F+37";
    constexpr char character = 'a';
    const LexemeData l1 = SA4(lexeme, character);
    EXPECT_EQ(l1.token, FLOAT_LITERAL);
    EXPECT_EQ(l1.symbol_reference, nullptr);
    EXPECT_NE(l1.constant_reference, nullptr);
    EXPECT_EQ(lexeme, "9.2F+37");
    LexemeData l2 = SA4(lexeme, character);
    EXPECT_EQ(l1.symbol_reference, nullptr);
    EXPECT_EQ(l1.constant_reference, l2.constant_reference);
    lexeme = "-0.1F-3";
    l2 = SA4(lexeme, character);
    EXPECT_EQ(l2.token, FLOAT_LITERAL);
    EXPECT_EQ(l1.symbol_reference, nullptr);
    EXPECT_NE(l2.constant_reference, nullptr);
    lexeme = "1.02F-39";
    l2 = SA4(lexeme, character);
    EXPECT_EQ(l2.token, INVALID_TOKEN);
    EXPECT_EQ(l2.constant_reference, nullptr);
    // Log Check
    const auto log = ERROR_HANDLER.getLastestLog();
    EXPECT_EQ(log->type, ERROR);
    EXPECT_EQ(log->code, FLOAT_OUT_OF_RANGE);
}

TEST(TestSemanticActions, SA5)
{
    std::string lexeme = "\"a";
    constexpr char character = '\"';
    const LexemeData l1 = SA5(lexeme, character);
    EXPECT_EQ(l1.token, STRING_LITERAL);
    EXPECT_EQ(l1.symbol_reference, nullptr);
    EXPECT_NE(l1.constant_reference, nullptr);
    EXPECT_EQ(lexeme, "\"a\"");
    lexeme = "\"a";
    const LexemeData l2 = SA5(lexeme, character);
    EXPECT_EQ(l1.symbol_reference, nullptr);
    EXPECT_EQ(l1.constant_reference, l2.constant_reference);
}

TEST(TestSemanticActions, SA6)
{
    std::string lexeme = "A";
    constexpr char character = 'B';
    const LexemeData l1 = SA6(lexeme, character);
    EXPECT_EQ(l1.token, IDENTIFIER);
    EXPECT_NE(l1.symbol_reference, nullptr);
    EXPECT_EQ(l1.constant_reference, nullptr);
    EXPECT_EQ(lexeme, "A");
    const LexemeData l2 = SA6(lexeme, character);
    EXPECT_EQ(l1.constant_reference, nullptr);
    EXPECT_EQ(l1.symbol_reference, l2.symbol_reference);
    lexeme = "LONGVARIABLENAME%%%%%%";
    SA6(lexeme, character);
    // Log Check
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
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
    EXPECT_EQ(lexeme, "a");
    EXPECT_EQ(line + 1, YYLINENO);
}

TEST(TestSemanticActions, SA8)
{
    std::string lexeme = "";
    char character = '(';
    const LexemeData l1 = SA8(lexeme, character);
    EXPECT_EQ(l1.token, '(');
    EXPECT_EQ(l1.constant_reference, nullptr);
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
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}

TEST(TestSemanticActions, SA10)
{
    std::string lexeme = "";
    constexpr char character = '!';
    const LexemeData l = SA10(lexeme, character);
    EXPECT_EQ(l.token, NOT_EQUAL_OP);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}

TEST(TestSemanticActions, SA11)
{
    std::string lexeme = "";
    constexpr char character = '=';
    const LexemeData l = SA11(lexeme, character);
    EXPECT_EQ(l.token, ASSIGN_OP);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}

TEST(TestSemanticActions, SA12)
{
    std::string lexeme = "";
    constexpr char character = '=';
    const LexemeData l = SA12(lexeme, character);
    EXPECT_EQ(l.token, LE_OP);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}


TEST(TestSemanticActions, SA13)
{
    std::string lexeme = "";
    constexpr char character = '=';
    const LexemeData l = SA13(lexeme, character);
    EXPECT_EQ(l.token, GE_OP);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}


TEST(TestSemanticActions, SA14)
{
    std::string lexeme = "";
    constexpr char character = '>';
    const LexemeData l = SA14(lexeme, character);
    EXPECT_EQ(l.token, POINTER_OP);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}


TEST(TestSemanticActions, SA15)
{
    std::string lexeme = "";
    constexpr char character = 'a';
    const LexemeData l = SA15(lexeme, character);
    EXPECT_EQ(l.token, '=');
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}

TEST(TestSemanticActions, SA16)
{
    std::string lexeme = "";
    constexpr char character = 'a';
    const LexemeData l = SA16(lexeme, character);
    EXPECT_EQ(l.token, '<');
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}

TEST(TestSemanticActions, SA17)
{
    std::string lexeme = "";
    constexpr char character = 'a';
    const LexemeData l = SA17(lexeme, character);
    EXPECT_EQ(l.token, '>');
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}

TEST(TestSemanticActions, SA18)
{
    std::string lexeme = "";
    constexpr char character = 'a';
    const LexemeData l = SA18(lexeme, character);
    EXPECT_EQ(l.token, '-');
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}

TEST(TestSemanticActions, SA19)
{
    std::string lexeme = "if";
    constexpr char character = 'A';
    LexemeData l = SA19(lexeme, character);
    EXPECT_EQ(l.token, IF);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
    lexeme = "else";
    l = SA19(lexeme, character);
    EXPECT_EQ(l.token, ELSE);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
    lexeme = "ab";
    l = SA19(lexeme, character);
    EXPECT_EQ(l.token, INVALID_TOKEN);
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
    // Log Check
    const auto log = ERROR_HANDLER.getLastestLog();
    EXPECT_EQ(log->type, ERROR);
    EXPECT_EQ(log->code, INVALID_RESERVED_WORD);
}

// Agregada por compatibilidad con el '.'
TEST(TestSemanticActions, SA20)
{
    std::string lexeme = "";
    constexpr char character = 'a';
    const LexemeData l = SA20(lexeme, character);
    EXPECT_EQ(l.token, '.');
    EXPECT_EQ(l.symbol_reference, nullptr);
    EXPECT_EQ(l.constant_reference, nullptr);
}