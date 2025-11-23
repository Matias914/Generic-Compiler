#include "gtest/gtest.h"
#include "lexical-analyzer/components/lexical_tokens.h"
#include "lexical-analyzer/components/Translator.h"

using namespace LexicalAnalyzer::Translator;

/*
 * @brief prueba los casos de uso. Se establecen caracteres
 * que deberian ser matcheados con un determinado grupo.
 */
TEST(TestTranslator, translate)
{
    // Upper Case Letters
    EXPECT_EQ(translate('A'), UPPER_CASE);
    EXPECT_EQ(translate('D'), UPPER_CASE);
    EXPECT_EQ(translate('F'), F);
    EXPECT_EQ(translate('I'), I);
    EXPECT_EQ(translate('U'), U);
    // Lower Case Letters
    EXPECT_EQ(translate('a'), LOWER_CASE);
    EXPECT_EQ(translate('b'), LOWER_CASE);
    EXPECT_EQ(translate('z'), LOWER_CASE);
    EXPECT_EQ(translate('n'), LOWER_CASE);
    EXPECT_EQ(translate('t'), LOWER_CASE);
    // Numbers
    EXPECT_EQ(translate('0'), NUMBER);
    EXPECT_EQ(translate('8'), NUMBER);
    EXPECT_EQ(translate('5'), NUMBER);
    // Special Characters
    EXPECT_EQ(translate('('), SPECIAL);
    EXPECT_EQ(translate(')'), SPECIAL);
    EXPECT_EQ(translate('*'), SPECIAL);
    EXPECT_EQ(translate('{'), SPECIAL);
    EXPECT_EQ(translate('}'), SPECIAL);
    EXPECT_EQ(translate('/'), SPECIAL);
    EXPECT_EQ(translate(';'), SPECIAL);
    // Unique Characters
    EXPECT_EQ(translate('%' ), PERCENTAGE);
    EXPECT_EQ(translate('"' ), QUOTE);
    EXPECT_EQ(translate('.' ), DOT);
    EXPECT_EQ(translate('=' ), EQUALS);
    EXPECT_EQ(translate('!' ), EXCLAMATION);
    EXPECT_EQ(translate('>' ), GREATER);
    EXPECT_EQ(translate('<' ), LESS);
    EXPECT_EQ(translate('#' ), NUMERAL);
    EXPECT_EQ(translate(':' ), COLON);
    EXPECT_EQ(translate('-' ), MINUS);
    EXPECT_EQ(translate('+' ), PLUS);
    EXPECT_EQ(translate('\n'), ENDLINE);
    // Blank Characters
    EXPECT_EQ(translate(' ' ), BLANK);
    EXPECT_EQ(translate('\t'), BLANK);
    // Others
    EXPECT_EQ(translate('~'), OTHER);
    EXPECT_EQ(translate('?'), OTHER);
    EXPECT_EQ(translate('$'), OTHER);
    EXPECT_EQ(translate('^'), OTHER);
    EXPECT_EQ(translate('&'), OTHER);
    EXPECT_EQ(translate('|'), OTHER);
}