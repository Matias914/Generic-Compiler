#include "gtest/gtest.h"
#include "utils/SymbolTable.h"

SymbolTable SYMBOL_TABLE;

TEST(TestSymbolTable, add)
{
    SymbolTable table;
    const std::string symbol = "foo";
    const auto ref = table.add(symbol);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->symbol, symbol);
}

TEST(TestSymbolTable, get)
{
    SymbolTable table;
    const std::string symbol = "foo";
    table.add(symbol);
    const auto ref = table.get(symbol);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->symbol, symbol);
}


