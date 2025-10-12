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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   862

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  201
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  335

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
     173,   174,   176,   175,   179,   187,   188,   197,   198,   200,
     199,   206,   207,   212,   216,   217,   222,   228,   235,   239,
     240,   248,   249,   253,   254,   258,   259,   264,   270,   275,
     281,   285,   289,   298,   299,   300,   301,   302,   303,   307,
     311,   319,   323,   328,   332,   337,   341,   353,   357,   362,
     369,   370,   372,   371,   376,   382,   384,   386,   385,   394,
     395,   400,   401,   409,   413,   421,   422,   424,   423,   430,
     431,   441,   445,   449,   453,   460,   461,   467,   471,   476,
     480,   485,   490,   495,   500,   506,   511,   517,   522,   528,
     536,   537,   542,   546,   547,   553,   557,   562,   566,   572,
     576,   587,   588,   589,   594,   598,   606,   607,   608,   613,
     617,   625,   626,   627,   632,   636,   646,   647,   652,   656,
     664,   665,   673,   674,   675,   676,   677,   678,   682,   683,
     684,   686,   685,   689,   694,   699,   703,   711,   712,   716,
     717,   718,   719,   724,   732,   733,   734,   735,   740,   745,
     749,   753,   758,   766,   767,   771,   772,   773,   777,   778,
     779,   783,   787,   791,   795,   806,   807,   811,   812,   816,
     823,   824
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

