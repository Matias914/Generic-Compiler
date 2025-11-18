#ifndef GC_SEMANTIC_ACTIONS_H
#define GC_SEMANTIC_ACTIONS_H

#include "utils/ErrorBuffer.h"
#include "utils/LiteralTable.h"

/*
 * @brief son las acciones asociadas a cada regla
 * detectada.
 *
 * Su responsabilidad es ejecutar aquello que se debe hacer
 * cuando se detecta una regla.
 */
namespace SyntaxAnalyzer::SemanticActions
{
    extern ErrorBuffer BUFFER;

    const LiteralTable::Entry* turnNegative(const LiteralTable::Entry* lref);

    /* Traps */
    void announceSyntaxError();
    void announceSpecificError(int code);
    void announceSpecificErrorWithSymbol(int code);
    void announceSpecificWarning(int code);
    void specifySyntaxError(int code);
    void specifySyntaxWarning(int code);

    /* Logs */
    void logStructure(const std::string& structure);
}

#endif //GC_SEMANTIC_ACTIONS_H