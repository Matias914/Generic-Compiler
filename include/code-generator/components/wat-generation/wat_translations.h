#ifndef GC_WAT_TRANSLATOR_H
#define GC_WAT_TRANSLATOR_H

#include <string>

namespace CodeGenerator::WatTranslator
{
    std::string translateType(int type);

    std::string translateFloat(const std::string& constant);
    std::string translateSymbol(const std::string& variable);
    std::string translateInteger(const std::string& constant);
}

#endif //GC_WAT_TRANSLATOR_H