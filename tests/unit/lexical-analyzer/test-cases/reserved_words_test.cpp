#include "gtest/gtest.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/parser.h"

#include "../fixture/TestLexicalAnalyzer.h"

using namespace LexicalAnalyzer;

/*
 * @brief se prueba la capacidad del analizador léxico para
 * reconocer casos de prueba válidos para las palabras reservadas
 *
 * Este test invoca a yylex() y compara el token devuelto con el que
 * debería haber devuelto.
 */
TEST_F(TestLexicalAnalyzer, reserved_words)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/reserved_words.log");

    const std::string file = WORKING_DIRECTORY + "/tests/unit/lexical-analyzer/files/reserved_words.txt";
    assert(open(file.c_str()));

    // ----- Palabras Reservadas ----- //

    EXPECT_EQ(yylex(), IF);
    EXPECT_EQ(yylex(), ELSE);
    EXPECT_EQ(yylex(), ENDIF);
    EXPECT_EQ(yylex(), DO);
    EXPECT_EQ(yylex(), WHILE);
    EXPECT_EQ(yylex(), RETURN);
    EXPECT_EQ(yylex(), PRINT);
    EXPECT_EQ(yylex(), TRUNC);
    EXPECT_EQ(yylex(), UINT);
    EXPECT_EQ(yylex(), FLOAT);
    EXPECT_EQ(yylex(), CR);

    // ----- Identificadores ----- //

    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_EQ(yylex(), IDENTIFIER);

    // ----------- Errores ------------ //

    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_EQ(yylex(), INVALID_TOKEN);

    EXPECT_EQ(yylex(), 0);
}
