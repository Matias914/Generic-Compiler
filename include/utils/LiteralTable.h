#ifndef TPE_CONSTANTLITERALTABLE_H
#define TPE_CONSTANTLITERALTABLE_H

#include "SymbolTable.h"

class LiteralTable
{
    public:
    LiteralTable();

    // Wrapper de la tabla de simbolos
    int add(const std::string& symbol);
    int addScope(const std::string& symbol, const SymbolTable::Entry& entry);
    const SymbolTable::Entry* get(const int& id) const;
    const SymbolTable::Entry* get(const std::string& symbol) const;
    void updateValue(const int& id, const SymbolTable::Type& value);
    void updateValue(const std::string& symbol, const SymbolTable::Type& value);

private:
    SymbolTable ts;
};

#endif //TPE_CONSTANTLITERALTABLE_H