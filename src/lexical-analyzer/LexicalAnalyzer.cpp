#include "lexical-analyzer/LexicalAnalyzer.h"
#include "lexical-analyzer/state-machine/States.h"
#include "lexical-analyzer/translator/Translator.h"
#include "lexical-analyzer/state-machine/StateMachine.h"

int LexicalAnalyzer::yylex()
{
    std::string lexeme = "";
    auto sm = StateMachine();
    // Initialization
    sm.finalState = false;
    sm.state = State::state0;
    // Logic
    char character;
    const bool OK = GFILE.get(character);
    while (OK || sm.finalState)
    {
        int ivalue = Translator::translate(character);
        // auto as = sm.getSemanticAction(ivalue);
        // free(as);
        throw std::runtime_error("Lexical analyzer");
        // as.do(character, lexeme);
    }
    // yyval.sval = lexeme; o usar directamente esa variable
    return 0;
}
