#ifndef GC_SEGMENTGENERATOR_H
#define GC_SEGMENTGENERATOR_H

#include "utils/LiteralTable.h"

namespace CodeGenerator
{
    class SegmentGenerator
    {
    public:
        explicit SegmentGenerator(std::string& output) : output(output) {};

        virtual void generate(const LiteralTable::Entry& entry) = 0;
        virtual ~SegmentGenerator() = default;
    protected:
        std::string& output;
    };
}

#endif //GC_SEGMENTGENERATOR_H