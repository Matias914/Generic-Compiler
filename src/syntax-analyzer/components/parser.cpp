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
#line 2 "include/syntax-analyzer/components/yacc.y"

#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/semantic_actions.h"

void yyerror(const char* s);

using namespace SyntaxAnalyzer::SemanticActions;

#define yylex LexicalAnalyzer::yylex

#line 83 "src/syntax-analyzer/components/parser.cpp"

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
  YYSYMBOL_INVALID_TOKEN = 3,              /* INVALID_TOKEN  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_ENDIF = 6,                      /* ENDIF  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_TRUNC = 11,                     /* TRUNC  */
  YYSYMBOL_UINT = 12,                      /* UINT  */
  YYSYMBOL_FLOAT = 13,                     /* FLOAT  */
  YYSYMBOL_CR = 14,                        /* CR  */
  YYSYMBOL_POINTER_OP = 15,                /* POINTER_OP  */
  YYSYMBOL_EQUAL_OP = 16,                  /* EQUAL_OP  */
  YYSYMBOL_GE_OP = 17,                     /* GE_OP  */
  YYSYMBOL_LE_OP = 18,                     /* LE_OP  */
  YYSYMBOL_ASSIGN_OP = 19,                 /* ASSIGN_OP  */
  YYSYMBOL_NOT_EQUAL_OP = 20,              /* NOT_EQUAL_OP  */
  YYSYMBOL_IDENTIFIER = 21,                /* IDENTIFIER  */
  YYSYMBOL_FLOAT_LITERAL = 22,             /* FLOAT_LITERAL  */
  YYSYMBOL_UINTEGER_LITERAL = 23,          /* UINTEGER_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 24,            /* STRING_LITERAL  */
  YYSYMBOL_25_ = 25,                       /* '{'  */
  YYSYMBOL_26_ = 26,                       /* '}'  */
  YYSYMBOL_27_ = 27,                       /* ';'  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '+'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_38_ = 38,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_global = 40,                    /* global  */
  YYSYMBOL_global_statement = 41,          /* global_statement  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_program_statements = 43,        /* program_statements  */
  YYSYMBOL_program_statement = 44,         /* program_statement  */
  YYSYMBOL_declarative_stmt = 45,          /* declarative_stmt  */
  YYSYMBOL_variable_list = 46,             /* variable_list  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_type = 48,                      /* type  */
  YYSYMBOL_formal_parameter_list = 49,     /* formal_parameter_list  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_formal_parameter = 51,          /* formal_parameter  */
  YYSYMBOL_parameter_semantics = 52,       /* parameter_semantics  */
  YYSYMBOL_function_body = 53,             /* function_body  */
  YYSYMBOL_function_statements = 54,       /* function_statements  */
  YYSYMBOL_function_statement = 55,        /* function_statement  */
  YYSYMBOL_return = 56,                    /* return  */
  YYSYMBOL_executable_stmt = 57,           /* executable_stmt  */
  YYSYMBOL_assignment = 58,                /* assignment  */
  YYSYMBOL_print = 59,                     /* print  */
  YYSYMBOL_60_3 = 60,                      /* $@3  */
  YYSYMBOL_print_end = 61,                 /* print_end  */
  YYSYMBOL_multiple_assignments = 62,      /* multiple_assignments  */
  YYSYMBOL_assignment_list = 63,           /* assignment_list  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_assignment_list_end = 65,       /* assignment_list_end  */
  YYSYMBOL_extra_numeric_constants = 66,   /* extra_numeric_constants  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_invocation = 68,                /* invocation  */
  YYSYMBOL_function_invocation = 69,       /* function_invocation  */
  YYSYMBOL_real_parameter_list = 70,       /* real_parameter_list  */
  YYSYMBOL_71_6 = 71,                      /* $@6  */
  YYSYMBOL_real_parameter = 72,            /* real_parameter  */
  YYSYMBOL_lambda_invocation = 73,         /* lambda_invocation  */
  YYSYMBOL_lambda_real_parameter = 74,     /* lambda_real_parameter  */
  YYSYMBOL_if = 75,                        /* if  */
  YYSYMBOL_executable_body = 76,           /* executable_body  */
  YYSYMBOL_executable_statements = 77,     /* executable_statements  */
  YYSYMBOL_control_stmt = 78,              /* control_stmt  */
  YYSYMBOL_79_7 = 79,                      /* $@7  */
  YYSYMBOL_80_8 = 80,                      /* $@8  */
  YYSYMBOL_end_while_statement = 81,       /* end_while_statement  */
  YYSYMBOL_opt_trunc_constant = 82,        /* opt_trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 83,        /* opt_trunc_variable  */
  YYSYMBOL_opt_trunc_expression = 84,      /* opt_trunc_expression  */
  YYSYMBOL_condition = 85,                 /* condition  */
  YYSYMBOL_comparison = 86,                /* comparison  */
  YYSYMBOL_comparison_operator = 87,       /* comparison_operator  */
  YYSYMBOL_expression = 88,                /* expression  */
  YYSYMBOL_89_9 = 89,                      /* $@9  */
  YYSYMBOL_term = 90,                      /* term  */
  YYSYMBOL_positive_term = 91,             /* positive_term  */
  YYSYMBOL_negative_term = 92,             /* negative_term  */
  YYSYMBOL_factor = 93,                    /* factor  */
  YYSYMBOL_positive_factor = 94,           /* positive_factor  */
  YYSYMBOL_negative_factor = 95,           /* negative_factor  */
  YYSYMBOL_numeric_constant = 96,          /* numeric_constant  */
  YYSYMBOL_positive_constant = 97,         /* positive_constant  */
  YYSYMBOL_negative_constant = 98,         /* negative_constant  */
  YYSYMBOL_variable = 99                   /* variable  */
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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   828

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


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
      28,    29,    36,    34,    30,    35,    38,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
      33,    31,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    60,    61,    65,    69,    73,    77,    78,
      82,    87,    91,    99,   103,   110,   111,   115,   116,   117,
     118,   122,   126,   131,   140,   144,   149,   154,   158,   162,
     167,   177,   178,   180,   179,   183,   191,   192,   201,   202,
     204,   203,   210,   211,   216,   220,   221,   226,   232,   239,
     243,   244,   252,   253,   257,   258,   262,   263,   268,   274,
     279,   285,   289,   293,   302,   303,   304,   305,   306,   307,
     311,   315,   323,   327,   332,   336,   342,   341,   350,   351,
     362,   366,   371,   375,   381,   390,   391,   392,   397,   396,
     401,   408,   409,   414,   420,   422,   424,   423,   432,   433,
     438,   439,   447,   451,   459,   460,   462,   461,   468,   469,
     479,   483,   487,   491,   498,   499,   505,   509,   514,   518,
     523,   528,   533,   538,   544,   549,   555,   560,   566,   574,
     575,   580,   584,   585,   591,   595,   601,   600,   606,   605,
     613,   614,   624,   625,   626,   631,   635,   643,   644,   645,
     650,   654,   662,   663,   664,   669,   673,   683,   684,   689,
     693,   701,   702,   710,   711,   712,   713,   714,   715,   719,
     720,   721,   723,   722,   726,   731,   736,   740,   748,   749,
     753,   754,   755,   756,   761,   769,   770,   771,   772,   777,
     782,   786,   790,   795,   803,   804,   808,   809,   810,   814,
     815,   816,   820,   824,   828,   832,   840,   841,   845,   846,
     850,   857,   858
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
  "\"end of file\"", "error", "\"invalid token\"", "INVALID_TOKEN", "IF",
  "ELSE", "ENDIF", "DO", "WHILE", "RETURN", "PRINT", "TRUNC", "UINT",
  "FLOAT", "CR", "POINTER_OP", "EQUAL_OP", "GE_OP", "LE_OP", "ASSIGN_OP",
  "NOT_EQUAL_OP", "IDENTIFIER", "FLOAT_LITERAL", "UINTEGER_LITERAL",
  "STRING_LITERAL", "'{'", "'}'", "';'", "'('", "')'", "','", "'='", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "'.'", "$accept", "global",
  "global_statement", "program", "program_statements", "program_statement",
  "declarative_stmt", "variable_list", "$@1", "type",
  "formal_parameter_list", "$@2", "formal_parameter",
  "parameter_semantics", "function_body", "function_statements",
  "function_statement", "return", "executable_stmt", "assignment", "print",
  "$@3", "print_end", "multiple_assignments", "assignment_list", "$@4",
  "assignment_list_end", "extra_numeric_constants", "$@5", "invocation",
  "function_invocation", "real_parameter_list", "$@6", "real_parameter",
  "lambda_invocation", "lambda_real_parameter", "if", "executable_body",
  "executable_statements", "control_stmt", "$@7", "$@8",
  "end_while_statement", "opt_trunc_constant", "opt_trunc_variable",
  "opt_trunc_expression", "condition", "comparison", "comparison_operator",
  "expression", "$@9", "term", "positive_term", "negative_term", "factor",
  "positive_factor", "negative_factor", "numeric_constant",
  "positive_constant", "negative_constant", "variable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-205)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-173)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     471,  -205,    -1,   680,   753,   753,   684,     8,  -205,  -205,
     113,   597,  -205,   193,   500,  -205,  -205,  -205,   143,  -205,
    -205,  -205,  -205,  -205,  -205,    19,    24,  -205,  -205,    39,
    -205,   791,    47,  -205,  -205,   662,   231,   442,     7,   157,
    -205,  -205,   441,   629,    18,   367,  -205,   233,   393,  -205,
    -205,  -205,  -205,    75,   783,  -205,   130,   225,   238,   662,
     174,   176,   597,   330,   214,   597,  -205,   529,  -205,  -205,
    -205,  -205,   240,  -205,  -205,   247,   251,   474,   353,    75,
    -205,  -205,  -205,  -205,   162,   702,   266,  -205,   271,   292,
     719,   201,    26,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
      75,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,  -205,   702,   103,   324,  -205,  -205,   375,
     386,   493,   312,   356,   416,   425,  -205,   651,   289,   680,
     680,   680,   180,  -205,  -205,   294,  -205,   278,   283,   558,
     320,   331,  -205,    37,  -205,   587,  -205,  -205,  -205,   326,
    -205,   474,  -205,  -205,   152,   404,  -205,   481,  -205,  -205,
     195,   266,  -205,  -205,    75,    33,   121,  -205,  -205,   396,
    -205,   341,  -205,  -205,  -205,  -205,   275,  -205,  -205,  -205,
    -205,  -205,    92,   344,  -205,  -205,   661,    56,  -205,  -205,
    -205,  -205,   233,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,   354,  -205,  -205,  -205,    70,  -205,   105,  -205,  -205,
    -205,   187,  -205,   357,   192,   224,  -205,  -205,  -205,  -205,
     702,   702,  -205,   373,  -205,  -205,   761,   437,  -205,  -205,
     374,   474,   474,  -205,  -205,   239,  -205,    75,    75,   125,
    -205,  -205,   321,   497,   427,    32,   405,  -205,  -205,   377,
    -205,  -205,   115,   122,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,   228,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,   783,   683,   374,   739,   255,  -205,  -205,  -205,
    -205,   274,   497,  -205,   383,   385,    72,  -205,  -205,  -205,
    -205,   497,   497,  -205,   409,  -205,  -205,   256,  -205,  -205,
     775,   413,   786,   257,  -205,   619,  -205,  -205,  -205,  -205,
    -205,    73,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,   417,   786,   468,   525,   423,  -205,  -205,    75,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,   468,   440,   448,   433,
      15,  -205,   456,  -205,  -205,   128,  -205,  -205,  -205,  -205,
    -205
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,   138,     0,     0,    36,    37,
     211,     0,    11,     0,     0,     2,     8,     5,     0,    69,
       6,    64,    68,    65,    66,     0,     0,    67,     7,     0,
      12,     0,   211,   209,   208,     0,     0,     0,     0,     0,
     198,   200,     0,     0,     0,   152,   171,   178,   179,   182,
     187,   197,   199,   196,     0,   131,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,    15,    17,
      18,    19,     0,     1,     3,     0,   211,     0,     0,    31,
      99,    98,   101,   100,     0,     0,     0,    85,     0,     0,
       0,     0,     0,   177,   176,   205,   210,   201,   202,   204,
     203,   192,   190,   194,   195,   193,   191,   162,   163,   165,
     166,   164,   167,   168,     0,     0,     0,   160,   159,     0,
       0,     0,     0,     0,     0,     0,   132,     0,     0,     0,
       0,     0,     0,    60,    63,    59,    76,     0,     0,     0,
       0,   106,   104,     0,    23,     0,    10,     9,    16,     0,
      25,     0,    49,    44,     0,    40,    38,     0,    26,    24,
       0,     0,   211,    84,    88,     0,     0,   212,    83,     0,
      82,     0,    94,   142,   206,   207,     0,   156,   155,   158,
     157,   161,     0,     0,   123,   120,     0,     0,   174,   169,
     175,   170,   173,   183,   180,   184,   181,   188,   185,   189,
     186,     0,   129,   133,   128,     0,   137,     0,   139,    58,
      61,     0,    62,     0,     0,     0,    14,    13,   103,   102,
       0,     0,   109,     0,    22,    21,     0,    40,    43,    42,
       0,     0,     0,    47,    48,     0,    35,    32,    34,     0,
      71,    70,     0,     0,     0,     0,     0,   154,   153,     0,
     125,   122,     0,     0,   117,   116,   130,   135,   134,   141,
     140,    57,    56,     0,    77,    73,    72,    75,    74,   105,
     107,   108,     0,     0,     0,     0,     0,    39,    41,    46,
      45,     0,     0,    89,     0,    90,     0,   146,   145,    81,
      80,     0,     0,   124,     0,   127,   121,     0,    79,    78,
       0,     0,     0,     0,    54,     0,    52,    55,    30,    28,
      93,     0,    87,    86,   144,   143,    95,    97,   126,   119,
     118,     0,     0,     0,     0,     0,   115,   114,   147,    29,
      27,    51,    50,    53,    92,    91,     0,     0,     0,     0,
       0,   113,     0,   112,   111,     0,   151,   150,   110,   149,
     148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -205,  -205,   484,   280,   297,   -58,     3,  -205,  -205,   -11,
     355,  -205,   286,  -205,   237,  -205,   219,  -205,   120,  -205,
    -205,  -205,  -205,  -205,  -154,  -205,  -205,  -205,  -205,  -205,
      45,  -205,  -205,   302,   100,   -59,  -205,    -4,  -204,   285,
    -205,  -205,   400,   -48,  -205,    17,     4,   492,  -205,   -18,
    -205,   -26,   414,  -205,   -33,    -7,    25,  -148,   -74,    46,
       0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    14,    15,    66,    67,    68,    69,    78,   161,    18,
     155,   232,   156,   157,   276,   305,   306,    19,    70,    21,
      22,   213,   264,    23,    89,   239,   283,   246,   292,    24,
      40,   141,   221,   142,    41,   325,    27,    56,   127,    71,
     130,    58,   206,   326,   327,    42,   207,    44,   114,    45,
     121,    46,    47,    48,   102,    49,    50,   173,    51,    52,
      53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    57,    72,    17,    29,    29,   106,    43,   101,   148,
      94,    29,   243,    91,    29,   174,   346,    17,    79,   117,
      80,   245,   273,    60,    72,    82,    30,   179,    32,    33,
      34,   103,   103,   287,   240,    13,    61,   100,   222,   116,
      84,   172,    37,    29,   347,    25,    81,   118,    72,    25,
      25,    83,   223,    88,    29,   180,    25,   254,    85,    25,
     241,   288,    29,   104,   104,    29,   154,    29,   300,    86,
      87,   257,   176,   314,   334,    63,   132,    88,   138,    72,
     143,   148,    98,   255,   164,   282,   166,   148,    25,   194,
     196,   198,   200,   189,   191,   174,   286,   258,   249,    25,
      26,   315,   165,   335,    26,    26,   259,    25,   182,   183,
      25,    26,    25,    88,    26,   103,   103,   103,   103,   250,
      20,   294,   242,   296,    55,    55,   281,    29,   297,   349,
     184,   181,   260,   205,    20,   175,   128,    99,    62,    29,
     154,    63,   295,    26,    75,    29,   235,   104,   104,   104,
     104,    86,    87,   228,    26,    86,    87,   350,   105,    88,
     237,   238,    26,    55,    76,    26,    88,    26,   174,   174,
     174,    77,    25,   229,   126,   133,   245,   136,    32,    33,
      34,   209,   253,   162,    25,    13,    29,    31,   261,   163,
      25,   286,    37,   265,   284,   285,   236,    32,    33,    34,
     137,   134,   177,   135,    13,     8,     9,   210,   174,   211,
      36,    37,    38,    39,   262,   175,   162,   174,   174,   266,
     154,   154,  -172,  -172,  -172,   267,    29,    26,   174,   298,
     178,    25,    93,   129,   311,   119,   120,   143,   143,    26,
     279,   144,   164,   316,   317,    26,   131,   203,   174,   174,
     174,   268,    32,    33,    34,   299,   308,   319,   329,    13,
     280,   149,   174,   337,   338,   174,    37,    38,    39,   122,
     123,    25,    29,    29,   150,    29,   247,   342,   304,   151,
      16,   164,   309,   320,   330,    28,    26,   162,   175,   175,
     175,    72,   167,   168,    16,   162,  -172,  -172,  -172,    28,
      29,   310,   328,   169,   248,    29,    55,   214,   304,   119,
     120,    72,   215,   193,    33,    34,   204,    25,    25,   170,
      25,   212,   328,   328,   340,   185,    26,   171,   175,   186,
     187,   140,   169,    32,    33,    34,   328,   175,   175,   345,
      13,    31,   162,    33,    34,    25,   126,    37,   175,   218,
      25,    32,    33,    34,   158,   226,   171,   195,    13,   139,
     219,   220,   145,    96,    36,    37,    38,    39,   175,   175,
     175,   251,    26,    26,   -33,    26,   188,    32,    33,    34,
     159,   256,   175,   160,    13,   175,   263,   190,  -172,  -172,
    -172,    37,   126,   203,   271,   307,    32,    33,    34,   275,
      26,   119,   120,    13,   293,    26,   289,    32,    33,    34,
      37,    38,    39,   312,    13,   313,   -96,   197,    33,    34,
     203,    37,    38,    39,   244,   307,   199,   -96,   -96,   124,
     125,   171,   290,   230,   231,   291,   318,    32,    33,    34,
     -96,   323,   107,    95,    13,   336,    32,    33,    34,    33,
      34,    37,   341,    13,   162,    33,    34,   108,   109,   110,
      37,   111,   171,    32,    96,    97,   274,   231,   171,   343,
      13,     1,     2,   112,   113,     3,     4,   344,     5,   324,
       6,     7,   233,     8,     9,   348,     8,     9,   152,   162,
      33,    34,    10,     8,     9,   153,    11,    12,    74,    13,
      73,     2,   234,   171,     3,     4,   227,     5,   169,     6,
       7,   303,     8,     9,    32,    33,    34,   277,   278,    33,
      34,    10,   269,   270,   333,    11,    12,    92,    13,   146,
      64,   208,   171,     3,     4,   192,     5,     0,     6,     7,
       0,     8,     9,     0,     0,     0,   162,    33,    34,     0,
      10,     0,     0,   339,    65,   147,     0,    13,   216,    64,
     171,     0,     3,     4,     0,     5,     0,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,    65,   217,     0,    13,   224,    64,     0,
       0,     3,     4,     0,     5,     0,     6,     7,    64,     8,
       9,     3,     4,     0,     5,     0,     6,     7,    10,     8,
       9,     0,    65,   225,     0,    13,     0,     0,    10,     0,
     331,     0,    65,     3,     4,    13,     0,     0,     6,     7,
     115,     8,     9,     3,     4,     0,     0,     0,     6,     7,
      32,     0,     0,     0,     0,   332,     0,    13,     0,     0,
      32,     0,   201,     0,    54,     3,     4,    13,     0,     0,
       6,     7,   252,     0,     0,     3,     4,     0,     0,     0,
       6,     7,    32,    31,     8,     9,     0,   202,     0,    13,
       0,     0,    32,    32,    33,    34,    54,     3,     4,    13,
      13,    31,     6,     7,     0,    31,    36,    37,    38,    39,
       0,    32,    33,    34,    32,    32,    33,    34,    35,   301,
       0,   302,    59,    31,    36,    37,    38,    39,    36,    37,
      38,    39,     0,    32,    33,    34,     0,     0,     0,     0,
      13,     8,     9,     0,     0,     0,    36,    37,    38,    39,
      32,    33,    34,     3,     4,     0,     0,    13,     6,     7,
       0,     8,     9,    36,    37,    38,    39,     3,     4,     0,
      32,     0,     6,     7,     0,     3,     4,    13,     0,     0,
       6,     7,     0,     0,    32,     0,     0,     0,    54,     3,
       4,    13,    32,     0,     6,     7,   272,     3,     4,    13,
       0,     0,     6,     7,     0,     0,    32,   324,     8,     9,
       0,   321,     0,   322,    32,     0,     0,   162,    33,    34,
       0,    13,    32,    33,    34,     0,     0,     0,     0,    90,
       0,   171,     0,     0,     0,    36,    37,    38,    39
};

