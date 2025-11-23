#include "../fixture/TestParserLexer.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

TEST_F(TestParserLexer, do_while)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/do_while.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/parser-lexer/files/do_while.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 34, {"do"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_WHILE    , 36, {"("}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_WHILE    , 40, {"("}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 42, {"do"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_WHILE_EXECUTABLE_BODY, 42, {"while"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_WHILE_EXECUTABLE_BODY, 44, {"while"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 45, {"}"}}));
}