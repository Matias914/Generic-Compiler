#ifndef GC_SYMBOLTABLE_H
#define GC_SYMBOLTABLE_H

#include <unordered_map>
#include <string_view>
#include <string>
#include <list>

#define UNSUPPORTED (-1)
#define PROGRAM       0
#define VARIABLE      1
#define FUNCTION      2
#define PARAMETER     3
#define CV            4

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
        int type      = UNSUPPORTED;
        int use       = UNSUPPORTED;
        int semantics = UNSUPPORTED;
        int params    = UNSUPPORTED;
    };

    SymbolTable();
    const Entry* addAndGet(const std::string& symbol);
    const Entry* get(const std::string& symbol) const;
    const Entry* update(const std::string& symbol, const Entry* entry);
    const Entry* upsert(const std::string& symbol, const Entry* entry);
    bool remove(const std::string& symbol);

    std::string toString() const;

    // útil para Testing
    void clear();

private:
    std::unordered_map<std::string_view, Entry*> mapping;
    std::list<Entry> entries;
};

#endif //GC_SYMBOLTABLE_H