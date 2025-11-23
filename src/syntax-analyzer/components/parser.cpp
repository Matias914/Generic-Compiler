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

#include "syntax-analyzer/components/parser.h"
#include "syntax-analyzer/components/translator.h"
#include "syntax-analyzer/components/string_pool.h"
#include "syntax-analyzer/components/semantic_actions.h"

#include "utils/resources/codes.h"
#include "code-generator/code-generator.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"

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


#line 106 "src/syntax-analyzer/components/parser.cpp"

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

#include "syntax-analyzer/components/parser.h"
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
  YYSYMBOL_unnamed_function_declaration_tail = 58, /* unnamed_function_declaration_tail  */
  YYSYMBOL_function_declaration_middle = 59, /* function_declaration_middle  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_function_declaration_tail = 61, /* function_declaration_tail  */
  YYSYMBOL_formal_parameter_list = 62,     /* formal_parameter_list  */
  YYSYMBOL_63_8 = 63,                      /* $@8  */
  YYSYMBOL_formal_parameter = 64,          /* formal_parameter  */
  YYSYMBOL_parameter_semantics = 65,       /* parameter_semantics  */
  YYSYMBOL_function_body = 66,             /* function_body  */
  YYSYMBOL_return = 67,                    /* return  */
  YYSYMBOL_executable_stmt = 68,           /* executable_stmt  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_assignment_head = 70,           /* assignment_head  */
  YYSYMBOL_assignment_tail = 71,           /* assignment_tail  */
  YYSYMBOL_print = 72,                     /* print  */
  YYSYMBOL_73_9 = 73,                      /* $@9  */
  YYSYMBOL_print_end = 74,                 /* print_end  */
  YYSYMBOL_multiple_assignments = 75,      /* multiple_assignments  */
  YYSYMBOL_assignment_list = 76,           /* assignment_list  */
  YYSYMBOL_assignment_end = 77,            /* assignment_end  */
  YYSYMBOL_left_variable = 78,             /* left_variable  */
  YYSYMBOL_79_10 = 79,                     /* $@10  */
  YYSYMBOL_extra_numeric_constants = 80,   /* extra_numeric_constants  */
  YYSYMBOL_81_11 = 81,                     /* $@11  */
  YYSYMBOL_82_12 = 82,                     /* $@12  */
  YYSYMBOL_invocation = 83,                /* invocation  */
  YYSYMBOL_function_invocation_head = 84,  /* function_invocation_head  */
  YYSYMBOL_invocation_setup = 85,          /* invocation_setup  */
  YYSYMBOL_function_invocation_tail = 86,  /* function_invocation_tail  */
  YYSYMBOL_real_parameter_list = 87,       /* real_parameter_list  */
  YYSYMBOL_real_parameter_list_setup = 88, /* real_parameter_list_setup  */
  YYSYMBOL_real_parameter = 89,            /* real_parameter  */
  YYSYMBOL_lambda_invocation_head = 90,    /* lambda_invocation_head  */
  YYSYMBOL_91_13 = 91,                     /* $@13  */
  YYSYMBOL_lambda_invocation_middle = 92,  /* lambda_invocation_middle  */
  YYSYMBOL_93_14 = 93,                     /* $@14  */
  YYSYMBOL_94_15 = 94,                     /* $@15  */
  YYSYMBOL_95_16 = 95,                     /* $@16  */
  YYSYMBOL_lambda_missing_closing_bracket = 96, /* lambda_missing_closing_bracket  */
  YYSYMBOL_lambda_invocation_tail = 97,    /* lambda_invocation_tail  */
  YYSYMBOL_lambda_real_parameter = 98,     /* lambda_real_parameter  */
  YYSYMBOL_if = 99,                        /* if  */
  YYSYMBOL_if_word = 100,                  /* if_word  */
  YYSYMBOL_if_head = 101,                  /* if_head  */
  YYSYMBOL_condition_body_setup = 102,     /* condition_body_setup  */
  YYSYMBOL_condition_setup = 103,          /* condition_setup  */
  YYSYMBOL_then_body_setup = 104,          /* then_body_setup  */
  YYSYMBOL_do_while = 105,                 /* do_while  */
  YYSYMBOL_106_17 = 106,                   /* $@17  */
  YYSYMBOL_do_while_head = 107,            /* do_while_head  */
  YYSYMBOL_do_body = 108,                  /* do_body  */
  YYSYMBOL_109_18 = 109,                   /* $@18  */
  YYSYMBOL_do_while_tail = 110,            /* do_while_tail  */
  YYSYMBOL_executable_body = 111,          /* executable_body  */
  YYSYMBOL_executable_statements = 112,    /* executable_statements  */
  YYSYMBOL_opt_trunc_constant = 113,       /* opt_trunc_constant  */
  YYSYMBOL_trunc_constant = 114,           /* trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 115,       /* opt_trunc_variable  */
  YYSYMBOL_trunc_variable = 116,           /* trunc_variable  */
  YYSYMBOL_trunc_expression = 117,         /* trunc_expression  */
  YYSYMBOL_condition = 118,                /* condition  */
  YYSYMBOL_comparison = 119,               /* comparison  */
  YYSYMBOL_comparison_operator = 120,      /* comparison_operator  */
  YYSYMBOL_expression = 121,               /* expression  */
  YYSYMBOL_expression_setup = 122,         /* expression_setup  */
  YYSYMBOL_term = 123,                     /* term  */
  YYSYMBOL_positive_term = 124,            /* positive_term  */
  YYSYMBOL_negative_term = 125,            /* negative_term  */
  YYSYMBOL_factor = 126,                   /* factor  */
  YYSYMBOL_positive_factor = 127,          /* positive_factor  */
  YYSYMBOL_negative_factor = 128,          /* negative_factor  */
  YYSYMBOL_numeric_constant = 129,         /* numeric_constant  */
  YYSYMBOL_positive_constant = 130,        /* positive_constant  */
  YYSYMBOL_negative_constant = 131,        /* negative_constant  */
  YYSYMBOL_variable = 132                  /* variable  */
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
#define YYLAST   1119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  271
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  412

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
     324,   332,   336,   347,   346,   355,   361,   374,   373,   384,
     395,   410,   411,   413,   412,   420,   426,   432,   440,   445,
     451,   458,   468,   478,   482,   486,   498,   512,   529,   547,
     564,   582,   598,   614,   630,   641,   642,   643,   644,   645,
     646,   647,   653,   676,   685,   702,   709,   722,   735,   748,
     761,   776,   775,   782,   790,   792,   800,   806,   814,   822,
     831,   838,   847,   858,   859,   863,   870,   871,   877,   886,
     890,   902,   902,   909,   911,   911,   915,   917,   916,   926,
     927,   932,   933,   943,   964,   985,  1003,  1011,  1021,  1025,
    1031,  1041,  1049,  1087,  1100,  1099,  1112,  1111,  1118,  1117,
    1124,  1126,  1125,  1136,  1145,  1200,  1201,  1207,  1211,  1218,
    1229,  1244,  1264,  1284,  1305,  1326,  1334,  1343,  1351,  1373,
    1381,  1388,  1409,  1416,  1433,  1450,  1470,  1477,  1492,  1514,
    1519,  1518,  1527,  1538,  1551,  1567,  1576,  1575,  1587,  1588,
    1599,  1603,  1611,  1617,  1621,  1628,  1629,  1635,  1639,  1646,
    1653,  1663,  1672,  1685,  1700,  1707,  1727,  1750,  1773,  1796,
    1808,  1814,  1824,  1833,  1848,  1852,  1860,  1867,  1878,  1901,
    1909,  1916,  1920,  1924,  1928,  1932,  1936,  1945,  1949,  1961,
    1968,  1977,  1981,  1989,  1993,  2001,  2005,  2009,  2016,  2027,
    2031,  2038,  2042,  2046,  2050,  2054,  2058,  2062,  2066,  2070,
    2074,  2082,  2093,  2097,  2101,  2105,  2109,  2113,  2121,  2129,
    2136,  2143,  2152,  2166,  2170,  2177,  2192,  2196,  2203,  2207,
    2214,  2222,  2229,  2245,  2254,  2268,  2272,  2279,  2284,  2292,
    2303,  2310
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
  "$@5", "type", "unnamed_function_declaration_middle", "$@6",
  "unnamed_function_declaration_tail", "function_declaration_middle",
  "$@7", "function_declaration_tail", "formal_parameter_list", "$@8",
  "formal_parameter", "parameter_semantics", "function_body", "return",
  "executable_stmt", "assignment", "assignment_head", "assignment_tail",
  "print", "$@9", "print_end", "multiple_assignments", "assignment_list",
  "assignment_end", "left_variable", "$@10", "extra_numeric_constants",
  "$@11", "$@12", "invocation", "function_invocation_head",
  "invocation_setup", "function_invocation_tail", "real_parameter_list",
  "real_parameter_list_setup", "real_parameter", "lambda_invocation_head",
  "$@13", "lambda_invocation_middle", "$@14", "$@15", "$@16",
  "lambda_missing_closing_bracket", "lambda_invocation_tail",
  "lambda_real_parameter", "if", "if_word", "if_head",
  "condition_body_setup", "condition_setup", "then_body_setup", "do_while",
  "$@17", "do_while_head", "do_body", "$@18", "do_while_tail",
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

