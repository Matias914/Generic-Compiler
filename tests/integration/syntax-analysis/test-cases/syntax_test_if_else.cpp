#include "../../fixture/CompilerTest.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"
#include "utils/ReportHandler.h"
#include "utils/resources/codes.h"

TEST_F(CompilerTest, syntax_if_else)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/syntax_if_else.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/syntax-analysis/files/syntax_if_else.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    // Dentro del campo del contenido debe aparecer aquello encontrado
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON  , 50, {"if"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON  , 56, {"if"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ENDIF      , 59, {"if"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ENDIF      , 64, {"if"}}));
    // Se encuentra ENDIF porque se usa token error para el cuerpo
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_IF_EXECUTABLE_BODY  , 65, {"endif"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_IF_EXECUTABLE_BODY  , 67, {";"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ENDIF               , 67, {";"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ELSE_EXECUTABLE_BODY, 72, {"endif"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ELSE_EXECUTABLE_BODY, 76, {";"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ENDIF               , 76, {";"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_IF_EXECUTABLE_BODY  , 81, {""}}));
}