#ifndef GC_SEMANTIC_ACTIONS_H
#define GC_SEMANTIC_ACTIONS_H

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
    const LiteralTable::Entry* turnNegative(const LiteralTable::Entry* lref);

    /* Traps */
    void announceSyntaxError();
    void announceSpecificError(const int& code);
    void announceSpecificErrorWithSymbol(const int& code);
    void specifySyntaxError(const int& code);
    void specifySyntaxWarning(const int& code);

    /* Logs */
    void logStructure(const std::string& structure);
}

#endif //GC_SEMANTIC_ACTIONS_H