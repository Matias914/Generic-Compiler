#include "utils/LiteralTable.h"
#include "utils/resources/builders.h"
#include "syntax-analyzer/components/parser.h"

LiteralTable::LiteralTable() : mapping(), entries(), strings_count(0), characters_count(0) {}

const LiteralTable::Entry* LiteralTable::addAndGet(const std::string& constant, const int& type, const TypeValue& value)
{
    if (const auto it = mapping.find(constant); it != mapping.end()) {
        it->second->refcount++;
        return it->second;
    }
    if (type == STRING)
    {
        strings_count++;
        characters_count += constant.length() - 2;
    }
    else if (type != FLOAT && type != UINT)
        return nullptr;
    Entry& ref = entries.emplace_back(Entry{constant, 1, type, value});
    mapping.emplace(std::string_view(ref.constant), &ref);
    return &ref;
}

const LiteralTable::Entry* LiteralTable::get(const std::string& constant) const
{
    const auto it = mapping.find(constant);
    return (it != mapping.end()) ? it->second : nullptr;
}

bool LiteralTable::decrementReferences(const std::string& constant)
{
    const auto it = mapping.find(constant);
    if (it == mapping.end())
        return false;
    if (--it->second->refcount == 0)
    {
        Entry* entryPtr = it->second;
        mapping.erase(it);
        entries.remove_if([entryPtr](const Entry& e) {
            return &e == entryPtr;
        });
        return true;
    }
    return false;
}

std::string LiteralTable::toString() const
{
    using namespace  StringBuilders::TableBuilders;
    std::string mssg;
    mssg.reserve(256 * entries.size());
    literalTableHeader(mssg);
    for (const auto& entry : entries) {
        mssg.append("\n");
        literalTableEntry(mssg, entry);
    }
    return mssg;
}

void LiteralTable::clear()
{
    entries.clear();
    mapping.clear();
}

int LiteralTable::getStringCount() const
{
    return strings_count;
}

int LiteralTable::getCharactersCount() const
{
    return characters_count;
}