#define YYPACT_NINF (-311)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-229)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     708,  -311,   -18,  -311,   911,   466,   102,  -311,  -311,   -11,
    -311,  -311,   173,   728,  -311,  -311,  -311,    55,  -311,  -311,
    -311,   993,  -311,  -311,  -311,    91,   989,   108,  -311,   336,
    -311,  1034,    15,  -311,     5,    27,    40,  1011,    24,  -311,
    -311,   971,   214,    58,   395,   619,  -311,  -311,   192,   428,
     386,  -311,   226,   248,  -311,  -311,  -311,  -311,    39,    99,
     410,  -311,   448,   828,   150,  -311,  -311,   148,   166,  -311,
     203,    39,  -311,   591,  -311,  -311,  -311,  -311,   319,   993,
    -311,   495,  -311,  -311,   189,  1034,   971,   115,   293,  1034,
     924,    13,   551,   937,  -311,  -311,   215,   193,   486,   222,
    -311,   235,   111,   216,   222,  -311,  1029,  -311,   971,   594,
     576,  -311,   192,  -311,  -311,  -311,  -311,  -311,  -311,    39,
    -311,  -311,  -311,  -311,  -311,  -311,   470,   470,  -311,  -311,
     250,   524,   542,   226,   317,   627,   635,   653,  -311,   260,
     264,   285,   848,   271,   277,   868,  -311,  -311,  -311,   748,
    -311,  -311,  -311,   299,  -311,  -311,   440,  -311,  -311,   212,
     222,  -311,  -311,   993,  -311,  -311,  -311,   313,  -311,   331,
      29,  -311,  -311,  -311,  1034,   950,  -311,  -311,  -311,   360,
    1034,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
     504,   324,  -311,  -311,   970,  1029,  1029,  -311,   329,  -311,
      19,  -311,  -311,    47,  -311,   339,   660,  -311,  -311,  -311,
    -311,   320,    39,  -311,   124,   609,  -311,  -311,  -311,  -311,
     127,  -311,  -311,  -311,  -311,  -311,  -311,   192,  -311,  -311,
     192,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,   145,   160,  -311,  -311,   768,
    -311,  -311,  -311,   788,  -311,  -311,  -311,  -311,   440,  -311,
    -311,   213,  -311,   345,  -311,   149,  -311,    39,    39,  -311,
    -311,  -311,  -311,  -311,    21,   363,   316,   371,  -311,   373,
    -311,    31,  -311,  -311,  -311,  -311,   168,  -311,  -311,   320,
     253,    94,    33,  -311,  -311,   320,   669,   320,  -311,    20,
    -311,  -311,  -311,  -311,  -311,  -311,   358,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  1063,  -311,   353,  -311,  -311,
     440,  -311,   440,  -311,  -311,   219,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,   357,  -311,   362,    38,
    -311,  -311,  -311,  -311,  -311,   320,   320,  -311,  -311,  -311,
    -311,  -311,   527,  -311,  1083,  1071,  -311,  -311,   368,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  1086,   678,
    -311,   364,  -311,  -311,  -311,    39,   370,   173,   368,   888,
    -311,   180,   375,   173,   378,   390,     7,  -311,  -311,  1083,
    -311,   181,  -311,   808,  -311,  -311,  -311,  -311,    26,  -311,
    -311,  1083,  -311,  -311,  -311,  -311,  -311,  1083,  -311,  -311,
    -311,  -311
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     4,     0,   150,     0,     0,     0,    41,    42,   270,
       8,    10,     0,     0,     2,     7,     5,     0,    80,     6,
      75,     0,    79,    76,    77,     0,     0,     0,    78,     0,
      81,     0,     0,    11,     0,     0,     0,     0,   270,   268,
     267,     0,     0,     0,     0,     0,   257,   259,   225,     0,
       0,   217,   229,   230,   239,   246,   256,   258,   255,     0,
       0,    15,     0,     0,     0,     1,     3,     0,   270,    34,
       0,    36,    82,     0,   120,   119,   127,   123,   131,     0,
     128,     0,   122,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   169,   176,     0,     0,     0,
     103,     0,     0,   111,     0,   172,     0,    74,     0,     0,
       0,   220,     0,   219,   264,   269,   260,   261,   263,   262,
     251,   249,   253,   254,   252,   250,     0,     0,    70,    73,
      69,     0,     0,   218,     0,     0,     0,     0,    93,     0,
       0,   228,     0,     0,     0,     0,    13,     9,    24,     0,
      20,    22,    23,     0,    30,    32,     0,    31,    29,     0,
       0,    86,    85,     0,   126,   130,   133,     0,   149,     0,
       0,   148,   147,   153,     0,     0,   151,   166,   168,   156,
     159,   207,   206,   209,   211,   213,   214,   212,   215,   216,
       0,     0,   184,   185,     0,     0,     0,   102,     0,   270,
       0,   271,   101,     0,   100,     0,     0,   188,   187,   265,
     266,     0,   112,   171,     0,     0,   203,   202,    68,    71,
       0,   236,   234,   235,   233,    72,   222,   226,   221,   224,
     227,   223,   240,   238,   231,   241,   237,   232,   247,   245,
     242,   248,   244,   243,    91,     0,     0,    19,    16,     0,
     124,    28,    25,     0,    14,    12,    21,   134,     0,    62,
      57,     0,    35,    53,    51,     0,    40,    37,    39,   129,
     132,   162,   205,   204,     0,   158,     0,     0,   155,     0,
     210,   228,   182,   181,   180,   186,     0,   177,    83,     0,
       0,     0,     0,    97,    96,     0,     0,     0,   106,     0,
     179,   178,   201,   200,    67,    66,    95,    88,    87,    90,
      89,    18,    17,    27,    26,     0,    33,    53,    56,    55,
       0,    43,     0,    60,    61,     0,   165,   164,   161,   154,
     163,   152,   157,   160,   175,   174,     0,   108,   107,     0,
     192,   191,   113,    99,    98,     0,     0,   115,   110,   109,
      94,    92,     0,   135,     0,     0,    47,    52,     0,    54,
      59,    58,   105,   104,   190,   189,   116,   118,     0,     0,
     140,     0,   146,   145,   194,   193,     0,   141,     0,     0,
      44,     0,     0,   143,     0,     0,     0,   144,   138,     0,
      48,     0,    64,     0,    46,    45,   136,   199,     0,   198,
     197,     0,   142,    50,    49,    65,    63,     0,   196,   195,
     139,   137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -311,  -311,   402,  -311,  -311,    73,  -311,  -311,  -139,  -148,
     140,  -311,  -311,  -311,  -311,    14,  -311,  -311,  -311,  -311,
    -311,  -311,   162,  -311,    25,  -311,    45,  -311,   113,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,   -92,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,     9,  -311,  -311,  -311,  -311,   -75,
      48,  -311,  -311,  -311,  -311,  -311,  -311,  -109,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
     234,   -60,  -310,   -90,  -311,  -311,  -311,   177,   -27,   350,
    -311,    69,  -311,   -35,   388,  -311,    30,   134,   147,  -184,
     -79,    36,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    13,    14,    63,   147,   148,   142,   248,   149,   150,
     151,   258,   156,    70,   160,    17,   262,   358,   380,   316,
     378,   390,   263,   322,   264,   265,   381,    18,   152,    20,
      21,    72,    22,   306,   351,    23,   102,   298,   103,   104,
     296,   297,   346,    24,    46,    26,    77,    78,    79,    80,
      47,   315,   353,   407,   401,   389,   354,   370,   371,    28,
      29,    87,    88,    89,   177,    30,    35,    31,    95,   196,
     213,    96,   194,   372,   207,   373,   374,    48,   214,    91,
     190,    92,    50,    51,    52,    53,   121,    54,    55,   208,
      56,    57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   256,    90,   249,   165,   355,   253,   113,   399,    25,
      33,   211,   206,    32,   181,    61,    97,    71,    62,   292,
     289,   348,    25,   209,   326,   169,    64,   408,   327,   178,
     272,    32,  -208,   105,   340,    98,   106,  -111,   400,   364,
      25,  -111,   368,   119,   182,    99,   101,   100,    27,    99,
     349,   100,   117,    62,   101,    64,    67,   409,   101,   114,
     273,    27,  -208,    32,   341,   101,   131,   132,   107,   365,
      39,    40,    25,    15,    49,   125,   291,    68,   101,    27,
      38,   115,   116,   205,    69,    32,    15,    12,   269,    32,
      73,   118,    74,    32,    25,    81,   228,   231,    25,   200,
      64,   256,    25,    59,   212,   256,   109,   339,   290,    82,
     110,    27,   202,    19,   274,   276,   171,    39,    40,    75,
     279,   299,    64,   203,   209,   300,    19,   138,   304,   141,
     205,    60,   209,    27,    39,    40,    83,    27,   210,   204,
      16,    27,    32,   172,    94,    32,   307,   205,    81,    32,
     323,    25,   301,    16,    25,   305,   222,   224,    25,   267,
     268,   309,     7,     8,   234,   237,   240,   243,   286,   334,
     261,   324,   153,   308,    32,    32,   154,   215,   122,   122,
      32,   394,   403,    25,    25,   292,     7,     8,   310,    25,
      27,   123,   123,    27,    32,   155,   335,    27,    94,   336,
     338,   339,    94,    25,   157,   342,   193,   347,   395,   404,
     209,   209,   209,   266,   318,   111,   209,   168,   209,   112,
     360,   197,    27,    27,   195,   -38,    37,   112,    27,   126,
     127,   158,    81,   159,   199,   319,    38,    39,    40,   210,
     393,   361,    27,    12,   199,   256,    99,   210,   100,    32,
      43,    44,    45,    32,   337,   366,   367,   201,    25,   281,
     122,   122,    25,   134,   135,   203,   209,   209,   122,   122,
     122,   122,   261,   123,   123,   209,    39,    40,   225,   325,
     402,   123,   123,   123,   123,   136,   137,    94,    94,   205,
     209,   244,   410,    94,   173,   245,   174,    27,   411,   175,
     176,    27,   250,   221,   223,   251,   209,   285,   227,   230,
     209,   233,   236,   239,   242,    32,   246,   329,   232,   330,
     131,   132,   209,   331,    25,   210,   210,   210,   209,    37,
     257,   210,   203,   210,   261,   270,   261,    84,   271,    38,
      39,    40,    85,    39,    40,   357,    12,   359,    37,   163,
     164,   282,    32,    43,   375,    32,   205,   288,    38,    39,
      40,    25,   115,    27,    25,    86,   277,   278,    32,   386,
     328,    42,    43,    44,    45,   320,   321,    25,   332,    32,
     333,   210,   210,   320,   356,   398,   350,   362,    25,   375,
     210,    64,   363,    32,   379,   387,   120,    64,    37,   388,
      27,   375,    25,    27,   396,   210,   397,   375,    38,    39,
      40,   139,   199,    39,    40,    66,    27,    38,    39,    40,
     317,   210,    37,   391,    12,   210,   205,    27,   193,   128,
     287,    43,    38,    39,    40,   140,   170,   210,   133,    12,
    -228,    27,     0,   210,     0,    42,    43,    44,    45,   143,
    -228,  -228,  -228,     7,     8,   259,   129,     0,     0,   130,
    -125,     0,   260,   131,   132,   193,     0,    36,   285,     0,
    -125,  -125,  -125,     0,     0,     0,     0,  -125,    37,  -125,
       0,   285,    37,  -125,  -125,  -125,  -125,   198,    38,    39,
      40,     0,    38,    39,    40,    41,   166,     0,   -84,    12,
       0,    42,    43,    44,    45,   280,    43,  -228,   -84,   -84,
     -84,   167,     0,     0,     0,   -84,    37,  -228,  -228,  -228,
       0,   -84,   -84,   -84,   -84,   226,    38,    39,    40,     0,
     131,   132,     3,    12,     0,     4,    37,     5,     6,    42,
      43,    44,    45,   229,     0,     0,    38,    39,    40,    38,
       0,     0,   183,    12,    37,     0,    12,     0,     0,     0,
      43,    44,    45,  -228,    38,    39,    40,     0,   184,   185,
     186,    12,   187,  -228,  -228,  -228,     0,   218,    43,    44,
      45,     0,     0,     0,   188,   189,   131,   132,  -228,     0,
       0,     0,   161,     0,     0,   216,     0,     0,  -228,  -228,
    -228,     0,     0,  -228,   219,     0,  -228,   220,     0,     0,
     302,   131,   132,  -228,  -228,  -228,  -228,  -228,  -228,   162,
     124,  -228,     0,     0,     0,   217,   131,   132,   235,   131,
     132,  -228,  -228,  -228,     0,     0,   238,     0,     0,    37,
     303,    38,    39,    40,   131,   132,     0,    37,    12,    38,
      39,    40,     0,     0,   241,    43,    12,    38,    39,    40,
       0,   293,     0,    43,    12,    37,     0,     0,     0,     0,
     343,    43,  -114,     0,     0,    38,    39,    40,     0,   384,
       0,  -117,    12,  -114,  -114,     0,     0,     0,   294,    43,
     295,     0,  -117,  -117,     0,     0,  -114,   344,     0,   345,
     199,    39,    40,     0,     0,  -117,     0,   385,     1,     2,
       0,     0,     0,     3,   205,     0,     4,     0,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,    65,     2,
       9,     0,     0,     3,    10,    11,     4,    12,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,   254,   144,
       9,     0,     0,     3,    10,    11,     4,    12,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,   311,   144,
       9,     0,     0,     3,   145,   255,     4,    12,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,   313,   144,
       9,     0,     0,     3,   145,   312,     4,    12,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,   405,   144,
       9,     0,     0,     3,   145,   314,     4,    12,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,     0,   144,
       9,     0,     0,     3,   145,   406,     4,    12,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,     0,   144,
       9,     0,     0,     3,   145,   146,     4,    12,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,     0,   144,
       9,     0,     0,     3,   145,   247,     4,    12,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,     0,   144,
       9,     0,     0,     3,   145,   252,     4,    12,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       9,     0,    34,     0,   145,   392,  -173,    12,     0,  -173,
    -170,  -173,  -173,     0,     0,   179,     0,     0,     0,  -167,
     180,     0,  -167,  -173,  -167,  -167,     0,  -173,   191,     0,
    -173,     0,     3,     0,     0,     4,  -167,     5,     6,     0,
    -167,   275,     0,  -167,     0,     3,     0,     0,     4,    38,
       5,     6,     0,     0,   192,     0,    12,     0,     0,     0,
       0,   283,    38,     0,     0,     3,    93,     0,     4,    12,
       5,     6,     0,    37,     7,     8,     0,     0,     0,     0,
       0,     0,    38,    38,    39,    40,     0,   284,     0,    12,
      12,    37,     0,     0,     0,    37,    42,    43,    44,    45,
       0,    38,    39,    40,     0,    38,    39,    40,    12,     0,
      76,     0,    12,    37,    42,    43,    44,    45,    42,    43,
      44,    45,     0,    38,    39,    40,     0,     0,     0,     3,
     108,    37,     4,     0,     5,     6,    42,    43,    44,    45,
       0,    38,    39,    40,     0,     0,    38,     0,    86,     0,
      93,     0,     0,    12,    42,    43,    44,    45,     3,     0,
       0,     4,     0,     5,     6,     0,     3,     0,     0,     4,
       0,     5,     6,     0,     0,    38,     0,     0,     0,   352,
       0,     3,    12,    38,     4,   369,     5,     6,   376,     0,
     377,     0,     0,     0,     0,   199,    39,    40,    38,     0,
       0,     0,     0,   382,     0,   383,     0,     0,     0,   205
};

