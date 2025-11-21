#include "utils/LiteralTable.h"
#include "code-generator/components/wat-generation/WatSegmentGenerator.h"

extern LiteralTable LITERAL_TABLE;

#define ERROR_MSG(X) "\"\\n\\n[[ RUNTIME ERROR ]]: " X ".\\n\""

namespace CodeGenerator
{
    WatSegmentGenerator::WatSegmentGenerator(std::string& output) : HeaderGenerator(output)
    {
        offset = 0;
        zeroDivision = LITERAL_TABLE.addAndGet (
            ERROR_MSG("zero division was found"),
            STRING,
            { .i = 0}
        );
        negativeUnsigned = LITERAL_TABLE.addAndGet (
            ERROR_MSG("unsigned integer underflow was found"),
            STRING,
            { .i = 0}
        );
        recursion = LITERAL_TABLE.addAndGet (
            ERROR_MSG("recursive call was found"),
            STRING,
            { .i = 0}
        );
    }

    void WatSegmentGenerator::generate()
    {
        // Generates Export Sentence
        output.append("\t(memory (export \"memory\") ");
        output.append( std::to_string (
        (LITERAL_TABLE.getStringCount() + LITERAL_TABLE.getCharactersCount()) / pageSize + 1
        )).append(")\n");

        // Creates Segment and Associates Offsets
        for (const auto& entry : LITERAL_TABLE)
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
    }

    int WatSegmentGenerator::getOffset(const LiteralTable::Entry* input) const
    {
        return offsets.at(input);
    }

    int WatSegmentGenerator::getZeroDivisionOffset() const
    {
        return offsets.at(zeroDivision);
    }

    int WatSegmentGenerator::getNegativeUnsignedOffset() const
    {
        return offsets.at(negativeUnsigned);
    }

    int WatSegmentGenerator::getRecursionOffset() const
    {
        return offsets.at(recursion);
    }
}
