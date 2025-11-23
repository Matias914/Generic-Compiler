#include "code-generator/components/wat-generation/WatInstruccionsBuilders.h"

namespace CodeGenerator::InstructionsGenerators
{
    // Only one but could be more
    void generateFloatToInteger(const Metadata& m)
    {
        if (m.o1.type == TRIPLE)
            m.output.append(m.nesting)
                    .append("global.set $tempf1\n");

        const auto id = std::to_string(++IF_BLOCK_ID);

        // Creates If Block
        m.output.append(m.nesting)
                .append("(block $endif_")
                .append(id)
                .append("\n");
        m.nesting.append("\t");

        if (m.o1.type == TRIPLE)
            m.output.append(m.nesting)
                    .append("global.get $tempf1\n");
        else
            generateOperand(m.output, m.nesting, m.o1);

        m.output.append(m.nesting)
                .append("f32.const 0.0\n")
                .append(m.nesting)
                .append("f32.ge\n")
                .append(m.nesting)
                .append("br_if $endif_")
                .append(id)
                .append("\n")
                .append(m.nesting)
                .append("i32.const ")
                .append(std::to_string(m.segment.getNegativeUnsignedOffset()))
                .append("\n")
                .append(m.nesting)
                .append("call $print_str\n")
                .append(m.nesting)
                .append("unreachable\n");

        // Closes If Block
        m.nesting.pop_back();
        m.output.append(m.nesting)
                .append(")\n");

        if (m.o1.type == TRIPLE)
            m.output.append(m.nesting)
                    .append("global.get $tempf1\n");
        else
            generateOperand(m.output, m.nesting, m.o1);

        m.output.append(m.nesting)
                .append("i32.trunc_f32_u\n");
    }
}