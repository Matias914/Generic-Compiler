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
  YYSYMBOL_assignment_end = 65,            /* assignment_end  */
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
#define YYLAST   820

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  349

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
       0,    61,    61,    62,    63,    67,    71,    75,    79,    80,
      84,    89,    93,   101,   105,   112,   113,   117,   118,   119,
     120,   124,   128,   133,   142,   146,   151,   156,   160,   164,
     169,   179,   180,   182,   181,   185,   193,   194,   203,   204,
     206,   205,   212,   213,   218,   222,   223,   228,   234,   241,
     245,   246,   254,   255,   259,   260,   264,   265,   270,   276,
     281,   287,   291,   295,   304,   305,   306,   307,   308,   309,
     313,   317,   325,   329,   334,   338,   344,   343,   352,   354,
     363,   367,   372,   376,   382,   390,   391,   392,   397,   396,
     400,   404,   411,   412,   419,   421,   423,   422,   431,   432,
     437,   438,   446,   450,   458,   459,   461,   460,   467,   468,
     478,   482,   486,   490,   497,   498,   504,   508,   513,   517,
     522,   527,   532,   537,   543,   548,   554,   559,   565,   573,
     574,   579,   583,   584,   590,   594,   600,   599,   605,   604,
     612,   613,   623,   624,   625,   630,   634,   642,   643,   644,
     649,   653,   661,   662,   663,   668,   672,   682,   683,   688,
     692,   700,   701,   709,   710,   711,   712,   713,   714,   718,
     719,   720,   722,   721,   725,   730,   735,   739,   747,   748,
     752,   753,   754,   755,   760,   768,   769,   770,   771,   776,
     781,   785,   789,   794,   802,   803,   807,   808,   809,   813,
     814,   815,   819,   823,   827,   831,   839,   840,   844,   845,
     849,   856,   857
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
  "assignment_end", "extra_numeric_constants", "$@5", "invocation",
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

