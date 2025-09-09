#include "lexical-analyzer/Translator.h"
#include "lexical-analyzer/StateMachine.h"
#include "lexical-analyzer/ErrorHandler.h"
#include "lexical-analyzer/LexicalAnalyzer.h"


FileReader GFILE = FileReader();

int LexicalAnalyzer::yylex()
{
    char character;
    std::string lexeme = "";
    auto sm = StateMachine();
    bool OK = GFILE.get(character);
    if (OK)
    {
        int token = 0;
        while (true)
        {
            const int ivalue = Translator::translate(character);
            const SemanticAction as = sm.getSemanticAction(ivalue);
            token = as(lexeme, character);
            if (sm.finalState) break;
            OK = GFILE.get(character);
            if (!OK) ErrorHandler::throwError("End of File Unexpected");
        }
        return token;
    }
    return 0;
}

void LexicalAnalyzer::setFileName(const char* filename)
{
    GFILE.set(filename);
}

