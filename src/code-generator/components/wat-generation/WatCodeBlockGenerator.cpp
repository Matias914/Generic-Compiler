#include "code-generator/components/wat-generation/wat_translations.h"
#include "code-generator/components/wat-generation/WatSegmentGenerator.h"
#include "code-generator/components/wat-generation/WatCodeBlockGenerator.h"

#include <stdexcept>

#define RUNTIME_E1 "\ngenerate: Code Block must be a function or program"

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
            // Recursion Detection
            output.append("\n")
                  .append(nesting)
                  .append("global.get ")
                  .append(symbol)
                  .append("\n")
                  .append(nesting)
                  .append("if\n")
                  .append(nesting)
                  .append("\ti32.const ")
                  .append(std::to_string(segment.getRecursionOffset()))
                  .append("\n")
                  .append(nesting)
                  .append("\tcall $print_str\n")
                  .append(nesting)
                  .append("\tunreachable\n")
                  .append(nesting)
                  .append("end\n")
                  .append(nesting)
                  .append("i32.const 1\n")
                  .append(nesting)
                  .append("global.set ")
                  .append(symbol)
                  .append("\n");
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
            if (op != CODEOP_FTOI && op != CODEOP_CALL && op != CODEOP_RET)
                mapping[op](m);
        }
        if (s.use == PROGRAM)
            output.append(nesting)
                  .append("i32.const 0\n\t)");
        else
            output.append(nesting)
                  .append("i32.const 0\n")
                  .append(nesting)
                  .append("global.set ")
                  .append(symbol)
                  .append("\n\t)\n\n");
    }
}
