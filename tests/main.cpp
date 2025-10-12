#include "gtest/gtest.h"
#include "utils/ErrorHandler.h"
#include "utils/LiteralTable.h"
#include "utils/ReportHandler.h"
#include "utils/SymbolTable.h"

#include <string>

bool VERBOSE_OPTION = false;

std::string WORKING_DIRECTORY;

SymbolTable SYMBOL_TABLE;
LiteralTable LITERAL_TABLE;
ErrorHandler ERROR_HANDLER;
ReportHandler REPORT_HANDLER;

/*
 * @brief este archivo contiene las variables globales utilizadas
 * en los tests y el main para poder correrlos.
 */
int main(int argc, char** argv)
{
    // Parsing requiere argumentos del tipo --option para diferenciarlos
    // del resto de argumentos de GoogleTest.
    for (int i = 1; i < argc; ++i) {
        if (std::string arg = argv[i]; arg.rfind("--input=", 0) == 0) {
            WORKING_DIRECTORY = arg.substr(8);
        }
        else if (arg == "--verbose") {
            VERBOSE_OPTION = true;
        }
    }

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
