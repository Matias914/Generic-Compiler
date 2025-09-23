#ifndef TPE_CONSTANTLITERALTABLE_H
#define TPE_CONSTANTLITERALTABLE_H

#include <map>
#include <list>
#include <bitset>

#define TYPE_UI     0
#define TYPE_FLOAT  1
#define TYPE_STRING 2

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
        unsigned int type;
        Type value;
        std::bitset<1> valid;
    };
    LiteralTable();
    // Wrapper de la tabla de simbolos
    const Entry* add(const std::string& constant, const unsigned int& type, const Type& value);
    const Entry* get(const std::string& constant) const;
    bool updateToNegative(const std::string& constant);

private:
    std::map<std::string_view, Entry*> mapping;
    std::list<Entry> entries;
};

#endif //TPE_CONSTANTLITERALTABLE_H