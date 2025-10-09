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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   787

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  194
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  328

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
       0,    59,    59,    60,    64,    68,    72,    76,    77,    81,
      86,    91,    99,   103,   110,   111,   115,   116,   117,   118,
     122,   126,   131,   140,   144,   149,   154,   158,   162,   172,
     173,   175,   174,   178,   186,   192,   193,   195,   194,   201,
     202,   207,   211,   212,   217,   223,   230,   234,   235,   243,
     244,   248,   249,   253,   254,   259,   269,   270,   271,   272,
     273,   274,   278,   282,   290,   294,   299,   303,   308,   312,
     324,   328,   333,   340,   341,   343,   342,   347,   353,   355,
     357,   356,   365,   366,   371,   372,   380,   384,   392,   393,
     395,   394,   401,   402,   412,   416,   420,   424,   431,   432,
     438,   442,   447,   451,   456,   461,   466,   471,   477,   482,
     488,   493,   499,   507,   508,   513,   517,   518,   524,   528,
     533,   537,   543,   547,   558,   559,   560,   565,   569,   577,
     578,   579,   584,   588,   596,   597,   598,   603,   607,   617,
     618,   623,   627,   635,   636,   644,   645,   646,   647,   648,
     649,   653,   654,   655,   657,   656,   660,   665,   670,   674,
     682,   683,   687,   688,   689,   690,   695,   703,   704,   705,
     706,   711,   716,   720,   724,   729,   737,   738,   742,   743,
     744,   748,   749,   750,   754,   758,   762,   766,   777,   778,
     782,   783,   787,   794,   795
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