#define YYPACT_NINF (-220)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-173)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     470,  -220,   -10,   679,   752,   752,   683,    35,  -220,  -220,
     282,   596,  -220,    13,   499,  -220,  -220,  -220,   144,  -220,
    -220,  -220,  -220,  -220,  -220,    57,    70,  -220,  -220,    51,
    -220,   782,    80,  -220,  -220,   661,   179,   441,   298,   376,
    -220,  -220,   440,   628,    22,   496,  -220,   451,   485,  -220,
    -220,  -220,  -220,    -4,   334,  -220,   133,    33,   150,   661,
      28,   175,   596,   258,   162,   596,  -220,   528,  -220,  -220,
    -220,  -220,   185,  -220,  -220,   186,   191,   472,   203,    -4,
    -220,  -220,  -220,  -220,   210,   701,  -220,   232,  -220,   234,
     401,   718,   222,    59,  -220,  -220,  -220,  -220,  -220,  -220,
    -220,    -4,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,  -220,  -220,  -220,   701,   462,   444,  -220,  -220,
     328,   331,   319,   387,   412,   416,   431,  -220,   650,   221,
     679,   679,   679,    75,  -220,  -220,   233,   242,   254,   272,
     557,   284,   486,  -220,    99,  -220,   586,  -220,  -220,  -220,
     306,  -220,   472,  -220,  -220,    18,   513,  -220,   277,  -220,
    -220,   106,   232,  -220,   115,   354,  -220,   122,  -220,  -220,
     479,  -220,   305,  -220,  -220,  -220,  -220,   357,  -220,  -220,
    -220,  -220,  -220,   211,   345,  -220,  -220,   660,   129,  -220,
    -220,  -220,  -220,   451,  -220,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,   362,  -220,  -220,  -220,   168,  -220,   178,  -220,
    -220,  -220,   193,  -220,  -220,   207,   225,  -220,  -220,  -220,
    -220,   701,   701,  -220,   384,  -220,  -220,   760,   521,  -220,
    -220,   382,   472,   472,  -220,  -220,   153,  -220,    -4,    -4,
    -220,  -220,   274,   274,    68,    -7,    82,   360,  -220,  -220,
     389,  -220,  -220,   219,   172,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,  -220,  -220,   391,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,   334,   682,   382,   738,   227,  -220,  -220,  -220,
    -220,  -220,    26,   390,  -220,   395,   108,  -220,  -220,  -220,
    -220,   274,   274,  -220,   400,  -220,  -220,   249,  -220,  -220,
     774,   386,   785,   260,  -220,   618,  -220,  -220,  -220,  -220,
    -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,
    -220,   418,   785,   408,   524,   419,  -220,  -220,    -4,  -220,
    -220,  -220,  -220,  -220,   408,   426,   432,   295,    11,  -220,
     436,  -220,  -220,    21,  -220,  -220,  -220,  -220,  -220
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
      99,    98,   101,   100,     0,     0,    88,     0,    85,     0,
       0,     0,     0,     0,   177,   176,   205,   210,   201,   202,
     204,   203,   192,   190,   194,   195,   193,   191,   162,   163,
     165,   166,   164,   167,   168,     0,     0,     0,   160,   159,
       0,     0,     0,     0,     0,     0,     0,   132,     0,     0,
       0,     0,     0,     0,    60,    63,    59,     0,     0,     0,
       0,     0,   106,   104,     0,    23,     0,    10,     9,    16,
       0,    25,     0,    49,    44,     0,    40,    38,     0,    26,
      24,     0,     0,    84,     0,     0,   211,     0,   212,    83,
       0,    82,     0,    94,   142,   206,   207,     0,   156,   155,
     158,   157,   161,     0,     0,   123,   120,     0,     0,   174,
     169,   175,   170,   173,   183,   180,   184,   181,   188,   185,
     189,   186,     0,   129,   133,   128,     0,   137,     0,   139,
      58,    61,     0,    62,    76,     0,     0,    14,    13,   103,
     102,     0,     0,   109,     0,    22,    21,     0,    40,    43,
      42,     0,     0,     0,    47,    48,     0,    35,    32,    34,
      71,    70,     0,     0,     0,     0,     0,     0,   154,   153,
       0,   125,   122,     0,     0,   117,   116,   130,   135,   134,
     141,   140,    57,    56,    79,    73,    72,    75,    74,   105,
     107,   108,     0,     0,     0,     0,     0,    39,    41,    46,
      45,    89,     0,     0,    91,    90,     0,   146,   145,    81,
      80,     0,     0,   124,     0,   127,   121,     0,    78,    77,
       0,     0,     0,     0,    54,     0,    52,    55,    30,    28,
      93,    92,    87,    86,   144,   143,    95,    97,   126,   119,
     118,     0,     0,     0,     0,     0,   115,   114,   147,    29,
      27,    51,    50,    53,     0,     0,     0,     0,     0,   113,
       0,   112,   111,     0,   151,   150,   110,   149,   148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -220,  -220,   464,   167,   338,   -54,     7,  -220,  -220,   -11,
     324,  -220,   339,  -220,   216,  -220,   176,  -220,   121,  -220,
    -220,  -220,  -220,  -220,   -43,  -220,  -220,  -220,  -220,  -220,
      31,  -220,  -220,   352,   101,    47,  -220,     1,  -219,   270,
    -220,  -220,   365,   -52,  -220,    14,     6,   457,  -220,   -30,
    -220,   -26,   372,  -220,    25,    -6,     8,  -167,   -60,    23,
       0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    14,    15,    66,    67,    68,    69,    78,   162,    18,
     156,   233,   157,   158,   276,   305,   306,    19,    70,    21,
      22,   264,   299,    23,    90,   165,   281,   247,   292,    24,
      40,   142,   222,   143,    41,   325,    27,    56,   128,    71,
     131,    58,   207,   326,   327,    42,   208,    44,   115,    45,
     122,    46,    47,    48,   103,    49,    50,   174,    51,    52,
      53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    92,    72,   246,    29,    29,    57,    17,   273,    43,
      95,    29,   344,   149,    29,    33,    34,    30,    79,   229,
      60,    17,   347,   118,    72,     8,     9,   310,   172,   134,
     175,    25,   104,   104,    89,    25,    25,   101,   173,   230,
     345,   130,    25,    29,   117,    25,   105,   105,    72,    89,
     348,   119,    84,   300,    29,   135,   311,   136,    80,    89,
     180,   177,    29,    61,   107,    29,   155,    29,    99,   284,
      85,    82,    86,   133,    25,   139,   210,   144,   286,   170,
      72,    87,    88,   287,    81,    25,   149,   167,   181,    89,
      33,    34,   149,    25,   190,   192,    25,    83,    25,   164,
     223,    26,   211,   172,   212,    26,    26,   237,    63,   314,
     175,   288,    26,   176,   224,    26,   240,   104,   104,   104,
     104,    20,   242,   243,   244,    55,    55,   166,    29,   182,
     255,   105,   105,   105,   105,    20,   206,   315,   100,   129,
      29,   155,   241,    86,    26,    75,    29,   236,   195,   197,
     199,   201,    87,    88,   279,    26,   256,   246,   132,    25,
      89,   238,   239,    26,    55,    76,    26,    16,    26,   258,
     286,    25,    77,   296,   280,   127,   137,    25,   297,   260,
      94,    16,   175,   175,   175,   175,    31,    29,   254,   145,
     282,   283,   285,   176,   262,   259,    32,    33,    34,   138,
      32,    33,    34,    13,   159,   261,   150,    13,   265,    36,
      37,    38,    39,   151,    37,    38,    39,   250,    25,   152,
     263,   155,   155,   178,   -33,   294,   267,    29,   308,    26,
     160,   175,   175,   161,   266,   144,   144,   163,   251,   316,
     317,    26,   175,  -172,  -172,  -172,   295,    26,   205,   204,
     319,   179,   268,   166,   309,   168,   120,   121,    25,   141,
     213,   329,   175,   175,   175,   176,   176,   176,   176,    31,
      28,   214,    29,    29,   175,    29,   320,   175,   234,    32,
      33,    34,   304,   215,    28,   170,    13,   330,    26,     8,
       9,    72,    36,    37,    38,    39,    33,    34,   235,   102,
      29,   216,   328,    25,    25,    29,    25,    62,    55,   172,
      63,    72,   304,   219,   176,   176,   166,    33,    34,    32,
      33,    34,   328,   328,   338,   176,    13,    97,    26,   189,
     172,    25,   191,    37,   328,   227,    25,   343,     3,     4,
      32,    33,    34,     6,     7,   176,   176,   176,   127,    32,
      33,    34,    32,    33,    34,    32,    13,   176,   248,    13,
     176,   289,    13,    37,    38,    39,    37,    38,    39,   335,
     336,   -96,   252,    26,    26,    86,    26,   106,  -172,  -172,
    -172,   340,   -96,   -96,    87,    88,   249,   290,   194,   257,
     291,   120,   121,   127,   204,   -96,   307,    32,    33,    34,
     140,    26,   169,   146,    13,   271,    26,   275,    32,    33,
      34,    37,   170,   196,   323,    13,   293,   198,   298,   324,
     312,   204,    37,    33,    34,   313,   307,   318,   171,   166,
      33,    34,   200,    32,    33,    34,   172,    32,    33,    34,
      13,   108,    96,   172,    13,   186,   334,    37,   339,   187,
     188,    37,    32,    33,    34,   341,   109,   110,   111,    13,
     112,   342,    32,    97,    98,   346,    37,   183,   184,    13,
       1,     2,   113,   114,     3,     4,   228,     5,    74,     6,
       7,   333,     8,     9,     8,     9,   153,   123,   124,   185,
     303,    10,    93,   154,   193,    11,    12,   209,    13,    73,
       2,    33,    34,     3,     4,     0,     5,   245,     6,     7,
       0,     8,     9,     0,   172,   220,   221,  -172,  -172,  -172,
      10,   125,   126,     0,    11,    12,     0,    13,   147,    64,
     120,   121,     3,     4,     0,     5,     0,     6,     7,     0,
       8,     9,   231,   232,     0,   166,    33,    34,     0,    10,
     274,   232,   337,    65,   148,     0,    13,   217,    64,   172,
       0,     3,     4,     0,     5,     0,     6,     7,     0,     8,
       9,   277,   278,   269,   270,     0,     0,     0,    10,     0,
       0,     0,    65,   218,     0,    13,   225,    64,     0,     0,
       3,     4,     0,     5,     0,     6,     7,    64,     8,     9,
       3,     4,     0,     5,     0,     6,     7,    10,     8,     9,
       0,    65,   226,     0,    13,     0,     0,    10,     0,   331,
       0,    65,     3,     4,    13,     0,     0,     6,     7,   116,
       8,     9,     3,     4,     0,     0,     0,     6,     7,    32,
       0,     0,     0,     0,   332,     0,    13,     0,     0,    32,
       0,   202,     0,    54,     3,     4,    13,     0,     0,     6,
       7,   253,     0,     0,     3,     4,     0,     0,     0,     6,
       7,    32,    31,     8,     9,     0,   203,     0,    13,     0,
       0,    32,    32,    33,    34,    54,     3,     4,    13,    13,
      31,     6,     7,     0,    31,    36,    37,    38,    39,     0,
      32,    33,    34,    32,    32,    33,    34,    35,   301,     0,
     302,    59,    31,    36,    37,    38,    39,    36,    37,    38,
      39,     0,    32,    33,    34,     0,     0,     0,     0,    13,
       8,     9,     0,     0,     0,    36,    37,    38,    39,    32,
      33,    34,     3,     4,     0,     0,    13,     6,     7,     0,
       8,     9,    36,    37,    38,    39,     3,     4,     0,    32,
       0,     6,     7,     0,     3,     4,    13,     0,     0,     6,
       7,     0,     0,    32,     0,     0,     0,    54,     3,     4,
      13,    32,     0,     6,     7,   272,     0,     0,    13,     0,
       0,     0,     0,     0,     0,    32,   324,     8,     9,     0,
     321,     0,   322,    32,    33,    34,   166,    33,    34,     0,
      91,     0,     0,     0,     0,     0,    36,    37,    38,    39,
     172
};

