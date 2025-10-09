#include "syntax-analyzer/components/parser.h"
#include "syntax-analyzer/components/translator.h"

using namespace SyntaxAnalyzer;

std::string Translator::translate(const int& token) {
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
    case IF:
        return "if";
    case ELSE:
        return "else";
    case ENDIF:
        return "endif";
    case DO:
        return "do";
    case WHILE:
        return "while";
    case RETURN:
        return "return";
    case PRINT:
        return "print";
    case TRUNC:
        return "trunc";
    case UINT:
        return "uint";
    case FLOAT:
        return "float";
    case CR:
        return "cr";
    case POINTER_OP:
        return "->";
    case EQUAL_OP:
        return "==";
    case GE_OP:
        return ">=";
    case LE_OP:
        return "<=";
    case ASSIGN_OP:
        return ":=";
    case NOT_EQUAL_OP:
        return "!=";
    case IDENTIFIER:
        return yylval.sref->symbol;
    case FLOAT_LITERAL:
    case UINTEGER_LITERAL:
    case STRING_LITERAL:
        return yylval.lref->constant;
    default:
        const char c = static_cast<char>(token);
        return std::string(1, c);
    }
}