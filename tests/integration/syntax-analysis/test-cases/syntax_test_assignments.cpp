#include "../../fixture/CompilerTest.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

TEST_F(CompilerTest, syntax_assignments)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/syntax_assignments.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/syntax-analysis/files/syntax_assignments.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 34, {"print"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 36, {"Y"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 36, {"3UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 36, {"4UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 36, {"5UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 36, {"6UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 37, {"X"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 37, {"3UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 37, {"4UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 37, {"5UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 37, {"6UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 38, {"X"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 38, {"Y"}}));

    // Se espera una coma porque faltan valores a la derecha
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 39, {"}"}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_SIDE_VALUES, 39, {"}"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON        , 39, {"}"}}));
}