#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/syntax_analyzer.h"
#include "syntax-analyzer/components/parser.h"
#include "syntax-analyzer/components/translator.h"
#include "syntax-analyzer/components/semantic_actions.h"

// Usada por Bison, guarda el token obtenido del lexico.
extern int yychar;

extern ErrorHandler ERROR_HANDLER;

using namespace SyntaxAnalyzer;

void SemanticActions::announceSyntaxError()
{
    BUFFER.commit();
    Log l;
    l.type = ERROR;
    l.code = SYNTAX_ERROR;
    l.line = LexicalAnalyzer::YYLINENO;
    l.content = {Translator::translate(yychar)};
    BUFFER.buffer(l);
}

void SemanticActions::announceSpecificError(const int& code)
{
    Log l;
    l.type = ERROR;
    l.code = code;
    l.line = LexicalAnalyzer::YYLINENO;
    l.content = {Translator::translate(yychar)};
    ERROR_HANDLER.add(l);
}

void SemanticActions::announceSpecificErrorWithSymbol(const int& code)
{
    Log l;
    l.type = ERROR;
    l.code = code;
    l.line = LexicalAnalyzer::YYLINENO;
    if (yylval.sref == nullptr)
        throw std::runtime_error (
            "\nannounceSpecificErrorWithSymbol: No log was buffered"
        );
    l.content = {yylval.sref->symbol};
    ERROR_HANDLER.add(l);
}

void SemanticActions::specifySyntaxError(const int& code)
{
    const auto ptr = BUFFER.get();
    if (ptr == nullptr)
        throw std::runtime_error(
            "\nspecifySyntaxError: No log was buffered"
        );
    ptr->code = code;
    BUFFER.commit();
}

void SemanticActions::specifySyntaxWarning(const int& code)
{
    const auto ptr = BUFFER.get();
    if (ptr == nullptr)
        throw std::runtime_error(
            "\nspecifySyntaxWarning: No log was buffered"
        );
    ptr->type = WARNING;
    ptr->code = code;
    BUFFER.commit();
}