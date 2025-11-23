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
  YYSYMBOL_lambda_invocation_tail = 95,    /* lambda_invocation_tail  */
  YYSYMBOL_lambda_real_parameter = 96,     /* lambda_real_parameter  */
  YYSYMBOL_if = 97,                        /* if  */
  YYSYMBOL_if_word = 98,                   /* if_word  */
  YYSYMBOL_if_head = 99,                   /* if_head  */
  YYSYMBOL_condition_body_setup = 100,     /* condition_body_setup  */
  YYSYMBOL_condition_setup = 101,          /* condition_setup  */
  YYSYMBOL_then_body_setup = 102,          /* then_body_setup  */
  YYSYMBOL_do_while = 103,                 /* do_while  */
  YYSYMBOL_104_16 = 104,                   /* $@16  */
  YYSYMBOL_do_while_head = 105,            /* do_while_head  */
  YYSYMBOL_do_body = 106,                  /* do_body  */
  YYSYMBOL_107_17 = 107,                   /* $@17  */
  YYSYMBOL_do_while_tail = 108,            /* do_while_tail  */
  YYSYMBOL_executable_body = 109,          /* executable_body  */
  YYSYMBOL_executable_statements = 110,    /* executable_statements  */
  YYSYMBOL_opt_trunc_constant = 111,       /* opt_trunc_constant  */
  YYSYMBOL_trunc_constant = 112,           /* trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 113,       /* opt_trunc_variable  */
  YYSYMBOL_trunc_variable = 114,           /* trunc_variable  */
  YYSYMBOL_trunc_expression = 115,         /* trunc_expression  */
  YYSYMBOL_condition = 116,                /* condition  */
  YYSYMBOL_comparison = 117,               /* comparison  */
  YYSYMBOL_comparison_operator = 118,      /* comparison_operator  */
  YYSYMBOL_expression = 119,               /* expression  */
  YYSYMBOL_expression_setup = 120,         /* expression_setup  */
  YYSYMBOL_term = 121,                     /* term  */
  YYSYMBOL_positive_term = 122,            /* positive_term  */
  YYSYMBOL_negative_term = 123,            /* negative_term  */
  YYSYMBOL_factor = 124,                   /* factor  */
  YYSYMBOL_positive_factor = 125,          /* positive_factor  */
  YYSYMBOL_negative_factor = 126,          /* negative_factor  */
  YYSYMBOL_numeric_constant = 127,         /* numeric_constant  */
  YYSYMBOL_positive_constant = 128,        /* positive_constant  */
  YYSYMBOL_negative_constant = 129,        /* negative_constant  */
  YYSYMBOL_variable = 130                  /* variable  */
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
#define YYLAST   1075

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  268
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  406

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
    1031,  1041,  1049,  1087,  1100,  1099,  1112,  1111,  1117,  1116,
    1123,  1131,  1142,  1197,  1198,  1204,  1208,  1215,  1223,  1232,
    1257,  1272,  1292,  1312,  1333,  1354,  1362,  1370,  1379,  1400,
    1407,  1424,  1441,  1461,  1468,  1483,  1505,  1510,  1509,  1518,
    1529,  1542,  1558,  1567,  1566,  1578,  1579,  1590,  1594,  1602,
    1608,  1612,  1619,  1620,  1626,  1630,  1637,  1644,  1654,  1663,
    1676,  1691,  1698,  1718,  1741,  1764,  1787,  1799,  1805,  1815,
    1824,  1839,  1843,  1851,  1858,  1869,  1892,  1900,  1907,  1911,
    1915,  1919,  1923,  1927,  1936,  1940,  1952,  1959,  1968,  1972,
    1980,  1984,  1992,  1996,  2000,  2007,  2018,  2022,  2029,  2033,
    2037,  2041,  2045,  2049,  2053,  2057,  2061,  2065,  2073,  2084,
    2088,  2092,  2096,  2100,  2104,  2112,  2120,  2127,  2134,  2143,
    2157,  2161,  2168,  2183,  2187,  2194,  2198,  2205,  2213,  2220,
    2236,  2245,  2259,  2263,  2270,  2275,  2283,  2294,  2301
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
  "$@13", "lambda_invocation_middle", "$@14", "$@15",
  "lambda_invocation_tail", "lambda_real_parameter", "if", "if_word",
  "if_head", "condition_body_setup", "condition_setup", "then_body_setup",
  "do_while", "$@16", "do_while_head", "do_body", "$@17", "do_while_tail",
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

