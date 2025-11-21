#include "code-generator/components/wat-generation/wat_instruccions_builders.h"

#define RUNTIME_E1 "\ngenerateMultiplication: unknown multiplication type."
#define RUNTIME_E2 "\ngenerateDivision: unknown division type."

#include <stdexcept>

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
        generateOperand(m.output, m.nesting, m.o2);
        switch (m.type)
        {
        case UINT:
            m.output.append(m.nesting)
                    .append("i32.const 0\n")
                    .append(m.nesting)
                    .append("i32.eq\n")
                    .append(m.nesting)
                    .append("if \n")
                    .append(m.nesting)
                    .append("\ti32.const ")
                    .append(std::to_string(m.segment.getZeroDivisionOffset()))
                    .append("\n")
                    .append(m.nesting)
                    .append("\tcall $print_str\n")
                    .append(m.nesting)
                    .append("\tunreachable\n")
                    .append(m.nesting)
                    .append("end\n");

            generateOperand(m.output, m.nesting, m.o1);
            generateOperand(m.output, m.nesting, m.o2);

            m.output.append(m.nesting)
                    .append("i32.div_u\n");
            break;
        case FLOAT:
            m.output.append(m.nesting)
                    .append("f32.const 0.0\n")
                    .append(m.nesting)
                    .append("f32.eq\n")
                    .append(m.nesting)
                    .append("if \n")
                    .append(m.nesting)
                    .append("\ti32.const ")
                    .append(std::to_string(m.segment.getZeroDivisionOffset()))
                    .append("\n")
                    .append(m.nesting)
                    .append("\tcall $print_str\n")
                    .append(m.nesting)
                    .append("\tunreachable\n")
                    .append(m.nesting)
                    .append("end\n");

            generateOperand(m.output, m.nesting, m.o1);
            generateOperand(m.output, m.nesting, m.o2);

            m.output.append(m.nesting)
                    .append("f32.div\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E2);
        }
    }
}
