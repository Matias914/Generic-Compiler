#include "gtest/gtest.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/SemanticActions.h"

/*
 * @brief verifica que cree un nuevo lexema.
 */
TEST(TestSemanticActions, SA1)
{
    std::string lexeme = "previous";
    constexpr char character = 'I';
    const int token = SemanticActions::SA1(lexeme, character);
    EXPECT_EQ(token, -1);
    EXPECT_EQ(lexeme, "I");
}

/*
 * @brief verifica que se concatene un caracter al lexema.
 */
TEST(TestSemanticActions, SA2)
{
    std::string lexeme = "previous";
    constexpr char character = 'I';
    const int token = SemanticActions::SA2(lexeme, character);
    EXPECT_EQ(token, -1);
    EXPECT_EQ(lexeme, "previousI");
}

/*
 * @brief verifica que el último caracter del lexema
 * sea una U. Se prueba el mensaje de error.
 */
TEST(TestSemanticActions, SA3)
{
    std::string lexeme = "previous";
    constexpr char character1 = 'U';
    const int token = SemanticActions::SA3(lexeme, character1);
    EXPECT_EQ(token, -1);
    EXPECT_EQ(lexeme, "previousU");
    constexpr char character2 = 'I';
    EXPECT_ANY_THROW(SemanticActions::SA3(lexeme, character2));
}

/*
 * @brief verifica que el último caracter del lexema
 * sea una I. Se prueba el mensaje de error del rango y del caracter
 * inválido.
 */
TEST(TestSemanticActions, SA4)
{
    std::string lexeme1 = "1U";
    constexpr char character1 = 'H';
    EXPECT_ANY_THROW(SemanticActions::SA4(lexeme1, character1));
    std::string lexeme2 = "previousU";
    constexpr char character2 = 'I';
    EXPECT_ANY_THROW(SemanticActions::SA4(lexeme2, character2));
    std::string lexeme3 = "25U";
    const int token = SemanticActions::SA4(lexeme3, character2);
    EXPECT_EQ(token, INTEGER_LITERAL);
    EXPECT_EQ(lexeme3, "25UI");
    std::string lexeme4 = "65600U";
    EXPECT_ANY_THROW(SemanticActions::SA4(lexeme4, character2));
}