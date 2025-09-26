#include "utils/Log.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "lexical-analyzer/components/macros.h"
#include "lexical-analyzer/components/translator.h"
#include "lexical-analyzer/components/StateMachine.h"
#include "utils/LogHandler.h"

extern LogHandler LOG_HANDLER;

namespace LexicalAnalyzer
{
    unsigned int YYLINENO = 1;
    std::ifstream SOURCE_FILE;

    int yylex()
    {
        char character;
        std::string lexeme = "";
        auto sm = StateMachine();
        int token = 0;
        while (!sm.endState())
        {
            int ivalue = END_OF_FILE;
            if (static_cast<bool>(SOURCE_FILE.get(character)))
                ivalue = Translator::translate(character);
            else
                SOURCE_FILE.close();
            const SemanticAction as = sm.getSemanticAction(ivalue);
            token = as(lexeme, character);
        }
        // Logs the token and lexeme found
        Log log;
        log.type = TOKEN;
        log.code = token;
        log.line = YYLINENO;
        log.content = {lexeme};
        LOG_HANDLER.add(log);
        return token;
    }

    bool open(const char* filename)
    {
        SOURCE_FILE = std::ifstream(filename, std::ios::in);
        return SOURCE_FILE.is_open();
    }
}
