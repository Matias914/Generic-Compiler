#ifndef GC_WATSEGMENTGENERATOR_H
#define GC_WATSEGMENTGENERATOR_H

#include "../SegmentGenerator.h"

#include <map>

namespace CodeGenerator
{
    class WatSegmentGenerator final : public SegmentGenerator
    {
    public:
        explicit WatSegmentGenerator(std::string& output);
        ~WatSegmentGenerator() override = default;

        void generate(const LiteralTable::Entry& entry) override;

        std::map<const LiteralTable::Entry*, int> getOffsets();

    private:
        int offset;
        std::map<const LiteralTable::Entry*, int> offsets;
    };
}

#endif //GC_WATSEGMENTGENERATOR_H