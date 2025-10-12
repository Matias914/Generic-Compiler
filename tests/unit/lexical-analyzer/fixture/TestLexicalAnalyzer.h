#ifndef GC_TESTLEXICALANALYZER_H
#define GC_TESTLEXICALANALYZER_H

#include "gtest/gtest.h"
#include "utils/SymbolTable.h"
#include "utils/LiteralTable.h"
#include "utils/ReportHandler.h"

extern bool VERBOSE_OPTION;
extern std::string WORKING_DIRECTORY;

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;
extern ReportHandler REPORT_HANDLER;

class TestLexicalAnalyzer : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    /*
    * @brief esta funcion verifica que el lexema actual, dado al
    * parser por el analizador léxico, exista en la tabla de símbolos
    * y que coincida con el valor esperado.
    */
    static bool validSymbol(const std::string& expected);

    /*
     * @brief esta funcion verifica que el lexema actual, dado al
     * parser por el analizador léxico, exista en la tabla de literales
     * y que coincida con el valor esperado.
     */
    static bool validLiteral(const std::string& expected);
};


#endif //GC_TESTLEXICALANALYZER_H