#define YYTABLE_NINF (-226)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     683,  -312,    -9,  -312,   886,   380,    68,  -312,  -312,   -15,
    -312,  -312,     9,   703,  -312,  -312,  -312,   156,  -312,  -312,
    -312,  1001,  -312,  -312,  -312,    83,   997,   118,  -312,   205,
    -312,   430,    19,  -312,     2,    73,    85,  1019,    59,  -312,
    -312,   979,   445,   663,   323,   626,  -312,  -312,   217,   517,
     629,  -312,   261,   285,  -312,  -312,  -312,  -312,    94,   123,
     376,  -312,   305,   803,   100,  -312,  -312,   140,   168,  -312,
     142,    94,  -312,   549,  -312,  -312,  -312,  -312,   363,  1001,
    -312,   454,  -312,  -312,   176,   430,   979,   128,   531,   430,
     899,     7,   492,   912,  -312,  -312,   199,   188,   407,   204,
    -312,   211,   272,   139,   204,  -312,  1037,  -312,   979,   557,
     532,  -312,   217,  -312,  -312,  -312,  -312,  -312,  -312,    94,
    -312,  -312,  -312,  -312,  -312,  -312,   326,   326,  -312,  -312,
     193,   463,   483,   261,   577,   602,   606,   610,  -312,   215,
     227,   329,   823,   235,   243,   843,  -312,  -312,  -312,   723,
    -312,  -312,  -312,   252,  -312,  -312,   410,  -312,  -312,   115,
     204,  -312,  -312,  1001,  -312,  -312,  -312,   263,  -312,   281,
      49,  -312,  -312,  -312,   430,   925,  -312,  -312,  -312,   177,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,   425,
     278,  -312,  -312,   945,  1037,  1037,  -312,   279,  -312,    23,
    -312,  -312,   297,  -312,   289,   635,  -312,  -312,  -312,  -312,
     239,    94,  -312,   154,   574,  -312,  -312,  -312,  -312,   161,
    -312,  -312,  -312,  -312,  -312,  -312,   217,  -312,  -312,   217,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,   166,   191,  -312,  -312,   743,  -312,
    -312,  -312,   763,  -312,  -312,  -312,  -312,   410,  -312,  -312,
     131,  -312,   397,  -312,   296,  -312,    94,    94,  -312,  -312,
    -312,  -312,  -312,   120,   179,   495,   324,  -312,  -312,  -312,
      36,  -312,  -312,  -312,  -312,   219,  -312,  -312,   239,   201,
      51,    60,  -312,  -312,   239,   644,   239,  -312,    65,  -312,
    -312,  -312,  -312,  -312,  -312,   309,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  1042,  -312,   420,  -312,  -312,   410,
    -312,   410,  -312,  -312,   200,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,   314,  -312,   327,    76,  -312,
    -312,  -312,  -312,  -312,   239,   239,  -312,  -312,  -312,  -312,
    -312,   554,  -312,   958,  -312,  -312,   337,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,   978,  -312,  -312,   337,
     863,  -312,   222,  -312,  -312,   344,  -312,   244,  -312,   783,
    -312,  -312,   344,   398,  -312,  -312,  -312,  -312,  -312,  -312,
     653,   345,  -312,  -312,  -312,    94,   350,   500,    25,  -312,
    -312,    26,  -312,  -312,  -312,  -312
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     4,     0,   150,     0,     0,     0,    41,    42,   267,
       8,    10,     0,     0,     2,     7,     5,     0,    80,     6,
      75,     0,    79,    76,    77,     0,     0,     0,    78,     0,
      81,     0,     0,    11,     0,     0,     0,     0,   267,   265,
     264,     0,     0,     0,     0,     0,   254,   256,   222,     0,
       0,   214,   226,   227,   236,   243,   253,   255,   252,     0,
       0,    15,     0,     0,     0,     1,     3,     0,   267,    34,
       0,    36,    82,     0,   120,   119,   127,   123,   131,     0,
     128,     0,   122,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   166,   173,     0,     0,     0,
     103,     0,     0,   111,     0,   169,     0,    74,     0,     0,
       0,   217,     0,   216,   261,   266,   257,   258,   260,   259,
     248,   246,   250,   251,   249,   247,     0,     0,    70,    73,
      69,     0,     0,   215,     0,     0,     0,     0,    93,     0,
       0,   225,     0,     0,     0,     0,    13,     9,    24,     0,
      20,    22,    23,     0,    30,    32,     0,    31,    29,     0,
       0,    86,    85,     0,   126,   130,   133,     0,   147,     0,
       0,   146,   145,   153,     0,     0,   151,   163,   165,     0,
     204,   203,   206,   208,   210,   211,   209,   212,   213,     0,
       0,   181,   182,     0,     0,     0,   102,     0,   267,     0,
     268,   101,     0,   100,     0,     0,   185,   184,   262,   263,
       0,   112,   168,     0,     0,   200,   199,    68,    71,     0,
     233,   231,   232,   230,    72,   219,   223,   218,   221,   224,
     220,   237,   235,   228,   238,   234,   229,   244,   242,   239,
     245,   241,   240,    91,     0,     0,    19,    16,     0,   124,
      28,    25,     0,    14,    12,    21,   134,     0,    62,    57,
       0,    35,    53,    51,     0,    40,    37,    39,   129,   132,
     159,   202,   201,     0,     0,     0,   157,   155,   148,   207,
     225,   179,   178,   177,   183,     0,   174,    83,     0,     0,
       0,     0,    97,    96,     0,     0,     0,   106,     0,   176,
     175,   198,   197,    67,    66,    95,    88,    87,    90,    89,
      18,    17,    27,    26,     0,    33,    53,    56,    55,     0,
      43,     0,    60,    61,     0,   162,   161,   158,   149,   154,
     160,   152,   156,   172,   171,     0,   108,   107,     0,   189,
     188,   113,    99,    98,     0,     0,   115,   110,   109,    94,
      92,     0,   135,     0,    47,    52,     0,    54,    59,    58,
     105,   104,   187,   186,   116,   118,     0,   141,   138,     0,
       0,    44,     0,   140,   136,     0,    48,     0,    64,     0,
      46,    45,     0,     0,   139,    50,    49,    65,    63,   137,
       0,     0,   144,   143,   191,   190,     0,     0,     0,   142,
     196,     0,   195,   194,   193,   192
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,  -312,   367,  -312,  -312,    12,  -312,  -312,  -135,  -140,
      70,  -312,  -312,  -312,  -312,    -8,  -312,  -312,  -312,  -312,
    -312,  -312,   132,  -312,   -45,  -312,    22,  -312,    21,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,   -97,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,     5,  -312,  -312,  -312,  -312,   -77,
      16,  -312,  -312,  -312,  -312,     3,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,   212,   -57,
    -311,  -168,  -312,  -312,  -312,     4,   -28,   310,  -312,    55,
    -312,    -7,   356,  -312,   167,   143,   155,  -187,   -58,   -29,
       0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    13,    14,    63,   147,   148,   142,   247,   149,   150,
     151,   257,   156,    70,   160,    17,   261,   356,   371,   315,
     369,   376,   262,   321,   263,   264,   372,    18,   152,    20,
      21,    72,    22,   305,   350,    23,   102,   297,   103,   104,
     295,   296,   345,    24,    46,    26,    77,    78,    79,    80,
      47,   314,   352,   382,   375,   384,   391,    28,    29,    87,
      88,    89,   177,    30,    35,    31,    95,   195,   212,    96,
     193,   205,   206,   393,   394,    48,   213,    91,   189,    92,
      50,    51,    52,    53,   121,    54,    55,   207,    56,    57,
      58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    90,   165,   353,    64,    25,   210,   248,   180,   255,
     252,    61,    15,    32,    62,   291,    27,    71,    25,    33,
      97,    19,     7,     8,   288,    15,   402,   404,   169,    27,
     105,    32,   178,    64,    19,   113,    25,  -205,   181,    98,
     366,  -111,   298,   119,   208,  -111,   112,    27,   117,    99,
     271,   100,    94,    99,   112,   100,   403,   405,   101,   118,
      49,   339,   101,    32,   101,   101,   347,  -205,    25,    59,
      16,   131,   132,   209,    39,    40,    73,   362,    64,    27,
     272,    81,   106,    16,    74,    32,   268,   204,    62,    32,
      25,   340,   109,    32,    25,   348,   110,    60,    25,   199,
      64,    27,   289,   338,   211,    27,    94,   363,   255,    27,
      94,    75,   255,   107,   192,   141,   265,   273,   275,    82,
     335,   337,   153,   325,   227,   230,   341,   326,   346,   171,
     220,   222,   317,   101,    81,   226,   229,   198,   232,   235,
     238,   241,    32,   157,   208,    32,    83,    25,   260,    32,
      25,   138,   208,   318,    25,   299,   172,    67,    27,   266,
     267,    27,   303,   214,   -38,    27,   285,   306,   154,    99,
     158,   100,   159,   209,    32,    32,   364,   365,    68,    25,
      25,   209,   300,   276,   277,    69,   327,   122,   122,   304,
      27,    27,   308,    32,   307,    94,    94,   155,    25,   123,
     123,   358,   336,   291,   168,   278,    84,   328,   194,    27,
     338,    85,   125,   202,   284,   392,   196,    37,    81,   309,
     333,   224,   359,   380,    39,    40,   198,    38,    39,    40,
     208,   208,   208,   200,    86,   379,   208,   204,   208,   255,
      42,    43,    44,    45,   280,   385,   243,   334,    32,   260,
     381,   202,    32,    25,   126,   127,   324,    25,   244,   209,
     209,   209,    39,    40,    27,   209,   249,   209,    27,   122,
     122,   250,   386,   201,   355,   204,   357,   122,   122,   122,
     122,   123,   123,   256,   202,   269,   208,   208,   270,   123,
     123,   123,   123,   221,   223,    39,    40,   322,   134,   135,
     203,   233,   236,   239,   242,   281,   143,   287,   204,     7,
       8,   260,   115,   260,    32,   209,   209,  -125,   323,    25,
      39,    40,   136,   137,   120,   208,   290,  -125,  -125,  -125,
      27,   332,   208,   204,  -125,   192,  -125,   349,    37,   208,
    -125,  -125,  -125,  -125,   360,    38,    39,    40,    38,    39,
      40,    32,    12,    32,   209,    12,    25,   361,    25,    43,
     245,   209,    43,   370,   131,   132,    32,    27,   209,    27,
      32,    25,   192,   383,   284,    25,   399,   139,   400,    32,
      66,    36,    27,   395,    25,   389,    27,   284,    37,   316,
     398,   377,    37,   163,   164,    27,   170,   401,    38,    39,
      40,   140,    38,    39,    40,    12,   133,   286,   197,    41,
     390,    42,    43,    44,    45,    42,    43,    44,    45,   -84,
     198,    39,    40,     7,     8,   258,   279,   319,   320,   -84,
     -84,   -84,   259,     0,   204,     3,   -84,    37,     4,     0,
       5,     6,   -84,   -84,   -84,   -84,   111,    38,    39,    40,
     319,   354,    38,     0,    12,   166,    93,    37,     0,    12,
      42,    43,    44,    45,   225,     0,  -225,    38,    39,    40,
     167,     0,     0,     0,    12,    37,  -225,  -225,  -225,     0,
       0,    43,    44,    45,   228,    38,    39,    40,     0,   131,
     132,     0,    12,   182,     0,    37,   329,     0,   330,    43,
      44,    45,   331,     0,  -225,    38,    39,    40,     0,   183,
     184,   185,    12,   186,  -225,  -225,  -225,     0,   128,    43,
      44,    45,   198,    39,    40,   187,   188,   131,   132,  -225,
       0,     0,   173,   217,   174,     0,   204,   175,   176,  -225,
    -225,  -225,     0,     0,  -225,   129,     0,     0,   130,     0,
     161,     0,   131,   132,  -225,  -225,  -225,     0,   215,     3,
     218,  -225,     4,   219,     5,     6,     0,   131,   132,  -225,
       0,  -225,  -225,  -225,     0,   301,    38,   162,   231,  -225,
    -225,  -225,     0,    12,   131,   132,  -225,     0,   216,    37,
       0,     0,   131,   132,     0,     0,  -225,  -225,  -225,    38,
      39,    40,     0,   234,     0,   302,    12,   237,     0,   131,
     132,   240,     0,    43,    37,     0,     0,     0,    37,     0,
       0,     0,    37,     0,    38,    39,    40,   124,    38,    39,
      40,    12,    38,    39,    40,    12,   292,     0,    43,    12,
       0,    37,    43,     0,     0,   342,    43,  -114,    38,    39,
      40,    38,    39,    40,   396,    12,  -117,     0,  -114,  -114,
       0,     0,    43,   293,   114,   294,     0,  -117,  -117,     0,
       0,  -114,   343,     0,   344,   198,    39,    40,     0,     0,
    -117,     0,   397,     1,     2,    38,   115,   116,     3,   204,
       0,     4,    12,     5,     6,     0,     7,     8,     0,     0,
       0,     0,     0,    65,     2,     9,     0,     0,     3,    10,
      11,     4,    12,     5,     6,     0,     7,     8,     0,     0,
       0,     0,     0,   253,   144,     9,     0,     0,     3,    10,
      11,     4,    12,     5,     6,     0,     7,     8,     0,     0,
       0,     0,     0,   310,   144,     9,     0,     0,     3,   145,
     254,     4,    12,     5,     6,     0,     7,     8,     0,     0,
       0,     0,     0,   312,   144,     9,     0,     0,     3,   145,
     311,     4,    12,     5,     6,     0,     7,     8,     0,     0,
       0,     0,     0,   387,   144,     9,     0,     0,     3,   145,
     313,     4,    12,     5,     6,     0,     7,     8,     0,     0,
       0,     0,     0,     0,   144,     9,     0,     0,     3,   145,
     388,     4,    12,     5,     6,     0,     7,     8,     0,     0,
       0,     0,     0,     0,   144,     9,     0,     0,     3,   145,
     146,     4,    12,     5,     6,     0,     7,     8,     0,     0,
       0,     0,     0,     0,   144,     9,     0,     0,     3,   145,
     246,     4,    12,     5,     6,     0,     7,     8,     0,     0,
       0,     0,     0,     0,   144,     9,     0,     0,     3,   145,
     251,     4,    12,     5,     6,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    34,     0,   145,
     378,  -170,    12,     0,  -170,  -167,  -170,  -170,     0,     0,
     179,     0,     0,     0,  -164,     0,     0,  -164,  -170,  -164,
    -164,     0,  -170,   190,     0,  -170,     0,     3,     0,     0,
       4,  -164,     5,     6,     0,  -164,   274,     0,  -164,     0,
       3,     0,     0,     4,    38,     5,     6,     0,     0,   191,
       0,    12,     0,     0,     0,     0,   282,    38,     0,     0,
       3,    93,     0,     4,    12,     5,     6,     0,     0,   367,
       0,     0,     0,     3,     0,     0,     4,    38,     5,     6,
       0,     0,   283,     0,    12,     0,     0,     0,     0,   373,
      38,     0,     0,     3,     0,   368,     4,    12,     5,     6,
       0,    37,     7,     8,     0,     0,     0,     0,     0,     0,
      38,    38,    39,    40,     0,   374,     0,    12,    12,    37,
       0,     0,     0,    37,    42,    43,    44,    45,     0,    38,
      39,    40,     0,    38,    39,    40,    12,     0,    76,     0,
      12,    37,    42,    43,    44,    45,    42,    43,    44,    45,
       0,    38,    39,    40,     0,     0,     0,     3,   108,    37,
       4,     0,     5,     6,    42,    43,    44,    45,     0,    38,
      39,    40,     0,     0,    38,     0,    86,     0,   351,     0,
       0,    12,    42,    43,    44,    45
};

