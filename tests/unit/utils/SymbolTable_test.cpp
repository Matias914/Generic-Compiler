#include "gtest/gtest.h"
#include "utils/SymbolTable.h"

SymbolTable SYMBOL_TABLE;

TEST(TestSymbolTable, add)
{
    SymbolTable table;
    const std::string symbol = "foo";
    const int ref = table.add(symbol);
    EXPECT_NE(ref, -1);
    auto entry = table.get(ref);
    EXPECT_EQ(*(entry->symbol), symbol);
    entry = table.get(symbol);
    EXPECT_EQ(*(entry->symbol), symbol);
}


