#include "utils/LiteralTable.h"

LiteralTable::LiteralTable()
{
    this->mapping = std::map<std::string_view, Entry*>();
    this->entries = std::list<Entry>();
}

const LiteralTable::Entry* LiteralTable::add(const std::string& constant, const unsigned int& type, const Type& value)
{
    const auto it = this->mapping.find(constant);
    if (it == this->mapping.end()) {
        auto entry = Entry();
        entry.constant = constant;
        entry.type = type;
        entry.value = value;
        // Solo la constante flotante puede no ser correcta
        if (type == TYPE_FLOAT)
            entry.valid.reset();
        else
            entry.valid.set();
        Entry& ref = entries.emplace_back(entry);
        mapping.insert({std::string_view(ref.constant), &ref});
        return &ref;
    }
    return it->second;
}

const LiteralTable::Entry* LiteralTable::get(const std::string& constant) const
{
    if (const auto it = mapping.find(constant); it != mapping.end())
        return it->second;
    return nullptr;
}

// TODO:
bool LiteralTable::updateToNegative(const std::string& constant)
{
    return false;
}