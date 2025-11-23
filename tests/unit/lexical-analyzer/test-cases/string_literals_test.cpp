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
 * debería.
 */
TEST_F(TestLexicalAnalyzer, string_literals)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/string_literals.log");

    const std::string file = WORKING_DIRECTORY + "/tests/unit/lexical-analyzer/files/string_literals.txt";
    assert(open(file.c_str()));

    // ----- Cadenas de una línea ----- //

    EXPECT_EQ(yylex(), LITERAL_STRING);
    EXPECT_TRUE(validLiteral("\"Esta es una cadena válida de una línea\""));

    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("\"Esta es una cadena inválida de más de"));

    // Por la palabra reservada
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);

    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("\"Esta es otra cadena inválida"));

    EXPECT_EQ(yylex(), 0);
}
