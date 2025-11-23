#include "gtest/gtest.h"
#include "utils/SymbolTable.h"
#include "syntax-analyzer/components/parser.h"

/*
 * @brief son pruebas muy simples de la tabla de simbolos
 */
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

TEST(TestSymbolTable, update)
{
    SymbolTable table;
    const std::string symbol = "foo";
    table.addAndGet(symbol);
    auto entry = SymbolTable::Entry({symbol, UINT, VARIABLE});
    auto ref = table.update(symbol, entry);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->type, UINT);
    EXPECT_EQ(ref->use, VARIABLE);
    entry = SymbolTable::Entry({symbol, FLOAT, FUNCTION});
    ref = table.update(symbol, entry);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->type, FLOAT);
    EXPECT_EQ(ref->use, FUNCTION);
}

TEST(TestSymbolTable, upsert)
{
    SymbolTable table;
    const std::string symbol = "foo1";
    table.addAndGet(symbol);
    auto entry = SymbolTable::Entry({symbol, UINT, VARIABLE});
    auto ref = table.update(symbol, entry);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->type, UINT);
    EXPECT_EQ(ref->use, VARIABLE);
    const std::string other = "foo2";
    entry = SymbolTable::Entry({other, FLOAT, FUNCTION});
    ref = table.update(symbol, entry);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->symbol, other);
    EXPECT_EQ(ref->type, FLOAT);
    EXPECT_EQ(ref->use, FUNCTION);
    entry = SymbolTable::Entry({other, UINT, VARIABLE});
    ref = table.update(symbol, entry);
    EXPECT_EQ(ref, nullptr);
}


