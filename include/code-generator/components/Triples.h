#ifndef GC_TRIPLES_H
#define GC_TRIPLES_H

#include <vector>

#include "utils/LiteralTable.h"
#include "utils/SymbolTable.h"

#define NULLREF (-1)
#define TRIPLE    0
#define SYMBOL    1
#define LITERAL   2

#define CODEOP_FTOI         0
#define CODEOP_BRANCH_TRUE  1
#define CODEOP_BRANCH_FALSE 2
#define CODEOP_DO_START     3
#define CODEOP_IF_END       4
#define CODEOP_CALL         5
#define CODEOP_RET          6
#define CODEOP_PRINT        7
#define CODEOP_ASSIGN       8
#define CODEOP_EQUAL        9
#define CODEOP_NOT_EQUAL    10
#define CODEOP_GE           11
#define CODEOP_LE           12
#define CODEOP_GT           13
#define CODEOP_LT           14
#define CODEOP_SUM          15
#define CODEOP_SUB          16
#define CODEOP_MUL          17
#define CODEOP_DIV          18

namespace CodeGenerator
{
    /*
     * @brief clase que almacena un bloque de tercetos.
     *
     * Su rol es justamente manejar su almacenamiento, permitiendo guardarlos,
     * recorrerlos o modificarlos ligeramente (las referencias).
     */
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