static const yytype_int16 yycheck[] =
{
       0,    29,    79,   314,    12,     0,   103,   142,     1,   149,
     145,    26,     0,    13,    29,   202,     0,    17,    13,    28,
       1,     0,    13,    14,     1,    13,     1,     1,    85,    13,
      28,    31,    89,    41,    13,    42,    31,     1,    31,    20,
     351,    22,   210,    43,   102,    22,    42,    31,    43,    30,
       1,    32,    31,    30,    50,    32,    31,    31,    39,    43,
       5,     1,    39,    63,    39,    39,     1,    31,    63,     1,
       0,    35,    36,   102,    23,    24,    21,     1,    86,    63,
      31,    26,     9,    13,     1,    85,   163,    36,    29,    89,
      85,    31,    37,    93,    89,    30,    41,    29,    93,    99,
     108,    85,   199,   290,   104,    89,    85,    31,   248,    93,
      89,    28,   252,    28,    93,    60,     1,   174,   175,     1,
     288,   289,    22,     3,   131,   132,   294,     7,   296,     1,
     126,   127,     1,    39,    79,   131,   132,    22,   134,   135,
     136,   137,   142,     1,   202,   145,    28,   142,   156,   149,
     145,    28,   210,    22,   149,     1,    28,     1,   142,   159,
     160,   145,     1,   108,    22,   149,   194,     1,    28,    30,
      28,    32,    30,   202,   174,   175,   344,   345,    22,   174,
     175,   210,    28,     6,     7,    29,     7,    44,    45,    28,
     174,   175,     1,   193,    28,   174,   175,    29,   193,    44,
      45,     1,     1,   390,    28,    28,     1,    28,     9,   193,
     397,     6,    45,    12,   193,   383,    28,    12,   163,    28,
       1,    28,    22,     1,    23,    24,    22,    22,    23,    24,
     288,   289,   290,    22,    29,   370,   294,    36,   296,   379,
      35,    36,    37,    38,   189,     1,    31,    28,   248,   257,
      28,    12,   252,   248,    37,    38,   264,   252,    31,   288,
     289,   290,    23,    24,   248,   294,    31,   296,   252,   126,
     127,    28,    28,     1,   319,    36,   321,   134,   135,   136,
     137,   126,   127,    31,    12,    22,   344,   345,     7,   134,
     135,   136,   137,   126,   127,    23,    24,     1,    37,    38,
      28,   134,   135,   136,   137,    27,     1,    28,    36,    13,
      14,   319,    23,   321,   314,   344,   345,    12,    22,   314,
      23,    24,    37,    38,     1,   383,    29,    22,    23,    24,
     314,     7,   390,    36,    29,   314,    31,    28,    12,   397,
      35,    36,    37,    38,    30,    22,    23,    24,    22,    23,
      24,   351,    29,   353,   383,    29,   351,    30,   353,    36,
      31,   390,    36,    26,    35,    36,   366,   351,   397,   353,
     370,   366,   351,    29,   353,   370,    31,     1,    28,   379,
      13,     1,   366,   383,   379,   382,   370,   366,    12,   257,
     390,   369,    12,    30,    31,   379,    86,   397,    22,    23,
      24,    25,    22,    23,    24,    29,    50,   195,     1,    29,
      12,    35,    36,    37,    38,    35,    36,    37,    38,    12,
      22,    23,    24,    13,    14,    15,     1,    30,    31,    22,
      23,    24,    22,    -1,    36,     5,    29,    12,     8,    -1,
      10,    11,    35,    36,    37,    38,     1,    22,    23,    24,
      30,    31,    22,    -1,    29,     1,    26,    12,    -1,    29,
      35,    36,    37,    38,     1,    -1,    12,    22,    23,    24,
      16,    -1,    -1,    -1,    29,    12,    22,    23,    24,    -1,
      -1,    36,    37,    38,     1,    22,    23,    24,    -1,    35,
      36,    -1,    29,     1,    -1,    12,     1,    -1,     3,    36,
      37,    38,     7,    -1,    12,    22,    23,    24,    -1,    17,
      18,    19,    29,    21,    22,    23,    24,    -1,     1,    36,
      37,    38,    22,    23,    24,    33,    34,    35,    36,    12,
      -1,    -1,     1,     1,     3,    -1,    36,     6,     7,    22,
      23,    24,    -1,    -1,    12,    28,    -1,    -1,    31,    -1,
       1,    -1,    35,    36,    22,    23,    24,    -1,     1,     5,
      28,    12,     8,    31,    10,    11,    -1,    35,    36,    12,
      -1,    22,    23,    24,    -1,     1,    22,    28,     1,    22,
      23,    24,    -1,    29,    35,    36,    12,    -1,    31,    12,
      -1,    -1,    35,    36,    -1,    -1,    22,    23,    24,    22,
      23,    24,    -1,     1,    -1,    31,    29,     1,    -1,    35,
      36,     1,    -1,    36,    12,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    12,    -1,    22,    23,    24,     1,    22,    23,
      24,    29,    22,    23,    24,    29,     1,    -1,    36,    29,
      -1,    12,    36,    -1,    -1,     1,    36,    12,    22,    23,
      24,    22,    23,    24,     1,    29,    12,    -1,    23,    24,
      -1,    -1,    36,    28,     1,    30,    -1,    23,    24,    -1,
      -1,    36,    28,    -1,    30,    22,    23,    24,    -1,    -1,
      36,    -1,    29,     0,     1,    22,    23,    24,     5,    36,
      -1,     8,    29,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,     0,     1,    22,    -1,    -1,     5,    26,
      27,     8,    29,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,     0,     1,    22,    -1,    -1,     5,    26,
      27,     8,    29,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,     0,     1,    22,    -1,    -1,     5,    26,
      27,     8,    29,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,     0,     1,    22,    -1,    -1,     5,    26,
      27,     8,    29,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,     0,     1,    22,    -1,    -1,     5,    26,
      27,     8,    29,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    22,    -1,    -1,     5,    26,
      27,     8,    29,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    22,    -1,    -1,     5,    26,
      27,     8,    29,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    22,    -1,    -1,     5,    26,
      27,     8,    29,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    22,    -1,    -1,     5,    26,
      27,     8,    29,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,     1,    -1,    26,
      27,     5,    29,    -1,     8,     9,    10,    11,    -1,    -1,
       1,    -1,    -1,    -1,     5,    -1,    -1,     8,    22,    10,
      11,    -1,    26,     1,    -1,    29,    -1,     5,    -1,    -1,
       8,    22,    10,    11,    -1,    26,     1,    -1,    29,    -1,
       5,    -1,    -1,     8,    22,    10,    11,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    -1,     1,    22,    -1,    -1,
       5,    26,    -1,     8,    29,    10,    11,    -1,    -1,     1,
      -1,    -1,    -1,     5,    -1,    -1,     8,    22,    10,    11,
      -1,    -1,    27,    -1,    29,    -1,    -1,    -1,    -1,     1,
      22,    -1,    -1,     5,    -1,    27,     8,    29,    10,    11,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    22,    23,    24,    -1,    27,    -1,    29,    29,    12,
      -1,    -1,    -1,    12,    35,    36,    37,    38,    -1,    22,
      23,    24,    -1,    22,    23,    24,    29,    -1,    31,    -1,
      29,    12,    35,    36,    37,    38,    35,    36,    37,    38,
      -1,    22,    23,    24,    -1,    -1,    -1,     5,    29,    12,
       8,    -1,    10,    11,    35,    36,    37,    38,    -1,    22,
      23,    24,    -1,    -1,    22,    -1,    29,    -1,    26,    -1,
      -1,    29,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     0,     1,     5,     8,    10,    11,    13,    14,    22,
      26,    27,    29,    41,    42,    45,    50,    55,    67,    68,
      69,    70,    72,    75,    83,    84,    85,    90,    97,    98,
     103,   105,   130,    28,     1,   104,     1,    12,    22,    23,
      24,    29,    35,    36,    37,    38,    84,    90,   115,   119,
     120,   121,   122,   123,   125,   126,   128,   129,   130,     1,
      29,    26,    29,    43,    55,     0,    42,     1,    22,    29,
      53,   130,    71,   119,     1,    28,    31,    86,    87,    88,
      89,   119,     1,    28,     1,     6,    29,    99,   100,   101,
     116,   117,   119,    26,    68,   106,   109,     1,    20,    30,
      32,    39,    76,    78,    79,    28,     9,    28,    29,   119,
     119,     1,   115,   121,     1,    23,    24,    84,    90,   130,
       1,   124,   125,   126,     1,   124,    37,    38,     1,    28,
      31,    35,    36,   122,    37,    38,    37,    38,    28,     1,
      25,   119,    46,     1,     1,    26,    27,    44,    45,    48,
      49,    50,    68,    22,    28,    29,    52,     1,    28,    30,
      54,     1,    28,    30,    31,    89,     1,    16,    28,   109,
     117,     1,    28,     1,     3,     6,     7,   102,   109,     1,
       1,    31,     1,    17,    18,    19,    21,    33,    34,   118,
       1,    27,    68,   110,     9,   107,    28,     1,    22,   130,
      22,     1,    12,    28,    36,   111,   112,   127,   128,   129,
      76,   130,   108,   116,   119,     1,    31,     1,    28,    31,
     115,   124,   115,   124,    28,     1,   115,   121,     1,   115,
     121,     1,   115,   124,     1,   115,   124,     1,   115,   124,
       1,   115,   124,    31,    31,    31,    27,    47,    48,    31,
      28,    27,    48,     0,    27,    49,    31,    51,    15,    22,
      55,    56,    62,    64,    65,     1,   130,   130,    89,    22,
       7,     1,    31,   109,     1,   109,     6,     7,    28,     1,
     119,    27,     1,    27,    68,   116,   108,    28,     1,    76,
      29,   127,     1,    28,    30,    80,    81,    77,   111,     1,
      28,     1,    31,     1,    28,    73,     1,    28,     1,    28,
       0,    27,     0,    27,    91,    59,    62,     1,    22,    30,
      31,    63,     1,    22,    55,     3,     7,     7,    28,     1,
       3,     7,     7,     1,    28,   111,     1,   111,   127,     1,
      31,   111,     1,    28,    30,    82,   111,     1,    30,    28,
      74,    26,    92,   110,    31,    64,    57,    64,     1,    22,
      30,    30,     1,    31,   111,   111,   110,     1,    27,    60,
      26,    58,    66,     1,    27,    94,    61,    66,    27,    48,
       1,    28,    93,    29,    95,     1,    28,     0,    27,    95,
      12,    96,   111,   113,   114,   130,     1,    29,   130,    31,
      28,   130,     1,    31,     1,    31
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
      92,    92,    95,    96,    96,    97,    97,    97,    97,    97,
      98,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   101,   102,   103,   104,   103,   103,
     105,   106,   106,   107,   106,   108,   108,   109,   109,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   112,   112,
     113,   113,   114,   114,   114,   114,   114,   115,   115,   115,
     115,   116,   116,   116,   116,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   120,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   124,   125,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   127,   127,   128,   128,   129,   130,   130
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
       2,     1,     3,     2,     0,     6,     0,     5,     0,     4,
       3,     2,     3,     1,     1,     3,     3,     3,     4,     5,
       1,     2,     4,     2,     4,     3,     4,     3,     4,     3,
       4,     4,     4,     2,     1,     1,     2,     0,     4,     3,
       1,     4,     4,     0,     3,     2,     2,     3,     3,     3,
       1,     2,     1,     2,     1,     1,     4,     4,     3,     3,
       1,     1,     4,     4,     3,     3,     3,     4,     4,     3,
       3,     3,     3,     2,     2,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     3,     3,
       3,     3,     1,     3,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     1,     3
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
#line 1672 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 138 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1680 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 8: /* $@1: %empty  */
#line 143 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::addInvalidScope();
        SemanticActions::announceSpecificError(MISSING_PROGRAM_NAME);

        SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration("");

    }
