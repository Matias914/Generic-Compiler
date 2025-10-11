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
  YYSYMBOL_multiple_assignments = 60,      /* multiple_assignments  */
  YYSYMBOL_assignment_list = 61,           /* assignment_list  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_extra_numeric_constants = 63,   /* extra_numeric_constants  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_invocation = 65,                /* invocation  */
  YYSYMBOL_function_invocation = 66,       /* function_invocation  */
  YYSYMBOL_real_parameter_list = 67,       /* real_parameter_list  */
  YYSYMBOL_68_5 = 68,                      /* $@5  */
  YYSYMBOL_real_parameter = 69,            /* real_parameter  */
  YYSYMBOL_lambda_invocation = 70,         /* lambda_invocation  */
  YYSYMBOL_lambda_real_parameter = 71,     /* lambda_real_parameter  */
  YYSYMBOL_if = 72,                        /* if  */
  YYSYMBOL_executable_body = 73,           /* executable_body  */
  YYSYMBOL_executable_statements = 74,     /* executable_statements  */
  YYSYMBOL_control_stmt = 75,              /* control_stmt  */
  YYSYMBOL_opt_trunc_constant = 76,        /* opt_trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 77,        /* opt_trunc_variable  */
  YYSYMBOL_opt_trunc_expression = 78,      /* opt_trunc_expression  */
  YYSYMBOL_condition = 79,                 /* condition  */
  YYSYMBOL_comparison = 80,                /* comparison  */
  YYSYMBOL_comparison_operator = 81,       /* comparison_operator  */
  YYSYMBOL_expression = 82,                /* expression  */
  YYSYMBOL_83_6 = 83,                      /* $@6  */
  YYSYMBOL_term = 84,                      /* term  */
  YYSYMBOL_positive_term = 85,             /* positive_term  */
  YYSYMBOL_negative_term = 86,             /* negative_term  */
  YYSYMBOL_factor = 87,                    /* factor  */
  YYSYMBOL_positive_factor = 88,           /* positive_factor  */
  YYSYMBOL_negative_factor = 89,           /* negative_factor  */
  YYSYMBOL_numeric_constant = 90,          /* numeric_constant  */
  YYSYMBOL_positive_constant = 91,         /* positive_constant  */
  YYSYMBOL_negative_constant = 92,         /* negative_constant  */
  YYSYMBOL_variable = 93                   /* variable  */
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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   784

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  195
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  329

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
      82,    87,    92,   100,   104,   111,   112,   116,   117,   118,
     119,   123,   127,   132,   141,   145,   150,   155,   159,   163,
     173,   174,   176,   175,   179,   187,   193,   194,   196,   195,
     202,   203,   208,   212,   213,   218,   224,   231,   235,   236,
     244,   245,   249,   250,   254,   255,   260,   270,   271,   272,
     273,   274,   275,   279,   283,   291,   295,   300,   304,   309,
     313,   325,   329,   334,   341,   342,   344,   343,   348,   354,
     356,   358,   357,   366,   367,   372,   373,   381,   385,   393,
     394,   396,   395,   402,   403,   413,   417,   421,   425,   432,
     433,   439,   443,   448,   452,   457,   462,   467,   472,   478,
     483,   489,   494,   500,   508,   509,   514,   518,   519,   525,
     529,   534,   538,   544,   548,   559,   560,   561,   566,   570,
     578,   579,   580,   585,   589,   597,   598,   599,   604,   608,
     618,   619,   624,   628,   636,   637,   645,   646,   647,   648,
     649,   650,   654,   655,   656,   658,   657,   661,   666,   671,
     675,   683,   684,   688,   689,   690,   691,   696,   704,   705,
     706,   707,   712,   717,   721,   725,   730,   738,   739,   743,
     744,   745,   749,   750,   751,   755,   759,   763,   767,   778,
     779,   783,   784,   788,   795,   796
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
  "multiple_assignments", "assignment_list", "$@3",
  "extra_numeric_constants", "$@4", "invocation", "function_invocation",
  "real_parameter_list", "$@5", "real_parameter", "lambda_invocation",
  "lambda_real_parameter", "if", "executable_body",
  "executable_statements", "control_stmt", "opt_trunc_constant",
  "opt_trunc_variable", "opt_trunc_expression", "condition", "comparison",
  "comparison_operator", "expression", "$@6", "term", "positive_term",
  "negative_term", "factor", "positive_factor", "negative_factor",
  "numeric_constant", "positive_constant", "negative_constant", "variable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-206)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-156)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     467,  -206,    13,   677,   746,   717,    60,    96,  -206,   237,
     593,  -206,    36,   496,  -206,  -206,  -206,    50,  -206,  -206,
    -206,  -206,  -206,  -206,    82,   122,  -206,  -206,   147,  -206,
     407,   100,  -206,  -206,   659,   171,   222,   371,   380,  -206,
    -206,   437,   625,    27,   321,  -206,   109,   151,  -206,  -206,
    -206,  -206,   101,   568,  -206,   163,   677,   428,   695,   655,
     593,   258,   126,   593,  -206,   525,  -206,  -206,  -206,  -206,
     160,  -206,  -206,   183,   170,   349,   106,   101,  -206,  -206,
    -206,  -206,   232,   695,   232,  -206,   261,   351,   712,   182,
      68,  -206,  -206,  -206,  -206,  -206,  -206,  -206,   101,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,   695,   292,   522,  -206,  -206,   313,   330,    11,
     388,   396,   399,   424,  -206,   481,   195,   125,   677,   157,
     113,   206,   185,   242,   554,   267,   300,  -206,    20,  -206,
     583,  -206,  -206,  -206,   286,  -206,   349,  -206,  -206,    17,
     317,  -206,   217,  -206,  -206,   136,   232,  -206,   101,   201,
      73,  -206,   438,  -206,   337,  -206,  -206,  -206,  -206,   303,
    -206,  -206,  -206,  -206,  -206,    48,   312,  -206,  -206,   647,
     214,  -206,  -206,  -206,  -206,   109,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,   350,  -206,  -206,  -206,  -206,  -206,
     219,  -206,  -206,  -206,   220,   231,  -206,  -206,   248,  -206,
    -206,  -206,  -206,   695,   695,  -206,   358,  -206,  -206,   748,
     355,  -206,  -206,   357,   349,   349,  -206,  -206,   233,  -206,
     101,   101,    75,  -206,  -206,   476,     2,   114,   353,  -206,
    -206,   360,  -206,  -206,   262,   306,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
     568,   510,   357,   756,   363,  -206,  -206,  -206,  -206,  -206,
     365,   118,  -206,  -206,  -206,  -206,   476,   476,  -206,   405,
    -206,  -206,   250,   539,   370,   288,   251,  -206,   615,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
     379,   288,   638,   610,   404,  -206,  -206,   101,  -206,  -206,
     410,  -206,  -206,   638,   411,   419,   391,    14,  -206,  -206,
     429,  -206,  -206,    30,  -206,  -206,  -206,  -206,  -206
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,     0,     0,     0,    35,   194,
       0,    11,     0,     0,     2,     8,     5,     0,    62,     6,
      57,    61,    58,    59,     0,     0,    60,     7,     0,    12,
       0,   194,   192,   191,     0,     0,     0,     0,     0,   181,
     183,     0,     0,     0,   135,   154,   161,   162,   165,   170,
     180,   182,   179,     0,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,    15,    17,    18,    19,
       0,     1,     3,     0,   194,     0,     0,    30,    84,    83,
      86,    85,     0,     0,     0,    74,     0,     0,     0,     0,
       0,   160,   159,   188,   193,   184,   185,   187,   186,   175,
     173,   177,   178,   176,   174,   145,   146,   148,   149,   147,
     150,   151,     0,     0,     0,   143,   142,     0,     0,     0,
       0,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    89,     0,    23,
       0,    10,     9,    16,     0,    25,     0,    47,    42,     0,
      38,    36,     0,    26,    24,     0,     0,   194,    76,     0,
       0,   195,     0,    73,     0,    79,   125,   189,   190,     0,
     139,   138,   141,   140,   144,     0,     0,   108,   105,     0,
       0,   157,   152,   158,   153,   156,   166,   163,   167,   164,
     171,   168,   172,   169,     0,   114,   118,   113,   124,   123,
       0,   122,   121,    56,     0,     0,    70,    69,     0,    14,
      13,    88,    87,     0,     0,    94,     0,    22,    21,     0,
      38,    41,    40,     0,     0,     0,    45,    46,     0,    34,
      31,    33,     0,    64,    63,     0,     0,     0,     0,   137,
     136,     0,   110,   107,     0,     0,   102,   101,   115,   120,
     119,    55,    54,    66,    65,    68,    67,    90,    92,    93,
       0,     0,     0,     0,     0,    37,    39,    44,    43,    77,
      78,     0,   129,   128,    72,    71,     0,     0,   109,     0,
     112,   106,     0,     0,     0,     0,     0,    52,     0,    50,
      53,    28,    75,   127,   126,    80,    82,   111,   104,   103,
       0,     0,     0,     0,     0,   100,    99,   130,    29,    27,
       0,    48,    51,     0,     0,     0,     0,     0,    98,    49,
       0,    97,    96,     0,   134,   133,    95,   132,   131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,   462,    72,   297,   -38,     3,  -206,  -206,   -11,
     332,  -206,    97,  -206,   218,  -206,   193,  -206,    45,  -206,
    -206,  -206,  -151,  -206,  -206,  -206,  -206,    57,  -206,  -206,
     191,   108,   -29,  -206,    -3,  -205,   138,   -81,  -206,   -39,
     -27,   449,  -206,   -22,  -206,   -23,   375,  -206,   -31,     9,
      42,  -136,   -76,   -46,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    13,    14,    64,    65,    66,    67,    76,   156,    17,
     150,   225,   151,   152,   264,   288,   289,    18,    68,    20,
      21,    22,    87,   232,   238,   277,    23,    39,   136,   214,
     137,    40,   304,    26,    55,   125,    69,   305,   306,    41,
      42,    43,   112,    44,   119,    45,    46,    47,   100,    48,
      49,   166,    50,    51,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    70,    57,    16,    28,    28,   165,   104,    89,   235,
      28,   167,    92,    28,   261,   324,    16,    77,   221,   130,
     133,   215,   138,    70,    32,    33,   237,   143,   115,   127,
     129,   327,    31,    32,    33,   216,    98,   164,   222,   114,
      29,   168,    28,   325,   159,    19,   101,   101,     8,    54,
      54,    73,    86,    28,   241,   283,   116,    24,    19,   328,
      28,    24,    24,    28,   149,    28,   169,    24,    86,   172,
      24,    74,    15,   174,    82,   242,    82,    70,    75,   102,
     102,   269,   158,    78,   160,    15,   167,    54,    58,   187,
     189,   191,   193,    96,   182,   184,   143,   173,   124,    24,
     271,   200,   143,    84,    85,    84,    85,   153,    25,    79,
      24,    86,    25,    25,   203,   272,   168,    24,    25,   293,
      24,    25,    24,    80,    59,    28,   198,   -32,    61,   101,
     101,   101,   101,   154,    28,   149,   155,   229,    27,    86,
      28,   228,   204,   273,    97,   120,   121,   294,    82,    81,
      25,    27,   199,   139,   270,   230,   231,   157,   201,   167,
     167,    25,   102,   102,   102,   102,    83,   237,    25,   126,
     196,    25,    91,    25,   138,   138,   245,    84,    85,    28,
     271,   144,    24,   170,   202,    86,   206,   122,   123,   168,
     168,    24,    31,    32,    33,   295,   296,    24,   146,    12,
     167,   167,   233,  -155,  -155,  -155,    36,    37,    38,   167,
     145,   171,   207,   149,   149,   246,   117,   118,   226,    28,
     249,   251,   197,    93,    54,   167,   167,   167,   234,     8,
     168,   168,   253,    25,   267,   205,    24,   167,   227,   168,
     167,   247,    25,    31,    94,    95,   250,   252,    25,   255,
      12,   298,   308,   157,   268,   168,   168,   168,   254,   135,
      28,    28,    60,    28,   124,    61,   287,   168,   279,    30,
     168,   208,   314,   315,    70,   256,    24,   299,   309,    31,
      32,    33,   161,    28,   320,   307,    12,    25,    28,   280,
      70,   287,    35,    36,    37,    38,   211,   175,   176,   303,
       8,   307,   307,   317,   239,   124,   196,   281,   290,   157,
      32,    33,   282,   307,   181,   219,   323,    24,    24,   177,
      24,   265,   266,   164,  -155,  -155,  -155,    25,   196,   212,
     213,   183,   240,   290,    31,    32,    33,   117,   118,   243,
      24,    12,  -155,  -155,  -155,    24,   223,   224,    36,    37,
      38,    31,    32,    33,   274,   117,   118,   134,    12,    94,
     140,     8,   162,   147,   -81,    36,    37,    38,    25,    25,
     148,    25,    99,    32,    33,   -81,   -81,   248,   163,   259,
     275,   103,   263,   276,   262,   224,   164,   278,   -81,   186,
     291,    25,    31,    32,    33,   292,    25,   188,   302,    12,
     190,    31,    32,    33,   257,   258,    36,   313,    12,    31,
      32,    33,   157,    32,    33,    36,    12,    31,    32,    33,
      31,    32,    33,    36,    12,   192,   164,    12,    31,    32,
      33,    36,   297,   318,    36,    88,   128,   319,   105,    30,
     321,    35,    36,    37,    38,    31,    32,    33,   322,    31,
      32,    33,    12,   106,   107,   108,    34,   109,   326,    36,
      32,    33,    35,    36,    37,    38,   236,     1,     2,   110,
     111,     3,     4,   164,     5,    72,     6,     7,   220,     8,
     286,   312,   194,    90,     0,     3,     4,   162,     9,     0,
       6,     7,    10,    11,   185,    12,    71,     2,    32,    33,
       3,     4,    31,     5,     0,     6,     7,   195,     8,    12,
       0,   164,     0,     0,     3,     4,     0,     9,     0,     6,
       7,    10,    11,   178,    12,   141,    62,   179,   180,     3,
       4,    31,     5,     0,     6,     7,   284,     8,   285,     0,
       0,     0,     0,     3,     4,     0,     9,     0,     6,     7,
      63,   142,     0,    12,   209,    62,     0,     0,     3,     4,
      31,     5,     0,     6,     7,   300,     8,   301,     0,     0,
       0,     0,     3,     4,     0,     9,     0,     6,     7,    63,
     210,     0,    12,   217,    62,     0,     0,     3,     4,    31,
       5,     0,     6,     7,    62,     8,    12,     3,     4,     0,
       5,     0,     6,     7,     9,     8,     0,     0,    63,   218,
       0,    12,     0,     0,     9,     0,   310,     0,    63,     3,
       4,    12,     0,     0,     6,     7,   113,     8,     0,     3,
       4,   157,    32,    33,     6,     7,    31,     0,   316,     0,
       0,   311,     0,    12,     0,   164,    31,     0,   244,   303,
      53,     3,     4,    12,     0,     0,     6,     7,     0,   157,
      32,    33,     0,     0,     0,     0,    30,     0,    31,     0,
      30,     8,    53,   164,     0,    12,    31,    32,    33,   131,
      31,    32,    33,    12,   132,     0,     0,    12,    30,    35,
      36,    37,    38,    35,    36,    37,    38,     0,    31,    32,
      33,     0,     0,     0,     0,    34,    30,     0,     0,     0,
       0,    35,    36,    37,    38,     0,    31,    32,    33,     0,
       0,     3,     4,    12,     8,    56,     6,     7,     0,    35,
      36,    37,    38,    31,    32,    33,     0,     0,    31,     0,
      12,     0,    53,     0,     0,    12,    35,    36,    37,    38,
       3,     4,     3,     4,     0,     6,     7,     6,     7,     0,
       3,     4,     0,     0,     0,     6,     7,    31,     8,    31,
       0,    53,     0,   260,    12,     0,    12,    31,     0,     0,
       0,     0,     0,     0,    12
};

