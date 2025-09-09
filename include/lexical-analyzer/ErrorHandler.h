//
// Created by matiasortiz on 9/9/25.
//

#ifndef TPE_ERRORHANDLER_H
#define TPE_ERRORHANDLER_H

#include <string>

#include "lexical-analyzer/FileReader.h"

extern FileReader GFILE;

namespace ErrorHandler
{
    /*
     * @brief se utiliza para lanzar errores con número de línea.
     */
    [[noreturn]] void throwError(const std::string& suffix);
}

#endif //TPE_ERRORHANDLER_H