#include "code-generator/components/wat-generation/WatInstruccionsBuilders.h"

#include <stdexcept>

#include "code-generator/components/wat-generation/WatTranslatator.h"

#define RUNTIME_E1 "\ngeneratePrint: unknow constant type."
#define RUNTIME_E2 "\ngeneratePrint: variable type cant be other than uint."
#define RUNTIME_E3 "\ngeneratePrint: an expression cannot have other type than uint or float."
#define RUNTIME_E4 "\ngeneratePrint: unknown operand type."

namespace CodeGenerator::InstructionsGenerators
{
    void generatePrint(const Metadata& m)
    {
        switch (m.o1.type)
        {
        case LITERAL:
            if (m.o1.value.lref->type == STRING)
                m.output.append(m.nesting)
                      .append("i32.const ")
                      .append(std::to_string(m.segment.getOffset(m.o1.value.lref)))
                      .append("\n")
                      .append(m.nesting)
                      .append("call $print_str\n");
            else if (m.o1.value.lref->type == UINT)
                m.output.append(m.nesting)
                      .append("i32.const ")
                      .append(WatTranslator::translateInteger(m.o1.value.lref->constant))
                      .append("\n")
                      .append(m.nesting)
                      .append("call $print_i32\n");
            else if (m.o1.value.lref->type == FLOAT)
                m.output.append(m.nesting)
                      .append("f32.const ")
                      .append(WatTranslator::translateFloat(m.o1.value.lref->constant))
                      .append("\n")
                      .append(m.nesting)
                      .append("call $print_f32\n");
            else
                throw std::runtime_error(RUNTIME_E1);
            break;
        case SYMBOL:
            if (m.o1.value.sref->type == UINT)
                m.output.append(m.nesting)
                      .append("global.get ")
                      .append(WatTranslator::translateSymbol(m.o1.value.sref->symbol))
                      .append("\n")
                      .append(m.nesting)
                      .append("call $print_i32\n");
            else
                throw std::runtime_error(RUNTIME_E2);
            break;
        case TRIPLE:
        {
            m.output.append(m.nesting);
            if (m.type == UINT)
                m.output.append("call $print_i32\n");
            else if (m.type == FLOAT)
                m.output.append("call $print_f32\n");
            else
                throw std::runtime_error(RUNTIME_E3);
            break;
        }
        default:
            throw std::runtime_error(RUNTIME_E4);
        }
    }
}
