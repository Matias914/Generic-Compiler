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
#line 24 "include/syntax-analyzer/components/yacc.y"

#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/semantic_actions.h"
#include "semantic-analyzer/semantic_analyzer.h"

void yyerror(const char* s);

using namespace SemanticAnalyzer;
using namespace SyntaxAnalyzer::SemanticActions;

#define yylex LexicalAnalyzer::yylex

#line 85 "src/syntax-analyzer/components/parser.cpp"

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
  YYSYMBOL_29_ = 29,                       /* ','  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
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
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_unnamed_program_tail = 43,      /* unnamed_program_tail  */
  YYSYMBOL_program_head = 44,              /* program_head  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_program_tail = 46,              /* program_tail  */
  YYSYMBOL_program_statements = 47,        /* program_statements  */
  YYSYMBOL_program_statement = 48,         /* program_statement  */
  YYSYMBOL_declarative_stmt = 49,          /* declarative_stmt  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_variable_list = 52,             /* variable_list  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_unnamed_function_declaration_middle = 55, /* unnamed_function_declaration_middle  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_unnamed_function_declaration_tail = 57, /* unnamed_function_declaration_tail  */
  YYSYMBOL_function_declaration_middle = 58, /* function_declaration_middle  */
  YYSYMBOL_59_7 = 59,                      /* $@7  */
  YYSYMBOL_function_declaration_tail = 60, /* function_declaration_tail  */
  YYSYMBOL_formal_parameter_list = 61,     /* formal_parameter_list  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_formal_parameter = 63,          /* formal_parameter  */
  YYSYMBOL_parameter_semantics = 64,       /* parameter_semantics  */
  YYSYMBOL_function_body = 65,             /* function_body  */
  YYSYMBOL_function_statements = 66,       /* function_statements  */
  YYSYMBOL_function_statement = 67,        /* function_statement  */
  YYSYMBOL_return = 68,                    /* return  */
  YYSYMBOL_executable_stmt = 69,           /* executable_stmt  */
  YYSYMBOL_assignment_head = 70,           /* assignment_head  */
  YYSYMBOL_71_9 = 71,                      /* $@9  */
  YYSYMBOL_assignment_tail = 72,           /* assignment_tail  */
  YYSYMBOL_print = 73,                     /* print  */
  YYSYMBOL_74_10 = 74,                     /* $@10  */
  YYSYMBOL_print_end = 75,                 /* print_end  */
  YYSYMBOL_multiple_assignments = 76,      /* multiple_assignments  */
  YYSYMBOL_assignment_list = 77,           /* assignment_list  */
  YYSYMBOL_78_11 = 78,                     /* $@11  */
  YYSYMBOL_assignment_end = 79,            /* assignment_end  */
  YYSYMBOL_extra_numeric_constants = 80,   /* extra_numeric_constants  */
  YYSYMBOL_81_12 = 81,                     /* $@12  */
  YYSYMBOL_invocation = 82,                /* invocation  */
  YYSYMBOL_function_invocation = 83,       /* function_invocation  */
  YYSYMBOL_84_13 = 84,                     /* $@13  */
  YYSYMBOL_function_invocation_tail = 85,  /* function_invocation_tail  */
  YYSYMBOL_real_parameter_list = 86,       /* real_parameter_list  */
  YYSYMBOL_87_14 = 87,                     /* $@14  */
  YYSYMBOL_real_parameter = 88,            /* real_parameter  */
  YYSYMBOL_lambda_invocation_head = 89,    /* lambda_invocation_head  */
  YYSYMBOL_90_15 = 90,                     /* $@15  */
  YYSYMBOL_lambda_invocation_tail = 91,    /* lambda_invocation_tail  */
  YYSYMBOL_lambda_real_parameter = 92,     /* lambda_real_parameter  */
  YYSYMBOL_if = 93,                        /* if  */
  YYSYMBOL_executable_body = 94,           /* executable_body  */
  YYSYMBOL_executable_statements = 95,     /* executable_statements  */
  YYSYMBOL_control_stmt = 96,              /* control_stmt  */
  YYSYMBOL_97_16 = 97,                     /* $@16  */
  YYSYMBOL_98_17 = 98,                     /* $@17  */
  YYSYMBOL_end_while_statement = 99,       /* end_while_statement  */
  YYSYMBOL_opt_trunc_constant = 100,       /* opt_trunc_constant  */
  YYSYMBOL_trunc_constant = 101,           /* trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 102,       /* opt_trunc_variable  */
  YYSYMBOL_trunc_variable = 103,           /* trunc_variable  */
  YYSYMBOL_condition = 104,                /* condition  */
  YYSYMBOL_comparison = 105,               /* comparison  */
  YYSYMBOL_comparison_operator = 106,      /* comparison_operator  */
  YYSYMBOL_expression = 107,               /* expression  */
  YYSYMBOL_108_18 = 108,                   /* $@18  */
  YYSYMBOL_trunc_expression = 109,         /* trunc_expression  */
  YYSYMBOL_term = 110,                     /* term  */
  YYSYMBOL_positive_term = 111,            /* positive_term  */
  YYSYMBOL_negative_term = 112,            /* negative_term  */
  YYSYMBOL_factor = 113,                   /* factor  */
  YYSYMBOL_positive_factor = 114,          /* positive_factor  */
  YYSYMBOL_negative_factor = 115,          /* negative_factor  */
  YYSYMBOL_numeric_constant = 116,         /* numeric_constant  */
  YYSYMBOL_positive_constant = 117,        /* positive_constant  */
  YYSYMBOL_negative_constant = 118,        /* negative_constant  */
  YYSYMBOL_variable = 119                  /* variable  */
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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   934

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  238
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  375

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
      28,    30,    36,    34,    29,    35,    38,    37,     2,     2,
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
       0,    87,    87,    88,    89,    93,    97,   101,   105,   107,
     106,   113,   117,   125,   129,   133,   142,   141,   154,   159,
     164,   172,   173,   177,   178,   179,   180,   184,   188,   192,
     197,   206,   210,   215,   221,   220,   226,   225,   236,   240,
     245,   244,   252,   260,   264,   275,   274,   282,   286,   296,
     295,   303,   308,   317,   318,   320,   319,   327,   332,   337,
     344,   348,   353,   359,   368,   375,   376,   384,   385,   389,
     390,   394,   395,   400,   406,   411,   417,   421,   425,   434,
     435,   436,   437,   438,   439,   444,   443,   451,   455,   463,
     467,   472,   476,   482,   481,   490,   492,   501,   505,   510,
     514,   520,   528,   529,   530,   535,   534,   539,   543,   550,
     551,   558,   560,   562,   561,   570,   571,   576,   577,   586,
     585,   590,   598,   603,   610,   611,   613,   612,   619,   623,
     634,   633,   642,   647,   652,   657,   665,   666,   672,   676,
     681,   685,   690,   695,   700,   705,   711,   716,   722,   727,
     733,   741,   742,   747,   751,   752,   758,   762,   768,   767,
     773,   772,   780,   781,   791,   792,   796,   800,   807,   813,
     823,   827,   831,   835,   841,   846,   857,   858,   863,   867,
     875,   876,   884,   885,   886,   887,   888,   889,   893,   895,
     894,   899,   903,   908,   909,   914,   915,   920,   921,   922,
     926,   927,   932,   936,   944,   945,   949,   950,   951,   952,
     957,   965,   966,   967,   968,   973,   978,   982,   986,   991,
     999,  1000,  1004,  1012,  1017,  1024,  1029,  1033,  1039,  1045,
    1055,  1061,  1071,  1076,  1084,  1089,  1097,  1105,  1110
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
  "STRING_LITERAL", "'{'", "'}'", "';'", "'('", "','", "')'", "'='", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "'.'", "$accept", "global",
  "global_statement", "$@1", "unnamed_program_tail", "program_head", "$@2",
  "program_tail", "program_statements", "program_statement",
  "declarative_stmt", "$@3", "$@4", "variable_list", "$@5", "type",
  "unnamed_function_declaration_middle", "$@6",
  "unnamed_function_declaration_tail", "function_declaration_middle",
  "$@7", "function_declaration_tail", "formal_parameter_list", "$@8",
  "formal_parameter", "parameter_semantics", "function_body",
  "function_statements", "function_statement", "return", "executable_stmt",
  "assignment_head", "$@9", "assignment_tail", "print", "$@10",
  "print_end", "multiple_assignments", "assignment_list", "$@11",
  "assignment_end", "extra_numeric_constants", "$@12", "invocation",
  "function_invocation", "$@13", "function_invocation_tail",
  "real_parameter_list", "$@14", "real_parameter",
  "lambda_invocation_head", "$@15", "lambda_invocation_tail",
  "lambda_real_parameter", "if", "executable_body",
  "executable_statements", "control_stmt", "$@16", "$@17",
  "end_while_statement", "opt_trunc_constant", "trunc_constant",
  "opt_trunc_variable", "trunc_variable", "condition", "comparison",
  "comparison_operator", "expression", "$@18", "trunc_expression", "term",
  "positive_term", "negative_term", "factor", "positive_factor",
  "negative_factor", "numeric_constant", "positive_constant",
  "negative_constant", "variable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-251)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-190)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     537,  -251,    20,   790,   874,   874,   808,    95,  -251,  -251,
     145,  -251,  -251,   262,   566,  -251,  -251,  -251,   130,  -251,
    -251,  -251,  -251,  -251,  -251,    35,    73,  -251,  -251,    78,
    -251,   826,   138,  -251,  -251,   768,   236,   179,   297,   450,
    -251,  -251,   735,    45,   397,  -251,  -251,   327,   408,  -251,
    -251,  -251,  -251,   124,   906,  -251,   211,   221,   228,   768,
     142,   217,  -251,   351,   663,   225,  -251,  -251,   233,   235,
    -251,    93,   124,  -251,  -251,  -251,  -251,   242,  -251,  -251,
     268,  -251,   279,   473,   768,   405,    48,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,   124,  -251,  -251,  -251,  -251,  -251,
    -251,    23,   260,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,   355,   388,   830,   465,   476,   491,   500,   508,
    -251,   757,   270,   790,   790,   790,   420,  -251,  -251,   285,
     291,   313,   367,   689,   318,   786,   288,   699,  -251,  -251,
    -251,   595,  -251,  -251,  -251,  -251,   324,  -251,  -251,   391,
    -251,  -251,   205,   268,  -251,   830,   339,  -251,   167,  -251,
    -251,   517,  -251,   305,  -251,  -251,  -251,  -251,  -251,   435,
    -251,  -251,  -251,  -251,    14,   330,  -251,  -251,   767,    86,
    -251,  -251,  -251,  -251,  -251,  -251,    76,   327,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,   340,  -251,  -251,  -251,
     118,  -251,   127,  -251,  -251,  -251,   129,  -251,  -251,   133,
     134,  -251,  -251,   624,  -251,  -251,  -251,   276,  -251,   445,
    -251,  -251,   653,  -251,  -251,  -251,  -251,   391,  -251,  -251,
     234,  -251,   404,  -251,   316,  -251,   124,   124,  -251,   269,
     426,   426,   480,   259,    85,   192,  -251,  -251,   344,  -251,
    -251,   168,   111,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,   348,  -251,  -251,  -251,  -251,  -251,  -251,   830,
    -251,   830,  -251,   375,  -251,  -251,   884,  -251,   453,  -251,
    -251,   391,  -251,   391,  -251,  -251,   241,  -251,  -251,  -251,
      43,   379,  -251,   393,    88,  -251,  -251,  -251,  -251,   426,
     426,  -251,   411,  -251,  -251,   156,  -251,  -251,  -251,  -251,
    -251,   906,  -251,   789,  -251,  -251,   428,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,   829,   431,   720,   428,   864,  -251,   196,   447,   720,
     441,   372,   463,  -251,  -251,  -251,   124,  -251,   203,  -251,
     725,  -251,  -251,  -251,  -251,   441,   464,   475,   104,     5,
    -251,  -251,  -251,  -251,  -251,  -251,   477,  -251,  -251,    30,
    -251,  -251,  -251,  -251,  -251
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,   160,     0,     0,    43,    44,
     237,     9,    11,     0,     0,     2,     8,     5,     0,    84,
       6,    79,    83,    80,    81,     0,     0,    82,     7,     0,
      12,     0,   237,   235,   234,     0,     0,     0,     0,     0,
     224,   226,     0,     0,     0,   197,   188,   204,   205,   208,
     213,   223,   225,   222,     0,   153,     0,   158,     0,     0,
       0,     0,    16,     0,     0,     0,     1,     3,     0,   237,
      36,     0,    38,   116,   115,   118,   117,     0,    85,   105,
       0,   102,     0,     0,     0,     0,     0,   192,   191,   231,
     236,   227,   228,   230,   229,   218,   216,   220,   221,   219,
     217,     0,     0,   179,   178,   181,   182,   184,   185,   183,
     186,   187,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,     0,     0,     0,     0,     0,    75,    78,    74,
       0,     0,   189,     0,     0,     0,     0,     0,    14,    10,
      26,     0,    21,    23,    24,    25,     0,    32,    34,     0,
      33,    31,     0,     0,   101,     0,     0,   237,     0,   238,
     100,     0,    99,     0,   111,   165,   164,   232,   233,     0,
     203,   202,   177,   176,     0,     0,   145,   142,     0,     0,
     194,   198,   193,   196,   199,   195,   189,   190,   209,   206,
     210,   207,   214,   211,   215,   212,     0,   151,   155,   150,
       0,   159,     0,   161,    73,    76,     0,    77,    93,     0,
       0,    20,    17,     0,   121,   123,   120,   126,   124,     0,
      30,    27,     0,    15,    13,    22,   130,     0,    64,    59,
       0,    37,    55,    53,     0,    42,    39,    41,    86,     0,
       0,     0,     0,     0,     0,     0,   201,   200,     0,   147,
     144,     0,     0,   139,   138,   152,   157,   156,   163,   162,
      72,    71,    96,    90,    89,    92,    91,    19,    18,     0,
     122,     0,   129,     0,    29,    28,     0,    35,    55,    58,
      57,     0,    45,     0,    62,    63,     0,    88,    87,   106,
       0,     0,   108,   107,     0,   169,   168,    98,    97,     0,
       0,   146,     0,   149,   143,     0,    95,    94,   125,   127,
     128,     0,   131,     0,    49,    54,     0,    56,    61,    60,
     110,   109,   104,   103,   167,   166,   112,   114,   148,   141,
     140,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,   137,   136,   171,   170,    50,     0,    69,
       0,    67,    70,    48,    47,     0,     0,     0,     0,     0,
     135,    52,    51,    66,    65,    68,     0,   134,   133,     0,
     175,   174,   132,   173,   172
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -251,  -251,   492,  -251,  -251,    52,  -251,  -251,   -74,  -140,
       9,  -251,  -251,  -251,  -251,    -3,  -251,  -251,  -251,  -251,
    -251,  -251,   283,  -251,    68,  -251,   182,  -251,   170,  -251,
      11,  -251,  -251,  -251,  -251,  -251,  -251,  -251,   224,  -251,
    -251,  -251,  -251,  -251,     3,  -251,  -251,  -251,  -251,    17,
      34,  -251,  -251,  -107,  -251,    16,  -250,   220,  -251,  -251,
     392,   -50,  -251,  -251,  -251,    19,   483,  -251,    24,  -251,
     377,   -17,   409,  -251,   -15,   -26,    31,  -159,   -56,   -32,
       0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    14,    15,    64,   139,   140,   133,   212,   141,   142,
     143,   227,   149,    71,   153,    18,   231,   316,   336,   277,
     334,   347,   232,   283,   233,   234,   337,   350,   351,    19,
     144,    21,   155,   238,    22,   262,   307,    23,    83,   156,
     289,   245,   300,    24,    40,   135,   216,   217,   271,   218,
      41,   276,   312,   342,    27,    56,   121,   145,   124,    58,
     201,   343,   165,   344,   345,   202,    43,   114,    44,   115,
      45,    46,    47,    48,    96,    49,    50,   166,    51,    52,
      53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,   225,   244,    25,    29,    29,   370,    25,    25,    17,
      65,    20,    97,    97,    29,    55,    55,    25,    72,    88,
     248,    57,    42,    17,   100,    20,   313,   167,   174,   175,
      60,   373,    65,   164,    26,   371,    73,    94,    26,    26,
      92,   249,    29,    82,   320,    25,   103,    30,    26,   172,
     176,   168,    16,    55,    29,    85,    65,    25,   102,   213,
     374,   331,    74,   222,    29,   120,    16,    25,    82,    98,
      98,    93,   321,   225,    75,   104,    26,  -180,   173,    77,
     158,    65,   225,   126,   294,   132,   295,   253,    26,   324,
      97,    97,    97,    97,   150,   182,   185,    78,    26,    79,
      76,   189,   191,   193,   195,   167,  -180,    80,   169,    81,
     112,   113,   304,   254,   -40,   296,    82,   305,   325,   256,
     151,    29,   152,    61,    25,   157,    33,    34,   258,   168,
     260,    68,   198,    29,   263,   265,    25,    29,   186,   163,
      25,    29,   200,   127,    25,   257,   230,    98,    98,    98,
      98,    69,   236,   237,   259,    26,   261,   329,    70,   219,
     264,   266,    82,  -189,  -189,  -189,    63,    26,   241,   128,
      62,    26,   129,    63,   302,    26,   112,   113,    29,   239,
      89,    25,   244,   330,   167,   167,   167,   167,    79,    55,
     290,   291,   293,   297,   252,   303,    80,   353,    81,   294,
      32,    90,    91,  -113,   361,    82,   235,    13,   168,   168,
     168,   168,    26,    29,  -113,  -113,    25,   122,   130,   298,
      28,   299,    29,   354,   230,    25,   157,  -113,    31,   123,
     362,   286,   356,   357,    28,   279,   125,    87,    32,    33,
      34,   131,   318,   167,   167,    13,   146,    26,   366,   326,
     327,    36,    37,    38,    39,   280,    26,    32,    33,    34,
     147,   177,   319,   148,    13,   178,   179,   168,   168,   154,
     287,    37,    38,    39,     8,     9,    29,   167,   230,    25,
     230,    33,    34,   167,   167,   167,   308,   120,   309,   157,
    -189,  -189,  -189,   219,   163,   219,   288,   199,    95,   167,
     159,   168,   167,   112,   113,   269,   270,   168,   168,   168,
      26,    29,   207,    29,    25,   220,    25,   284,    32,    33,
      34,   208,   120,   168,   198,    13,   168,    90,     8,     9,
      65,    29,    37,   346,    25,    29,    65,   285,    25,   346,
     346,   359,   198,   209,   349,    26,   352,    26,   214,   315,
      29,   317,   134,    25,   226,   346,   180,   250,   369,   349,
      79,   352,  -119,   116,   117,    26,    31,   255,    80,    26,
      81,   301,  -119,  -119,  -119,   306,    32,    33,    34,  -119,
     240,  -119,   242,    13,    26,  -119,  -119,  -119,  -119,   183,
      37,    38,    39,   157,    33,    34,   310,   210,   105,    31,
     358,   112,   113,     8,     9,   228,   170,   163,   322,    32,
      33,    34,   229,   106,   107,   108,    13,   109,  -189,  -189,
    -189,   204,   323,    37,    38,    39,  -189,  -189,  -189,   110,
     111,   112,   113,   281,   282,   171,   246,   161,   328,   112,
     113,  -189,  -189,  -189,   118,   119,   272,   205,    33,    34,
     206,    99,   341,   335,   112,   113,  -189,  -189,  -189,   340,
     273,   163,   157,    33,    34,   247,  -189,  -189,  -189,   112,
     113,    32,    33,    34,   160,   355,   163,   188,    13,   112,
     113,   292,   281,   314,   161,    37,    32,    33,    34,   181,
     184,   161,   190,   360,   367,    33,    34,    32,    33,    34,
     162,   192,    33,    34,    13,   368,    67,   372,   163,   194,
     278,    37,    32,    33,    34,   163,   348,   203,    86,    13,
     365,    32,    33,    34,   187,     0,    37,     0,    13,    32,
      33,    34,     0,     0,     0,    37,    13,     1,     2,    33,
      34,     3,     4,    37,     5,   243,     6,     7,     0,     8,
       9,     0,   163,     0,     0,     0,     0,     0,    10,     0,
       0,     0,    11,    12,     0,    13,    66,     2,     0,     0,
       3,     4,     0,     5,     0,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,    10,     0,     0,
       0,    11,    12,     0,    13,   223,   136,     0,     0,     3,
       4,     0,     5,     0,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
     137,   224,     0,    13,   267,   136,     0,     0,     3,     4,
       0,     5,     0,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,   137,
     268,     0,    13,   274,   136,     0,     0,     3,     4,     0,
       5,     0,     6,     7,   136,     8,     9,     3,     4,     0,
       5,     0,     6,     7,    10,     8,     9,     0,   137,   275,
       0,    13,     0,     0,    10,     0,     0,     0,   137,   138,
     136,    13,     0,     3,     4,     0,     5,     0,     6,     7,
     136,     8,     9,     3,     4,     0,     5,     0,     6,     7,
      10,     8,     9,     0,   137,   211,     0,    13,     0,     0,
      10,     0,     0,     0,   137,   221,   363,    13,     0,     3,
       4,   341,     8,     9,     6,     7,   101,     8,     9,     3,
       4,   157,    33,    34,     6,     7,    32,     0,     0,     0,
       0,   364,     0,    13,     0,   163,    32,     0,   196,     0,
      54,     3,     4,    13,     0,     0,     6,     7,   251,     0,
       0,     3,     4,     0,     0,     0,     6,     7,    32,    31,
       8,     9,     0,   197,     0,    13,     0,     0,    32,    32,
      33,    34,    54,     3,     4,    13,    13,    31,     6,     7,
       0,    31,    36,    37,    38,    39,     0,    32,    33,    34,
      32,    32,    33,    34,    13,   332,   215,   333,    35,    31,
      36,    37,    38,    39,    36,    37,    38,    39,     0,    32,
      33,    34,     0,     3,     4,     0,    59,    31,     6,     7,
       0,    31,    36,    37,    38,    39,     0,    32,    33,    34,
      32,    32,    33,    34,    84,   338,     0,   339,    13,     0,
      36,    37,    38,    39,    36,    37,    38,    39,     3,     4,
       0,     0,     0,     6,     7,     0,     8,     9,     3,     4,
       0,     0,     0,     6,     7,    32,     0,     0,     3,     4,
       0,     0,    13,     6,     7,    32,     0,     0,     0,    54,
       0,     0,    13,     0,     0,    32,     0,     0,     0,   311,
       3,     4,    13,     0,     0,     6,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,    13
};

