#include "TestParserLexer.h"

#include "utils/CompilerState.h"

void TestParserLexer::SetUp()
{
    CompilerState::reset();
}

void TestParserLexer::TearDown()
{
    if (VERBOSE_OPTION)
        if (REPORT_HANDLER.validOutput())
            REPORT_HANDLER.generateReport();
        else
            std::cerr << "\nCouldn't generate report!\n" << std::endl;
}