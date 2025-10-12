#ifndef TPE_SEMANTIC_ACTIONS_H
#define TPE_SEMANTIC_ACTIONS_H

/*
 * @brief son las acciones asociadas a cada regla
 * detectada.
 *
 * Su responsabilidad es ejecutar aquello que se debe hacer
 * cuando se detecta una regla.
 */
namespace SyntaxAnalyzer::SemanticActions
{
    void addNegativeFloatToTable();

    /* Traps */
    void announceSyntaxError();
    void specifySyntaxError(const int& code);
    void announceSpecificError(const int& code);

    /* Logs */
    void logStructure(const std::string& structure);
}

#endif //TPE_SEMANTIC_ACTIONS_H