static const yytype_int16 yycheck[] =
{
       0,   141,   161,     0,     4,     5,     1,     4,     5,     0,
      13,     0,    38,    39,    14,     4,     5,    14,    18,    36,
       6,     5,     3,    14,    39,    14,   276,    83,     5,     6,
       6,     1,    35,    83,     0,    30,     1,    37,     4,     5,
      37,    27,    42,    38,     1,    42,     1,    27,    14,     1,
      27,    83,     0,    42,    54,    31,    59,    54,    42,   133,
      30,   311,    27,   137,    64,    54,    14,    64,    38,    38,
      39,    37,    29,   213,     1,    30,    42,     1,    30,     1,
      80,    84,   222,    59,   243,    61,     1,     1,    54,     1,
     116,   117,   118,   119,     1,   112,   113,    19,    64,    21,
      27,   116,   117,   118,   119,   161,    30,    29,    84,    31,
      34,    35,     1,    27,    21,    30,    38,     6,    30,     1,
      27,   121,    29,    28,   121,    21,    22,    23,     1,   161,
       1,     1,   121,   133,     1,     1,   133,   137,   114,    35,
     137,   141,   123,     1,   141,    27,   149,   116,   117,   118,
     119,    21,   152,   153,    27,   121,    27,     1,    28,   135,
      27,    27,    38,    21,    22,    23,    28,   133,     1,    27,
      25,   137,    30,    28,     6,   141,    34,    35,   178,   155,
       1,   178,   341,    27,   240,   241,   242,   243,    21,   178,
     240,   241,   242,     1,   178,    27,    29,     1,    31,   358,
      21,    22,    23,    11,     1,    38,     1,    28,   240,   241,
     242,   243,   178,   213,    22,    23,   213,     6,     1,    27,
       0,    29,   222,    27,   227,   222,    21,    35,    11,     8,
      27,   234,   339,   340,    14,     1,     8,     1,    21,    22,
      23,    24,     1,   299,   300,    28,    21,   213,   355,   299,
     300,    34,    35,    36,    37,    21,   222,    21,    22,    23,
      27,     1,    21,    28,    28,     5,     6,   299,   300,    27,
       1,    35,    36,    37,    12,    13,   276,   333,   281,   276,
     283,    22,    23,   339,   340,   341,   269,   276,   271,    21,
      21,    22,    23,   269,    35,   271,    27,    27,     1,   355,
      21,   333,   358,    34,    35,    29,    30,   339,   340,   341,
     276,   311,    27,   313,   311,    27,   313,     1,    21,    22,
      23,    30,   311,   355,   313,    28,   358,    22,    12,    13,
     333,   331,    35,   333,   331,   335,   339,    21,   335,   339,
     340,   341,   331,    30,   335,   311,   335,   313,    30,   281,
     350,   283,     1,   350,    30,   355,     1,    27,   358,   350,
      21,   350,    11,    36,    37,   331,    11,    27,    29,   335,
      31,    27,    21,    22,    23,    27,    21,    22,    23,    28,
     156,    30,   158,    28,   350,    34,    35,    36,    37,     1,
      35,    36,    37,    21,    22,    23,    21,    30,     1,    11,
      28,    34,    35,    12,    13,    14,     1,    35,    29,    21,
      22,    23,    21,    16,    17,    18,    28,    20,    21,    22,
      23,     1,    29,    35,    36,    37,    21,    22,    23,    32,
      33,    34,    35,    29,    30,    30,     1,    11,    27,    34,
      35,    21,    22,    23,    36,    37,     1,    27,    22,    23,
      30,     1,    11,    25,    34,    35,    21,    22,    23,    28,
      15,    35,    21,    22,    23,    30,    21,    22,    23,    34,
      35,    21,    22,    23,     1,    28,    35,     1,    28,    34,
      35,     1,    29,    30,    11,    35,    21,    22,    23,   112,
     113,    11,     1,    30,    30,    22,    23,    21,    22,    23,
      27,     1,    22,    23,    28,    30,    14,    30,    35,     1,
     227,    35,    21,    22,    23,    35,   334,   125,    35,    28,
     350,    21,    22,    23,   115,    -1,    35,    -1,    28,    21,
      22,    23,    -1,    -1,    -1,    35,    28,     0,     1,    22,
      23,     4,     5,    35,     7,    28,     9,    10,    -1,    12,
      13,    -1,    35,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    -1,    28,     0,     1,    -1,    -1,
       4,     5,    -1,     7,    -1,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    25,    26,    -1,    28,     0,     1,    -1,    -1,     4,
       5,    -1,     7,    -1,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    28,     0,     1,    -1,    -1,     4,     5,
      -1,     7,    -1,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,
      26,    -1,    28,     0,     1,    -1,    -1,     4,     5,    -1,
       7,    -1,     9,    10,     1,    12,    13,     4,     5,    -1,
       7,    -1,     9,    10,    21,    12,    13,    -1,    25,    26,
      -1,    28,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,
       1,    28,    -1,     4,     5,    -1,     7,    -1,     9,    10,
       1,    12,    13,     4,     5,    -1,     7,    -1,     9,    10,
      21,    12,    13,    -1,    25,    26,    -1,    28,    -1,    -1,
      21,    -1,    -1,    -1,    25,    26,     1,    28,    -1,     4,
       5,    11,    12,    13,     9,    10,     1,    12,    13,     4,
       5,    21,    22,    23,     9,    10,    21,    -1,    -1,    -1,
      -1,    26,    -1,    28,    -1,    35,    21,    -1,     1,    -1,
      25,     4,     5,    28,    -1,    -1,     9,    10,     1,    -1,
      -1,     4,     5,    -1,    -1,    -1,     9,    10,    21,    11,
      12,    13,    -1,    26,    -1,    28,    -1,    -1,    21,    21,
      22,    23,    25,     4,     5,    28,    28,    11,     9,    10,
      -1,    11,    34,    35,    36,    37,    -1,    21,    22,    23,
      21,    21,    22,    23,    28,    26,    30,    28,    28,    11,
      34,    35,    36,    37,    34,    35,    36,    37,    -1,    21,
      22,    23,    -1,     4,     5,    -1,    28,    11,     9,    10,
      -1,    11,    34,    35,    36,    37,    -1,    21,    22,    23,
      21,    21,    22,    23,    28,    26,    -1,    28,    28,    -1,
      34,    35,    36,    37,    34,    35,    36,    37,     4,     5,
      -1,    -1,    -1,     9,    10,    -1,    12,    13,     4,     5,
      -1,    -1,    -1,     9,    10,    21,    -1,    -1,     4,     5,
      -1,    -1,    28,     9,    10,    21,    -1,    -1,    -1,    25,
      -1,    -1,    28,    -1,    -1,    21,    -1,    -1,    -1,    25,
       4,     5,    28,    -1,    -1,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     0,     1,     4,     5,     7,     9,    10,    12,    13,
      21,    25,    26,    28,    40,    41,    44,    49,    54,    68,
      69,    70,    73,    76,    82,    83,    89,    93,    96,   119,
      27,    11,    21,    22,    23,    28,    34,    35,    36,    37,
      83,    89,   104,   105,   107,   109,   110,   111,   112,   114,
     115,   117,   118,   119,    25,    69,    94,    94,    98,    28,
     107,    28,    25,    28,    42,    54,     0,    41,     1,    21,
      28,    52,   119,     1,    27,     1,    27,     1,    19,    21,
      29,    31,    38,    77,    28,   107,   105,     1,   110,     1,
      22,    23,    83,    89,   119,     1,   113,   114,   115,     1,
     113,     1,    94,     1,    30,     1,    16,    17,    18,    20,
      32,    33,    34,    35,   106,   108,    36,    37,    36,    37,
      69,    95,     6,     8,    97,     8,   107,     1,    27,    30,
       1,    24,   107,    45,     1,    84,     1,    25,    26,    43,
      44,    47,    48,    49,    69,    96,    21,    27,    28,    51,
       1,    27,    29,    53,    27,    71,    78,    21,   119,    21,
       1,    11,    27,    35,   100,   101,   116,   117,   118,   107,
       1,    30,     1,    30,     5,     6,    27,     1,     5,     6,
       1,   109,   110,     1,   109,   110,   107,   111,     1,   113,
       1,   113,     1,   113,     1,   113,     1,    26,    69,    27,
     104,    99,   104,    99,     1,    27,    30,    27,    30,    30,
      30,    26,    46,    47,    30,    30,    85,    86,    88,   107,
      27,    26,    47,     0,    26,    48,    30,    50,    14,    21,
      54,    55,    61,    63,    64,     1,   119,   119,    72,   107,
      77,     1,    77,    28,   116,    80,     1,    30,     6,    27,
      27,     1,    94,     1,    27,    27,     1,    27,     1,    27,
       1,    27,    74,     1,    27,     1,    27,     0,    26,    29,
      30,    87,     1,    15,     0,    26,    90,    58,    61,     1,
      21,    29,    30,    62,     1,    21,    54,     1,    27,    79,
     100,   100,     1,   100,   116,     1,    30,     1,    27,    29,
      81,    27,     6,    27,     1,     6,    27,    75,    88,    88,
      21,    25,    91,    95,    30,    63,    56,    63,     1,    21,
       1,    29,    29,    29,     1,    30,   100,   100,    27,     1,
      27,    95,    26,    28,    59,    25,    57,    65,    26,    28,
      28,    11,    92,   100,   102,   103,   119,    60,    65,    49,
      66,    67,    69,     1,    27,    28,    92,    92,    28,   119,
      30,     1,    27,     1,    26,    67,    92,    30,    30,   119,
       1,    30,    30,     1,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    41,    41,    41,    42,
      41,    41,    41,    43,    43,    43,    45,    44,    46,    46,
      46,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    49,    50,    49,    51,    49,    52,    52,
      53,    52,    52,    54,    54,    56,    55,    57,    57,    59,
      58,    60,    60,    61,    61,    62,    61,    63,    63,    63,
      63,    63,    63,    63,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    71,    70,    72,    72,    73,
      73,    73,    73,    74,    73,    75,    75,    76,    76,    76,
      76,    76,    77,    77,    77,    78,    77,    77,    77,    79,
      79,    80,    80,    81,    80,    82,    82,    82,    82,    84,
      83,    83,    85,    85,    86,    86,    87,    86,    88,    88,
      90,    89,    91,    91,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    94,    94,    94,    95,    95,    96,    96,    97,    96,
      98,    96,    99,    99,   100,   100,   101,   101,   101,   101,
     102,   102,   103,   103,   103,   103,   104,   104,   104,   104,
     105,   105,   106,   106,   106,   106,   106,   106,   107,   108,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     109,   109,   109,   109,   110,   110,   111,   111,   111,   111,
     111,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     113,   113,   114,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   116,   116,   117,   117,   118,   119,   119
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     2,     1,     2,     0,     4,     2,     2,
       1,     1,     2,     1,     1,     1,     1,     2,     3,     3,
       2,     3,     3,     3,     0,     5,     0,     4,     1,     3,
       0,     3,     3,     1,     1,     0,     4,     2,     2,     0,
       4,     2,     2,     1,     3,     0,     3,     2,     2,     1,
       3,     3,     2,     2,     1,     3,     3,     1,     2,     1,
       1,     5,     5,     4,     3,     3,     4,     4,     3,     1,
       1,     1,     1,     1,     1,     0,     4,     2,     2,     5,
       5,     5,     5,     0,     6,     1,     0,     5,     5,     3,
       3,     3,     1,     5,     5,     0,     4,     4,     4,     2,
       2,     0,     3,     0,     3,     2,     2,     2,     2,     0,
       4,     4,     2,     1,     1,     3,     0,     3,     3,     2,
       0,     6,     6,     5,     5,     4,     1,     1,     5,     5,
       7,     7,     4,     6,     5,     4,     6,     5,     7,     6,
       4,     3,     4,     1,     1,     2,     5,     5,     0,     4,
       0,     4,     2,     2,     1,     1,     4,     4,     3,     3,
       1,     1,     4,     4,     3,     3,     3,     3,     2,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     2,     2,     3,     3,     3,     3,     1,     3,     3,
       4,     4,     3,     3,     1,     1,     3,     3,     1,     3,
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
#line 94 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1589 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 98 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1597 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 7: /* global_statement: control_stmt  */
#line 102 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1605 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 9: /* $@1: %empty  */
#line 107 "include/syntax-analyzer/components/yacc.y"
    {
        addInvalidScope();
        announceSpecificError(MISSING_PROGRAM_NAME);
        checkProgramRedeclaration("");
    }
#line 1615 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: '}'  */
#line 114 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1623 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* global_statement: error ';'  */
#line 118 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1632 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* unnamed_program_tail: program_statements '}'  */
#line 126 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
    }
