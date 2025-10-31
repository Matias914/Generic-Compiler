#ifndef TPE_SYNTAX_ANALYZER_H
#define TPE_SYNTAX_ANALYZER_H

#include "utils/ErrorBuffer.h"

/*
 * @brief representa el analizador sintactico de un compilador.
 *
 * Su rol es la generacion de reglas que permitan identificar
 * la gramatica del lenguaje. El parser fue realizado con la
 * herramienta de Bison.
 */
namespace SyntaxAnalyzer
{
    extern ErrorBuffer BUFFER;

    void analyze();
}

#endif //TPE_SYNTAX_ANALYZER_H