#include "code-generator/components/wat-generation/wat_instruccions_builders.h"

namespace CodeGenerator::InstructionsGenerators
{
    // Only one but could be more
    void generateFloatToInteger(const Metadata& m)
    {
        if (m.o1.type == TRIPLE)
            m.output.append(m.nesting)
                    .append("global.set $tempf1\n")
                    .append(m.nesting)
                    .append("global.get $tempf1\n");
        else
            generateOperand(m.output, m.nesting, m.o1);

        m.output.append(m.nesting)
                .append("f32.const 0.0\n")
                .append(m.nesting)
                .append("f32.lt\n")
                .append(m.nesting)
                .append("if\n")
                .append(m.nesting)
                .append("\ti32.const ")
                .append(std::to_string(m.segment.getNegativeUnsignedOffset()))
                .append("\n")
                .append(m.nesting)
                .append("\tcall $print_str\n")
                .append(m.nesting)
                .append("\tunreachable\n")
                .append(m.nesting)
                .append("end\n");

        if (m.o1.type == TRIPLE)
            m.output.append(m.nesting)
                    .append("global.get $tempf1\n");
        else
            generateOperand(m.output, m.nesting, m.o1);

        m.output.append(m.nesting)
                .append("i32.trunc_f32_u\n");
    }
}