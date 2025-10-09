#ifndef TPE_SEMANTIC_ACTIONS_H
#define TPE_SEMANTIC_ACTIONS_H

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