#define YYPACT_NINF (-194)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-155)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     562,     2,   650,   719,   690,    32,   158,  -194,     8,   588,
    -194,   137,   465,  -194,  -194,  -194,    19,  -194,  -194,  -194,
    -194,  -194,  -194,   103,   134,  -194,  -194,   121,  -194,   750,
     168,  -194,  -194,   632,   162,   515,   366,   381,  -194,  -194,
     187,   598,    21,   583,  -194,   237,   286,  -194,  -194,  -194,
    -194,   124,   537,  -194,   220,   650,   427,   668,   628,   588,
     323,   165,   588,  -194,   494,  -194,  -194,  -194,  -194,   215,
    -194,  -194,   224,   258,   278,   147,   124,  -194,  -194,  -194,
    -194,   274,   668,   274,  -194,   283,   486,   685,   243,    43,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,   124,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,   668,   166,   313,  -194,  -194,   188,   340,   358,   390,
     398,   406,   409,  -194,   479,   298,   149,   650,   186,    55,
     301,   200,   306,   523,   311,   336,  -194,   164,  -194,   552,
    -194,  -194,  -194,   318,  -194,   278,  -194,  -194,   117,   367,
    -194,   116,  -194,  -194,   120,   274,  -194,   124,   201,   126,
    -194,   417,  -194,   330,  -194,  -194,  -194,  -194,   349,  -194,
    -194,  -194,  -194,  -194,    47,   329,  -194,  -194,   620,   207,
    -194,  -194,  -194,  -194,   237,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,   342,  -194,  -194,  -194,  -194,  -194,   216,
    -194,  -194,  -194,   230,   240,  -194,  -194,   241,  -194,  -194,
    -194,  -194,   668,   668,  -194,   352,  -194,  -194,   721,   376,
    -194,  -194,   370,   278,   278,  -194,  -194,   234,  -194,   124,
     124,    27,  -194,  -194,   559,   248,    72,   363,  -194,  -194,
     365,  -194,  -194,    79,   302,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,   537,
     228,   370,   729,   373,  -194,  -194,  -194,  -194,  -194,   378,
      76,  -194,  -194,  -194,  -194,   559,   559,  -194,   415,  -194,
    -194,   249,   749,   389,   744,   252,  -194,   327,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,   418,
     744,   436,   612,   414,  -194,  -194,   124,  -194,  -194,   424,
    -194,  -194,   436,   425,   431,   401,    94,  -194,  -194,   438,
    -194,  -194,    96,  -194,  -194,  -194,  -194,  -194
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    34,   193,     0,
      10,     0,     0,     2,     7,     4,     0,    61,     5,    56,
      60,    57,    58,     0,     0,    59,     6,     0,    11,     0,
     193,   191,   190,     0,     0,     0,     0,     0,   180,   182,
       0,     0,     0,   134,   153,   160,   161,   164,   169,   179,
     181,   178,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    14,    16,    17,    18,     0,
       1,     3,     0,   193,     0,     0,    29,    83,    82,    85,
      84,     0,     0,     0,    73,     0,     0,     0,     0,     0,
     159,   158,   187,   192,   183,   184,   186,   185,   174,   172,
     176,   177,   175,   173,   144,   145,   147,   148,   146,   149,
     150,     0,     0,     0,   142,   141,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    88,     0,    22,     0,
       9,     8,    15,     0,    24,     0,    46,    41,     0,    37,
      35,     0,    25,    23,     0,     0,   193,    75,     0,     0,
     194,     0,    72,     0,    78,   124,   188,   189,     0,   138,
     137,   140,   139,   143,     0,     0,   107,   104,     0,     0,
     156,   151,   157,   152,   155,   165,   162,   166,   163,   170,
     167,   171,   168,     0,   113,   117,   112,   123,   122,     0,
     121,   120,    55,     0,     0,    69,    68,     0,    13,    12,
      87,    86,     0,     0,    93,     0,    21,    20,     0,    37,
      40,    39,     0,     0,     0,    44,    45,     0,    33,    30,
      32,     0,    63,    62,     0,     0,     0,     0,   136,   135,
       0,   109,   106,     0,     0,   101,   100,   114,   119,   118,
      54,    53,    65,    64,    67,    66,    89,    91,    92,     0,
       0,     0,     0,     0,    36,    38,    43,    42,    76,    77,
       0,   128,   127,    71,    70,     0,     0,   108,     0,   111,
     105,     0,     0,     0,     0,     0,    51,     0,    49,    52,
      27,    74,   126,   125,    79,    81,   110,   103,   102,     0,
       0,     0,     0,     0,    99,    98,   129,    28,    26,     0,
      47,    50,     0,     0,     0,     0,     0,    97,    48,     0,
      96,    95,     0,   133,   132,    94,   131,   130
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,  -194,   441,    11,   -41,   -45,     1,  -194,  -194,    -9,
     328,  -194,   119,  -194,   195,  -194,   181,  -194,    51,  -194,
    -194,  -194,  -149,  -194,  -194,  -194,  -194,    34,  -194,  -194,
     202,    67,    -3,  -194,     4,  -193,    87,   -81,  -194,   -43,
      -7,   443,  -194,    13,  -194,   -27,   360,  -194,    24,   -10,
      -6,  -155,   -54,     5,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    12,    13,    63,    64,    65,    66,    75,   155,    16,
     149,   224,   150,   151,   263,   287,   288,    17,    67,    19,
      20,    21,    86,   231,   237,   276,    22,    38,   135,   213,
     136,    39,   303,    25,    54,   124,    68,   304,   305,    40,
      41,    42,   111,    43,   118,    44,    45,    46,    99,    47,
      48,   165,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    15,    69,    27,    27,   164,   236,    91,    56,    27,
     234,    14,    27,    15,   129,   132,    76,   137,   133,   142,
      72,   139,   114,    14,    69,   260,   100,   100,    81,    28,
     101,   101,   166,    59,    23,    97,    60,    23,    23,   158,
      73,    27,    88,    23,   171,   113,    23,    74,   126,   128,
     115,    18,    27,   240,    53,    53,   202,    83,    84,    27,
      57,   103,    27,    18,    27,   148,   282,    24,   173,    95,
      24,    24,   172,   271,   241,    23,    24,   292,    69,    24,
     270,   157,   268,   159,   203,   278,    23,    26,   142,   181,
     183,   167,    53,    23,   142,   323,    23,   326,    23,    26,
     168,   272,    96,   123,    77,   293,   279,   166,    24,   100,
     100,   100,   100,   101,   101,   101,   101,   225,   220,    24,
     199,   228,    81,   324,    27,   327,    24,    81,     7,    24,
      78,    24,    85,    27,    85,    79,   148,   226,   221,    27,
      82,   156,   227,   186,   188,   190,   192,   236,   152,     7,
     197,    83,    84,   269,   229,   230,    83,    84,    23,    85,
     270,    80,    85,    90,    85,   214,   167,    23,   -31,   137,
     137,   174,   175,    23,   153,   195,   198,   154,    27,   215,
     166,   166,   244,    30,    31,    32,    58,   200,   104,   180,
      11,    24,   138,   176,   294,   295,    60,    35,    36,    37,
      24,   205,   232,   105,   106,   107,    24,   108,   245,    30,
      31,    32,    23,   201,   148,   148,    11,   248,    27,   109,
     110,   166,   166,    35,    36,    37,   125,   206,   233,    53,
     166,   250,     2,     3,   246,   266,   143,     5,     6,   167,
     167,   252,   254,   249,   169,    24,   166,   166,   166,    30,
     297,   144,    23,   307,   283,   267,   284,   251,   166,    27,
      27,   166,    27,   286,  -154,  -154,  -154,   253,   255,   123,
      31,    32,   170,   119,   120,    69,   298,   116,   117,   308,
     167,   167,    27,   163,   306,    24,   145,    27,   286,   167,
       7,    69,   146,    23,    23,   156,    23,   313,   314,   147,
     306,   306,   316,   280,   160,   167,   167,   167,   281,   319,
     123,   195,   306,   289,   177,   322,    23,   167,   178,   179,
     167,    23,   121,   122,   134,   196,    24,    24,   309,    24,
     204,     2,     3,   195,    29,   207,     5,     6,   289,     7,
     210,   182,   264,   265,    30,    31,    32,   218,    30,    24,
     238,    11,    93,   310,    24,    11,   242,    34,    35,    36,
      37,    30,    31,    32,   273,   211,   212,    98,    11,   247,
    -154,  -154,  -154,   258,   -80,    35,    36,    37,   239,    30,
      31,    32,   102,   116,   117,   -80,   -80,    30,    31,    32,
     274,   185,   277,   275,    11,   262,   222,   223,   -80,   187,
     290,    35,    30,    31,    32,   261,   223,   189,   291,    11,
     191,    30,    31,    32,   256,   257,    35,   301,    11,    30,
      31,    32,   156,    31,    32,    35,    11,    30,    31,    32,
      30,    31,    32,    35,    11,   127,   163,    11,    29,    31,
      32,    35,   296,   317,    35,   235,   312,   302,    30,    31,
      32,   318,   163,    71,   320,    33,   285,   156,    31,    32,
     321,    34,    35,    36,    37,    70,     1,   325,   311,     2,
       3,   163,     4,   219,     5,     6,    89,     7,   184,     0,
     193,     0,     0,     2,     3,     0,     8,     0,     5,     6,
       9,    10,     0,    11,   140,    61,     0,   161,     2,     3,
      30,     4,     0,     5,     6,   194,     7,    11,    31,    32,
       0,     0,     0,   162,     0,     8,    92,     0,     0,    62,
     141,   163,    11,   208,    61,     0,     0,     2,     3,     0,
       4,     0,     5,     6,     0,     7,    30,    93,    94,     0,
       0,     2,     3,    11,     8,     0,     5,     6,    62,   209,
       0,    11,   216,    61,     0,     0,     2,     3,    30,     4,
       0,     5,     6,     1,     7,    11,     2,     3,     0,     4,
     161,     5,     6,     8,     7,     0,     0,    62,   217,     0,
      11,    31,    32,     8,     0,     0,     0,     9,    10,    61,
      11,     0,     2,     3,   163,     4,     0,     5,     6,   112,
       7,     0,     2,     3,  -154,  -154,  -154,     5,     6,     8,
       0,     0,     0,    62,     0,     0,    11,   116,   117,    30,
       0,   243,     0,    52,     2,     3,    11,     0,     0,     5,
       6,     0,     0,   156,    31,    32,     0,     0,     0,    29,
     315,    30,     0,    29,     7,    52,     0,   163,    11,    30,
      31,    32,   130,    30,    31,    32,    11,   131,     0,     0,
      11,    29,    34,    35,    36,    37,    34,    35,    36,    37,
       0,    30,    31,    32,     0,     0,     0,     0,    33,    29,
       0,     0,     0,     0,    34,    35,    36,    37,     0,    30,
      31,    32,     0,     0,     2,     3,    11,     7,    55,     5,
       6,     0,    34,    35,    36,    37,    30,    31,    32,     0,
       0,    30,     0,    11,     0,    52,     0,     0,    11,    34,
      35,    36,    37,     2,     3,     2,     3,     0,     5,     6,
       5,     6,     0,     2,     3,     0,     0,     0,     5,     6,
      30,     7,    30,     0,    52,     0,   259,    11,     0,    11,
      30,     0,     0,     2,     3,   302,     7,    11,     5,     6,
       0,     0,     0,     0,     0,   156,    31,    32,     0,     0,
      30,    30,    31,    32,     0,   299,     0,   300,    87,   163,
       0,     0,     0,     0,    34,    35,    36,    37
};

