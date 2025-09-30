#include <stdexcept>

#include "utils/resources/builders.h"

#define   ERROR_MSG(x) "Error: " x "."
#define WARNING_MSG(x) "Warning: " x "."

namespace StringBuilders
{
    // -------------------------------------- Warnings -------------------------------------- //

    std::string truncatedIdentifier(const std::vector<std::string>& content)
    {
        if (content.size() != 2)
            throw std::runtime_error("truncatedIdentifier: invalid log");
        std::string mssg;
        mssg.reserve(256);
        mssg.append("Identifier '")
            .append(content[0])
            .append("' was truncated to '")
            .append(content[1]).append("'. The maximum length is 20 characters");
        return WARNING_MSG(+mssg+);
    }

    // --------------------------------------- Errors --------------------------------------- //

    std::string defaultError(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Unknown Error");
    }

    std::string integerOutOfRange(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("integerOutOfRange: invalid log");
        return ERROR_MSG("Integer literal '" + content[0] + "' is out of range [0, 65535]");
    }

    std::string floatOutOfRange(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("floatOutOfRange: invalid log");
        std::string mssg;
        mssg.reserve(256);
        mssg.append("Float literal '")
            .append(content[0])
            .append("' is out of range: ")
            .append("[-3.40282347F+38, -1.17549435F-38]")
            .append(" U 0.0 U ")
            .append("[1.17549435F-38, 3.40282347F+38]");
        return ERROR_MSG(+mssg+);
    }

    std::string invalidReservedWord(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("invalidReservedWord: invalid log");
        return ERROR_MSG("'" + content[0] + "' is not a reserved word");
    }

    std::string unexpectedCharacter(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("unexpectedCharacter: invalid log");
        return ERROR_MSG("Unexpected character '" + content[0] + "' was found");
    }

    std::string integerWithoutSuffix(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("integerWithoutSuffix: invalid log");
        return ERROR_MSG("Integer literal '" + content[0] + "' doesnt end with 'UI'");
    }

    std::string exponentWithoutSign(const std::vector<std::string>& content)
    {
        return ERROR_MSG("An exponent should have a sign (after an 'F') and a value");
    }

    std::string floatWithoutNumbers(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("floatWithoutNumbers: invalid log");
        return ERROR_MSG("A number was expected after '" + content[0] + "'. Did you mean to write a float literal?");
    }

    std::string stringLiteralWithEndl(const std::vector<std::string>& content)
    {
        return ERROR_MSG("A string literal must be a single line. '\\n' was found");
    }

    std::string unclosedStringLiteral(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Unexpected End Of File. Unclosed String Literal");
    }

    std::string unopenedComment(const std::vector<std::string>& content)
    {
        return ERROR_MSG("A comment should be opened like this '##'");
    }

    std::string unclosedComment(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Unexpected End Of File. Unclosed comment (##)");
    }

    std::string invalidColon(const std::vector<std::string>& content)
    {
        return ERROR_MSG("':' is not valid. Did you mean ':=' ?");
    }

    std::string expectedButFound(const std::vector<std::string>& content)
    {
        if (content.size() != 2)
            throw std::runtime_error("expectedButFound: invalid log");
        return ERROR_MSG(+content[1]+ " was expected but '" + content[0] + "' was found");
    }

    std::string genericSyntaxError(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Syntax Error");
    }
}