static const yytype_int16 yycheck[] =
{
       0,    12,     5,     0,     4,     5,    87,    38,    30,   160,
      10,    87,    35,    13,   219,     1,    13,    17,     1,    58,
      59,     1,    61,    34,    22,    23,   162,    65,     1,    56,
      57,     1,    21,    22,    23,    15,    36,    35,    21,    42,
      27,    87,    42,    29,    83,     0,    37,    38,    12,     4,
       5,     1,    38,    53,     6,   260,    29,     0,    13,    29,
      60,     4,     5,    63,    75,    65,    88,    10,    38,     1,
      13,    21,     0,   112,     1,    27,     1,    88,    28,    37,
      38,   232,    82,     1,    84,    13,   162,    42,    28,   120,
     121,   122,   123,    36,   117,   118,   134,    29,    53,    42,
     236,   128,   140,    30,    31,    30,    31,     1,     0,    27,
      53,    38,     4,     5,     1,     1,   162,    60,    10,     1,
      63,    13,    65,     1,    28,   125,     1,    21,    28,   120,
     121,   122,   123,    27,   134,   146,    30,     1,     0,    38,
     140,   152,    29,    29,    36,    36,    37,    29,     1,    27,
      42,    13,    27,    27,   235,   155,   156,    21,     1,   235,
     236,    53,   120,   121,   122,   123,    19,   303,    60,     6,
     125,    63,     1,    65,   213,   214,   179,    30,    31,   179,
     316,    21,   125,     1,    27,    38,     1,    36,    37,   235,
     236,   134,    21,    22,    23,   276,   277,   140,    28,    28,
     276,   277,     1,    21,    22,    23,    35,    36,    37,   285,
      27,    29,    27,   224,   225,     1,    34,    35,     1,   219,
       1,     1,    27,     1,   179,   301,   302,   303,    27,    12,
     276,   277,     1,   125,     1,    29,   179,   313,    21,   285,
     316,    27,   134,    21,    22,    23,    27,    27,   140,     1,
      28,     1,     1,    21,    21,   301,   302,   303,    27,     1,
     260,   261,    25,   263,   219,    28,   263,   313,     6,    11,
     316,    29,   301,   302,   285,    27,   219,    27,    27,    21,
      22,    23,    21,   283,   313,   285,    28,   179,   288,    27,
     301,   288,    34,    35,    36,    37,    29,     5,     6,    11,
      12,   301,   302,   303,     1,   260,   261,     1,   263,    21,
      22,    23,     6,   313,     1,    29,   316,   260,   261,    27,
     263,   224,   225,    35,    21,    22,    23,   219,   283,    29,
      30,     1,    29,   288,    21,    22,    23,    34,    35,    27,
     283,    28,    21,    22,    23,   288,    29,    30,    35,    36,
      37,    21,    22,    23,     1,    34,    35,    60,    28,    22,
      63,    12,    11,    14,    11,    35,    36,    37,   260,   261,
      21,   263,     1,    22,    23,    22,    23,    27,    27,    21,
      27,     1,    25,    30,    29,    30,    35,    27,    35,     1,
      27,   283,    21,    22,    23,    30,   288,     1,    28,    28,
       1,    21,    22,    23,   213,   214,    35,    28,    28,    21,
      22,    23,    21,    22,    23,    35,    28,    21,    22,    23,
      21,    22,    23,    35,    28,     1,    35,    28,    21,    22,
      23,    35,    27,    29,    35,    28,     8,    27,     1,    11,
      29,    34,    35,    36,    37,    21,    22,    23,    29,    21,
      22,    23,    28,    16,    17,    18,    28,    20,    29,    35,
      22,    23,    34,    35,    36,    37,    28,     0,     1,    32,
      33,     4,     5,    35,     7,    13,     9,    10,   146,    12,
     262,   288,     1,    34,    -1,     4,     5,    11,    21,    -1,
       9,    10,    25,    26,   119,    28,     0,     1,    22,    23,
       4,     5,    21,     7,    -1,     9,    10,    26,    12,    28,
      -1,    35,    -1,    -1,     4,     5,    -1,    21,    -1,     9,
      10,    25,    26,     1,    28,     0,     1,     5,     6,     4,
       5,    21,     7,    -1,     9,    10,    26,    12,    28,    -1,
      -1,    -1,    -1,     4,     5,    -1,    21,    -1,     9,    10,
      25,    26,    -1,    28,     0,     1,    -1,    -1,     4,     5,
      21,     7,    -1,     9,    10,    26,    12,    28,    -1,    -1,
      -1,    -1,     4,     5,    -1,    21,    -1,     9,    10,    25,
      26,    -1,    28,     0,     1,    -1,    -1,     4,     5,    21,
       7,    -1,     9,    10,     1,    12,    28,     4,     5,    -1,
       7,    -1,     9,    10,    21,    12,    -1,    -1,    25,    26,
      -1,    28,    -1,    -1,    21,    -1,     1,    -1,    25,     4,
       5,    28,    -1,    -1,     9,    10,     1,    12,    -1,     4,
       5,    21,    22,    23,     9,    10,    21,    -1,    28,    -1,
      -1,    26,    -1,    28,    -1,    35,    21,    -1,     1,    11,
      25,     4,     5,    28,    -1,    -1,     9,    10,    -1,    21,
      22,    23,    -1,    -1,    -1,    -1,    11,    -1,    21,    -1,
      11,    12,    25,    35,    -1,    28,    21,    22,    23,    24,
      21,    22,    23,    28,    29,    -1,    -1,    28,    11,    34,
      35,    36,    37,    34,    35,    36,    37,    -1,    21,    22,
      23,    -1,    -1,    -1,    -1,    28,    11,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    -1,    21,    22,    23,    -1,
      -1,     4,     5,    28,    12,     8,     9,    10,    -1,    34,
      35,    36,    37,    21,    22,    23,    -1,    -1,    21,    -1,
      28,    -1,    25,    -1,    -1,    28,    34,    35,    36,    37,
       4,     5,     4,     5,    -1,     9,    10,     9,    10,    -1,
       4,     5,    -1,    -1,    -1,     9,    10,    21,    12,    21,
      -1,    25,    -1,    25,    28,    -1,    28,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     0,     1,     4,     5,     7,     9,    10,    12,    21,
      25,    26,    28,    40,    41,    42,    45,    48,    56,    57,
      58,    59,    60,    65,    66,    70,    72,    75,    93,    27,
      11,    21,    22,    23,    28,    34,    35,    36,    37,    66,
      70,    78,    79,    80,    82,    84,    85,    86,    88,    89,
      91,    92,    93,    25,    57,    73,     8,    73,    28,    28,
      25,    28,     1,    25,    42,    43,    44,    45,    57,    75,
      48,     0,    41,     1,    21,    28,    46,    93,     1,    27,
       1,    27,     1,    19,    30,    31,    38,    61,    28,    82,
      80,     1,    84,     1,    22,    23,    66,    70,    93,     1,
      87,    88,    89,     1,    87,     1,    16,    17,    18,    20,
      32,    33,    81,     1,    73,     1,    29,    34,    35,    83,
      36,    37,    36,    37,    57,    74,     6,    79,     8,    79,
      78,    24,    29,    78,    43,     1,    67,    69,    78,    27,
      43,     0,    26,    44,    21,    27,    28,    14,    21,    48,
      49,    51,    52,     1,    27,    30,    47,    21,    93,    78,
      93,    21,    11,    27,    35,    76,    90,    91,    92,    82,
       1,    29,     1,    29,    78,     5,     6,    27,     1,     5,
       6,     1,    84,     1,    84,    85,     1,    87,     1,    87,
       1,    87,     1,    87,     1,    26,    57,    27,     1,    27,
      79,     1,    27,     1,    29,    29,     1,    27,    29,     0,
      26,    29,    29,    30,    68,     1,    15,     0,    26,    29,
      49,     1,    21,    29,    30,    50,     1,    21,    48,     1,
      93,    93,    62,     1,    27,    61,    28,    90,    63,     1,
      29,     6,    27,    27,     1,    73,     1,    27,    27,     1,
      27,     1,    27,     1,    27,     1,    27,    69,    69,    21,
      25,    74,    29,    25,    53,    51,    51,     1,    21,    61,
      76,    90,     1,    29,     1,    27,    30,    64,    27,     6,
      27,     1,     6,    74,    26,    28,    53,    45,    54,    55,
      57,    27,    30,     1,    29,    76,    76,    27,     1,    27,
      26,    28,    28,    11,    71,    76,    77,    93,     1,    27,
       1,    26,    55,    28,    71,    71,    28,    93,    29,    27,
      71,    29,    29,    93,     1,    29,    29,     1,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    42,    42,    43,    43,    44,    44,    44,
      44,    44,    44,    44,    45,    45,    45,    45,    45,    45,
      46,    46,    47,    46,    46,    48,    49,    49,    50,    49,
      51,    51,    51,    51,    51,    51,    51,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    56,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    60,    60,    60,    61,    61,    62,    61,    61,    63,
      63,    64,    63,    65,    65,    65,    65,    66,    66,    67,
      67,    68,    67,    69,    69,    70,    70,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    80,    80,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    83,    82,    82,    82,    82,
      82,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    91,    91,    92,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     1,     2,     4,     4,     1,     2,     1,     1,     1,
       1,     3,     3,     2,     3,     3,     3,     7,     6,     7,
       1,     3,     0,     3,     3,     1,     1,     3,     0,     3,
       2,     2,     1,     3,     3,     2,     2,     1,     3,     4,
       1,     2,     1,     1,     5,     5,     4,     1,     1,     1,
       1,     1,     1,     4,     4,     5,     5,     5,     5,     4,
       4,     5,     5,     3,     1,     5,     0,     4,     4,     0,
       3,     0,     3,     2,     2,     2,     2,     4,     4,     1,
       3,     0,     3,     3,     2,    10,     9,     9,     8,     1,
       1,     5,     5,     7,     7,     4,     6,     5,     4,     6,
       5,     7,     6,     4,     3,     4,     1,     1,     2,     5,
       5,     4,     4,     4,     4,     1,     4,     4,     3,     3,
       1,     4,     4,     3,     3,     1,     4,     4,     3,     3,
       3,     3,     2,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     0,     3,     3,     3,     2,
       2,     1,     1,     3,     3,     1,     3,     3,     3,     3,
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
#line 66 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1490 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 70 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1498 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 7: /* global_statement: control_stmt  */
#line 74 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1506 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 9: /* global_statement: '{' program_statements '}'  */
#line 79 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
    }
