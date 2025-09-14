#ifndef TPE_SEMANTICACTION_H
#define TPE_SEMANTICACTION_H

#include <string>

/*
 * @brief representa el grupo funciones que asocian a las transiciones de la
 * máquina de estados del analizador lexico.
 *
 * Se define una estructura LexemeData que viene a ser un DTO para la comunicacion
 * con el analizador lexico.
 */
namespace LexicalAnalyzer
{
    struct LexemeData
    {
        int token;
        int entry_reference;
    };

    using SemanticAction = LexemeData(*) (std::string&, const char& character);

    namespace SemanticActions
    {
        LexemeData  SA1(std::string& lexeme, const char& character);
        LexemeData  SA2(std::string& lexeme, const char& character);
        LexemeData  SA3(std::string& lexeme, const char& character);
        LexemeData  SA4(std::string& lexeme, const char& character);
        LexemeData  SA5(std::string& lexeme, const char& character);
        LexemeData  SA6(std::string& lexeme, const char& character);
        LexemeData  SA7(std::string& lexeme, const char& character);
        LexemeData  SA8(std::string& lexeme, const char& character);
        LexemeData  SA9(std::string& lexeme, const char& character);
        LexemeData SA10(std::string& lexeme, const char& character);
        LexemeData SA11(std::string& lexeme, const char& character);
        LexemeData SA12(std::string& lexeme, const char& character);
        LexemeData SA13(std::string& lexeme, const char& character);
        LexemeData SA14(std::string& lexeme, const char& character);
        LexemeData SA15(std::string& lexeme, const char& character);
        LexemeData SA16(std::string& lexeme, const char& character);
        LexemeData SA17(std::string& lexeme, const char& character);
        LexemeData SA18(std::string& lexeme, const char& character);
        LexemeData SA19(std::string& lexeme, const char& character);

        LexemeData DoNothing(std::string& lexeme, const char& character);
        LexemeData Trap(std::string& lexeme, const char& character);
    }
}

#endif //TPE_SEMANTICACTION_H