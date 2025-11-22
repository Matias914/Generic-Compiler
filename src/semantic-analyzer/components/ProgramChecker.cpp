#include "semantic-analyzer/components/ProgramChecker.h"

#include "lexical-analyzer/lexical_analyzer.h"
#include "utils/ErrorHandler.h"
#include "utils/resources/codes.h"

#define RUNTIME_E1 "\nupdateSymbolAsProgram: failed to get program"

extern SymbolTable  SYMBOL_TABLE;
extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    ProgramChecker::ProgramChecker() : declared(false) {}

    /*
     * @brief Determina si ya hubo un programa declarado y, además, intenta modificar la tabla de símbolos para indicar
     * que el símbolo es programa.
     *
     * Si falla la actualización retorna nullptr. Podría fallar si el símbolo fue declarado ya.
     */
    const SymbolTable::Entry* ProgramChecker::checkProgramDeclaration(const std::string& program)
    {
        if (declared)
        {
            const Log l(ERROR, MULTIPLE_PROGRAMS_DECLARED, LexicalAnalyzer::YYLINENO, {program});
            ERROR_HANDLER.add(l);
        }
        declared = true;

        // Intenta actualizar tabla de símbolos
        if (program.empty())
            return nullptr;
        const auto entry = SYMBOL_TABLE.get(program);
        if (entry == nullptr)
            throw std::runtime_error(RUNTIME_E1);
        // Ya fue inicializada
        if (entry->use != UNKNOWN)
            return nullptr;
        const auto new_entry = SymbolTable::Entry({program, UNKNOWN, PROGRAM});
        return SYMBOL_TABLE.update(program, new_entry);
    }
}
