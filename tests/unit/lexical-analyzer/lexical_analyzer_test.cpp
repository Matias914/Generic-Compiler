#include "gtest/gtest.h"
#include "utils/globals.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"

using namespace LexicalAnalyzer;

TEST(TestLexicalAnalyzer, yylex_test)
{
    filename("../tests/unit/lexical-analyzer/files/test.txt");

    EXPECT_EQ(yylex(), IDENTIFIER);
    auto* entry = SYMBOL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    std::string lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), '=');

    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    entry = LITERAL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "1.23F+10");

    EXPECT_EQ(yylex(), ';');
    EXPECT_EQ(yylex(), IF);
    EXPECT_EQ(yylex(), '(');

    EXPECT_EQ(yylex(), IDENTIFIER);
    entry = SYMBOL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), LE_OP);

    EXPECT_EQ(yylex(), INTEGER_LITERAL);
    entry = LITERAL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "9UI");

    EXPECT_EQ(yylex(), ')');
    EXPECT_EQ(yylex(), '{');

    EXPECT_EQ(yylex(), IDENTIFIER);
    entry = SYMBOL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), ASSIGN_OP);

    EXPECT_EQ(yylex(), STRING_LITERAL);
    entry = LITERAL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "\"hola como estas?\"");

    EXPECT_EQ(yylex(), '}');
    EXPECT_EQ(yylex(), ELSE);
    EXPECT_EQ(yylex(), '{');

    EXPECT_EQ(yylex(), IDENTIFIER);
    entry = SYMBOL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "Y");

    EXPECT_EQ(yylex(), '=');
    EXPECT_EQ(yylex(), '-');

    EXPECT_EQ(yylex(), INTEGER_LITERAL);
    entry = LITERAL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "1UI");

    EXPECT_EQ(yylex(), ';');
    EXPECT_EQ(yylex(), IF);
    EXPECT_EQ(yylex(), '(');

    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    entry = LITERAL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, ".3F-1");

    EXPECT_EQ(yylex(), NOT_EQUAL_OP);
    EXPECT_EQ(yylex(), DO);
    EXPECT_EQ(yylex(), WHILE);
    EXPECT_EQ(yylex(), ';');
    EXPECT_EQ(yylex(), ENDIF);

    EXPECT_EQ(yylex(), IDENTIFIER);
    entry = SYMBOL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), POINTER_OP);

    EXPECT_EQ(yylex(), IDENTIFIER);
    entry = SYMBOL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), IDENTIFIER);
    entry = SYMBOL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), GE_OP);

    EXPECT_EQ(yylex(), IDENTIFIER);
    entry = SYMBOL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "Y");

    EXPECT_EQ(yylex(), ';');

    EXPECT_EQ(yylex(), IDENTIFIER);
    entry = SYMBOL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "VARIABLE%%1");

    EXPECT_EQ(yylex(), GE_OP);

    EXPECT_EQ(yylex(), IDENTIFIER);
    entry = SYMBOL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), ';');
    EXPECT_EQ(yylex(), RETURN);

    EXPECT_EQ(yylex(), INTEGER_LITERAL);
    entry = LITERAL_TABLE.get(yylval);
    EXPECT_NE(entry, nullptr);
    lexeme = *(entry->symbol);
    EXPECT_EQ(lexeme, "0UI");

    EXPECT_EQ(yylex(), ';');

    EXPECT_EQ(yylex(), 0);
}
