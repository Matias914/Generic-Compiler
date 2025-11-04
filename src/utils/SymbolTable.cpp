#include "utils/SymbolTable.h"

#include <algorithm>

#include "utils/resources/builders.h"

SymbolTable::SymbolTable()
{
    this->mapping = std::unordered_map<std::string_view, Entry*>();
    this->entries = std::list<Entry>();
}

const SymbolTable::Entry* SymbolTable::addAndGet(const std::string& symbol)
{
    const auto it = this->mapping.find(symbol);
    if (it == this->mapping.end()) {
        Entry& ref = entries.emplace_back(Entry({
            symbol,
            UNSUPPORTED,
            UNSUPPORTED,
            UNSUPPORTED,
            UNSUPPORTED
        }));
        this->mapping.insert({std::string_view(ref.symbol), &ref});
        return &ref;
    }
    return it->second;
}

const SymbolTable::Entry* SymbolTable::get(const std::string& symbol) const
{
    if (const auto it = this->mapping.find(symbol); it != mapping.end())
        return it->second;
    return nullptr;
}

/*
 * @brief actualiza una entrada de la tabla de simbolos.
 *
 * - Verifica que la entrada a actualizar exista.
 * - Verifica que la nueva clave no esté siendo usada.
 * - Si la nueva clave cambia borra la entrada vieja y agrega una nueva, de lo contrario,
 * modifica los campos
 */
const SymbolTable::Entry* SymbolTable::update(const std::string& symbol, const Entry* entry)
{
    const auto row = this->mapping.find(symbol);
    if (row == this->mapping.end())
        return nullptr;
    if (symbol == entry->symbol)
    {
        row->second->type = entry->type;
        row->second->use = entry->use;
        row->second->semantics = entry->semantics;
        row->second->params = entry->params;
        return row->second;
    }
    if (const auto it = this->mapping.find(entry->symbol); it != this->mapping.end())
        return nullptr;
    this->mapping.erase(row);
    this->entries.remove_if([&](const auto& e){ return e.symbol == symbol; });
    Entry& ref = entries.emplace_back(*entry);
    this->mapping.insert({std::string_view(ref.symbol), &ref});
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
const SymbolTable::Entry* SymbolTable::upsert(const std::string& symbol, const Entry* entry)
{
    if (const auto it = this->mapping.find(entry->symbol); it != this->mapping.end())
    {
        if (entry->symbol == symbol)
        {
            it->second->type = entry->type;
            it->second->use = entry->use;
            it->second->semantics = entry->semantics;
            it->second->params = entry->params;
            return it->second;
        }
        return nullptr;
    }
    Entry& ref = entries.emplace_back(*entry);
    this->mapping.insert({std::string_view(ref.symbol), &ref});
    if (const auto it = this->mapping.find(symbol); it != this->mapping.end())
    {
        this->mapping.erase(it);
        this->entries.remove_if([&](const auto& e){ return e.symbol == symbol; });
    }
    return &ref;
}

bool SymbolTable::remove(const std::string& symbol)
{
    const int n = this->mapping.erase(symbol);
    this->entries.remove_if([&](const auto& e){ return e.symbol == symbol; });
    if (n != 0)
        return true;
    return false;
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
    this->entries.clear();
    this->mapping.clear();
}