static const yytype_int16 yycheck[] =
{
       0,     0,    11,     3,     4,    86,   161,    34,     4,     9,
     159,     0,    12,    12,    57,    58,    16,    60,    59,    64,
       1,    62,     1,    12,    33,   218,    36,    37,     1,    27,
      36,    37,    86,    25,     0,    35,    28,     3,     4,    82,
      21,    41,    29,     9,     1,    41,    12,    28,    55,    56,
      29,     0,    52,     6,     3,     4,     1,    30,    31,    59,
      28,    37,    62,    12,    64,    74,   259,     0,   111,    35,
       3,     4,    29,     1,    27,    41,     9,     1,    87,    12,
     235,    81,   231,    83,    29,     6,    52,     0,   133,   116,
     117,    86,    41,    59,   139,     1,    62,     1,    64,    12,
      87,    29,    35,    52,     1,    29,    27,   161,    41,   119,
     120,   121,   122,   119,   120,   121,   122,     1,     1,    52,
     127,     1,     1,    29,   124,    29,    59,     1,    12,    62,
      27,    64,    38,   133,    38,     1,   145,    21,    21,   139,
      19,    21,   151,   119,   120,   121,   122,   302,     1,    12,
       1,    30,    31,   234,   154,   155,    30,    31,   124,    38,
     315,    27,    38,     1,    38,     1,   161,   133,    21,   212,
     213,     5,     6,   139,    27,   124,    27,    30,   178,    15,
     234,   235,   178,    21,    22,    23,    28,     1,     1,     1,
      28,   124,    27,    27,   275,   276,    28,    35,    36,    37,
     133,     1,     1,    16,    17,    18,   139,    20,     1,    21,
      22,    23,   178,    27,   223,   224,    28,     1,   218,    32,
      33,   275,   276,    35,    36,    37,     6,    27,    27,   178,
     284,     1,     4,     5,    27,     1,    21,     9,    10,   234,
     235,     1,     1,    27,     1,   178,   300,   301,   302,    21,
       1,    27,   218,     1,    26,    21,    28,    27,   312,   259,
     260,   315,   262,   262,    21,    22,    23,    27,    27,   218,
      22,    23,    29,    36,    37,   284,    27,    34,    35,    27,
     275,   276,   282,    35,   284,   218,    28,   287,   287,   284,
      12,   300,    14,   259,   260,    21,   262,   300,   301,    21,
     300,   301,   302,     1,    21,   300,   301,   302,     6,   312,
     259,   260,   312,   262,     1,   315,   282,   312,     5,     6,
     315,   287,    36,    37,     1,    27,   259,   260,     1,   262,
      29,     4,     5,   282,    11,    29,     9,    10,   287,    12,
      29,     1,   223,   224,    21,    22,    23,    29,    21,   282,
       1,    28,    22,    26,   287,    28,    27,    34,    35,    36,
      37,    21,    22,    23,     1,    29,    30,     1,    28,    27,
      21,    22,    23,    21,    11,    35,    36,    37,    29,    21,
      22,    23,     1,    34,    35,    22,    23,    21,    22,    23,
      27,     1,    27,    30,    28,    25,    29,    30,    35,     1,
      27,    35,    21,    22,    23,    29,    30,     1,    30,    28,
       1,    21,    22,    23,   212,   213,    35,    28,    28,    21,
      22,    23,    21,    22,    23,    35,    28,    21,    22,    23,
      21,    22,    23,    35,    28,     8,    35,    28,    11,    22,
      23,    35,    27,    29,    35,    28,    28,    11,    21,    22,
      23,    27,    35,    12,    29,    28,   261,    21,    22,    23,
      29,    34,    35,    36,    37,     0,     1,    29,   287,     4,
       5,    35,     7,   145,     9,    10,    33,    12,   118,    -1,
       1,    -1,    -1,     4,     5,    -1,    21,    -1,     9,    10,
      25,    26,    -1,    28,     0,     1,    -1,    11,     4,     5,
      21,     7,    -1,     9,    10,    26,    12,    28,    22,    23,
      -1,    -1,    -1,    27,    -1,    21,     1,    -1,    -1,    25,
      26,    35,    28,     0,     1,    -1,    -1,     4,     5,    -1,
       7,    -1,     9,    10,    -1,    12,    21,    22,    23,    -1,
      -1,     4,     5,    28,    21,    -1,     9,    10,    25,    26,
      -1,    28,     0,     1,    -1,    -1,     4,     5,    21,     7,
      -1,     9,    10,     1,    12,    28,     4,     5,    -1,     7,
      11,     9,    10,    21,    12,    -1,    -1,    25,    26,    -1,
      28,    22,    23,    21,    -1,    -1,    -1,    25,    26,     1,
      28,    -1,     4,     5,    35,     7,    -1,     9,    10,     1,
      12,    -1,     4,     5,    21,    22,    23,     9,    10,    21,
      -1,    -1,    -1,    25,    -1,    -1,    28,    34,    35,    21,
      -1,     1,    -1,    25,     4,     5,    28,    -1,    -1,     9,
      10,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    11,
      28,    21,    -1,    11,    12,    25,    -1,    35,    28,    21,
      22,    23,    24,    21,    22,    23,    28,    29,    -1,    -1,
      28,    11,    34,    35,    36,    37,    34,    35,    36,    37,
      -1,    21,    22,    23,    -1,    -1,    -1,    -1,    28,    11,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    -1,    21,
      22,    23,    -1,    -1,     4,     5,    28,    12,     8,     9,
      10,    -1,    34,    35,    36,    37,    21,    22,    23,    -1,
      -1,    21,    -1,    28,    -1,    25,    -1,    -1,    28,    34,
      35,    36,    37,     4,     5,     4,     5,    -1,     9,    10,
       9,    10,    -1,     4,     5,    -1,    -1,    -1,     9,    10,
      21,    12,    21,    -1,    25,    -1,    25,    28,    -1,    28,
      21,    -1,    -1,     4,     5,    11,    12,    28,     9,    10,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,
      21,    21,    22,    23,    -1,    26,    -1,    28,    28,    35,
      -1,    -1,    -1,    -1,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     4,     5,     7,     9,    10,    12,    21,    25,
      26,    28,    40,    41,    42,    45,    48,    56,    57,    58,
      59,    60,    65,    66,    70,    72,    75,    93,    27,    11,
      21,    22,    23,    28,    34,    35,    36,    37,    66,    70,
      78,    79,    80,    82,    84,    85,    86,    88,    89,    91,
      92,    93,    25,    57,    73,     8,    73,    28,    28,    25,
      28,     1,    25,    42,    43,    44,    45,    57,    75,    48,
       0,    41,     1,    21,    28,    46,    93,     1,    27,     1,
      27,     1,    19,    30,    31,    38,    61,    28,    82,    80,
       1,    84,     1,    22,    23,    66,    70,    93,     1,    87,
      88,    89,     1,    87,     1,    16,    17,    18,    20,    32,
      33,    81,     1,    73,     1,    29,    34,    35,    83,    36,
      37,    36,    37,    57,    74,     6,    79,     8,    79,    78,
      24,    29,    78,    43,     1,    67,    69,    78,    27,    43,
       0,    26,    44,    21,    27,    28,    14,    21,    48,    49,
      51,    52,     1,    27,    30,    47,    21,    93,    78,    93,
      21,    11,    27,    35,    76,    90,    91,    92,    82,     1,
      29,     1,    29,    78,     5,     6,    27,     1,     5,     6,
       1,    84,     1,    84,    85,     1,    87,     1,    87,     1,
      87,     1,    87,     1,    26,    57,    27,     1,    27,    79,
       1,    27,     1,    29,    29,     1,    27,    29,     0,    26,
      29,    29,    30,    68,     1,    15,     0,    26,    29,    49,
       1,    21,    29,    30,    50,     1,    21,    48,     1,    93,
      93,    62,     1,    27,    61,    28,    90,    63,     1,    29,
       6,    27,    27,     1,    73,     1,    27,    27,     1,    27,
       1,    27,     1,    27,     1,    27,    69,    69,    21,    25,
      74,    29,    25,    53,    51,    51,     1,    21,    61,    76,
      90,     1,    29,     1,    27,    30,    64,    27,     6,    27,
       1,     6,    74,    26,    28,    53,    45,    54,    55,    57,
      27,    30,     1,    29,    76,    76,    27,     1,    27,    26,
      28,    28,    11,    71,    76,    77,    93,     1,    27,     1,
      26,    55,    28,    71,    71,    28,    93,    29,    27,    71,
      29,    29,    93,     1,    29,    29,     1,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    41,    41,    41,    41,
      41,    41,    42,    42,    43,    43,    44,    44,    44,    44,
      44,    44,    44,    45,    45,    45,    45,    45,    45,    46,
      46,    47,    46,    46,    48,    49,    49,    50,    49,    51,
      51,    51,    51,    51,    51,    51,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      60,    60,    60,    61,    61,    62,    61,    61,    63,    63,
      64,    63,    65,    65,    65,    65,    66,    66,    67,    67,
      68,    67,    69,    69,    70,    70,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    74,    74,    75,    75,
      75,    75,    75,    75,    76,    76,    76,    76,    76,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    83,    82,    82,    82,    82,    82,
      84,    84,    85,    85,    85,    85,    85,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    87,    87,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    92,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       1,     2,     4,     4,     1,     2,     1,     1,     1,     1,
       3,     3,     2,     3,     3,     3,     7,     6,     7,     1,
       3,     0,     3,     3,     1,     1,     3,     0,     3,     2,
       2,     1,     3,     3,     2,     2,     1,     3,     4,     1,
       2,     1,     1,     5,     5,     4,     1,     1,     1,     1,
       1,     1,     4,     4,     5,     5,     5,     5,     4,     4,
       5,     5,     3,     1,     5,     0,     4,     4,     0,     3,
       0,     3,     2,     2,     2,     2,     4,     4,     1,     3,
       0,     3,     3,     2,    10,     9,     9,     8,     1,     1,
       5,     5,     7,     7,     4,     6,     5,     4,     6,     5,
       7,     6,     4,     3,     4,     1,     1,     2,     5,     5,
       4,     4,     4,     4,     1,     4,     4,     3,     3,     1,
       4,     4,     3,     3,     1,     4,     4,     3,     3,     3,
       3,     2,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     0,     3,     3,     3,     2,     2,
       1,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     1,     3
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
  case 4: /* global_statement: declarative_stmt  */
#line 65 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1490 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 5: /* global_statement: executable_stmt  */
#line 69 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1498 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: control_stmt  */
#line 73 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1506 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 8: /* global_statement: '{' program_statements '}'  */
#line 78 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
    }
