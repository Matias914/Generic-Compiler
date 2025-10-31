#include "utils/resources/macros.h"
#include "utils/resources/builders.h"
#include "utils/resources/dispatcher.h"
#include "syntax-analyzer/components/parser.h"

using namespace StringBuilders::ErrorBuilders;

StringBuilder getBuilderForWarnings(const int& code)
{
    switch (code)
    {
    case TRUNCATED_IDENTIFIER:
        return truncatedIdentifier;
    case STATEMENT_INTERPRETED:
        return statementInterpreted;
    default:
        return defaultWarning;
    }
}

StringBuilder getBuilderForErrors(const int& code)
{
    switch (code)
    {
    case CUSTOM_ERROR:
        return customError;
    case INTEGER_OUT_OF_RANGE:
        return integerOutOfRange;
    case FLOAT_OUT_OF_RANGE:
        return floatOutOfRange;
    case INVALID_RESERVED_WORD:
        return invalidReservedWord;
    case UNEXPECTED_CHARACTER:
        return unexpectedCharacter;
    case INTEGER_WITHOUT_SUFFIX:
        return integerWithoutSuffix;
    case EXPONENT_WITHOUT_SIGN:
        return exponentWithoutSign;
    case FLOAT_WITHOUT_NUMBERS:
        return floatWithoutNumbers;
    case STRING_LITERAL_WITH_ENDL:
        return stringLiteralWithEndl;
    case UNCLOSED_STRING_LITERAL:
        return unclosedStringLiteral;
    case UNOPENED_COMMENT:
        return unopenedComment;
    case UNCLOSED_COMMENT:
        return unclosedComment;
    case INVALID_COLON:
        return invalidColon;
    case GLOBAL_SCOPE_STATEMENT:
        return globalScopeStatement;
    case MISSING_PROGRAM_NAME:
        return missingProgramName;
    case MISSING_CLOSING_BRACKET:
        return missingClosingBracket;
    case MISSING_OPENING_BRACKET:
        return missingOpeningBracket;
    case MISSING_BOTH_BRACKETS:
        return missingBothBrackets;
    case INVALID_PROGRAM_NESTING:
        return invalidProgramNesting;
    case INVALID_COMPOUND_NESTING:
        return invalidCompoundNesting;
    case MISSING_VARIABLE:
        return missingVariable;
    case MISSING_FUNCTION_NAME:
        return missingFunctionName;
    case MISSING_PARAMETER_NAME:
        return missingParameterName;
    case MISSING_PARAMETER_TYPE:
        return missingParameterType;
    case MISSING_COMMA:
        return missingComma;
    case MISSING_SEMICOLON:
        return missingSemicolon;
    case MISSING_OPENING_PARENTHESIS:
        return missingOpeningParenthesis;
    case MISSING_CLOSING_PARENTHESIS:
        return missingClosingParenthesis;
    case MISSING_BOTH_PARENTHESIS:
        return missingBothParenthesis;
    case MISSING_BOTH_PARENTHESIS_CALL:
        return missingBothParenthesisCall;
    case MISSING_BOTH_PARENTHESIS_TRUNC:
        return missingBothParenthesisTrunc;
    case MISSING_BOTH_PARENTHESIS_RETURN:
        return missingBothParenthesisReturn;
    case MISSING_ARGUMENT:
        return missingArgument;
    case MISSING_RIGHT_SIDE_VALUES:
        return missingRightSideValues;
    case MISSING_EQUALS:
        return missingEquals;
    case MISSING_POINTED_PARAMETER:
        return missingPointedParameter;
    case MISSING_ENDIF:
        return missingEndif;
    case MISSING_IF_EXECUTABLE_BODY:
        return missingIfExecutableBody;
    case MISSING_ELSE_EXECUTABLE_BODY:
        return missingElseExecutableBody;
    case MISSING_BOTH_EXECUTABLE_BODY:
        return missingBothExecutableBody;
    case MISSING_IF_STATEMENT:
        return missingIfStatement;
    case MISSING_WHILE:
        return missingWhile;
    case MISSING_WHILE_EXECUTABLE_BODY:
        return missingWhileExecutableBody;
    case MISSING_COMPARISON_OPERATOR:
        return missingComparisonOperator;
    case MISSING_EXPRESSION_OPERATOR:
        return missingExpressionOperator;
    case MISSING_RIGHT_OPERAND:
        return missingRightOperand;
    case MISSING_LEFT_SUM_OPERAND:
        return missingLeftSumOperand;
    case MISSING_LEFT_SUB_OPERAND:
        return missingLeftSubOperand;
    case MISSING_BOTH_SUM_OPERANDS:
        return missingBothSumOperands;
    case MISSING_FLOAT_CONSTANT:
        return missingFloatConstant;
    case MISSING_RIGHT_FACTOR:
        return missingRightFactor;
    case MISSING_LEFT_MUL_FACTOR:
        return missingLeftMulFactor;
    case MISSING_LEFT_DIV_FACTOR:
        return missingLeftDivFactor;
    case MISSING_BOTH_FACTORS:
        return missingBothFactors;
    case NOT_YET_IMPLEMENTED:
        return notYetImplemented;
    case SYNTAX_ERROR:
        return genericSyntaxError;
    case FUNCTION_REDECLARATION:
        return functionRedeclaration;
    case VARIABLE_REDECLARATION:
        return variableRedeclaration;
    case VARIABLE_PREFIX_IN_DECLARATION:
        return variablePrefixInDeclaration;
    case UNDECLARED_VARIABLE:
        return undeclaredVariable;
    case MULTIPLE_PROGRAMS_DECLARED:
        return multipleProgramsDeclared;
    default:
        return defaultError;
    }
}

namespace StringBuilderDispatcher
{
    StringBuilder getStringBuilder(const int& type, const int& code)
    {
        switch (type)
        {
        case WARNING:
            return getBuilderForWarnings(code);
        case ERROR:
            return getBuilderForErrors(code);
        default:
            return defaultError;
        }
    }
}
