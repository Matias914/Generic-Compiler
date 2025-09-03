#pragma once

#ifndef TPE_LEXICALANALYZER_H
#define TPE_LEXICALANALYZER_H

#include "FileReader.h"

extern FileReader GFILE;

/*
 * @brief representa el analizador lexico de un compilador
 *
 * Utiliza el lector de archivos para obtener los caracteres y convertirlos
 * en tokens que solicita el analizador sintactico
 *
 */
namespace LexicalAnalyzer
{
    int yylex();
    void setFileName(const char* filename);
}

#endif //TPE_LEXICALANALYZER_H