#define YYPACT_NINF (-221)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-162)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     465,  -221,    49,   678,   779,   752,   696,    24,  -221,  -221,
      33,   591,  -221,   118,   494,  -221,  -221,  -221,   162,  -221,
    -221,  -221,  -221,  -221,  -221,     7,    48,  -221,  -221,   106,
    -221,   823,   144,  -221,  -221,   656,   210,   227,   358,   366,
    -221,  -221,   414,   623,    27,   418,  -221,   176,   229,  -221,
    -221,  -221,  -221,    96,   653,  -221,   159,   678,   427,   656,
     137,   674,   591,   158,   202,   591,  -221,   523,  -221,  -221,
    -221,  -221,   168,  -221,  -221,   214,   226,   496,   105,    96,
    -221,  -221,  -221,  -221,   237,   714,   237,  -221,   279,   323,
     731,   326,    43,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
      96,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,   714,   255,   368,  -221,  -221,   252,
     316,   436,   382,   390,   398,   401,  -221,   645,   249,    70,
     678,   127,   181,  -221,  -221,   275,   256,   150,   286,   552,
     293,   264,  -221,   152,  -221,   581,  -221,  -221,  -221,   306,
    -221,   496,  -221,  -221,   206,   295,  -221,   395,  -221,  -221,
     215,   237,  -221,    96,   151,    72,  -221,   445,  -221,   332,
    -221,  -221,  -221,  -221,   341,  -221,  -221,  -221,  -221,  -221,
      88,   330,  -221,  -221,   655,   174,  -221,  -221,  -221,  -221,
     176,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,   338,
    -221,  -221,  -221,  -221,  -221,   187,  -221,  -221,  -221,  -221,
     208,  -221,   216,  -221,  -221,   217,  -221,  -221,  -221,  -221,
     714,   714,  -221,   347,  -221,  -221,   781,   303,  -221,  -221,
     367,   496,   496,  -221,  -221,   258,  -221,    96,    96,   111,
    -221,  -221,   296,   349,   170,   355,  -221,  -221,   373,  -221,
    -221,   250,   263,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,   653,   806,   367,
     766,   379,  -221,  -221,  -221,  -221,  -221,   365,   173,  -221,
    -221,  -221,  -221,   296,   296,  -221,   387,  -221,  -221,   224,
     809,   409,   827,   251,  -221,   613,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,   417,   827,    18,
     461,   422,  -221,  -221,    96,  -221,  -221,  -221,  -221,  -221,
      18,   425,   431,   421,    76,  -221,   442,  -221,  -221,    91,
    -221,  -221,  -221,  -221,  -221
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,     0,     0,     0,    35,    36,
     200,     0,    11,     0,     0,     2,     8,     5,     0,    68,
       6,    63,    67,    64,    65,     0,     0,    66,     7,     0,
      12,     0,   200,   198,   197,     0,     0,     0,     0,     0,
     187,   189,     0,     0,     0,   141,   160,   167,   168,   171,
     176,   186,   188,   185,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,    15,    17,
      18,    19,     0,     1,     3,     0,   200,     0,     0,    30,
      90,    89,    92,    91,     0,     0,     0,    80,     0,     0,
       0,     0,     0,   166,   165,   194,   199,   190,   191,   193,
     192,   181,   179,   183,   184,   182,   180,   151,   152,   154,
     155,   153,   156,   157,     0,     0,     0,   149,   148,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,    59,    62,    58,     0,     0,     0,     0,
       0,    97,    95,     0,    23,     0,    10,     9,    16,     0,
      25,     0,    48,    43,     0,    39,    37,     0,    26,    24,
       0,     0,   200,    82,     0,     0,   201,     0,    79,     0,
      85,   131,   195,   196,     0,   145,   144,   147,   146,   150,
       0,     0,   114,   111,     0,     0,   163,   158,   164,   159,
     162,   172,   169,   173,   170,   177,   174,   178,   175,     0,
     120,   124,   119,   130,   129,     0,   128,   127,    57,    60,
       0,    61,     0,    76,    75,     0,    14,    13,    94,    93,
       0,     0,   100,     0,    22,    21,     0,    39,    42,    41,
       0,     0,     0,    46,    47,     0,    34,    31,    33,     0,
      70,    69,     0,     0,     0,     0,   143,   142,     0,   116,
     113,     0,     0,   108,   107,   121,   126,   125,    56,    55,
      72,    71,    74,    73,    96,    98,    99,     0,     0,     0,
       0,     0,    38,    40,    45,    44,    83,    84,     0,   135,
     134,    78,    77,     0,     0,   115,     0,   118,   112,     0,
       0,     0,     0,     0,    53,     0,    51,    54,    28,    81,
     133,   132,    86,    88,   117,   110,   109,     0,     0,     0,
       0,     0,   106,   105,   136,    29,    27,    50,    49,    52,
       0,     0,     0,     0,     0,   104,     0,   103,   102,     0,
     140,   139,   101,   138,   137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,   462,   205,   -43,   -44,     1,  -221,  -221,   -11,
     328,  -221,   196,  -221,   212,  -221,   190,  -221,    16,  -221,
    -221,  -221,  -152,  -221,  -221,  -221,  -221,    31,  -221,  -221,
     267,    46,    89,  -221,    12,  -220,   291,   -80,  -221,    19,
     -31,   457,  -221,   -21,  -221,   -29,   376,  -221,    -1,    -6,
      25,  -155,   -86,    20,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    14,    15,    66,    67,    68,    69,    78,   161,    18,
     155,   232,   156,   157,   271,   295,   296,    19,    70,    21,
      22,    23,    89,   239,   245,   284,    24,    40,   141,   221,
     142,    41,   311,    27,    56,   127,    71,   312,   313,    42,
      43,    44,   114,    45,   121,    46,    47,    48,   102,    49,
      50,   171,    51,    52,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    17,    72,   172,    29,    29,   268,    94,    80,   170,
      91,    29,   244,   242,    29,    17,    20,    58,    79,   139,
      55,    55,   145,   148,    72,    60,   129,   131,   117,   310,
      20,    25,   103,   103,    81,    25,    25,   100,   106,   162,
      33,    34,    25,    29,   177,    25,    26,   290,    72,    82,
      26,    26,    61,   169,    29,   116,   118,    26,    62,    55,
      26,    63,    29,   104,   104,    29,   154,    29,    98,   174,
     126,   203,   178,    84,    25,    83,    30,   330,   132,    72,
     138,   172,   143,    99,   163,    25,   165,   276,   278,    26,
     187,   189,   333,    25,   248,   148,    25,   204,    25,   205,
      26,   148,    86,    87,   164,   331,   158,    84,    26,   173,
      88,    26,    84,    26,    88,   249,   103,   103,   103,   103,
     334,   192,   194,   196,   198,    85,   -32,    29,   206,    88,
       8,     9,   159,   179,    88,   160,    86,    87,   133,    29,
     154,    86,    87,   201,    88,    29,   235,   104,   104,   104,
     104,   213,   240,   222,   207,   244,   172,   172,    25,   140,
     237,   238,   277,    75,   134,   128,   135,   223,   278,    31,
      25,   279,    63,    26,   300,   253,    25,   214,   241,    32,
      33,    34,   208,    76,    29,    26,    13,   173,   256,   149,
      77,    26,    36,    37,    38,    39,   252,   172,   172,   280,
      55,   254,   301,   302,   303,    16,   172,   228,   209,   258,
     210,    93,   122,   123,   257,    25,   236,   260,   262,    16,
     154,   154,   172,   172,   172,   305,    29,   229,    95,   144,
      26,    32,    33,    34,   172,   259,   162,   172,    13,   143,
     143,   150,   126,   261,   263,    37,    38,    39,    32,    96,
      97,   306,   315,   186,   151,    13,   286,    25,   162,   274,
     180,   181,   173,   173,   288,   124,   125,    29,    29,   289,
      29,   294,    26,    32,    33,    34,   202,   287,   316,   275,
      13,    72,   182,   126,   201,   212,   297,    37,    38,    39,
      29,    28,   314,   219,   220,    29,   294,    72,    25,    25,
     166,    25,   211,   173,   173,    28,   201,   167,   314,   314,
     324,   297,   173,    26,    26,   215,    26,   188,    33,    34,
     314,    25,   218,   329,   230,   231,    25,   175,   173,   173,
     173,   169,   269,   231,   167,   226,    26,    32,    33,    34,
     173,    26,   246,   173,    13,    33,    34,  -161,  -161,  -161,
     168,    37,    38,    39,    96,   176,   281,   250,   169,   101,
     119,   120,  -161,  -161,  -161,   255,   -87,   105,   266,   183,
     247,    33,    34,   184,   185,   119,   120,   -87,   -87,    32,
      33,    34,   282,   191,   169,   283,    13,    32,    33,    34,
     -87,   193,   270,    37,    13,   299,   233,   321,   322,   195,
     285,    37,   197,    32,    33,    34,   298,     8,     9,   326,
      13,    32,    33,    34,   304,   107,   234,    37,    13,    32,
      33,    34,    32,    33,    34,    37,    13,   272,   273,    13,
     108,   109,   110,    37,   111,   130,    37,   309,    31,  -161,
    -161,  -161,   162,    33,    34,   320,   112,   113,    32,    33,
      34,   325,   119,   120,   327,    35,   169,    32,    33,    34,
     328,    36,    37,    38,    39,     1,     2,    33,    34,     3,
       4,   332,     5,   243,     6,     7,    74,     8,     9,   227,
     169,   293,   162,    33,    34,   319,    10,   264,   265,   323,
      11,    12,    92,    13,    73,     2,   169,   190,     3,     4,
       0,     5,     0,     6,     7,     0,     8,     9,     8,     9,
     152,     0,     0,     0,     0,    10,     0,   153,     0,    11,
      12,     0,    13,   146,    64,     0,     0,     3,     4,     0,
       5,     0,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,    65,   147,
       0,    13,   216,    64,     0,     0,     3,     4,     0,     5,
       0,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,    65,   217,     0,
      13,   224,    64,     0,     0,     3,     4,     0,     5,     0,
       6,     7,    64,     8,     9,     3,     4,     0,     5,     0,
       6,     7,    10,     8,     9,     0,    65,   225,     0,    13,
       0,     0,    10,     0,   317,     0,    65,     3,     4,    13,
       0,     0,     6,     7,   115,     8,     9,     3,     4,     0,
       0,     0,     6,     7,    32,     0,     0,     0,     0,   318,
       0,    13,     0,     0,    32,     0,   199,     0,    54,     3,
       4,    13,     0,     0,     6,     7,   251,     3,     4,     3,
       4,     0,     6,     7,     6,     7,    32,    31,     8,     9,
       0,   200,     0,    13,    32,     0,    32,    32,    33,    34,
      54,    13,     0,    13,    13,    31,     0,     0,     0,    31,
      36,    37,    38,    39,     0,    32,    33,    34,   136,    32,
      33,    34,    13,   137,     0,     0,    35,    31,    36,    37,
      38,    39,    36,    37,    38,    39,     0,    32,    33,    34,
       0,     0,     0,     0,    59,    31,     0,     0,     0,     0,
      36,    37,    38,    39,     0,    32,    33,    34,     0,     0,
       0,     0,    13,     8,     9,     0,     0,     0,    36,    37,
      38,    39,    32,    33,    34,     0,     3,     4,     0,    13,
      57,     6,     7,     0,     0,    36,    37,    38,    39,     0,
       3,     4,     0,    32,     0,     6,     7,    54,     8,     9,
      13,     0,     0,     3,     4,     3,     4,    32,     6,     7,
       6,     7,     0,     0,    13,     0,     0,     0,     0,     0,
      32,     0,    32,     0,    54,     0,   267,    13,     0,    13,
       3,     4,     0,     3,     4,     6,     7,     0,     6,     7,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
      32,     0,   291,     0,   292,   307,     0,   308,   310,     8,
       9,     0,     0,     0,    32,    33,    34,     0,   162,    33,
      34,    90,     0,     0,     0,     0,     0,    36,    37,    38,
      39,     0,   169
};

