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

    EXPECT_EQ(yylex(), WORD_IF);
    EXPECT_EQ(yylex(), WORD_ELSE);
    EXPECT_EQ(yylex(), WORD_ENDIF);
    EXPECT_EQ(yylex(), WORD_DO);
    EXPECT_EQ(yylex(), WORD_WHILE);
    EXPECT_EQ(yylex(), WORD_RETURN);
    EXPECT_EQ(yylex(), WORD_PRINT);
    EXPECT_EQ(yylex(), WORD_TRUNC);
    EXPECT_EQ(yylex(), WORD_UINT);
    EXPECT_EQ(yylex(), WORD_FLOAT);
    EXPECT_EQ(yylex(), WORD_CR);

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

    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);
    EXPECT_EQ(yylex(), INVALID_RWORD);

    EXPECT_EQ(yylex(), 0);
}
