#include "code-generator/components/wat-generation/wat_instruccions_builders.h"

#include <stdexcept>

#include "code-generator/components/wat-generation/wat_translations.h"

#define RUNTIME_E1 "\ngenerateOperand: constant operand cannot be other than uint or float."
#define RUNTIME_E2 "\ngenerateOperand: symbol operand cannot be other than uint."
#define RUNTIME_E3 "\ngenerateOperand: unknown operand type."

namespace CodeGenerator::InstructionsGenerators
{
    void generateOperand(std::string& mssg, const std::string& nesting, const Triples::Operand& op)
    {
        switch (op.type)
        {
        case LITERAL:
            if (op.value.lref->type == UINT)
                mssg.append(nesting)
                    .append("i32.const ")
                    .append(WatTranslator::translateInteger(op.value.lref->constant))
                    .append("\n");
            else if (op.value.lref->type == FLOAT)
                mssg.append(nesting)
                    .append("f32.const ")
                    .append(WatTranslator::translateFloat(op.value.lref->constant))
                    .append("\n");
            else
                throw std::runtime_error(RUNTIME_E1);
            break;
        case SYMBOL:
            if (op.value.sref->type == UINT)
                mssg.append(nesting)
                    .append("global.get ")
                    .append(WatTranslator::translateSymbol(op.value.sref->symbol))
                    .append("\n");
            else
                throw std::runtime_error(RUNTIME_E2);
            break;
        case TRIPLE:
            break;
        default:
            throw std::runtime_error(RUNTIME_E3);
        }
    }
}
