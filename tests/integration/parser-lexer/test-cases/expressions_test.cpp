#include "../fixture/TestParserLexer.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

TEST_F(TestParserLexer, expressions)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/expressions.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/parser-lexer/files/expressions.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado

    /* ------------ Trunc Statement ------------ */
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_CLOSING_PARENTHESIS   , 17, {";"}}));
    // No se espera nada porque cuando la regla se reduce se consumen todos los tokens
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_OPENING_PARENTHESIS   , 18, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_BOTH_PARENTHESIS_TRUNC, 19, {";"}}));

    /* ------------ Print Statement ------------ */
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 34, {"print"}}));
    // No se espera nada porque cuando la regla se reduce se consumen todos los tokens
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 35, {"print"}}));
    // Se espera ")" porque se uso el token error para el argumento
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ARGUMENT , 36, {")"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 42, {"uint"}}));

    /* ------------ Expressions ------------ */
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_OPERAND    , 72, {"+"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_FACTOR     , 72, {"+"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_FACTOR     , 72, {"/"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_OPERAND    , 72, {"+"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_BOTH_SUB_OPERANDS, 72, {"-"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_BOTH_SUB_OPERANDS, 74, {"print"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON        , 74, {"print"}}));

    // No se espera nada porque la regla se reduce
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_LEFT_SUB_OPERAND  , 76, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_BOTH_SUB_OPERANDS , 76, {"-"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, INVALID_LAMBDA_USE        , 76, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_FACTOR      , 76, {"*"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_BOTH_SUB_OPERANDS , 76, {"+"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_OPERAND     , 76, {"+"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_OPERAND     , 76, {"+"}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_LEFT_SUB_OPERAND , 77, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_BOTH_SUB_OPERANDS, 78, {"-"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_LEFT_SUM_OPERAND , 79, {";"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_LEFT_MUL_FACTOR  , 80, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_LEFT_DIV_FACTOR  , 81, {""}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_EXPRESSION_OPERATOR, 83, {"3UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_EXPRESSION_OPERATOR, 83, {"4UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_EXPRESSION_OPERATOR, 83, {"F"}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 85, {"("}}));
}