#line 1692 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '}'  */
#line 152 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1700 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: error ';'  */
#line 156 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1709 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* unnamed_program_tail: program_statements '}'  */
#line 164 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1717 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* unnamed_program_tail: '}'  */
#line 168 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1725 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* unnamed_program_tail: program_statements $end  */
#line 172 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1734 "src/syntax-analyzer/components/parser.cpp"
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
#line 1750 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 17: /* program_tail: program_statements '}'  */
#line 198 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1759 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 18: /* program_tail: program_statements $end  */
#line 203 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticAnalyzer::removeScope();
    }
#line 1768 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 19: /* program_tail: '}'  */
#line 208 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1777 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statements: program_statement  */
#line 217 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 1783 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statements: program_statements program_statement  */
#line 218 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 1789 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: declarative_stmt  */
#line 223 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 1797 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* program_statement: executable_stmt  */
#line 227 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 1805 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* program_statement: program_head  */
#line 231 "include/syntax-analyzer/components/yacc.y"
    {
       (yyval.returnable) = false;

       SemanticActions::announceSpecificError(INVALID_PROGRAM_NESTING);

    }
#line 1816 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* program_statement: '{' '}'  */
#line 238 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1827 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* program_statement: '{' program_statements '}'  */
#line 245 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1838 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* program_statement: '{' program_statements $end  */
#line 252 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1850 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* program_statement: error ';'  */
#line 260 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;

    }
