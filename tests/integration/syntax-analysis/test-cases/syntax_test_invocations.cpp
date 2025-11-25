#include "../../fixture/CompilerTest.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

TEST_F(CompilerTest, syntax_invocations)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/syntax_invocations.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/syntax-analysis/files/syntax_invocations.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA            , 39, {"X1"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON        , 40, {"F"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_POINTED_PARAMETER, 40, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON        , 41, {"F"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_POINTED_PARAMETER, 41, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON        , 42, {"F"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ARGUMENT         , 42, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON        , 44, {"("}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON      , 45, {"("}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_OPENING_BRACKET, 45, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON      , 46, {"("}}));
    // Se encuentra programa porque la regla se reduce después de '(' y no se hizo un error personalizado
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_CLOSING_BRACKET, 46, {"PROGRAMA"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON      , 47, {"("}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_BOTH_BRACKETS  , 47, {"PROGRAMA"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON      , 48, {"}"}}));
}