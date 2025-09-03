#include "tables/SymbolTable.h"

SymbolTable::SymbolTable()
{
    this->table = std::unordered_map<std::string, Entry*>();
}

SymbolTable::Entry* SymbolTable::add(const std::string& symbol, Entry* entry)
{
    const auto it = this->table.find(symbol);
    if (it == this->table.end())
        this->table[symbol] = entry;
    return it->second;
}

SymbolTable::Entry* SymbolTable::get(const std::string& symbol) const
{
    return this->table.find(symbol)->second;
}