#line 1514 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 9: /* global_statement: '{' program_statements $end  */
#line 82 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1523 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '}'  */
#line 87 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1532 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: error ';'  */
#line 92 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1541 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* program: IDENTIFIER '{' program_statements '}'  */
#line 100 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PROGRAM");
    }
#line 1549 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* program: IDENTIFIER '{' program_statements $end  */
#line 104 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1557 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 19: /* program_statement: program  */
#line 119 "include/syntax-analyzer/components/yacc.y"
    {
       announceSpecificError(INVALID_PROGRAM_NESTING);
    }
#line 1565 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statement: '{' program_statements '}'  */
#line 123 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1573 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statement: '{' program_statements $end  */
#line 127 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1582 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: error ';'  */
#line 132 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1590 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* declarative_stmt: type variable_list ';'  */
#line 141 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("VARIABLE DECLARATION");
    }
#line 1598 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* declarative_stmt: type error ';'  */
#line 145 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1607 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* declarative_stmt: type variable_list error  */
#line 150 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1616 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body ';'  */
#line 155 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION DECLARATION");
    }
#line 1624 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* declarative_stmt: type '(' formal_parameter_list ')' function_body ';'  */
#line 159 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_FUNCTION_NAME);
    }
#line 1632 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body error  */
#line 163 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1641 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 31: /* $@1: %empty  */
#line 175 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1649 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 33: /* variable_list: variable_list ',' error  */
#line 179 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1658 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* $@2: %empty  */
#line 195 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1666 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* formal_parameter: type error  */
#line 203 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1675 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* formal_parameter: IDENTIFIER  */
#line 208 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PARAMETER_TYPE);
    }