static const yytype_int16 yycheck[] =
{
       0,     0,    13,    89,     4,     5,   226,    36,     1,    89,
      31,    11,   167,   165,    14,    14,     0,     5,    18,    62,
       4,     5,    65,    67,    35,     6,    57,    58,     1,    11,
      14,     0,    38,    39,    27,     4,     5,    37,    39,    21,
      22,    23,    11,    43,     1,    14,     0,   267,    59,     1,
       4,     5,    28,    35,    54,    43,    29,    11,    25,    43,
      14,    28,    62,    38,    39,    65,    77,    67,    37,    90,
      54,     1,    29,     1,    43,    27,    27,     1,    59,    90,
      61,   167,    63,    37,    84,    54,    86,   239,   243,    43,
     119,   120,     1,    62,     6,   139,    65,    27,    67,   130,
      54,   145,    30,    31,    85,    29,     1,     1,    62,    89,
      38,    65,     1,    67,    38,    27,   122,   123,   124,   125,
      29,   122,   123,   124,   125,    19,    21,   127,     1,    38,
      12,    13,    27,   114,    38,    30,    30,    31,     1,   139,
     151,    30,    31,   127,    38,   145,   157,   122,   123,   124,
     125,     1,     1,     1,    27,   310,   242,   243,   127,     1,
     160,   161,   242,     1,    27,     6,    29,    15,   323,    11,
     139,     1,    28,   127,     1,     1,   145,    27,    27,    21,
      22,    23,     1,    21,   184,   139,    28,   167,     1,    21,
      28,   145,    34,    35,    36,    37,   184,   283,   284,    29,
     184,    27,    29,   283,   284,     0,   292,     1,    27,     1,
      29,     1,    36,    37,    27,   184,     1,     1,     1,    14,
     231,   232,   308,   309,   310,     1,   226,    21,     1,    27,
     184,    21,    22,    23,   320,    27,    21,   323,    28,   220,
     221,    27,   226,    27,    27,    35,    36,    37,    21,    22,
      23,    27,     1,     1,    28,    28,     6,   226,    21,     1,
       5,     6,   242,   243,     1,    36,    37,   267,   268,     6,
     270,   270,   226,    21,    22,    23,    27,    27,    27,    21,
      28,   292,    27,   267,   268,    29,   270,    35,    36,    37,
     290,     0,   292,    29,    30,   295,   295,   308,   267,   268,
      21,   270,    27,   283,   284,    14,   290,    11,   308,   309,
     310,   295,   292,   267,   268,    29,   270,     1,    22,    23,
     320,   290,    29,   323,    29,    30,   295,     1,   308,   309,
     310,    35,    29,    30,    11,    29,   290,    21,    22,    23,
     320,   295,     1,   323,    28,    22,    23,    21,    22,    23,
      27,    35,    36,    37,    22,    29,     1,    27,    35,     1,
      34,    35,    21,    22,    23,    27,    11,     1,    21,     1,
      29,    22,    23,     5,     6,    34,    35,    22,    23,    21,
      22,    23,    27,     1,    35,    30,    28,    21,    22,    23,
      35,     1,    25,    35,    28,    30,     1,   308,   309,     1,
      27,    35,     1,    21,    22,    23,    27,    12,    13,   320,
      28,    21,    22,    23,    27,     1,    21,    35,    28,    21,
      22,    23,    21,    22,    23,    35,    28,   231,   232,    28,
      16,    17,    18,    35,    20,     8,    35,    28,    11,    21,
      22,    23,    21,    22,    23,    28,    32,    33,    21,    22,
      23,    29,    34,    35,    29,    28,    35,    21,    22,    23,
      29,    34,    35,    36,    37,     0,     1,    22,    23,     4,
       5,    29,     7,    28,     9,    10,    14,    12,    13,   151,
      35,   269,    21,    22,    23,   295,    21,   220,   221,    28,
      25,    26,    35,    28,     0,     1,    35,   121,     4,     5,
      -1,     7,    -1,     9,    10,    -1,    12,    13,    12,    13,
      14,    -1,    -1,    -1,    -1,    21,    -1,    21,    -1,    25,
      26,    -1,    28,     0,     1,    -1,    -1,     4,     5,    -1,
       7,    -1,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,
      -1,    28,     0,     1,    -1,    -1,     4,     5,    -1,     7,
      -1,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    -1,
      28,     0,     1,    -1,    -1,     4,     5,    -1,     7,    -1,
       9,    10,     1,    12,    13,     4,     5,    -1,     7,    -1,
       9,    10,    21,    12,    13,    -1,    25,    26,    -1,    28,
      -1,    -1,    21,    -1,     1,    -1,    25,     4,     5,    28,
      -1,    -1,     9,    10,     1,    12,    13,     4,     5,    -1,
      -1,    -1,     9,    10,    21,    -1,    -1,    -1,    -1,    26,
      -1,    28,    -1,    -1,    21,    -1,     1,    -1,    25,     4,
       5,    28,    -1,    -1,     9,    10,     1,     4,     5,     4,
       5,    -1,     9,    10,     9,    10,    21,    11,    12,    13,
      -1,    26,    -1,    28,    21,    -1,    21,    21,    22,    23,
      25,    28,    -1,    28,    28,    11,    -1,    -1,    -1,    11,
      34,    35,    36,    37,    -1,    21,    22,    23,    24,    21,
      22,    23,    28,    29,    -1,    -1,    28,    11,    34,    35,
      36,    37,    34,    35,    36,    37,    -1,    21,    22,    23,
      -1,    -1,    -1,    -1,    28,    11,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    -1,    21,    22,    23,    -1,    -1,
      -1,    -1,    28,    12,    13,    -1,    -1,    -1,    34,    35,
      36,    37,    21,    22,    23,    -1,     4,     5,    -1,    28,
       8,     9,    10,    -1,    -1,    34,    35,    36,    37,    -1,
       4,     5,    -1,    21,    -1,     9,    10,    25,    12,    13,
      28,    -1,    -1,     4,     5,     4,     5,    21,     9,    10,
       9,    10,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    21,    -1,    25,    -1,    25,    28,    -1,    28,
       4,     5,    -1,     4,     5,     9,    10,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      21,    -1,    26,    -1,    28,    26,    -1,    28,    11,    12,
      13,    -1,    -1,    -1,    21,    22,    23,    -1,    21,    22,
      23,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     0,     1,     4,     5,     7,     9,    10,    12,    13,
      21,    25,    26,    28,    40,    41,    42,    45,    48,    56,
      57,    58,    59,    60,    65,    66,    70,    72,    75,    93,
      27,    11,    21,    22,    23,    28,    34,    35,    36,    37,
      66,    70,    78,    79,    80,    82,    84,    85,    86,    88,
      89,    91,    92,    93,    25,    57,    73,     8,    73,    28,
      78,    28,    25,    28,     1,    25,    42,    43,    44,    45,
      57,    75,    48,     0,    41,     1,    21,    28,    46,    93,
       1,    27,     1,    27,     1,    19,    30,    31,    38,    61,
      28,    82,    80,     1,    84,     1,    22,    23,    66,    70,
      93,     1,    87,    88,    89,     1,    87,     1,    16,    17,
      18,    20,    32,    33,    81,     1,    73,     1,    29,    34,
      35,    83,    36,    37,    36,    37,    57,    74,     6,    79,
       8,    79,    78,     1,    27,    29,    24,    29,    78,    43,
       1,    67,    69,    78,    27,    43,     0,    26,    44,    21,
      27,    28,    14,    21,    48,    49,    51,    52,     1,    27,
      30,    47,    21,    93,    78,    93,    21,    11,    27,    35,
      76,    90,    91,    92,    82,     1,    29,     1,    29,    78,
       5,     6,    27,     1,     5,     6,     1,    84,     1,    84,
      85,     1,    87,     1,    87,     1,    87,     1,    87,     1,
      26,    57,    27,     1,    27,    79,     1,    27,     1,    27,
      29,    27,    29,     1,    27,    29,     0,    26,    29,    29,
      30,    68,     1,    15,     0,    26,    29,    49,     1,    21,
      29,    30,    50,     1,    21,    48,     1,    93,    93,    62,
       1,    27,    61,    28,    90,    63,     1,    29,     6,    27,
      27,     1,    73,     1,    27,    27,     1,    27,     1,    27,
       1,    27,     1,    27,    69,    69,    21,    25,    74,    29,
      25,    53,    51,    51,     1,    21,    61,    76,    90,     1,
      29,     1,    27,    30,    64,    27,     6,    27,     1,     6,
      74,    26,    28,    53,    45,    54,    55,    57,    27,    30,
       1,    29,    76,    76,    27,     1,    27,    26,    28,    28,
      11,    71,    76,    77,    93,     1,    27,     1,    26,    55,
      28,    71,    71,    28,    93,    29,    71,    29,    29,    93,
       1,    29,    29,     1,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    42,    42,    43,    43,    44,    44,    44,
      44,    44,    44,    44,    45,    45,    45,    45,    45,    45,
      46,    46,    47,    46,    46,    48,    48,    49,    49,    50,
      49,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    62,    61,    61,    63,    63,    64,    63,    65,
      65,    65,    65,    66,    66,    67,    67,    68,    67,    69,
      69,    70,    70,    70,    70,    71,    71,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      75,    76,    76,    76,    76,    76,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    78,    79,    79,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    83,    82,    82,    82,    82,    82,    84,    84,    85,
      85,    85,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    91,    91,    92,
      93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     1,     2,     4,     4,     1,     2,     1,     1,     1,
       1,     3,     3,     2,     3,     3,     3,     7,     6,     7,
       1,     3,     0,     3,     3,     1,     1,     1,     3,     0,
       3,     2,     2,     1,     3,     3,     2,     2,     1,     3,
       3,     1,     2,     1,     1,     5,     5,     4,     3,     3,
       4,     4,     3,     1,     1,     1,     1,     1,     1,     4,
       4,     5,     5,     5,     5,     4,     4,     5,     5,     3,
       1,     5,     0,     4,     4,     0,     3,     0,     3,     2,
       2,     2,     2,     4,     4,     1,     3,     0,     3,     3,
       2,    10,     9,     9,     8,     1,     1,     5,     5,     7,
       7,     4,     6,     5,     4,     6,     5,     7,     6,     4,
       3,     4,     1,     1,     2,     5,     5,     4,     4,     4,
       4,     1,     4,     4,     3,     3,     1,     4,     4,     3,
       3,     1,     4,     4,     3,     3,     3,     3,     2,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     0,     3,     3,     3,     2,     2,     1,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     2,
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
#line 66 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1512 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 70 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1520 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 7: /* global_statement: control_stmt  */
#line 74 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1528 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 9: /* global_statement: '{' program_statements '}'  */
#line 79 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
    }
