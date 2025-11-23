#include "code-generator/components/wat-generation/WatCodeBlockGenerator.h"

#include <stdexcept>

#include "code-generator/components/wat-generation/WatSegmentGenerator.h"
#include "code-generator/components/wat-generation/wat_translations.h"

#define RUNTIME_E1 "\ngenerate: Code Block must be a function or program"
#define RUNTIME_E2 "\ngenerate: Operation Code Unrecognized"

namespace CodeGenerator
{
    WatCodeBlockGenerator::WatCodeBlockGenerator(std::string& output, const WatSegmentGenerator& segment) :
        CodeBlockGenerator(output),
        nesting("\t\t"),
        segment(segment) {}

    void WatCodeBlockGenerator::generate(const SymbolTable::Entry& s, const Triples& triples)
    {
        const auto& symbol = WatTranslator::translateSymbol(s.symbol);

        output.append("\t(func ")
              .append(symbol)
              .append(" ");

        if (s.use == PROGRAM)
            output.append("(export \"main\") (result i32)\n");
        else if (s.use == FUNCTION)
        {
            // Lambda is VOID and not callable
            if (s.type == UINT)
            {
                output.append("(result i32)\n");

                // Recursion Detection
                const auto id = std::to_string(++InstructionsGenerators::IF_BLOCK_ID);
                output.append(nesting)
                      .append("(block $endif_")
                      .append(id)
                      .append("\n")
                      .append(nesting)
                      .append("\tglobal.get ")
                      .append(symbol)
                      .append("\n")
                      .append(nesting)
                      .append("\tbr_if $endif_")
                      .append(id)
                      .append("\n")
                      .append(nesting)
                      .append("\ti32.const ")
                      .append(std::to_string(segment.getRecursionOffset()))
                      .append("\n")
                      .append(nesting)
                      .append("\tcall $print_str\n")
                      .append(nesting)
                      .append("\tunreachable\n")
                      .append(nesting)
                      .append(")\n")
                      .append(nesting)
                      .append("i32.const 0\n")
                      .append(nesting)
                      .append("global.set ")
                      .append(symbol);
            }
            output.append("\n");
        }
        else
            throw std::runtime_error(RUNTIME_E1);

        for (const auto& [op, tp, o1, o2] : triples)
        {
            InstructionsGenerators::Metadata m = {
                output,
                nesting,
                tp,
                o1,
                o2,
                segment,
            };
            if (auto it = mapping.find(op); it != mapping.end())
                it->second(m);
            else
                throw std::runtime_error(RUNTIME_E2);
        }
        if (s.use == PROGRAM)
            output.append(nesting)
                  .append("i32.const 0\n\t)");
        else
            output.append("\t)\n\n");
    }
}