#line 1683 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* formal_parameter: parameter_semantics type error  */
#line 213 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1692 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 44: /* formal_parameter: parameter_semantics error  */
#line 218 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;
    }
#line 1702 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 224 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PARAMETER_TYPE);
    }
#line 1710 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 48: /* function_body: '{' function_statements error ';'  */
#line 236 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 1719 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 54: /* return: RETURN '(' opt_trunc_expression ')' error  */
#line 255 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1728 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* return: RETURN '(' opt_trunc_expression error  */
#line 260 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 1737 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* assignment: variable ASSIGN_OP opt_trunc_expression ';'  */
#line 279 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("ASSIGNMENT");
    }
#line 1745 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* assignment: variable ASSIGN_OP opt_trunc_expression error  */
#line 283 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1754 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* print: PRINT '(' STRING_LITERAL ')' ';'  */
#line 291 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1762 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 65: /* print: PRINT '(' STRING_LITERAL ')' error  */
#line 295 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1771 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 66: /* print: PRINT '(' opt_trunc_expression ')' ';'  */
#line 300 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1779 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 67: /* print: PRINT '(' opt_trunc_expression ')' error  */
#line 304 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1788 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 68: /* print: PRINT '(' ')' ';'  */
#line 309 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_ARGUMENT);
    }
