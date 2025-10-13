#include "utils/Log.h"
#include "utils/ReportHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "lexical-analyzer/components/macros.h"
#include "lexical-analyzer/components/translator.h"
#include "lexical-analyzer/components/StateMachine.h"

extern bool VERBOSE_OPTION;
extern ReportHandler REPORT_HANDLER;

namespace LexicalAnalyzer
{
    unsigned int YYLINENO = 0;
    std::ifstream SOURCE_FILE;

    int yylex()
    {
        int token = 0;
        std::string lexeme = "";
        auto sm = StateMachine();
        while (!sm.endState())
        {
            char character;
            int  chartype;
            if (!static_cast<bool>(SOURCE_FILE.get(character)))
            {
                SOURCE_FILE.close();
                chartype = END_OF_FILE;
            }
            else
                chartype = Translator::translate(character);
            const SemanticAction SA = sm.getSemanticAction(chartype);
            token = SA(lexeme, character);
        }
        // Logs the token and lexeme found
        if (VERBOSE_OPTION)
        {
            Log log;
            log.type = TOKEN;
            log.code = token;
            log.line = YYLINENO;
            log.content = {lexeme};
            REPORT_HANDLER.add(log);
        }
        return token;
    }

    bool open(const char* filename)
    {
        SOURCE_FILE = std::ifstream(filename, std::ios::in);
        if (!SOURCE_FILE.is_open())
        {
            YYLINENO = 0;
            return false;
        }
        YYLINENO = 1;
        return true;
    }
}