static const yytype_int16 yycheck[] =
{
       0,    31,    13,   170,     4,     5,     5,     0,   227,     3,
      36,    11,     1,    67,    14,    22,    23,    27,    18,     1,
       6,    14,     1,     1,    35,    12,    13,     1,    35,     1,
      90,     0,    38,    39,    38,     4,     5,    37,    90,    21,
      29,     8,    11,    43,    43,    14,    38,    39,    59,    38,
      29,    29,     1,   272,    54,    27,    30,    29,     1,    38,
       1,    91,    62,    28,    39,    65,    77,    67,    37,     1,
      19,     1,    21,    59,    43,    61,     1,    63,   245,    11,
      91,    30,    31,     1,    27,    54,   140,    87,    29,    38,
      22,    23,   146,    62,   120,   121,    65,    27,    67,    85,
       1,     0,    27,    35,    29,     4,     5,     1,    28,     1,
     170,    29,    11,    90,    15,    14,     1,   123,   124,   125,
     126,     0,   165,     1,   167,     4,     5,    21,   128,   115,
       1,   123,   124,   125,   126,    14,   130,    29,    37,     6,
     140,   152,    27,    21,    43,     1,   146,   158,   123,   124,
     125,   126,    30,    31,     1,    54,    27,   324,     8,   128,
      38,   161,   162,    62,    43,    21,    65,     0,    67,     1,
     337,   140,    28,     1,    21,    54,     1,   146,     6,     1,
       1,    14,   242,   243,   244,   245,    11,   187,   187,    27,
     242,   243,   244,   170,     1,    27,    21,    22,    23,    24,
      21,    22,    23,    28,     1,    27,    21,    28,     1,    34,
      35,    36,    37,    27,    35,    36,    37,     6,   187,    28,
      27,   232,   233,     1,    21,     6,     1,   227,     1,   128,
      27,   291,   292,    30,    27,   221,   222,    27,    27,   291,
     292,   140,   302,    21,    22,    23,    27,   146,    27,   128,
       1,    29,    27,    21,    27,    21,    34,    35,   227,     1,
      27,     1,   322,   323,   324,   242,   243,   244,   245,    11,
       0,    29,   272,   273,   334,   275,    27,   337,     1,    21,
      22,    23,   275,    29,    14,    11,    28,    27,   187,    12,
      13,   302,    34,    35,    36,    37,    22,    23,    21,     1,
     300,    29,   302,   272,   273,   305,   275,    25,   187,    35,
      28,   322,   305,    29,   291,   292,    21,    22,    23,    21,
      22,    23,   322,   323,   324,   302,    28,    22,   227,     1,
      35,   300,     1,    35,   334,    29,   305,   337,     4,     5,
      21,    22,    23,     9,    10,   322,   323,   324,   227,    21,
      22,    23,    21,    22,    23,    21,    28,   334,     1,    28,
     337,     1,    28,    35,    36,    37,    35,    36,    37,   322,
     323,    11,    27,   272,   273,    21,   275,     1,    21,    22,
      23,   334,    22,    23,    30,    31,    29,    27,     1,    27,
      30,    34,    35,   272,   273,    35,   275,    21,    22,    23,
      62,   300,     1,    65,    28,    21,   305,    25,    21,    22,
      23,    35,    11,     1,    28,    28,    27,     1,    27,    11,
      30,   300,    35,    22,    23,    30,   305,    27,    27,    21,
      22,    23,     1,    21,    22,    23,    35,    21,    22,    23,
      28,     1,     1,    35,    28,     1,    28,    35,    29,     5,
       6,    35,    21,    22,    23,    29,    16,    17,    18,    28,
      20,    29,    21,    22,    23,    29,    35,     5,     6,    28,
       0,     1,    32,    33,     4,     5,   152,     7,    14,     9,
      10,   305,    12,    13,    12,    13,    14,    36,    37,    27,
     274,    21,    35,    21,   122,    25,    26,   132,    28,     0,
       1,    22,    23,     4,     5,    -1,     7,    28,     9,    10,
      -1,    12,    13,    -1,    35,    29,    30,    21,    22,    23,
      21,    36,    37,    -1,    25,    26,    -1,    28,     0,     1,
      34,    35,     4,     5,    -1,     7,    -1,     9,    10,    -1,
      12,    13,    29,    30,    -1,    21,    22,    23,    -1,    21,
      29,    30,    28,    25,    26,    -1,    28,     0,     1,    35,
      -1,     4,     5,    -1,     7,    -1,     9,    10,    -1,    12,
      13,   232,   233,   221,   222,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    -1,    28,     0,     1,    -1,    -1,
       4,     5,    -1,     7,    -1,     9,    10,     1,    12,    13,
       4,     5,    -1,     7,    -1,     9,    10,    21,    12,    13,
      -1,    25,    26,    -1,    28,    -1,    -1,    21,    -1,     1,
      -1,    25,     4,     5,    28,    -1,    -1,     9,    10,     1,
      12,    13,     4,     5,    -1,    -1,    -1,     9,    10,    21,
      -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    -1,    21,
      -1,     1,    -1,    25,     4,     5,    28,    -1,    -1,     9,
      10,     1,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,
      10,    21,    11,    12,    13,    -1,    26,    -1,    28,    -1,
      -1,    21,    21,    22,    23,    25,     4,     5,    28,    28,
      11,     9,    10,    -1,    11,    34,    35,    36,    37,    -1,
      21,    22,    23,    21,    21,    22,    23,    28,    26,    -1,
      28,    28,    11,    34,    35,    36,    37,    34,    35,    36,
      37,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      12,    13,    -1,    -1,    -1,    34,    35,    36,    37,    21,
      22,    23,     4,     5,    -1,    -1,    28,     9,    10,    -1,
      12,    13,    34,    35,    36,    37,     4,     5,    -1,    21,
      -1,     9,    10,    -1,     4,     5,    28,    -1,    -1,     9,
      10,    -1,    -1,    21,    -1,    -1,    -1,    25,     4,     5,
      28,    21,    -1,     9,    10,    25,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    11,    12,    13,    -1,
      26,    -1,    28,    21,    22,    23,    21,    22,    23,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      35
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
       1,    27,     1,    27,     1,    19,    21,    30,    31,    38,
      63,    28,    88,    86,     1,    90,     1,    22,    23,    69,
      73,    99,     1,    93,    94,    95,     1,    93,     1,    16,
      17,    18,    20,    32,    33,    87,     1,    76,     1,    29,
      34,    35,    89,    36,    37,    36,    37,    57,    77,     6,
       8,    79,     8,    84,     1,    27,    29,     1,    24,    84,
      43,     1,    70,    72,    84,    27,    43,     0,    26,    44,
      21,    27,    28,    14,    21,    48,    49,    51,    52,     1,
      27,    30,    47,    27,    84,    64,    21,    99,    21,     1,
      11,    27,    35,    82,    96,    97,    98,    88,     1,    29,
       1,    29,    84,     5,     6,    27,     1,     5,     6,     1,
      90,     1,    90,    91,     1,    93,     1,    93,     1,    93,
       1,    93,     1,    26,    57,    27,    85,    81,    85,    81,
       1,    27,    29,    27,    29,    29,    29,     0,    26,    29,
      29,    30,    71,     1,    15,     0,    26,    29,    49,     1,
      21,    29,    30,    50,     1,    21,    48,     1,    99,    99,
       1,    27,    63,     1,    63,    28,    96,    66,     1,    29,
       6,    27,    27,     1,    76,     1,    27,    27,     1,    27,
       1,    27,     1,    27,    60,     1,    27,     1,    27,    72,
      72,    21,    25,    77,    29,    25,    53,    51,    51,     1,
      21,    65,    82,    82,     1,    82,    96,     1,    29,     1,
      27,    30,    67,    27,     6,    27,     1,     6,    27,    61,
      77,    26,    28,    53,    45,    54,    55,    57,     1,    27,
       1,    30,    30,    30,     1,    29,    82,    82,    27,     1,
      27,    26,    28,    28,    11,    74,    82,    83,    99,     1,
      27,     1,    26,    55,    28,    74,    74,    28,    99,    29,
      74,    29,    29,    99,     1,    29,    29,     1,    29
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
      63,    63,    65,    65,    66,    66,    67,    66,    68,    68,
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
       4,     4,     5,     5,     5,     5,     0,     6,     1,     0,
       5,     5,     3,     3,     3,     1,     5,     5,     0,     4,
       4,     4,     2,     2,     0,     3,     0,     3,     2,     2,
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
#line 68 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1519 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 72 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1527 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 7: /* global_statement: control_stmt  */
#line 76 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1535 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 9: /* global_statement: '{' program_statements '}'  */
#line 81 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
    }
