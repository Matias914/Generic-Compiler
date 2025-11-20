#include "gtest/gtest.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/syntax_analyzer.h"

#include "../fixture/TestParserLexer.h"

TEST_F(TestParserLexer, invocations)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/invocations.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/parser-lexer/files/invocations.txt";
    assert(LexicalAnalyzer::open(file.c_str()));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA            , 41, {"X1"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON        , 42, {"F"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_POINTED_PARAMETER, 42, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON        , 43, {"F"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_POINTED_PARAMETER, 43, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON        , 44, {"F"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ARGUMENT         , 44, {")"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON        , 46, {"("}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON      , 47, {"("}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_OPENING_BRACKET, 47, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON      , 48, {"("}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_CLOSING_BRACKET, 48, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON      , 49, {"("}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_BOTH_BRACKETS  , 49, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON      , 50, {"}"}}));

    EXPECT_EQ(ERROR_HANDLER.errorCount(), 15);
}