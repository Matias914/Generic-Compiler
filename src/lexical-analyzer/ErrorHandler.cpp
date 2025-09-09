#include "lexical-analyzer/ErrorHandler.h"

[[noreturn]] void ErrorHandler::throwError(const std::string& suffix)
{
    const std::string prefix = "ERROR. Line " + std::to_string(GFILE.yylineno) + ": ";
    throw std::runtime_error(prefix + suffix + ".");
}