static const yytype_int16 yycheck[] =
{
       0,     5,    13,     0,     4,     5,    39,     3,     1,    67,
      36,    11,   166,    31,    14,    89,     1,    14,    18,     1,
       1,   169,   226,     6,    35,     1,    27,     1,    21,    22,
      23,    38,    39,     1,     1,    28,    28,    37,     1,    43,
       1,    89,    35,    43,    29,     0,    27,    29,    59,     4,
       5,    27,    15,    38,    54,    29,    11,     1,    19,    14,
      27,    29,    62,    38,    39,    65,    77,    67,   272,    30,
      31,     1,    90,     1,     1,    28,    59,    38,    61,    90,
      63,   139,    37,    27,    84,   239,    86,   145,    43,   122,
     123,   124,   125,   119,   120,   169,   244,    27,     6,    54,
       0,    29,    85,    30,     4,     5,     1,    62,     5,     6,
      65,    11,    67,    38,    14,   122,   123,   124,   125,    27,
       0,     6,     1,     1,     4,     5,     1,   127,     6,     1,
      27,   114,    27,   129,    14,    89,     6,    37,    25,   139,
     151,    28,    27,    43,     1,   145,   157,   122,   123,   124,
     125,    30,    31,     1,    54,    30,    31,    29,     1,    38,
     160,   161,    62,    43,    21,    65,    38,    67,   242,   243,
     244,    28,   127,    21,    54,     1,   324,     1,    21,    22,
      23,     1,   186,    21,   139,    28,   186,    11,     1,    27,
     145,   339,    35,     1,   242,   243,     1,    21,    22,    23,
      24,    27,     1,    29,    28,    12,    13,    27,   282,    29,
      34,    35,    36,    37,    27,   169,    21,   291,   292,    27,
     231,   232,    21,    22,    23,     1,   226,   127,   302,     1,
      29,   186,     1,     8,   282,    34,    35,   220,   221,   139,
       1,    27,   242,   291,   292,   145,     8,   127,   322,   323,
     324,    27,    21,    22,    23,    27,     1,     1,     1,    28,
      21,    21,   336,   322,   323,   339,    35,    36,    37,    36,
      37,   226,   272,   273,    27,   275,     1,   336,   275,    28,
       0,   281,    27,    27,    27,     0,   186,    21,   242,   243,
     244,   302,    21,     1,    14,    21,    21,    22,    23,    14,
     300,    27,   302,    11,    29,   305,   186,    29,   305,    34,
      35,   322,    29,     1,    22,    23,    27,   272,   273,    27,
     275,    27,   322,   323,   324,     1,   226,    35,   282,     5,
       6,     1,    11,    21,    22,    23,   336,   291,   292,   339,
      28,    11,    21,    22,    23,   300,   226,    35,   302,    29,
     305,    21,    22,    23,     1,    29,    35,     1,    28,    62,
      29,    30,    65,    22,    34,    35,    36,    37,   322,   323,
     324,    27,   272,   273,    21,   275,     1,    21,    22,    23,
      27,    27,   336,    30,    28,   339,    29,     1,    21,    22,
      23,    35,   272,   273,    21,   275,    21,    22,    23,    25,
     300,    34,    35,    28,    27,   305,     1,    21,    22,    23,
      35,    36,    37,    30,    28,    30,    11,     1,    22,    23,
     300,    35,    36,    37,    28,   305,     1,    22,    23,    36,
      37,    35,    27,    29,    30,    30,    27,    21,    22,    23,
      35,    28,     1,     1,    28,    28,    21,    22,    23,    22,
      23,    35,    29,    28,    21,    22,    23,    16,    17,    18,
      35,    20,    35,    21,    22,    23,    29,    30,    35,    29,
      28,     0,     1,    32,    33,     4,     5,    29,     7,    11,
       9,    10,     1,    12,    13,    29,    12,    13,    14,    21,
      22,    23,    21,    12,    13,    21,    25,    26,    14,    28,
       0,     1,    21,    35,     4,     5,   151,     7,    11,     9,
      10,   274,    12,    13,    21,    22,    23,   231,   232,    22,
      23,    21,   220,   221,   305,    25,    26,    35,    28,     0,
       1,   131,    35,     4,     5,   121,     7,    -1,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    21,    22,    23,    -1,
      21,    -1,    -1,    28,    25,    26,    -1,    28,     0,     1,
      35,    -1,     4,     5,    -1,     7,    -1,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    25,    26,    -1,    28,     0,     1,    -1,
      -1,     4,     5,    -1,     7,    -1,     9,    10,     1,    12,
      13,     4,     5,    -1,     7,    -1,     9,    10,    21,    12,
      13,    -1,    25,    26,    -1,    28,    -1,    -1,    21,    -1,
       1,    -1,    25,     4,     5,    28,    -1,    -1,     9,    10,
       1,    12,    13,     4,     5,    -1,    -1,    -1,     9,    10,
      21,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    -1,
      21,    -1,     1,    -1,    25,     4,     5,    28,    -1,    -1,
       9,    10,     1,    -1,    -1,     4,     5,    -1,    -1,    -1,
       9,    10,    21,    11,    12,    13,    -1,    26,    -1,    28,
      -1,    -1,    21,    21,    22,    23,    25,     4,     5,    28,
      28,    11,     9,    10,    -1,    11,    34,    35,    36,    37,
      -1,    21,    22,    23,    21,    21,    22,    23,    28,    26,
      -1,    28,    28,    11,    34,    35,    36,    37,    34,    35,
      36,    37,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    12,    13,    -1,    -1,    -1,    34,    35,    36,    37,
      21,    22,    23,     4,     5,    -1,    -1,    28,     9,    10,
      -1,    12,    13,    34,    35,    36,    37,     4,     5,    -1,
      21,    -1,     9,    10,    -1,     4,     5,    28,    -1,    -1,
       9,    10,    -1,    -1,    21,    -1,    -1,    -1,    25,     4,
       5,    28,    21,    -1,     9,    10,    25,     4,     5,    28,
      -1,    -1,     9,    10,    -1,    -1,    21,    11,    12,    13,
      -1,    26,    -1,    28,    21,    -1,    -1,    21,    22,    23,
      -1,    28,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      -1,    35,    -1,    -1,    -1,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     0,     1,     4,     5,     7,     9,    10,    12,    13,
      21,    25,    26,    28,    40,    41,    42,    45,    48,    56,
      57,    58,    59,    62,    68,    69,    73,    75,    78,    99,
      27,    11,    21,    22,    23,    28,    34,    35,    36,    37,
      69,    73,    84,    85,    86,    88,    90,    91,    92,    94,
      95,    97,    98,    99,    25,    57,    76,    76,    80,    28,
      84,    28,    25,    28,     1,    25,    42,    43,    44,    45,
      57,    78,    48,     0,    41,     1,    21,    28,    46,    99,
       1,    27,     1,    27,     1,    19,    30,    31,    38,    63,
      28,    88,    86,     1,    90,     1,    22,    23,    69,    73,
      99,     1,    93,    94,    95,     1,    93,     1,    16,    17,
      18,    20,    32,    33,    87,     1,    76,     1,    29,    34,
      35,    89,    36,    37,    36,    37,    57,    77,     6,     8,
      79,     8,    84,     1,    27,    29,     1,    24,    84,    43,
       1,    70,    72,    84,    27,    43,     0,    26,    44,    21,
      27,    28,    14,    21,    48,    49,    51,    52,     1,    27,
      30,    47,    21,    27,    99,    84,    99,    21,     1,    11,
      27,    35,    82,    96,    97,    98,    88,     1,    29,     1,
      29,    84,     5,     6,    27,     1,     5,     6,     1,    90,
       1,    90,    91,     1,    93,     1,    93,     1,    93,     1,
      93,     1,    26,    57,    27,    85,    81,    85,    81,     1,
      27,    29,    27,    60,    29,    29,     0,    26,    29,    29,
      30,    71,     1,    15,     0,    26,    29,    49,     1,    21,
      29,    30,    50,     1,    21,    48,     1,    99,    99,    64,
       1,    27,     1,    63,    28,    96,    66,     1,    29,     6,
      27,    27,     1,    76,     1,    27,    27,     1,    27,     1,
      27,     1,    27,    29,    61,     1,    27,     1,    27,    72,
      72,    21,    25,    77,    29,    25,    53,    51,    51,     1,
      21,     1,    63,    65,    82,    82,    96,     1,    29,     1,
      27,    30,    67,    27,     6,    27,     1,     6,     1,    27,
      77,    26,    28,    53,    45,    54,    55,    57,     1,    27,
      27,    82,    30,    30,     1,    29,    82,    82,    27,     1,
      27,    26,    28,    28,    11,    74,    82,    83,    99,     1,
      27,     1,    26,    55,     1,    30,    28,    74,    74,    28,
      99,    29,    74,    29,    29,    99,     1,    29,    29,     1,
      29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    42,    42,    43,    43,    44,    44,    44,
      44,    44,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    46,    46,    47,    46,    46,    48,    48,    49,    49,
      50,    49,    51,    51,    51,    51,    51,    51,    51,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    57,    57,    57,    57,
      58,    58,    59,    59,    59,    59,    60,    59,    61,    61,
      62,    62,    62,    62,    62,    63,    63,    63,    64,    63,
      63,    65,    65,    65,    66,    66,    67,    66,    68,    68,
      68,    68,    69,    69,    70,    70,    71,    70,    72,    72,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    77,    77,    78,    78,    79,    78,    80,    78,
      81,    81,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    86,    86,    87,    87,    87,    87,    87,    87,    88,
      88,    88,    89,    88,    88,    88,    88,    88,    90,    90,
      91,    91,    91,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    97,    97,
      98,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     1,     2,     4,     4,     1,     2,     1,     1,     1,
       1,     3,     3,     2,     3,     3,     3,     7,     6,     7,
       6,     1,     3,     0,     3,     3,     1,     1,     1,     3,
       0,     3,     2,     2,     1,     3,     3,     2,     2,     1,
       3,     3,     1,     2,     1,     1,     5,     5,     4,     3,
       3,     4,     4,     3,     1,     1,     1,     1,     1,     1,
       4,     4,     5,     5,     5,     5,     0,     5,     2,     2,
       5,     5,     3,     3,     3,     1,     5,     5,     0,     4,
       4,     3,     3,     2,     0,     3,     0,     3,     2,     2,
       2,     2,     4,     4,     1,     3,     0,     3,     3,     2,
      10,     9,     9,     8,     1,     1,     5,     5,     7,     7,
       4,     6,     5,     4,     6,     5,     7,     6,     4,     3,
       4,     1,     1,     2,     5,     5,     0,     4,     0,     4,
       2,     2,     1,     4,     4,     3,     3,     1,     4,     4,
       3,     3,     1,     4,     4,     3,     3,     3,     3,     2,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     0,     3,     3,     3,     2,     2,     1,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       2,     1,     3
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
#line 66 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1522 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 70 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1530 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 7: /* global_statement: control_stmt  */
#line 74 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1538 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 9: /* global_statement: '{' program_statements '}'  */
#line 79 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
    }
