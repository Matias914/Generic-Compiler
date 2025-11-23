#include "utils/CompilerState.h"

#include "code-generator/CodeGenerator.h"
#include "semantic-analyzer/SemanticAnalyzer.h"
#include "utils/ErrorHandler.h"
#include "utils/LiteralTable.h"
#include "utils/ReportHandler.h"
#include "utils/SymbolTable.h"

extern SymbolTable   SYMBOL_TABLE;
extern LiteralTable  LITERAL_TABLE;
extern ErrorHandler  ERROR_HANDLER;
extern ReportHandler REPORT_HANDLER;

extern bool VERBOSE_OPTION;

namespace CompilerState
{
    void reset()
    {
        // Reseteo de Utilidades
        SYMBOL_TABLE.clear();
        LITERAL_TABLE.clear();
        ERROR_HANDLER.clear();

        if (VERBOSE_OPTION)
            REPORT_HANDLER.clear();

        // Reseteo del Analizador Semántico
        SemanticAnalyzer::CHK_TYPES = SemanticAnalyzer::TypeChecker();
        SemanticAnalyzer::CHK_RETURNS = SemanticAnalyzer::ReturnChecker();
        SemanticAnalyzer::CHK_LAMBDAS = SemanticAnalyzer::LambdaChecker();
        SemanticAnalyzer::CHK_PROGRAMS = SemanticAnalyzer::ProgramChecker();
        SemanticAnalyzer::CHK_FUNCTIONS = SemanticAnalyzer::FunctionChecker();
        SemanticAnalyzer::CHK_VARIABLES = SemanticAnalyzer::VariableChecker();
        SemanticAnalyzer::CHK_INVOCATIONS = SemanticAnalyzer::InvocationChecker();
        SemanticAnalyzer::SCOPE = "";
        SemanticAnalyzer::TYPE = UNKNOWN;

        // Reseteo del Generador de Código
        CodeGenerator::clear();
     }
}