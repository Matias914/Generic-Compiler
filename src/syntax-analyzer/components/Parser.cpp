/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 35 "include/syntax-analyzer/components/yacc.y"

#include "syntax-analyzer/components/Parser.h"
#include "syntax-analyzer/components/Translator.h"
#include "syntax-analyzer/components/StringPool.h"
#include "syntax-analyzer/components/SemanticActions.h"

#include "utils/resources/codes.h"
#include "code-generator/CodeGenerator.h"
#include "lexical-analyzer/LexicalAnalyzer.h"
#include "semantic-analyzer/SemanticAnalyzer.h"

#include <stack>
#include <iostream>

#define yylex LexicalAnalyzer::yylex

using namespace SyntaxAnalyzer;

// BackPatching

std::stack<int> STACK;

// Parser Functions

void yyerror(const char* s);
char mapWithTripleOperator(const int op);
CodeGenerator::Triples::Operand mapWithOperand(const Metadata::Reference& ref);

// Avoids Code Repetition
void createMultipleAssignmentTriple(const Metadata& m);
void createTruncateTriple(Metadata& result, const Metadata& operand);
void createArithmeticTriple(Metadata& r, const Metadata& o1, const Metadata& o2, char op);


#line 106 "src/syntax-analyzer/components/Parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syntax-analyzer/components/Parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INVALID_RWORD = 3,              /* INVALID_RWORD  */
  YYSYMBOL_INVALID_TOKEN = 4,              /* INVALID_TOKEN  */
  YYSYMBOL_WORD_IF = 5,                    /* WORD_IF  */
  YYSYMBOL_WORD_ELSE = 6,                  /* WORD_ELSE  */
  YYSYMBOL_WORD_ENDIF = 7,                 /* WORD_ENDIF  */
  YYSYMBOL_WORD_DO = 8,                    /* WORD_DO  */
  YYSYMBOL_WORD_WHILE = 9,                 /* WORD_WHILE  */
  YYSYMBOL_WORD_RETURN = 10,               /* WORD_RETURN  */
  YYSYMBOL_WORD_PRINT = 11,                /* WORD_PRINT  */
  YYSYMBOL_WORD_TRUNC = 12,                /* WORD_TRUNC  */
  YYSYMBOL_WORD_UINT = 13,                 /* WORD_UINT  */
  YYSYMBOL_WORD_FLOAT = 14,                /* WORD_FLOAT  */
  YYSYMBOL_WORD_CR = 15,                   /* WORD_CR  */
  YYSYMBOL_OP_POINTER = 16,                /* OP_POINTER  */
  YYSYMBOL_OP_EQUAL = 17,                  /* OP_EQUAL  */
  YYSYMBOL_OP_GE = 18,                     /* OP_GE  */
  YYSYMBOL_OP_LE = 19,                     /* OP_LE  */
  YYSYMBOL_OP_ASSIGN = 20,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_NOT_EQUAL = 21,              /* OP_NOT_EQUAL  */
  YYSYMBOL_IDENTIFIER = 22,                /* IDENTIFIER  */
  YYSYMBOL_LITERAL_FLOAT = 23,             /* LITERAL_FLOAT  */
  YYSYMBOL_LITERAL_UINT = 24,              /* LITERAL_UINT  */
  YYSYMBOL_LITERAL_STRING = 25,            /* LITERAL_STRING  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* '='  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_global = 41,                    /* global  */
  YYSYMBOL_global_statement = 42,          /* global_statement  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_unnamed_program_tail = 44,      /* unnamed_program_tail  */
  YYSYMBOL_program_head = 45,              /* program_head  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_program_tail = 47,              /* program_tail  */
  YYSYMBOL_program_statements = 48,        /* program_statements  */
  YYSYMBOL_program_statement = 49,         /* program_statement  */
  YYSYMBOL_declarative_stmt = 50,          /* declarative_stmt  */
  YYSYMBOL_51_3 = 51,                      /* $@3  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_variable_list = 53,             /* variable_list  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_unnamed_function_declaration_middle = 56, /* unnamed_function_declaration_middle  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_unnamed_function_declaration_tail = 59, /* unnamed_function_declaration_tail  */
  YYSYMBOL_function_declaration_middle = 60, /* function_declaration_middle  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_62_9 = 62,                      /* $@9  */
  YYSYMBOL_function_declaration_tail = 63, /* function_declaration_tail  */
  YYSYMBOL_formal_parameter_list = 64,     /* formal_parameter_list  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_formal_parameter = 66,          /* formal_parameter  */
  YYSYMBOL_parameter_semantics = 67,       /* parameter_semantics  */
  YYSYMBOL_function_body = 68,             /* function_body  */
  YYSYMBOL_return = 69,                    /* return  */
  YYSYMBOL_executable_stmt = 70,           /* executable_stmt  */
  YYSYMBOL_assignment = 71,                /* assignment  */
  YYSYMBOL_assignment_head = 72,           /* assignment_head  */
  YYSYMBOL_assignment_tail = 73,           /* assignment_tail  */
  YYSYMBOL_print = 74,                     /* print  */
  YYSYMBOL_75_11 = 75,                     /* $@11  */
  YYSYMBOL_print_end = 76,                 /* print_end  */
  YYSYMBOL_multiple_assignments = 77,      /* multiple_assignments  */
  YYSYMBOL_assignment_list = 78,           /* assignment_list  */
  YYSYMBOL_assignment_end = 79,            /* assignment_end  */
  YYSYMBOL_left_variable = 80,             /* left_variable  */
  YYSYMBOL_81_12 = 81,                     /* $@12  */
  YYSYMBOL_extra_numeric_constants = 82,   /* extra_numeric_constants  */
  YYSYMBOL_83_13 = 83,                     /* $@13  */
  YYSYMBOL_84_14 = 84,                     /* $@14  */
  YYSYMBOL_invocation = 85,                /* invocation  */
  YYSYMBOL_function_invocation_head = 86,  /* function_invocation_head  */
  YYSYMBOL_invocation_setup = 87,          /* invocation_setup  */
  YYSYMBOL_function_invocation_tail = 88,  /* function_invocation_tail  */
  YYSYMBOL_real_parameter_list = 89,       /* real_parameter_list  */
  YYSYMBOL_real_parameter_list_setup = 90, /* real_parameter_list_setup  */
  YYSYMBOL_real_parameter = 91,            /* real_parameter  */
  YYSYMBOL_lambda_invocation_head = 92,    /* lambda_invocation_head  */
  YYSYMBOL_93_15 = 93,                     /* $@15  */
  YYSYMBOL_lambda_invocation_middle = 94,  /* lambda_invocation_middle  */
  YYSYMBOL_95_16 = 95,                     /* $@16  */
  YYSYMBOL_96_17 = 96,                     /* $@17  */
  YYSYMBOL_97_18 = 97,                     /* $@18  */
  YYSYMBOL_lambda_missing_closing_bracket = 98, /* lambda_missing_closing_bracket  */
  YYSYMBOL_lambda_invocation_tail = 99,    /* lambda_invocation_tail  */
  YYSYMBOL_lambda_real_parameter = 100,    /* lambda_real_parameter  */
  YYSYMBOL_if = 101,                       /* if  */
  YYSYMBOL_if_word = 102,                  /* if_word  */
  YYSYMBOL_if_head = 103,                  /* if_head  */
  YYSYMBOL_condition_body_setup = 104,     /* condition_body_setup  */
  YYSYMBOL_condition_setup = 105,          /* condition_setup  */
  YYSYMBOL_then_body_setup = 106,          /* then_body_setup  */
  YYSYMBOL_do_while = 107,                 /* do_while  */
  YYSYMBOL_108_19 = 108,                   /* $@19  */
  YYSYMBOL_do_while_head = 109,            /* do_while_head  */
  YYSYMBOL_do_body = 110,                  /* do_body  */
  YYSYMBOL_111_20 = 111,                   /* $@20  */
  YYSYMBOL_do_while_tail = 112,            /* do_while_tail  */
  YYSYMBOL_executable_body = 113,          /* executable_body  */
  YYSYMBOL_executable_statements = 114,    /* executable_statements  */
  YYSYMBOL_opt_trunc_constant = 115,       /* opt_trunc_constant  */
  YYSYMBOL_trunc_constant = 116,           /* trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 117,       /* opt_trunc_variable  */
  YYSYMBOL_trunc_variable = 118,           /* trunc_variable  */
  YYSYMBOL_trunc_expression = 119,         /* trunc_expression  */
  YYSYMBOL_condition = 120,                /* condition  */
  YYSYMBOL_comparison = 121,               /* comparison  */
  YYSYMBOL_comparison_operator = 122,      /* comparison_operator  */
  YYSYMBOL_expression = 123,               /* expression  */
  YYSYMBOL_expression_setup = 124,         /* expression_setup  */
  YYSYMBOL_term = 125,                     /* term  */
  YYSYMBOL_positive_term = 126,            /* positive_term  */
  YYSYMBOL_negative_term = 127,            /* negative_term  */
  YYSYMBOL_factor = 128,                   /* factor  */
  YYSYMBOL_positive_factor = 129,          /* positive_factor  */
  YYSYMBOL_negative_factor = 130,          /* negative_factor  */
  YYSYMBOL_numeric_constant = 131,         /* numeric_constant  */
  YYSYMBOL_positive_constant = 132,        /* positive_constant  */
  YYSYMBOL_negative_constant = 133,        /* negative_constant  */
  YYSYMBOL_variable = 134                  /* variable  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1083

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  275
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  418

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    31,    37,    35,    30,    36,    39,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      34,    32,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   127,   127,   128,   129,   133,   137,   141,   143,   142,
     151,   155,   163,   167,   171,   182,   181,   197,   202,   207,
     217,   218,   222,   226,   230,   237,   244,   251,   259,   269,
     273,   278,   284,   283,   293,   292,   308,   312,   317,   316,
     324,   332,   336,   347,   346,   353,   352,   363,   369,   382,
     381,   390,   389,   402,   413,   428,   429,   431,   430,   438,
     444,   450,   458,   463,   469,   476,   486,   496,   500,   504,
     516,   530,   547,   565,   582,   600,   616,   632,   648,   659,
     660,   661,   662,   663,   664,   665,   671,   694,   703,   720,
     727,   740,   753,   766,   779,   794,   793,   800,   808,   810,
     818,   824,   832,   840,   849,   856,   865,   876,   877,   881,
     888,   889,   895,   904,   908,   920,   920,   927,   929,   929,
     933,   935,   934,   944,   945,   950,   951,   961,   982,  1003,
    1021,  1029,  1039,  1043,  1049,  1059,  1067,  1105,  1118,  1117,
    1130,  1129,  1136,  1135,  1142,  1144,  1143,  1154,  1163,  1218,
    1219,  1225,  1229,  1236,  1247,  1262,  1282,  1302,  1323,  1344,
    1352,  1361,  1369,  1391,  1399,  1406,  1427,  1434,  1451,  1468,
    1488,  1495,  1510,  1532,  1537,  1536,  1545,  1556,  1569,  1585,
    1594,  1593,  1605,  1606,  1617,  1621,  1629,  1635,  1639,  1646,
    1647,  1653,  1657,  1664,  1671,  1681,  1690,  1703,  1718,  1725,
    1745,  1768,  1791,  1814,  1826,  1832,  1842,  1851,  1866,  1870,
    1878,  1885,  1896,  1919,  1927,  1934,  1938,  1942,  1946,  1950,
    1954,  1963,  1967,  1979,  1986,  1995,  1999,  2007,  2011,  2019,
    2023,  2027,  2034,  2045,  2049,  2056,  2060,  2064,  2068,  2072,
    2076,  2080,  2084,  2088,  2092,  2100,  2111,  2115,  2119,  2123,
    2127,  2131,  2139,  2147,  2154,  2161,  2170,  2184,  2188,  2195,
    2210,  2214,  2221,  2225,  2232,  2240,  2247,  2263,  2272,  2286,
    2290,  2297,  2302,  2310,  2321,  2328
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INVALID_RWORD",
  "INVALID_TOKEN", "WORD_IF", "WORD_ELSE", "WORD_ENDIF", "WORD_DO",
  "WORD_WHILE", "WORD_RETURN", "WORD_PRINT", "WORD_TRUNC", "WORD_UINT",
  "WORD_FLOAT", "WORD_CR", "OP_POINTER", "OP_EQUAL", "OP_GE", "OP_LE",
  "OP_ASSIGN", "OP_NOT_EQUAL", "IDENTIFIER", "LITERAL_FLOAT",
  "LITERAL_UINT", "LITERAL_STRING", "'{'", "'}'", "';'", "'('", "','",
  "')'", "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'.'", "$accept",
  "global", "global_statement", "$@1", "unnamed_program_tail",
  "program_head", "$@2", "program_tail", "program_statements",
  "program_statement", "declarative_stmt", "$@3", "$@4", "variable_list",
  "$@5", "type", "unnamed_function_declaration_middle", "$@6", "$@7",
  "unnamed_function_declaration_tail", "function_declaration_middle",
  "$@8", "$@9", "function_declaration_tail", "formal_parameter_list",
  "$@10", "formal_parameter", "parameter_semantics", "function_body",
  "return", "executable_stmt", "assignment", "assignment_head",
  "assignment_tail", "print", "$@11", "print_end", "multiple_assignments",
  "assignment_list", "assignment_end", "left_variable", "$@12",
  "extra_numeric_constants", "$@13", "$@14", "invocation",
  "function_invocation_head", "invocation_setup",
  "function_invocation_tail", "real_parameter_list",
  "real_parameter_list_setup", "real_parameter", "lambda_invocation_head",
  "$@15", "lambda_invocation_middle", "$@16", "$@17", "$@18",
  "lambda_missing_closing_bracket", "lambda_invocation_tail",
  "lambda_real_parameter", "if", "if_word", "if_head",
  "condition_body_setup", "condition_setup", "then_body_setup", "do_while",
  "$@19", "do_while_head", "do_body", "$@20", "do_while_tail",
  "executable_body", "executable_statements", "opt_trunc_constant",
  "trunc_constant", "opt_trunc_variable", "trunc_variable",
  "trunc_expression", "condition", "comparison", "comparison_operator",
  "expression", "expression_setup", "term", "positive_term",
  "negative_term", "factor", "positive_factor", "negative_factor",
  "numeric_constant", "positive_constant", "negative_constant", "variable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-312)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-233)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     671,  -312,   -18,  -312,   417,   456,    57,  -312,  -312,    47,
    -312,  -312,   130,   702,  -312,  -312,  -312,   147,  -312,  -312,
    -312,   953,  -312,  -312,  -312,    50,   949,   135,  -312,   368,
    -312,   994,    35,  -312,   -12,    16,    34,   971,    41,  -312,
    -312,   931,   271,   187,   349,   634,  -312,  -312,   203,    11,
     267,  -312,   364,   413,  -312,  -312,  -312,  -312,    73,    96,
     310,  -312,   418,   802,   106,  -312,  -312,   139,   109,  -312,
     214,    73,  -312,   555,  -312,  -312,  -312,  -312,   414,   953,
    -312,   580,  -312,  -312,   197,   994,   931,   136,   799,   994,
     889,    28,   552,   897,  -312,  -312,   221,   222,   474,   234,
    -312,   258,   129,   347,   234,  -312,   989,  -312,   931,   583,
     436,  -312,   203,  -312,  -312,  -312,  -312,  -312,  -312,    73,
    -312,  -312,  -312,  -312,  -312,  -312,   928,   928,  -312,  -312,
     270,   521,   525,   364,   291,   330,   616,   624,  -312,   287,
     290,   398,   822,   293,   276,   842,  -312,  -312,  -312,   722,
    -312,  -312,  -312,   298,  -312,  -312,   677,  -312,  -312,    60,
     234,  -312,  -312,   953,  -312,  -312,  -312,   315,  -312,   334,
      29,  -312,  -312,  -312,   994,   912,  -312,  -312,  -312,   470,
     994,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
     494,   324,  -312,  -312,   920,   989,   989,  -312,   332,  -312,
      49,  -312,  -312,   320,  -312,   340,   631,  -312,  -312,  -312,
    -312,   371,    73,  -312,   185,   598,  -312,  -312,  -312,  -312,
     190,  -312,  -312,  -312,  -312,  -312,  -312,   203,  -312,  -312,
     203,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,   207,   238,  -312,  -312,   742,
    -312,  -312,  -312,   762,  -312,  -312,  -312,  -312,   865,  -312,
    -312,  -312,   199,  -312,   453,  -312,   486,  -312,    73,    73,
    -312,  -312,  -312,  -312,  -312,    12,   361,   407,   374,  -312,
     380,  -312,    90,  -312,  -312,  -312,  -312,   260,  -312,  -312,
     371,   149,   169,    53,  -312,  -312,   371,   650,   371,  -312,
      36,  -312,  -312,  -312,  -312,  -312,  -312,   384,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  1023,  -312,  -312,   483,
     394,  -312,  -312,   448,  -312,   448,  -312,  -312,   274,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,   401,
    -312,   406,    79,  -312,  -312,  -312,  -312,  -312,   371,   371,
    -312,  -312,  -312,  -312,  -312,  1054,  -312,   110,  1031,   394,
    -312,   862,  -312,   273,  -312,   394,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  1046,   665,  -312,   393,  -312,
    -312,  -312,    73,   440,   130,  -312,   277,   394,  -312,   782,
    -312,  -312,  -312,   452,   130,   437,   466,    10,  -312,  -312,
     110,  -312,  -312,  -312,  -312,  -312,  -312,  -312,    44,  -312,
    -312,   110,  -312,   110,  -312,  -312,  -312,  -312
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     4,     0,   154,     0,     0,     0,    41,    42,   274,
       8,    10,     0,     0,     2,     7,     5,     0,    84,     6,
      79,     0,    83,    80,    81,     0,     0,     0,    82,     0,
      85,     0,     0,    11,     0,     0,     0,     0,   274,   272,
     271,     0,     0,     0,     0,     0,   261,   263,   229,     0,
       0,   221,   233,   234,   243,   250,   260,   262,   259,     0,
       0,    15,     0,     0,     0,     1,     3,     0,   274,    34,
       0,    36,    86,     0,   124,   123,   131,   127,   135,     0,
     132,     0,   126,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,   173,   180,     0,     0,     0,
     107,     0,     0,   115,     0,   176,     0,    78,     0,     0,
       0,   224,     0,   223,   268,   273,   264,   265,   267,   266,
     255,   253,   257,   258,   256,   254,     0,     0,    74,    77,
      73,     0,     0,   222,     0,     0,     0,     0,    97,     0,
       0,   232,     0,     0,     0,     0,    13,     9,    24,     0,
      20,    22,    23,     0,    30,    32,     0,    31,    29,     0,
       0,    90,    89,     0,   130,   134,   137,     0,   153,     0,
       0,   152,   151,   157,     0,     0,   155,   170,   172,   160,
     163,   211,   210,   213,   215,   217,   218,   216,   219,   220,
       0,     0,   188,   189,     0,     0,     0,   106,     0,   274,
       0,   275,   105,     0,   104,     0,     0,   192,   191,   269,
     270,     0,   116,   175,     0,     0,   207,   206,    72,    75,
       0,   240,   238,   239,   237,    76,   226,   230,   225,   228,
     231,   227,   244,   242,   235,   245,   241,   236,   251,   249,
     246,   252,   248,   247,    95,     0,     0,    19,    16,     0,
     128,    28,    25,     0,    14,    12,    21,   138,     0,    66,
      61,    45,     0,    35,    57,    55,     0,    40,    37,    39,
     133,   136,   166,   209,   208,     0,   162,     0,     0,   159,
       0,   214,   232,   186,   185,   184,   190,     0,   181,    87,
       0,     0,     0,     0,   101,   100,     0,     0,     0,   110,
       0,   183,   182,   205,   204,    71,    70,    99,    92,    91,
      94,    93,    18,    17,    27,    26,     0,    51,    33,    57,
       0,    60,    59,     0,    43,     0,    64,    65,     0,   169,
     168,   165,   158,   167,   156,   161,   164,   179,   178,     0,
     112,   111,     0,   196,   195,   117,   103,   102,     0,     0,
     119,   114,   113,    98,    96,     0,   139,     0,     0,     0,
      49,     0,    46,     0,    56,     0,    58,    63,    62,   109,
     108,   194,   193,   120,   122,     0,     0,   144,     0,   150,
     149,   198,   197,     0,   145,    52,     0,     0,    68,     0,
      48,    47,    44,     0,   147,     0,     0,     0,   148,   142,
       0,    54,    53,    50,    69,    67,   140,   203,     0,   202,
     201,     0,   146,     0,   200,   199,   143,   141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,  -312,   491,  -312,  -312,   297,  -312,  -312,  -141,  -146,
     299,  -312,  -312,  -312,  -312,    15,  -312,  -312,  -312,   140,
    -312,  -312,  -312,   120,   257,  -312,    63,  -312,  -290,  -312,
       7,  -312,  -312,  -312,  -312,  -312,  -312,  -312,   -89,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,     9,  -312,  -312,  -312,
    -312,   -58,    77,  -312,  -312,  -312,  -312,  -312,  -312,  -282,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,   323,   -61,  -311,   -84,  -312,  -312,  -312,    97,
     -27,   434,  -312,    27,  -312,   -16,   477,  -312,   150,   111,
     133,  -197,   -94,   125,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    13,    14,    63,   147,   148,   142,   248,   149,   150,
     151,   258,   156,    70,   160,    17,   263,   365,   320,   362,
     318,   387,   359,   385,   264,   325,   265,   266,   363,    18,
     152,    20,    21,    72,    22,   307,   354,    23,   102,   299,
     103,   104,   297,   298,   349,    24,    46,    26,    77,    78,
      79,    80,    47,   316,   356,   413,   411,   400,   357,   377,
     378,    28,    29,    87,    88,    89,   177,    30,    35,    31,
      95,   196,   213,    96,   194,   379,   207,   380,   381,    48,
     214,    91,   190,    92,    50,    51,    52,    53,   121,    54,
      55,   208,    56,    57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   249,    90,   256,   253,   358,   293,    19,   209,    25,
      33,   409,   128,    32,   211,   329,   105,    71,   206,   330,
      19,   165,    25,  -232,   169,   106,   113,    64,   178,   181,
     273,    32,    49,  -232,  -232,  -232,    97,   351,    94,   129,
      25,   410,   130,   119,   375,   414,   131,   132,    73,   101,
     290,    74,   117,    81,   343,    98,    64,  -115,    59,   182,
     274,   267,   107,    32,   109,    99,   352,   100,   110,   386,
      62,  -115,    25,    61,   101,   415,    62,    27,    75,    99,
     371,   100,   199,   101,   344,    32,    60,   141,   101,    32,
      27,  -212,    94,    32,    25,   342,    94,   386,    25,   200,
     193,    64,    25,   256,   212,   270,    81,   256,    27,   209,
     372,   291,   101,   275,   277,   228,   231,   209,   412,   280,
     118,  -212,   376,    64,   138,   131,   132,   300,   153,   416,
     202,   417,   199,    39,    40,   215,    82,   171,   155,   112,
      27,   203,    32,     7,     8,    32,   205,   112,    67,    32,
     340,    25,    39,    40,    25,   122,   122,   204,    25,   268,
     269,   203,    27,    83,   172,   205,    27,   154,   287,    68,
      27,   262,    39,    40,    32,    32,    69,   123,   123,   293,
      32,    94,    94,    25,    25,   205,   301,    94,   114,    25,
      81,   305,    39,    40,    32,   125,   209,   209,   209,   342,
     321,   286,   209,    25,   209,   205,   339,   341,   308,    38,
     115,   116,   345,   302,   350,   157,    12,   282,   306,    27,
     389,   322,    27,   221,   223,   168,    27,   210,   227,   230,
     195,   233,   236,   239,   242,   309,   -38,   122,   122,   310,
     126,   127,   158,   256,   159,   122,   122,   122,   122,    32,
     197,    27,    27,    32,   209,   209,   199,    27,    25,   123,
     123,   337,    25,   209,   373,   374,   311,   123,   123,   123,
     123,    27,   111,   262,   390,   367,   222,   224,   401,    37,
     201,   328,   209,    37,   234,   237,   240,   243,   338,    38,
      39,    40,   232,    38,    39,    40,   368,    15,   225,    16,
      12,   391,   209,    37,   251,   402,   209,    43,    44,    45,
      15,   139,    16,    38,    39,    40,    32,   209,   244,   209,
      12,   245,    37,   193,   250,    25,    27,    43,   210,   257,
      27,   235,    38,    39,    40,   140,   210,   271,   262,    12,
     262,   272,    37,    39,    40,    42,    43,    44,    45,   292,
     120,   283,    38,    39,    40,    32,   205,   382,    32,    12,
     289,    32,   193,   115,    25,   286,    43,    25,   331,    84,
      25,    38,    39,    40,    85,    32,   397,    99,    12,   100,
      37,   335,   286,   203,    25,    43,   364,   336,   366,    32,
      38,    39,    40,    27,    39,    40,   408,    86,    25,    64,
     382,   134,   135,    42,    43,    44,    45,   205,   332,    64,
     333,   382,   353,   382,   334,   210,   210,   210,    34,   143,
     361,   210,  -177,   210,   398,  -177,  -174,  -177,  -177,   246,
    -129,   369,    27,   131,   132,    27,   370,   218,    27,  -177,
    -129,  -129,  -129,  -177,   163,   164,  -177,  -129,  -232,  -129,
     136,   137,    27,  -129,  -129,  -129,  -129,    36,  -232,  -232,
    -232,     7,     8,   259,   219,   407,    27,   220,    37,   399,
     260,   131,   132,   210,   210,   198,   278,   279,    38,    39,
      40,   406,   210,   323,   324,    41,   -88,   326,   199,    39,
      40,    42,    43,    44,    45,   281,   -88,   -88,   -88,     7,
       8,   210,   205,   -88,    66,   392,    37,   403,   327,   -88,
     -88,   -88,   -88,   323,   360,   319,    38,    39,    40,   288,
     170,   210,   226,    12,     0,   210,   229,   133,     0,    42,
      43,    44,    45,    37,     0,     0,   210,    37,   210,     0,
       0,     0,     0,    38,    39,    40,     0,    38,    39,    40,
      12,     0,     0,   183,    12,     0,   161,    43,    44,    45,
       0,    43,    44,    45,  -232,     0,     0,  -232,     0,   184,
     185,   186,     0,   187,  -232,  -232,  -232,  -232,  -232,  -232,
       0,   166,     0,   162,   216,   188,   189,   131,   132,     0,
     131,   132,  -232,     0,     0,  -232,   167,     0,     0,   303,
       0,     0,  -232,  -232,  -232,  -232,  -232,  -232,     0,     0,
    -232,     0,     0,     0,   217,   131,   132,   238,   131,   132,
    -232,  -232,  -232,     0,     0,   241,     0,     0,    37,   304,
       0,     0,   294,   131,   132,   124,    37,     0,    38,    39,
      40,     0,     0,  -118,     0,    12,    38,    39,    40,     0,
       0,   346,    43,    12,  -118,  -118,    38,    39,    40,   295,
      43,   296,  -121,    12,     0,     0,   395,  -118,     0,     0,
      43,     1,     2,  -121,  -121,     0,     3,     0,   347,     4,
     348,     5,     6,     0,     7,     8,  -121,   199,    39,    40,
       7,     8,   259,     9,   396,     0,     0,    10,    11,   260,
      12,   205,    65,     2,     0,     0,     0,     3,   261,     0,
       4,     0,     5,     6,     0,     7,     8,     0,     0,     0,
       0,     0,   254,   144,     9,     0,     0,     3,    10,    11,
       4,    12,     5,     6,     0,     7,     8,     0,     0,     0,
       0,     0,   312,   144,     9,     0,     0,     3,   145,   255,
       4,    12,     5,     6,     0,     7,     8,     0,     0,     0,
       0,     0,   314,   144,     9,     0,     0,     3,   145,   313,
       4,    12,     5,     6,     0,     7,     8,     0,     0,     0,
       0,     0,   404,   144,     9,     0,     0,     3,   145,   315,
       4,    12,     5,     6,     0,     7,     8,     0,     0,     0,
     173,     0,   174,   144,     9,   175,   176,     3,   145,   405,
       4,    12,     5,     6,     0,     7,     8,     0,     0,     0,
       0,     0,     0,   144,     9,     0,     0,     3,   145,   146,
       4,    12,     5,     6,     0,     7,     8,     0,     0,     0,
       0,     0,     0,   144,     9,     0,     0,     3,   145,   247,
       4,    12,     5,     6,     0,     7,     8,     0,     0,     0,
       0,     0,     0,   144,     9,     0,     0,     3,   145,   252,
       4,    12,     5,     6,     0,     7,     8,     0,     7,     8,
     259,     0,     0,     0,     9,     0,     0,   260,   145,   388,
     179,    12,     0,     0,  -171,   180,   317,  -171,   191,  -171,
    -171,     0,     3,     0,     0,     4,     0,     5,     6,     0,
       0,  -171,     0,   276,     0,  -171,     0,     3,  -171,    38,
       4,   284,     5,     6,   192,     3,    12,     0,     4,     0,
       5,     6,     0,     0,    38,     0,     0,     0,    93,     0,
      37,    12,    38,    37,     7,     8,     0,   285,     0,    12,
      38,    39,    40,    38,    39,    40,     0,    12,     0,     0,
      12,    37,     0,     0,    43,    37,    42,    43,    44,    45,
       0,    38,    39,    40,     0,    38,    39,    40,    12,     0,
      76,     0,    12,    37,    42,    43,    44,    45,    42,    43,
      44,    45,     0,    38,    39,    40,     0,     0,     0,     3,
     108,    37,     4,     0,     5,     6,    42,    43,    44,    45,
       0,    38,    39,    40,     0,     0,    38,     0,    86,     0,
      93,     0,     0,    12,    42,    43,    44,    45,     3,     0,
       0,     4,     0,     5,     6,     0,     3,     0,     0,     4,
       0,     5,     6,     0,     0,    38,     0,     0,     0,   355,
       0,     3,    12,    38,     4,     0,     5,     6,   383,     3,
     384,     0,     4,     0,     5,     6,     0,     0,    38,     0,
       0,     0,     0,   393,     0,   394,    38,     0,     0,     0,
       0,     0,     0,    12
};

static const yytype_int16 yycheck[] =
{
       0,   142,    29,   149,   145,   316,   203,     0,   102,     0,
      28,     1,     1,    13,   103,     3,    28,    17,   102,     7,
      13,    79,    13,    12,    85,     9,    42,    12,    89,     1,
       1,    31,     5,    22,    23,    24,     1,     1,    31,    28,
      31,    31,    31,    43,   355,     1,    35,    36,    21,    39,
       1,     1,    43,    26,     1,    20,    41,    22,     1,    31,
      31,     1,    28,    63,    37,    30,    30,    32,    41,   359,
      29,    22,    63,    26,    39,    31,    29,     0,    28,    30,
       1,    32,    22,    39,    31,    85,    29,    60,    39,    89,
      13,     1,    85,    93,    85,   292,    89,   387,    89,    99,
      93,    86,    93,   249,   104,   163,    79,   253,    31,   203,
      31,   200,    39,   174,   175,   131,   132,   211,   400,   180,
      43,    31,    12,   108,    28,    35,    36,   211,    22,   411,
       1,   413,    22,    23,    24,   108,     1,     1,    29,    42,
      63,    12,   142,    13,    14,   145,    36,    50,     1,   149,
       1,   142,    23,    24,   145,    44,    45,    28,   149,   159,
     160,    12,    85,    28,    28,    36,    89,    28,   195,    22,
      93,   156,    23,    24,   174,   175,    29,    44,    45,   376,
     180,   174,   175,   174,   175,    36,     1,   180,     1,   180,
     163,     1,    23,    24,   194,    45,   290,   291,   292,   396,
       1,   194,   296,   194,   298,    36,   290,   291,     1,    22,
      23,    24,   296,    28,   298,     1,    29,   190,    28,   142,
     361,    22,   145,   126,   127,    28,   149,   102,   131,   132,
       9,   134,   135,   136,   137,    28,    22,   126,   127,     1,
      37,    38,    28,   389,    30,   134,   135,   136,   137,   249,
      28,   174,   175,   253,   348,   349,    22,   180,   249,   126,
     127,     1,   253,   357,   348,   349,    28,   134,   135,   136,
     137,   194,     1,   258,     1,     1,   126,   127,     1,    12,
      22,   266,   376,    12,   134,   135,   136,   137,    28,    22,
      23,    24,     1,    22,    23,    24,    22,     0,    28,     0,
      29,    28,   396,    12,    28,    28,   400,    36,    37,    38,
      13,     1,    13,    22,    23,    24,   316,   411,    31,   413,
      29,    31,    12,   316,    31,   316,   249,    36,   203,    31,
     253,     1,    22,    23,    24,    25,   211,    22,   323,    29,
     325,     7,    12,    23,    24,    35,    36,    37,    38,    29,
       1,    27,    22,    23,    24,   355,    36,   357,   358,    29,
      28,   361,   355,    23,   355,   358,    36,   358,     7,     1,
     361,    22,    23,    24,     6,   375,   376,    30,    29,    32,
      12,     7,   375,    12,   375,    36,   323,     7,   325,   389,
      22,    23,    24,   316,    23,    24,   396,    29,   389,   384,
     400,    37,    38,    35,    36,    37,    38,    36,     1,   394,
       3,   411,    28,   413,     7,   290,   291,   292,     1,     1,
      26,   296,     5,   298,    31,     8,     9,    10,    11,    31,
      12,    30,   355,    35,    36,   358,    30,     1,   361,    22,
      22,    23,    24,    26,    30,    31,    29,    29,    12,    31,
      37,    38,   375,    35,    36,    37,    38,     1,    22,    23,
      24,    13,    14,    15,    28,    28,   389,    31,    12,    29,
      22,    35,    36,   348,   349,     1,     6,     7,    22,    23,
      24,    29,   357,    30,    31,    29,    12,     1,    22,    23,
      24,    35,    36,    37,    38,     1,    22,    23,    24,    13,
      14,   376,    36,    29,    13,   365,    12,   387,    22,    35,
      36,    37,    38,    30,    31,   258,    22,    23,    24,   196,
      86,   396,     1,    29,    -1,   400,     1,    50,    -1,    35,
      36,    37,    38,    12,    -1,    -1,   411,    12,   413,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    22,    23,    24,
      29,    -1,    -1,     1,    29,    -1,     1,    36,    37,    38,
      -1,    36,    37,    38,    12,    -1,    -1,    12,    -1,    17,
      18,    19,    -1,    21,    22,    23,    24,    22,    23,    24,
      -1,     1,    -1,    28,     1,    33,    34,    35,    36,    -1,
      35,    36,    12,    -1,    -1,    12,    16,    -1,    -1,     1,
      -1,    -1,    22,    23,    24,    22,    23,    24,    -1,    -1,
      12,    -1,    -1,    -1,    31,    35,    36,     1,    35,    36,
      22,    23,    24,    -1,    -1,     1,    -1,    -1,    12,    31,
      -1,    -1,     1,    35,    36,     1,    12,    -1,    22,    23,
      24,    -1,    -1,    12,    -1,    29,    22,    23,    24,    -1,
      -1,     1,    36,    29,    23,    24,    22,    23,    24,    28,
      36,    30,    12,    29,    -1,    -1,     1,    36,    -1,    -1,
      36,     0,     1,    23,    24,    -1,     5,    -1,    28,     8,
      30,    10,    11,    -1,    13,    14,    36,    22,    23,    24,
      13,    14,    15,    22,    29,    -1,    -1,    26,    27,    22,
      29,    36,     0,     1,    -1,    -1,    -1,     5,    31,    -1,
       8,    -1,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,     0,     1,    22,    -1,    -1,     5,    26,    27,
       8,    29,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,     0,     1,    22,    -1,    -1,     5,    26,    27,
       8,    29,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,     0,     1,    22,    -1,    -1,     5,    26,    27,
       8,    29,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,     0,     1,    22,    -1,    -1,     5,    26,    27,
       8,    29,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
       1,    -1,     3,     1,    22,     6,     7,     5,    26,    27,
       8,    29,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    22,    -1,    -1,     5,    26,    27,
       8,    29,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    22,    -1,    -1,     5,    26,    27,
       8,    29,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    22,    -1,    -1,     5,    26,    27,
       8,    29,    10,    11,    -1,    13,    14,    -1,    13,    14,
      15,    -1,    -1,    -1,    22,    -1,    -1,    22,    26,    27,
       1,    29,    -1,    -1,     5,     6,    31,     8,     1,    10,
      11,    -1,     5,    -1,    -1,     8,    -1,    10,    11,    -1,
      -1,    22,    -1,     1,    -1,    26,    -1,     5,    29,    22,
       8,     1,    10,    11,    27,     5,    29,    -1,     8,    -1,
      10,    11,    -1,    -1,    22,    -1,    -1,    -1,    26,    -1,
      12,    29,    22,    12,    13,    14,    -1,    27,    -1,    29,
      22,    23,    24,    22,    23,    24,    -1,    29,    -1,    -1,
      29,    12,    -1,    -1,    36,    12,    35,    36,    37,    38,
      -1,    22,    23,    24,    -1,    22,    23,    24,    29,    -1,
      31,    -1,    29,    12,    35,    36,    37,    38,    35,    36,
      37,    38,    -1,    22,    23,    24,    -1,    -1,    -1,     5,
      29,    12,     8,    -1,    10,    11,    35,    36,    37,    38,
      -1,    22,    23,    24,    -1,    -1,    22,    -1,    29,    -1,
      26,    -1,    -1,    29,    35,    36,    37,    38,     5,    -1,
      -1,     8,    -1,    10,    11,    -1,     5,    -1,    -1,     8,
      -1,    10,    11,    -1,    -1,    22,    -1,    -1,    -1,    26,
      -1,     5,    29,    22,     8,    -1,    10,    11,    27,     5,
      29,    -1,     8,    -1,    10,    11,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    27,    -1,    29,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     0,     1,     5,     8,    10,    11,    13,    14,    22,
      26,    27,    29,    41,    42,    45,    50,    55,    69,    70,
      71,    72,    74,    77,    85,    86,    87,    92,   101,   102,
     107,   109,   134,    28,     1,   108,     1,    12,    22,    23,
      24,    29,    35,    36,    37,    38,    86,    92,   119,   123,
     124,   125,   126,   127,   129,   130,   132,   133,   134,     1,
      29,    26,    29,    43,    55,     0,    42,     1,    22,    29,
      53,   134,    73,   123,     1,    28,    31,    88,    89,    90,
      91,   123,     1,    28,     1,     6,    29,   103,   104,   105,
     120,   121,   123,    26,    70,   110,   113,     1,    20,    30,
      32,    39,    78,    80,    81,    28,     9,    28,    29,   123,
     123,     1,   119,   125,     1,    23,    24,    86,    92,   134,
       1,   128,   129,   130,     1,   128,    37,    38,     1,    28,
      31,    35,    36,   126,    37,    38,    37,    38,    28,     1,
      25,   123,    46,     1,     1,    26,    27,    44,    45,    48,
      49,    50,    70,    22,    28,    29,    52,     1,    28,    30,
      54,     1,    28,    30,    31,    91,     1,    16,    28,   113,
     121,     1,    28,     1,     3,     6,     7,   106,   113,     1,
       6,     1,    31,     1,    17,    18,    19,    21,    33,    34,
     122,     1,    27,    70,   114,     9,   111,    28,     1,    22,
     134,    22,     1,    12,    28,    36,   115,   116,   131,   132,
     133,    78,   134,   112,   120,   123,     1,    31,     1,    28,
      31,   119,   128,   119,   128,    28,     1,   119,   125,     1,
     119,   125,     1,   119,   128,     1,   119,   128,     1,   119,
     128,     1,   119,   128,    31,    31,    31,    27,    47,    48,
      31,    28,    27,    48,     0,    27,    49,    31,    51,    15,
      22,    31,    55,    56,    64,    66,    67,     1,   134,   134,
      91,    22,     7,     1,    31,   113,     1,   113,     6,     7,
     113,     1,   123,    27,     1,    27,    70,   120,   112,    28,
       1,    78,    29,   131,     1,    28,    30,    82,    83,    79,
     115,     1,    28,     1,    31,     1,    28,    75,     1,    28,
       1,    28,     0,    27,     0,    27,    93,    31,    60,    64,
      58,     1,    22,    30,    31,    65,     1,    22,    55,     3,
       7,     7,     1,     3,     7,     7,     7,     1,    28,   115,
       1,   115,   131,     1,    31,   115,     1,    28,    30,    84,
     115,     1,    30,    28,    76,    26,    94,    98,   114,    62,
      31,    26,    59,    68,    66,    57,    66,     1,    22,    30,
      30,     1,    31,   115,   115,   114,    12,    99,   100,   115,
     117,   118,   134,    27,    29,    63,    68,    61,    27,    48,
       1,    28,    59,    27,    29,     1,    29,   134,    31,    29,
      97,     1,    28,    63,     0,    27,    29,    28,   134,     1,
      31,    96,    99,    95,     1,    31,    99,    99
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    41,    42,    42,    42,    43,    42,
      42,    42,    44,    44,    44,    46,    45,    47,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    49,    50,
      50,    50,    51,    50,    52,    50,    53,    53,    54,    53,
      53,    55,    55,    57,    56,    58,    56,    59,    59,    61,
      60,    62,    60,    63,    63,    64,    64,    65,    64,    66,
      66,    66,    66,    66,    66,    66,    67,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    72,    73,
      73,    74,    74,    74,    74,    75,    74,    74,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      78,    78,    78,    79,    79,    81,    80,    82,    83,    82,
      82,    84,    82,    85,    85,    85,    85,    86,    86,    87,
      88,    88,    89,    89,    89,    90,    91,    91,    93,    92,
      95,    94,    96,    94,    94,    97,    94,    98,    99,   100,
     100,   101,   101,   101,   102,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   105,   106,   107,   108,   107,   107,   109,   110,   110,
     111,   110,   112,   112,   113,   113,   113,   113,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   117,   117,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   120,   120,
     120,   120,   121,   121,   121,   122,   122,   122,   122,   122,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     129,   129,   130,   130,   130,   130,   130,   130,   130,   131,
     131,   132,   132,   133,   134,   134
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     3,
       1,     2,     2,     1,     2,     0,     4,     2,     2,     1,
       1,     2,     1,     1,     1,     2,     3,     3,     2,     3,
       3,     3,     0,     5,     0,     4,     1,     3,     0,     3,
       3,     1,     1,     0,     4,     0,     3,     2,     2,     0,
       4,     0,     3,     2,     2,     1,     3,     0,     3,     2,
       2,     1,     3,     3,     2,     2,     1,     3,     2,     3,
       5,     5,     4,     3,     3,     4,     4,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     2,     2,
       2,     5,     5,     5,     5,     0,     6,     3,     1,     0,
       4,     4,     5,     5,     3,     3,     3,     1,     5,     5,
       3,     4,     4,     2,     2,     0,     2,     2,     0,     2,
       3,     0,     3,     2,     2,     2,     2,     2,     4,     2,
       2,     1,     1,     3,     2,     1,     3,     2,     0,     6,
       0,     6,     0,     5,     2,     0,     4,     3,     2,     1,
       1,     3,     3,     3,     1,     2,     4,     2,     4,     3,
       2,     4,     3,     2,     4,     4,     3,     4,     4,     4,
       2,     1,     1,     2,     0,     4,     3,     1,     4,     4,
       0,     3,     2,     2,     3,     3,     3,     1,     2,     1,
       2,     1,     1,     4,     4,     3,     3,     1,     1,     4,
       4,     3,     3,     3,     4,     4,     3,     3,     3,     3,
       2,     2,     3,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     3,     3,     3,     3,     1,
       3,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* global_statement: declarative_stmt  */
