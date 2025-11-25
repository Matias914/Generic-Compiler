#include "../../fixture/CompilerTest.h"
#include "code-generator/CodeGenerator.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"

TEST_F(CompilerTest, code_functions)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/code_functions.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/code-generation/files/code_functions.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    auto ptr_triples = CodeGenerator::getAssociatedTriples("PROGRAMA");
    EXPECT_NE(ptr_triples, nullptr);

    auto& program_triples = *ptr_triples;
    auto it = program_triples.begin();

    /* PROGRAMA */

    // 0. Por semantica CV
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "A:PROGRAMA:FUNC");
    EXPECT_EQ(it->o2.type, LITERAL);
    EXPECT_EQ(it->o2.value.lref->constant, "10UI");

    ++it;

    // 1. Llamada
    EXPECT_EQ(it->codeop, CODEOP_CALL);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "FUNC:PROGRAMA");

    ++it;

    // 2. Por semantica CR
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "GLOB:PROGRAMA");
    EXPECT_EQ(it->o2.type, SYMBOL);
    EXPECT_EQ(it->o2.value.sref->symbol, "B:PROGRAMA:FUNC");

    ++it;

    // 3. Por Return
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "GLOB:PROGRAMA");
    EXPECT_EQ(it->o2.type, TRIPLE);
    EXPECT_EQ(it->o2.value.tref, 1);

    ++it;

    // 4. Por semantica obligatoria CV en Lambda
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "E:PROGRAMA:@L1");
    EXPECT_EQ(it->o2.type, SYMBOL);
    EXPECT_EQ(it->o2.value.sref->symbol, "GLOB:PROGRAMA");

    ++it;

    // 5. Llamada a Lambda
    EXPECT_EQ(it->codeop, CODEOP_CALL);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "@L1:PROGRAMA");

    ptr_triples = CodeGenerator::getAssociatedTriples("FUNC:PROGRAMA");
    EXPECT_NE(ptr_triples, nullptr);

    const auto& function_triples = *ptr_triples;
    it = function_triples.begin();

    /* FUNCION */

    // 0. Por la suma
    EXPECT_EQ(it->codeop, CODEOP_SUM);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "A:PROGRAMA:FUNC");
    EXPECT_EQ(it->o2.type, SYMBOL);
    EXPECT_EQ(it->o2.value.sref->symbol, "B:PROGRAMA:FUNC");

    ++it;

    // 1. Asignacion
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "B:PROGRAMA:FUNC");
    EXPECT_EQ(it->o2.type, TRIPLE);
    EXPECT_EQ(it->o2.value.tref, 0);

    ++it;

    // 2. Por Return
    EXPECT_EQ(it->codeop, CODEOP_RET);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "B:PROGRAMA:FUNC");
    EXPECT_EQ(it->o2.type, NULLREF);

    ptr_triples = CodeGenerator::getAssociatedTriples("@L1:PROGRAMA");
    EXPECT_NE(ptr_triples, nullptr);

    const auto& lambda_triples = *ptr_triples;
    it = lambda_triples.begin();

    /* LAMBDA */

    // 0. Por la suma
    EXPECT_EQ(it->codeop, CODEOP_SUM);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "E:PROGRAMA:@L1");
    EXPECT_EQ(it->o2.type, LITERAL);
    EXPECT_EQ(it->o2.value.lref->constant, "1UI");

    ++it;

    // 1. Por print
    EXPECT_EQ(it->codeop, CODEOP_PRINT);
    EXPECT_EQ(it->o1.type, TRIPLE);
    EXPECT_EQ(it->o2.type, NULLREF);

    ++it;

    // 2. Por ser VOID
    EXPECT_EQ(it->codeop, CODEOP_RET);
    EXPECT_EQ(it->o1.type, NULLREF);
    EXPECT_EQ(it->o2.type, NULLREF);
}