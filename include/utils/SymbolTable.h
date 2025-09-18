#ifndef TPE_SYMBOLTABLE_H
#define TPE_SYMBOLTABLE_H

#include <map>
#include <vector>
#include <string>

class SymbolTable
{
public:
    union Type
    {
        int     i;
        float   f;
    };
        struct Entry
        {
            const std::string* symbol;
            unsigned int type;
            Type value;
        };
    SymbolTable();
    // Devuelve la referencia a la entrada de la tabla
    int add(const std::string& symbol);
    int addScope(const std::string& symbol, const Entry& entry);
    // Se puede invalidar el Entry si se agregan scopes
    const Entry* get(const int& id) const;
    const Entry* get(const std::string& symbol) const;
    // Se puede invalidar la referencia a symbol si se borran
    // elementos del mapa
    bool updateValue(const int& id, const Type& value);
    bool updateValue(const std::string& symbol, const Type& value);

private:
    std::map<std::string, int> mapping;
    std::vector<Entry> entries;
};

#endif //TPE_SYMBOLTABLE_H