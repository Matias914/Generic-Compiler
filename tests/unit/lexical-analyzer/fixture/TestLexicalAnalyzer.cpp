#include "TestLexicalAnalyzer.h"
#include "syntax-analyzer/components/parser.h"

void TestLexicalAnalyzer::SetUp()
{
    SYMBOL_TABLE.clear();
    LITERAL_TABLE.clear();

    if (VERBOSE_OPTION)
        REPORT_HANDLER.clear();
}

void TestLexicalAnalyzer::TearDown()
{
    if (VERBOSE_OPTION)
        if (REPORT_HANDLER.validOutput())
            REPORT_HANDLER.generateReport();
        else
            std::cerr << "\nCouldn't generate report!\n" << std::endl;
}

bool TestLexicalAnalyzer::validSymbol(const std::string& expected)
{
    const std::string actual = yylval.sref->symbol;
    if (const auto entry = SYMBOL_TABLE.get(actual); entry != nullptr)
        return (expected == entry->symbol);
    return false;
}

bool TestLexicalAnalyzer::validLiteral(const std::string& expected)
{
    const std::string actual = yylval.lref->constant;
    if (const auto entry = LITERAL_TABLE.get(actual); entry != nullptr)
        return (expected == entry->constant);
    return false;
}