#line 1546 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '{' program_statements $end  */
#line 83 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1555 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: '}'  */
#line 88 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1563 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* global_statement: error ';'  */
#line 92 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1572 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* program: IDENTIFIER '{' program_statements '}'  */
#line 100 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PROGRAM");
    }
#line 1580 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* program: IDENTIFIER '{' program_statements $end  */
#line 104 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1588 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statement: program  */
#line 119 "include/syntax-analyzer/components/yacc.y"
    {
       announceSpecificError(INVALID_PROGRAM_NESTING);
    }
#line 1596 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statement: '{' program_statements '}'  */
#line 123 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1604 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: '{' program_statements $end  */
#line 127 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1613 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* program_statement: error ';'  */
#line 132 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1621 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* declarative_stmt: type variable_list ';'  */
#line 141 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("VARIABLE DECLARATION");
    }
#line 1629 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* declarative_stmt: type error ';'  */
#line 145 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1638 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* declarative_stmt: type variable_list error  */
#line 150 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1647 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body ';'  */
#line 155 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION DECLARATION");
    }
#line 1655 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* declarative_stmt: type '(' formal_parameter_list ')' function_body ';'  */
#line 159 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_FUNCTION_NAME);
    }
#line 1663 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body error  */
#line 163 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1672 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* declarative_stmt: type '(' formal_parameter_list ')' function_body error  */
#line 168 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1681 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 33: /* $@1: %empty  */
#line 180 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1689 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 35: /* variable_list: variable_list ',' error  */
#line 184 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1698 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* type: FLOAT  */
#line 193 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1706 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* $@2: %empty  */
#line 204 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1714 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* formal_parameter: type error  */
#line 212 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1723 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 44: /* formal_parameter: IDENTIFIER  */
#line 217 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    }
#line 1731 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* formal_parameter: parameter_semantics type error  */
#line 222 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1740 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* formal_parameter: parameter_semantics error  */
#line 227 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;
    }