#line 1514 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '{' program_statements $end  */
#line 83 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1523 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: '}'  */
#line 88 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1532 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* global_statement: error ';'  */
#line 93 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1541 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* program: IDENTIFIER '{' program_statements '}'  */
#line 101 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PROGRAM");
    }
#line 1549 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* program: IDENTIFIER '{' program_statements $end  */
#line 105 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1557 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statement: program  */
#line 120 "include/syntax-analyzer/components/yacc.y"
    {
       announceSpecificError(INVALID_PROGRAM_NESTING);
    }
#line 1565 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statement: '{' program_statements '}'  */
#line 124 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1573 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: '{' program_statements $end  */
#line 128 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1582 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* program_statement: error ';'  */
#line 133 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1590 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* declarative_stmt: type variable_list ';'  */
#line 142 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("VARIABLE DECLARATION");
    }
#line 1598 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* declarative_stmt: type error ';'  */
#line 146 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1607 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* declarative_stmt: type variable_list error  */
#line 151 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1616 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body ';'  */
#line 156 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION DECLARATION");
    }
#line 1624 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* declarative_stmt: type '(' formal_parameter_list ')' function_body ';'  */
#line 160 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_FUNCTION_NAME);
    }
#line 1632 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body error  */
#line 164 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1641 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* $@1: %empty  */
#line 176 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1649 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 34: /* variable_list: variable_list ',' error  */
#line 180 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1658 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 38: /* $@2: %empty  */
#line 196 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1666 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* formal_parameter: type error  */
#line 204 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1675 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* formal_parameter: IDENTIFIER  */
#line 209 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PARAMETER_TYPE);
    }
