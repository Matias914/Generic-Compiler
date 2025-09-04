#include "lexical-analyzer/States.h"
#include "lexical-analyzer/Translator.h"
#include "lexical-analyzer/StateMachine.h"
#include "lexical-analyzer/LexicalAnalyzer.h"

FileReader GFILE = FileReader();

int LexicalAnalyzer::yylex()
{
    std::string lexeme = "";
    auto sm = StateMachine();
    // Initialization of StateMachine
    sm.finalState = false;
    sm.state = States::state0;
    // Logic
    char character;
    const bool OK = GFILE.get(character);
    while (OK || sm.finalState)
    {
        const int ivalue = Translator::translate(character);
        const SemanticAction as = sm.getSemanticAction(ivalue);
        as(lexeme, character);
    }
    // TODO: yyval.sval = lexeme; o usar directamente esa variable
    return 0;
}

void LexicalAnalyzer::setFileName(const char* filename)
{
    GFILE.set(filename);
}