#line 1859 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type variable_list ';'  */
#line 270 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("VARIABLE DECLARATION");
    }
#line 1867 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* declarative_stmt: type error ';'  */
#line 274 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1876 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 31: /* declarative_stmt: type variable_list error  */
#line 279 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1885 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* $@3: %empty  */
#line 284 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction (
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, (yyvsp[-1].sref)->symbol})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionName((yyvsp[-1].sref)->symbol);

    }
#line 1897 "src/syntax-analyzer/components/parser.cpp"
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
#line 1911 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 36: /* variable_list: variable  */
#line 309 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1919 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* variable_list: variable_list ',' variable  */
#line 313 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1927 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 38: /* $@5: %empty  */
#line 317 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 1935 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 39: /* variable_list: variable_list $@5 variable  */
#line 321 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1943 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* variable_list: variable_list ',' error  */
#line 325 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1952 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* type: WORD_UINT  */
#line 333 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UINT;
    }
#line 1960 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* type: WORD_FLOAT  */
#line 337 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = FLOAT;
        SemanticActions::announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1969 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* $@6: %empty  */
#line 347 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();

    }
#line 1978 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* unnamed_function_declaration_tail: function_body ';'  */
#line 356 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

    }
#line 1988 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* unnamed_function_declaration_tail: function_body error  */
#line 362 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2001 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* $@7: %empty  */
#line 374 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
        if (entry != nullptr)
            CodeGenerator::addIntermediateCodeBlock(entry);

    }
