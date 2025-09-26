#include "gtest/gtest.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"

#include "utils/ErrorHandler.h"

using namespace LexicalAnalyzer;

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;

TEST(TestLexicalAnalyzer, yylex_test)
{
    open("../tests/unit/lexical-analyzer/files/test.txt");

    EXPECT_EQ(yylex(), IDENTIFIER);
    auto symb_entry = SYMBOL_TABLE.get(yylval.symbol_reference->symbol);
    EXPECT_NE(symb_entry, nullptr);
    std::string lexeme = symb_entry->symbol;
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), '=');

    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    auto const_entry = LITERAL_TABLE.get(yylval.constant_reference->constant);
    EXPECT_NE(const_entry, nullptr);
    lexeme = const_entry->constant;
    EXPECT_EQ(lexeme, "1.23F+10");

    EXPECT_EQ(yylex(), ';');
    EXPECT_EQ(yylex(), IF);
    EXPECT_EQ(yylex(), '(');

    EXPECT_EQ(yylex(), IDENTIFIER);
    symb_entry = SYMBOL_TABLE.get(yylval.symbol_reference->symbol);
    EXPECT_NE(symb_entry, nullptr);
    lexeme = symb_entry->symbol;
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), LE_OP);

    EXPECT_EQ(yylex(), UINTEGER_LITERAL);
    const_entry = LITERAL_TABLE.get(yylval.constant_reference->constant);
    EXPECT_NE(const_entry, nullptr);
    lexeme = const_entry->constant;
    EXPECT_EQ(lexeme, "9UI");

    EXPECT_EQ(yylex(), ')');
    EXPECT_EQ(yylex(), '{');

    EXPECT_EQ(yylex(), IDENTIFIER);
    symb_entry = SYMBOL_TABLE.get(yylval.symbol_reference->symbol);
    EXPECT_NE(symb_entry, nullptr);
    lexeme = symb_entry->symbol;
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), ASSIGN_OP);

    EXPECT_EQ(yylex(), STRING_LITERAL);
    const_entry = LITERAL_TABLE.get(yylval.constant_reference->constant);
    EXPECT_NE(const_entry, nullptr);
    lexeme = const_entry->constant;
    EXPECT_EQ(lexeme, "\"hola como estas?\"");

    EXPECT_EQ(yylex(), '}');
    EXPECT_EQ(yylex(), ELSE);
    EXPECT_EQ(yylex(), '{');

    EXPECT_EQ(yylex(), IDENTIFIER);
    symb_entry = SYMBOL_TABLE.get(yylval.symbol_reference->symbol);
    EXPECT_NE(symb_entry, nullptr);
    lexeme = symb_entry->symbol;
    EXPECT_EQ(lexeme, "Y");

    EXPECT_EQ(yylex(), '=');
    EXPECT_EQ(yylex(), '-');

    EXPECT_EQ(yylex(), UINTEGER_LITERAL);
    const_entry = LITERAL_TABLE.get(yylval.constant_reference->constant);
    EXPECT_NE(const_entry, nullptr);
    lexeme = const_entry->constant;
    EXPECT_EQ(lexeme, "1UI");

    EXPECT_EQ(yylex(), ';');
    EXPECT_EQ(yylex(), IF);
    EXPECT_EQ(yylex(), '(');

    EXPECT_EQ(yylex(), FLOAT_LITERAL);
    const_entry = LITERAL_TABLE.get(yylval.constant_reference->constant);
    EXPECT_NE(const_entry, nullptr);
    lexeme = const_entry->constant;
    EXPECT_EQ(lexeme, ".3F-1");

    EXPECT_EQ(yylex(), NOT_EQUAL_OP);
    EXPECT_EQ(yylex(), DO);
    EXPECT_EQ(yylex(), WHILE);
    EXPECT_EQ(yylex(), ';');
    EXPECT_EQ(yylex(), ENDIF);

    EXPECT_EQ(yylex(), IDENTIFIER);
    symb_entry = SYMBOL_TABLE.get(yylval.symbol_reference->symbol);
    EXPECT_NE(symb_entry, nullptr);
    lexeme = symb_entry->symbol;
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), POINTER_OP);

    EXPECT_EQ(yylex(), IDENTIFIER);
    symb_entry = SYMBOL_TABLE.get(yylval.symbol_reference->symbol);
    EXPECT_NE(symb_entry, nullptr);
    lexeme = symb_entry->symbol;
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), IDENTIFIER);
    symb_entry = SYMBOL_TABLE.get(yylval.symbol_reference->symbol);
    EXPECT_NE(symb_entry, nullptr);
    lexeme = symb_entry->symbol;
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), GE_OP);

    EXPECT_EQ(yylex(), IDENTIFIER);
    symb_entry = SYMBOL_TABLE.get(yylval.symbol_reference->symbol);
    EXPECT_NE(symb_entry, nullptr);
    lexeme = symb_entry->symbol;
    EXPECT_EQ(lexeme, "Y");

    EXPECT_EQ(yylex(), ';');

    EXPECT_EQ(yylex(), IDENTIFIER);
    symb_entry = SYMBOL_TABLE.get(yylval.symbol_reference->symbol);
    EXPECT_NE(symb_entry, nullptr);
    lexeme = symb_entry->symbol;
    EXPECT_EQ(lexeme, "VARIABLE%%1");

    EXPECT_EQ(yylex(), GE_OP);

    EXPECT_EQ(yylex(), IDENTIFIER);
    symb_entry = SYMBOL_TABLE.get(yylval.symbol_reference->symbol);
    EXPECT_NE(symb_entry, nullptr);
    lexeme = symb_entry->symbol;
    EXPECT_EQ(lexeme, "X");

    EXPECT_EQ(yylex(), ';');
    EXPECT_EQ(yylex(), RETURN);

    EXPECT_EQ(yylex(), UINTEGER_LITERAL);
    const_entry = LITERAL_TABLE.get(yylval.constant_reference->constant);
    EXPECT_NE(const_entry, nullptr);
    lexeme = const_entry->constant;
    EXPECT_EQ(lexeme, "0UI");

    EXPECT_EQ(yylex(), ';');

    EXPECT_EQ(yylex(), 0);
}