#line 1640 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* unnamed_program_tail: '}'  */
#line 130 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
    }
#line 1648 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 15: /* unnamed_program_tail: program_statements $end  */
#line 134 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1657 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 16: /* $@2: %empty  */
#line 142 "include/syntax-analyzer/components/yacc.y"
    {
        const std::string s = (yyvsp[-1].sref)->symbol;
        checkProgramRedeclaration(s);
        if (updateSymbolAsProgram(s) == nullptr)
            addInvalidScope();
        else
            addScope(s);
    }
#line 1670 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 18: /* program_tail: program_statements '}'  */
#line 155 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PROGRAM");
        removeScope();
    }
#line 1679 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 19: /* program_tail: program_statements $end  */
#line 160 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        removeScope();
    }
#line 1688 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_tail: '}'  */
#line 165 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PROGRAM");
        removeScope();
    }
#line 1697 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* program_statement: program_head  */
#line 181 "include/syntax-analyzer/components/yacc.y"
    {
       announceSpecificError(INVALID_PROGRAM_NESTING);
    }
#line 1705 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* program_statement: '{' '}'  */
#line 185 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1713 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* program_statement: '{' program_statements '}'  */
#line 189 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1721 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* program_statement: '{' program_statements $end  */
#line 193 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1730 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* program_statement: error ';'  */
#line 198 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1738 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 31: /* declarative_stmt: type variable_list ';'  */
#line 207 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("VARIABLE DECLARATION");
    }
