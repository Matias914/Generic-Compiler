#include "CompilerTest.h"

#include <iostream>

#include "utils/CompilerState.h"

void CompilerTest::SetUp()
{
    CompilerState::reset();
}

void CompilerTest::TearDown()
{
    if (VERBOSE_OPTION)
        if (REPORT_HANDLER.validOutput())
            REPORT_HANDLER.generateReport();
        else
            std::cerr << "\nCouldn't generate report!\n" << std::endl;
}