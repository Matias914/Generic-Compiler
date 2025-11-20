#ifndef GC_WATCODEBLOCKGENERATOR_H
#define GC_WATCODEBLOCKGENERATOR_H

#include "utils/SymbolTable.h"
#include "code-generator/components/Triples.h"
#include "code-generator/components/CodeBlockGenerator.h"
#include "code-generator/components/wat-generation/wat_instruccions_builders.h"

#include <string>

namespace CodeGenerator
{
    class WatCodeBlockGenerator final : public CodeBlockGenerator
    {
    public:
        explicit WatCodeBlockGenerator(std::string& output, std::map<const LiteralTable::Entry*, int> offsets);
        ~WatCodeBlockGenerator() override = default;

        void generate(const SymbolTable::Entry& s, const Triples& triples) override;

    private:
        std::string nesting;
        std::map<const LiteralTable::Entry*, int> offsets;

        std::map<char, InstructionsGenerators::InstructionsGenerator> mapping = {
            {CODEOP_PRINT, InstructionsGenerators::generatePrint }
        };
    };
}

#endif //GC_WATCODEBLOCKGENERATOR_H