#line 1746 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* declarative_stmt: type error ';'  */
#line 211 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1755 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 33: /* declarative_stmt: type variable_list error  */
#line 216 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1764 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 34: /* $@3: %empty  */
#line 221 "include/syntax-analyzer/components/yacc.y"
    {
        notifyFunctionDeclaration((yyvsp[-1].sref)->symbol);
    }
#line 1772 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 36: /* $@4: %empty  */
#line 226 "include/syntax-analyzer/components/yacc.y"
    {
        notifyUnnamedFunctionDeclaration();
        announceSpecificError(MISSING_FUNCTION_NAME);
    }
#line 1781 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 38: /* variable_list: variable  */
#line 237 "include/syntax-analyzer/components/yacc.y"
    {
        upsertVariableScope();
    }
#line 1789 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 39: /* variable_list: variable_list ',' variable  */
#line 241 "include/syntax-analyzer/components/yacc.y"
    {
        upsertVariableScope();
    }
#line 1797 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* $@5: %empty  */
#line 245 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1805 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* variable_list: variable_list $@5 variable  */
#line 249 "include/syntax-analyzer/components/yacc.y"
    {
        upsertVariableScope();
    }
#line 1813 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* variable_list: variable_list ',' error  */
#line 253 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1822 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* type: UINT  */
#line 261 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_TYPE = UINT;
    }