#line 1536 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '{' program_statements $end  */
#line 83 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1545 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: '}'  */
#line 88 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1554 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* global_statement: error ';'  */
#line 93 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1563 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* program: IDENTIFIER '{' program_statements '}'  */
#line 101 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PROGRAM");
    }
#line 1571 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* program: IDENTIFIER '{' program_statements $end  */
#line 105 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1579 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statement: program  */
#line 120 "include/syntax-analyzer/components/yacc.y"
    {
       announceSpecificError(INVALID_PROGRAM_NESTING);
    }
#line 1587 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statement: '{' program_statements '}'  */
#line 124 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1595 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: '{' program_statements $end  */
#line 128 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1604 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* program_statement: error ';'  */
#line 133 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1612 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* declarative_stmt: type variable_list ';'  */
#line 142 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("VARIABLE DECLARATION");
    }
#line 1620 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* declarative_stmt: type error ';'  */
#line 146 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1629 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* declarative_stmt: type variable_list error  */
#line 151 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1638 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body ';'  */
#line 156 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION DECLARATION");
    }
#line 1646 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* declarative_stmt: type '(' formal_parameter_list ')' function_body ';'  */
#line 160 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_FUNCTION_NAME);
    }
#line 1654 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body error  */
#line 164 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1663 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* $@1: %empty  */
#line 176 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1671 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 34: /* variable_list: variable_list ',' error  */
#line 180 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1680 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 36: /* type: FLOAT  */
#line 189 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1688 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 39: /* $@2: %empty  */
#line 200 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1696 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* formal_parameter: type error  */
#line 208 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1705 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* formal_parameter: IDENTIFIER  */
#line 213 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PARAMETER_TYPE);
    }
