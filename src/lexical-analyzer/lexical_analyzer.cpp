#include "utils/globals.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "lexical-analyzer/components/translator.h"
#include "lexical-analyzer/components/StateMachine.h"

#include <fstream>

namespace LexicalAnalyzer
{
    int YYLINENO = 0;
    std::ifstream SOURCE_FILE;

    int yylex()
    {
        char character;
        std::string lexeme = "";
        auto sm = StateMachine();
        bool OK = static_cast<bool>(SOURCE_FILE.get(character));
        if (OK)
        {
            LexemeData data;
            while (true)
            {
                const int ivalue = Translator::translate(character);
                const SemanticAction as = sm.getSemanticAction(ivalue);
                data = as(lexeme, character);
                if (sm.finalState) break;
                OK = static_cast<bool>(SOURCE_FILE.get(character));
                if (!OK)
                {
                    SOURCE_FILE.close();
                    ErrorHandler::Log l;
                    l.type = ERROR;
                    l.code = UNEXPECTED_EOF;
                    l.line = YYLINENO;
                    ERROR_HANDLER.add(l);
                    return 0;
                }
            }
            yylval = data.entry_reference;
            return data.token;
        }
        SOURCE_FILE.close();
        return 0;
    }

    void filename(const char* filename)
    {
        SOURCE_FILE = std::ifstream(filename, std::ios::in);
        if (!SOURCE_FILE.is_open()) ERROR_HANDLER.fatal();
    }
}