static const yytype_int16 yycheck[] =
{
       0,   149,    29,   142,    79,   315,   145,    42,     1,     0,
      28,   103,   102,    13,     1,    26,     1,    17,    29,   203,
       1,     1,    13,   102,     3,    85,    12,     1,     7,    89,
       1,    31,     1,    28,     1,    20,     9,    22,    31,     1,
      31,    22,   352,    43,    31,    30,    39,    32,     0,    30,
      30,    32,    43,    29,    39,    41,     1,    31,    39,     1,
      31,    13,    31,    63,    31,    39,    35,    36,    28,    31,
      23,    24,    63,     0,     5,    45,    29,    22,    39,    31,
      22,    23,    24,    36,    29,    85,    13,    29,   163,    89,
      21,    43,     1,    93,    85,    26,   131,   132,    89,    99,
      86,   249,    93,     1,   104,   253,    37,   291,   200,     1,
      41,    63,     1,     0,   174,   175,     1,    23,    24,    28,
     180,   211,   108,    12,   203,     1,    13,    28,     1,    60,
      36,    29,   211,    85,    23,    24,    28,    89,   102,    28,
       0,    93,   142,    28,    31,   145,     1,    36,    79,   149,
       1,   142,    28,    13,   145,    28,   126,   127,   149,   159,
     160,     1,    13,    14,   134,   135,   136,   137,   195,     1,
     156,    22,    22,    28,   174,   175,    28,   108,    44,    45,
     180,     1,     1,   174,   175,   369,    13,    14,    28,   180,
     142,    44,    45,   145,   194,    29,    28,   149,    85,   289,
     290,   385,    89,   194,     1,   295,    93,   297,    28,    28,
     289,   290,   291,     1,     1,     1,   295,    28,   297,    42,
       1,    28,   174,   175,     9,    22,    12,    50,   180,    37,
      38,    28,   163,    30,    22,    22,    22,    23,    24,   203,
     379,    22,   194,    29,    22,   393,    30,   211,    32,   249,
      36,    37,    38,   253,     1,   345,   346,    22,   249,   190,
     126,   127,   253,    37,    38,    12,   345,   346,   134,   135,
     136,   137,   258,   126,   127,   354,    23,    24,    28,   265,
     389,   134,   135,   136,   137,    37,    38,   174,   175,    36,
     369,    31,   401,   180,     1,    31,     3,   249,   407,     6,
       7,   253,    31,   126,   127,    28,   385,   194,   131,   132,
     389,   134,   135,   136,   137,   315,    31,     1,     1,     3,
      35,    36,   401,     7,   315,   289,   290,   291,   407,    12,
      31,   295,    12,   297,   320,    22,   322,     1,     7,    22,
      23,    24,     6,    23,    24,   320,    29,   322,    12,    30,
      31,    27,   352,    36,   354,   355,    36,    28,    22,    23,
      24,   352,    23,   315,   355,    29,     6,     7,   368,   369,
       7,    35,    36,    37,    38,    30,    31,   368,     7,   379,
       7,   345,   346,    30,    31,   385,    28,    30,   379,   389,
     354,   377,    30,   393,    26,    31,     1,   383,    12,    29,
     352,   401,   393,   355,    29,   369,    28,   407,    22,    23,
      24,     1,    22,    23,    24,    13,   368,    22,    23,    24,
     258,   385,    12,   378,    29,   389,    36,   379,   315,     1,
     196,    36,    22,    23,    24,    25,    86,   401,    50,    29,
      12,   393,    -1,   407,    -1,    35,    36,    37,    38,     1,
      22,    23,    24,    13,    14,    15,    28,    -1,    -1,    31,
      12,    -1,    22,    35,    36,   352,    -1,     1,   355,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    29,    12,    31,
      -1,   368,    12,    35,    36,    37,    38,     1,    22,    23,
      24,    -1,    22,    23,    24,    29,     1,    -1,    12,    29,
      -1,    35,    36,    37,    38,     1,    36,    12,    22,    23,
      24,    16,    -1,    -1,    -1,    29,    12,    22,    23,    24,
      -1,    35,    36,    37,    38,     1,    22,    23,    24,    -1,
      35,    36,     5,    29,    -1,     8,    12,    10,    11,    35,
      36,    37,    38,     1,    -1,    -1,    22,    23,    24,    22,
      -1,    -1,     1,    29,    12,    -1,    29,    -1,    -1,    -1,
      36,    37,    38,    12,    22,    23,    24,    -1,    17,    18,
      19,    29,    21,    22,    23,    24,    -1,     1,    36,    37,
      38,    -1,    -1,    -1,    33,    34,    35,    36,    12,    -1,
      -1,    -1,     1,    -1,    -1,     1,    -1,    -1,    22,    23,
      24,    -1,    -1,    12,    28,    -1,    12,    31,    -1,    -1,
       1,    35,    36,    22,    23,    24,    22,    23,    24,    28,
       1,    12,    -1,    -1,    -1,    31,    35,    36,     1,    35,
      36,    22,    23,    24,    -1,    -1,     1,    -1,    -1,    12,
      31,    22,    23,    24,    35,    36,    -1,    12,    29,    22,
      23,    24,    -1,    -1,     1,    36,    29,    22,    23,    24,
      -1,     1,    -1,    36,    29,    12,    -1,    -1,    -1,    -1,
       1,    36,    12,    -1,    -1,    22,    23,    24,    -1,     1,
      -1,    12,    29,    23,    24,    -1,    -1,    -1,    28,    36,
      30,    -1,    23,    24,    -1,    -1,    36,    28,    -1,    30,
      22,    23,    24,    -1,    -1,    36,    -1,    29,     0,     1,
      -1,    -1,    -1,     5,    36,    -1,     8,    -1,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,     0,     1,
      22,    -1,    -1,     5,    26,    27,     8,    29,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,     0,     1,
      22,    -1,    -1,     5,    26,    27,     8,    29,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,     0,     1,
      22,    -1,    -1,     5,    26,    27,     8,    29,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,     0,     1,
      22,    -1,    -1,     5,    26,    27,     8,    29,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,     0,     1,
      22,    -1,    -1,     5,    26,    27,     8,    29,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      22,    -1,    -1,     5,    26,    27,     8,    29,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      22,    -1,    -1,     5,    26,    27,     8,    29,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      22,    -1,    -1,     5,    26,    27,     8,    29,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      22,    -1,    -1,     5,    26,    27,     8,    29,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,     1,    -1,    26,    27,     5,    29,    -1,     8,
       9,    10,    11,    -1,    -1,     1,    -1,    -1,    -1,     5,
       6,    -1,     8,    22,    10,    11,    -1,    26,     1,    -1,
      29,    -1,     5,    -1,    -1,     8,    22,    10,    11,    -1,
      26,     1,    -1,    29,    -1,     5,    -1,    -1,     8,    22,
      10,    11,    -1,    -1,    27,    -1,    29,    -1,    -1,    -1,
      -1,     1,    22,    -1,    -1,     5,    26,    -1,     8,    29,
      10,    11,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    22,    23,    24,    -1,    27,    -1,    29,
      29,    12,    -1,    -1,    -1,    12,    35,    36,    37,    38,
      -1,    22,    23,    24,    -1,    22,    23,    24,    29,    -1,
      31,    -1,    29,    12,    35,    36,    37,    38,    35,    36,
      37,    38,    -1,    22,    23,    24,    -1,    -1,    -1,     5,
      29,    12,     8,    -1,    10,    11,    35,    36,    37,    38,
      -1,    22,    23,    24,    -1,    -1,    22,    -1,    29,    -1,
      26,    -1,    -1,    29,    35,    36,    37,    38,     5,    -1,
      -1,     8,    -1,    10,    11,    -1,     5,    -1,    -1,     8,
      -1,    10,    11,    -1,    -1,    22,    -1,    -1,    -1,    26,
      -1,     5,    29,    22,     8,    12,    10,    11,    27,    -1,
      29,    -1,    -1,    -1,    -1,    22,    23,    24,    22,    -1,
      -1,    -1,    -1,    27,    -1,    29,    -1,    -1,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     0,     1,     5,     8,    10,    11,    13,    14,    22,
      26,    27,    29,    41,    42,    45,    50,    55,    67,    68,
      69,    70,    72,    75,    83,    84,    85,    90,    99,   100,
     105,   107,   132,    28,     1,   106,     1,    12,    22,    23,
      24,    29,    35,    36,    37,    38,    84,    90,   117,   121,
     122,   123,   124,   125,   127,   128,   130,   131,   132,     1,
      29,    26,    29,    43,    55,     0,    42,     1,    22,    29,
      53,   132,    71,   121,     1,    28,    31,    86,    87,    88,
      89,   121,     1,    28,     1,     6,    29,   101,   102,   103,
     118,   119,   121,    26,    68,   108,   111,     1,    20,    30,
      32,    39,    76,    78,    79,    28,     9,    28,    29,   121,
     121,     1,   117,   123,     1,    23,    24,    84,    90,   132,
       1,   126,   127,   128,     1,   126,    37,    38,     1,    28,
      31,    35,    36,   124,    37,    38,    37,    38,    28,     1,
      25,   121,    46,     1,     1,    26,    27,    44,    45,    48,
      49,    50,    68,    22,    28,    29,    52,     1,    28,    30,
      54,     1,    28,    30,    31,    89,     1,    16,    28,   111,
     119,     1,    28,     1,     3,     6,     7,   104,   111,     1,
       6,     1,    31,     1,    17,    18,    19,    21,    33,    34,
     120,     1,    27,    68,   112,     9,   109,    28,     1,    22,
     132,    22,     1,    12,    28,    36,   113,   114,   129,   130,
     131,    76,   132,   110,   118,   121,     1,    31,     1,    28,
      31,   117,   126,   117,   126,    28,     1,   117,   123,     1,
     117,   123,     1,   117,   126,     1,   117,   126,     1,   117,
     126,     1,   117,   126,    31,    31,    31,    27,    47,    48,
      31,    28,    27,    48,     0,    27,    49,    31,    51,    15,
      22,    55,    56,    62,    64,    65,     1,   132,   132,    89,
      22,     7,     1,    31,   111,     1,   111,     6,     7,   111,
       1,   121,    27,     1,    27,    68,   118,   110,    28,     1,
      76,    29,   129,     1,    28,    30,    80,    81,    77,   113,
       1,    28,     1,    31,     1,    28,    73,     1,    28,     1,
      28,     0,    27,     0,    27,    91,    59,    62,     1,    22,
      30,    31,    63,     1,    22,    55,     3,     7,     7,     1,
       3,     7,     7,     7,     1,    28,   113,     1,   113,   129,
       1,    31,   113,     1,    28,    30,    82,   113,     1,    30,
      28,    74,    26,    92,    96,   112,    31,    64,    57,    64,
       1,    22,    30,    30,     1,    31,   113,   113,   112,    12,
      97,    98,   113,   115,   116,   132,    27,    29,    60,    26,
      58,    66,    27,    29,     1,    29,   132,    31,    29,    95,
      61,    66,    27,    48,     1,    28,    29,    28,   132,     1,
      31,    94,    97,     1,    28,     0,    27,    93,     1,    31,
      97,    97
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    41,    42,    42,    42,    43,    42,
      42,    42,    44,    44,    44,    46,    45,    47,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    49,    50,
      50,    50,    51,    50,    52,    50,    53,    53,    54,    53,
      53,    55,    55,    57,    56,    58,    58,    60,    59,    61,
      61,    62,    62,    63,    62,    64,    64,    64,    64,    64,
      64,    64,    65,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    71,    71,    72,    72,    72,
      72,    73,    72,    72,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    77,
      77,    79,    78,    80,    81,    80,    80,    82,    80,    83,
      83,    83,    83,    84,    84,    85,    86,    86,    87,    87,
      87,    88,    89,    89,    91,    90,    93,    92,    94,    92,
      92,    95,    92,    96,    97,    98,    98,    99,    99,    99,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   103,   104,   105,
     106,   105,   105,   107,   108,   108,   109,   108,   110,   110,
     111,   111,   111,   111,   111,   112,   112,   113,   113,   114,
     114,   114,   114,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   118,   118,   118,   118,   119,   119,
     119,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   122,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   129,   129,   130,   130,   131,
     132,   132
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     3,
       1,     2,     2,     1,     2,     0,     4,     2,     2,     1,
       1,     2,     1,     1,     1,     2,     3,     3,     2,     3,
       3,     3,     0,     5,     0,     4,     1,     3,     0,     3,
       3,     1,     1,     0,     4,     2,     2,     0,     4,     2,
       2,     1,     3,     0,     3,     2,     2,     1,     3,     3,
       2,     2,     1,     3,     2,     3,     5,     5,     4,     3,
       3,     4,     4,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     2,     2,     2,     5,     5,     5,
       5,     0,     6,     3,     1,     0,     4,     4,     5,     5,
       3,     3,     3,     1,     5,     5,     3,     4,     4,     2,
       2,     0,     2,     2,     0,     2,     3,     0,     3,     2,
       2,     2,     2,     2,     4,     2,     2,     1,     1,     3,
       2,     1,     3,     2,     0,     6,     0,     6,     0,     5,
       2,     0,     4,     3,     2,     1,     1,     3,     3,     3,
       1,     2,     4,     2,     4,     3,     2,     4,     3,     2,
       4,     4,     3,     4,     4,     4,     2,     1,     1,     2,
       0,     4,     3,     1,     4,     4,     0,     3,     2,     2,
       3,     3,     3,     1,     2,     1,     2,     1,     1,     4,
       4,     3,     3,     1,     1,     4,     4,     3,     3,     3,
       4,     4,     3,     3,     3,     3,     2,     2,     3,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     2,
       1,     3
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
#line 1689 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 138 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1697 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 8: /* $@1: %empty  */
#line 143 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::addInvalidScope();
        SemanticActions::announceSpecificError(MISSING_PROGRAM_NAME);

        SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration("");

    }