#line 1830 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 44: /* type: FLOAT  */
#line 265 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_TYPE = FLOAT;
        announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1839 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* $@6: %empty  */
#line 275 "include/syntax-analyzer/components/yacc.y"
    {
        notifyParametersDeclarationEnd();
    }
#line 1847 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* unnamed_function_declaration_tail: function_body ';'  */
#line 283 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
    }
#line 1855 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 48: /* unnamed_function_declaration_tail: function_body error  */
#line 287 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1865 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 49: /* $@7: %empty  */
#line 296 "include/syntax-analyzer/components/yacc.y"
    {
        notifyParametersDeclarationEnd();
    }
#line 1873 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 51: /* function_declaration_tail: function_body ';'  */
#line 304 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION DECLARATION");
        removeScope();
    }
#line 1882 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 52: /* function_declaration_tail: function_body error  */
#line 309 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
        removeScope();
    }
#line 1892 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* $@8: %empty  */
#line 320 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1900 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* formal_parameter: type IDENTIFIER  */
#line 328 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_SEMANTIC = CV;
        updateParameterScope((yyvsp[0].sref)->symbol);
    }
#line 1909 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* formal_parameter: type error  */
#line 333 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1918 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* formal_parameter: IDENTIFIER  */
#line 338 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_TYPE = UNSUPPORTED;
        CURRENT_SEMANTIC = CV;
        updateParameterScope((yyvsp[0].sref)->symbol);
        announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    }
