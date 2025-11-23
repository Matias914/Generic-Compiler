#include "code-generator/components/wat-generation/WatInstruccionsBuilders.h"

#include <stdexcept>

#define RUNTIME_E1 "\ngenerateMultiplication: unknown multiplication type."
#define RUNTIME_E2 "\ngenerateDivision: unknown division type."

namespace CodeGenerator::InstructionsGenerators
{
    void generateMultiplication(const Metadata& m)
    {
        generateOperand(m.output, m.nesting, m.o1);
        generateOperand(m.output, m.nesting, m.o2);

        switch (m.type)
        {
        case UINT:
            m.output.append(m.nesting).append("i32.mul\n");
            break;
        case FLOAT:
            m.output.append(m.nesting).append("f32.mul\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E1);
        }
    }

    void generateDivision(const Metadata& m)
    {
        const auto id = std::to_string(++IF_BLOCK_ID);

        // Creates If Block
        m.output.append(m.nesting)
                .append("(block $endif_")
                .append(id)
                .append("\n");
        m.nesting.append("\t");

        switch (m.type)
        {
        case UINT:
            if (m.o2.type == TRIPLE)
                m.output.append(m.nesting)
                        .append("global.set $tempi1\n")
                        .append(m.nesting)
                        .append("global.get $tempi1\n");
            else
                generateOperand(m.output, m.nesting, m.o2);

            // Checks If Not Zero
            m.output.append(m.nesting)
                    .append("br_if $endif_")
                    .append(id)
                    .append("\n")
                    .append(m.nesting)
                    .append("i32.const ")
                    .append(std::to_string(m.segment.getZeroDivisionOffset()))
                    .append("\n")
                    .append(m.nesting)
                    .append("call $print_str\n")
                    .append(m.nesting)
                    .append("unreachable\n");

            // Closes If Block
            m.nesting.pop_back();
            m.output.append(m.nesting)
                    .append(")\n");

            generateOperand(m.output, m.nesting, m.o1);
            if (m.o2.type == TRIPLE)
                m.output.append(m.nesting).append("global.get $tempi1\n");
            else
                generateOperand(m.output, m.nesting, m.o2);

            m.output.append(m.nesting)
                    .append("i32.div_u\n");
            break;
        case FLOAT:
            if (m.o2.type == TRIPLE)
                m.output.append(m.nesting)
                        .append("global.set $tempf1\n")
                        .append(m.nesting)
                        .append("global.get $tempf1\n");
            else
                generateOperand(m.output, m.nesting, m.o2);

            // Checks If Not Zero With Floating Point
            m.output.append(m.nesting)
                    .append("f32.const 0.0\n")
                    .append(m.nesting)
                    .append("f32.ne\n")
                    .append(m.nesting)
                    .append("br_if $endif_")
                    .append(id)
                    .append("\n")
                    .append(m.nesting)
                    .append("i32.const ")
                    .append(std::to_string(m.segment.getZeroDivisionOffset()))
                    .append("\n")
                    .append(m.nesting)
                    .append("call $print_str\n")
                    .append(m.nesting)
                    .append("unreachable\n");

            // Closes If Block
            m.nesting.pop_back();
            m.output.append(m.nesting)
                    .append(")\n");

            generateOperand(m.output, m.nesting, m.o1);
            if (m.o2.type == TRIPLE)
                m.output.append(m.nesting).append("global.get $tempf1\n");
            else
                generateOperand(m.output, m.nesting, m.o2);

            m.output.append(m.nesting)
                    .append("f32.div\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E2);
        }
    }
}