#line 1683 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 44: /* formal_parameter: parameter_semantics type error  */
#line 214 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1692 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* formal_parameter: parameter_semantics error  */
#line 219 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;
    }
#line 1702 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 225 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PARAMETER_TYPE);
    }
#line 1710 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 49: /* function_body: '{' function_statements error ';'  */
#line 237 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 1719 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* return: RETURN '(' opt_trunc_expression ')' error  */
#line 256 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1728 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 56: /* return: RETURN '(' opt_trunc_expression error  */
#line 261 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 1737 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* assignment: variable ASSIGN_OP opt_trunc_expression ';'  */
#line 280 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("ASSIGNMENT");
    }
#line 1745 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* assignment: variable ASSIGN_OP opt_trunc_expression error  */
#line 284 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1754 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 65: /* print: PRINT '(' STRING_LITERAL ')' ';'  */
#line 292 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1762 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 66: /* print: PRINT '(' STRING_LITERAL ')' error  */
#line 296 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1771 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 67: /* print: PRINT '(' opt_trunc_expression ')' ';'  */
#line 301 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1779 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 68: /* print: PRINT '(' opt_trunc_expression ')' error  */
#line 305 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1788 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 69: /* print: PRINT '(' ')' ';'  */
#line 310 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_ARGUMENT);
    }
