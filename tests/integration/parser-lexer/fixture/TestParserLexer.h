#ifndef GC_TESTPARSERLEXER_H
#define GC_TESTPARSERLEXER_H

#include "gtest/gtest.h"
#include "utils/SymbolTable.h"
#include "utils/LiteralTable.h"
#include "utils/ErrorHandler.h"
#include "utils/ReportHandler.h"

#include <string>

extern bool VERBOSE_OPTION;

extern std::string OUTPUT_DIRECTORY;
extern std::string WORKING_DIRECTORY;

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;

extern ErrorHandler ERROR_HANDLER;
extern ReportHandler REPORT_HANDLER;

class TestParserLexer : public ::testing::Test
{
    void SetUp() override;
    void TearDown() override;
};


#endif //GC_TESTPARSERLEXER_H