#include "code-generator/components/wat-generation/wat_instruccions_builders.h"

#include <stdexcept>

#define RUNTIME_E1 "\ngenerateAddition: unknown addition type."
#define RUNTIME_E2 "\ngenerateSubstraction: unknown substraction type."

namespace CodeGenerator::InstructionsGenerators
{
    void generateAddition(const Metadata& m)
    {
        generateOperand(m.output, m.nesting, m.o1);
        generateOperand(m.output, m.nesting, m.o2);

        switch (m.type)
        {
        case UINT:
            m.output.append(m.nesting).append("i32.add\n");
            break;
        case FLOAT:
            m.output.append(m.nesting).append("f32.add\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E1);
        }
    }

    void generateSubstraction(const Metadata& m)
    {
        switch (m.type)
        {
        case UINT:
            // Se escribe 1er. variable auxiliar
            if (m.o2.type == TRIPLE)
                m.output.append(m.nesting)
                        .append("global.set $tempi2\n");

            // Se escribe 2da. variable auxiliar
            if (m.o1.type == TRIPLE)
                m.output.append(m.nesting)
                        .append("global.set $tempi1\n");

            // Ahora se obtienen valores, cosa de guardar en un registro temporal
            // lo que se trajo de otro.
            if (m.o1.type == TRIPLE)
                m.output.append(m.nesting)
                        .append("global.get $tempi1\n");
            else
                generateOperand(m.output, m.nesting, m.o1);

            if (m.o2.type == TRIPLE)
                m.output.append(m.nesting)
                        .append("global.get $tempi2\n");
            else
                generateOperand(m.output, m.nesting, m.o2);

            m.output.append(m.nesting)
                    .append("i32.lt_u\n")
                    .append(m.nesting)
                    .append("if \n")
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
                m.output.append(m.nesting).append("global.get $tempi1\n");
            else
                generateOperand(m.output, m.nesting, m.o1);

            if (m.o2.type == TRIPLE)
                m.output.append(m.nesting).append("global.get $tempi2\n");
            else
                generateOperand(m.output, m.nesting, m.o2);

            m.output.append(m.nesting)
                    .append("i32.sub\n");
            break;
        case FLOAT:
            generateOperand(m.output, m.nesting, m.o1);
            generateOperand(m.output, m.nesting, m.o2);

            m.output.append(m.nesting)
                    .append("f32.sub\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E2);
        }
    }
}