#line 2012 "src/syntax-analyzer/components/parser.cpp"
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
#line 2027 "src/syntax-analyzer/components/parser.cpp"
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
#line 2043 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 53: /* $@8: %empty  */
#line 413 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2051 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* formal_parameter: type IDENTIFIER  */
#line 421 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2061 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 56: /* formal_parameter: type error  */
#line 427 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2071 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* formal_parameter: IDENTIFIER  */
#line 433 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2083 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* formal_parameter: parameter_semantics type IDENTIFIER  */
#line 441 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2092 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* formal_parameter: parameter_semantics type error  */
#line 446 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2102 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* formal_parameter: parameter_semantics error  */
#line 452 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        SemanticActions::announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;

    }
#line 2113 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 459 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2124 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* parameter_semantics: WORD_CR  */
#line 469 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CR);

    }
#line 2133 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* function_body: '{' program_statements '}'  */
#line 479 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 2141 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* function_body: '{' '}'  */
#line 483 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 2149 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 65: /* function_body: '{' program_statements $end  */
#line 487 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    }
#line 2160 "src/syntax-analyzer/components/parser.cpp"
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
#line 2178 "src/syntax-analyzer/components/parser.cpp"
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
#line 2199 "src/syntax-analyzer/components/parser.cpp"
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
#line 2221 "src/syntax-analyzer/components/parser.cpp"
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
#line 2242 "src/syntax-analyzer/components/parser.cpp"
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
#line 2264 "src/syntax-analyzer/components/parser.cpp"
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
#line 2284 "src/syntax-analyzer/components/parser.cpp"
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
#line 2304 "src/syntax-analyzer/components/parser.cpp"
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
#line 2324 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 74: /* return: WORD_RETURN error ';'  */
#line 631 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(RETURN_SYNTAX_ERROR);
        yyerrok;

    }
#line 2334 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* executable_stmt: assignment  */
#line 641 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2340 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* executable_stmt: multiple_assignments  */
#line 642 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2346 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 77: /* executable_stmt: invocation  */
#line 643 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2352 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 78: /* executable_stmt: if  */
#line 644 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2358 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 79: /* executable_stmt: print  */
#line 645 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2364 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 80: /* executable_stmt: return  */
#line 646 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = true;  }
#line 2370 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* executable_stmt: do_while  */
#line 647 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2376 "src/syntax-analyzer/components/parser.cpp"
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
#line 2403 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* assignment: variable OP_ASSIGN error ';'  */
#line 677 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2413 "src/syntax-analyzer/components/parser.cpp"
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
#line 2431 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 85: /* assignment_tail: expression ';'  */
#line 703 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::logStructure("ASSIGNMENT");

    }
#line 2442 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 86: /* assignment_tail: expression error  */
#line 710 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2454 "src/syntax-analyzer/components/parser.cpp"
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
#line 2471 "src/syntax-analyzer/components/parser.cpp"
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
#line 2488 "src/syntax-analyzer/components/parser.cpp"
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
#line 2505 "src/syntax-analyzer/components/parser.cpp"
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
#line 2523 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 91: /* $@9: %empty  */
#line 776 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;

    }
#line 2533 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 93: /* print: WORD_PRINT error ';'  */
#line 783 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(PRINT_SYNTAX_ERROR);
        yyerrok;
    }
#line 2542 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* print_end: %empty  */
#line 792 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
    }
#line 2550 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* multiple_assignments: variable assignment_list opt_trunc_constant ';'  */
#line 801 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2560 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* multiple_assignments: variable assignment_list opt_trunc_constant error  */
#line 807 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2572 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 98: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 815 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2584 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 99: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 823 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2597 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 100: /* multiple_assignments: variable assignment_list ';'  */
#line 832 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::announceSpecificError(MISSING_RIGHT_SIDE_VALUES);

    }
#line 2608 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* multiple_assignments: variable assignment_list error  */
#line 839 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2621 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* multiple_assignments: variable error ';'  */
#line 848 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;

    }
#line 2633 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 104: /* assignment_list: ',' variable assignment_list opt_trunc_constant ','  */
#line 860 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2641 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 105: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 864 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_EQUALS);

    }
#line 2652 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 107: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 872 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[0].metadata));
        SemanticActions::announceSpecificError(MISSING_COMMA);

    }
#line 2662 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* assignment_list: ',' variable assignment_list error  */
#line 878 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2672 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* assignment_end: opt_trunc_constant ','  */
#line 887 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2680 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* assignment_end: opt_trunc_constant error  */
#line 891 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_COMMA);
        yyerrok;

    }
#line 2692 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* $@10: %empty  */
#line 902 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_COMMA);
    }
#line 2700 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 114: /* $@11: %empty  */
#line 911 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2708 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 117: /* $@12: %empty  */
#line 917 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2716 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* invocation: function_invocation_head error  */
#line 928 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2725 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* invocation: lambda_invocation_head error  */
#line 934 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2734 "src/syntax-analyzer/components/parser.cpp"
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
#line 2759 "src/syntax-analyzer/components/parser.cpp"
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
#line 2781 "src/syntax-analyzer/components/parser.cpp"
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
#line 2800 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* function_invocation_tail: real_parameter_list ')'  */
#line 1004 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, ")");
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
    }
#line 2812 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* function_invocation_tail: ')'  */
#line 1012 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = { UNKNOWN, StringPool::create(")") };

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
        SemanticActions::announceSpecificError(MISSING_ARGUMENT);
    }
#line 2823 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* real_parameter_list: real_parameter  */
#line 1022 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 2831 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 129: /* real_parameter_list: real_parameter_list ',' real_parameter  */
#line 1026 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].metadata).expression.pid, ", " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
    }
#line 2841 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* real_parameter_list: real_parameter_list_setup real_parameter  */
#line 1032 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

    }
#line 2852 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 131: /* real_parameter_list_setup: real_parameter_list  */
#line 1042 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2861 "src/syntax-analyzer/components/parser.cpp"
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
#line 2903 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* real_parameter: expression error  */
#line 1088 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2914 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 134: /* $@13: %empty  */
#line 1100 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclaration((yyvsp[-1].sref)->symbol);
        CodeGenerator::addIntermediateCodeBlock (
              SemanticAnalyzer::CHK_LAMBDAS.getLambda().function
        );

    }
