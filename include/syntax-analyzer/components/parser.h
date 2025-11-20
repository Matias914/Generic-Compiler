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

#ifndef YY_YY_INCLUDE_SYNTAX_ANALYZER_COMPONENTS_PARSER_H_INCLUDED
# define YY_YY_INCLUDE_SYNTAX_ANALYZER_COMPONENTS_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "include/syntax-analyzer/components/yacc.y"

    #include "utils/SymbolTable.h"
    #include "utils/LiteralTable.h"

    struct Operator
    {
        char tid;
        int  pid;
    };

    struct Metadata
    {
        struct Expression
        {
            int type;
            int pid;
            bool assignable;
        } expression;
        struct Reference
        {
            int type;
            union
            {
                const SymbolTable::Entry*  sref;
                const LiteralTable::Entry* lref;
                int tref;
            };
        } reference;
    };

#line 80 "include/syntax-analyzer/components/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INVALID_TOKEN = 258,           /* INVALID_TOKEN  */
    WORD_IF = 259,                 /* WORD_IF  */
    WORD_ELSE = 260,               /* WORD_ELSE  */
    WORD_ENDIF = 261,              /* WORD_ENDIF  */
    WORD_DO = 262,                 /* WORD_DO  */
    WORD_WHILE = 263,              /* WORD_WHILE  */
    WORD_RETURN = 264,             /* WORD_RETURN  */
    WORD_PRINT = 265,              /* WORD_PRINT  */
    WORD_TRUNC = 266,              /* WORD_TRUNC  */
    WORD_UINT = 267,               /* WORD_UINT  */
    WORD_FLOAT = 268,              /* WORD_FLOAT  */
    WORD_CR = 269,                 /* WORD_CR  */
    OP_POINTER = 270,              /* OP_POINTER  */
    OP_EQUAL = 271,                /* OP_EQUAL  */
    OP_GE = 272,                   /* OP_GE  */
    OP_LE = 273,                   /* OP_LE  */
    OP_ASSIGN = 274,               /* OP_ASSIGN  */
    OP_NOT_EQUAL = 275,            /* OP_NOT_EQUAL  */
    IDENTIFIER = 276,              /* IDENTIFIER  */
    LITERAL_FLOAT = 277,           /* LITERAL_FLOAT  */
    LITERAL_UINT = 278,            /* LITERAL_UINT  */
    LITERAL_STRING = 279           /* LITERAL_STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 73 "include/syntax-analyzer/components/yacc.y"

    const SymbolTable::Entry*  sref;
    const LiteralTable::Entry* lref;
    Metadata metadata;
    int pid;
    Operator op;
    bool returnable;

#line 130 "include/syntax-analyzer/components/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_SYNTAX_ANALYZER_COMPONENTS_PARSER_H_INCLUDED  */