#line 1709 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '}'  */
#line 152 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1717 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: error ';'  */
#line 156 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1726 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* unnamed_program_tail: program_statements '}'  */
#line 164 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1734 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* unnamed_program_tail: '}'  */
#line 168 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1742 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* unnamed_program_tail: program_statements $end  */
#line 172 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1751 "src/syntax-analyzer/components/parser.cpp"
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
#line 1767 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 17: /* program_tail: program_statements '}'  */
#line 198 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1776 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 18: /* program_tail: program_statements $end  */
#line 203 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticAnalyzer::removeScope();
    }
#line 1785 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 19: /* program_tail: '}'  */
#line 208 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1794 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statements: program_statement  */
#line 217 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 1800 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statements: program_statements program_statement  */
#line 218 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 1806 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: declarative_stmt  */
#line 223 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 1814 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* program_statement: executable_stmt  */
#line 227 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 1822 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* program_statement: program_head  */
#line 231 "include/syntax-analyzer/components/yacc.y"
    {
       (yyval.returnable) = false;

       SemanticActions::announceSpecificError(INVALID_PROGRAM_NESTING);

    }
#line 1833 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* program_statement: '{' '}'  */
#line 238 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1844 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* program_statement: '{' program_statements '}'  */
#line 245 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1855 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* program_statement: '{' program_statements $end  */
#line 252 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1867 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* program_statement: error ';'  */
#line 260 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;

    }
