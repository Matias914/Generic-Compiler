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
#define TR_CALL            'D'
#define TR_RET             'E'
#define TR_EQUAL_OP        'F'
#define TR_NOT_EQUAL_OP    'G'
#define TR_GE_OP           'H'
#define TR_LE_OP           'I'
#define TR_PRINT           'J'

namespace CodeGenerator
{
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
            char op;
            Operand o1, o2;
        };
        Triples();

        int addTriple(const Triple& t);
        int addBuffer(const Triple& t);
        int getLastTriple() const;

        bool updateTripleReference(int id, int ref);

        void commit();

        std::string toString(bool withTab, int& line) const;

    private:
        std::vector<Triple> triples;
        std::vector<Triple> buffer;
    };
}


#endif //GC_TRIPLES_H