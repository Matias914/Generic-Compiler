#include "code-generator/components/wat-generation/WatTranslatator.h"

#include <algorithm>
#include <stdexcept>
#include <string>

#include "utils/SymbolTable.h"

#define RUNTIME_E1 "\ntranslateType: Float or other should be unsupported."
#define RUNTIME_E2 "\ntranslateInteger: Malformed integer constant. Expected 'UI' suffix."

namespace CodeGenerator::WatTranslator
{
    std::string translateType(const int type)
    {
        switch (type)
        {
        case UINT:
            return "i32";
        default:
            throw std::runtime_error(RUNTIME_E1);
        }
    }

    std::string translateFloat(const std::string& constant)
    {
        std::string result;
        if (constant[0] == '.')
            result = "0" + constant;
        else
            result = constant;
        std::replace(result.begin(), result.end(), 'F', 'E');
        return result;
    }

    std::string translateSymbol(const std::string& variable)
    {
        return "$" + variable;
    }

    std::string translateInteger(const std::string& constant)
    {
        if (!(constant.length() > 2 && constant.substr(constant.length() - 2) == "UI")) {
            throw std::runtime_error(RUNTIME_E2);
        }
        return constant.substr(0, constant.length() - 2);
    }
}