#line 1543 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '{' program_statements $end  */
#line 85 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_PROGRAM_NAME);
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1552 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: '}'  */
#line 90 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1560 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* global_statement: error ';'  */
#line 94 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1569 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* program: IDENTIFIER '{' program_statements '}'  */
#line 102 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PROGRAM");
    }
#line 1577 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* program: IDENTIFIER '{' program_statements $end  */
#line 106 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1585 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statement: program  */
#line 121 "include/syntax-analyzer/components/yacc.y"
    {
       announceSpecificError(INVALID_PROGRAM_NESTING);
    }
#line 1593 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statement: '{' program_statements '}'  */
#line 125 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1601 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: '{' program_statements $end  */
#line 129 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1610 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* program_statement: error ';'  */
#line 134 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1618 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* declarative_stmt: type variable_list ';'  */
#line 143 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("VARIABLE DECLARATION");
    }
#line 1626 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* declarative_stmt: type error ';'  */
#line 147 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1635 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* declarative_stmt: type variable_list error  */
#line 152 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1644 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body ';'  */
#line 157 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION DECLARATION");
    }
#line 1652 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* declarative_stmt: type '(' formal_parameter_list ')' function_body ';'  */
#line 161 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_FUNCTION_NAME);
    }
#line 1660 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type IDENTIFIER '(' formal_parameter_list ')' function_body error  */
#line 165 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1669 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* declarative_stmt: type '(' formal_parameter_list ')' function_body error  */
#line 170 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1678 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 33: /* $@1: %empty  */
#line 182 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1686 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 35: /* variable_list: variable_list ',' error  */
#line 186 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1695 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* type: FLOAT  */
#line 195 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1703 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* $@2: %empty  */
#line 206 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1711 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* formal_parameter: type error  */
#line 214 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1720 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 44: /* formal_parameter: IDENTIFIER  */
#line 219 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    }
#line 1728 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* formal_parameter: parameter_semantics type error  */
#line 224 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1737 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* formal_parameter: parameter_semantics error  */
#line 229 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;
    }
