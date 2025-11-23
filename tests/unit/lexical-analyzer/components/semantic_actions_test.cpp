#include "gtest/gtest.h"
#include "utils/ErrorHandler.h"
#include "utils/resources/codes.h"
#include "syntax-analyzer/components/Parser.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "lexical-analyzer/components/SemanticActions.h"

#include <cmath>

#include "syntax-analyzer/components/Translator.h"

using namespace LexicalAnalyzer;
using namespace LexicalAnalyzer::SemanticActions;

extern ErrorHandler ERROR_HANDLER;

extern SymbolTable  SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;

TEST(TestSemanticActions, DoNothing)
{
    std::string lexeme = "l";
    constexpr char character = 'c';
    const int token = DoNothing(lexeme, character);
    EXPECT_EQ(token, INVALID_TOKEN);
    EXPECT_EQ(lexeme, "l");
}

TEST(TestSemanticActions, EndOfFile)
{
    std::string lexeme = "l";
    constexpr char character = 'c';
    const int token = EndOfFile(lexeme, character);
    EXPECT_EQ(token, YYEOF);
    EXPECT_EQ(lexeme, "l");
}

TEST(TestSemanticActions, SA1)
{
    std::string lexeme = "l";
    constexpr char character = 'c';
    const int token = SA1(lexeme, character);
    EXPECT_EQ(token, INVALID_TOKEN);
    EXPECT_EQ(lexeme, "c");
}

TEST(TestSemanticActions, SA2)
{
    std::string lexeme = "1";
    constexpr char character = '2';
    const int token = SA2(lexeme, character);
    EXPECT_EQ(token, INVALID_TOKEN);
    EXPECT_EQ(lexeme, "12");
}

TEST(TestSemanticActions, SA3)
{
    // Max Value for UINT
    std::string lexeme = "65535U";
    constexpr char character = 'I';
    const int token = SA3(lexeme, character);
    EXPECT_EQ(token, LITERAL_UINT);
    EXPECT_EQ(lexeme, "65535UI");
    const auto entry = LITERAL_TABLE.get(lexeme);
    EXPECT_EQ(entry->constant, lexeme);
    EXPECT_EQ(entry->type, UINT);
    EXPECT_EQ(entry->value.i, 65535);
    // Integration With Parser
    EXPECT_EQ(entry, yylval.lref);
}

TEST(TestSemanticActions, ErrorInSA3)
{
    // Overflow
    std::string lexeme = "65536U";
    constexpr char character = 'I';
    const int token = SA3(lexeme, character);
    EXPECT_EQ(token, INVALID_TOKEN);
    EXPECT_EQ(LITERAL_TABLE.get(lexeme), nullptr);
    const auto log = ERROR_HANDLER.getLastestLog();
    EXPECT_EQ(log->type, ERROR);
    EXPECT_EQ(log->code, INTEGER_OUT_OF_RANGE);
}

TEST(TestSemanticActions, SA4)
{
    // Max Value for Float
    std::string lexeme = "3.40282346F+38";
    constexpr char character = 'c';
    int token = SA4(lexeme, character);
    EXPECT_EQ(token, LITERAL_FLOAT);
    EXPECT_EQ(lexeme, "3.40282346F+38");
    auto entry = LITERAL_TABLE.get(lexeme);
    EXPECT_EQ(entry->constant, lexeme);
    EXPECT_EQ(entry->type, FLOAT);
    EXPECT_EQ(entry->value.f, std::numeric_limits<float>::max());
    // Integration With Parser
    EXPECT_EQ(entry, yylval.lref);
    // Min Value for Float
    lexeme = "1.17549436F-38";
    token = SA4(lexeme, character);
    EXPECT_EQ(token, LITERAL_FLOAT);
    EXPECT_EQ(lexeme, "1.17549436F-38");
    entry = LITERAL_TABLE.get(lexeme);
    EXPECT_EQ(entry->constant, lexeme);
    EXPECT_EQ(entry->type, FLOAT);
    EXPECT_EQ(entry->value.f, std::numeric_limits<float>::min());
    // Integration With Parser
    EXPECT_EQ(entry, yylval.lref);
}

TEST(TestSemanticActions, ErrorInSA4)
{
    // Overflow
    std::string lexeme = "3.40282347F+38";
    constexpr char character = 'c';
    int token = SA4(lexeme, character);
    EXPECT_EQ(token, INVALID_TOKEN);
    EXPECT_EQ(LITERAL_TABLE.get(lexeme), nullptr);
    auto log = ERROR_HANDLER.getLastestLog();
    EXPECT_EQ(log->type, ERROR);
    EXPECT_EQ(log->code, FLOAT_OUT_OF_RANGE);
    // Underflow
    lexeme = "1.17549435F-38";
    token = SA4(lexeme, character);
    EXPECT_EQ(token, INVALID_TOKEN);
    EXPECT_EQ(LITERAL_TABLE.get(lexeme), nullptr);
    log = ERROR_HANDLER.getLastestLog();
    EXPECT_EQ(log->type, ERROR);
    EXPECT_EQ(log->code, FLOAT_OUT_OF_RANGE);
}

