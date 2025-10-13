#include "utils/SymbolTable.h"
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
        auto entry = Entry();
        entry.symbol = symbol;
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