#line 1750 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 48: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 233 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    }
#line 1758 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 51: /* function_body: '{' function_statements error  */
#line 245 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 1767 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* return: RETURN '(' opt_trunc_expression ')' error  */
#line 264 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1776 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* return: RETURN '(' opt_trunc_expression error  */
#line 269 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1786 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* return: RETURN opt_trunc_expression ')'  */
#line 275 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
    }
#line 1795 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* return: RETURN opt_trunc_expression error  */
#line 280 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1805 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* return: RETURN '(' opt_trunc_expression ';'  */
#line 286 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_PARENTHESIS);
    }
#line 1813 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* return: RETURN opt_trunc_expression ')' ';'  */
#line 290 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 1821 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* return: RETURN opt_trunc_expression ';'  */
#line 294 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);
    }
#line 1829 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* assignment: variable ASSIGN_OP opt_trunc_expression ';'  */
#line 312 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("ASSIGNMENT");
    }
#line 1837 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* assignment: variable ASSIGN_OP opt_trunc_expression error  */
#line 316 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1846 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* print: PRINT '(' STRING_LITERAL ')' ';'  */
#line 324 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1854 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 73: /* print: PRINT '(' STRING_LITERAL ')' error  */
#line 328 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1863 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 74: /* print: PRINT '(' opt_trunc_expression ')' ';'  */
#line 333 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1871 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* print: PRINT '(' opt_trunc_expression ')' error  */
#line 337 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1880 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* $@3: %empty  */
#line 342 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 1889 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 79: /* print_end: ')' error  */
#line 352 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1898 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 80: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 363 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("MULTIPLE ASSIGNMENT");
    }
