#ifndef TPE_SYMBOLTABLE_H
#define TPE_SYMBOLTABLE_H

#include <unordered_map>
#include <list>
#include <string_view>
#include <string>

class SymbolTable
{
public:
    struct Entry
    {
        std::string symbol;
        unsigned int value;
    };
    SymbolTable();
    // Devuelve la referencia a la entrada de la tabla
    const Entry* addAndGet(const std::string& symbol);
    int addScope(const std::string& symbol, const Entry& entry) const;
    // Se puede invalidar el Entry si se agregan scopes
    const Entry* get(const std::string& symbol) const;
    // Se puede invalidar la referencia a symbol si se borran
    // elementos del mapa
    bool updateValue(const std::string& symbol, const unsigned int& value);

    std::string toString() const;

private:
    std::unordered_map<std::string_view, Entry*> mapping;
    std::list<Entry> entries;
};

#endif //TPE_SYMBOLTABLE_H