#line 134 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1686 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 138 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1694 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 8: /* $@1: %empty  */
#line 143 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::addInvalidScope();
        SemanticActions::announceSpecificError(MISSING_PROGRAM_NAME);

        SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration("");

    }
#line 1706 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 10: /* global_statement: '}'  */
#line 152 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1714 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 11: /* global_statement: error ';'  */
#line 156 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1723 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 12: /* unnamed_program_tail: program_statements '}'  */
#line 164 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1731 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 13: /* unnamed_program_tail: '}'  */
#line 168 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1739 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 14: /* unnamed_program_tail: program_statements $end  */
#line 172 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1748 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 15: /* $@2: %empty  */
#line 182 "include/syntax-analyzer/components/yacc.y"
    {
        const std::string s = (yyvsp[-1].sref)->symbol;
        auto entry = SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration(s);
        if (entry != nullptr)
        {
            SemanticAnalyzer::addScope(s);
            CodeGenerator::addIntermediateCodeBlock(entry);
        }
        else
            SemanticAnalyzer::addInvalidScope();
    }
#line 1764 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 17: /* program_tail: program_statements '}'  */
#line 198 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1773 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 18: /* program_tail: program_statements $end  */
#line 203 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticAnalyzer::removeScope();
    }
#line 1782 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 19: /* program_tail: '}'  */
#line 208 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1791 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 20: /* program_statements: program_statement  */
#line 217 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 1797 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 21: /* program_statements: program_statements program_statement  */
#line 218 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 1803 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 22: /* program_statement: declarative_stmt  */
#line 223 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 1811 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 23: /* program_statement: executable_stmt  */
#line 227 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 1819 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 24: /* program_statement: program_head  */
#line 231 "include/syntax-analyzer/components/yacc.y"
    {
       (yyval.returnable) = false;

       SemanticActions::announceSpecificError(INVALID_PROGRAM_NESTING);

    }
