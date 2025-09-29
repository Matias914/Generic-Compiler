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

#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/semantic_actions.h"

#define yylex LexicalAnalyzer::yylex

void yyerror(const char* s);

using namespace SyntaxAnalyzer::SemanticActions;

#line 82 "src/syntax-analyzer/components/parser.cpp"

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
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_program_body = 39,              /* program_body  */
  YYSYMBOL_program_statements = 40,        /* program_statements  */
  YYSYMBOL_program_statement = 41,         /* program_statement  */
  YYSYMBOL_declarative_stmt = 42,          /* declarative_stmt  */
  YYSYMBOL_variable_list = 43,             /* variable_list  */
  YYSYMBOL_type = 44,                      /* type  */
  YYSYMBOL_formal_parameter_list = 45,     /* formal_parameter_list  */
  YYSYMBOL_formal_parameter = 46,          /* formal_parameter  */
  YYSYMBOL_parameter_type = 47,            /* parameter_type  */
  YYSYMBOL_function_body = 48,             /* function_body  */
  YYSYMBOL_function_statements = 49,       /* function_statements  */
  YYSYMBOL_function_statement = 50,        /* function_statement  */
  YYSYMBOL_executable_stmt = 51,           /* executable_stmt  */
  YYSYMBOL_assignment = 52,                /* assignment  */
  YYSYMBOL_print = 53,                     /* print  */
  YYSYMBOL_multiple_assignments = 54,      /* multiple_assignments  */
  YYSYMBOL_assignment_list = 55,           /* assignment_list  */
  YYSYMBOL_extra_numeric_constants = 56,   /* extra_numeric_constants  */
  YYSYMBOL_function_invocation = 57,       /* function_invocation  */
  YYSYMBOL_real_parameter_list = 58,       /* real_parameter_list  */
  YYSYMBOL_real_parameter = 59,            /* real_parameter  */
  YYSYMBOL_lambda_invocation = 60,         /* lambda_invocation  */
  YYSYMBOL_lambda_real_parameter = 61,     /* lambda_real_parameter  */
  YYSYMBOL_if = 62,                        /* if  */
  YYSYMBOL_executable_body = 63,           /* executable_body  */
  YYSYMBOL_executable_statements = 64,     /* executable_statements  */
  YYSYMBOL_control_stmt = 65,              /* control_stmt  */
  YYSYMBOL_opt_trunc_constant = 66,        /* opt_trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 67,        /* opt_trunc_variable  */
  YYSYMBOL_opt_trunc_expression = 68,      /* opt_trunc_expression  */
  YYSYMBOL_condition = 69,                 /* condition  */
  YYSYMBOL_comparison_operator = 70,       /* comparison_operator  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_term = 72,                      /* term  */
  YYSYMBOL_factor = 73,                    /* factor  */
  YYSYMBOL_variable = 74,                  /* variable  */
  YYSYMBOL_numeric_constant = 75           /* numeric_constant  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

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
      28,    29,    34,    32,    30,    33,    36,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,    58,    58,    65,    66,    73,    75,    79,    80,    81,
      82,    91,    95,   100,   104,   114,   115,   116,   124,   130,
     131,   132,   140,   141,   145,   149,   150,   158,   159,   163,
     164,   169,   170,   175,   176,   177,   178,   179,   180,   184,
     188,   196,   200,   205,   209,   220,   224,   232,   233,   236,
     238,   244,   248,   256,   257,   258,   266,   273,   277,   285,
     286,   292,   296,   301,   305,   313,   314,   319,   323,   324,
     330,   334,   344,   345,   349,   350,   354,   355,   361,   365,
     366,   367,   368,   372,   373,   374,   378,   379,   380,   384,
     385,   389,   390,   394,   395,   396
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
  "STRING_LITERAL", "'{'", "'}'", "';'", "'('", "')'", "','", "'='", "'+'",
  "'-'", "'*'", "'/'", "'.'", "$accept", "program", "program_body",
  "program_statements", "program_statement", "declarative_stmt",
  "variable_list", "type", "formal_parameter_list", "formal_parameter",
  "parameter_type", "function_body", "function_statements",
  "function_statement", "executable_stmt", "assignment", "print",
  "multiple_assignments", "assignment_list", "extra_numeric_constants",
  "function_invocation", "real_parameter_list", "real_parameter",
  "lambda_invocation", "lambda_real_parameter", "if", "executable_body",
  "executable_statements", "control_stmt", "opt_trunc_constant",
  "opt_trunc_variable", "opt_trunc_expression", "condition",
  "comparison_operator", "expression", "term", "factor", "variable",
  "numeric_constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    20,    50,  -104,  -104,  -104,    68,    19,     2,   127,
      42,  -104,    59,  -104,    47,  -104,  -104,    60,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,   -10,  -104,  -104,   148,
     111,  -104,    80,   142,   148,    83,    92,    69,     6,  -104,
     148,   109,  -104,   163,    73,   102,  -104,  -104,   119,   177,
     125,   -16,   112,  -104,  -104,  -104,  -104,    82,   129,   133,
     147,    11,  -104,   165,  -104,   171,    65,    79,  -104,   109,
      12,   152,   173,  -104,  -104,   169,  -104,  -104,  -104,  -104,
    -104,   148,   127,   169,   169,   169,   169,   176,  -104,  -104,
     148,    21,    22,   148,    26,   148,   183,   180,  -104,   185,
      13,  -104,    47,  -104,  -104,  -104,   181,  -104,   163,    51,
      17,    93,  -104,   167,   112,   112,  -104,  -104,  -104,   178,
     182,  -104,   184,  -104,  -104,   186,  -104,  -104,  -104,   111,
    -104,    65,   187,    65,   189,  -104,   188,   190,   193,  -104,
     163,  -104,   127,    27,    28,  -104,  -104,  -104,   130,  -104,
     107,    30,  -104,  -104,  -104,  -104,  -104,  -104,   208,   194,
    -104,   195,  -104,   196,   197,  -104,    81,  -104,  -104,   199,
    -104,    31,  -104,  -104,   156,   148,   200,  -104,  -104,  -104,
     201,  -104,   202,   203,  -104,  -104,  -104,   204,  -104,  -104,
     169,    33,    37,   205,   209,  -104,  -104,  -104,  -104,  -104
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     2,     1,     0,     0,     0,     0,
       0,    18,    91,     3,     0,     6,     7,     0,     8,    33,
      37,    34,    35,    38,    36,     9,     0,     4,    10,     0,
       0,    67,     0,     0,     0,     0,     0,    91,     0,    15,
       0,     0,    47,     0,     0,    91,    94,    93,     0,     0,
       0,    76,    85,    88,    89,    90,    68,     0,     0,     0,
       0,     0,    53,     0,    92,     0,     0,     0,    11,     0,
       0,     0,     0,    49,    72,     0,    95,    79,    81,    82,
      80,     0,     0,     0,     0,     0,     0,     0,    65,    69,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,    19,     0,    12,    17,    16,     0,    39,     0,     0,
       0,     0,    78,     0,    83,    84,    86,    87,    66,     0,
       0,    41,     0,    43,    55,     0,    51,    54,    56,     0,
      22,     0,     0,     0,     0,    40,     0,     0,     0,    45,
       0,    77,     0,     0,     0,    42,    44,    52,     0,    21,
       0,     0,    20,    23,    48,    73,    46,    50,     0,     0,
      61,     0,    70,     0,     0,    31,     0,    27,    32,     0,
      13,     0,    62,    71,     0,     0,     0,    25,    28,    14,
       0,    63,     0,     0,    60,    59,    74,     0,    26,    64,
       0,     0,     0,     0,     0,    57,    30,    29,    75,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,  -104,  -104,   210,  -104,    -4,  -104,   -19,
    -104,  -104,  -104,    49,    -5,  -104,  -104,  -104,   146,  -104,
    -104,  -104,    25,  -104,  -104,  -104,   -76,    94,  -104,  -103,
    -104,   -25,   139,  -104,   160,   104,   113,    -6,   -41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     4,     6,    15,   165,    38,    17,   100,   101,
     102,   151,   166,   167,    31,    19,    20,    21,    43,   110,
      22,    61,    62,    23,   183,    24,    32,    57,    25,    73,
     185,    63,    50,    81,    51,    52,    53,    54,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    18,    74,    26,    49,   136,   113,    67,    60,    40,
      36,    39,    93,   106,   131,    70,    83,    84,   138,    27,
      41,    42,   120,   122,    26,    56,     1,   125,   159,   161,
      29,   169,   180,    68,   194,    71,    69,   157,   196,   107,
      94,    95,   132,   133,   139,     3,    28,   140,   121,   123,
       5,    26,    89,   126,   160,   162,   112,   170,   181,    11,
     195,   104,    99,   105,   197,    49,   158,    74,   137,     7,
      33,   184,     8,    46,    47,     9,    26,    11,    10,    98,
      11,    37,   176,    87,    48,     8,     8,    34,    58,    12,
     164,    10,    10,    11,    13,    35,    14,    66,   134,    74,
      45,    75,    12,    12,    64,    35,   103,   177,    88,    14,
      14,     8,   149,    65,   152,     8,   164,    10,   124,    11,
     127,    10,   141,    26,    56,    83,    84,    99,    12,    99,
      45,     8,    12,    74,     8,    14,    26,    10,    35,    14,
      10,    76,    26,    89,    26,   168,    85,    86,    12,   137,
     187,    12,    30,    44,    82,    14,   163,    90,    14,    44,
      26,   168,    91,    45,    46,    47,    59,   182,   186,    45,
      46,    47,   142,   143,    72,    48,    92,    45,    46,    47,
      96,    48,    41,    42,   193,    46,    47,   114,   115,    48,
      45,    46,    47,    77,    78,    79,    48,    80,   116,   117,
      97,   109,    48,   118,   128,   129,   130,   144,   135,   145,
     153,   146,   150,   147,   171,   178,    16,   108,   154,   155,
     156,   172,   173,   148,   174,   175,   179,   188,   189,   119,
     190,     0,   191,   192,   198,   111,   199
};

static const yytype_int16 yycheck[] =
{
       6,     6,    43,     9,    29,   108,    82,     1,    33,    19,
      14,    17,     1,     1,     1,    40,    32,    33,     1,     0,
      30,    31,     1,     1,    30,    30,    21,     1,     1,     1,
      28,     1,     1,    27,     1,    41,    30,   140,     1,    27,
      29,    30,    29,    30,    27,    25,    27,    30,    27,    27,
       0,    57,    57,    27,    27,    27,    81,    27,    27,    12,
      27,    67,    66,    69,    27,    90,   142,   108,   109,     1,
      28,   174,     4,    22,    23,     7,    82,    12,    10,    14,
      12,    21,     1,     1,    33,     4,     4,    28,     8,    21,
       9,    10,    10,    12,    26,    36,    28,    28,   102,   140,
      21,    28,    21,    21,    21,    36,    27,    26,    26,    28,
      28,     4,   131,    21,   133,     4,     9,    10,    93,    12,
      95,    10,    29,   129,   129,    32,    33,   131,    21,   133,
      21,     4,    21,   174,     4,    28,   142,    10,    36,    28,
      10,    22,   148,   148,   150,   150,    34,    35,    21,   190,
     175,    21,    25,    11,    29,    28,    26,    28,    28,    11,
     166,   166,    29,    21,    22,    23,    24,    11,   174,    21,
      22,    23,     5,     6,    11,    33,    29,    21,    22,    23,
      15,    33,    30,    31,   190,    22,    23,    83,    84,    33,
      21,    22,    23,    16,    17,    18,    33,    20,    85,    86,
      29,    28,    33,    27,    21,    25,    21,    29,    27,    27,
      21,    27,    25,    27,     6,   166,     6,    71,    30,    29,
      27,    27,    27,   129,    28,    28,    27,    27,    27,    90,
      28,    -1,    29,    29,    29,    75,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    38,    25,    39,     0,    40,     1,     4,     7,
      10,    12,    21,    26,    28,    41,    42,    44,    51,    52,
      53,    54,    57,    60,    62,    65,    74,     0,    27,    28,
      25,    51,    63,    28,    28,    36,    44,    21,    43,    74,
      19,    30,    31,    55,    11,    21,    22,    23,    33,    68,
      69,    71,    72,    73,    74,    75,    51,    64,     8,    24,
      68,    58,    59,    68,    21,    21,    28,     1,    27,    30,
      68,    74,    11,    66,    75,    28,    22,    16,    17,    18,
      20,    70,    29,    32,    33,    34,    35,     1,    26,    51,
      28,    29,    29,     1,    29,    30,    15,    29,    14,    44,
      45,    46,    47,    27,    74,    74,     1,    27,    55,    28,
      56,    71,    68,    63,    72,    72,    73,    73,    27,    69,
       1,    27,     1,    27,    59,     1,    27,    59,    21,    25,
      21,     1,    29,    30,    44,    27,    66,    75,     1,    27,
      30,    29,     5,     6,    29,    27,    27,    27,    64,    46,
      25,    48,    46,    21,    30,    29,    27,    66,    63,     1,
      27,     1,    27,    26,     9,    42,    49,    50,    51,     1,
      27,     6,    27,    27,    28,    28,     1,    26,    50,    27,
       1,    27,    11,    61,    66,    67,    74,    68,    27,    27,
      28,    29,    29,    74,     1,    27,     1,    27,    29,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    41,
      41,    42,    42,    42,    42,    43,    43,    43,    44,    45,
      45,    45,    46,    46,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    51,    51,    51,    51,    51,    51,    52,
      52,    53,    53,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     4,     0,     2,     1,     1,     1,
       2,     3,     4,     7,     8,     1,     3,     3,     1,     1,
       3,     3,     2,     3,     1,     3,     4,     1,     2,     5,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     5,     6,     5,     6,     5,     6,     1,     5,     0,
       3,     5,     6,     1,     3,     3,     3,    11,    12,     1,
       1,     7,     8,     9,    10,     3,     4,     1,     1,     2,
       7,     8,     1,     4,     1,     4,     1,     4,     3,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     3,     1,     1,     2
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
  case 2: /* program: IDENTIFIER program_body  */