#line 1713 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* formal_parameter: parameter_semantics type error  */
#line 218 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1722 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* formal_parameter: parameter_semantics error  */
#line 223 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;
    }
#line 1732 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 229 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PARAMETER_TYPE);
    }
#line 1740 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 50: /* function_body: '{' function_statements error  */
#line 241 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 1749 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 56: /* return: RETURN '(' opt_trunc_expression ')' error  */
#line 260 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1758 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* return: RETURN '(' opt_trunc_expression error  */
#line 265 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1768 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* return: RETURN opt_trunc_expression ')'  */
#line 271 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
    }
#line 1777 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* return: RETURN opt_trunc_expression error  */
#line 276 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1787 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* return: RETURN '(' opt_trunc_expression ';'  */
#line 282 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_PARENTHESIS);
    }
#line 1795 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* return: RETURN opt_trunc_expression ')' ';'  */
#line 286 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 1803 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* return: RETURN opt_trunc_expression ';'  */
#line 290 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);
    }
#line 1811 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 69: /* assignment: variable ASSIGN_OP opt_trunc_expression ';'  */
#line 308 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("ASSIGNMENT");
    }
#line 1819 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* assignment: variable ASSIGN_OP opt_trunc_expression error  */
#line 312 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1828 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* print: PRINT '(' STRING_LITERAL ')' ';'  */
#line 320 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1836 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* print: PRINT '(' STRING_LITERAL ')' error  */
#line 324 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1845 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 73: /* print: PRINT '(' opt_trunc_expression ')' ';'  */
#line 329 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1853 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 74: /* print: PRINT '(' opt_trunc_expression ')' error  */
#line 333 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1862 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* print: PRINT '(' ')' ';'  */
#line 338 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_ARGUMENT);
    }
