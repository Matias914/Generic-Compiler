#include "lexical-analyzer/FileReader.h"
#include "lexical-analyzer/SemanticActions.h"

extern FileReader GFILE;

/*
 * @brief se utiliza para lanzar errores con numero de linea.
 *
 */
void lanzarError(const std::string& suffix)
{
    const std::string prefix = "Linea " + std::to_string(GFILE.yylineno) + ": ";
    throw std::runtime_error(prefix + suffix);
}

/* ------------------------- SEMANTIC ACTIONS ------------------------- */

void  SemanticActions::SA1(std::string& lexeme, const char& character)
{
    lexeme = "" + character;
}

void  SemanticActions::SA2(std::string& lexeme, const char& character)
{
    lexeme += character;
}

void  SemanticActions::SA3(std::string& lexeme, const char& character)
{
    if (character == 'U')
        lanzarError(lexeme + "el sufijo de una constante es UI");
    lexeme += character;
}

void  SemanticActions::SA4(std::string& lexeme, const char& character)
{
    if (character == 'I')
        lanzarError(lexeme + "el sufijo de una constante es UI");
    lexeme += character;
    // TODO: si el lexema solo puede ser uint, no comparar con cero. TABLA DE SIMBOLOS
    const int value = stoi(lexeme.substr(0, lexeme.size() - 2));
    if (value >= 0 && value <= 65535)
        lanzarError(lexeme + "la constante sobrepasa 65535");
}

void  SemanticActions::SA5(std::string& lexeme, const char& character)
{

}

void  SemanticActions::SA6(std::string& lexeme, const char& character)
{

}

void  SemanticActions::SA7(std::string& lexeme, const char& character)
{

}

void  SemanticActions::SA8(std::string& lexeme, const char& character)
{

}

// TODO: preguntar por el tema de la insercion de espacio
void  SemanticActions::SA9(std::string& lexeme, const char& character)
{

}

void SemanticActions::SA10(std::string& lexeme, const char& character)
{

}

void SemanticActions::SA11(std::string& lexeme, const char& character)
{

}

void SemanticActions::SA12(std::string& lexeme, const char& character)
{

}

void SemanticActions::SA13(std::string& lexeme, const char& character)
{

}

void SemanticActions::SA14(std::string& lexeme, const char& character)
{

}

void SemanticActions::SA15(std::string& lexeme, const char& character)
{

}