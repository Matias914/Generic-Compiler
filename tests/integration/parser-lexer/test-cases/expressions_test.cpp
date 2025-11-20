#include "gtest/gtest.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/syntax_analyzer.h"

#include "../fixture/TestParserLexer.h"

TEST_F(TestParserLexer, expressions)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/expressions.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/parser-lexer/files/expressions.txt";
    assert(LexicalAnalyzer::open(file.c_str()));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado

    /* ------------ Trunc Statement ------------ */
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_CLOSING_PARENTHESIS   , 17, {";"}}));
    // No se espera nada porque cuando la regla se reduce se consumen todos los tokens
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_OPENING_PARENTHESIS   , 18, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_BOTH_PARENTHESIS_TRUNC, 19, {";"}}));

    /* ------------ Print Statement ------------ */
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 36, {"print"}}));
    // No se espera nada porque cuando la regla se reduce se consumen todos los tokens
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 37, {"print"}}));
    // Se espera ")" porque se uso el token error para el argumento
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ARGUMENT , 38, {")"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 46, {"uint"}}));

    /* ------------ Expressions ------------ */
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_OPERAND , 78, {"+"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_FACTOR  , 78, {"+"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_FACTOR  , 78, {"/"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_OPERAND , 78, {"+"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_FLOAT_CONSTANT, 78, {"-"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_FLOAT_CONSTANT, 80, {"print"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON     , 80, {"print"}}));

    // No se espera nada porque la regla se reduce
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_LEFT_SUB_OPERAND, 82, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_FLOAT_CONSTANT  , 82, {"-"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_FACTOR    , 82, {"*"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_FLOAT_CONSTANT  , 82, {"+"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_OPERAND   , 82, {"+"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_OPERAND   , 82, {"+"}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_LEFT_SUB_OPERAND, 83, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_FLOAT_CONSTANT  , 84, {"-"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_LEFT_SUM_OPERAND, 85, {";"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_LEFT_MUL_FACTOR , 86, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_LEFT_DIV_FACTOR , 87, {""}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_EXPRESSION_OPERATOR, 89, {"3UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_EXPRESSION_OPERATOR, 89, {"4UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_EXPRESSION_OPERATOR, 89, {"F"}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 91, {"("}}));

    EXPECT_EQ(ERROR_HANDLER.errorCount(), 30);
}