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
    bool OK = GFILE.get(character);
    if (OK)
    {
        int token = 0;
        while (!sm.finalState)
        {
            if (!OK)
                throw std::runtime_error("End of File Unexpected");
            const int ivalue = Translator::translate(character);
            const SemanticAction as = sm.getSemanticAction(ivalue);
            token = as(lexeme, character);
            OK = GFILE.get(character);
        }
        return token;
    }
    return 0;
}

void LexicalAnalyzer::setFileName(const char* filename)
{
    GFILE.set(filename);
}

