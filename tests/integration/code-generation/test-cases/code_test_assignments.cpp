#include "../../fixture/CompilerTest.h"
#include "code-generator/CodeGenerator.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"

TEST_F(CompilerTest, code_assignments)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/code_assignments.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/code-generation/files/code_assignments.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    const auto ptr_triples = CodeGenerator::getAssociatedTriples("PROGRAMA");
    EXPECT_NE(ptr_triples, nullptr);

    const auto& triples = *ptr_triples;
    auto it = triples.begin();

    /* PROGRAMA */

    // 0. Asignacion
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "F:PROGRAMA");
    EXPECT_EQ(it->o2.type, LITERAL);
    EXPECT_EQ(it->o2.value.lref->constant, "5.5");

    ++it;

    // 1. Por Asignacion Multiple
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "A:PROGRAMA");
    EXPECT_EQ(it->o2.type, LITERAL);
    EXPECT_EQ(it->o2.value.lref->constant, "10UI");

    ++it;

    // 2. Por Asignacion Multiple
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "B:PROGRAMA");
    EXPECT_EQ(it->o2.type, LITERAL);
    EXPECT_EQ(it->o2.value.lref->constant, "20UI");

    ++it;

    // 3. Por Coercion
    EXPECT_EQ(it->codeop, CODEOP_FTOI);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "F:PROGRAMA");
    EXPECT_EQ(it->o2.type, NULLREF);

    ++it;

    // 4. Asignacion
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "C:PROGRAMA");
    EXPECT_EQ(it->o2.type, TRIPLE);
    EXPECT_EQ(it->o2.value.tref, 3);

    ++it;

    // 5. Asignacion SIN trunc
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "A:PROGRAMA");
    EXPECT_EQ(it->o2.type, SYMBOL);
    EXPECT_EQ(it->o2.value.sref->symbol, "B:PROGRAMA");
}