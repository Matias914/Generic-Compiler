#include "utils/resources/StringBuilders.h"

#include <stdexcept>

#define   ERROR_MSG(x) "Error: " x "."
#define WARNING_MSG(x) "Warning: " x "."

namespace StringBuilders::ErrorBuilders
{
    // -------------------------------------- Warnings -------------------------------------- //

    std::string defaultWarning(const std::vector<std::string>& content)
    {
        return WARNING_MSG("Unknown Warning");
    }

    std::string truncatedIdentifier(const std::vector<std::string>& content)
    {
        if (content.size() != 2)
            throw std::runtime_error("\ntruncatedIdentifier: invalid log");
        std::string mssg;
        mssg.reserve(256);
        mssg.append("Identifier '")
            .append(content[0])
            .append("' was truncated to '")
            .append(content[1]).append("'. The maximum length is 20 characters");
        return WARNING_MSG(+mssg+);
    }

    std::string statementInterpreted(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nstatementInterpreted: invalid log");
        std::string mssg;
        mssg.append("'")
            .append(content[0])
            .append("' was found after an Identifier. This was interpreted as a statement")
            .append(" but you might have missed a {");
        return WARNING_MSG(+mssg+);
    }

    std::string truncUseless(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\ntruncUseless: invalid log");
        return WARNING_MSG("Useless trunc found. '" + content[0] + "' is already an integer");
    }

    std::string extraNumericConstants(const std::vector<std::string>& content)
    {
        return WARNING_MSG (
            "In multiple assignments, both sides should have the same amount of elements. "
            "The extra numeric constants will be ignored"
        );
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
            throw std::runtime_error("\nintegerOutOfRange: invalid log");
        return ERROR_MSG("Integer literal '" + content[0] + "' is out of range [0, 65535]");
    }

    std::string floatOutOfRange(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nfloatOutOfRange: invalid log");
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
            throw std::runtime_error("\ninvalidReservedWord: invalid log");
        return ERROR_MSG("'" + content[0] + "' is not a reserved word");
    }

    std::string unexpectedCharacter(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nunexpectedCharacter: invalid log");
        return ERROR_MSG("Unexpected character '" + content[0] + "' was found");
    }

    std::string integerWithoutSuffix(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nintegerWithoutSuffix: invalid log");
        return ERROR_MSG("Integer literal '" + content[0] + "' doesnt end with UI");
    }

    std::string exponentWithoutSign(const std::vector<std::string>& content)
    {
        return ERROR_MSG("An exponent should have a sign (after an F) and a value");
    }

    std::string floatWithoutNumbers(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nfloatWithoutNumbers: invalid log");
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
        return ERROR_MSG("Program without name was opened but it must be defined as IDENTIFIER { ... }");
    }

    std::string missingOpeningBracket(const std::vector<std::string>& content)
    {
        return ERROR_MSG("} was found but it no block was opened");
    }

    std::string missingClosingBracket(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nmissingClosingBrackets: invalid log");
        if (content[0].size() > 0)
            return ERROR_MSG("'" + content[0] + "' found but } was expected");

        return ERROR_MSG("Block was opened with '{' but never closed with }");
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
            throw std::runtime_error("\nmissingVariable: invalid log");
        return ERROR_MSG("Variable was expected as IDENTIFIER instead '" + content[0] + "' was found");
    }

    std::string missingFunctionName(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Function structure without name ended here but it must be defined with it");
    }

    std::string missingParameterName(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nmissingParameterName: invalid log");
        return ERROR_MSG("Formal parameter name was expected but '" + content[0] + "' was found");
    }

    std::string missingParameterType(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nmissingParameterType: invalid log");
        return ERROR_MSG("Formal parameter type was expected before '" + content[0] + "'");
    }

    std::string missingComma(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nmissingComma: invalid log");
        return ERROR_MSG(", was expected but '" + content[0] + "' was found");
    }

