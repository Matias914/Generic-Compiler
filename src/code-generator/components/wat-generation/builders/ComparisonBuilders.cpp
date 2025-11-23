#include "code-generator/components/wat-generation/WatInstruccionsBuilders.h"

#include <stdexcept>

#define RUNTIME_E1 "\ngenerateEquals: unknown == type."
#define RUNTIME_E2 "\ngenerateNotEquals: unknown =! type."
#define RUNTIME_E3 "\ngenerateGreaterOrEquals: >= type."
#define RUNTIME_E4 "\ngenerateLessOrEquals: unknown <= type."
#define RUNTIME_E5 "\ngenerateGreaterThan: unknown > type."
#define RUNTIME_E6 "\ngenerateLessThan: unknown < type."

namespace CodeGenerator::InstructionsGenerators
{
    void generateEquals(const Metadata& m)
    {
        generateOperand(m.output, m.nesting, m.o1);
        generateOperand(m.output, m.nesting, m.o2);

        switch (m.type)
        {
        case UINT:
            m.output.append(m.nesting)
                    .append("i32.eq\n");
            break;
        case FLOAT:
            m.output.append(m.nesting)
                    .append("f32.eq\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E1);
        }
    }

    void generateNotEquals(const Metadata& m)
    {
        generateOperand(m.output, m.nesting, m.o1);
        generateOperand(m.output, m.nesting, m.o2);

        switch (m.type)
        {
        case UINT:
            m.output.append(m.nesting)
                    .append("i32.ne\n");
            break;
        case FLOAT:
            m.output.append(m.nesting)
                    .append("f32.ne\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E2);
        }
    }

    void generateGreaterOrEqual(const Metadata& m)
    {
        generateOperand(m.output, m.nesting, m.o1);
        generateOperand(m.output, m.nesting, m.o2);

        switch (m.type)
        {
        case UINT:
            m.output.append(m.nesting)
             .append("i32.ge_u\n");
            break;
        case FLOAT:
            m.output.append(m.nesting)
             .append("f32.ge\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E3);
        }
    }

    void generateLessOrEqual(const Metadata& m)
    {
        generateOperand(m.output, m.nesting, m.o1);
        generateOperand(m.output, m.nesting, m.o2);

        switch (m.type)
        {
        case UINT:
            m.output.append(m.nesting)
             .append("i32.le_u\n");
            break;
        case FLOAT:
            m.output.append(m.nesting)
             .append("f32.le\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E4);
        }
    }

    void generateGreaterThan(const Metadata& m)
    {
        generateOperand(m.output, m.nesting, m.o1);
        generateOperand(m.output, m.nesting, m.o2);

        switch (m.type)
        {
        case UINT:
            m.output.append(m.nesting)
                    .append("i32.gt_u\n");
            break;
        case FLOAT:
            m.output.append(m.nesting)
                    .append("f32.gt\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E5);
        }
    }

    void generateLessThan(const Metadata& m)
    {
        generateOperand(m.output, m.nesting, m.o1);
        generateOperand(m.output, m.nesting, m.o2);

        switch (m.type)
        {
        case UINT:
            m.output.append(m.nesting)
             .append("i32.lt_u\n");
            break;
        case FLOAT:
            m.output.append(m.nesting)
             .append("f32.lt\n");
            break;
        default:
            throw std::runtime_error(RUNTIME_E6);
        }
    }
}