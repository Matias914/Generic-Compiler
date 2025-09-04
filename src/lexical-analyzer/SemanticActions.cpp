#include "syntax-analyzer/Parser.h"
#include "tables/ReservedWordsTable.h"
#include "lexical-analyzer/SemanticActions.h"
#include "lexical-analyzer/LexicalAnalyzer.h"

#include "tables/SymbolTable.h"

extern FileReader GFILE;
extern SymbolTable SYMBOL_TABLE;

/*
 * @brief se utiliza para lanzar errores con número de línea.
 */
void lanzarError(const std::string& suffix)
{
    const std::string prefix = "ERROR. Line " + std::to_string(GFILE.yylineno) + ": ";
    throw std::runtime_error(prefix + suffix + ".");
}

/* ------------------------- SEMANTIC ACTIONS ------------------------- */

int  SemanticActions::SA1(std::string& lexeme, const char& character)
{
    lexeme.clear();
    lexeme.reserve(32);
    lexeme += character;
    return -1;
}

int  SemanticActions::SA2(std::string& lexeme, const char& character)
{
    lexeme += character;
    return -1;
}

int  SemanticActions::SA3(std::string& lexeme, const char& character)
{
    if (character != 'U')
        lanzarError(lexeme + "the uint constant suffix is defined as UI");
    lexeme += character;
    return -1;
}

int  SemanticActions::SA4(std::string& lexeme, const char& character)
{
    if (character != 'I')
        lanzarError(lexeme + "the uint constant suffix is defined as UI");
    lexeme += character;
    // TODO: si el lexema solo puede ser uint, no comparar con cero.
    const int value = stoi(lexeme.substr(0, lexeme.size() - 2));
    if (value < 0 || value > 65535)
        lanzarError(lexeme + "the constant is out of range [0-65535]");
    return INTEGER_LITERAL;
}

int  SemanticActions::SA5(std::string& lexeme, const char& character)
{

    return -1;
}

int  SemanticActions::SA6(std::string& lexeme, const char& character)
{

    return -1;
}

int  SemanticActions::SA7(std::string& lexeme, const char& character)
{

    return -1;
}

int  SemanticActions::SA8(std::string& lexeme, const char& character)
{

    return -1;
}

// TODO: preguntar por el tema de la insercion de espacio
int  SemanticActions::SA9(std::string& lexeme, const char& character)
{

    return -1;
}

int SemanticActions::SA10(std::string& lexeme, const char& character)
{

    return -1;
}

int SemanticActions::SA11(std::string& lexeme, const char& character)
{

    return -1;
}

int SemanticActions::SA12(std::string& lexeme, const char& character)
{

    return -1;
}

int SemanticActions::SA13(std::string& lexeme, const char& character)
{

    return -1;
}

int SemanticActions::SA14(std::string& lexeme, const char& character)
{

    return -1;
}

int SemanticActions::SA15(std::string& lexeme, const char& character)
{

    return -1;
}

int SemanticActions::SA16(std::string& lexeme, const char& character)
{
    const int token = ReservedWordsTable::getToken(lexeme);
    if (token == -1)
        lanzarError("Unknown reserved word '" + lexeme + "'");
    return token;
}