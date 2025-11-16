#include "utils/Log.h"
#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"

bool EXISTS_PROGRAM = false;

extern SymbolTable SYMBOL_TABLE;
extern ErrorHandler ERROR_HANDLER;

namespace SemanticAnalyzer
{
    void checkProgramRedeclaration(const std::string& program)
    {
        if (EXISTS_PROGRAM)
        {
            const Log l(ERROR, MULTIPLE_PROGRAMS_DECLARED, LexicalAnalyzer::YYLINENO, {program});
            ERROR_HANDLER.add(l);
            return;
        }
        EXISTS_PROGRAM = true;
    }

    const SymbolTable::Entry* updateSymbolAsProgram(const std::string& program)
    {
        const auto entry = SYMBOL_TABLE.get(program);
        if (entry == nullptr)
            throw std::runtime_error("\nupdateSymbolAsProgram: failed to get program");
        if (entry->use == ST_PROGRAM)
            return nullptr;
        const auto newEntry = SymbolTable::Entry({program, ST_UNSUPPORTED, ST_PROGRAM});
        return SYMBOL_TABLE.update(program, newEntry);
    }
}