#line 1830 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 25: /* program_statement: '{' '}'  */
#line 238 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1841 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 26: /* program_statement: '{' program_statements '}'  */
#line 245 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1852 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 27: /* program_statement: '{' program_statements $end  */
#line 252 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1864 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 28: /* program_statement: error ';'  */
#line 260 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;

    }
#line 1873 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 29: /* declarative_stmt: type variable_list ';'  */
#line 270 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("VARIABLE DECLARATION");
    }
#line 1881 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 30: /* declarative_stmt: type error ';'  */
#line 274 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1890 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 31: /* declarative_stmt: type variable_list error  */
#line 279 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1899 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 32: /* $@3: %empty  */
#line 284 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction (
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, (yyvsp[-1].sref)->symbol})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionName((yyvsp[-1].sref)->symbol);

    }
#line 1911 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 34: /* $@4: %empty  */
#line 293 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction(
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, "...()"})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionWithoutName();

        SemanticActions::announceSpecificError(MISSING_FUNCTION_NAME);

    }
#line 1925 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 36: /* variable_list: variable  */
#line 309 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1933 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 37: /* variable_list: variable_list ',' variable  */
#line 313 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1941 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 38: /* $@5: %empty  */
#line 317 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 1949 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 39: /* variable_list: variable_list $@5 variable  */
#line 321 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1957 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 40: /* variable_list: variable_list ',' error  */
#line 325 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1966 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 41: /* type: WORD_UINT  */
#line 333 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UINT;
    }
