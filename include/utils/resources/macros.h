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
#define INTEGER_OUT_OF_RANGE     0
#define FLOAT_OUT_OF_RANGE       1
#define INVALID_RESERVED_WORD    2
#define UNEXPECTED_CHARACTER     3
#define INTEGER_WITHOUT_SUFFIX   4
#define EXPONENT_WITHOUT_SIGN    5
#define FLOAT_WITHOUT_NUMBERS    6
#define STRING_LITERAL_WITH_ENDL 7
#define UNCLOSED_STRING_LITERAL  8
#define UNOPENED_COMMENT         9
#define UNCLOSED_COMMENT         10
#define INVALID_COLON            11
#define EXPECTED_BUT_FOUND       12
#define SYNTAX_ERROR             13

// ------------- Tables ------------ //
#define SYMBOL_ENTRY   0
#define SYMBOL_HEADER  1
#define LITERAL_ENTRY  2
#define LITERAL_HEADER 3

#endif //TPE_UTILS_MACROS_H