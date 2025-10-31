#include "gtest/gtest.h"
#include "utils/ReportHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/syntax_analyzer.h"

#include "../fixture/TestParserLexer.h"

TEST_F(TestParserLexer, programs)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/programs.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/parser-lexer/files/programs.txt";
    assert(LexicalAnalyzer::open(file.c_str()));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado

    // 33, 37, 42, 46, 50, 51, 53, 55
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, GLOBAL_SCOPE_STATEMENT  , 33, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PROGRAM_NAME    , 35, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, INVALID_PROGRAM_NESTING , 42, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, INVALID_COMPOUND_NESTING, 46, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, GLOBAL_SCOPE_STATEMENT  , 50, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_OPENING_BRACKET , 51, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PROGRAM_NAME    , 53, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_CLOSING_BRACKET , 55, {""}}));

    EXPECT_EQ(ERROR_HANDLER.errorCount(), 12);
}