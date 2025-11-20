#ifndef GC_GLOBALSGENERATOR_H
#define GC_GLOBALSGENERATOR_H

#include "utils/SymbolTable.h"

namespace CodeGenerator
{
    class GlobalsGenerator
    {
    public:
        explicit GlobalsGenerator(std::string& output) : output(output) {};

        virtual void generate(const SymbolTable::Entry& entry) = 0;
        virtual ~GlobalsGenerator() = default;
    protected:
        std::string& output;
    };
}

#endif //GC_GLOBALSGENERATOR_H