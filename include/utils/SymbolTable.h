#ifndef GC_SYMBOLTABLE_H
#define GC_SYMBOLTABLE_H

#include <unordered_map>
#include <string_view>
#include <string>
#include <list>

#define ST_UNSUPPORTED (-1)

#define ST_FLOAT         0
#define ST_UINT          1

#define ST_PROGRAM       0
#define ST_VARIABLE      1
#define ST_FUNCTION      2
#define ST_PARAMETER     3

#define ST_CV            0
#define ST_CR            1

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
        int type      = ST_UNSUPPORTED;
        int use       = ST_UNSUPPORTED;
        int semantics = ST_UNSUPPORTED;
        int params    = ST_UNSUPPORTED;

        Entry() = default;

        Entry(std::string s, const int t, const int u, const int sem = ST_UNSUPPORTED, const int p = ST_UNSUPPORTED)
            : symbol(std::move(s)), type(t), use(u), semantics(sem), params(p) {}
    };

    SymbolTable();

    const Entry* addAndGet(const std::string& symbol);
    const Entry* get(const std::string& symbol) const;
    const Entry* update(const std::string& symbol, const Entry& entry);
    const Entry* upsert(const std::string& symbol, const Entry& entry);

    bool remove(const std::string& symbol);

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