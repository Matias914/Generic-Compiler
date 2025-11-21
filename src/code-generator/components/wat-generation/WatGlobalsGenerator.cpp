#include "code-generator/components/wat-generation/wat_translations.h"
#include "code-generator/components/wat-generation/WatGlobalsGenerator.h"

#include <stdexcept>

#define RUNTIME_E1 "\ndetermineInitilizer: Couldn't find an initializer."

extern SymbolTable SYMBOL_TABLE;

namespace CodeGenerator
{
    WatGlobalsGenerator::WatGlobalsGenerator(std::string& output) : HeaderGenerator(output) {}

    std::string WatGlobalsGenerator::determineInitializer(const SymbolTable::Entry& entry)
    {
        if (entry.type == UINT)
            return "0";
        if (entry.type == FLOAT)
            return "0.0";
        throw std::runtime_error(RUNTIME_E1);
    }

    void WatGlobalsGenerator::generate()
    {
        for (const auto& entry : SYMBOL_TABLE)
        {
            if (entry.use == VARIABLE || entry.use == PARAMETER || entry.use == FUNCTION)
            {
                const std::string type = WatTranslator::translateType(entry.type);
                output.append("\t(global ")
                      .append(WatTranslator::translateSymbol(entry.symbol))
                      .append(" (mut ")
                      .append(type)
                      .append(") (")
                      .append(type)
                      .append(".const ")
                      .append(determineInitializer(entry))
                      .append("))\n");
            }
        }
    }
}
