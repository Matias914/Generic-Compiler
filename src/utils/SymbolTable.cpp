#include "utils/SymbolTable.h"

#include <iostream>

SymbolTable::SymbolTable()
{
    this->mapping = std::unordered_map<std::string_view, Entry*>();
    this->entries = std::list<Entry>();
}

const SymbolTable::Entry* SymbolTable::addAndGet(const std::string& symbol)
{
    const auto it = this->mapping.find(symbol);
    if (it == this->mapping.end()) {
        auto entry = Entry();
        entry.symbol = symbol;
        Entry& ref = entries.emplace_back(entry);
        mapping.insert({std::string_view(ref.symbol), &ref});
        return &ref;
    }
    return it->second;
}

// TODO: hacer algo a futuro XD
int SymbolTable::addScope(const std::string& symbol, const Entry& entry) const
{
    return this->entries.size();
}

const SymbolTable::Entry* SymbolTable::get(const std::string& symbol) const
{

    if (const auto it = this->mapping.find(symbol); it != mapping.end())
        return it->second;
    return nullptr;
}

bool SymbolTable::updateValue(const std::string& symbol, const unsigned int& value)
{
    const auto it = mapping.find(symbol);
    if (it == mapping.end()) return false;
    it->second->value = value;
    return true;
}