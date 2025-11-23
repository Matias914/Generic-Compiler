#include "code-generator/components/wat-generation/wat_instruccions_builders.h"

#include <stack>
#include <stdexcept>

#define WHILE_BLOCK_NAME "$do_while_block_"

#define RUNTIME_E1 "\ngenerateBranchTrue: the stack was empty or there wasn't a triple ref."
#define RUNTIME_E2 "\ngenerateBranchTrue: the stack should have had a while ID."
#define RUNTIME_E3 "\ngenerateIf: a triple reference must be an integer."

namespace CodeGenerator::InstructionsGenerators
{
    int IF_BLOCK_ID = 0;

    static int WHILE_BLOCK_ID = 0;
    static auto CONTEXT = std::stack<int>();

    void generateBranchTrue(const Metadata& m)
    {
        // Si es NULL es porque se trata del BT de un IF
        if (m.o2.type == NULLREF)
            if (!CONTEXT.empty() && m.o1.type == TRIPLE)
            {
                m.output.append(m.nesting)
                        .append("br $endif_")
                        .append(std::to_string(CONTEXT.top()))
                        .append("\n");
                m.nesting.pop_back();
                m.output.append(m.nesting)
                        .append(")\n");
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
        m.output.append(m.nesting)
                .append("i32.eqz\n")
                .append(m.nesting)
                .append("br_if $dummy_else_")
                .append(std::to_string(CONTEXT.top()))
                .append("\n");
    }

    void generateIf(const Metadata& m)
    {
        const auto id = std::to_string(++IF_BLOCK_ID);
        m.output.append(m.nesting)
                .append("(block $endif_")
                .append(id)
                .append("\n");
        m.nesting.append("\t");
        m.output.append(m.nesting)
                .append("(block $dummy_else_")
                .append(id)
                .append("\n");
        m.nesting.append("\t");

        // Para que el Branch True/False conozca el nombre
        CONTEXT.push(IF_BLOCK_ID);
    }

    void generateEndif(const Metadata& m)
    {
        m.nesting.pop_back();
        m.output.append(m.nesting)
                .append(")\n");
    }

    void generateDoWhile(const Metadata& m)
    {
        m.output.append(m.nesting)
                .append("(loop ")
                .append(WHILE_BLOCK_NAME)
                .append(std::to_string(++WHILE_BLOCK_ID))
                .append("\n");
        m.nesting.append("\t");

        // Para que el Branch True conozca el nombre
        CONTEXT.push(WHILE_BLOCK_ID);
    }
}
