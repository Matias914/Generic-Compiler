#ifndef GC_WAT_INSTRUCCIONS_BUILDERS_H
#define GC_WAT_INSTRUCCIONS_BUILDERS_H

#include "code-generator/components/Triples.h"

#include <string>

namespace CodeGenerator::InstructionsGenerators
{
    struct Metadata
    {
        std::string& output;
        std::string& nesting;
        const int& type;
        const Triples::Operand& o1;
        const Triples::Operand& o2;
        const std::map<const LiteralTable::Entry*, int>& offsets;
    };
    using InstructionsGenerator = void (*) (const Metadata& metadata);

    void generatePrint(const Metadata& m);
}

#endif //GC_WAT_INSTRUCCIONS_BUILDERS_H