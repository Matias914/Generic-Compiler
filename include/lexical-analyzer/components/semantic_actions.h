#ifndef TPE_SEMANTICACTION_H
#define TPE_SEMANTICACTION_H

#include <string>

#include "utils/SymbolTable.h"
#include "utils/LiteralTable.h"
#include "syntax-analyzer/Parser.h"

/*
 * @brief representa el grupo funciones que asocian a las transiciones de la
 * máquina de estados del analizador lexico.
 *
 * Se define una estructura int que viene a ser un DTO para la comunicacion
 * con el analizador lexico.
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
        int SA17(std::string& lexeme, const char& character);
        int SA18(std::string& lexeme, const char& character);
        int SA19(std::string& lexeme, const char& character);
        // Agregada por compatibilidad con el '.'
        int SA20(std::string& lexeme, const char& character);

        int DoNothing(std::string& lexeme, const char& character);
        int EndOfFile(std::string& lexeme, const char& character);

        /* Traps */
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

#endif //TPE_SEMANTICACTION_H