#line 1876 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type variable_list ';'  */
#line 270 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("VARIABLE DECLARATION");
    }
#line 1884 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* declarative_stmt: type error ';'  */
#line 274 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1893 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 31: /* declarative_stmt: type variable_list error  */
#line 279 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1902 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* $@3: %empty  */
#line 284 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction (
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, (yyvsp[-1].sref)->symbol})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionName((yyvsp[-1].sref)->symbol);

    }
#line 1914 "src/syntax-analyzer/components/parser.cpp"
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
#line 1928 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 36: /* variable_list: variable  */
#line 309 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1936 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* variable_list: variable_list ',' variable  */
#line 313 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1944 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 38: /* $@5: %empty  */
#line 317 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 1952 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 39: /* variable_list: variable_list $@5 variable  */
#line 321 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1960 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* variable_list: variable_list ',' error  */
#line 325 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1969 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* type: WORD_UINT  */
#line 333 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UINT;
    }
#line 1977 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* type: WORD_FLOAT  */
#line 337 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = FLOAT;
        SemanticActions::announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1986 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* $@6: %empty  */
#line 347 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();

    }
#line 1995 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* unnamed_function_declaration_tail: function_body ';'  */
#line 356 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

    }
#line 2005 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* unnamed_function_declaration_tail: function_body error  */
#line 362 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2018 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* $@7: %empty  */
#line 374 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
        if (entry != nullptr)
            CodeGenerator::addIntermediateCodeBlock(entry);

    }
