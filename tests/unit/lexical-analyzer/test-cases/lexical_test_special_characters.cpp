#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/components/Parser.h"

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
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/lexical_special_characters.log");

    const std::string file = WORKING_DIRECTORY + "/tests/unit/lexical-analyzer/files/lexical_special_characters.txt";
    assert(open(file.c_str()));

    // ----- Operadores Compuestos ----- //

    EXPECT_EQ(yylex(), OP_EQUAL);
    EXPECT_EQ(yylex(), OP_NOT_EQUAL);
    EXPECT_EQ(yylex(), OP_LE);
    EXPECT_EQ(yylex(), OP_GE);
    EXPECT_EQ(yylex(), OP_ASSIGN);
    EXPECT_EQ(yylex(), OP_POINTER);

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
