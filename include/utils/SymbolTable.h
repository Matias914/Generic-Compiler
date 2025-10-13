#ifndef GC_SYMBOLTABLE_H
#define GC_SYMBOLTABLE_H

#include <unordered_map>
#include <string_view>
#include <string>
#include <list>

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
        std::string symbol;
    };

    SymbolTable();
    const Entry* addAndGet(const std::string& symbol);
    const Entry* get(const std::string& symbol) const;

    std::string toString() const;

    // útil para Testint
    void clear();

private:
    std::unordered_map<std::string_view, Entry*> mapping;
    std::list<Entry> entries;
};

#endif //GC_SYMBOLTABLE_H