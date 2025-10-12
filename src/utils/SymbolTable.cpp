#include "utils/SymbolTable.h"
#include "utils/resources/macros.h"
#include "utils/resources/dispatcher.h"

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

void SymbolTable::clear()
{
    this->entries.clear();
    this->mapping.clear();
}

std::string SymbolTable::toString() const
{
    std::string mssg;
    mssg.reserve(32 * entries.size());
    using namespace StringBuilderDispatcher;
    StringBuilder builder = getStringBuilder(TABLE, SYMBOL_HEADER);
    mssg.append(builder({})).append("\n");
    builder = getStringBuilder(TABLE, SYMBOL_ENTRY);
    bool first = true;
    for (const auto& [symbol] : entries) {
        if (!first) mssg.append("\n");
        first = false;
        mssg.append(builder({symbol}));
    }
    return mssg;
}