#line 2926 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 136: /* $@14: %empty  */
#line 1112 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 2934 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* $@15: %empty  */
#line 1117 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);

    }
#line 2944 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 140: /* lambda_invocation_middle: '{' executable_statements error  */
#line 1124 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 2956 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* lambda_invocation_middle: executable_statements error  */
#line 1132 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_BOTH_BRACKETS);
        yyerrok;

    }
#line 2968 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 142: /* lambda_invocation_tail: '(' lambda_real_parameter ')'  */
#line 1143 "include/syntax-analyzer/components/yacc.y"
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
#line 3024 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* lambda_real_parameter: opt_trunc_variable  */
#line 1197 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3030 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* lambda_real_parameter: opt_trunc_constant  */
#line 1198 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3036 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* if: if_word if_head ';'  */
#line 1205 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3044 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 146: /* if: if_word if_head error  */
#line 1209 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 3055 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 147: /* if: if_word error ';'  */
#line 1216 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;

    }
#line 3067 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 148: /* if: if_word condition error ';'  */
#line 1224 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3080 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* if: if_word condition_body_setup WORD_ELSE error ';'  */
#line 1233 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

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
#line 3106 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 150: /* if_word: WORD_IF  */
#line 1258 "include/syntax-analyzer/components/yacc.y"
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
#line 3122 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* if_head: condition_body_setup WORD_ENDIF  */
#line 1273 "include/syntax-analyzer/components/yacc.y"
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
#line 3146 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 152: /* if_head: condition_body_setup WORD_ELSE executable_body WORD_ENDIF  */
#line 1293 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

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
#line 3170 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 153: /* if_head: condition_body_setup error  */
#line 1313 "include/syntax-analyzer/components/yacc.y"
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
#line 3195 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 154: /* if_head: condition_body_setup WORD_ELSE executable_body error  */
#line 1334 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable) || (yyvsp[-1].returnable);

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
#line 3220 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 155: /* if_head: condition error WORD_ENDIF  */
#line 1355 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3232 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* if_head: condition error WORD_ELSE WORD_ENDIF  */
#line 1363 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3244 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 157: /* if_head: condition error WORD_ELSE  */
#line 1371 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3257 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* if_head: condition_body_setup WORD_ELSE error WORD_ENDIF  */
#line 1380 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

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
#line 3282 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 159: /* if_head: WORD_ELSE executable_body WORD_ENDIF  */
#line 1401 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_IF_STATEMENT);

    }
#line 3293 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* if_head: condition_body_setup WORD_ELSE executable_body INVALID_RWORD  */
#line 1408 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

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
#line 3314 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 161: /* if_head: condition_body_setup INVALID_RWORD executable_body WORD_ENDIF  */
#line 1425 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

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
#line 3335 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 162: /* if_head: condition_body_setup INVALID_RWORD executable_body INVALID_RWORD  */
#line 1442 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

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
#line 3356 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 163: /* condition_body_setup: condition_setup then_body_setup  */
#line 1462 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3364 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 164: /* condition_setup: condition  */
#line 1469 "include/syntax-analyzer/components/yacc.y"
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
#line 3380 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 165: /* then_body_setup: executable_body  */
#line 1484 "include/syntax-analyzer/components/yacc.y"
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
#line 3401 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* do_while: do_while_head do_body  */
#line 1506 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3409 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 167: /* $@16: %empty  */
#line 1510 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);

    }
#line 3418 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 168: /* do_while: WORD_DO $@16 WORD_WHILE do_while_tail  */
#line 1515 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3426 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 169: /* do_while: WORD_DO error ';'  */
#line 1519 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;

    }
#line 3438 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 170: /* do_while_head: WORD_DO  */
#line 1530 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_DO_START,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            }));
    }
#line 3452 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 171: /* do_body: executable_body WORD_WHILE condition ';'  */
#line 1543 "include/syntax-analyzer/components/yacc.y"
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
#line 3472 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* do_body: executable_body WORD_WHILE condition error  */
#line 1559 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3484 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* $@17: %empty  */
#line 1567 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE);

    }
#line 3493 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* do_body: executable_body $@17 do_while_tail  */
#line 1572 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);
    }
#line 3501 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 176: /* do_while_tail: condition error  */
#line 1580 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3511 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* executable_body: '{' executable_statements '}'  */
#line 1591 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3519 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 178: /* executable_body: '{' executable_statements error  */
#line 1595 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 3531 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 179: /* executable_body: '{' error '}'  */
#line 1603 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        yyerrok;
    }
#line 3541 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 180: /* executable_body: executable_stmt  */
#line 1609 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3549 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 181: /* executable_body: '{' '}'  */
#line 1613 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3557 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 182: /* executable_statements: executable_stmt  */
#line 1619 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 3563 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* executable_statements: executable_statements executable_stmt  */
#line 1620 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 3569 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* opt_trunc_constant: numeric_constant  */
#line 1627 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3577 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 185: /* opt_trunc_constant: trunc_constant  */
#line 1631 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3585 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 186: /* trunc_constant: WORD_TRUNC '(' numeric_constant ')'  */
#line 1638 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

    }
#line 3596 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 187: /* trunc_constant: WORD_TRUNC '(' numeric_constant error  */
#line 1645 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3610 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 188: /* trunc_constant: WORD_TRUNC numeric_constant ')'  */
#line 1655 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3623 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 189: /* trunc_constant: WORD_TRUNC numeric_constant error  */
#line 1664 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3637 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* opt_trunc_variable: variable  */
#line 1677 "include/syntax-analyzer/components/yacc.y"
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
#line 3656 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* opt_trunc_variable: trunc_variable  */
#line 1692 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3664 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* trunc_variable: WORD_TRUNC '(' variable ')'  */
#line 1699 "include/syntax-analyzer/components/yacc.y"
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
#line 3688 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* trunc_variable: WORD_TRUNC '(' variable error  */
#line 1719 "include/syntax-analyzer/components/yacc.y"
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
#line 3715 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 194: /* trunc_variable: WORD_TRUNC variable ')'  */
#line 1742 "include/syntax-analyzer/components/yacc.y"
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
#line 3742 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 195: /* trunc_variable: WORD_TRUNC variable error  */
#line 1765 "include/syntax-analyzer/components/yacc.y"
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
#line 3769 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 196: /* trunc_variable: WORD_TRUNC error ';'  */
#line 1788 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("trunc ..."), false };

        SemanticActions::specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;

    }
#line 3782 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 197: /* trunc_expression: WORD_TRUNC '(' expression ')'  */
#line 1800 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");
    }
#line 3792 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 198: /* trunc_expression: WORD_TRUNC '(' expression error  */
#line 1806 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3806 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 199: /* trunc_expression: WORD_TRUNC expression ')'  */
#line 1816 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3819 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 200: /* trunc_expression: WORD_TRUNC expression error  */
#line 1825 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3833 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 201: /* condition: '(' comparison ')'  */
#line 1840 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);
    }
