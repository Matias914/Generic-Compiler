#ifndef TPE_SYMBOLTABLE_H
#define TPE_SYMBOLTABLE_H

#include <unordered_map>
#include <string_view>
#include <string>
#include <list>

class SymbolTable
{
public:
    struct Entry
    {
        std::string symbol;
    };

    SymbolTable();
    const Entry* addAndGet(const std::string& symbol);
    const Entry* get(const std::string& symbol) const;

    void clear();

    std::string toString() const;

private:
    std::unordered_map<std::string_view, Entry*> mapping;
    std::list<Entry> entries;
};

#endif //TPE_SYMBOLTABLE_H