#line 1906 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 367 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1915 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 82: /* multiple_assignments: variable assignment_list ';'  */
#line 372 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_RIGHT_SIDE_VALUES);
    }
#line 1923 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* multiple_assignments: variable assignment_list error  */
#line 376 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1933 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 84: /* multiple_assignments: variable error ';'  */
#line 382 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxWarning(STATEMENT_INTERPRETED);
        announceSyntaxError();
        yyerrok;
    }
#line 1943 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 393 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_EQUALS);
    }
#line 1951 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 88: /* $@4: %empty  */
#line 397 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 1960 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 402 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1968 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 92: /* assignment_list_end: assignment_list opt_trunc_constant error  */
#line 410 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 1977 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 93: /* assignment_list_end: error ';'  */
#line 415 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1985 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* $@5: %empty  */
#line 424 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1993 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 99: /* invocation: function_invocation error  */
#line 434 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2002 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* invocation: lambda_invocation error  */
#line 440 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2011 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* function_invocation: IDENTIFIER '(' real_parameter_list ')'  */
#line 448 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION INVOCATION");
    }
#line 2019 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 103: /* function_invocation: IDENTIFIER '(' error ')'  */
#line 452 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 2028 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 106: /* $@6: %empty  */
#line 462 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 2036 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* real_parameter: opt_trunc_expression error  */
#line 470 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2045 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 480 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("LAMBDA");
    }
