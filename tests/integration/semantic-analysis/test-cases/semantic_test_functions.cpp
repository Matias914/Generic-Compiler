#include "../../fixture/CompilerTest.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

TEST_F(CompilerTest, semantic_functions)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/semantic_functions.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/semantic-analysis/files/semantic_functions.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, FUNCTION_REDECLARATION    , 18, {"GLOBALVAR"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, FUNCTION_REDECLARATION    , 27, {"F1"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, RETURN_INCOMPATIBLE       , 41, {"2.5", "F%BAD%TYPE"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RETURN_STATEMENT  , 47, {"F%NO%RETURN"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, INCOMPATIBLE_WITH_SEMANTIC, 62, {"2.5", "A", "cr"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, INCOMPATIBLE_TYPES        , 65, {"X", "uint", "A", "float"}}));
}