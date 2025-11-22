#ifndef GC_SYMBOLTABLE_H
#define GC_SYMBOLTABLE_H

#include <list>
#include <string>
#include <string_view>
#include <unordered_map>

#include "resources/types.h"

/*
 * @brief colecciona los símbolos hallados durante el análisis
 * léxico y sus metadatos.
 *
 * Una de sus responsabilidades la de saber convertirse a String,
 * además, claras funciones de búsquedas y agregados de símbolos.
 */
class SymbolTable
{
public:
    struct Entry
    {
        std::string symbol = "";
        int type      = UNKNOWN;
        int use       = UNKNOWN;
        int semantics = UNKNOWN;
        int params    = UNKNOWN;

        Entry() = default;

        Entry(std::string s, const int t, const int u, const int sem = UNKNOWN, const int p = UNKNOWN)
            : symbol(std::move(s)), type(t), use(u), semantics(sem), params(p) {}
    };

    SymbolTable();

    const Entry* addAndGet(const std::string& symbol);
    const Entry* get(const std::string& symbol) const;
    const Entry* update(const std::string& symbol, const Entry& entry);
    const Entry* upsert(const std::string& symbol, const Entry& entry);

    bool remove(const std::string& symbol);

    auto begin() const { return this->entries.begin(); }
    auto end()   const { return this->entries.end();   }

    std::string toString() const;

    // útil para Testing
    void clear();

private:
    std::unordered_map<std::string_view, Entry*> mapping;
    std::list<Entry> entries;

    static void updateFields(Entry* target, const Entry& source);
    void removeFromList(const Entry* entryPtr);
};

#endif //GC_SYMBOLTABLE_H