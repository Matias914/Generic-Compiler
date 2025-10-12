#ifndef TPE_BUILDERS_H
#define TPE_BUILDERS_H

#include <string>
#include <vector>

namespace StringBuilders
{
    std::string customError(const std::vector<std::string>& content);

    // Lexical Errors
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

    // Syntax Errors
    std::string globalScopeStatement(const std::vector<std::string>& content);
    std::string missingProgramName(const std::vector<std::string>& content);
    std::string missingOpeningBracket(const std::vector<std::string>& content);
    std::string missingClosingBracket(const std::vector<std::string>& content);
    std::string missingBothBrackets(const std::vector<std::string>& content);
    std::string invalidProgramNesting(const std::vector<std::string>& content);
    std::string invalidCompoundNesting(const std::vector<std::string>& content);
    std::string missingVariable(const std::vector<std::string>& content);
    std::string missingFunctionName(const std::vector<std::string>& content);
    std::string missingParameterName(const std::vector<std::string>& content);
    std::string missingParameterType(const std::vector<std::string>& content);
    std::string missingComma(const std::vector<std::string>& content);
    std::string missingSemicolon(const std::vector<std::string>& content);
    std::string missingOpeningParenthesis(const std::vector<std::string>& content);
    std::string missingClosingParenthesis(const std::vector<std::string>& content);
    std::string missingBothParenthesis(const std::vector<std::string>& content);
    std::string missingBothParenthesisCall(const std::vector<std::string>& content);
    std::string missingBothParenthesisTrunc(const std::vector<std::string>& content);
    std::string missingBothParenthesisPrint(const std::vector<std::string>& content);
    std::string missingBothParenthesisReturn(const std::vector<std::string>& content);
    std::string missingArgument(const std::vector<std::string>& content);
    std::string missingRightSideValues(const std::vector<std::string>& content);
    std::string missingPointedParameter(const std::vector<std::string>& content);
    std::string missingEndif(const std::vector<std::string>& content);
    std::string missingIfExecutableBody(const std::vector<std::string>& content);
    std::string missingElseExecutableBody(const std::vector<std::string>& content);
    std::string missingBothExecutableBody(const std::vector<std::string>& content);
    std::string missingIfStatement(const std::vector<std::string>& content);
    std::string missingWhile(const std::vector<std::string>& content);
    std::string missingWhileExecutableBody(const std::vector<std::string>& content);
    std::string missingComparisonOperator(const std::vector<std::string>& content);
    std::string missingExpressionOperator(const std::vector<std::string>& content);
    std::string missingRightOperand(const std::vector<std::string>& content);
    std::string missingLeftOperand(const std::vector<std::string>& content);
    std::string missingBothOperands(const std::vector<std::string>& content);
    std::string missingFloatConstant(const std::vector<std::string>& content);
    std::string missingLeftFactor(const std::vector<std::string>& content);
    std::string missingRightFactor(const std::vector<std::string>& content);
    std::string missingBothFactors(const std::vector<std::string>& content);
    std::string notYetImplemented(const std::vector<std::string>& content);
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