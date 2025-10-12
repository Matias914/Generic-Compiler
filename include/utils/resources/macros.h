#ifndef TPE_UTILS_MACROS_H
#define TPE_UTILS_MACROS_H

// ================================= //
//               Types               //
// ================================= //

#define WARNING   0
#define ERROR     1
#define TOKEN     2
#define STRUCTURE 3
#define TABLE     4

// ================================= //
//               Codes               //
// ================================= //

// ------------ Warnings ----------- //
#define TRUNCATED_VARIABLE 0

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
#define MISSING_POINTED_PARAMETER       35
#define MISSING_ENDIF                   36
#define MISSING_IF_EXECUTABLE_BODY      37
#define MISSING_ELSE_EXECUTABLE_BODY    38
#define MISSING_BOTH_EXECUTABLE_BODY    39
#define MISSING_IF_STATEMENT            40
#define MISSING_WHILE                   41
#define MISSING_WHILE_EXECUTABLE_BODY   42
#define MISSING_COMPARISON_OPERATOR     43
#define MISSING_EXPRESSION_OPERATOR     44
#define MISSING_RIGHT_OPERAND           45
#define MISSING_LEFT_OPERAND            46
#define MISSING_BOTH_OPERANDS           47
#define MISSING_FLOAT_CONSTANT          48
#define MISSING_RIGHT_FACTOR            49
#define MISSING_LEFT_FACTOR             50
#define MISSING_BOTH_FACTORS            51
#define NOT_YET_IMPLEMENTED             52
#define SYNTAX_ERROR                    53

// ------------- Tables ------------ //
#define SYMBOL_ENTRY   0
#define SYMBOL_HEADER  1
#define LITERAL_ENTRY  2
#define LITERAL_HEADER 3

#endif //TPE_UTILS_MACROS_H