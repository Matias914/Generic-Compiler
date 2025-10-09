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

    std::string customError(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\ncustomError: invalid log");
        return ERROR_MSG(+content[0]+);
    }

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
        return ERROR_MSG("Integer literal '" + content[0] + "' doesnt end with UI");
    }

    std::string exponentWithoutSign(const std::vector<std::string>& content)
    {
        return ERROR_MSG("An exponent should have a sign (after an F) and a value");
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
        return ERROR_MSG("A comment should be opened like this ##");
    }

    std::string unclosedComment(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Unexpected End Of File. Unclosed comment (##)");
    }

    std::string invalidColon(const std::vector<std::string>& content)
    {
        return ERROR_MSG("':' is not valid. Did you mean := ?");
    }

    // Syntax //

    std::string globalScopeStatement(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Global scope statements are not valid. They should be inside a program");
    }

    std::string missingProgramName(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Program without name was closed but it must be defined as IDENTIFIER { ... }");
    }

    std::string missingOpeningBracket(const std::vector<std::string>& content)
    {
        return ERROR_MSG("} was found but it no block was opened");
    }

    std::string missingClosingBracket(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("missingClosingBrackets: invalid log");
        if (content[0].size() > 0)
            return ERROR_MSG("'" + content[0] + "' found but } was expected");
        return ERROR_MSG("Block was opened with { but never closed");
    }

    std::string missingBothBrackets(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Body must be defined with '{' '}'");
    }

    std::string invalidProgramNesting(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Program definition ended here but program nesting is not allowed");
    }

    std::string invalidCompoundNesting(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Compound structure ended here but that kind of nesting is not allowed");
    }

    std::string missingVariable(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("missingVariable: invalid log");
        return ERROR_MSG("Variable was expected as IDENTIFIER instead '" + content[0] + "' was found");
    }

    std::string missingFunctionName(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Function structure without name ended here but it must be defined with it");
    }

    std::string missingParameterName(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("missingParameterName: invalid log");
        return ERROR_MSG("Formal parameter name was expected but '" + content[0] + "' was found");
    }

    std::string missingParameterType(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("missingParameterType: invalid log");
        return ERROR_MSG("Formal parameter type (like uint) was expected before parameter name");
    }

    std::string missingComma(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("missingComma: invalid log");
        return ERROR_MSG(", was expected but '" + content[0] + "' was found");
    }

    std::string missingSemicolon(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("missingSemicolon: invalid log");
        return ERROR_MSG("; was expected but '" + content[0] + "' was found");
    }

    std::string missingOpeningParenthesis(const std::vector<std::string>& content)
    {
        return ERROR_MSG("')' was not corresponded with (");
    }

    std::string missingClosingParenthesis(const std::vector<std::string>& content)
    {
        return ERROR_MSG("'(' was used but never closed");
    }

    std::string missingBothParenthesis(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Conditions or arguments should be inside ( )");
    }

    std::string missingBothParenthesisCall(const std::vector<std::string>& content)
    {
        return ERROR_MSG("An invocation should have both ( )");
    }

    std::string missingBothParenthesisTrunc(const std::vector<std::string>& content)
    {
        return ERROR_MSG("trunc statment without ( ) is not allowed");
    }

    std::string missingBothParenthesisPrint(const std::vector<std::string>& content)
    {
        return ERROR_MSG("print statement without ( ) is not allowed");
    }

    std::string missingArgument(const std::vector<std::string>& content)
    {
        return ERROR_MSG("A valid argument was expected inside '( )'");
    }

    std::string missingRightSideValues(const std::vector<std::string>& content)
    {
        std::string mssg;
        mssg.append("In multiple assignments, the right-hand side must contain at least")
            .append(" as many values as the left-hand side");
        return ERROR_MSG(+mssg+);
    }

    std::string missingPointedParameter(const std::vector<std::string>& content)
    {
        return ERROR_MSG("A real parameter should specify the corresponding formal parameter with '->IDENTIFIER' syntax");
    }

    std::string missingEndif(const std::vector<std::string>& content)
    {
        return ERROR_MSG("if or if-else statement must end with 'endif'");
    }

    std::string missingIfExecutableBody(const std::vector<std::string>& content)
    {
        return ERROR_MSG("'if' without body was found");
    }

    std::string missingElseExecutableBody(const std::vector<std::string>& content)
    {
        return ERROR_MSG("'else' without body was found");
    }

    std::string missingBothExecutableBody(const std::vector<std::string>& content)
    {
        return ERROR_MSG("if-else should have both executable bodies!");
    }

    std::string missingIfStatement(const std::vector<std::string>& content)
    {
        return ERROR_MSG("'else' without if was found. Did you mean to write 'if'?");
    }

    std::string missingWhile(const std::vector<std::string>& content)
    {
        return ERROR_MSG("'while' word missing before condition");
    }

    std::string missingWhileExecutableBody(const std::vector<std::string>& content)
    {
        return ERROR_MSG("while statement without body");
    }

    std::string missingComparisonOperator(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Two expressions cannot be compared without operator. Did you mean to write '==', '!=', ... ?");
    }

    std::string missingExpressionOperator(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("missingExpressionOperator: invalid log");
        std::string mssg;
        mssg.append("'").append(content[0]).append("' was found but two expressions ")
            .append("should have an arithmetic operator in between");
        return ERROR_MSG(+mssg+);
    }

    std::string missingRightOperand(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("missingRightOperand: invalid log");
        return ERROR_MSG("An operand was expected but '" + content[0] + "' was found");
    }

    std::string missingLeftOperand(const std::vector<std::string>& content)
    {
        return ERROR_MSG("An operand was expected but '-' was found");
    }

    std::string missingBothOperands(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Two operands were expected when '+' was used");
    }

    std::string missingFloatConstant(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Missing float constant after '-'");
    }

    std::string missingLeftFactor(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Some value should be placed before * or /");
    }

    std::string missingRightFactor(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("missingRightFactor: invalid log");
        return ERROR_MSG("A factor was expected but '" + content[0] + "' was found");
    }

    std::string missingBothFactors(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Two operands factors are required when using * or /");
    }

    std::string genericSyntaxError(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Syntax Error. No structure was recognize");
    }
}