#line 1796 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* print: PRINT '(' ')' error  */
#line 314 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_ARGUMENT);
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1806 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 326 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("MULTIPLE ASSIGNMENT");
    }
#line 1814 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 330 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1823 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 73: /* multiple_assignments: variable assignment_list ';'  */
#line 335 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_RIGHT_SIDE_VALUES);
    }
#line 1831 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* $@3: %empty  */
#line 344 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 1840 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 78: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 349 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1848 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* $@4: %empty  */
#line 358 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1856 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 84: /* invocation: function_invocation error  */
#line 368 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1865 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 86: /* invocation: lambda_invocation error  */
#line 374 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1874 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* function_invocation: IDENTIFIER '(' real_parameter_list ')'  */
#line 382 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION INVOCATION");
    }
#line 1882 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 88: /* function_invocation: IDENTIFIER '(' error ')'  */
#line 386 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 1891 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 91: /* $@5: %empty  */
#line 396 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1899 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 94: /* real_parameter: opt_trunc_expression error  */
#line 404 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 1908 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 414 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("LAMBDA");
    }
#line 1916 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 418 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1924 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '(' lambda_real_parameter ')'  */
#line 422 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1932 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 98: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '(' lambda_real_parameter ')'  */
#line 426 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_BRACKETS);
    }
