#include "code-generator/components/wat-generation/WatInstruccionsBuilders.h"

#include <stdexcept>

#include "code-generator/components/wat-generation/WatTranslatator.h"

#define RUNTIME_E1 "\ngenerateAssignment: left side cannot be other than uint."
#define RUNTIME_E2 "\ngenerateAssignment: right side constant cannot be other than uint."
#define RUNTIME_E3 "\ngenerateAssignment: right side symbol cannot be other than uint."
#define RUNTIME_E4 "\ngenerateAssignment: unknown operand type."

namespace CodeGenerator::InstructionsGenerators
{
    void generateAssignment(const Metadata& m)
    {
        if (m.o1.value.sref->type != UINT)
            throw std::runtime_error(RUNTIME_E1);
        switch (m.o2.type)
        {
        case LITERAL:
            if (m.o2.value.lref->type == UINT)
                m.output.append(m.nesting)
                        .append("i32.const ")
                        .append(WatTranslator::translateInteger(m.o2.value.lref->constant))
                        .append("\n")
                        .append(m.nesting)
                        .append("global.set ")
                        .append(WatTranslator::translateSymbol(m.o1.value.sref->symbol))
                        .append("\n");
            else
                throw std::runtime_error(RUNTIME_E2);
            break;
        case SYMBOL:
            if (m.o2.value.sref->type == UINT)
                m.output.append(m.nesting)
                        .append("global.get ")
                        .append(WatTranslator::translateSymbol(m.o2.value.sref->symbol))
                        .append("\n")
                        .append(m.nesting)
                        .append("global.set ")
                        .append(WatTranslator::translateSymbol(m.o1.value.sref->symbol))
                        .append("\n");
            else
                throw std::runtime_error(RUNTIME_E3);
            break;
        case TRIPLE:
        {
            m.output.append(m.nesting)
                    .append("global.set ")
                    .append(WatTranslator::translateSymbol(m.o1.value.sref->symbol))
                    .append("\n");
            break;
        }
        default:
            throw std::runtime_error(RUNTIME_E4);
        }
    }
}
