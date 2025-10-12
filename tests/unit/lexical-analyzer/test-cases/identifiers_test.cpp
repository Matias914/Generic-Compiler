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
 * debería haber devuelto. Por último, se verifican diferentes tokenizaciones
 * propuestas. Por cada token, además, se verifica que esté en la tabla
 * de símbolos.
 */
TEST_F(TestLexicalAnalyzer, identifiers)
{
    REPORT_HANDLER.setOutput(WORKING_DIRECTORY + "/identifiers_output.txt");

    const std::string file = WORKING_DIRECTORY + "/tests/unit/lexical-analyzer/files/identifiers.txt";
    assert(open(file.c_str()));

    // ----- Identificadores ----- //

    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_TRUE(validSymbol("IDENTIF"));
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_FALSE(validLiteral("I1D2N3T4I5F6"));
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_FALSE(validLiteral("I1D2N3T4I5F6"));
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_FALSE(validLiteral("I1%D2%N3%T4%I5%F6%"));
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_FALSE(validLiteral("I1%D2%N3%T4%I5%F6%EXTENDIDA"));

    // ----- Ejemplos de Tokenización ----- //

    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_TRUE(validSymbol("ERA%VARIABLE"));
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_TRUE(validSymbol("MIVARIABLE%"));
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_TRUE(validSymbol("M"));
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_TRUE(validSymbol("VARIA"));
    EXPECT_EQ(yylex(), '.');
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_TRUE(validSymbol("BLE"));

    EXPECT_EQ(yylex(), 0);
}
