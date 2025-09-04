#ifndef TPE_SEMANTICACTION_H
#define TPE_SEMANTICACTION_H

#include <string>

/*
 * @brief clase que representa una accion asociada a una transicion en la máquina
 * de estados
 *
 * Realiza una accion sobre el lexema. Puede tirar error en caso de detectarlos.
 *
 * IMPORTANTE: Actualiza el yylval y se encarga de agregar a la tabla de simbolos.
 */
using SemanticAction = int(*) (std::string&, const char& character);

namespace SemanticActions
{
    int  SA1(std::string& lexeme, const char& character);
    int  SA2(std::string& lexeme, const char& character);
    int  SA3(std::string& lexeme, const char& character);
    int  SA4(std::string& lexeme, const char& character);
    int  SA5(std::string& lexeme, const char& character);
    int  SA6(std::string& lexeme, const char& character);
    int  SA7(std::string& lexeme, const char& character);
    int  SA8(std::string& lexeme, const char& character);
    int  SA9(std::string& lexeme, const char& character);
    int SA10(std::string& lexeme, const char& character);
    int SA11(std::string& lexeme, const char& character);
    int SA12(std::string& lexeme, const char& character);
    int SA13(std::string& lexeme, const char& character);
    int SA14(std::string& lexeme, const char& character);
    int SA15(std::string& lexeme, const char& character);
    int SA16(std::string& lexeme, const char& character);
}

#endif //TPE_SEMANTICACTION_H