#ifndef GC_UTILS_MACROS_H
#define GC_UTILS_MACROS_H

// ================================= //
//               Types               //
// ================================= //

#define WARNING   0
#define ERROR     1
#define TOKEN     2
#define STRUCTURE 3

// ================================= //
//               Codes               //
// ================================= //

// ------------ Warnings ----------- //
#define TRUNCATED_IDENTIFIER  0
#define STATEMENT_INTERPRETED 1
#define TRUNC_USELESS         2

// ------------- Errors ------------ //
#define CUSTOM_ERROR                    0
#define INTEGER_OUT_OF_RANGE            1
#define FLOAT_OUT_OF_RANGE              2
#define INVALID_RESERVED_WORD           3
#define UNEXPECTED_CHARACTER            4
#define INTEGER_WITHOUT_SUFFIX          5
#define EXPONENT_WITHOUT_SIGN           6
#define FLOAT_WITHOUT_NUMBERS           7
#define STRING_LITERAL_WITH_ENDL        8
#define UNCLOSED_STRING_LITERAL         9
#define UNOPENED_COMMENT                10
#define UNCLOSED_COMMENT                11
#define INVALID_COLON                   12
#define GLOBAL_SCOPE_STATEMENT          13
#define MISSING_PROGRAM_NAME            14
#define MISSING_CLOSING_BRACKET         15
#define MISSING_OPENING_BRACKET         16
#define MISSING_BOTH_BRACKETS           17
#define INVALID_PROGRAM_NESTING         18
#define INVALID_COMPOUND_NESTING        19
#define MISSING_VARIABLE                20
#define MISSING_FUNCTION_NAME           21
#define MISSING_PARAMETER_NAME          22
#define MISSING_PARAMETER_TYPE          23
#define MISSING_COMMA                   24
#define MISSING_SEMICOLON               25
#define MISSING_OPENING_PARENTHESIS     26
#define MISSING_CLOSING_PARENTHESIS     27
#define MISSING_BOTH_PARENTHESIS        28
#define MISSING_BOTH_PARENTHESIS_CALL   29
#define MISSING_BOTH_PARENTHESIS_TRUNC  30
#define MISSING_BOTH_PARENTHESIS_PRINT  31
#define MISSING_BOTH_PARENTHESIS_RETURN 32
#define MISSING_ARGUMENT                33
#define MISSING_RIGHT_SIDE_VALUES       34
#define MISSING_EQUALS                  35
#define MISSING_POINTED_PARAMETER       36
#define MISSING_ENDIF                   37
#define MISSING_IF_EXECUTABLE_BODY      38
#define MISSING_ELSE_EXECUTABLE_BODY    39
#define MISSING_BOTH_EXECUTABLE_BODY    40
#define MISSING_IF_STATEMENT            41
#define MISSING_WHILE                   42
#define MISSING_WHILE_EXECUTABLE_BODY   43
#define MISSING_COMPARISON_OPERATOR     44
#define MISSING_EXPRESSION_OPERATOR     45
#define MISSING_RIGHT_OPERAND           46
#define MISSING_LEFT_SUM_OPERAND        47
#define MISSING_LEFT_SUB_OPERAND        48
#define MISSING_BOTH_SUM_OPERANDS       49
#define MISSING_FLOAT_CONSTANT          50
#define MISSING_RIGHT_FACTOR            51
#define MISSING_LEFT_MUL_FACTOR         52
#define MISSING_LEFT_DIV_FACTOR         53
#define MISSING_BOTH_FACTORS            54
#define NOT_YET_IMPLEMENTED             55
#define SYNTAX_ERROR                    56
#define MULTIPLE_PROGRAMS_DECLARED      57
#define FUNCTION_REDECLARATION          58
#define VARIABLE_REDECLARATION          59
#define PARAMETER_REDECLARATION         60
#define VARIABLE_PREFIX_IN_DECLARATION  61
#define UNDECLARED_VARIABLE             62
#define UNDECLARED_FUNCTION             63
#define UNDECLARED_PARAMETER            64
#define PARAMETERS_LIMIT_EXCEEDED       65
#define PARAMETER_ALREADY_INSTANTIATED  66
#define INVALID_ARGUMENTS_NUMBER        67

// ------------- Structures ------------ //

#endif //GC_UTILS_MACROS_H