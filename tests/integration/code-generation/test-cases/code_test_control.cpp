#include "../../fixture/CompilerTest.h"
#include "code-generator/CodeGenerator.h"
#include "gtest/gtest.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "syntax-analyzer/SyntaxAnalyzer.h"

TEST_F(CompilerTest, code_control)
{
    REPORT_HANDLER.setOutput(OUTPUT_DIRECTORY + "/code_control.log");

    const std::string file = WORKING_DIRECTORY + "/tests/integration/code-generation/files/code_control.txt";
    assert(LexicalAnalyzer::open(file));

    SyntaxAnalyzer::analyze();

    const auto ptr_triples = CodeGenerator::getAssociatedTriples("PROGRAMA");
    EXPECT_NE(ptr_triples, nullptr);

    const auto& triples = *ptr_triples;
    auto it = triples.begin();

    // 0. Inicializacion X
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "X:PROGRAMA");
    EXPECT_EQ(it->o2.type, LITERAL);
    EXPECT_EQ(it->o2.value.lref->constant, "0UI");

    ++it;

    // 1. Inicializacion Y
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "Y:PROGRAMA");
    EXPECT_EQ(it->o2.type, LITERAL);
    EXPECT_EQ(it->o2.value.lref->constant, "10UI");

    ++it;

    // 2. Etiqueta Inicio DO-WHILE
    EXPECT_EQ(it->codeop, CODEOP_DO_START);
    EXPECT_EQ(it->o1.type, NULLREF);
    EXPECT_EQ(it->o2.type, NULLREF);

    ++it;

    // 3. Etiqueta Inicio IF
    EXPECT_EQ(it->codeop, CODEOP_IF_START);
    EXPECT_EQ(it->o1.type, NULLREF);
    EXPECT_EQ(it->o2.type, NULLREF);

    ++it;

    // 4. Condicion IF (X > 5)
    EXPECT_EQ(it->codeop, CODEOP_GT);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "X:PROGRAMA");
    EXPECT_EQ(it->o2.type, LITERAL);
    EXPECT_EQ(it->o2.value.lref->constant, "5UI");

    ++it;

    // 5. Salto al ELSE si es falso
    EXPECT_EQ(it->codeop, CODEOP_BRANCH_FALSE);
    EXPECT_EQ(it->o1.type, TRIPLE);
    EXPECT_EQ(it->o1.value.tref, 4); // Refiere a la comparación anterior
    EXPECT_EQ(it->o2.type, TRIPLE);
    EXPECT_EQ(it->o2.value.tref, 9); // Destino: Inicio del Else

    ++it;

    // 6. Cuerpo IF (true): Resta (X - 1)
    EXPECT_EQ(it->codeop, CODEOP_SUB);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "X:PROGRAMA");
    EXPECT_EQ(it->o2.type, LITERAL);
    EXPECT_EQ(it->o2.value.lref->constant, "1UI");

    ++it;

    // 7. Cuerpo IF (true): Asignacion X
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "X:PROGRAMA");
    EXPECT_EQ(it->o2.type, TRIPLE);
    EXPECT_EQ(it->o2.value.tref, 6);

    ++it;

    // 8. Salto Incondicional Fin IF (Para saltar el Else)
    // Salta a la instruccion 10 (Fin del IF)
    EXPECT_EQ(it->codeop, CODEOP_BRANCH_TRUE);
    EXPECT_EQ(it->o1.type, TRIPLE);
    EXPECT_EQ(it->o1.value.tref, 11); // Destino: Fin del IF
    EXPECT_EQ(it->o2.type, NULLREF);

    ++it;

    // 9. Cuerpo ELSE: Suma (X + 1)
    EXPECT_EQ(it->codeop, CODEOP_SUM);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "X:PROGRAMA");
    EXPECT_EQ(it->o2.type, LITERAL);
    EXPECT_EQ(it->o2.value.lref->constant, "1UI");

    ++it;

    // 10. Cuerpo ELSE: Asignacion X
    EXPECT_EQ(it->codeop, CODEOP_ASSIGN);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "X:PROGRAMA");
    EXPECT_EQ(it->o2.type, TRIPLE);
    EXPECT_EQ(it->o2.value.tref, 9);

    ++it;

    // 11. Marca Fin IF
    EXPECT_EQ(it->codeop, CODEOP_IF_END);

    ++it;

    // 12. Comparacion Loop (X < Y)
    EXPECT_EQ(it->codeop, CODEOP_LT);
    EXPECT_EQ(it->o1.type, SYMBOL);
    EXPECT_EQ(it->o1.value.sref->symbol, "X:PROGRAMA");
    EXPECT_EQ(it->o2.type, SYMBOL);
    EXPECT_EQ(it->o2.value.sref->symbol, "Y:PROGRAMA");

    ++it;

    // 13. Salto al inicio del loop si Verdadero
    EXPECT_EQ(it->codeop, CODEOP_BRANCH_TRUE);
    EXPECT_EQ(it->o1.type, TRIPLE);
    EXPECT_EQ(it->o1.value.tref, 12);
    EXPECT_EQ(it->o2.type, TRIPLE);
    EXPECT_EQ(it->o2.value.tref, 2); // Vuelta al inicio
}