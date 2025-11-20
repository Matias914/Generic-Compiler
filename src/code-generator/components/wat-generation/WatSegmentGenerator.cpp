#include "code-generator/components/wat-generation/WatSegmentGenerator.h"

namespace CodeGenerator
{
    WatSegmentGenerator::WatSegmentGenerator(std::string& output) : SegmentGenerator(output), offset(0) {}

    void WatSegmentGenerator::generate(const LiteralTable::Entry& entry)
    {
        if (entry.type == STRING)
        {
            const auto size = entry.constant.size() - 1;
            offsets.emplace(&entry, offset);
            output.append("\t(data (i32.const ")
                  .append(std::to_string(offset))
                  .append(") ")
                  .append(entry.constant.substr(0, size))
                  .append("\\00\")\n");
            offset += size;
        }
    }

    std::map<const LiteralTable::Entry*, int> WatSegmentGenerator::getOffsets()
    {
        return std::move(offsets);
    }
}