#line 1870 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* print: PRINT '(' ')' error  */
#line 342 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_ARGUMENT);
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1880 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 77: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 354 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("MULTIPLE ASSIGNMENT");
    }
#line 1888 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 78: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 358 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1897 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 79: /* multiple_assignments: variable assignment_list ';'  */
#line 363 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_RIGHT_SIDE_VALUES);
    }
#line 1905 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 82: /* $@3: %empty  */
#line 372 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 1914 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 84: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 377 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1922 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* $@4: %empty  */
#line 386 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1930 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* invocation: function_invocation error  */
#line 396 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1939 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 92: /* invocation: lambda_invocation error  */
#line 402 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1948 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 93: /* function_invocation: IDENTIFIER '(' real_parameter_list ')'  */
#line 410 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION INVOCATION");
    }
#line 1956 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 94: /* function_invocation: IDENTIFIER '(' error ')'  */
#line 414 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 1965 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* $@5: %empty  */
#line 424 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1973 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 100: /* real_parameter: opt_trunc_expression error  */
#line 432 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 1982 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 442 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("LAMBDA");
    }
#line 1990 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 446 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1998 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 103: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '(' lambda_real_parameter ')'  */
#line 450 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 2006 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 104: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '(' lambda_real_parameter ')'  */
#line 454 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_BRACKETS);
    }
