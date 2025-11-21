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
        if (entry.type == UINT || entry.use == FUNCTION)
            return "0";
        if (entry.type == FLOAT)
            return "0.0";
        throw std::runtime_error(RUNTIME_E1);
    }

    void WatGlobalsGenerator::generate()
    {
        // Auxiliar Variables for Checks
        output.append("\t(global $tempi1 (mut i32) (i32.const 0))\n")
              .append("\t(global $tempi2 (mut i32) (i32.const 0))\n")
              .append("\t(global $tempf1 (mut f32) (f32.const 0.0))\n")
              .append("\t(global $tempf2 (mut f32) (f32.const 0.0))\n");

        for (const auto& entry : SYMBOL_TABLE)
        {

            if (entry.use == VARIABLE || entry.use == PARAMETER || entry.use == FUNCTION)
            {
                std::string type;
                if (entry.use != FUNCTION)
                    type = WatTranslator::translateType(entry.type);
                // Because Function Variables are used to detect recursion
                else
                    type = "i32";
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
