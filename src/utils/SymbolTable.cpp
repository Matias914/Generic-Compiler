#include "utils/SymbolTable.h"

#include <algorithm>

#include "utils/resources/builders.h"

SymbolTable::SymbolTable()
{
    this->mapping = std::unordered_map<std::string_view, Entry*>();
    this->entries = std::list<Entry>();
}

const SymbolTable::Entry* SymbolTable::addAndGet(const std::string& symbol)
{
    const auto it = this->mapping.find(symbol);
    if (it == this->mapping.end()) {
        auto entry = Entry({ symbol, -1, -1 });
        Entry& ref = entries.emplace_back(entry);
        mapping.insert({std::string_view(ref.symbol), &ref});
        return &ref;
    }
    return it->second;
}

const SymbolTable::Entry* SymbolTable::get(const std::string& symbol) const
{

    if (const auto it = this->mapping.find(symbol); it != mapping.end())
        return it->second;
    return nullptr;
}

const SymbolTable::Entry* SymbolTable::update(const std::string& symbol, const int& type, const int& use)
{
    if (const auto it = this->mapping.find(symbol); it != this->mapping.end())
    {
        it->second->type = type;
        it->second->use = use;
        return it->second;
    }
    return nullptr;
}

const SymbolTable::Entry* SymbolTable::upsert(const std::string& symbol, const std::string& new_symbol, const int& type, const int& use)
{
    if (const auto it = this->mapping.find(new_symbol); it != this->mapping.end())
    {
        if (symbol == new_symbol)
        {
            it->second->type = type;
            it->second->use = use;
            return it->second;
        }
        return nullptr;
    }
    auto entry = Entry({ new_symbol, type, use });
    Entry& ref = entries.emplace_back(entry);
    mapping.insert({std::string_view(ref.symbol), &ref});
    if (const auto it = this->mapping.find(symbol); it != this->mapping.end())
    {
        this->mapping.erase(it);
        this->entries.remove_if([&](const auto& e){ return e.symbol == symbol; });
    }
    return &ref;
}

bool SymbolTable::remove(const std::string& symbol)
{
    const int n = this->mapping.erase(symbol);
    this->entries.erase(
        std::remove_if(
            this->entries.begin(),
            this->entries.end(),
            [&](const auto& e){ return e.symbol == symbol; }
        ),
        this->entries.end()
    );
    if (n != 0)
        return true;
    return false;
}

std::string SymbolTable::toString() const
{
    using namespace StringBuilders::TableBuilders;
    std::string mssg;
    mssg.reserve(256 * entries.size());
    symbolTableHeader(mssg);
    for (const auto& entry : entries) {
        mssg.append("\n");
        symbolTableEntry(mssg, entry);
    }
    return mssg;
}

void SymbolTable::clear()
{
    this->entries.clear();
    this->mapping.clear();
}