#line 1929 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* formal_parameter: parameter_semantics type IDENTIFIER  */
#line 345 "include/syntax-analyzer/components/yacc.y"
    {
        updateParameterScope((yyvsp[0].sref)->symbol);
    }
#line 1937 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* formal_parameter: parameter_semantics type error  */
#line 349 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1946 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* formal_parameter: parameter_semantics error  */
#line 354 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;
    }
#line 1956 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 360 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_TYPE = UNSUPPORTED;
        updateParameterScope((yyvsp[0].sref)->symbol);
        announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    }
#line 1966 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* parameter_semantics: CR  */
#line 369 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_SEMANTIC = CR;
    }
#line 1974 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 66: /* function_body: '{' function_statements error  */
#line 377 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 1983 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* return: RETURN '(' expression ')' error  */
#line 396 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1992 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 73: /* return: RETURN '(' expression error  */
#line 401 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2002 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 74: /* return: RETURN expression ')'  */
#line 407 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
    }
#line 2011 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* return: RETURN expression error  */
#line 412 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2021 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* return: RETURN '(' expression ';'  */
#line 418 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_PARENTHESIS);
    }
#line 2029 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 77: /* return: RETURN expression ')' ';'  */
#line 422 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2037 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 78: /* return: RETURN expression ';'  */
#line 426 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);
    }
