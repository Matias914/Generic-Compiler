#include <string>

#include "gtest/gtest.h"
#include "utils/ErrorHandler.h"
#include "utils/LiteralTable.h"
#include "utils/ReportHandler.h"
#include "utils/SymbolTable.h"

bool VERBOSE_OPTION = false;

std::string OUTPUT_DIRECTORY;
std::string WORKING_DIRECTORY = ".";

SymbolTable   SYMBOL_TABLE;
LiteralTable  LITERAL_TABLE;
ErrorHandler  ERROR_HANDLER;
ReportHandler REPORT_HANDLER;

/*
 * @brief este archivo contiene las variables globales utilizadas
 * en los tests y el main para poder correrlos.
 */
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    // Parsing requiere argumentos del tipo --option para diferenciarlos
    // del resto de argumentos de GoogleTest.
    for (int i = 1; i < argc; ++i) {
        if (std::string arg = argv[i]; arg.rfind("--input=", 0) == 0) {
            WORKING_DIRECTORY = arg.substr(8);
        }
        else if (arg.rfind("--verbose=", 0) == 0) {
            VERBOSE_OPTION = true;
            OUTPUT_DIRECTORY = arg.substr(10);
        } else
            std::cerr << "\n[[ ERROR ]]: Invalid Arguments were given: " << arg << "\n";
    }
    return RUN_ALL_TESTS();
}
