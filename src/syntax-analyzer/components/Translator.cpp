#include "syntax-analyzer/components/Translator.h"

#include "syntax-analyzer/components/Parser.h"

using namespace SyntaxAnalyzer;

std::string Translator::translate(const int token) {
    switch (token)
    {
    case YYEMPTY:
        return "";
    case YYEOF:
        return "End of File";
    case YYerror:
        return "ERROR";
    case YYUNDEF:
        return "Unknown Token";
    case INVALID_TOKEN:
        return "Unknown Word";
    case INVALID_RWORD:
        return "Unknown Reserved Word";
    case WORD_IF:
        return "if";
    case WORD_ELSE:
        return "else";
    case WORD_ENDIF:
        return "endif";
    case WORD_DO:
        return "do";
    case WORD_WHILE:
        return "while";
    case WORD_RETURN:
        return "return";
    case WORD_PRINT:
        return "print";
    case WORD_TRUNC:
        return "trunc";
    case WORD_UINT:
        return "uint";
    case WORD_FLOAT:
        return "float";
    case WORD_CR:
        return "cr";
    case OP_POINTER:
        return "->";
    case OP_EQUAL:
        return "==";
    case OP_GE:
        return ">=";
    case OP_LE:
        return "<=";
    case OP_ASSIGN:
        return ":=";
    case OP_NOT_EQUAL:
        return "!=";
    case IDENTIFIER:
        return yylval.sref->symbol;
    case LITERAL_FLOAT:
    case LITERAL_UINT:
    case LITERAL_STRING:
        return yylval.lref->constant;
    default:
        const char c = static_cast<char>(token);
        return std::string(1, c);
    }
}