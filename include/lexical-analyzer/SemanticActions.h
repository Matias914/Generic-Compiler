#ifndef TPE_SEMANTICACTION_H
#define TPE_SEMANTICACTION_H

#include <string>

/*
 * @brief clase que representa una accion asociada a una transicion en
 * la máquina de estados
 *
 * Realiza una accion sobre el lexema. Puede tirar error en caso de detectarlos.
 *
 */
using SemanticAction = void(*) (std::string&, const char& character);

namespace SemanticActions
{
    void  SA1(std::string& lexeme, const char& character);
    void  SA2(std::string& lexeme, const char& character);
    void  SA3(std::string& lexeme, const char& character);
    void  SA4(std::string& lexeme, const char& character);
    void  SA5(std::string& lexeme, const char& character);
    void  SA6(std::string& lexeme, const char& character);
    void  SA7(std::string& lexeme, const char& character);
    void  SA8(std::string& lexeme, const char& character);
    void  SA9(std::string& lexeme, const char& character);
    void SA10(std::string& lexeme, const char& character);
    void SA11(std::string& lexeme, const char& character);
    void SA12(std::string& lexeme, const char& character);
    void SA13(std::string& lexeme, const char& character);
    void SA14(std::string& lexeme, const char& character);
    void SA15(std::string& lexeme, const char& character);
}

#endif //TPE_SEMANTICACTION_H