#line 1974 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 42: /* type: WORD_FLOAT  */
#line 337 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = FLOAT;
        SemanticActions::announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1983 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 43: /* $@6: %empty  */
#line 347 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();

    }
#line 1992 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 45: /* $@7: %empty  */
#line 353 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();

        SemanticActions::announceSpecificError(NO_PARAMS_GIVEN);

    }
#line 2003 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 47: /* unnamed_function_declaration_tail: function_body ';'  */
#line 364 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

    }
#line 2013 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 48: /* unnamed_function_declaration_tail: function_body error  */
#line 370 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2026 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 49: /* $@8: %empty  */
#line 382 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
        if (entry != nullptr)
            CodeGenerator::addIntermediateCodeBlock(entry);

    }
#line 2037 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 51: /* $@9: %empty  */
#line 390 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
        if (entry != nullptr)
            CodeGenerator::addIntermediateCodeBlock(entry);

        SemanticActions::announceSpecificError(NO_PARAMS_GIVEN);

    }
#line 2050 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 53: /* function_declaration_tail: function_body ';'  */
#line 403 "include/syntax-analyzer/components/yacc.y"
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn((yyvsp[-1].returnable));
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::logStructure("FUNCTION DECLARATION");

    }
#line 2065 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 54: /* function_declaration_tail: function_body error  */
#line 414 "include/syntax-analyzer/components/yacc.y"
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn((yyvsp[-1].returnable));
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2081 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 57: /* $@10: %empty  */
#line 431 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2089 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 59: /* formal_parameter: type IDENTIFIER  */
#line 439 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2099 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 60: /* formal_parameter: type error  */
#line 445 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2109 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 61: /* formal_parameter: IDENTIFIER  */
#line 451 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2121 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 62: /* formal_parameter: parameter_semantics type IDENTIFIER  */
#line 459 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2130 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 63: /* formal_parameter: parameter_semantics type error  */
#line 464 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2140 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 64: /* formal_parameter: parameter_semantics error  */
#line 470 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        SemanticActions::announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;

    }