#line 1796 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 69: /* print: PRINT '(' ')' error  */
#line 313 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_ARGUMENT);
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1806 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 325 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("MULTIPLE ASSIGNMENT");
    }
#line 1814 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 329 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1823 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* multiple_assignments: variable assignment_list ';'  */
#line 334 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_RIGHT_SIDE_VALUES);
    }
#line 1831 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* $@3: %empty  */
#line 343 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 1840 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 77: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 348 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1848 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 80: /* $@4: %empty  */
#line 357 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1856 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* invocation: function_invocation error  */
#line 367 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1865 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 85: /* invocation: lambda_invocation error  */
#line 373 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1874 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 86: /* function_invocation: IDENTIFIER '(' real_parameter_list ')'  */
#line 381 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION INVOCATION");
    }
#line 1882 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* function_invocation: IDENTIFIER '(' error ')'  */
#line 385 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 1891 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* $@5: %empty  */
#line 395 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1899 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 93: /* real_parameter: opt_trunc_expression error  */
#line 403 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 1908 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 94: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 413 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("LAMBDA");
    }
#line 1916 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 417 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1924 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '(' lambda_real_parameter ')'  */
#line 421 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1932 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '(' lambda_real_parameter ')'  */
#line 425 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_BRACKETS);
    }
#line 1940 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 100: /* if: IF condition executable_body ENDIF ';'  */
#line 439 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF");
    }