#line 2014 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 107: /* if: IF condition executable_body ENDIF ';'  */
#line 468 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF");
    }
#line 2022 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* if: IF condition executable_body ENDIF error  */
#line 472 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2031 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* if: IF condition executable_body ELSE executable_body ENDIF ';'  */
#line 477 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF-ELSE");
    }
#line 2039 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* if: IF condition executable_body ELSE executable_body ENDIF error  */
#line 481 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2048 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* if: IF condition executable_body error  */
#line 486 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2057 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 112: /* if: IF condition executable_body ELSE executable_body error  */
#line 491 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2066 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 113: /* if: IF condition error ENDIF ';'  */
#line 496 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2075 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 114: /* if: IF condition error ';'  */
#line 501 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2085 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 115: /* if: IF condition error ELSE ENDIF ';'  */
#line 507 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2094 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 116: /* if: IF condition error ELSE ';'  */
#line 512 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2104 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 117: /* if: IF condition executable_body ELSE error ENDIF ';'  */
#line 518 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2113 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 118: /* if: IF condition executable_body ELSE error ';'  */
#line 523 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2123 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* if: ELSE executable_body ENDIF ';'  */
#line 529 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;
    }
#line 2132 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 121: /* executable_body: '{' executable_statements error ';'  */
#line 538 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 2141 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 125: /* control_stmt: DO executable_body WHILE condition ';'  */
#line 554 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("DO-WHILE");
    }
