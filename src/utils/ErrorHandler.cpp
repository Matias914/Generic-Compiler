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

int ErrorHandler::warningCount() const
{
    return this->logs.size() - this->error_count;
}

const ErrorHandler::Log* ErrorHandler::getLastestLog() const
{
    if (this->logs.empty())
        return nullptr;
    return &this->logs.back();
}

std::string ErrorHandler::getLogs() const
{
    const int n =  logs.size();
    std::string mssg;
    for (int i = 0; i < n; i++)
    {
        auto& log = this->logs[i];
        if (log.type == ERROR)
        {
            mssg += "ERROR. Line " + std::to_string(log.line) + ": ";
            mssg += createErrorMssg(log.code, log.content);
        }
        else
        {
            mssg += "WARNING. Line " + std::to_string(log.line) + ": ";
            mssg += createWarningMssg(log.code, log.content);
        }
        if (i + 1 != n)
            mssg += "\n";
    }
    return mssg;
}

/* Private Functions to create the error and warning messages */

std::string ErrorHandler::createErrorMssg(const int& code, const std::vector<std::string>& content)
{
    switch (code)
    {
    case INTEGER_OUT_OF_RANGE:
        return "Integer literal '" + content[0] + "' is out of range [0, 65535].";
    case FLOAT_OUT_OF_RANGE:
        {
            std::string range = "[-3.40282347F+38, -1.17549435F-38]";
            range += " U 0.0 U ";
            range += "[1.17549435F-38, 3.40282347F+38]";
            return "Float literal '" + content[0] + "' is out of range range" + range + ".";
        }
    case INVALID_RESERVED_WORD:
        return "'" + content[0] + "' is not a reserved word.";
    case UNEXPECTED_CHARACTER:
        return "Unexpected character '" + content[0] + "' was found.";
    case INTEGER_WITHOUT_SUFFIX:
        return "Integer literal '" + content[0] + "' doesnt end with 'UI'.";
    case EXPONENT_WITHOUT_SIGN:
        return "An exponent should have a sign (after an 'F') and a value.";
    case FLOAT_WITHOUT_NUMBERS:
        return "A number was expected after '" + content[0] + "'. Did you mean to write a float literal?.";
    case STRING_LITERAL_WITH_ENDL:
        return "A string literal must be a single line. '\\n' was found.";
    case UNCLOSED_STRING_LITERAL:
        return "Unexpected End Of File. Unclosed String Literal.";
    case UNOPENED_COMMENT:
        return "A comment should be opened like this '##'.";
    case UNCLOSED_COMMENT:
        return "Unexpected End Of File. Unclosed comment (##).";
    case INVALID_COLON:
        return "':' is not valid. Did you mean ':=' ?";
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
             + "'.\nThe maximum length is 20 characters.";
    default:
        return "Unknown Error.";
    }
}