#line 1948 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* if: IF condition executable_body ENDIF error  */
#line 443 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1957 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* if: IF condition executable_body ELSE executable_body ENDIF ';'  */
#line 448 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF-ELSE");
    }
#line 1965 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 103: /* if: IF condition executable_body ELSE executable_body ENDIF error  */
#line 452 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1974 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 104: /* if: IF condition executable_body error  */
#line 457 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 1983 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 105: /* if: IF condition executable_body ELSE executable_body error  */
#line 462 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 1992 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 106: /* if: IF condition error ENDIF ';'  */
#line 467 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2001 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 107: /* if: IF condition error ';'  */
#line 472 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2011 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* if: IF condition error ELSE ENDIF ';'  */
#line 478 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2020 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* if: IF condition error ELSE ';'  */
#line 483 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2030 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* if: IF condition executable_body ELSE error ENDIF ';'  */
#line 489 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2039 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* if: IF condition executable_body ELSE error ';'  */
#line 494 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2049 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 112: /* if: ELSE executable_body ENDIF ';'  */
#line 500 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;
    }
#line 2058 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 114: /* executable_body: '{' executable_statements error ';'  */
#line 509 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 2067 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 118: /* control_stmt: DO executable_body WHILE condition ';'  */
#line 525 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("DO-WHILE");
    }
