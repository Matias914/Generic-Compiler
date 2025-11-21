#ifndef GC_WATGLOBALSGENERATOR_H
#define GC_WATGLOBALSGENERATOR_H

#include "utils/SymbolTable.h"
#include "code-generator/components/HeaderGenerator.h"

namespace CodeGenerator
{
    class WatGlobalsGenerator final : public HeaderGenerator
    {
    public:
        explicit WatGlobalsGenerator(std::string& output);
        ~WatGlobalsGenerator() override = default;

        void generate() override;

    private:
        static std::string determineInitializer(const SymbolTable::Entry& entry);
    };
}

#endif //GC_WATGLOBALSGENERATOR_H