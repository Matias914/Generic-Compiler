#ifndef TPE_SYMBOLTABLE_H
#define TPE_SYMBOLTABLE_H

#include <string>
#include <unordered_map>

/*
 * @brief clase que representa una tabla de simbolos
 *
 * Usa una hash table para asociar a cada lexema su informacion.
 *
 */
class SymbolTable
{
public:
    class Entry
    {
    public:
        union
        {
            int   i;
            float f;
        } value;
        unsigned int type;
    };
    SymbolTable();

    Entry* add(const std::string& symbol, Entry* entry);
    Entry* get(const std::string& symbol) const;

private:
    std::unordered_map<std::string, Entry*> table;
};

#endif //TPE_SYMBOLTABLE_H