#line 2075 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* control_stmt: DO executable_body WHILE condition error  */
#line 529 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2084 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* control_stmt: DO executable_body condition ';'  */
#line 534 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE);
    }
#line 2092 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 121: /* control_stmt: DO executable_body condition error  */
#line 538 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE);
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2102 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* control_stmt: DO WHILE condition ';'  */
#line 544 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
    }
#line 2110 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* control_stmt: DO WHILE condition error  */
#line 548 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2120 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* opt_trunc_constant: TRUNC '(' numeric_constant error  */
#line 561 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2129 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* opt_trunc_constant: TRUNC numeric_constant ')'  */
#line 566 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2137 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* opt_trunc_constant: TRUNC numeric_constant error  */
#line 570 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2146 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 131: /* opt_trunc_variable: TRUNC '(' variable error  */
#line 580 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2155 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 132: /* opt_trunc_variable: TRUNC variable ')'  */
#line 585 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2163 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* opt_trunc_variable: TRUNC variable error  */
#line 589 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2172 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 136: /* opt_trunc_expression: TRUNC '(' expression error  */
#line 599 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2181 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 137: /* opt_trunc_expression: TRUNC expression ')'  */
#line 604 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2189 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* opt_trunc_expression: TRUNC expression error  */
#line 608 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2198 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 140: /* condition: '(' comparison error  */
#line 619 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2207 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* condition: comparison ')'  */
#line 624 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2215 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 142: /* condition: comparison error  */
#line 628 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    }
#line 2224 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* comparison: opt_trunc_expression error  */
#line 637 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;
    }
#line 2233 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 154: /* $@6: %empty  */
#line 657 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 2241 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* expression: expression '+' error  */
#line 661 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2250 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 157: /* expression: expression '-' error  */
#line 666 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2259 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* expression: '+' term  */
#line 671 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2267 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 159: /* expression: '+' error  */
#line 675 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_OPERANDS);
        yyerrok;
    }
#line 2276 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 165: /* positive_term: positive_term '*' error  */
#line 691 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2285 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* positive_term: positive_term '/' error  */
#line 696 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2294 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 170: /* negative_term: negative_term '*' error  */
#line 707 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2303 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 171: /* negative_term: negative_term '/' error  */
#line 712 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2312 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* negative_term: '*' factor  */
#line 717 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_FACTOR);
    }
#line 2320 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* negative_term: '/' factor  */
#line 721 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_FACTOR);
    }
#line 2328 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* negative_term: '*' error  */
#line 725 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2337 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* negative_term: '/' error  */
#line 730 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2346 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* negative_factor: '-' UINTEGER_LITERAL  */
#line 751 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2354 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* negative_factor: '-' function_invocation  */
#line 755 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2362 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 185: /* negative_factor: '-' variable  */
#line 759 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2370 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 186: /* negative_factor: '-' lambda_invocation  */
#line 763 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_OPERAND);
    }
#line 2378 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 187: /* negative_factor: '-' error  */
#line 767 "include/syntax-analyzer/components/yacc.y"
    {
        if (yychar != '-')
            specifySyntaxError(MISSING_LEFT_OPERAND);
        else
            specifySyntaxError(MISSING_FLOAT_CONSTANT);
        yyerrok;
    }
#line 2390 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* negative_constant: '-' FLOAT_LITERAL  */
#line 788 "include/syntax-analyzer/components/yacc.y"
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

#line 798 "include/syntax-analyzer/components/yacc.y"


void yyerror(const char* s)
{
    announceSyntaxError();
}
