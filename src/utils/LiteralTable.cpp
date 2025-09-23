#include "utils/LiteralTable.h"

LiteralTable::LiteralTable()
{
    this->mapping = std::map<std::string_view, Entry*>();
    this->entries = std::list<Entry>();
}

const LiteralTable::Entry* LiteralTable::addAndGet(const std::string& constant, const unsigned int& type, const Type& value)
{
    const auto it = this->mapping.find(constant);
    if (it == this->mapping.end()) {
        auto entry = Entry();
        entry.constant = constant;
        entry.refcount = 1;
        entry.type = type;
        entry.value = value;
        Entry& ref = entries.emplace_back(entry);
        mapping.insert({std::string_view(ref.constant), &ref});
        return &ref;
    }
    it->second->refcount++;
    return it->second;
}

const LiteralTable::Entry* LiteralTable::get(const std::string& constant) const
{
    const auto it = mapping.find(constant);
    if (it == mapping.end()) return nullptr;
    it->second->refcount++;
    return it->second;
}

bool LiteralTable::decrementReferences(const std::string& constant)
{
    const auto it = this->mapping.find(constant);
    if (it == this->mapping.end()) return false;
    it->second->refcount--;
    if (it->second->refcount == 0)
    {
        for (auto position = entries.begin(); position != entries.end(); ++position) {
            if (position->constant == it->second->constant) {
                entries.erase(position);
                break;
            }
        }
        mapping.erase(it);
        return true;
    }
    return false;
}