#line 2053 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 484 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 2061 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 112: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '(' lambda_real_parameter ')'  */
#line 488 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 2069 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 113: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '(' lambda_real_parameter ')'  */
#line 492 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_BRACKETS);
    }
#line 2077 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 116: /* if: IF condition executable_body ENDIF ';'  */
#line 506 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF");
    }
#line 2085 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 117: /* if: IF condition executable_body ENDIF error  */
#line 510 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2094 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 118: /* if: IF condition executable_body ELSE executable_body ENDIF ';'  */
#line 515 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF-ELSE");
    }
#line 2102 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* if: IF condition executable_body ELSE executable_body ENDIF error  */
#line 519 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2111 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* if: IF condition executable_body error  */
#line 524 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2120 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 121: /* if: IF condition executable_body ELSE executable_body error  */
#line 529 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2129 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* if: IF condition error ENDIF ';'  */
#line 534 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2138 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* if: IF condition error ';'  */
#line 539 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2148 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 124: /* if: IF condition error ELSE ENDIF ';'  */
#line 545 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2157 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 125: /* if: IF condition error ELSE ';'  */
#line 550 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2167 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* if: IF condition executable_body ELSE error ENDIF ';'  */
#line 556 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2176 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* if: IF condition executable_body ELSE error ';'  */
#line 561 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2186 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* if: ELSE executable_body ENDIF ';'  */
#line 567 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;
    }
