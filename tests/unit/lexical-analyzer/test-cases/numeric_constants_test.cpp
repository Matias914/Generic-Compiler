#include "gtest/gtest.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/parser.h"

#include "../fixture/TestLexicalAnalyzer.h"

using namespace LexicalAnalyzer;

/*
 * @brief se prueba la capacidad del analizador léxico para
 * reconocer casos de prueba válidos para las constantes enteras
 *
 * En este test se prueba que el token recibido por yylex() coincida
 * con el lógicamente esperado. Además, se verifica, en el caso de
 * identificadores y constantes, que estén en las tablas y que sean igual
 * a su valor esperado también.
 */
TEST_F(TestLexicalAnalyzer, numeric_constants)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/numeric_constants.log");

    const std::string file = WORKING_DIRECTORY + "/tests/unit/lexical-analyzer/files/numeric_constants.txt";
    assert(open(file.c_str()));

    // ----- Entero sin Signo (16 bits) ----- //

    EXPECT_EQ(yylex(), UINTEGER_LITERAL);
    EXPECT_TRUE(validLiteral("0UI"));
    EXPECT_EQ(yylex(), UINTEGER_LITERAL);
    EXPECT_TRUE(validLiteral("65535UI"));
    EXPECT_EQ(yylex(), UINTEGER_LITERAL);
    EXPECT_TRUE(validLiteral("15UI"));

    // ------ Punto Flotante (32 bits) ------ //

    
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("1.17549436F-38"));
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("3.40282346F+38"));
    EXPECT_EQ(yylex(), '-');
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("1.17549436F-38"));
    EXPECT_EQ(yylex(), '-');
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("3.40282346F+38"));
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("0.0"));

    // ----------- Combinaciones ------------ //

    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("3."));
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("3.40282346"));
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral(".40282346"));
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("3.F+38"));
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("3.40282346F+38"));
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral(".40282346F+38"));
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("3.F-38"));
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral("3.40282346F-38"));
    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    EXPECT_TRUE(validLiteral(".40282346F-37"));

    // ----------- Errores ------------ //

    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("65536UI"));
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("16"));
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("16U"));
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("16I"));

    // Porque la I se vuelve a leer
    EXPECT_EQ(yylex(), IDENTIFIER);
    EXPECT_TRUE(validSymbol("I"));

    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("1.17549435F-38"));
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("3.40282347F+38"));
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("3.40282346F38"));

    // Porque el 3 se vuelve a leer
    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("38"));

    // Resincronización
    EXPECT_EQ(yylex(), ';');

    EXPECT_EQ(yylex(), INVALID_TOKEN);
    EXPECT_FALSE(validLiteral("3.40282346F"));

    EXPECT_EQ(yylex(), 0);
}
