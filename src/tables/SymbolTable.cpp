#include "tables/SymbolTable.h"

#include <iostream>
#include <ostream>

SymbolTable::SymbolTable()
{
    this->table = std::unordered_map<std::string, Metadata>();
}

/*
 * @brief agrega una entrada a la tabla de simbolos. Retorna un bool
 * que indica el estado de la operacion.
 */
bool SymbolTable::add(const std::string& symbol, const Metadata& entry)
{
    const auto it = this->table.find(symbol);
    if (it == this->table.end()) {
        this->table[symbol] = entry;
        return true;
    }
    return false;
}

/*
 * @brief da una referencia a la tabla. Lanza un std::runtime_error
 * en caso de no encontrarse.
 */
SymbolTable::EntryReference SymbolTable::get(const std::string& symbol) const
{
    const auto it = table.find(symbol);
    if (it != table.end())
    {
        EntryReference e;
        e.sptr = &it->first;
        e.dptr = &it->second;
        return e;
    }
    throw std::runtime_error("Symbol not found");
}