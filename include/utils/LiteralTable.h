#ifndef TPE_LITERALTABLE_H
#define TPE_LITERALTABLE_H

#include <map>
#include <list>
#include <bitset>

class LiteralTable
{
public:
    union Type
    {
        unsigned int i;
        float        f;
    };
    struct Entry
    {
        std::string constant;
        unsigned int refcount;
        int type;
        Type value;
    };
    LiteralTable();

    const Entry* addAndGet(const std::string& constant, const int& type, const Type& value);
    const Entry* get(const std::string& constant) const;
    bool decrementReferences(const std::string& constant);

    std::string toString() const;
private:
    std::map<std::string_view, Entry*> mapping;
    std::list<Entry> entries;
};

#endif //TPE_LITERALTABLE_H