#line 2151 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 65: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 477 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2162 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 66: /* parameter_semantics: WORD_CR  */
#line 487 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CR);

    }
#line 2171 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 67: /* function_body: '{' program_statements '}'  */
#line 497 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 2179 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 68: /* function_body: '{' '}'  */
#line 501 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 2187 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 69: /* function_body: '{' program_statements $end  */
#line 505 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    }
#line 2198 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 70: /* return: WORD_RETURN '(' expression ')' ';'  */
#line 517 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                (yyvsp[-2].metadata).expression.type,
                mapWithOperand((yyvsp[-2].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

    }
#line 2216 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 71: /* return: WORD_RETURN '(' expression ')' error  */
#line 531 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                (yyvsp[-2].metadata).expression.type,
                mapWithOperand((yyvsp[-2].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2237 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 72: /* return: WORD_RETURN '(' expression error  */
#line 548 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                (yyvsp[-1].metadata).expression.type,
                mapWithOperand((yyvsp[-1].metadata).reference),
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2259 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 73: /* return: WORD_RETURN expression ')'  */
#line 566 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                (yyvsp[-1].metadata).expression.type,
                mapWithOperand((yyvsp[-1].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);

    }
#line 2280 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 74: /* return: WORD_RETURN expression error  */
#line 583 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                (yyvsp[-1].metadata).expression.type,
                mapWithOperand((yyvsp[-1].metadata).reference),
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2302 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 75: /* return: WORD_RETURN '(' expression ';'  */
#line 601 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                (yyvsp[-1].metadata).expression.type, 
                mapWithOperand((yyvsp[-1].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::announceSpecificError(MISSING_CLOSING_PARENTHESIS);

    }
#line 2322 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 76: /* return: WORD_RETURN expression ')' ';'  */
#line 617 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                (yyvsp[-2].metadata).expression.type,
                mapWithOperand((yyvsp[-2].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 2342 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 77: /* return: WORD_RETURN expression ';'  */
#line 633 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                (yyvsp[-1].metadata).expression.type, 
                mapWithOperand((yyvsp[-1].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);

    }
#line 2362 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 78: /* return: WORD_RETURN error ';'  */
#line 649 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(RETURN_SYNTAX_ERROR);
        yyerrok;

    }
#line 2372 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 79: /* executable_stmt: assignment  */
#line 659 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2378 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 80: /* executable_stmt: multiple_assignments  */
#line 660 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2384 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 81: /* executable_stmt: invocation  */
#line 661 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2390 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 82: /* executable_stmt: if  */
#line 662 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2396 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 83: /* executable_stmt: print  */
#line 663 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2402 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 84: /* executable_stmt: return  */
#line 664 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = true;  }
#line 2408 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 85: /* executable_stmt: do_while  */
#line 665 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2414 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 86: /* assignment: assignment_head assignment_tail  */
#line 672 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        { 
            SemanticAnalyzer::TypeChecker::Expression e1 = {
                (yyvsp[-1].metadata).expression.type,
                *StringPool::get((yyvsp[-1].metadata).expression.pid),
                (yyvsp[-1].metadata).expression.assignable
            };
            SemanticAnalyzer::TypeChecker::Expression e2 = {
                (yyvsp[0].metadata).expression.type,
                *StringPool::get((yyvsp[0].metadata).expression.pid),
                (yyvsp[0].metadata).expression.assignable
            };

            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_ASSIGN,
                SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2),
                mapWithOperand((yyvsp[-1].metadata).reference),
                mapWithOperand((yyvsp[0].metadata).reference)
            });
        }
    }
