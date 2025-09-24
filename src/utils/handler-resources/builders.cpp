#include "utils/handler-resources/builders.h"

// ========================================= //
//                  ERRORS                   //
// ========================================= //

namespace Builders
{
    std::string create(const std::string& mssg)
    {
        return "Error: " + mssg + ".";
    }

    std::string defaultError(const std::vector<std::string>& content)
    {
        return create("Unknown Error");
    }

    std::string integerOutOfRange(const std::vector<std::string>& content)
    {
        return create("Integer literal '" + content[0] + "' is out of range [0, 65535]");
    }

    std::string floatOutOfRange(const std::vector<std::string>& content)
    {
        std::string range = "[-3.40282347F+38, -1.17549435F-38]";
        range += " U 0.0 U ";
        range += "[1.17549435F-38, 3.40282347F+38]";
        return create("Float literal '" + content[0] + "' is out of range range" + range);
    }

    std::string invalidReservedWord(const std::vector<std::string>& content)
    {
        return create("'" + content[0] + "' is not a reserved word");
    }

    std::string unexpectedCharacter(const std::vector<std::string>& content)
    {
        return create("Unexpected character '" + content[0] + "' was found");
    }

    std::string integerWithoutSuffix(const std::vector<std::string>& content)
    {
        return create("Integer literal '" + content[0] + "' doesnt end with 'UI'");
    }

    std::string exponentWithoutSign(const std::vector<std::string>& content)
    {
        return create("An exponent should have a sign (after an 'F') and a value.");
    }

    std::string floatWithoutNumbers(const std::vector<std::string>& content)
    {
        return create("A number was expected after '" + content[0] + "'. Did you mean to write a float literal?.");
    }

    std::string stringLiteralWithEndl(const std::vector<std::string>& content)
    {
        return create("A string literal must be a single line. '\\n' was found.");
    }

    std::string unclosedStringLiteral(const std::vector<std::string>& content)
    {
        return create("Unexpected End Of File. Unclosed String Literal.");
    }

    std::string unopenedComment(const std::vector<std::string>& content)
    {
        return create("A comment should be opened like this '##'.");
    }

    std::string unclosedComment(const std::vector<std::string>& content)
    {
        return create("Unexpected End Of File. Unclosed comment (##).");
    }

    std::string invalidColon(const std::vector<std::string>& content)
    {
        return create("':' is not valid. Did you mean ':=' ?");
    }

    std::string statementWithoutSemicolon(const std::vector<std::string>& content)
    {
        return create("; was expected");
    }

    std::string genericSyntaxError(const std::vector<std::string>& content)
    {
        return create("Syntax Error");
    }

    // ========================================= //
    //                  WARNING                  //
    // ========================================= //

    std::string truncatedIdentifier(const std::vector<std::string>& content)
    {
        return "Warning: Identifier '" + content[0] + "' was truncated to '" + content[1]
             + "'.\nThe maximum length is 20 characters.";
    }
}