#line 2195 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* executable_body: '{' executable_statements error ';'  */
#line 576 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 2204 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 134: /* control_stmt: DO executable_body WHILE condition ';'  */
#line 592 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("DO-WHILE");
    }
#line 2212 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 135: /* control_stmt: DO executable_body WHILE condition error  */
#line 596 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2221 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 136: /* $@7: %empty  */
#line 601 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE);
    }
#line 2229 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* $@8: %empty  */
#line 606 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
    }
#line 2237 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* end_while_statement: condition error  */
#line 615 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2246 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* opt_trunc_constant: TRUNC '(' numeric_constant error  */
#line 627 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2255 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* opt_trunc_constant: TRUNC numeric_constant ')'  */
#line 632 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2263 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 146: /* opt_trunc_constant: TRUNC numeric_constant error  */
#line 636 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2272 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* opt_trunc_variable: TRUNC '(' variable error  */
#line 646 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2281 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 150: /* opt_trunc_variable: TRUNC variable ')'  */
#line 651 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2289 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* opt_trunc_variable: TRUNC variable error  */
#line 655 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2298 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 154: /* opt_trunc_expression: TRUNC '(' expression error  */
#line 665 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2307 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 155: /* opt_trunc_expression: TRUNC expression ')'  */
#line 670 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2315 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* opt_trunc_expression: TRUNC expression error  */
#line 674 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2324 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* condition: '(' comparison error  */
#line 685 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2333 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 159: /* condition: comparison ')'  */
#line 690 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2341 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* condition: comparison error  */
#line 694 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    }
#line 2350 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 162: /* comparison: opt_trunc_expression error  */
#line 703 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;
    }
