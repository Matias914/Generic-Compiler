#ifndef TPE_WARNING_CODES_H
#define TPE_WARNING_CODES_H

#include <string>
#include <vector>

using Builder = std::string (*) (const std::vector<std::string>&);

namespace Builders
{
    // Errors
    std::string defaultError(const std::vector<std::string>& content);
    std::string integerOutOfRange(const std::vector<std::string>& content);
    std::string floatOutOfRange(const std::vector<std::string>& content);
    std::string invalidReservedWord(const std::vector<std::string>& content);
    std::string unexpectedCharacter(const std::vector<std::string>& content);
    std::string integerWithoutSuffix(const std::vector<std::string>& content);
    std::string exponentWithoutSign(const std::vector<std::string>& content);
    std::string floatWithoutNumbers(const std::vector<std::string>& content);
    std::string stringLiteralWithEndl(const std::vector<std::string>& content);
    std::string unclosedStringLiteral(const std::vector<std::string>& content);
    std::string unopenedComment(const std::vector<std::string>& content);
    std::string unclosedComment(const std::vector<std::string>& content);
    std::string invalidColon(const std::vector<std::string>& content);
    std::string statementWithoutSemicolon(const std::vector<std::string>& content);
    std::string genericSyntaxError(const std::vector<std::string>& content);
    std::string genericSyntaxError(const std::vector<std::string>& content);

    // Warnings
    std::string truncatedIdentifier(const std::vector<std::string>& content);
}

#endif //TPE_WARNING_CODES_H