#include "gtest/gtest.h"
#include "utils/SymbolTable.h"


TEST(TestSymbolTable, addAndGet)
{
    SymbolTable table;
    const std::string symbol = "foo";
    const auto ref = table.addAndGet(symbol);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->symbol, symbol);
}

TEST(TestSymbolTable, get)
{
    SymbolTable table;
    const std::string symbol = "foo";
    table.addAndGet(symbol);
    const auto ref = table.get(symbol);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->symbol, symbol);
}


