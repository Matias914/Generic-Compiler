#include "gtest/gtest.h"
#include "../../include/lexical-analyzer/translator/Translator.h"

/*
 * @brief prueba los casos de uso. Se establecen caracteres
 * que deberian ser matcheados con un determinado grupo.
 *
 */
TEST(TestTranslator, translate)
{
    // Upper Case Letters
    EXPECT_EQ(Translator::translate('A'), UPPER_CASE);
    EXPECT_EQ(Translator::translate('D'), UPPER_CASE);
    EXPECT_EQ(Translator::translate('F'), UPPER_CASE);
    EXPECT_EQ(Translator::translate('I'), UPPER_CASE);
    EXPECT_EQ(Translator::translate('U'), UPPER_CASE);
    // Lower Case Letters
    EXPECT_EQ(Translator::translate('a'), LOWER_CASE);
    EXPECT_EQ(Translator::translate('b'), LOWER_CASE);
    EXPECT_EQ(Translator::translate('z'), LOWER_CASE);
    EXPECT_EQ(Translator::translate('n'), LOWER_CASE);
    EXPECT_EQ(Translator::translate('t'), LOWER_CASE);
    // Numbers
    EXPECT_EQ(Translator::translate('0'), NUMBER);
    EXPECT_EQ(Translator::translate('8'), NUMBER);
    EXPECT_EQ(Translator::translate('5'), NUMBER);
    // Special Characters
    EXPECT_EQ(Translator::translate('('), SPECIAL);
    EXPECT_EQ(Translator::translate(')'), SPECIAL);
    EXPECT_EQ(Translator::translate('*'), SPECIAL);
    EXPECT_EQ(Translator::translate('{'), SPECIAL);
    EXPECT_EQ(Translator::translate('}'), SPECIAL);
    EXPECT_EQ(Translator::translate('/'), SPECIAL);
    EXPECT_EQ(Translator::translate(';'), SPECIAL);
    EXPECT_EQ(Translator::translate('%'), SPECIAL);
    EXPECT_EQ(Translator::translate('!'), SPECIAL);
    // Operators
    EXPECT_EQ(Translator::translate('<'), OPERATOR);
    EXPECT_EQ(Translator::translate('='), OPERATOR);
    EXPECT_EQ(Translator::translate('>'), OPERATOR);
    EXPECT_EQ(Translator::translate(':'), OPERATOR);
    // Blank Characters
    EXPECT_EQ(Translator::translate('\t'), BLANK);
    EXPECT_EQ(Translator::translate(' '), BLANK);
    // Unique Characters
    EXPECT_EQ(Translator::translate('.'), DOT);
    EXPECT_EQ(Translator::translate('+'), PLUS);
    EXPECT_EQ(Translator::translate('-'), MINUS);
    EXPECT_EQ(Translator::translate('"'), QUOTE);
    EXPECT_EQ(Translator::translate('#'), NUMERAL);
    EXPECT_EQ(Translator::translate('\n'), ENDLINE);
    // Others
    EXPECT_EQ(Translator::translate('~'), OTHER);
    EXPECT_EQ(Translator::translate('?'), OTHER);
    EXPECT_EQ(Translator::translate('$'), OTHER);
    EXPECT_EQ(Translator::translate('^'), OTHER);
    EXPECT_EQ(Translator::translate('&'), OTHER);
    EXPECT_EQ(Translator::translate('|'), OTHER);
}