#line 1747 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 48: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 235 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    }
#line 1755 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 51: /* function_body: '{' function_statements error  */
#line 247 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 1764 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* return: RETURN '(' opt_trunc_expression ')' error  */
#line 266 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1773 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* return: RETURN '(' opt_trunc_expression error  */
#line 271 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1783 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* return: RETURN opt_trunc_expression ')'  */
#line 277 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
    }
#line 1792 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* return: RETURN opt_trunc_expression error  */
#line 282 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1802 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* return: RETURN '(' opt_trunc_expression ';'  */
#line 288 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_PARENTHESIS);
    }
#line 1810 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* return: RETURN opt_trunc_expression ')' ';'  */
#line 292 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 1818 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* return: RETURN opt_trunc_expression ';'  */
#line 296 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);
    }
#line 1826 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* assignment: variable ASSIGN_OP opt_trunc_expression ';'  */
#line 314 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("ASSIGNMENT");
    }
#line 1834 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* assignment: variable ASSIGN_OP opt_trunc_expression error  */
#line 318 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1843 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* print: PRINT '(' STRING_LITERAL ')' ';'  */
#line 326 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1851 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 73: /* print: PRINT '(' STRING_LITERAL ')' error  */
#line 330 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1860 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 74: /* print: PRINT '(' opt_trunc_expression ')' ';'  */
#line 335 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1868 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* print: PRINT '(' opt_trunc_expression ')' error  */
#line 339 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1877 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* $@3: %empty  */
#line 344 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 1886 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 79: /* print_end: %empty  */
#line 354 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_SEMICOLON);
    }
