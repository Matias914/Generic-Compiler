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
    // TODO: Si crece en memoria, pasar a puntero.
    struct Metadata
    {
        union
        {
            int   i;
            float f;
        } value;
        unsigned int type;
    };
    struct EntryReference
    {
        const std::string* sptr;
        const Metadata*    dptr;
    };
    SymbolTable();

    bool add(const std::string& symbol, const Metadata& entry);
    /* Devuelve iterador constante */
    EntryReference get(const std::string& symbol) const;

private:
    std::unordered_map<std::string, Metadata> table;
};

#endif //TPE_SYMBOLTABLE_H