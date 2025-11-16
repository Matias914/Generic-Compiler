#ifndef GC_CODE_GENERATOR_H
#define GC_CODE_GENERATOR_H

#include "components/Triples.h"

namespace CodeGenerator
{
    extern Triples* INTERMEDIATE_CODE;

    void addIntermediateCodeBlock(const std::string& name);
    void notifyEndOfBlock();

    std::string getIntermediateCode();

}

#endif //GC_CODE_GENERATOR_H