#line 1894 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 80: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 364 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("MULTIPLE ASSIGNMENT");
    }
#line 1902 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 368 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1911 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 82: /* multiple_assignments: variable assignment_list ';'  */
#line 373 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_RIGHT_SIDE_VALUES);
    }
#line 1919 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* multiple_assignments: variable assignment_list error  */
#line 377 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1929 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 84: /* multiple_assignments: variable error ';'  */
#line 383 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;
    }
#line 1938 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 393 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_EQUALS);
    }
#line 1946 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 88: /* $@4: %empty  */
#line 397 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificErrorWithSymbol(MISSING_COMMA);
    }
#line 1954 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 401 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1962 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 91: /* assignment_list: ',' variable assignment_list error  */
#line 405 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1970 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 93: /* assignment_end: opt_trunc_constant error  */
#line 413 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 1979 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* $@5: %empty  */
#line 423 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1987 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 99: /* invocation: function_invocation error  */
#line 433 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1996 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* invocation: lambda_invocation error  */
#line 439 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2005 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* function_invocation: IDENTIFIER '(' real_parameter_list ')'  */
#line 447 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION INVOCATION");
    }
#line 2013 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 103: /* function_invocation: IDENTIFIER '(' error ')'  */
#line 451 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 2022 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 106: /* $@6: %empty  */
#line 461 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 2030 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* real_parameter: opt_trunc_expression error  */
#line 469 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2039 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 479 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("LAMBDA");
    }