#line 59 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PROGRAM");
    }
#line 1285 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 4: /* program_body: '{' program_statements error $end  */
#line 67 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError("}");
        yyerrok;
    }
#line 1294 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* program_statement: error ';'  */
#line 83 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1302 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* declarative_stmt: type variable_list ';'  */
#line 92 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("VARIABLE DECLARATION");
    }
#line 1310 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* declarative_stmt: type variable_list error ';'  */
#line 96 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1319 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body ';'  */
#line 101 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION DECLARATION");
    }
#line 1327 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body error ';'  */
#line 105 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1336 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 17: /* variable_list: variable_list error variable  */
#line 117 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(",");
        yyerrok;
    }
#line 1345 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* formal_parameter_list: formal_parameter_list error formal_parameter  */
#line 133 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(",");
        yyerrok;
    }
#line 1354 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* function_body: '{' function_statements error ';'  */
#line 151 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError("}");
        yyerrok;
    }
#line 1363 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* function_statement: RETURN '(' opt_trunc_expression ')' error  */
#line 165 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1372 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 39: /* assignment: variable ASSIGN_OP opt_trunc_expression ';'  */
#line 185 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("ASSIGNMENT");
    }
#line 1380 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* assignment: variable ASSIGN_OP opt_trunc_expression error ';'  */
#line 189 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1389 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* print: PRINT '(' STRING_LITERAL ')' ';'  */
#line 197 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1397 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* print: PRINT '(' STRING_LITERAL ')' error ';'  */
#line 201 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1406 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* print: PRINT '(' opt_trunc_expression ')' ';'  */
#line 206 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1414 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 44: /* print: PRINT '(' opt_trunc_expression ')' error ';'  */
#line 210 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1423 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 221 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("MULTIPLE ASSIGNMENT");
    }