#line 2441 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 87: /* assignment: variable OP_ASSIGN error ';'  */
#line 695 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2451 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 88: /* assignment_head: variable OP_ASSIGN  */
#line 704 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression = { (yyval.metadata).reference.sref->type, (yyvsp[-1].pid), true };
        }
        else
        {
            (yyval.metadata).reference.type = NULLREF;
            (yyval.metadata).expression = { UNKNOWN, (yyvsp[-1].pid), false };
        }
    }
#line 2469 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 89: /* assignment_tail: expression ';'  */
#line 721 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::logStructure("ASSIGNMENT");

    }
#line 2480 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 90: /* assignment_tail: expression error  */
#line 728 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2492 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 91: /* print: WORD_PRINT '(' LITERAL_STRING ')' ';'  */
#line 741 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PRINT");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT, 
                STRING,
                CodeGenerator::Triples::Operand({ LITERAL, { .lref = (yyvsp[-2].lref) } }), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

    }
#line 2509 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 92: /* print: WORD_PRINT '(' LITERAL_STRING ')' error  */
#line 754 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT, 
                STRING,
                CodeGenerator::Triples::Operand({ LITERAL, { .lref = (yyvsp[-2].lref) } }), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2526 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 93: /* print: WORD_PRINT '(' expression ')' ';'  */
#line 767 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT, 
                (yyvsp[-2].metadata).expression.type,
                mapWithOperand((yyvsp[-2].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::logStructure("PRINT");

    }
#line 2543 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 94: /* print: WORD_PRINT '(' expression ')' error  */
#line 780 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT,
                (yyvsp[-2].metadata).expression.type, 
                mapWithOperand((yyvsp[-2].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2561 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 95: /* $@11: %empty  */
#line 794 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;

    }
#line 2571 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 97: /* print: WORD_PRINT error ';'  */
#line 801 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(PRINT_SYNTAX_ERROR);
        yyerrok;
    }
#line 2580 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 99: /* print_end: %empty  */
#line 810 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
    }
#line 2588 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 100: /* multiple_assignments: variable assignment_list opt_trunc_constant ';'  */
#line 819 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2598 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 101: /* multiple_assignments: variable assignment_list opt_trunc_constant error  */
#line 825 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2610 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 102: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 833 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2622 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 103: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 841 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2635 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 104: /* multiple_assignments: variable assignment_list ';'  */
#line 850 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::announceSpecificError(MISSING_RIGHT_SIDE_VALUES);

    }
#line 2646 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 105: /* multiple_assignments: variable assignment_list error  */
#line 857 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2659 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 106: /* multiple_assignments: variable error ';'  */
#line 866 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;

    }
#line 2671 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 108: /* assignment_list: ',' variable assignment_list opt_trunc_constant ','  */
#line 878 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2679 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 109: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 882 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_EQUALS);

    }
#line 2690 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 111: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 890 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[0].metadata));
        SemanticActions::announceSpecificError(MISSING_COMMA);

    }
#line 2700 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 112: /* assignment_list: ',' variable assignment_list error  */
#line 896 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2710 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 113: /* assignment_end: opt_trunc_constant ','  */
#line 905 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2718 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 114: /* assignment_end: opt_trunc_constant error  */
#line 909 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_COMMA);
        yyerrok;

    }
#line 2730 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 115: /* $@12: %empty  */
#line 920 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_COMMA);
    }
#line 2738 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 118: /* $@13: %empty  */
#line 929 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2746 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 121: /* $@14: %empty  */
#line 935 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2754 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 124: /* invocation: function_invocation_head error  */
#line 946 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2763 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 126: /* invocation: lambda_invocation_head error  */
#line 952 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2772 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 127: /* function_invocation_head: invocation_setup function_invocation_tail  */
#line 962 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = (yyvsp[-1].metadata).expression;
        StringPool::append((yyval.metadata).expression.pid, *StringPool::get((yyvsp[0].metadata).expression.pid));

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr && (yyvsp[-1].metadata).reference.type != NULLREF)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_CALL, 
                (yyvsp[-1].metadata).expression.type,
                mapWithOperand((yyvsp[-1].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) }
            );
            CodeGenerator::INTERMEDIATE_CODE->commit();
            (yyval.metadata).reference.type = TRIPLE;
        }
        else
            (yyval.metadata).reference = (yyvsp[-1].metadata).reference;

        SemanticActions::logStructure("FUNCTION INVOCATION");
    }
#line 2797 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 128: /* function_invocation_head: IDENTIFIER '(' error ')'  */
#line 983 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression.pid = StringPool::create((yyvsp[-3].sref)->symbol + "(...)");
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_INVOCATIONS.checkFunctionInScope((yyvsp[-3].sref)->symbol);
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression.type = (yyval.metadata).reference.sref->type;
        }
        else
        {
            (yyval.metadata).reference.type = NULLREF;
            (yyval.metadata).expression.type = UNKNOWN;
        }

        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 2819 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 129: /* invocation_setup: IDENTIFIER '('  */
#line 1004 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression.pid = StringPool::create((yyvsp[-1].sref)->symbol + "(");
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_INVOCATIONS.checkFunctionInScope((yyvsp[-1].sref)->symbol);
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression.type = (yyval.metadata).reference.sref->type;
        }
        else
        {
            (yyval.metadata).reference.type = NULLREF;
            (yyval.metadata).expression.type = UNKNOWN;
        }
    }
#line 2838 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 130: /* function_invocation_tail: real_parameter_list ')'  */
#line 1022 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, ")");
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
    }
#line 2850 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 131: /* function_invocation_tail: ')'  */
#line 1030 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = { UNKNOWN, StringPool::create(")") };

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
        SemanticActions::announceSpecificError(MISSING_ARGUMENT);
    }
#line 2861 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 132: /* real_parameter_list: real_parameter  */
#line 1040 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 2869 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 133: /* real_parameter_list: real_parameter_list ',' real_parameter  */
#line 1044 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].metadata).expression.pid, ", " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
    }
#line 2879 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 134: /* real_parameter_list: real_parameter_list_setup real_parameter  */
#line 1050 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

    }
#line 2890 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 135: /* real_parameter_list_setup: real_parameter_list  */
#line 1060 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2899 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 136: /* real_parameter: expression OP_POINTER IDENTIFIER  */
#line 1068 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_INVOCATIONS.checkParameterInScope((yyvsp[0].sref)->symbol);
        if (entry != nullptr)
        {
            SemanticAnalyzer::TypeChecker::Expression e1 = {
                (yyvsp[-2].metadata).expression.type,
                *StringPool::get((yyvsp[-2].metadata).expression.pid),
                (yyvsp[-2].metadata).expression.assignable
            };
            SemanticAnalyzer::TypeChecker::Expression e2 = { entry->semantics, (yyvsp[0].sref)->symbol, true };
            int result = SemanticAnalyzer::CHK_TYPES.checkSemantics(e1, e2);

            e2.type = entry->type;
            if (result == CR && CodeGenerator::INTERMEDIATE_CODE != nullptr)
            { 
                int typeCR = SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2);
                CodeGenerator::INTERMEDIATE_CODE->addBuffer ({
                    CODEOP_ASSIGN,
                    typeCR,
                    mapWithOperand((yyvsp[-2].metadata).reference), 
                    CodeGenerator::Triples::Operand({ SYMBOL, entry }) 
                });
            }
            else if (result == CV && CodeGenerator::INTERMEDIATE_CODE != nullptr)
            { 
                int typeCV = SemanticAnalyzer::CHK_TYPES.checkAssignment(e2, e1);
                CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                    CODEOP_ASSIGN,
                    typeCV,
                    CodeGenerator::Triples::Operand({ SYMBOL, entry }), 
                    mapWithOperand((yyvsp[-2].metadata).reference) 
                });
            }
        }
        StringPool::append((yyvsp[-2].metadata).expression.pid, "->" + (yyvsp[0].sref)->symbol);
        (yyval.metadata).expression = { UNKNOWN, (yyvsp[-2].metadata).expression.pid, false };
    }
#line 2941 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 137: /* real_parameter: expression error  */
#line 1106 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2952 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 138: /* $@15: %empty  */
#line 1118 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclaration((yyvsp[-1].sref)->symbol);
        CodeGenerator::addIntermediateCodeBlock (
              SemanticAnalyzer::CHK_LAMBDAS.getLambda().function
        );

    }