#line 2029 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 49: /* function_declaration_tail: function_body ';'  */
#line 385 "include/syntax-analyzer/components/yacc.y"
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn((yyvsp[-1].returnable));
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::logStructure("FUNCTION DECLARATION");

    }
#line 2044 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 50: /* function_declaration_tail: function_body error  */
#line 396 "include/syntax-analyzer/components/yacc.y"
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn((yyvsp[-1].returnable));
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2060 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 53: /* $@8: %empty  */
#line 413 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2068 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* formal_parameter: type IDENTIFIER  */
#line 421 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2078 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 56: /* formal_parameter: type error  */
#line 427 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2088 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* formal_parameter: IDENTIFIER  */
#line 433 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2100 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* formal_parameter: parameter_semantics type IDENTIFIER  */
#line 441 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2109 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* formal_parameter: parameter_semantics type error  */
#line 446 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2119 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* formal_parameter: parameter_semantics error  */
#line 452 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        SemanticActions::announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;

    }
#line 2130 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 459 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2141 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* parameter_semantics: WORD_CR  */
#line 469 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CR);

    }
#line 2150 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* function_body: '{' program_statements '}'  */
#line 479 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 2158 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* function_body: '{' '}'  */
#line 483 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 2166 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 65: /* function_body: '{' program_statements $end  */
#line 487 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    }
#line 2177 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 66: /* return: WORD_RETURN '(' expression ')' ';'  */
#line 499 "include/syntax-analyzer/components/yacc.y"
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
#line 2195 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 67: /* return: WORD_RETURN '(' expression ')' error  */
#line 513 "include/syntax-analyzer/components/yacc.y"
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
#line 2216 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 68: /* return: WORD_RETURN '(' expression error  */
#line 530 "include/syntax-analyzer/components/yacc.y"
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
#line 2238 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 69: /* return: WORD_RETURN expression ')'  */
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

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);

    }
#line 2259 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* return: WORD_RETURN expression error  */
#line 565 "include/syntax-analyzer/components/yacc.y"
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
#line 2281 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* return: WORD_RETURN '(' expression ';'  */
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

        SemanticActions::announceSpecificError(MISSING_CLOSING_PARENTHESIS);

    }
#line 2301 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* return: WORD_RETURN expression ')' ';'  */
#line 599 "include/syntax-analyzer/components/yacc.y"
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
#line 2321 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 73: /* return: WORD_RETURN expression ';'  */
#line 615 "include/syntax-analyzer/components/yacc.y"
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
#line 2341 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 74: /* return: WORD_RETURN error ';'  */
#line 631 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(RETURN_SYNTAX_ERROR);
        yyerrok;

    }
#line 2351 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* executable_stmt: assignment  */
#line 641 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2357 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* executable_stmt: multiple_assignments  */
#line 642 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2363 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 77: /* executable_stmt: invocation  */
#line 643 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2369 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 78: /* executable_stmt: if  */
#line 644 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2375 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 79: /* executable_stmt: print  */
#line 645 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2381 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 80: /* executable_stmt: return  */
#line 646 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = true;  }
#line 2387 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* executable_stmt: do_while  */
#line 647 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2393 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 82: /* assignment: assignment_head assignment_tail  */
#line 654 "include/syntax-analyzer/components/yacc.y"
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
#line 2420 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* assignment: variable OP_ASSIGN error ';'  */
#line 677 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2430 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 84: /* assignment_head: variable OP_ASSIGN  */
#line 686 "include/syntax-analyzer/components/yacc.y"
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
#line 2448 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 85: /* assignment_tail: expression ';'  */
#line 703 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::logStructure("ASSIGNMENT");

    }
#line 2459 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 86: /* assignment_tail: expression error  */
#line 710 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2471 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* print: WORD_PRINT '(' LITERAL_STRING ')' ';'  */
#line 723 "include/syntax-analyzer/components/yacc.y"
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
#line 2488 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 88: /* print: WORD_PRINT '(' LITERAL_STRING ')' error  */
#line 736 "include/syntax-analyzer/components/yacc.y"
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
#line 2505 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 89: /* print: WORD_PRINT '(' expression ')' ';'  */
#line 749 "include/syntax-analyzer/components/yacc.y"
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
#line 2522 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* print: WORD_PRINT '(' expression ')' error  */
#line 762 "include/syntax-analyzer/components/yacc.y"
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
#line 2540 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 91: /* $@9: %empty  */
#line 776 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;

    }
#line 2550 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 93: /* print: WORD_PRINT error ';'  */
#line 783 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(PRINT_SYNTAX_ERROR);
        yyerrok;
    }
#line 2559 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* print_end: %empty  */
#line 792 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
    }
#line 2567 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* multiple_assignments: variable assignment_list opt_trunc_constant ';'  */
#line 801 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2577 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* multiple_assignments: variable assignment_list opt_trunc_constant error  */
#line 807 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2589 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 98: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 815 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2601 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 99: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 823 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2614 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 100: /* multiple_assignments: variable assignment_list ';'  */
#line 832 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::announceSpecificError(MISSING_RIGHT_SIDE_VALUES);

    }
#line 2625 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* multiple_assignments: variable assignment_list error  */
#line 839 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2638 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* multiple_assignments: variable error ';'  */
#line 848 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;

    }
#line 2650 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 104: /* assignment_list: ',' variable assignment_list opt_trunc_constant ','  */
#line 860 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2658 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 105: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 864 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_EQUALS);

    }
#line 2669 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 107: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 872 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[0].metadata));
        SemanticActions::announceSpecificError(MISSING_COMMA);

    }
#line 2679 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* assignment_list: ',' variable assignment_list error  */
#line 878 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2689 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* assignment_end: opt_trunc_constant ','  */
#line 887 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2697 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* assignment_end: opt_trunc_constant error  */
#line 891 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_COMMA);
        yyerrok;

    }
#line 2709 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* $@10: %empty  */
#line 902 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_COMMA);
    }
