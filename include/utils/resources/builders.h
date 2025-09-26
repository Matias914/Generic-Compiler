#ifndef TPE_BUILDERS_H
#define TPE_BUILDERS_H

#include <string>
#include <vector>

namespace StringBuilders
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
    std::string expectedButFound(const std::vector<std::string>& content);
    std::string genericSyntaxError(const std::vector<std::string>& content);

    // Warnings
    std::string truncatedIdentifier(const std::vector<std::string>& content);

    // Tokens
    std::string reportToken(const std::vector<std::string>& content);
    std::string reportEndOfFile(const std::vector<std::string>& content);
    std::string reportInvalidToken(const std::vector<std::string>& content);

    // Structures
    std::string reportStructure(const std::vector<std::string>& content);

    // Tables
    std::string symbolTableEntry(const std::vector<std::string>& content);
    std::string symbolTableHeader(const std::vector<std::string>& content);
    std::string literalTableEntry(const std::vector<std::string>& content);
    std::string literalTableHeader(const std::vector<std::string>& content);
}

#endif //TPE_BUILDERS_H