#line 2964 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 140: /* $@16: %empty  */
#line 1130 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

    }
#line 2973 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 142: /* $@17: %empty  */
#line 1136 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);

    }
#line 2983 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 145: /* $@18: %empty  */
#line 1144 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::announceSpecificError(MISSING_BOTH_BRACKETS);

    }
#line 2994 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 147: /* lambda_missing_closing_bracket: '{' executable_statements '('  */
#line 1155 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    }
#line 3004 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 148: /* lambda_invocation_tail: lambda_real_parameter ')'  */
#line 1164 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("LAMBDA");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_RET,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            });

            CodeGenerator::notifyEndOfBlock();

            SemanticAnalyzer::TypeChecker::Expression e1, e2;
            SemanticAnalyzer::LambdaChecker::Lambda l = SemanticAnalyzer::CHK_LAMBDAS.getLambda();

            CodeGenerator::Triples::Operand o1;
            if (l.parameter != nullptr)
            {
                e1 = { l.parameter->type, l.pname, true };
                o1 = { SYMBOL, l.parameter };
            }
            else
            {
                e1 = { UNKNOWN, "...", false };
                o1 = { NULLREF, nullptr };
            }
            e2 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid), (yyvsp[-1].metadata).expression.assignable };
            int type = SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2);

            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_ASSIGN,
                type,
                o1,
                mapWithOperand((yyvsp[-1].metadata).reference)
            });

            if (l.function != nullptr)
                CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                    CODEOP_CALL,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({SYMBOL, l.function}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr})
                });
        }
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclarationEnd();

        SemanticActions::logStructure("LAMBDA");

    }
#line 3060 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 149: /* lambda_real_parameter: opt_trunc_variable  */
#line 1218 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3066 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 150: /* lambda_real_parameter: opt_trunc_constant  */
#line 1219 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3072 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 151: /* if: if_word if_head ';'  */
#line 1226 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3080 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 152: /* if: if_word if_head error  */
#line 1230 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 3091 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 153: /* if: if_word error ';'  */
#line 1237 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;

    }
#line 3103 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 154: /* if_word: WORD_IF  */
#line 1248 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_IF_START,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
            });
        }
    }
#line 3119 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 155: /* if_head: condition_body_setup WORD_ENDIF  */
#line 1263 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::logStructure("IF");

    }
#line 3143 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 156: /* if_head: condition_body_setup WORD_ELSE executable_body WORD_ENDIF  */
#line 1283 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable) && (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::logStructure("IF-ELSE");

    }
#line 3167 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 157: /* if_head: condition_body_setup error  */
#line 1303 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ENDIF);
        yyerrok;

    }
#line 3192 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 158: /* if_head: condition_body_setup WORD_ELSE executable_body error  */
#line 1324 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable) && (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ENDIF);
        yyerrok;

    }
#line 3217 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 159: /* if_head: condition error WORD_ENDIF  */
#line 1345 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3229 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 160: /* if_head: condition error  */
#line 1353 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3242 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 161: /* if_head: condition error WORD_ELSE WORD_ENDIF  */
#line 1362 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3254 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 162: /* if_head: condition_body_setup WORD_ELSE error  */
#line 1370 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3280 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 163: /* if_head: condition WORD_ELSE  */
#line 1392 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(MISSING_BOTH_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);

    }
#line 3292 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 164: /* if_head: condition WORD_ELSE executable_body WORD_ENDIF  */
#line 1400 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(MISSING_IF_EXECUTABLE_BODY);

    }
#line 3303 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 165: /* if_head: condition_body_setup WORD_ELSE error WORD_ENDIF  */
#line 1407 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3328 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 166: /* if_head: WORD_ELSE executable_body WORD_ENDIF  */
#line 1428 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_IF_STATEMENT);

    }
#line 3339 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 167: /* if_head: condition_body_setup WORD_ELSE executable_body INVALID_RWORD  */
#line 1435 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable) && (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }
    }
#line 3360 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 168: /* if_head: condition_body_setup INVALID_RWORD executable_body WORD_ENDIF  */
#line 1452 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable) && (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }
    }
#line 3381 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 169: /* if_head: condition_body_setup INVALID_RWORD executable_body INVALID_RWORD  */
#line 1469 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable) && (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }
    }
#line 3402 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 170: /* condition_body_setup: condition_setup then_body_setup  */
#line 1489 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3410 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 171: /* condition_setup: condition  */
#line 1496 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_BRANCH_FALSE,
                (yyvsp[0].metadata).expression.type,
                mapWithOperand((yyvsp[0].metadata).reference),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            }));
        }
    }
#line 3426 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 172: /* then_body_setup: executable_body  */
#line 1511 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            int triple = CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_BRANCH_TRUE,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            });
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(STACK.top(), triple + 1);
            STACK.pop();
            STACK.push(triple);
        }
    }
#line 3447 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 173: /* do_while: do_while_head do_body  */
#line 1533 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3455 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 174: /* $@19: %empty  */
#line 1537 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);

    }
#line 3464 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 175: /* do_while: WORD_DO $@19 WORD_WHILE do_while_tail  */
#line 1542 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3472 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 176: /* do_while: WORD_DO error ';'  */
#line 1546 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;

    }
#line 3484 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 177: /* do_while_head: WORD_DO  */
#line 1557 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_DO_START,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            }));
    }
#line 3498 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 178: /* do_body: executable_body WORD_WHILE condition ';'  */
#line 1570 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_BRANCH_TRUE,
                (yyvsp[-1].metadata).expression.type,
                mapWithOperand((yyvsp[-1].metadata).reference),
                CodeGenerator::Triples::Operand({ TRIPLE, { .tref = STACK.top() }})
            });
        STACK.pop();

        SemanticActions::logStructure("DO-WHILE");

    }
#line 3518 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 179: /* do_body: executable_body WORD_WHILE condition error  */
#line 1586 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3530 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 180: /* $@20: %empty  */
#line 1594 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE);

    }
#line 3539 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 181: /* do_body: executable_body $@20 do_while_tail  */
#line 1599 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);
    }
#line 3547 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 183: /* do_while_tail: condition error  */
#line 1607 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3557 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 184: /* executable_body: '{' executable_statements '}'  */
#line 1618 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3565 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 185: /* executable_body: '{' executable_statements error  */
#line 1622 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 3577 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 186: /* executable_body: '{' error '}'  */
#line 1630 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        yyerrok;
    }
#line 3587 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 187: /* executable_body: executable_stmt  */
#line 1636 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3595 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 188: /* executable_body: '{' '}'  */
#line 1640 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3603 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 189: /* executable_statements: executable_stmt  */
#line 1646 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 3609 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 190: /* executable_statements: executable_statements executable_stmt  */
#line 1647 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 3615 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 191: /* opt_trunc_constant: numeric_constant  */
#line 1654 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3623 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 192: /* opt_trunc_constant: trunc_constant  */
#line 1658 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3631 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 193: /* trunc_constant: WORD_TRUNC '(' numeric_constant ')'  */
#line 1665 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

    }
#line 3642 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 194: /* trunc_constant: WORD_TRUNC '(' numeric_constant error  */
#line 1672 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3656 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 195: /* trunc_constant: WORD_TRUNC numeric_constant ')'  */
#line 1682 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3669 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 196: /* trunc_constant: WORD_TRUNC numeric_constant error  */
#line 1691 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3683 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 197: /* opt_trunc_variable: variable  */
#line 1704 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression = { (yyval.metadata).reference.sref->type, (yyvsp[0].pid), true };
        }
        else
        {
            (yyval.metadata).reference.type = NULLREF;
            (yyval.metadata).expression = { UNKNOWN, (yyvsp[0].pid), true };
        }

    }
#line 3702 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 198: /* opt_trunc_variable: trunc_variable  */
#line 1719 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3710 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 199: /* trunc_variable: WORD_TRUNC '(' variable ')'  */
#line 1726 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);
        }
        else
        {
            (yyval.metadata).reference  = { NULLREF, nullptr };
            (yyval.metadata).expression.type = UNKNOWN;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

    }
#line 3734 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 200: /* trunc_variable: WORD_TRUNC '(' variable error  */
#line 1746 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);
        }
        else
        {
            (yyval.metadata).reference  = { NULLREF, nullptr };
            (yyval.metadata).expression.type = UNKNOWN;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3761 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 201: /* trunc_variable: WORD_TRUNC variable ')'  */
#line 1769 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        { 
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);

        }
        else
        {
            (yyval.metadata).reference  = { NULLREF, nullptr };
            (yyval.metadata).expression.type = UNKNOWN;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3788 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 202: /* trunc_variable: WORD_TRUNC variable error  */
#line 1792 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        { 
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);
        }
        else
        {
            (yyval.metadata).reference  = { NULLREF, nullptr };
            (yyval.metadata).expression.type = UNKNOWN;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3815 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 203: /* trunc_variable: WORD_TRUNC error ';'  */
#line 1815 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("trunc ..."), false };

        SemanticActions::specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;

    }
#line 3828 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 204: /* trunc_expression: WORD_TRUNC '(' expression ')'  */
#line 1827 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");
    }
#line 3838 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 205: /* trunc_expression: WORD_TRUNC '(' expression error  */
#line 1833 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3852 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 206: /* trunc_expression: WORD_TRUNC expression ')'  */
#line 1843 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3865 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 207: /* trunc_expression: WORD_TRUNC expression error  */
#line 1852 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3879 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 208: /* condition: '(' comparison ')'  */
#line 1867 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);
    }
#line 3887 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 209: /* condition: '(' comparison error  */
#line 1871 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3899 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 210: /* condition: comparison ')'  */
#line 1879 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3910 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 211: /* condition: comparison error  */
#line 1886 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;

    }
#line 3922 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 212: /* comparison: expression comparison_operator expression  */
#line 1897 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
        StringPool::append((yyvsp[-2].metadata).expression.pid, *StringPool::get((yyvsp[-1].op).pid) + *StringPool::get((yyvsp[0].metadata).expression.pid));

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                (yyvsp[-1].op).tid,
                (yyval.metadata).expression.type,
                mapWithOperand((yyvsp[-2].metadata).reference),
                mapWithOperand((yyvsp[0].metadata).reference)
            });
            (yyval.metadata).reference.type = TRIPLE;
        }
        else
            (yyval.metadata).reference = { NULLREF, nullptr };
        (yyval.metadata).expression.assignable = false;
    }
