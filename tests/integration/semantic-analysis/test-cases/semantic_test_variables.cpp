#include "../../fixture/CompilerTest.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

TEST_F(CompilerTest, semantic_variables)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/semantic_variables.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/semantic-analysis/files/semantic_variables.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    EXPECT_FALSE(ERROR_HANDLER.contains({ERROR, UNDECLARED_VARIABLE, 18, {"VAR%GLOBAL"}}));
    EXPECT_FALSE(ERROR_HANDLER.contains({ERROR, UNDECLARED_VARIABLE, 22, {"PROGRAMA.VAR%GLOBAL"}}));
    EXPECT_FALSE(ERROR_HANDLER.contains({ERROR, UNDECLARED_VARIABLE, 25, {"PARAM%VAR"}}));

    // Este error es de tipo Sintáctico pero se incluyó en esta sección por el contexto
    EXPECT_TRUE(ERROR_HANDLER.contains({WARNING, EXTRA_NUMERIC_CONSTANTS, 39, {""}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR  , INCOMPATIBLE_TYPES     , 39, {"Y", "uint", "2.3", "float"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR  , INCOMPATIBLE_TYPES     , 44, {"X", "uint", "4.5", "float"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR  , UNDECLARED_VARIABLE    , 53, {"FUNC%TEST"}}));
}