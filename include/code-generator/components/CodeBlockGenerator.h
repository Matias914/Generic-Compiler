#ifndef GC_CODEBLOCKGENERATOR_H
#define GC_CODEBLOCKGENERATOR_H

#include "utils/SymbolTable.h"
#include "code-generator/components/Triples.h"

namespace CodeGenerator
{
    class CodeBlockGenerator
    {
    public:
        explicit CodeBlockGenerator(std::string& output) : output(output) {}

        virtual void generate(const SymbolTable::Entry& s, const Triples& triple) = 0;
        virtual ~CodeBlockGenerator() = default;
    protected:
        std::string& output;
    };
}

#endif //GC_CODEBLOCKGENERATOR_H