#line 1940 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* if: IF condition executable_body ENDIF ';'  */
#line 440 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF");
    }
#line 1948 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* if: IF condition executable_body ENDIF error  */
#line 444 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1957 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 103: /* if: IF condition executable_body ELSE executable_body ENDIF ';'  */
#line 449 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF-ELSE");
    }
#line 1965 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 104: /* if: IF condition executable_body ELSE executable_body ENDIF error  */
#line 453 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1974 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 105: /* if: IF condition executable_body error  */
#line 458 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 1983 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 106: /* if: IF condition executable_body ELSE executable_body error  */
#line 463 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 1992 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 107: /* if: IF condition error ENDIF ';'  */
#line 468 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2001 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* if: IF condition error ';'  */
#line 473 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2011 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* if: IF condition error ELSE ENDIF ';'  */
#line 479 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2020 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* if: IF condition error ELSE ';'  */
#line 484 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2030 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* if: IF condition executable_body ELSE error ENDIF ';'  */
#line 490 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2039 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 112: /* if: IF condition executable_body ELSE error ';'  */
#line 495 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2049 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 113: /* if: ELSE executable_body ENDIF ';'  */
#line 501 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;
    }
#line 2058 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 115: /* executable_body: '{' executable_statements error ';'  */
#line 510 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 2067 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* control_stmt: DO executable_body WHILE condition ';'  */
#line 526 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("DO-WHILE");
    }
