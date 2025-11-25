#ifndef GC_CODE_GENERATOR_H
#define GC_CODE_GENERATOR_H

#include "components/Triples.h"

/*
 * @brief namespace que expone las funcionalidades del generador
 * de código.
 */
namespace CodeGenerator
{
    extern Triples* INTERMEDIATE_CODE;

    void addIntermediateCodeBlock(const SymbolTable::Entry* ref);
    void notifyEndOfBlock();

    bool generateWebAssembly(const std::string& output);

    // Used for report
    std::string getIntermediateCode();

    // Util para Testing
    void clear();
    const Triples* getAssociatedTriples(const std::string& name);
}

#endif //GC_CODE_GENERATOR_H