#line 2047 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 483 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 2055 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 112: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '(' lambda_real_parameter ')'  */
#line 487 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 2063 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 113: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '(' lambda_real_parameter ')'  */
#line 491 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_BRACKETS);
    }
#line 2071 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 116: /* if: IF condition executable_body ENDIF ';'  */
#line 505 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF");
    }
#line 2079 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 117: /* if: IF condition executable_body ENDIF error  */
#line 509 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2088 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 118: /* if: IF condition executable_body ELSE executable_body ENDIF ';'  */
#line 514 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF-ELSE");
    }
#line 2096 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* if: IF condition executable_body ELSE executable_body ENDIF error  */
#line 518 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2105 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* if: IF condition executable_body error  */
#line 523 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2114 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 121: /* if: IF condition executable_body ELSE executable_body error  */
#line 528 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2123 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* if: IF condition error ENDIF ';'  */
#line 533 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2132 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* if: IF condition error ';'  */
#line 538 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2142 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 124: /* if: IF condition error ELSE ENDIF ';'  */
#line 544 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2151 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 125: /* if: IF condition error ELSE ';'  */
#line 549 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2161 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* if: IF condition executable_body ELSE error ENDIF ';'  */
#line 555 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2170 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* if: IF condition executable_body ELSE error ';'  */
#line 560 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2180 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* if: ELSE executable_body ENDIF ';'  */
#line 566 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;
    }