#line 2045 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 85: /* $@9: %empty  */
#line 444 "include/syntax-analyzer/components/yacc.y"
    {
        checkVariableExistanceInScope();
    }
#line 2053 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* assignment_tail: expression ';'  */
#line 452 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("ASSIGNMENT");
    }
#line 2061 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 88: /* assignment_tail: expression error  */
#line 456 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2070 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 89: /* print: PRINT '(' STRING_LITERAL ')' ';'  */
#line 464 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 2078 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* print: PRINT '(' STRING_LITERAL ')' error  */
#line 468 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2087 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 91: /* print: PRINT '(' expression ')' ';'  */
#line 473 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 2095 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 92: /* print: PRINT '(' expression ')' error  */
#line 477 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2104 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 93: /* $@10: %empty  */
#line 482 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 2113 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* print_end: %empty  */
#line 492 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_SEMICOLON);
    }
#line 2121 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 502 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("MULTIPLE ASSIGNMENT");
    }
#line 2129 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 98: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 506 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2138 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 99: /* multiple_assignments: variable assignment_list ';'  */
#line 511 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_RIGHT_SIDE_VALUES);
    }
#line 2146 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 100: /* multiple_assignments: variable assignment_list error  */
#line 515 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2156 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* multiple_assignments: variable error ';'  */
#line 521 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;
    }
#line 2165 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 104: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 531 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_EQUALS);
    }
#line 2173 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 105: /* $@11: %empty  */
#line 535 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificErrorWithSymbol(MISSING_COMMA);
    }
#line 2181 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 107: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 540 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 2189 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* assignment_list: ',' variable assignment_list error  */
#line 544 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 2197 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* assignment_end: opt_trunc_constant error  */
#line 552 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 2206 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 113: /* $@12: %empty  */
#line 562 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 2214 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 116: /* invocation: function_invocation error  */
#line 572 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2223 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 118: /* invocation: lambda_invocation_head error  */
#line 578 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2232 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* $@13: %empty  */
#line 586 "include/syntax-analyzer/components/yacc.y"
    {
        checkFunctionExistanceInScopeAndBuffer((yyvsp[-1].sref)->symbol);
    }
#line 2240 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 121: /* function_invocation: IDENTIFIER '(' error ')'  */
#line 591 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 2249 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* function_invocation_tail: real_parameter_list ')'  */
#line 599 "include/syntax-analyzer/components/yacc.y"
    {
        checkInvocationParametersNumber();
        logStructure("FUNCTION INVOCATION");
    }
#line 2258 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* function_invocation_tail: ')'  */
#line 604 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_ARGUMENT);
    }
#line 2266 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* $@14: %empty  */
#line 613 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 2274 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* real_parameter: expression POINTER_OP IDENTIFIER  */
#line 620 "include/syntax-analyzer/components/yacc.y"
    {
        checkParameterExistanceInScope((yyvsp[0].sref)->symbol);
    }
#line 2282 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 129: /* real_parameter: expression error  */
#line 624 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2291 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* $@15: %empty  */
#line 634 "include/syntax-analyzer/components/yacc.y"
    {
        addLambdaScope();
        updateParameterScope((yyvsp[-1].sref)->symbol);
    }
#line 2300 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 132: /* lambda_invocation_tail: '{' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 643 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
        logStructure("LAMBDA");
    }
#line 2309 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* lambda_invocation_tail: executable_statements '}' '(' lambda_real_parameter ')'  */
#line 648 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 2318 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 134: /* lambda_invocation_tail: '{' executable_statements '(' lambda_real_parameter ')'  */
#line 653 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 2327 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 135: /* lambda_invocation_tail: executable_statements '(' lambda_real_parameter ')'  */
#line 658 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
        announceSpecificError(MISSING_BOTH_BRACKETS);
    }
#line 2336 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* if: IF condition executable_body ENDIF ';'  */
#line 673 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF");
    }
#line 2344 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 139: /* if: IF condition executable_body ENDIF error  */
#line 677 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2353 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 140: /* if: IF condition executable_body ELSE executable_body ENDIF ';'  */
#line 682 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF-ELSE");
    }
#line 2361 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* if: IF condition executable_body ELSE executable_body ENDIF error  */
#line 686 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2370 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 142: /* if: IF condition executable_body error  */
#line 691 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2379 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* if: IF condition executable_body ELSE executable_body error  */
#line 696 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2388 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* if: IF condition error ENDIF ';'  */
#line 701 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2397 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* if: IF condition error ';'  */
#line 706 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2407 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 146: /* if: IF condition error ELSE ENDIF ';'  */
#line 712 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2416 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 147: /* if: IF condition error ELSE ';'  */
#line 717 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2426 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 148: /* if: IF condition executable_body ELSE error ENDIF ';'  */
#line 723 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2435 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* if: IF condition executable_body ELSE error ';'  */
#line 728 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2445 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 150: /* if: ELSE executable_body ENDIF ';'  */
#line 734 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;
    }
#line 2454 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 152: /* executable_body: '{' executable_statements error ';'  */
#line 743 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 2463 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* control_stmt: DO executable_body WHILE condition ';'  */
#line 759 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("DO-WHILE");
    }
#line 2471 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 157: /* control_stmt: DO executable_body WHILE condition error  */
#line 763 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2480 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* $@16: %empty  */
#line 768 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE);
    }
#line 2488 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* $@17: %empty  */
#line 773 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
    }
#line 2496 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 163: /* end_while_statement: condition error  */
#line 782 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2505 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* trunc_constant: TRUNC '(' numeric_constant ')'  */
#line 797 "include/syntax-analyzer/components/yacc.y"
    {
        COERTIONS.truncable((yyvsp[-1].metadata).lref->type);
    }
