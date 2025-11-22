#ifndef GC_CODE_GENERATOR_H
#define GC_CODE_GENERATOR_H

#include "components/Triples.h"

namespace CodeGenerator
{
    extern Triples* INTERMEDIATE_CODE;

    void addIntermediateCodeBlock(const SymbolTable::Entry* ref);
    void notifyEndOfBlock();

    std::string getIntermediateCode();

    bool generateWebAssembly(const std::string& output);
}

#endif //GC_CODE_GENERATOR_H