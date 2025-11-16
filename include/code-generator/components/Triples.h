#ifndef GC_TRIPLES_H
#define GC_TRIPLES_H

#include "utils/SymbolTable.h"
#include "utils/LiteralTable.h"

#include <vector>

#define TR_NULL  (-1)
#define TR_TRIPLE  0
#define TR_SYMBOL  1
#define TR_LITERAL 2

#define TR_FTOI            'A'
#define TR_BRANCH_TRUE     'B'
#define TR_BRANCH_FALSE    'C'
#define TR_BRANCH_FUNCTION 'D'
#define TR_EQUAL_OP        'E'
#define TR_NOT_EQUAL_OP    'F'
#define TR_GE_OP           'G'
#define TR_LE_OP           'H'

class Triples
{
public:
    union Value
    {
        const SymbolTable::Entry*  sref;
        const LiteralTable::Entry* lref;
        int tref;
    };
    struct Operand
    {
        int type;
        Value value;
    };
    struct Triple
    {
        const char op;
        Operand o1, o2;
    };
    Triples();

    int addTriple(const Triple& t);

    std::string toString(bool withTab, int& line) const;

private:
    std::vector<Triple> triples;
};


#endif //GC_TRIPLES_H