#line 2717 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 114: /* $@11: %empty  */
#line 911 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2725 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 117: /* $@12: %empty  */
#line 917 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2733 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* invocation: function_invocation_head error  */
#line 928 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2742 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* invocation: lambda_invocation_head error  */
#line 934 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2751 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* function_invocation_head: invocation_setup function_invocation_tail  */
#line 944 "include/syntax-analyzer/components/yacc.y"
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
#line 2776 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 124: /* function_invocation_head: IDENTIFIER '(' error ')'  */
#line 965 "include/syntax-analyzer/components/yacc.y"
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
#line 2798 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 125: /* invocation_setup: IDENTIFIER '('  */
#line 986 "include/syntax-analyzer/components/yacc.y"
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
#line 2817 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* function_invocation_tail: real_parameter_list ')'  */
#line 1004 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, ")");
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
    }
#line 2829 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* function_invocation_tail: ')'  */
#line 1012 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = { UNKNOWN, StringPool::create(")") };

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
        SemanticActions::announceSpecificError(MISSING_ARGUMENT);
    }
#line 2840 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* real_parameter_list: real_parameter  */
#line 1022 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 2848 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 129: /* real_parameter_list: real_parameter_list ',' real_parameter  */
#line 1026 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].metadata).expression.pid, ", " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
    }
#line 2858 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* real_parameter_list: real_parameter_list_setup real_parameter  */
#line 1032 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

    }
#line 2869 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 131: /* real_parameter_list_setup: real_parameter_list  */
#line 1042 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2878 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 132: /* real_parameter: expression OP_POINTER IDENTIFIER  */
#line 1050 "include/syntax-analyzer/components/yacc.y"
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
#line 2920 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* real_parameter: expression error  */
#line 1088 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2931 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 134: /* $@13: %empty  */
#line 1100 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclaration((yyvsp[-1].sref)->symbol);
        CodeGenerator::addIntermediateCodeBlock (
              SemanticAnalyzer::CHK_LAMBDAS.getLambda().function
        );

    }
#line 2943 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 136: /* $@14: %empty  */
#line 1112 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

    }
#line 2952 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* $@15: %empty  */
#line 1118 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);

    }
#line 2962 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* $@16: %empty  */
#line 1126 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::announceSpecificError(MISSING_BOTH_BRACKETS);

    }
#line 2973 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* lambda_missing_closing_bracket: '{' executable_statements '('  */
#line 1137 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    }
#line 2983 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* lambda_invocation_tail: lambda_real_parameter ')'  */
#line 1146 "include/syntax-analyzer/components/yacc.y"
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
#line 3039 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* lambda_real_parameter: opt_trunc_variable  */
#line 1200 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3045 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 146: /* lambda_real_parameter: opt_trunc_constant  */
#line 1201 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3051 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 147: /* if: if_word if_head ';'  */
#line 1208 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3059 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 148: /* if: if_word if_head error  */
#line 1212 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 3070 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* if: if_word error ';'  */
#line 1219 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;

    }
#line 3082 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 150: /* if_word: WORD_IF  */
#line 1230 "include/syntax-analyzer/components/yacc.y"
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
#line 3098 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* if_head: condition_body_setup WORD_ENDIF  */
#line 1245 "include/syntax-analyzer/components/yacc.y"
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
#line 3122 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 152: /* if_head: condition_body_setup WORD_ELSE executable_body WORD_ENDIF  */
#line 1265 "include/syntax-analyzer/components/yacc.y"
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
#line 3146 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 153: /* if_head: condition_body_setup error  */
#line 1285 "include/syntax-analyzer/components/yacc.y"
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
#line 3171 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 154: /* if_head: condition_body_setup WORD_ELSE executable_body error  */
#line 1306 "include/syntax-analyzer/components/yacc.y"
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
#line 3196 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 155: /* if_head: condition error WORD_ENDIF  */
#line 1327 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3208 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* if_head: condition error  */
#line 1335 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3221 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 157: /* if_head: condition error WORD_ELSE WORD_ENDIF  */
#line 1344 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3233 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* if_head: condition_body_setup WORD_ELSE error  */
#line 1352 "include/syntax-analyzer/components/yacc.y"
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
#line 3259 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 159: /* if_head: condition WORD_ELSE  */
#line 1374 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(MISSING_BOTH_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);

    }
#line 3271 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* if_head: condition WORD_ELSE executable_body WORD_ENDIF  */
#line 1382 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(MISSING_IF_EXECUTABLE_BODY);

    }
#line 3282 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 161: /* if_head: condition_body_setup WORD_ELSE error WORD_ENDIF  */
#line 1389 "include/syntax-analyzer/components/yacc.y"
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
#line 3307 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 162: /* if_head: WORD_ELSE executable_body WORD_ENDIF  */
#line 1410 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_IF_STATEMENT);

    }
#line 3318 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 163: /* if_head: condition_body_setup WORD_ELSE executable_body INVALID_RWORD  */
#line 1417 "include/syntax-analyzer/components/yacc.y"
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
#line 3339 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 164: /* if_head: condition_body_setup INVALID_RWORD executable_body WORD_ENDIF  */
#line 1434 "include/syntax-analyzer/components/yacc.y"
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
#line 3360 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 165: /* if_head: condition_body_setup INVALID_RWORD executable_body INVALID_RWORD  */
#line 1451 "include/syntax-analyzer/components/yacc.y"
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
#line 3381 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* condition_body_setup: condition_setup then_body_setup  */
#line 1471 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3389 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 167: /* condition_setup: condition  */
#line 1478 "include/syntax-analyzer/components/yacc.y"
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
#line 3405 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 168: /* then_body_setup: executable_body  */
#line 1493 "include/syntax-analyzer/components/yacc.y"
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
#line 3426 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 169: /* do_while: do_while_head do_body  */
#line 1515 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3434 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 170: /* $@17: %empty  */
#line 1519 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);

    }
#line 3443 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 171: /* do_while: WORD_DO $@17 WORD_WHILE do_while_tail  */
#line 1524 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3451 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* do_while: WORD_DO error ';'  */
#line 1528 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;

    }
#line 3463 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* do_while_head: WORD_DO  */
#line 1539 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_DO_START,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            }));
    }
#line 3477 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* do_body: executable_body WORD_WHILE condition ';'  */
#line 1552 "include/syntax-analyzer/components/yacc.y"
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
#line 3497 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* do_body: executable_body WORD_WHILE condition error  */
#line 1568 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3509 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 176: /* $@18: %empty  */
#line 1576 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE);

    }
#line 3518 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* do_body: executable_body $@18 do_while_tail  */
#line 1581 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);
    }
#line 3526 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 179: /* do_while_tail: condition error  */
#line 1589 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3536 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 180: /* executable_body: '{' executable_statements '}'  */
#line 1600 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3544 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 181: /* executable_body: '{' executable_statements error  */
#line 1604 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 3556 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 182: /* executable_body: '{' error '}'  */
#line 1612 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        yyerrok;
    }
#line 3566 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* executable_body: executable_stmt  */
#line 1618 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3574 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* executable_body: '{' '}'  */
#line 1622 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3582 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 185: /* executable_statements: executable_stmt  */
#line 1628 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 3588 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 186: /* executable_statements: executable_statements executable_stmt  */
#line 1629 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 3594 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 187: /* opt_trunc_constant: numeric_constant  */
#line 1636 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3602 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 188: /* opt_trunc_constant: trunc_constant  */
#line 1640 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3610 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 189: /* trunc_constant: WORD_TRUNC '(' numeric_constant ')'  */
#line 1647 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

    }
#line 3621 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* trunc_constant: WORD_TRUNC '(' numeric_constant error  */
#line 1654 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3635 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* trunc_constant: WORD_TRUNC numeric_constant ')'  */
#line 1664 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3648 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* trunc_constant: WORD_TRUNC numeric_constant error  */
#line 1673 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3662 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* opt_trunc_variable: variable  */
#line 1686 "include/syntax-analyzer/components/yacc.y"
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
#line 3681 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 194: /* opt_trunc_variable: trunc_variable  */
#line 1701 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3689 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 195: /* trunc_variable: WORD_TRUNC '(' variable ')'  */
#line 1708 "include/syntax-analyzer/components/yacc.y"
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
#line 3713 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 196: /* trunc_variable: WORD_TRUNC '(' variable error  */
#line 1728 "include/syntax-analyzer/components/yacc.y"
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
#line 3740 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 197: /* trunc_variable: WORD_TRUNC variable ')'  */
#line 1751 "include/syntax-analyzer/components/yacc.y"
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
#line 3767 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 198: /* trunc_variable: WORD_TRUNC variable error  */
#line 1774 "include/syntax-analyzer/components/yacc.y"
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
#line 3794 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 199: /* trunc_variable: WORD_TRUNC error ';'  */
#line 1797 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("trunc ..."), false };

        SemanticActions::specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;

    }