#line 2189 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* executable_body: '{' executable_statements error ';'  */
#line 575 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 2198 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 134: /* control_stmt: DO executable_body WHILE condition ';'  */
#line 591 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("DO-WHILE");
    }
#line 2206 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 135: /* control_stmt: DO executable_body WHILE condition error  */
#line 595 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2215 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 136: /* $@7: %empty  */
#line 600 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE);
    }
#line 2223 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* $@8: %empty  */
#line 605 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
    }
#line 2231 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* end_while_statement: condition error  */
#line 614 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2240 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* opt_trunc_constant: TRUNC '(' numeric_constant error  */
#line 626 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2249 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* opt_trunc_constant: TRUNC numeric_constant ')'  */
#line 631 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2257 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 146: /* opt_trunc_constant: TRUNC numeric_constant error  */
#line 635 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2266 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* opt_trunc_variable: TRUNC '(' variable error  */
#line 645 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2275 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 150: /* opt_trunc_variable: TRUNC variable ')'  */
#line 650 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2283 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* opt_trunc_variable: TRUNC variable error  */
#line 654 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2292 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 154: /* opt_trunc_expression: TRUNC '(' expression error  */
#line 664 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2301 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 155: /* opt_trunc_expression: TRUNC expression ')'  */
#line 669 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2309 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* opt_trunc_expression: TRUNC expression error  */
#line 673 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2318 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* condition: '(' comparison error  */
#line 684 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2327 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 159: /* condition: comparison ')'  */
#line 689 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2335 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* condition: comparison error  */
#line 693 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    }
#line 2344 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 162: /* comparison: opt_trunc_expression error  */
#line 702 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;
    }
#line 2353 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* $@9: %empty  */
#line 722 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 2361 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* expression: expression '+' error  */
#line 726 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2370 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* expression: expression '-' error  */
#line 731 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2379 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 176: /* expression: '+' term  */
#line 736 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUM_OPERAND);
    }
#line 2387 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* expression: '+' error  */
#line 740 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;
    }
#line 2396 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* positive_term: positive_term '*' error  */
#line 756 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2405 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* positive_term: positive_term '/' error  */
#line 761 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2414 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 188: /* negative_term: negative_term '*' error  */
#line 772 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2423 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 189: /* negative_term: negative_term '/' error  */
#line 777 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2432 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* negative_term: '*' factor  */
#line 782 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_MUL_FACTOR);
    }
#line 2440 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* negative_term: '/' factor  */
#line 786 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_DIV_FACTOR);
    }
#line 2448 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* negative_term: '*' error  */
#line 790 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2457 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* negative_term: '/' error  */
#line 795 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2466 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 201: /* negative_factor: '-' UINTEGER_LITERAL  */
#line 816 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2474 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 202: /* negative_factor: '-' function_invocation  */
#line 820 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2482 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 203: /* negative_factor: '-' variable  */
#line 824 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2490 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 204: /* negative_factor: '-' lambda_invocation  */
#line 828 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2498 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 205: /* negative_factor: '-' error  */
#line 832 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_FLOAT_CONSTANT);
        yyerrok;
    }
#line 2507 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* negative_constant: '-' FLOAT_LITERAL  */
#line 850 "include/syntax-analyzer/components/yacc.y"
    {
        addNegativeFloatToTable();
    }
#line 2515 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 2519 "src/syntax-analyzer/components/parser.cpp"

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

#line 860 "include/syntax-analyzer/components/yacc.y"


void yyerror(const char* s)
{
    announceSyntaxError();
}
