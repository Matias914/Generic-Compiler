#ifndef TPE_SEMANTIC_ACTIONS_H
#define TPE_SEMANTIC_ACTIONS_H

namespace SyntaxAnalyzer::SemanticActions
{
    void announceSyntaxError();
    void specifySemicolonError();

    void addNegativeFloatToTable();
}

#endif //TPE_SEMANTIC_ACTIONS_H