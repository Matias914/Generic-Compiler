#ifndef GC_LITERALTABLE_H
#define GC_LITERALTABLE_H

#include <bitset>
#include <list>
#include <map>

#include "resources/types.h"

/*
 * @brief colecciona las constantes literales halladas durante
 * el análisis léxico y sus metadatos.
 *
 * Una de sus responsabilidades la de saber convertirse a String,
 * además, claras funciones de búsquedas y agregados de constantes.
 * Debe manejar un contador de referencias que le permita saber si
 * una constante está siendo usada (existe en el programa) con el fin
 * de poder liberar memoria en caso contrario.
 */
class LiteralTable
{
public:
    union TypeValue
    {
        unsigned int i;
        float        f;
    };

    struct Entry
    {
        std::string constant  = "";
        unsigned int refcount = 0;
        int type              = UNKNOWN;
        TypeValue value;
    };

    LiteralTable();

    const Entry* addAndGet(const std::string& constant, const int& type, const TypeValue& value);
    const Entry* get(const std::string& constant) const;

    bool decrementReferences(const std::string& constant);

    std::string toString() const;

    auto begin() const { return this->entries.begin(); }
    auto end()   const { return this->entries.end();   }

    // Útil para Testing
    void clear();

    // tracing information
    int getStringCount() const;
    int getCharactersCount() const;

private:
    std::map<std::string_view, Entry*> mapping;
    std::list<Entry> entries;

    int strings_count;
    int characters_count;
};

#endif //GC_LITERALTABLE_H