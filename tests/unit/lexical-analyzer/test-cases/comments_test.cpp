#include "gtest/gtest.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/parser.h"

#include "../fixture/TestLexicalAnalyzer.h"

using namespace LexicalAnalyzer;

/*
 * @brief se prueba la capacidad del analizador léxico para
 * reconocer casos de prueba válidos para los comentarios
 *
 * Este test invoca a yylex() y compara el token devuelto con el que
 * debería haber devuelto.
 */
TEST_F(TestLexicalAnalyzer, comments)
{
    REPORT_HANDLER.setOutput(WORKING_DIRECTORY + "/comments_output.txt");

    const std::string file = WORKING_DIRECTORY + "/tests/unit/lexical-analyzer/files/comments.txt";
    assert(open(file.c_str()));

    // ----- Comentarios ----- //

    // Por el #
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);

    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_TRUE(validSymbol("C"));

    // Por la palabra reservada
    EXPECT_EQ(yylex(), INVALID_TOKEN);

    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_TRUE(validSymbol("I"));

    // Por la palabra reservada
    EXPECT_EQ(yylex(), INVALID_TOKEN);

    EXPECT_EQ(yylex(), 0);
}