#line 2359 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* $@9: %empty  */
#line 723 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 2367 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* expression: expression '+' error  */
#line 727 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2376 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* expression: expression '-' error  */
#line 732 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2385 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 176: /* expression: '+' term  */
#line 737 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUM_OPERAND);
    }
#line 2393 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* expression: '+' error  */
#line 741 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;
    }
#line 2402 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* positive_term: positive_term '*' error  */
#line 757 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2411 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* positive_term: positive_term '/' error  */
#line 762 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2420 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 188: /* negative_term: negative_term '*' error  */
#line 773 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2429 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 189: /* negative_term: negative_term '/' error  */
#line 778 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2438 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* negative_term: '*' factor  */
#line 783 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_MUL_FACTOR);
    }
#line 2446 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* negative_term: '/' factor  */
#line 787 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_DIV_FACTOR);
    }
#line 2454 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* negative_term: '*' error  */
#line 791 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2463 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* negative_term: '/' error  */
#line 796 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2472 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 201: /* negative_factor: '-' UINTEGER_LITERAL  */
#line 817 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2480 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 202: /* negative_factor: '-' function_invocation  */
#line 821 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2488 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 203: /* negative_factor: '-' variable  */
#line 825 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2496 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 204: /* negative_factor: '-' lambda_invocation  */
#line 829 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2504 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 205: /* negative_factor: '-' error  */
#line 833 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_FLOAT_CONSTANT);
        yyerrok;
    }
#line 2513 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* negative_constant: '-' FLOAT_LITERAL  */
#line 851 "include/syntax-analyzer/components/yacc.y"
    {
        addNegativeFloatToTable();
    }
#line 2521 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 2525 "src/syntax-analyzer/components/parser.cpp"

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

#line 861 "include/syntax-analyzer/components/yacc.y"


void yyerror(const char* s)
{
    announceSyntaxError();
}
