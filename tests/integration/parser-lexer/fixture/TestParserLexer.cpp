#include "TestParserLexer.h"

#include "code-generator/code-generator.h"
#include "code-generator/components/wat-generation/WatCodeBlockGenerator.h"
#include "semantic-analyzer/semantic_analyzer.h"

void TestParserLexer::SetUp()
{
    SYMBOL_TABLE.clear();
    LITERAL_TABLE.clear();
    ERROR_HANDLER.clear();

    if (VERBOSE_OPTION)
        REPORT_HANDLER.clear();

    SemanticAnalyzer::CHK_TYPES = SemanticAnalyzer::TypeChecker();
    SemanticAnalyzer::CHK_RETURNS = SemanticAnalyzer::ReturnChecker();
    SemanticAnalyzer::CHK_LAMBDAS = SemanticAnalyzer::LambdaChecker();
    SemanticAnalyzer::CHK_PROGRAMS = SemanticAnalyzer::ProgramChecker();
    SemanticAnalyzer::CHK_FUNCTIONS = SemanticAnalyzer::FunctionChecker();
    SemanticAnalyzer::CHK_VARIABLES = SemanticAnalyzer::VariableChecker();
    SemanticAnalyzer::CHK_INVOCATIONS = SemanticAnalyzer::InvocationChecker();

    SemanticAnalyzer::SCOPE = "";
    SemanticAnalyzer::TYPE = UNKNOWN;

    CodeGenerator::clear();
}

void TestParserLexer::TearDown()
{
    if (VERBOSE_OPTION)
        if (REPORT_HANDLER.validOutput())
            REPORT_HANDLER.generateReport();
        else
            std::cerr << "\nCouldn't generate report!\n" << std::endl;
}