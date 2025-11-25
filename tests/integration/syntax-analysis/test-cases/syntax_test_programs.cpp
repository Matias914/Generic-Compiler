#include "../../fixture/CompilerTest.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

TEST_F(CompilerTest, syntax_programs)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/syntax_programs.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/syntax-analysis/files/syntax_programs.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, GLOBAL_SCOPE_STATEMENT  , 33, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PROGRAM_NAME    , 35, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, INVALID_PROGRAM_NESTING , 42, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, INVALID_COMPOUND_NESTING, 46, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, GLOBAL_SCOPE_STATEMENT  , 50, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_OPENING_BRACKET , 51, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_PROGRAM_NAME    , 53, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_CLOSING_BRACKET , 55, {""}}));
}