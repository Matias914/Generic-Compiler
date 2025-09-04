#include "gtest/gtest.h"
#include "tables/SymbolTable.h"

/*
 * @brief se agrega un dato a la tabla de simbolos.
 * Luego, se verifica que este se encuentre en
 * la tabla.
 */
TEST(TestSymbolTable, add)
{
    SymbolTable table;
    SymbolTable::Metadata e1;
    e1.value.f = 3.2f;
    e1.type = 1;
    const std::string symbol = "foo";
    bool valid = table.add(symbol, e1);
    EXPECT_TRUE(valid);
    valid = table.add(symbol, e1);
    EXPECT_FALSE(valid);
    const SymbolTable::Metadata e2 = e1;
    valid = table.add(symbol, e2);
    EXPECT_FALSE(valid);
}

/*
 * @brief se agrega un dato a la tabla de simbolos.
 * Luego, se verifica que pueda obtenerse correctamente.
 */
TEST(TestSymbolTable, get)
{
    SymbolTable table;
    SymbolTable::Metadata e1;
    e1.value.f = 3.2f;
    e1.type = 1;
    const std::string symbol = "foo";
    table.add(symbol, e1);
    const auto e2 = table.get(symbol);
    EXPECT_EQ(*e2.sptr, "foo");
    EXPECT_EQ(e2.dptr->type, 1);
    EXPECT_EQ(e2.dptr->value.f, 3.2f);
}
