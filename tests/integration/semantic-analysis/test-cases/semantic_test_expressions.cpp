#include "../../fixture/CompilerTest.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

TEST_F(CompilerTest, semantic_expressions)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/semantic_expressions.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/semantic-analysis/files/semantic_expressions.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, INCOMPATIBLE_TYPES, 17, {"VAR%INT", "uint", "VAR%FLOAT", "float"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, INCOMPATIBLE_TYPES, 20, {"VAR%FLOAT", "float", "VAR%INT", "uint"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, INCOMPATIBLE_TYPES, 23, {"VAR%INT", "uint", "VAR%FLOAT", "float"}}));

    EXPECT_FALSE(ERROR_HANDLER.contains({ERROR, INCOMPATIBLE_TYPES, 38, {"VAR%INT", "uint", "VAR%FLOAT", "float"}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({WARNING, TRUNC_USELESS, 45, {"10UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({WARNING, TRUNC_USELESS, 48, {"VAR%INT"}}));
}