#line 3949 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 213: /* comparison: expression error  */
#line 1920 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;

    }
#line 3961 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 214: /* comparison: expression comparison_operator error  */
#line 1928 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 3969 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 215: /* comparison_operator: OP_EQUAL  */
#line 1935 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_EQUAL, StringPool::create(Translator::translate(OP_EQUAL)) };
    }
#line 3977 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 216: /* comparison_operator: OP_NOT_EQUAL  */
#line 1939 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_NOT_EQUAL, StringPool::create(Translator::translate(OP_NOT_EQUAL)) };
    }
#line 3985 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 217: /* comparison_operator: OP_GE  */
#line 1943 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GE, StringPool::create(Translator::translate(OP_GE)) };
    }
#line 3993 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 218: /* comparison_operator: OP_LE  */
#line 1947 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LE, StringPool::create(Translator::translate(OP_LE)) };
    }
#line 4001 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 219: /* comparison_operator: '>'  */
#line 1951 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GT, StringPool::create(">") };
    }
#line 4009 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 220: /* comparison_operator: '<'  */
#line 1955 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LT, StringPool::create("<") };
    }
#line 4017 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 221: /* expression: term  */
#line 1964 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4025 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 222: /* expression: expression_setup positive_term  */
#line 1968 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;
        (yyval.metadata).reference = (yyvsp[-1].metadata).reference;
        
        (yyval.metadata).expression.assignable = false;
    }
#line 4041 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 223: /* expression: '+' term  */
#line 1980 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUM_OPERAND);

    }
#line 4052 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 224: /* expression: '+' error  */
#line 1987 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;

    }
#line 4065 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 225: /* expression: expression '+' term  */
#line 1996 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4073 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 226: /* expression: expression '+' error  */
#line 2000 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 4085 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 227: /* expression: expression '-' term  */
#line 2008 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4093 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 228: /* expression: expression '-' error  */
#line 2012 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 4105 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 229: /* expression: trunc_expression  */
#line 2020 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4113 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 230: /* expression: expression '+' trunc_expression  */
#line 2024 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4121 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 231: /* expression: expression '-' trunc_expression  */
#line 2028 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4129 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 232: /* expression_setup: expression  */
#line 2035 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 4139 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 233: /* term: positive_term  */
#line 2046 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4147 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 234: /* term: negative_term  */
#line 2050 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4155 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 235: /* positive_term: positive_term '*' factor  */
#line 2057 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4163 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 236: /* positive_term: positive_term '/' factor  */
#line 2061 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4171 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 237: /* positive_term: trunc_expression '/' factor  */
#line 2065 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4179 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 238: /* positive_term: trunc_expression '*' factor  */
#line 2069 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4187 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 239: /* positive_term: trunc_expression '/' trunc_expression  */
#line 2073 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4195 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 240: /* positive_term: trunc_expression '*' trunc_expression  */
#line 2077 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4203 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 241: /* positive_term: positive_term '/' trunc_expression  */
#line 2081 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4211 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 242: /* positive_term: positive_term '*' trunc_expression  */
#line 2085 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4219 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 243: /* positive_term: positive_factor  */
#line 2089 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4227 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 244: /* positive_term: positive_term '*' error  */
#line 2093 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4239 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 245: /* positive_term: positive_term '/' error  */
#line 2101 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4251 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 246: /* negative_term: negative_term '*' factor  */
#line 2112 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4259 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 247: /* negative_term: negative_term '/' factor  */
#line 2116 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4267 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 248: /* negative_term: negative_term '/' trunc_expression  */
#line 2120 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4275 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 249: /* negative_term: negative_term '*' trunc_expression  */
#line 2124 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4283 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 250: /* negative_term: negative_factor  */
#line 2128 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4291 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 251: /* negative_term: negative_term '*' error  */
#line 2132 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4303 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 252: /* negative_term: negative_term '/' error  */
#line 2140 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4315 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 253: /* negative_term: '*' factor  */
#line 2148 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_MUL_FACTOR);

    }
#line 4326 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 254: /* negative_term: '/' factor  */
#line 2155 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_DIV_FACTOR);

    }
#line 4337 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 255: /* negative_term: '*' error  */
#line 2162 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4350 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 256: /* negative_term: '/' error  */
#line 2171 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4363 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 257: /* factor: positive_factor  */
#line 2185 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4371 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 258: /* factor: negative_factor  */
#line 2189 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4379 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 259: /* positive_factor: variable  */
#line 2196 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression = { (yyval.metadata).reference.sref->type, (yyvsp[0].pid), true };
        }
        else
        {
            (yyval.metadata).reference.type = NULLREF;
            (yyval.metadata).expression = { UNKNOWN, (yyvsp[0].pid), true };
        }

    }
#line 4398 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 260: /* positive_factor: positive_constant  */
#line 2211 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4406 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 261: /* positive_factor: function_invocation_head  */
#line 2215 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4414 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 262: /* negative_factor: negative_constant  */
#line 2222 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4422 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 263: /* negative_factor: lambda_invocation_head  */
#line 2226 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };
        
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);
    }
#line 4433 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 264: /* negative_factor: '-' LITERAL_UINT  */
#line 2233 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4445 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 265: /* negative_factor: '-' function_invocation_head  */
#line 2241 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4456 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 266: /* negative_factor: '-' variable  */
#line 2248 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression = { (yyval.metadata).reference.sref->type, (yyvsp[0].pid), false };
        }
        else
        {
            (yyval.metadata).reference = { NULLREF, nullptr };
            (yyval.metadata).expression = { UNKNOWN, (yyvsp[0].pid), false };
        }
        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4476 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 267: /* negative_factor: '-' lambda_invocation_head  */
#line 2264 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);

    }
#line 4489 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 268: /* negative_factor: '-' error  */
#line 2273 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUB_OPERANDS);
        yyerrok;

    }
#line 4502 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 269: /* numeric_constant: positive_constant  */
#line 2287 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4510 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 270: /* numeric_constant: negative_constant  */
#line 2291 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4518 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 271: /* positive_constant: LITERAL_UINT  */
#line 2298 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4527 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 272: /* positive_constant: LITERAL_FLOAT  */
#line 2303 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4536 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 273: /* negative_constant: '-' LITERAL_FLOAT  */
#line 2311 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL , .lref = SemanticActions::turnNegative((yyvsp[0].lref)) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };

    }
#line 4546 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 274: /* variable: IDENTIFIER  */
#line 2322 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.pid) = StringPool::create((yyvsp[0].sref)->symbol);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariableName((yyvsp[0].sref)->symbol);

    }
#line 4557 "src/syntax-analyzer/components/Parser.cpp"
    break;

  case 275: /* variable: variable '.' IDENTIFIER  */
#line 2329 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].pid), "." + (yyvsp[0].sref)->symbol);
        (yyval.pid) = (yyvsp[-2].pid);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariablePrefix((yyvsp[0].sref)->symbol);

    }
#line 4569 "src/syntax-analyzer/components/Parser.cpp"
    break;


#line 4573 "src/syntax-analyzer/components/Parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2338 "include/syntax-analyzer/components/yacc.y"
 // Codes ------------------------------------------

void yyerror(const char* s)
{
    SemanticActions::announceSyntaxError();
}

CodeGenerator::Triples::Operand mapWithOperand(const Metadata::Reference& ref)
{
    switch (ref.type)
    {
    case SYMBOL:
        return { SYMBOL , { .sref = ref.sref } };
    case LITERAL:
        return { LITERAL, { .lref = ref.lref } };
    case TRIPLE:
        return { TRIPLE , { .tref = ref.tref } };
    default:
        return { NULLREF, { .sref = nullptr  }};
    }
}

void createMultipleAssignmentTriple(const Metadata& m)
{
    SemanticAnalyzer::TypeChecker::Expression e1 = {
        UNKNOWN,
        SemanticAnalyzer::CHK_VARIABLES.getCurrentVariableName()
    };

    auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
    if (entry != nullptr)
    {
        e1.type = entry->type;

        SemanticAnalyzer::TypeChecker::Expression e2 = { m.expression.type, *StringPool::get(m.expression.pid) };
        int result = SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_ASSIGN,
                result,
                CodeGenerator::Triples::Operand({SYMBOL, entry}),
                mapWithOperand(m.reference)
            });
        }
    }
}

void createTruncateTriple(Metadata& result, const Metadata& operand)
{
    SemanticAnalyzer::TypeChecker::Expression e = { operand.expression.type, *StringPool::get(operand.expression.pid) };

    if (SemanticAnalyzer::CHK_TYPES.truncateNecessary(e))
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            result.expression.type = SemanticAnalyzer::CHK_TYPES.checkTruncate(e);
            result.reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_FTOI,
                result.expression.type,
                mapWithOperand(operand.reference),
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });
            result.reference.type = TRIPLE;
        }
        else
            result.reference = { NULLREF, nullptr };
        result.expression.assignable = false;
    } else
        result = operand;
}

void createArithmeticTriple(Metadata& r, const Metadata& o1, const Metadata& o2, const char op)
{
    SemanticAnalyzer::TypeChecker::Expression e1 = { o1.expression.type, *StringPool::get(o1.expression.pid) };
    SemanticAnalyzer::TypeChecker::Expression e2 = { o2.expression.type, *StringPool::get(o2.expression.pid) };
    r.expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

    r.expression.pid = o1.expression.pid;
    StringPool::append(o1.expression.pid, " " + std::string(1, op) + " " + *StringPool::get(o2.expression.pid));

    int codeop;
    switch (op)
    {
    case '+':
        codeop = CODEOP_SUM;
        break;
    case '-':
        codeop = CODEOP_SUB;
        break;
    case '*':
        codeop = CODEOP_MUL;
        break;
    case '/':
        codeop = CODEOP_DIV;
        break;
    default:
        codeop = UNKNOWN;
    }

    if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
    {
        r.reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple ({
            codeop,
            r.expression.type,
            mapWithOperand(o1.reference),
            mapWithOperand(o2.reference)
        });
        r.reference.type = TRIPLE;
    }
    else
        r.reference = { NULLREF, nullptr };
    
    r.expression.assignable = false;
}
