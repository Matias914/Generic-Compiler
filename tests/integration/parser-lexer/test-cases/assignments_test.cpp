#include "gtest/gtest.h"
#include "utils/ReportHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/syntax_analyzer.h"

#include "../fixture/TestParserLexer.h"

TEST_F(TestParserLexer, assignments)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/assignments.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/parser-lexer/files/assignments.txt";
    assert(LexicalAnalyzer::open(file.c_str()));

    SyntaxAnalyzer::analyze();

    // Se espera error en las líneas: 36 38 38 38 38 38 38 39 39 39 39 39 40 40 41 41 41

    // Dentro del campo del contenido debe aparecer aquello encontrado
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 36, {"print"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 38, {"Y"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 38, {"3UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 38, {"4UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 38, {"5UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 38, {"6UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 39, {"X"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 39, {"3UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 39, {"4UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 39, {"5UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 39, {"6UI"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 40, {"X"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 40, {"Y"}}));

    // Se espera una coma porque faltan valores a la derecha
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_COMMA    , 41, {"}"}}));

    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_RIGHT_SIDE_VALUES, 41, {"}"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON, 41, {"}"}}));

    EXPECT_EQ(ERROR_HANDLER.errorCount(), 17);
}