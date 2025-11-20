#include "utils/SymbolTable.h"
#include "utils/resources/builders.h"

#include <algorithm>

SymbolTable::SymbolTable() : mapping(), entries() {}

const SymbolTable::Entry* SymbolTable::addAndGet(const std::string& symbol)
{
    if (const auto it = mapping.find(symbol); it != mapping.end())
        return it->second;
    Entry& ref = entries.emplace_back(symbol, UNKNOWN, UNKNOWN);
    mapping.emplace(std::string_view(ref.symbol), &ref);
    return &ref;
}

const SymbolTable::Entry* SymbolTable::get(const std::string& symbol) const
{
    const auto it = mapping.find(symbol);
    return (it != mapping.end()) ? it->second : nullptr;
}

void SymbolTable::updateFields(Entry* target, const Entry& source)
{
    target->type = source.type;
    target->use = source.use;
    target->semantics = source.semantics;
    target->params = source.params;
}

void SymbolTable::removeFromList(const Entry* entryPtr)
{
    entries.remove_if([entryPtr](const Entry& e) {
            return &e == entryPtr;
    });
}

/*
 * @brief actualiza una entrada de la tabla de simbolos.
 *
 * - Verifica que la entrada a actualizar exista.
 * - Verifica que la nueva clave no esté siendo usada.
 * - Si la nueva clave cambia borra la entrada vieja y agrega una nueva, de lo contrario,
 * modifica los campos
 */
const SymbolTable::Entry* SymbolTable::update(const std::string& symbol, const Entry& entry)
{
    const auto row = mapping.find(symbol);
    if (row == mapping.end())
        return nullptr;
    if (symbol == entry.symbol)
    {
        updateFields(row->second, entry);
        return row->second;
    }
    if (mapping.find(entry.symbol) != mapping.end())
        return nullptr;
    mapping.erase(row);
    removeFromList(row->second);
    Entry& ref = entries.emplace_back(entry);
    mapping.emplace(std::string_view(ref.symbol), &ref);
    return &ref;
}

/*
 * @brief intenta actualizar una entrada. Si no existe, la crea.
 *
 * - Verifica si la nueva clave existe. Si existe, entonces, se verifica que la entrada que se quiere actualizar
 * no cambie de clave. De otra forma, la actualizacion no es válida porque no se puede insertar la nueva fila.
 * Caso contrario, se actualiza la entrada.
 * - Si no existe, entonces, la nueva fila se inserta y si la fila a actualizar existe, se borra.
 */
const SymbolTable::Entry* SymbolTable::upsert(const std::string& symbol, const Entry& entry)
{
    if (const auto newIt = mapping.find(entry.symbol); newIt != mapping.end())
    {
        if (entry.symbol != symbol)
            return nullptr;
        updateFields(newIt->second, entry);
        return newIt->second;
    }
    if (const auto oldIt = mapping.find(symbol); oldIt != mapping.end())
    {
        mapping.erase(oldIt);
        removeFromList(oldIt->second);
    }
    Entry& ref = entries.emplace_back(entry);
    mapping.emplace(std::string_view(ref.symbol), &ref);
    return &ref;
}

bool SymbolTable::remove(const std::string& symbol)
{
    const auto it = mapping.find(symbol);
    if (it == mapping.end()) {
        return false;
    }
    removeFromList(it->second);
    mapping.erase(it);
    return true;
}

std::string SymbolTable::toString() const
{
    using namespace StringBuilders::TableBuilders;
    std::string mssg;
    mssg.reserve(256 * entries.size());
    symbolTableHeader(mssg);
    for (const auto& entry : entries) {
        mssg.append("\n");
        symbolTableEntry(mssg, entry);
    }
    return mssg;
}

void SymbolTable::clear()
{
    entries.clear();
    mapping.clear();
}