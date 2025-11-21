#ifndef GC_WATSEGMENTGENERATOR_H
#define GC_WATSEGMENTGENERATOR_H

#include "utils/LiteralTable.h"
#include "code-generator/components/HeaderGenerator.h"

#include <map>

namespace CodeGenerator
{
    class WatSegmentGenerator final : public HeaderGenerator
    {
    public:
        explicit WatSegmentGenerator(std::string& output);
        ~WatSegmentGenerator() override = default;

        void generate() override;

        int getOffset(const LiteralTable::Entry* input) const;
        int getZeroDivisionOffset() const;
        int getNegativeUnsignedOffset() const;
        int getRecursionOffset() const;

    private:
        const int pageSize = 65536;
        int offset;
        std::map<const LiteralTable::Entry*, int> offsets;

        const LiteralTable::Entry* zeroDivision;
        const LiteralTable::Entry* negativeUnsigned;
        const LiteralTable::Entry* recursion;
    };
}

#endif //GC_WATSEGMENTGENERATOR_H