#include "code-generator/components/wat-generation/wat_instruccions_builders.h"

#include <stdexcept>

#include "code-generator/components/wat-generation/wat_translations.h"

#define RUNTIME_E1 "\ngenerateCall: invalid function."

namespace CodeGenerator::InstructionsGenerators
{
    void generateCall(const Metadata& m)
    {
        if (m.o1.type != SYMBOL)
            throw std::runtime_error(RUNTIME_E1);

        const auto& symbol = WatTranslator::translateSymbol(m.o1.value.sref->symbol);
        m.output.append(m.nesting)
            .append("call ")
            .append(symbol)
            .append("\n")
            .append(m.nesting)
            .append("i32.const 0\n")
            .append(m.nesting)
            .append("global.set ")
            .append(symbol)
            .append("\n");
    }

    void generateReturn(const Metadata& m)
    {
        // Lambda is VOID and doesn't have operands
        if (m.o1.type != UNKNOWN)
        {
            generateOperand(m.output, m.nesting, m.o1);
        }
        m.output.append(m.nesting)
                .append("return\n");

    }
}
