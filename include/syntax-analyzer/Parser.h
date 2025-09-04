/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INCLUDE_SYNTAX_ANALYZER_PARSER_H_INCLUDED
# define YY_YY_INCLUDE_SYNTAX_ANALYZER_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "include/syntax-analyzer/Parser.y"

    #include "tables/SymbolTable.h"

#line 53 "include/syntax-analyzer/Parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    ENDIF = 260,                   /* ENDIF  */
    DO = 261,                      /* DO  */
    WHILE = 262,                   /* WHILE  */
    RETURN = 263,                  /* RETURN  */
    PRINT = 264,                   /* PRINT  */
    UINT = 265,                    /* UINT  */
    FLOAT = 266,                   /* FLOAT  */
    POINTER_OP = 267,              /* POINTER_OP  */
    EQUAL_OP = 268,                /* EQUAL_OP  */
    GE_OP = 269,                   /* GE_OP  */
    LE_OP = 270,                   /* LE_OP  */
    ASSIGN_OP = 271,               /* ASSIGN_OP  */
    NOT_EQUAL_OP = 272,            /* NOT_EQUAL_OP  */
    IDENTIFIER = 273,              /* IDENTIFIER  */
    FLOAT_LITERAL = 274,           /* FLOAT_LITERAL  */
    INTEGER_LITERAL = 275,         /* INTEGER_LITERAL  */
    STRING_LITERAL = 276           /* STRING_LITERAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef 
    SymbolTable::EntryReference
 YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_SYNTAX_ANALYZER_PARSER_H_INCLUDED  */
