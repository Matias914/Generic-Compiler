#ifndef GC_SEMANTICACTION_H
#define GC_SEMANTICACTION_H

#include <string>

/*
 * @brief representa el grupo funciones que asocian a las transiciones de la
 * máquina de estados del analizador lexico.
 *
 * Las acciones semanticas son las responsables de conocer qué es lo que se
 * debe de hacer por cada tipo de caracter encontrado.
 */
namespace LexicalAnalyzer
{
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

        int DoNothing(std::string& lexeme, const char& character);
        int EndOfFile(std::string& lexeme, const char& character);

        /*
         * @brief estas acciones semanticas fueron hechas para tratar
         * errores.
         *
         * Conceptualmente, son las acciones semanticas asociadas a las
         * transiciones que llevan al estado de error.
         */
        int UnexpectedCharTrap(std::string& lexeme, const char& character);
        int ExpectedUITrap(std::string& lexeme, const char& character);
        int ExpectedSignTrap(std::string& lexeme, const char& character);
        int ExpectedNumberTrap(std::string& lexeme, const char& character);
        int ExpectedNoEndlTrap(std::string& lexeme, const char& character);
        int ExpectedQuoteTrap(std::string& lexeme, const char& character);
        int ExpectedNumeralTrap(std::string& lexeme, const char& character);
        int ExpectedCommentEndTrap(std::string& lexeme, const char& character);
        int ExpectedEqualsTrap(std::string& lexeme, const char& character);
    }
}

#endif //GC_SEMANTICACTION_H