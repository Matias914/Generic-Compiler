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
    auto entry = SymbolTable::Entry({symbol, ST_UINT, ST_VARIABLE});
    auto ref = table.update(symbol, entry);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->type, ST_UINT);
    EXPECT_EQ(ref->use, ST_VARIABLE);
    entry = SymbolTable::Entry({symbol, ST_FLOAT, ST_FUNCTION});
    ref = table.update(symbol, entry);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->type, ST_FLOAT);
    EXPECT_EQ(ref->use, ST_FUNCTION);
}

TEST(TestSymbolTable, upsert)
{
    SymbolTable table;
    const std::string symbol = "foo1";
    table.addAndGet(symbol);
    auto entry = SymbolTable::Entry({symbol, ST_UINT, ST_VARIABLE});
    auto ref = table.update(symbol, entry);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->type, ST_UINT);
    EXPECT_EQ(ref->use, ST_VARIABLE);
    const std::string other = "foo2";
    entry = SymbolTable::Entry({other, ST_FLOAT, ST_FUNCTION});
    ref = table.update(symbol, entry);
    EXPECT_NE(ref, nullptr);
    EXPECT_EQ(ref->symbol, other);
    EXPECT_EQ(ref->type, ST_FLOAT);
    EXPECT_EQ(ref->use, ST_FUNCTION);
    entry = SymbolTable::Entry({other, ST_UINT, ST_VARIABLE});
    ref = table.update(symbol, entry);
    EXPECT_EQ(ref, nullptr);
}


