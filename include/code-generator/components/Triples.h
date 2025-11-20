#ifndef GC_TRIPLES_H
#define GC_TRIPLES_H

#include "utils/SymbolTable.h"
#include "utils/LiteralTable.h"

#include <vector>

#define NULLREF (-1)
#define TRIPLE    0
#define SYMBOL    1
#define LITERAL   2

#define CODEOP_FTOI         0
#define CODEOP_BRANCH_TRUE  1
#define CODEOP_BRANCH_FALSE 2
#define CODEOP_CALL         3
#define CODEOP_RET          4
#define CODEOP_PRINT        5
#define CODEOP_EQUAL        6
#define CODEOP_NOT_EQUAL    7
#define CODEOP_GE           8
#define CODEOP_LE           9
#define CODEOP_GT           10
#define CODEOP_LT           11
#define CODEOP_SUM          12
#define CODEOP_SUB          13
#define CODEOP_MUL          14
#define CODEOP_DIV          15

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
            int codeop;
            int type;
            Operand o1, o2;
        };
        Triples();

        int addTriple(const Triple& t);
        int addBuffer(const Triple& t);
        int getLastTriple() const;

        bool updateTripleReference(int id, int ref);

        void commit();

        std::string toString(bool withTab, int& line) const;

        auto begin() const { return triples.begin(); }
        auto end()   const { return triples.end();   }

    private:
        std::vector<Triple> triples;
        std::vector<Triple> buffer;
    };
}


#endif //GC_TRIPLES_H