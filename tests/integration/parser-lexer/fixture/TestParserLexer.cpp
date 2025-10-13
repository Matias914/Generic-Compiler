#include "TestParserLexer.h"

void TestParserLexer::SetUp()
{
    SYMBOL_TABLE.clear();
    LITERAL_TABLE.clear();
    ERROR_HANDLER.clear();

    if (VERBOSE_OPTION)
        REPORT_HANDLER.clear();
}

void TestParserLexer::TearDown()
{
    if (VERBOSE_OPTION)
        if (REPORT_HANDLER.validOutput())
            REPORT_HANDLER.generateReport();
        else
            std::cerr << "\nCouldn't generate report!\n" << std::endl;
}