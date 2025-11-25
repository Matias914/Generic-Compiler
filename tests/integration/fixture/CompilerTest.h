#ifndef GC_COMPILERTEST_H
#define GC_COMPILERTEST_H

#include <string>

#include "gtest/gtest.h"
#include "utils/ErrorHandler.h"
#include "utils/LiteralTable.h"
#include "utils/ReportHandler.h"
#include "utils/SymbolTable.h"

extern bool VERBOSE_OPTION;

extern std::string OUTPUT_DIRECTORY;
extern std::string WORKING_DIRECTORY;

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;

extern ErrorHandler ERROR_HANDLER;
extern ReportHandler REPORT_HANDLER;

class CompilerTest : public ::testing::Test
{
    void SetUp() override;
    void TearDown() override;
};


#endif //GC_COMPILERTEST_H