TEST(TestSemanticActions, SA5)
{
    std::string lexeme = "\"l";
    constexpr char character = '\"';
    const int token = SA5(lexeme, character);
    EXPECT_EQ(token, LITERAL_STRING);
    EXPECT_EQ(lexeme, "\"l\"");
    const auto entry = LITERAL_TABLE.get(lexeme);
    EXPECT_EQ(entry->constant, lexeme);
    EXPECT_EQ(entry->type, STRING);
    // Integration With Parser
    EXPECT_EQ(entry, yylval.lref);
}

TEST(TestSemanticActions, SA6)
{
    std::string lexeme = "L";
    constexpr char character = ':';
    const int token = SA6(lexeme, character);
    EXPECT_EQ(token, IDENTIFIER);
    EXPECT_EQ(lexeme, "L");
    const auto entry = SYMBOL_TABLE.get(lexeme);
    EXPECT_EQ(entry->symbol, lexeme);
    // Integration With Parser
    EXPECT_EQ(entry, yylval.sref);
}

TEST(TestSemanticActions, WarningInSA6)
{
    std::string lexeme = "LONGVARIABLENAME%%%123%%%";
    constexpr char character = ':';
    SA6(lexeme, character);
    const auto log = ERROR_HANDLER.getLastestLog();
    EXPECT_EQ(log->type, WARNING);
    EXPECT_EQ(log->code, TRUNCATED_IDENTIFIER);
}

TEST(TestSemanticActions, SA7)
{
    std::string lexeme = "l";
    constexpr char character = '\n';
    const int line = YYLINENO;
    const int token = SA7(lexeme, character);
    EXPECT_EQ(token, INVALID_TOKEN);
    EXPECT_EQ(lexeme, "l");
    EXPECT_EQ(line + 1, YYLINENO);
}

TEST(TestSemanticActions, SA8)
{
    for (int i = 0; i < 9; i++)
    {
        constexpr char cvals[9]    = {  ',',   '/',   ';',   '{',   '}',   '(',   ')',   '*',   '+'};
        const std::string svals[9] = {",", "/", ";", "{", "}", "(", ")", "*", "+"};
        std::string lexeme = "";
        char character = cvals[i];
        int token = SA8(lexeme, character);
        EXPECT_EQ(token, cvals[i]);
        EXPECT_EQ(lexeme, svals[i]);
    }
}

TEST(TestSemanticActions, SA9)
{
    std::string lexeme = "=";
    constexpr char character = '=';
    const int token = SA9(lexeme, character);
    EXPECT_EQ(token, OP_EQUAL);
    EXPECT_EQ(lexeme, "==");
}

TEST(TestSemanticActions, SA10)
{
    std::string lexeme = "=";
    constexpr char character = '!';
    const int token = SA10(lexeme, character);
    EXPECT_EQ(token, OP_NOT_EQUAL);
    EXPECT_EQ(lexeme, "=!");
}

TEST(TestSemanticActions, SA11)
{
    std::string lexeme = ":";
    constexpr char character = '=';
    const int token = SA11(lexeme, character);
    EXPECT_EQ(token, OP_ASSIGN);
    EXPECT_EQ(lexeme, ":=");
}

TEST(TestSemanticActions, SA12)
{
    std::string lexeme = "<";
    constexpr char character = '=';
    const int token = SA12(lexeme, character);
    EXPECT_EQ(token, OP_LE);
    EXPECT_EQ(lexeme, "<=");
}


TEST(TestSemanticActions, SA13)
{
    std::string lexeme = ">";
    constexpr char character = '=';
    const int token = SA13(lexeme, character);
    EXPECT_EQ(token, OP_GE);
    EXPECT_EQ(lexeme, ">=");
}


TEST(TestSemanticActions, SA14)
{
    std::string lexeme = "-";
    constexpr char character = '>';
    const int token = SA14(lexeme, character);
    EXPECT_EQ(token, OP_POINTER);
    EXPECT_EQ(lexeme, "->");
}


TEST(TestSemanticActions, SA15)
{
    std::string lexeme = "=";
    constexpr char character = 'c';
    const int token = SA15(lexeme, character);
    EXPECT_EQ(token, '=');
}

TEST(TestSemanticActions, SA16)
{
    constexpr int vals[11] = {
        WORD_IF,
        WORD_ELSE,
        WORD_ENDIF,
        WORD_DO,
        WORD_WHILE,
        WORD_RETURN,
        WORD_PRINT,
        WORD_TRUNC,
        WORD_UINT,
        WORD_FLOAT,
        WORD_CR
    };
    for (int i = 0; i < std::size(vals); i++)
    {
        constexpr char character = 'C';
        std::string svalue = SyntaxAnalyzer::Translator::translate(vals[i]);
        std::string lexeme = svalue;
        int token = SA16(lexeme, character);
        EXPECT_EQ(token, vals[i]);
        EXPECT_EQ(lexeme, svalue);
    }
}

TEST(TestSemanticActions, ErrorInSA16)
{
    std::string lexeme = "l";
    constexpr char character = 'C';
    const int token = SA16(lexeme, character);
    EXPECT_EQ(token, INVALID_RWORD);
    // Log Check
    const auto log = ERROR_HANDLER.getLastestLog();
    EXPECT_EQ(log->type, ERROR);
    EXPECT_EQ(log->code, INVALID_RESERVED_WORD);
}