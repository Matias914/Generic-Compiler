#include "gtest/gtest.h"
#include "../include/prueba.h"

TEST(TestIndexMapping, indexMapping)
{
    // Upper Case Letters
    EXPECT_EQ(indexMapping('A'), 0);
    EXPECT_EQ(indexMapping('D'), 0);
    EXPECT_EQ(indexMapping('F'), 1);
    EXPECT_EQ(indexMapping('I'), 2);
    EXPECT_EQ(indexMapping('U'), 3);
    // Lower Case Letters
    EXPECT_EQ(indexMapping('a'), 4);
    EXPECT_EQ(indexMapping('b'), 4);
    EXPECT_EQ(indexMapping('z'), 4);
    EXPECT_EQ(indexMapping('n'), 5);
    EXPECT_EQ(indexMapping('t'), 6);
    // Numbers
    EXPECT_EQ(indexMapping('0'), 7);
    EXPECT_EQ(indexMapping('8'), 7);
    EXPECT_EQ(indexMapping('5'), 7);
    // Special Characters
    EXPECT_EQ(indexMapping('('), 8);
    EXPECT_EQ(indexMapping(')'), 8);
    EXPECT_EQ(indexMapping('*'), 8);
    EXPECT_EQ(indexMapping('{'), 8);
    EXPECT_EQ(indexMapping('}'), 8);
    EXPECT_EQ(indexMapping('/'), 8);
    EXPECT_EQ(indexMapping(';'), 8);
    EXPECT_EQ(indexMapping(','), 8);
    // Operators And Distinguished Characters
    EXPECT_EQ(indexMapping(' '), 9);
    EXPECT_EQ(indexMapping('!'), 10);
    EXPECT_EQ(indexMapping('"'), 11);
    EXPECT_EQ(indexMapping('#'), 12);
    EXPECT_EQ(indexMapping('%'), 13);
    EXPECT_EQ(indexMapping('+'), 14);
    EXPECT_EQ(indexMapping('-'), 15);
    EXPECT_EQ(indexMapping('.'), 16);
    EXPECT_EQ(indexMapping(':'), 17);
    EXPECT_EQ(indexMapping('<'), 18);
    EXPECT_EQ(indexMapping('='), 19);
    EXPECT_EQ(indexMapping('>'), 20);
    EXPECT_EQ(indexMapping('\\'), 21);
    // Others
    EXPECT_EQ(indexMapping('~'), 22);
    EXPECT_EQ(indexMapping('?'), 22);
    EXPECT_EQ(indexMapping('$'), 22);
    EXPECT_EQ(indexMapping('^'), 22);
    EXPECT_EQ(indexMapping('&'), 22);
    EXPECT_EQ(indexMapping('|'), 22);
}
