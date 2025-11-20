#ifndef GC_WATGLOBALSGENERATOR_H
#define GC_WATGLOBALSGENERATOR_H

#include "code-generator/components/GlobalsGenerator.h"

namespace CodeGenerator
{
    class WatGlobalsGenerator final : public GlobalsGenerator
    {
    public:
        explicit WatGlobalsGenerator(std::string& output);
        ~WatGlobalsGenerator() override = default;

        void generate(const SymbolTable::Entry& entry) override;

    private:
        static std::string determineInitializer(const SymbolTable::Entry& entry);
    };
}

#endif //GC_WATGLOBALSGENERATOR_H