#include "code-generator/components/wat-generation/wat_translations.h"
#include "code-generator/components/wat-generation/WatSegmentGenerator.h"
#include "code-generator/components/wat-generation/WatCodeBlockGenerator.h"

#include <stdexcept>

#define RUNTIME_E1 "\ngenerate: Code Block must be a function or program"

namespace CodeGenerator
{
    WatCodeBlockGenerator::WatCodeBlockGenerator(std::string& output, std::map<const LiteralTable::Entry*, int> offsets) :
        CodeBlockGenerator(output),
        nesting("\t\t"),
        offsets(std::move(offsets)) {}

    void WatCodeBlockGenerator::generate(const SymbolTable::Entry& s, const Triples& triples)
    {
        output.append("\t(func ")
              .append(WatTranslator::translateSymbol(s.symbol))
              .append(" ");
        if (s.use == PROGRAM)
            output.append("(export \"main\") (result i32)");
        else if (s.use != FUNCTION)
            throw std::runtime_error(RUNTIME_E1);

        output.append("\n");

        for (const auto& [op, tp, o1, o2] : triples)
        {
            InstructionsGenerators::Metadata m = {
                output,
                nesting,
                tp,
                o1,
                o2,
                offsets,
            };
            if (op == CODEOP_PRINT)
                mapping[op](m);
        }
        output.append("\t\ti32.const 0\n\t)");
    }
}
