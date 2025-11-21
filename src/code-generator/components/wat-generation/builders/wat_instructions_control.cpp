#include "code-generator/components/wat-generation/wat_instruccions_builders.h"

#define WHILE_BLOCK_NAME "$do_while_block_"

#include <stack>
#include <stdexcept>

#define RUNTIME_E1 "\ngenerateBranchTrue: the stack was empty or there wasn't a triple ref."
#define RUNTIME_E2 "\ngenerateBranchTrue: the stack should have had a while ID."
#define RUNTIME_E3 "\ngenerateBranchTrue: a triple reference must be an integer."

namespace CodeGenerator::InstructionsGenerators
{
    static int WHILE_BLOCK_ID = 0;
    static auto CONTEXT = std::stack<int>();

    void generateBranchTrue(const Metadata& m)
    {
        // Si es NULL es porque se trata del BT de un IF
        if (m.o2.type == NULLREF)
            if (!CONTEXT.empty() && m.o1.type == TRIPLE)
            {
                // Si el branch de la rama True tiene el distinto destino que
                // el de la rama False, hay else
                if (CONTEXT.top() != m.o1.value.tref)
                {
                    m.nesting.pop_back();
                    m.output.append(m.nesting)
                            .append("else");
                    m.nesting.append("\t");
                }
            }
            else
                throw std::runtime_error(RUNTIME_E1);

        // Sino se trata del Branch True de un Do-While
        else if (!CONTEXT.empty())
        {
            m.output.append(m.nesting)
                    .append("br_if ")
                    .append(WHILE_BLOCK_NAME)
                    .append(std::to_string(CONTEXT.top()))
                    .append("\n");
            m.nesting.pop_back();
            m.output.append(m.nesting).append(")\n");
        }
        else
            throw std::runtime_error(RUNTIME_E2);

        CONTEXT.pop();
    }

    void generateBranchFalse(const Metadata& m)
    {
        if (m.o2.type != TRIPLE)
            throw std::runtime_error(RUNTIME_E3);

        // Se empuja la dirección de salto para el Branch True
        CONTEXT.push(m.o2.value.tref);
        m.output.append(m.nesting)
                .append("if\n");
        m.nesting.append("\t");
    }

    void generateEndif(const Metadata& m)
    {
        m.nesting.pop_back();
        m.output.append(m.nesting)
                .append("end\n");
    }

    void generateDoWhile(const Metadata& m)
    {
        m.output.append(m.nesting)
                .append("(loop ")
                .append(WHILE_BLOCK_NAME)
                .append(std::to_string(++WHILE_BLOCK_ID))
                .append("\n");
        m.nesting.append("\t");

        // Para el Branch True conozca el nombre
        CONTEXT.push(WHILE_BLOCK_ID);
    }
}