#line 3841 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 202: /* condition: '(' comparison error  */
#line 1844 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3853 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 203: /* condition: comparison ')'  */
#line 1852 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3864 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 204: /* condition: comparison error  */
#line 1859 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;

    }
#line 3876 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 205: /* comparison: expression comparison_operator expression  */
#line 1870 "include/syntax-analyzer/components/yacc.y"
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
#line 3903 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 206: /* comparison: expression error  */
#line 1893 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;

    }
#line 3915 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 207: /* comparison: expression comparison_operator error  */
#line 1901 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 3923 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 208: /* comparison_operator: OP_EQUAL  */
#line 1908 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_EQUAL, StringPool::create(Translator::translate(OP_EQUAL)) };
    }
#line 3931 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 209: /* comparison_operator: OP_NOT_EQUAL  */
#line 1912 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_NOT_EQUAL, StringPool::create(Translator::translate(OP_NOT_EQUAL)) };
    }
#line 3939 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* comparison_operator: OP_GE  */
#line 1916 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GE, StringPool::create(Translator::translate(OP_GE)) };
    }
#line 3947 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 211: /* comparison_operator: OP_LE  */
#line 1920 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LE, StringPool::create(Translator::translate(OP_LE)) };
    }
#line 3955 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 212: /* comparison_operator: '>'  */
#line 1924 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GT, StringPool::create(">") };
    }
#line 3963 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 213: /* comparison_operator: '<'  */
#line 1928 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LT, StringPool::create("<") };
    }
#line 3971 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 214: /* expression: term  */
#line 1937 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3979 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 215: /* expression: expression_setup positive_term  */
#line 1941 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;
        (yyval.metadata).reference = (yyvsp[-1].metadata).reference;
        
        (yyval.metadata).expression.assignable = false;
    }
#line 3995 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 216: /* expression: '+' term  */
#line 1953 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUM_OPERAND);

    }
#line 4006 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 217: /* expression: '+' error  */
#line 1960 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;

    }
#line 4019 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 218: /* expression: expression '+' term  */
#line 1969 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4027 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 219: /* expression: expression '+' error  */
#line 1973 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 4039 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 220: /* expression: expression '-' term  */
#line 1981 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4047 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 221: /* expression: expression '-' error  */
#line 1985 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 4059 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 222: /* expression: trunc_expression  */
#line 1993 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4067 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 223: /* expression: expression '+' trunc_expression  */
#line 1997 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4075 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 224: /* expression: expression '-' trunc_expression  */
#line 2001 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4083 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 225: /* expression_setup: expression  */
#line 2008 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 4093 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 226: /* term: positive_term  */
#line 2019 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4101 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 227: /* term: negative_term  */
#line 2023 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4109 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 228: /* positive_term: positive_term '*' factor  */
#line 2030 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4117 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 229: /* positive_term: positive_term '/' factor  */
#line 2034 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4125 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 230: /* positive_term: trunc_expression '/' factor  */
#line 2038 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4133 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 231: /* positive_term: trunc_expression '*' factor  */
#line 2042 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4141 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 232: /* positive_term: trunc_expression '/' trunc_expression  */
#line 2046 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4149 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 233: /* positive_term: trunc_expression '*' trunc_expression  */
#line 2050 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4157 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 234: /* positive_term: positive_term '/' trunc_expression  */
#line 2054 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4165 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 235: /* positive_term: positive_term '*' trunc_expression  */
#line 2058 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4173 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 236: /* positive_term: positive_factor  */
#line 2062 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4181 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 237: /* positive_term: positive_term '*' error  */
#line 2066 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4193 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 238: /* positive_term: positive_term '/' error  */
#line 2074 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4205 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 239: /* negative_term: negative_term '*' factor  */
#line 2085 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4213 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 240: /* negative_term: negative_term '/' factor  */
#line 2089 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4221 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 241: /* negative_term: negative_term '/' trunc_expression  */
#line 2093 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4229 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 242: /* negative_term: negative_term '*' trunc_expression  */
#line 2097 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4237 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 243: /* negative_term: negative_factor  */
#line 2101 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4245 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 244: /* negative_term: negative_term '*' error  */
#line 2105 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4257 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 245: /* negative_term: negative_term '/' error  */
#line 2113 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4269 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 246: /* negative_term: '*' factor  */
#line 2121 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_MUL_FACTOR);

    }
#line 4280 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 247: /* negative_term: '/' factor  */
#line 2128 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_DIV_FACTOR);

    }
#line 4291 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 248: /* negative_term: '*' error  */
#line 2135 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4304 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 249: /* negative_term: '/' error  */
#line 2144 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4317 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 250: /* factor: positive_factor  */
#line 2158 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4325 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 251: /* factor: negative_factor  */
#line 2162 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4333 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 252: /* positive_factor: variable  */
#line 2169 "include/syntax-analyzer/components/yacc.y"
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
#line 4352 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 253: /* positive_factor: positive_constant  */
#line 2184 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4360 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 254: /* positive_factor: function_invocation_head  */
#line 2188 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4368 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 255: /* negative_factor: negative_constant  */
#line 2195 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4376 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 256: /* negative_factor: lambda_invocation_head  */
#line 2199 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };
        
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);
    }
#line 4387 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 257: /* negative_factor: '-' LITERAL_UINT  */
#line 2206 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4399 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 258: /* negative_factor: '-' function_invocation_head  */
#line 2214 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4410 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 259: /* negative_factor: '-' variable  */
#line 2221 "include/syntax-analyzer/components/yacc.y"
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
#line 4430 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 260: /* negative_factor: '-' lambda_invocation_head  */
#line 2237 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);

    }
#line 4443 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 261: /* negative_factor: '-' error  */
#line 2246 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUB_OPERANDS);
        yyerrok;

    }
#line 4456 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 262: /* numeric_constant: positive_constant  */
#line 2260 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4464 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 263: /* numeric_constant: negative_constant  */
#line 2264 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4472 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 264: /* positive_constant: LITERAL_UINT  */
#line 2271 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4481 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 265: /* positive_constant: LITERAL_FLOAT  */
#line 2276 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4490 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 266: /* negative_constant: '-' LITERAL_FLOAT  */
#line 2284 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL , .lref = SemanticActions::turnNegative((yyvsp[0].lref)) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };

    }
#line 4500 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 267: /* variable: IDENTIFIER  */
#line 2295 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.pid) = StringPool::create((yyvsp[0].sref)->symbol);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariableName((yyvsp[0].sref)->symbol);

    }
#line 4511 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 268: /* variable: variable '.' IDENTIFIER  */
#line 2302 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].pid), "." + (yyvsp[0].sref)->symbol);
        (yyval.pid) = (yyvsp[-2].pid);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariablePrefix((yyvsp[0].sref)->symbol);

    }
#line 4523 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 4527 "src/syntax-analyzer/components/parser.cpp"

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

#line 2311 "include/syntax-analyzer/components/yacc.y"
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
