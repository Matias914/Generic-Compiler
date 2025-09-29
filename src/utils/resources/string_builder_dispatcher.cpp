#include "utils/resources/macros.h"
#include "utils/resources/builders.h"
#include "utils/resources/string_builder_dispatcher.h"
#include "syntax-analyzer/components/parser.h"

using namespace StringBuilders;

StringBuilder getBuilderForErrors(const int& code)
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
    case EXPECTED_BUT_FOUND:
        return expectedButFound;
    case SYNTAX_ERROR:
        return genericSyntaxError;
    default:
        return defaultError;
    }
}

StringBuilder getBuilderForTokens(const int& code)
{
    switch (code)
    {
    case YYEOF:
        return reportEndOfFile;
    case INVALID_TOKEN:
        return reportInvalidToken;
    default:
        return reportToken;
    }
}

StringBuilder getBuilderForTables(const int& code)
{
    switch (code)
    {
        case SYMBOL_ENTRY:
            return symbolTableEntry;
        case SYMBOL_HEADER:
            return symbolTableHeader;
        case LITERAL_ENTRY:
            return literalTableEntry;
        default:
            return literalTableHeader;
    }
}

namespace StringBuilderDispatcher
{
    StringBuilder getStringBuilder(const int& type, const int& code)
    {
        switch (type)
        {
        case WARNING:
            return truncatedIdentifier;
        case ERROR:
            return getBuilderForErrors(code);
        case TOKEN:
            return getBuilderForTokens(code);
        case STRUCTURE:
            return reportStructure;
        case TABLE:
            return getBuilderForTables(code);
        default:
            return defaultError;
        }
    }
}
