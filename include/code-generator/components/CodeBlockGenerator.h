#ifndef GC_CODEBLOCKGENERATOR_H
#define GC_CODEBLOCKGENERATOR_H

#include "code-generator/components/Triples.h"
#include "utils/SymbolTable.h"

namespace CodeGenerator
{
    /*
     * @brief interfaz que define cómo es un generador de código ejecutable de
     * Assembler.
     */
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