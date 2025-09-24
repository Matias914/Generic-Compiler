#include "utils/handler-resources/codes.h"
#include "utils/handler-resources/mappers.h"
#include "utils/handler-resources/builders.h"

using namespace Builders;

Builder Mapper::getBuilderForErrors(const int& code)
{
    switch (code)
    {
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
    case STATEMENT_WITHOUT_SEMICOLON:
        return statementWithoutSemicolon;
    case SYNTAX_ERROR:
        return genericSyntaxError;
    default:
        return defaultError;
    }
}

Builder Mapper::getBuilderForWarnings(const int& code)
{
    return truncatedIdentifier;
}

