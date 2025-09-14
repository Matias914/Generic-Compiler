#include "utils/ErrorHandler.h"

#include <iostream>
#include <ostream>

ErrorHandler::ErrorHandler()
{
    this->logs = std::vector<Log>();
    this->error_count = 0;
}

void ErrorHandler::add(const Log& log)
{
    this->logs.push_back(log);
    if (log.type == ERROR)
        error_count++;
}

int ErrorHandler::errorCount() const
{
    return this->error_count;
}

void ErrorHandler::showLogs() const
{
    const int n = this->logs.size();
    if (n == 0) return;
    std::string mssg;
    if (this->error_count == 0)
        mssg += "Compiled with " + std::to_string(n - error_count) + " warnings.\n";
    else
        "Compilation Failed with " + std::to_string(n) + " error/s.\n";
    for (int i = 0; i < n; i++)
    {
        auto& log = this->logs[i];
        if (log.type == ERROR)
        {
            mssg += "ERROR. Line " + std::to_string(log.line) + ": ";
            mssg + createErrorMssg(log.code, log.content);
        }
        else
        {
            mssg += "WARNING. Line " + std::to_string(log.line) + ": ";
            mssg += createWarningMssg(log.code, log.content);
        }
        mssg += "\n";
    }
    std::cout << mssg << std::endl;
}

const ErrorHandler::Log& ErrorHandler::getLastestLog() const
{
    return this->logs.back();
}

[[noreturn]] void ErrorHandler::fatal()
{
    throw std::runtime_error("Process was terminated");
}


/* Private Functions to create the error and warning messages */

std::string ErrorHandler::createErrorMssg(const int& code, const std::vector<std::string>& content)
{
    switch (code)
    {
    case UNEXPECTED_EOF:
        return "Unexpected end of file.";
    case INVALID_RESERVED_WORD:
        return "'" + content[0] + "' is not a reserved word.";
    case INTEGER_OUT_OF_RANGE:
        return "Integer literal '" + content[0] + "' is out of range [0, 65535]";
    case FLOAT_OUT_OF_RANGE:
        {
            std::string range = "[-3.40282347F+38, -1.17549435F-38]";
            range += " U 0.0 U ";
            range += "[1.17549435F-38, 3.40282347F+38]";
            return "Float literal '" + content[0] + "' is out of range range" + range;
        }
    default:
        return "Unknown Error.";
    }
}

std::string ErrorHandler::createWarningMssg(const int& code, const std::vector<std::string>& content)
{
    switch (code)
    {
    case TRUNCATED_VARIABLE:
        return "Identifier '" + content[0] + "' was truncated to '" + content[1]
             + "'. The maximum lenth is 20 characters.";
    default:
        return "Unknown Error";
    }
}
