#include "utils/ErrorHandler.h"
#include "syntax-analyzer/Parser.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "lexical-analyzer/components/mapping.h"
#include "lexical-analyzer/components/translator.h"
#include "lexical-analyzer/components/StateMachine.h"

#include <fstream>

extern ErrorHandler ERROR_HANDLER;

namespace LexicalAnalyzer
{
    int YYLINENO = 1;
    std::ifstream SOURCE_FILE;

    int yylex()
    {
        char character;
        std::string lexeme = "";
        auto sm = StateMachine();
        LexemeData data = {0, nullptr, nullptr};
        while (!sm.endState())
        {
            int ivalue = END_OF_FILE;
            if (const bool OK = static_cast<bool>(SOURCE_FILE.get(character)))
                ivalue = Translator::translate(character);
            else
                SOURCE_FILE.close();
            const SemanticAction as = sm.getSemanticAction(ivalue);
            data = as(lexeme, character);
        }
        if (data.symbol_reference != nullptr)
            yylval.symbol_reference = data.symbol_reference;
        else if (data.constant_reference != nullptr)
            yylval.constant_reference = data.constant_reference;
        return data.token;
    }

    bool open(const char* filename)
    {
        SOURCE_FILE = std::ifstream(filename, std::ios::in);
        return SOURCE_FILE.is_open();
    }
}