    std::string missingSemicolon(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nmissingSemicolon: invalid log");
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

    std::string missingBothParenthesisReturn(const std::vector<std::string>& content)
    {
        return ERROR_MSG("return statement without ( ) is not allowed");
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

    std::string missingEquals(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nmissingEquals: invalid log");
        return ERROR_MSG("In multiple assignments, = should be used instead of '" + content[0] + "'");
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
        return ERROR_MSG("Two expressions cannot be compared without operator. Did you mean to write '==', '=!', ... ?");
    }

    std::string missingExpressionOperator(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nmissingExpressionOperator: invalid log");
        std::string mssg;
        mssg.append("'").append(content[0]).append("' was found but two expressions ")
            .append("should have an arithmetic operator in between");
        return ERROR_MSG(+mssg+);
    }

    std::string missingRightOperand(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nmissingRightOperand: invalid log");
        return ERROR_MSG("An operand was expected but '" + content[0] + "' was found");
    }

    std::string missingLeftSumOperand(const std::vector<std::string>& content)
    {
        return ERROR_MSG("An operand was expected but '+' was found");
    }

    std::string missingLeftSubOperand(const std::vector<std::string>& content)
    {
        return ERROR_MSG("An operand was expected but '-' was found");
    }

    std::string missingBothSumOperands(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Two operands were expected when '+' was used");
    }

    std::string missingBothSubOperands(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Two operands were expected when '-' was used");
    }

    std::string missingLeftMulFactor(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Some value should be placed before *");
    }

    std::string missingLeftDivFactor(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Some value should be placed before /");
    }

    std::string missingRightFactor(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nmissingRightFactor: invalid log");
        return ERROR_MSG("A factor was expected but '" + content[0] + "' was found");
    }

    std::string missingBothFactors(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Two operands factors are required when using * or /");
    }

    std::string notYetImplemented(const std::vector<std::string>& content)
    {
        return ERROR_MSG("The type specified is not yet supported");
    }

    std::string invalidLambdaUse(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Lambda function cannot return a value. It does not specify a type");
    }

    std::string printSyntaxError(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Syntax Error. Invalid print statement");
    }

    std::string truncSyntaxError(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Syntax Error. Invalid trunc statement");
    }

    std::string ifSyntaxError(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Syntax Error. Invalid if statement");
    }

    std::string returnSyntaxError(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Syntax Error. Invalid return statement");
    }

    std::string doSyntaxError(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Syntax Error. Invalid do-while statement");
    }

    std::string genericSyntaxError(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Syntax Error. No structure was recognized");
    }

    std::string multipleProgramsDeclared(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\numultipleProgramsDeclared: invalid log");
        if (content[0].size() != 0)
            return ERROR_MSG("'" + content[0] + "' was declared, but having multiple programs is not valid");
        return ERROR_MSG("An unnamed program was declared, but having multiple programs is not valid");
    }

    std::string functionRedeclaration(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nfunctionRedeclaration: invalid log");
        return ERROR_MSG("Function name '" + content[0] + "' was already used in other declaration");
    }

    std::string variableRedeclaration(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nvariableRedeclaration: invalid log");
        return ERROR_MSG("Variable name '" + content[0] + "' was already used in other declaration");
    }

    std::string parameterRedeclaration(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nparameterRedeclaration: invalid log");
        return ERROR_MSG("Parameter name '" + content[0] + "' was already used in the defined scope");
    }

    std::string variablePrefixInDeclaration(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nvariablePrefixInDeclaration: invalid log");
        std::string prefix;
        for (int i = 1; i < content[0].size(); ++i)
            prefix += (content[0][i] == ':') ? '.' : content[0][i];
        return ERROR_MSG("Prefix '" + prefix + "' was found in declaration");
    }

    std::string undeclaredVariable(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nundeclaredVariable: invalid log");
        return ERROR_MSG("Variable '" + content[0] + "' was not declared");
    }

    std::string undeclaredFunction(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nundeclaredFunction: invalid log");
        return ERROR_MSG("Funtion '" + content[0] + "' was not declared");
    }

    std::string undeclaredParameter(const std::vector<std::string>& content)
    {
        if (content.size() != 2)
            throw std::runtime_error("\nundeclaredParameter: invalid log");
        return ERROR_MSG("'" + content[0] + "' is not a valid parameter for '" + content[1] + "'");
    }

    std::string parameterLimitExceeded(const std::vector<std::string>& content)
    {
        return "";
    }

    std::string parameterAlreadyInstantiated(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nparameterAlreadyInstantiated: invalid log");
        return ERROR_MSG("Parameter " + content[0] + " was already used");
    }

    std::string invalidArgumentsNumber(const std::vector<std::string>& content)
    {
        if (content.size() != 2)
            throw std::runtime_error("\ninvalidArgumentsNumber: invalid log");
        return ERROR_MSG(+content[0] + " arguments were found but " + content[1] + " parameters were declared");
    }

    std::string incompatibleTypes(const std::vector<std::string>& content)
    {
        if (content.size() != 4)
            throw std::runtime_error("\nincompatibleTypes: invalid log");
        std::string mssg;
        mssg.clear();
        mssg.append("Incompatible types in operation. Left side: '")
            .append(content[0])
            .append("' (")
            .append(content[1])
            .append(")")
            .append(", Right side: '")
            .append(content[2])
            .append("' (")
            .append(content[3])
            .append(")");
        return ERROR_MSG(+mssg+);
    }

    std::string incompatibleWithSemantic(const std::vector<std::string>& content)
    {
        if (content.size() != 3)
            throw std::runtime_error("\nincompatibleWithSemantic: invalid log");
        std::string mssg;
        mssg.clear();
        mssg.append("Argument not compatible with parameter semantic. Argument: '")
            .append(content[0])
            .append("', but Parameter: '")
            .append(content[1])
            .append("' with semantic ")
            .append(content[2]);
        return ERROR_MSG(+mssg+);
    }

    std::string returnIncompatible(const std::vector<std::string>& content)
    {
        if (content.size() != 2)
            throw std::runtime_error("\nreturnIncompatible: invalid log");
        return ERROR_MSG("Return with '" + content[0] + "' does not match '" + content[1] + "' type");
    }

    std::string returnWithoutScope(const std::vector<std::string>& content)
    {
        return ERROR_MSG("Return does not belong to any function scope");
    }

    std::string missingReturnStatement(const std::vector<std::string>& content)
    {
        if (content.size() != 1)
            throw std::runtime_error("\nmissingReturnStatement: invalid log");
        return ERROR_MSG("Function '" + content[0] + "' has a path without a return statemnt");
    }

    std::string noParamsGiven(const std::vector<std::string>& content)
    {
        return ERROR_MSG("A function must have at least one parameter");
    }
}