#line 2075 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* control_stmt: DO executable_body WHILE condition error  */
#line 530 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2084 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 121: /* control_stmt: DO executable_body condition ';'  */
#line 535 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE);
    }
#line 2092 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* control_stmt: DO executable_body condition error  */
#line 539 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE);
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2102 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* control_stmt: DO WHILE condition ';'  */
#line 545 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
    }
#line 2110 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 124: /* control_stmt: DO WHILE condition error  */
#line 549 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2120 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* opt_trunc_constant: TRUNC '(' numeric_constant error  */
#line 562 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2129 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* opt_trunc_constant: TRUNC numeric_constant ')'  */
#line 567 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2137 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 129: /* opt_trunc_constant: TRUNC numeric_constant error  */
#line 571 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2146 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 132: /* opt_trunc_variable: TRUNC '(' variable error  */
#line 581 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2155 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* opt_trunc_variable: TRUNC variable ')'  */
#line 586 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2163 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 134: /* opt_trunc_variable: TRUNC variable error  */
#line 590 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2172 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 137: /* opt_trunc_expression: TRUNC '(' expression error  */
#line 600 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2181 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* opt_trunc_expression: TRUNC expression ')'  */
#line 605 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2189 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 139: /* opt_trunc_expression: TRUNC expression error  */
#line 609 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2198 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* condition: '(' comparison error  */
#line 620 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2207 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 142: /* condition: comparison ')'  */
#line 625 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2215 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* condition: comparison error  */
#line 629 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    }
#line 2224 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* comparison: opt_trunc_expression error  */
#line 638 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;
    }
