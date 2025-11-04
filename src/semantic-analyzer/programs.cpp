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
            Log l;
            l.type = ERROR;
            l.code = MULTIPLE_PROGRAMS_DECLARED;
            l.line = LexicalAnalyzer::YYLINENO;
            l.content = { program };
            ERROR_HANDLER.add(l);
        } else
            EXISTS_PROGRAM = true;
    }

    const SymbolTable::Entry* updateSymbolAsProgram(const std::string& program)
    {
        const auto entry = SYMBOL_TABLE.get(program);
        if (entry == nullptr)
            throw std::runtime_error("\nupdateSymbolAsProgram: failed to get program");
        if (entry->use == PROGRAM)
            return nullptr;
        const auto newentry = SymbolTable::Entry({program, -1, PROGRAM});
        return SYMBOL_TABLE.update(program, &newentry);
    }
}