#ifndef GC_TRIPLES_H
#define GC_TRIPLES_H

#include "utils/SymbolTable.h"
#include "utils/LiteralTable.h"

#include <vector>

constexpr char BRANCH = '~';

class Triples
{
public:
    union Value
    {
        const SymbolTable::Entry*  sref;
        const LiteralTable::Entry* lref;
        int tref;
    };
    struct Triple
    {
        const char& op;
        Value val1, val2;
    };

    int addTriple(Triple t);

private:
    std::vector<Triple> triples;
};


#endif //GC_TRIPLES_H