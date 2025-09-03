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
using SemanticAction = void(*) (std::string&);

namespace SemanticActions
{
    void  SA1(std::string& lexeme);
    void  SA2(std::string& lexeme);
    void  SA3(std::string& lexeme);
    void  SA4(std::string& lexeme);
    void  SA5(std::string& lexeme);
    void  SA6(std::string& lexeme);
    void  SA7(std::string& lexeme);
    void  SA8(std::string& lexeme);
    void  SA9(std::string& lexeme);
    void SA10(std::string& lexeme);
    void SA11(std::string& lexeme);
    void SA12(std::string& lexeme);
    void SA13(std::string& lexeme);
    void SA14(std::string& lexeme);
    void SA15(std::string& lexeme);
}

#endif //TPE_SEMANTICACTION_H