#line 3807 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 200: /* trunc_expression: WORD_TRUNC '(' expression ')'  */
#line 1809 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");
    }
#line 3817 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 201: /* trunc_expression: WORD_TRUNC '(' expression error  */
#line 1815 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3831 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 202: /* trunc_expression: WORD_TRUNC expression ')'  */
#line 1825 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3844 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 203: /* trunc_expression: WORD_TRUNC expression error  */
#line 1834 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3858 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 204: /* condition: '(' comparison ')'  */
#line 1849 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);
    }
#line 3866 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 205: /* condition: '(' comparison error  */
#line 1853 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3878 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 206: /* condition: comparison ')'  */
#line 1861 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3889 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 207: /* condition: comparison error  */
#line 1868 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;

    }
#line 3901 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 208: /* comparison: expression comparison_operator expression  */
#line 1879 "include/syntax-analyzer/components/yacc.y"
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
#line 3928 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 209: /* comparison: expression error  */
#line 1902 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;

    }
#line 3940 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* comparison: expression comparison_operator error  */
#line 1910 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 3948 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 211: /* comparison_operator: OP_EQUAL  */
#line 1917 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_EQUAL, StringPool::create(Translator::translate(OP_EQUAL)) };
    }
#line 3956 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 212: /* comparison_operator: OP_NOT_EQUAL  */
#line 1921 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_NOT_EQUAL, StringPool::create(Translator::translate(OP_NOT_EQUAL)) };
    }
#line 3964 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 213: /* comparison_operator: OP_GE  */
#line 1925 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GE, StringPool::create(Translator::translate(OP_GE)) };
    }
#line 3972 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 214: /* comparison_operator: OP_LE  */
#line 1929 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LE, StringPool::create(Translator::translate(OP_LE)) };
    }
#line 3980 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 215: /* comparison_operator: '>'  */
#line 1933 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GT, StringPool::create(">") };
    }
#line 3988 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 216: /* comparison_operator: '<'  */
#line 1937 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LT, StringPool::create("<") };
    }
#line 3996 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 217: /* expression: term  */
#line 1946 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4004 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 218: /* expression: expression_setup positive_term  */
#line 1950 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;
        (yyval.metadata).reference = (yyvsp[-1].metadata).reference;
        
        (yyval.metadata).expression.assignable = false;
    }
#line 4020 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 219: /* expression: '+' term  */
#line 1962 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUM_OPERAND);

    }
#line 4031 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 220: /* expression: '+' error  */
#line 1969 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;

    }
#line 4044 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 221: /* expression: expression '+' term  */
#line 1978 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4052 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 222: /* expression: expression '+' error  */
#line 1982 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 4064 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 223: /* expression: expression '-' term  */
#line 1990 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4072 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 224: /* expression: expression '-' error  */
#line 1994 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 4084 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 225: /* expression: trunc_expression  */
#line 2002 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4092 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 226: /* expression: expression '+' trunc_expression  */
#line 2006 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4100 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 227: /* expression: expression '-' trunc_expression  */
#line 2010 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4108 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 228: /* expression_setup: expression  */
#line 2017 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 4118 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 229: /* term: positive_term  */
#line 2028 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4126 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 230: /* term: negative_term  */
#line 2032 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4134 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 231: /* positive_term: positive_term '*' factor  */
#line 2039 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4142 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 232: /* positive_term: positive_term '/' factor  */
#line 2043 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4150 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 233: /* positive_term: trunc_expression '/' factor  */
#line 2047 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4158 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 234: /* positive_term: trunc_expression '*' factor  */
#line 2051 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4166 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 235: /* positive_term: trunc_expression '/' trunc_expression  */
#line 2055 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4174 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 236: /* positive_term: trunc_expression '*' trunc_expression  */
#line 2059 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4182 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 237: /* positive_term: positive_term '/' trunc_expression  */
#line 2063 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4190 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 238: /* positive_term: positive_term '*' trunc_expression  */
#line 2067 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4198 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 239: /* positive_term: positive_factor  */
#line 2071 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4206 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 240: /* positive_term: positive_term '*' error  */
#line 2075 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4218 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 241: /* positive_term: positive_term '/' error  */
#line 2083 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4230 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 242: /* negative_term: negative_term '*' factor  */
#line 2094 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4238 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 243: /* negative_term: negative_term '/' factor  */
#line 2098 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4246 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 244: /* negative_term: negative_term '/' trunc_expression  */
#line 2102 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4254 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 245: /* negative_term: negative_term '*' trunc_expression  */
#line 2106 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4262 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 246: /* negative_term: negative_factor  */
#line 2110 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4270 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 247: /* negative_term: negative_term '*' error  */
#line 2114 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4282 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 248: /* negative_term: negative_term '/' error  */
#line 2122 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4294 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 249: /* negative_term: '*' factor  */
#line 2130 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_MUL_FACTOR);

    }
#line 4305 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 250: /* negative_term: '/' factor  */
#line 2137 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_DIV_FACTOR);

    }
#line 4316 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 251: /* negative_term: '*' error  */
#line 2144 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4329 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 252: /* negative_term: '/' error  */
#line 2153 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4342 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 253: /* factor: positive_factor  */
#line 2167 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4350 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 254: /* factor: negative_factor  */
#line 2171 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4358 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 255: /* positive_factor: variable  */
#line 2178 "include/syntax-analyzer/components/yacc.y"
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
#line 4377 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 256: /* positive_factor: positive_constant  */
#line 2193 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4385 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 257: /* positive_factor: function_invocation_head  */
#line 2197 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4393 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 258: /* negative_factor: negative_constant  */
#line 2204 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4401 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 259: /* negative_factor: lambda_invocation_head  */
#line 2208 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };
        
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);
    }
#line 4412 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 260: /* negative_factor: '-' LITERAL_UINT  */
#line 2215 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4424 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 261: /* negative_factor: '-' function_invocation_head  */
#line 2223 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4435 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 262: /* negative_factor: '-' variable  */
#line 2230 "include/syntax-analyzer/components/yacc.y"
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
#line 4455 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 263: /* negative_factor: '-' lambda_invocation_head  */
#line 2246 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);

    }
#line 4468 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 264: /* negative_factor: '-' error  */
#line 2255 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUB_OPERANDS);
        yyerrok;

    }
#line 4481 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 265: /* numeric_constant: positive_constant  */
#line 2269 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4489 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 266: /* numeric_constant: negative_constant  */
#line 2273 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4497 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 267: /* positive_constant: LITERAL_UINT  */
#line 2280 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4506 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 268: /* positive_constant: LITERAL_FLOAT  */
#line 2285 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4515 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 269: /* negative_constant: '-' LITERAL_FLOAT  */
#line 2293 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL , .lref = SemanticActions::turnNegative((yyvsp[0].lref)) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };

    }
#line 4525 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 270: /* variable: IDENTIFIER  */
#line 2304 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.pid) = StringPool::create((yyvsp[0].sref)->symbol);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariableName((yyvsp[0].sref)->symbol);

    }
#line 4536 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 271: /* variable: variable '.' IDENTIFIER  */
#line 2311 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].pid), "." + (yyvsp[0].sref)->symbol);
        (yyval.pid) = (yyvsp[-2].pid);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariablePrefix((yyvsp[0].sref)->symbol);

    }
#line 4548 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 4552 "src/syntax-analyzer/components/parser.cpp"

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

#line 2320 "include/syntax-analyzer/components/yacc.y"
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