#line 2149 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* control_stmt: DO executable_body WHILE condition error  */
#line 558 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2158 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* control_stmt: DO executable_body condition ';'  */
#line 563 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE);
    }
#line 2166 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* control_stmt: DO executable_body condition error  */
#line 567 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE);
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2176 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 129: /* control_stmt: DO WHILE condition ';'  */
#line 573 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
    }
#line 2184 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* control_stmt: DO WHILE condition error  */
#line 577 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2194 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* opt_trunc_constant: TRUNC '(' numeric_constant error  */
#line 590 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2203 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 134: /* opt_trunc_constant: TRUNC numeric_constant ')'  */
#line 595 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2211 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 135: /* opt_trunc_constant: TRUNC numeric_constant error  */
#line 599 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2220 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* opt_trunc_variable: TRUNC '(' variable error  */
#line 609 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2229 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 139: /* opt_trunc_variable: TRUNC variable ')'  */
#line 614 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2237 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 140: /* opt_trunc_variable: TRUNC variable error  */
#line 618 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2246 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* opt_trunc_expression: TRUNC '(' expression error  */
#line 628 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2255 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* opt_trunc_expression: TRUNC expression ')'  */
#line 633 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2263 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* opt_trunc_expression: TRUNC expression error  */
#line 637 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2272 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 147: /* condition: '(' comparison error  */
#line 648 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2281 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 148: /* condition: comparison ')'  */
#line 653 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2289 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* condition: comparison error  */
#line 657 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    }
#line 2298 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* comparison: opt_trunc_expression error  */
#line 666 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;
    }
#line 2307 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 161: /* $@6: %empty  */
#line 686 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 2315 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 163: /* expression: expression '+' error  */
#line 690 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2324 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 164: /* expression: expression '-' error  */
#line 695 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2333 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 165: /* expression: '+' term  */
#line 700 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2341 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* expression: '+' error  */
#line 704 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_OPERANDS);
        yyerrok;
    }
#line 2350 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* positive_term: positive_term '*' error  */
#line 720 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2359 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* positive_term: positive_term '/' error  */
#line 725 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2368 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* negative_term: negative_term '*' error  */
#line 736 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2377 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 178: /* negative_term: negative_term '/' error  */
#line 741 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2386 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 179: /* negative_term: '*' factor  */
#line 746 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_FACTOR);
    }
#line 2394 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 180: /* negative_term: '/' factor  */
#line 750 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_FACTOR);
    }
#line 2402 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 181: /* negative_term: '*' error  */
#line 754 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2411 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 182: /* negative_term: '/' error  */
#line 759 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2420 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* negative_factor: '-' UINTEGER_LITERAL  */
#line 780 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2428 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* negative_factor: '-' function_invocation  */
#line 784 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2436 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* negative_factor: '-' variable  */
#line 788 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2444 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* negative_factor: '-' lambda_invocation  */
#line 792 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2452 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 194: /* negative_factor: '-' error  */
#line 796 "include/syntax-analyzer/components/yacc.y"
    {
        if (yychar != '-')
            specifySyntaxError(MISSING_LEFT_OPERAND);
        else
            specifySyntaxError(MISSING_FLOAT_CONSTANT);
        yyerrok;
    }
#line 2464 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 199: /* negative_constant: '-' FLOAT_LITERAL  */
#line 817 "include/syntax-analyzer/components/yacc.y"
    {
        addNegativeFloatToTable();
    }
#line 2472 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 2476 "src/syntax-analyzer/components/parser.cpp"

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

#line 827 "include/syntax-analyzer/components/yacc.y"


void yyerror(const char* s)
{
    announceSyntaxError();
}