#line 1431 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error ';'  */
#line 225 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1440 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 51: /* function_invocation: IDENTIFIER '(' real_parameter_list ')' ';'  */
#line 245 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION INVOCATION");
    }
#line 1448 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 52: /* function_invocation: IDENTIFIER '(' real_parameter_list ')' error ';'  */
#line 249 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1457 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* real_parameter_list: real_parameter_list error real_parameter  */
#line 259 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(",");
        yyerrok;
    }
#line 1466 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '}' '(' lambda_real_parameter ')' ';'  */
#line 274 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("LAMBDA");
    }
#line 1474 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '}' '(' lambda_real_parameter ')' error ';'  */
#line 278 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1483 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* if: IF '(' condition ')' executable_body ENDIF ';'  */
#line 293 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF");
    }
#line 1491 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* if: IF '(' condition ')' executable_body ENDIF error ';'  */
#line 297 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1500 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* if: IF '(' condition ')' executable_body ELSE executable_body ENDIF ';'  */
#line 302 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF-ELSE");
    }
#line 1508 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* if: IF '(' condition ')' executable_body ELSE executable_body ENDIF error ';'  */
#line 306 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1517 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 66: /* executable_body: '{' executable_statements error ';'  */
#line 315 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError("}");
        yyerrok;
    }
#line 1526 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* control_stmt: DO executable_body WHILE '(' condition ')' ';'  */
#line 331 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("DO-WHILE");
    }
#line 1534 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* control_stmt: DO executable_body WHILE '(' condition ')' error ';'  */
#line 335 "include/syntax-analyzer/components/yacc.y"
    {
        specifyExpectedError(";");
        yyerrok;
    }
#line 1543 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* numeric_constant: '-' FLOAT_LITERAL  */
#line 397 "include/syntax-analyzer/components/yacc.y"
    {
        addNegativeFloatToTable();
    }
#line 1551 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 1555 "src/syntax-analyzer/components/parser.cpp"

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

#line 402 "include/syntax-analyzer/components/yacc.y"


void yyerror(const char* s)
{
    announceSyntaxError();
}
