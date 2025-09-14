#include "utils/SymbolTable.h"

#include <iostream>

SymbolTable::SymbolTable()
{
    this->mapping = std::map<std::string, int>();
    this->entries = std::vector<Entry>();
}

int SymbolTable::add(const std::string& symbol)
{
    const auto it = this->mapping.find(symbol);
    if (it == this->mapping.end()) {
        const int id = this->entries.size();
        const auto [it, _] = mapping.insert({symbol, id});
        auto entry = Entry();
        entry.symbol = &it->first;
        this->entries.push_back(entry);
        return id;
    }
    return it->second;
}

// TODO: hacer algo a futuro XD
int SymbolTable::addScope(const std::string& symbol, const Entry& entry)
{
    return -1;
}

const SymbolTable::Entry* SymbolTable::get(const int& id) const
{
    if (id < this->entries.size())
        return &this->entries[id];
    return nullptr;
}

const SymbolTable::Entry* SymbolTable::get(const std::string& symbol) const
{
    const auto it = mapping.find(symbol);
    if (it != mapping.end())
        return &this->entries[it->second];
    return nullptr;
}

bool SymbolTable::updateValue(const int& id, const Type& value)
{
    if (id  >= this->entries.size()) return false;
    this->entries[id].value = value;
    return true;
}

bool SymbolTable::updateValue(const std::string& symbol, const Type& value)
{
    const auto it = mapping.find(symbol);
    if (it == mapping.end()) return false;
    this->entries[it->second].value = value;
    return true;
}