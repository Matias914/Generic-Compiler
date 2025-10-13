#include "gtest/gtest.h"
#include "utils/ReportHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/syntax_analyzer.h"

#include "../fixture/TestParserLexer.h"

TEST_F(TestParserLexer, if_else)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/if_else.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/parser-lexer/files/if_else.txt";
    assert(LexicalAnalyzer::open(file.c_str()));

    SyntaxAnalyzer::yyparsewrapper();

    // Dentro del campo del contenido debe aparecer aquello encontrado
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON  , 52, {"if"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_SEMICOLON  , 58, {"if"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ENDIF      , 61, {"if"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ENDIF      , 66, {"if"}}));
    // Se encuentra ENDIF porque se usa token error para el cuerpo
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_IF_EXECUTABLE_BODY  , 67, {"endif"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_IF_EXECUTABLE_BODY  , 69, {";"}}));
    // No se encuentra nada porque cuando la regla se reduce se consumieron los tokens
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ENDIF       , 69, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ELSE_EXECUTABLE_BODY, 74, {"endif"}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ELSE_EXECUTABLE_BODY, 78, {";"}}));
    // No se encuentra nada porque cuando la regla se reduce se consumieron los tokens
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ENDIF       , 78, {""}}));
    // No se encuentra nada porque cuando la regla se reduce se consumieron los tokens
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_IF_STATEMENT, 83, {""}}));
    EXPECT_TRUE(ERROR_HANDLER.contains({ERROR, MISSING_ENDIF       , 84, {"}"}}));
    EXPECT_EQ(ERROR_HANDLER.errorCount(), 12);
}