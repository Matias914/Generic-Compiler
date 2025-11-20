#include "utils/ErrorHandler.h"
#include "utils/resources/codes.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/parser.h"
#include "syntax-analyzer/components/translator.h"
#include "syntax-analyzer/components/semantic_actions.h"

#define RUNTIME_E1 "\nannounceSpecificErrorWithSymbol: No log was buffered"
#define RUNTIME_E2 "\nspecifySyntaxError: No log was buffered"
#define RUNTIME_E3 "\nspecifySyntaxWarning: No log was buffered"

// Usada por Bison, guarda el token obtenido del lexico.
extern int yychar;

extern ErrorHandler ERROR_HANDLER;

namespace SyntaxAnalyzer::SemanticActions
{
    ErrorBuffer BUFFER(&ERROR_HANDLER);

    void announceSyntaxError()
    {
        BUFFER.commit();
        const Log l(ERROR, SYNTAX_ERROR, LexicalAnalyzer::YYLINENO, {Translator::translate(yychar)});
        BUFFER.buffer(l);
    }

    void announceSpecificError(const int code)
    {
        const Log l(ERROR, code, LexicalAnalyzer::YYLINENO, {Translator::translate(yychar)});
        ERROR_HANDLER.add(l);
    }

    void announceSpecificWarning(const int code)
    {
        const Log l(WARNING, code, LexicalAnalyzer::YYLINENO, {Translator::translate(yychar)});
        ERROR_HANDLER.add(l);
    }

    void announceSpecificErrorWithSymbol(const int code)
    {
        if (yylval.sref == nullptr)
            throw std::runtime_error (RUNTIME_E1);
        const Log l(ERROR, code, LexicalAnalyzer::YYLINENO, {yylval.sref->symbol});
        ERROR_HANDLER.add(l);
    }

    void specifySyntaxError(const int code)
    {
        const auto ptr = BUFFER.get();
        if (ptr == nullptr)
            throw std::runtime_error(RUNTIME_E2);
        ptr->code = code;
        BUFFER.commit();
    }

    void specifySyntaxWarning(const int code)
    {
        const auto ptr = BUFFER.get();
        if (ptr == nullptr)
            throw std::runtime_error(RUNTIME_E3);
        ptr->type = WARNING;
        ptr->code = code;
        BUFFER.commit();
    }
}