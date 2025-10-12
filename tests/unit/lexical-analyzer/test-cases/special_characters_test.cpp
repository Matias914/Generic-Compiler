#include "gtest/gtest.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/parser.h"

#include "../fixture/TestLexicalAnalyzer.h"

using namespace LexicalAnalyzer;

/*
 * @brief se prueba la capacidad del analizador léxico para
 * reconocer casos de prueba válidos para los caracteres especiales
 * y operadores compuestos.
 *
 * Este test invoca a yylex() y compara el token devuelto con el que
 * debería.
 */
TEST_F(TestLexicalAnalyzer, special_characters)
{
    REPORT_HANDLER.setOutput(WORKING_DIRECTORY + "/special_characters_output.txt");

    const std::string file = WORKING_DIRECTORY + "/tests/unit/lexical-analyzer/files/special_characters.txt";
    assert(open(file.c_str()));

    // ----- Operadores Compuestos ----- //

    EXPECT_EQ(yylex(), EQUAL_OP);
    EXPECT_EQ(yylex(), NOT_EQUAL_OP);
    EXPECT_EQ(yylex(), LE_OP);
    EXPECT_EQ(yylex(), GE_OP);
    EXPECT_EQ(yylex(), ASSIGN_OP);
    EXPECT_EQ(yylex(), POINTER_OP);

    // ----- Caracteres Especiales ----- //

    EXPECT_EQ(yylex(), '>');
    EXPECT_EQ(yylex(), '<');
    EXPECT_EQ(yylex(), '=');
    EXPECT_EQ(yylex(), '+');
    EXPECT_EQ(yylex(), '-');
    EXPECT_EQ(yylex(), '/');
    EXPECT_EQ(yylex(), '*');
    EXPECT_EQ(yylex(), '.');
    EXPECT_EQ(yylex(), ';');
    EXPECT_EQ(yylex(), '(');
    EXPECT_EQ(yylex(), ')');
    EXPECT_EQ(yylex(), '{');
    EXPECT_EQ(yylex(), '}');
    EXPECT_EQ(yylex(), ',');

    // ----------- Errores ------------ //

    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
}