#line 2513 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 167: /* trunc_constant: TRUNC '(' numeric_constant error  */
#line 801 "include/syntax-analyzer/components/yacc.y"
    {
        COERTIONS.truncable((yyvsp[-1].metadata).lref->type);

        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2524 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 168: /* trunc_constant: TRUNC numeric_constant ')'  */
#line 808 "include/syntax-analyzer/components/yacc.y"
    {
        COERTIONS.truncable((yyvsp[-1].metadata).lref->type);

        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2534 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 169: /* trunc_constant: TRUNC numeric_constant error  */
#line 814 "include/syntax-analyzer/components/yacc.y"
    {
        COERTIONS.truncable((yyvsp[-1].metadata).lref->type);

        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2545 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 170: /* opt_trunc_variable: variable  */
#line 824 "include/syntax-analyzer/components/yacc.y"
    {
        checkVariableExistanceInScope();
    }
#line 2553 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* trunc_variable: TRUNC '(' variable ')'  */
#line 832 "include/syntax-analyzer/components/yacc.y"
    {
        checkVariableExistanceInScope();
    }
#line 2561 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* trunc_variable: TRUNC '(' variable error  */
#line 836 "include/syntax-analyzer/components/yacc.y"
    {
        checkVariableExistanceInScope();
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2571 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* trunc_variable: TRUNC variable ')'  */
#line 842 "include/syntax-analyzer/components/yacc.y"
    {
        checkVariableExistanceInScope();
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2580 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* trunc_variable: TRUNC variable error  */
#line 847 "include/syntax-analyzer/components/yacc.y"
    {
        checkVariableExistanceInScope();
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2590 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* condition: '(' comparison error  */
#line 859 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2599 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 178: /* condition: comparison ')'  */
#line 864 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2607 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 179: /* condition: comparison error  */
#line 868 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    }
#line 2616 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 181: /* comparison: expression error  */
#line 877 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;
    }
#line 2625 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 189: /* $@18: %empty  */
#line 895 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 2633 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* expression: '+' term  */
#line 900 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUM_OPERAND);
    }
#line 2641 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* expression: '+' error  */
#line 904 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;
    }
#line 2650 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 194: /* expression: expression '+' error  */
#line 910 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2659 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 196: /* expression: expression '-' error  */
#line 916 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2668 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 201: /* trunc_expression: TRUNC '(' expression error  */
#line 928 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2677 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 202: /* trunc_expression: TRUNC expression ')'  */
#line 933 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2685 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 203: /* trunc_expression: TRUNC expression error  */
#line 937 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2694 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 209: /* positive_term: positive_term '*' error  */
#line 953 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2703 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* positive_term: positive_term '/' error  */
#line 958 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2712 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 214: /* negative_term: negative_term '*' error  */
#line 969 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2721 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 215: /* negative_term: negative_term '/' error  */
#line 974 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2730 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 216: /* negative_term: '*' factor  */
#line 979 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_MUL_FACTOR);
    }
#line 2738 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 217: /* negative_term: '/' factor  */
#line 983 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_DIV_FACTOR);
    }
#line 2746 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 218: /* negative_term: '*' error  */
#line 987 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2755 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 219: /* negative_term: '/' error  */
#line 992 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2764 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 222: /* positive_factor: variable  */
#line 1005 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).sref = checkVariableExistanceInScope();
        if ((yyval.metadata).sref == nullptr)
            (yyval.metadata).type = NOTHING;
        else
            (yyval.metadata).type = SYMBOL;
    }
#line 2776 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 223: /* positive_factor: positive_constant  */
#line 1013 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).sref = (yyvsp[0].metadata).sref;
        (yyval.metadata).type = LITERAL;
    }
#line 2785 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 224: /* positive_factor: function_invocation  */
#line 1018 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).type = NOTHING;
    }
#line 2793 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 225: /* negative_factor: negative_constant  */
#line 1025 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).lref = (yyvsp[0].metadata).lref;
        (yyval.metadata).type = LITERAL;
    }
#line 2802 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 226: /* negative_factor: lambda_invocation_head  */
#line 1030 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).type = NOTHING;
    }
#line 2810 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 227: /* negative_factor: '-' UINTEGER_LITERAL  */
#line 1034 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).type = NOTHING;

        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2820 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 228: /* negative_factor: '-' function_invocation  */
#line 1040 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).type = NOTHING;

        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2830 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 229: /* negative_factor: '-' variable  */
#line 1046 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).sref = checkVariableExistanceInScope();
        if ((yyval.metadata).sref == nullptr)
            (yyval.metadata).type = NOTHING;
        else
            (yyval.metadata).type = SYMBOL;

        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2844 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 230: /* negative_factor: '-' lambda_invocation_head  */
#line 1056 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).type = NOTHING;

        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2854 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 231: /* negative_factor: '-' error  */
#line 1062 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).type = NOTHING;

        specifySyntaxError(MISSING_FLOAT_CONSTANT);
        yyerrok;
    }
#line 2865 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 232: /* numeric_constant: positive_constant  */
#line 1072 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).lref = (yyvsp[0].metadata).lref;
        (yyval.metadata).type = LITERAL;
    }
#line 2874 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 233: /* numeric_constant: negative_constant  */
#line 1077 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).lref = (yyvsp[0].metadata).lref;
        (yyval.metadata).type = LITERAL;
    }
#line 2883 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 234: /* positive_constant: UINTEGER_LITERAL  */
#line 1085 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).lref = (yyvsp[0].lref);
        (yyval.metadata).type = LITERAL;
    }
#line 2892 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 235: /* positive_constant: FLOAT_LITERAL  */
#line 1090 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).lref = (yyvsp[0].lref);
        (yyval.metadata).type = LITERAL;
    }
#line 2901 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 236: /* negative_constant: '-' FLOAT_LITERAL  */
#line 1098 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).lref = turnNegative((yyvsp[0].lref));
        (yyval.metadata).type = LITERAL;
    }
#line 2910 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 237: /* variable: IDENTIFIER  */
#line 1106 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_VARIABLE.prefix.clear();
        CURRENT_VARIABLE.name = (yyvsp[0].sref)->symbol;
    }
#line 2919 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 238: /* variable: variable '.' IDENTIFIER  */
#line 1111 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_VARIABLE.prefix.append(":").append(CURRENT_VARIABLE.name);
        CURRENT_VARIABLE.name = (yyvsp[0].sref)->symbol;
    }
#line 2928 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 2932 "src/syntax-analyzer/components/parser.cpp"

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

#line 1117 "include/syntax-analyzer/components/yacc.y"


void yyerror(const char* s)
{
    announceSyntaxError();
}
