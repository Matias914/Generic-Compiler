#include "../fixture/TestParserLexer.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/syntax_analyzer.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

TEST_F(TestParserLexer, declarations)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/declarations.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/parser-lexer/files/declarations.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_VARIABLE , 42, {";"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_VARIABLE , 43, {"1UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 45, {"uint"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 45, {"Z"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_VARIABLE , 46, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_VARIABLE , 46, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_VARIABLE , 46, {";"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PARAMETER_TYPE, 47, {"B"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PARAMETER_NAME, 47, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PARAMETER_TYPE, 47, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PARAMETER_TYPE, 47, {"B"}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_OPENING_PARENTHESIS, 48, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_CLOSING_BRACKET    , 49, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON          , 49, {"End of File"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_CLOSING_BRACKET    , 49, {""}}));
}