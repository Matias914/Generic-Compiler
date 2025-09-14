#include "utils/SymbolTable.h"
#include "utils/LiteralTable.h"

#include <iostream>

LiteralTable::LiteralTable()
{
    this->ts = SymbolTable();
}

int LiteralTable::add(const std::string& symbol)
{
    return this->ts.add(symbol);
}

// TODO: hacer algo a futuro XD
int LiteralTable::addScope(const std::string& symbol, const SymbolTable::Entry& entry)
{
    return this->ts.addScope(symbol, entry);
}

const SymbolTable::Entry* LiteralTable::get(const int& id) const
{
    return this->ts.get(id);
}

const SymbolTable::Entry* LiteralTable::get(const std::string& symbol) const
{
    return this->ts.get(symbol);
}

void LiteralTable::updateValue(const int& id, const SymbolTable::Type& value)
{
    this->ts.updateValue(id, value);
}

void LiteralTable::updateValue(const std::string& symbol, const SymbolTable::Type& value)
{
    this->ts.updateValue(symbol, value);
}