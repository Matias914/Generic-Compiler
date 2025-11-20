#include "gtest/gtest.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/syntax_analyzer.h"

#include "../fixture/TestParserLexer.h"

TEST_F(TestParserLexer, declarations)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/declarations.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/parser-lexer/files/declarations.txt";
    assert(LexicalAnalyzer::open(file.c_str()));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_VARIABLE , 44, {";"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_VARIABLE , 45, {"1UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 47, {"uint"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 47, {"Z"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_VARIABLE , 48, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_VARIABLE , 48, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_VARIABLE , 48, {";"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PARAMETER_TYPE, 49, {"B"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PARAMETER_NAME, 49, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PARAMETER_TYPE, 49, {","}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PARAMETER_TYPE, 49, {"B"}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_OPENING_PARENTHESIS, 50, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_CLOSING_BRACKET, 51, {"End of File"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON      , 51, {"End of File"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_CLOSING_BRACKET, 51, {"End of File"}}));

    EXPECT_EQ(ERROR_HANDLER.errorCount(), 15);
}