#line 2233 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 155: /* $@6: %empty  */
#line 658 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 2241 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 157: /* expression: expression '+' error  */
#line 662 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2250 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* expression: expression '-' error  */
#line 667 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2259 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 159: /* expression: '+' term  */
#line 672 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2267 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* expression: '+' error  */
#line 676 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_OPERANDS);
        yyerrok;
    }
#line 2276 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* positive_term: positive_term '*' error  */
#line 692 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2285 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 167: /* positive_term: positive_term '/' error  */
#line 697 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2294 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 171: /* negative_term: negative_term '*' error  */
#line 708 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2303 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* negative_term: negative_term '/' error  */
#line 713 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2312 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* negative_term: '*' factor  */
#line 718 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_FACTOR);
    }
#line 2320 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* negative_term: '/' factor  */
#line 722 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_FACTOR);
    }
#line 2328 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* negative_term: '*' error  */
#line 726 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2337 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 176: /* negative_term: '/' error  */
#line 731 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2346 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* negative_factor: '-' UINTEGER_LITERAL  */
#line 752 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2354 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 185: /* negative_factor: '-' function_invocation  */
#line 756 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2362 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 186: /* negative_factor: '-' variable  */
#line 760 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2370 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 187: /* negative_factor: '-' lambda_invocation  */
#line 764 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2378 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 188: /* negative_factor: '-' error  */
#line 768 "include/syntax-analyzer/components/yacc.y"
    {
        if (yychar != '-')
            specifySyntaxError(MISSING_LEFT_OPERAND);
        else
            specifySyntaxError(MISSING_FLOAT_CONSTANT);
        yyerrok;
    }
#line 2390 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* negative_constant: '-' FLOAT_LITERAL  */
#line 789 "include/syntax-analyzer/components/yacc.y"
    {
        addNegativeFloatToTable();
    }
#line 2398 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 2402 "src/syntax-analyzer/components/parser.cpp"

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

#line 799 "include/syntax-analyzer/components/yacc.y"


void yyerror(const char* s)
{
    announceSyntaxError();
}
