#include "gtest/gtest.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/LexicalAnalyzer.h"

TEST(TestLexicalAnalyzer, yylex)
{
    FileReader f;
    auto filename = "testfile.txt";
    std::string filecontent = "if ( ) \n\treturn\nelse\n\treturn\nendif;";
    std::ofstream tmp(filename);
    tmp << filecontent;
    tmp.close();
    LexicalAnalyzer::setFileName(filename);
    EXPECT_EQ(LexicalAnalyzer::yylex(), IF);
    EXPECT_EQ(LexicalAnalyzer::yylex(), 40);
    EXPECT_EQ(LexicalAnalyzer::yylex(), 41);
    EXPECT_EQ(LexicalAnalyzer::yylex(), RETURN);
    EXPECT_EQ(LexicalAnalyzer::yylex(), ELSE);
    EXPECT_EQ(LexicalAnalyzer::yylex(), RETURN);
    EXPECT_EQ(LexicalAnalyzer::yylex(), ENDIF);
}