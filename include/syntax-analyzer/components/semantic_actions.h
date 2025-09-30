#ifndef TPE_SEMANTIC_ACTIONS_H
#define TPE_SEMANTIC_ACTIONS_H

namespace SyntaxAnalyzer::SemanticActions
{
    void addNegativeFloatToTable();

    /* Traps */
    void announceSyntaxError();
    void specifyExpectedError(const std::string& expected);

    /* Logs */
    void logStructure(const std::string& structure);
}

#endif //TPE_SEMANTIC_ACTIONS_H