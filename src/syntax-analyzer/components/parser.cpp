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
#line 20 "include/syntax-analyzer/components/yacc.y"

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
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_unnamed_program_tail = 43,      /* unnamed_program_tail  */
  YYSYMBOL_program_head = 44,              /* program_head  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_program_tail = 46,              /* program_tail  */
  YYSYMBOL_program_statements = 47,        /* program_statements  */
  YYSYMBOL_program_statement = 48,         /* program_statement  */
  YYSYMBOL_declarative_stmt = 49,          /* declarative_stmt  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_function_declaration_tail = 51, /* function_declaration_tail  */
  YYSYMBOL_variable_list_head = 52,        /* variable_list_head  */
  YYSYMBOL_variable_list_tail = 53,        /* variable_list_tail  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_formal_parameter_list = 55,     /* formal_parameter_list  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_formal_parameter = 57,          /* formal_parameter  */
  YYSYMBOL_parameter_semantics = 58,       /* parameter_semantics  */
  YYSYMBOL_function_body = 59,             /* function_body  */
  YYSYMBOL_function_statements = 60,       /* function_statements  */
  YYSYMBOL_function_statement = 61,        /* function_statement  */
  YYSYMBOL_return = 62,                    /* return  */
  YYSYMBOL_executable_stmt = 63,           /* executable_stmt  */
  YYSYMBOL_assignment = 64,                /* assignment  */
  YYSYMBOL_print = 65,                     /* print  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_print_end = 67,                 /* print_end  */
  YYSYMBOL_multiple_assignments = 68,      /* multiple_assignments  */
  YYSYMBOL_assignment_list = 69,           /* assignment_list  */
  YYSYMBOL_70_6 = 70,                      /* $@6  */
  YYSYMBOL_assignment_end = 71,            /* assignment_end  */
  YYSYMBOL_extra_numeric_constants = 72,   /* extra_numeric_constants  */
  YYSYMBOL_73_7 = 73,                      /* $@7  */
  YYSYMBOL_invocation = 74,                /* invocation  */
  YYSYMBOL_function_invocation = 75,       /* function_invocation  */
  YYSYMBOL_real_parameter_list = 76,       /* real_parameter_list  */
  YYSYMBOL_77_8 = 77,                      /* $@8  */
  YYSYMBOL_real_parameter = 78,            /* real_parameter  */
  YYSYMBOL_lambda_invocation = 79,         /* lambda_invocation  */
  YYSYMBOL_lambda_real_parameter = 80,     /* lambda_real_parameter  */
  YYSYMBOL_if = 81,                        /* if  */
  YYSYMBOL_executable_body = 82,           /* executable_body  */
  YYSYMBOL_executable_statements = 83,     /* executable_statements  */
  YYSYMBOL_control_stmt = 84,              /* control_stmt  */
  YYSYMBOL_85_9 = 85,                      /* $@9  */
  YYSYMBOL_86_10 = 86,                     /* $@10  */
  YYSYMBOL_end_while_statement = 87,       /* end_while_statement  */
  YYSYMBOL_opt_trunc_constant = 88,        /* opt_trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 89,        /* opt_trunc_variable  */
  YYSYMBOL_opt_trunc_expression = 90,      /* opt_trunc_expression  */
  YYSYMBOL_condition = 91,                 /* condition  */
  YYSYMBOL_comparison = 92,                /* comparison  */
  YYSYMBOL_comparison_operator = 93,       /* comparison_operator  */
  YYSYMBOL_expression = 94,                /* expression  */
  YYSYMBOL_95_11 = 95,                     /* $@11  */
  YYSYMBOL_term = 96,                      /* term  */
  YYSYMBOL_positive_term = 97,             /* positive_term  */
  YYSYMBOL_negative_term = 98,             /* negative_term  */
  YYSYMBOL_factor = 99,                    /* factor  */
  YYSYMBOL_positive_factor = 100,          /* positive_factor  */
  YYSYMBOL_negative_factor = 101,          /* negative_factor  */
  YYSYMBOL_numeric_constant = 102,         /* numeric_constant  */
  YYSYMBOL_positive_constant = 103,        /* positive_constant  */
  YYSYMBOL_negative_constant = 104,        /* negative_constant  */
  YYSYMBOL_variable = 105                  /* variable  */
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
#define YYLAST   869

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  356

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
       0,    76,    76,    77,    78,    82,    86,    90,    94,    96,
      95,   102,   106,   114,   118,   127,   126,   139,   144,   149,
     157,   158,   162,   163,   164,   165,   169,   173,   178,   187,
     191,   196,   202,   201,   208,   212,   220,   225,   236,   240,
     244,   248,   253,   261,   265,   275,   276,   278,   277,   284,
     285,   290,   294,   295,   300,   306,   313,   317,   318,   326,
     327,   331,   332,   336,   337,   342,   348,   353,   359,   363,
     367,   376,   377,   378,   379,   380,   381,   385,   389,   397,
     401,   406,   410,   416,   415,   424,   426,   435,   439,   444,
     448,   454,   462,   463,   464,   469,   468,   473,   477,   484,
     485,   492,   494,   496,   495,   504,   505,   510,   511,   519,
     523,   531,   532,   534,   533,   540,   541,   551,   555,   559,
     563,   570,   571,   577,   581,   586,   590,   595,   600,   605,
     610,   616,   621,   627,   632,   638,   646,   647,   652,   656,
     657,   663,   667,   673,   672,   678,   677,   685,   686,   696,
     697,   698,   703,   707,   715,   716,   717,   722,   726,   734,
     735,   736,   741,   745,   755,   756,   761,   765,   773,   774,
     782,   783,   784,   785,   786,   787,   791,   792,   793,   795,
     794,   798,   803,   808,   812,   820,   821,   825,   826,   827,
     828,   833,   841,   842,   843,   844,   849,   854,   858,   862,
     867,   875,   876,   880,   881,   882,   886,   887,   888,   892,
     896,   900,   904,   912,   913,   917,   922,   930,   938,   943
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
  "global_statement", "$@1", "unnamed_program_tail", "program_head", "$@2",
  "program_tail", "program_statements", "program_statement",
  "declarative_stmt", "$@3", "function_declaration_tail",
  "variable_list_head", "variable_list_tail", "type",
  "formal_parameter_list", "$@4", "formal_parameter",
  "parameter_semantics", "function_body", "function_statements",
  "function_statement", "return", "executable_stmt", "assignment", "print",
  "$@5", "print_end", "multiple_assignments", "assignment_list", "$@6",
  "assignment_end", "extra_numeric_constants", "$@7", "invocation",
  "function_invocation", "real_parameter_list", "$@8", "real_parameter",
  "lambda_invocation", "lambda_real_parameter", "if", "executable_body",
  "executable_statements", "control_stmt", "$@9", "$@10",
  "end_while_statement", "opt_trunc_constant", "opt_trunc_variable",
  "opt_trunc_expression", "condition", "comparison", "comparison_operator",
  "expression", "$@11", "term", "positive_term", "negative_term", "factor",
  "positive_factor", "negative_factor", "numeric_constant",
  "positive_constant", "negative_constant", "variable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-304)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-180)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     488,  -304,    -8,   706,   793,   793,   724,    48,  -304,  -304,
       4,  -304,  -304,   262,   517,  -304,  -304,  -304,   137,  -304,
    -304,  -304,  -304,  -304,  -304,    38,   146,  -304,  -304,    88,
    -304,   831,    70,  -304,  -304,   702,   171,   335,   424,   433,
    -304,  -304,   128,   665,    11,   514,  -304,   179,   278,  -304,
    -304,  -304,  -304,    -3,   745,  -304,   125,    36,   117,   702,
      52,   349,  -304,   379,   640,    80,  -304,  -304,   114,   135,
     452,   174,    -3,  -304,  -304,  -304,  -304,   176,   742,  -304,
     198,  -304,   206,   440,   759,   234,    19,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,    -3,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,   742,   173,
     421,  -304,  -304,   396,   407,   415,   448,   456,   459,   484,
    -304,   678,   220,   706,   706,   706,    95,  -304,  -304,   255,
     283,   288,   306,   614,   314,   291,  -304,    16,   257,   640,
    -304,  -304,   546,  -304,  -304,  -304,  -304,   322,  -304,  -304,
    -304,  -304,    87,   302,  -304,   391,  -304,  -304,  -304,   102,
    -304,    -3,  -304,   154,   375,   119,  -304,  -304,   326,  -304,
     331,  -304,  -304,  -304,  -304,   238,  -304,  -304,  -304,  -304,
    -304,   203,   311,  -304,  -304,   691,   170,  -304,  -304,  -304,
    -304,   179,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
     328,  -304,  -304,  -304,   185,  -304,   186,  -304,  -304,  -304,
     197,  -304,  -304,   209,   210,  -304,  -304,   575,  -304,  -304,
     742,   742,  -304,   347,  -304,   604,  -304,  -304,  -304,   801,
     452,  -304,  -304,   334,   452,   452,  -304,  -304,   155,  -304,
      -3,  -304,  -304,   353,   353,    93,   359,    23,   275,  -304,
    -304,   360,  -304,  -304,   244,   298,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,   364,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,   745,   815,  -304,
     316,   779,   213,  -304,  -304,  -304,  -304,  -304,    12,   363,
    -304,   365,    68,  -304,  -304,  -304,  -304,   353,   353,  -304,
     394,  -304,  -304,   227,  -304,  -304,   823,   411,   834,   334,
    -304,   650,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,   412,   834,   268,
     272,   419,  -304,  -304,    -3,   237,  -304,  -304,  -304,   268,
     429,   443,   211,    21,  -304,  -304,  -304,   445,  -304,  -304,
      37,  -304,  -304,  -304,  -304,  -304
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,   145,     0,     0,    43,    44,
     218,     9,    11,     0,     0,     2,     8,     5,     0,    76,
       6,    71,    75,    72,    73,     0,     0,    74,     7,     0,
      12,     0,   218,   216,   215,     0,     0,     0,     0,     0,
     205,   207,     0,     0,     0,   159,   178,   185,   186,   189,
     194,   204,   206,   203,     0,   138,     0,   143,     0,     0,
       0,     0,    15,     0,     0,     0,     1,     3,     0,   218,
       0,     0,    38,   106,   105,   108,   107,     0,     0,    95,
       0,    92,     0,     0,     0,     0,     0,   184,   183,   212,
     217,   208,   209,   211,   210,   199,   197,   201,   202,   200,
     198,   169,   170,   172,   173,   171,   174,   175,     0,     0,
       0,   167,   166,     0,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,    67,    70,    66,
       0,     0,     0,     0,     0,   113,   111,     0,     0,     0,
      10,    25,     0,    20,    22,    23,    24,     0,    30,    32,
      56,    51,     0,    47,    45,     0,    31,   218,    29,     0,
      39,    41,    91,     0,     0,     0,   219,    90,     0,    89,
       0,   101,   149,   213,   214,     0,   163,   162,   165,   164,
     168,     0,     0,   130,   127,     0,     0,   181,   176,   182,
     177,   180,   190,   187,   191,   188,   195,   192,   196,   193,
       0,   136,   140,   135,     0,   144,     0,   146,    65,    68,
       0,    69,    83,     0,     0,    19,    16,     0,   110,   109,
       0,     0,   116,     0,    28,     0,    14,    13,    21,     0,
       0,    50,    49,     0,     0,     0,    54,    55,     0,    42,
      40,    78,    77,     0,     0,     0,     0,     0,     0,   161,
     160,     0,   132,   129,     0,     0,   124,   123,   137,   142,
     141,   148,   147,    64,    63,    86,    80,    79,    82,    81,
      18,    17,   112,   114,   115,    27,    26,     0,     0,    33,
      47,     0,     0,    46,    48,    53,    52,    96,     0,     0,
      98,    97,     0,   153,   152,    88,    87,     0,     0,   131,
       0,   134,   128,     0,    85,    84,     0,     0,     0,     0,
      61,     0,    59,    62,    35,    34,   100,    99,    94,    93,
     151,   150,   102,   104,   133,   126,   125,     0,     0,     0,
       0,     0,   122,   121,   154,     0,    58,    57,    60,     0,
       0,     0,     0,     0,   120,    37,    36,     0,   119,   118,
       0,   158,   157,   117,   156,   155
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -304,  -304,   436,  -304,  -304,   287,  -304,  -304,  -112,  -135,
       2,  -304,  -304,  -304,  -304,   -12,   223,  -304,   131,  -304,
     177,  -304,   188,  -304,    56,  -304,  -304,  -304,  -304,  -304,
     338,  -304,  -304,  -304,  -304,  -304,    41,  -304,  -304,   178,
      63,  -303,  -304,     6,  -226,   309,  -304,  -304,   371,   -55,
    -304,    24,     7,   455,  -304,   -22,  -304,   -21,   389,  -304,
      18,    -5,    35,  -160,   -77,    81,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    14,    15,    64,   140,   141,   133,   216,   142,   143,
     144,   230,   279,    71,   160,    18,   153,   235,   154,   155,
     282,   311,   312,    19,   145,    21,    22,   265,   305,    23,
      83,   164,   287,   248,   298,    24,    40,   135,   221,   136,
      41,   331,    27,    56,   121,   146,   124,    58,   205,   332,
     333,    42,   206,    44,   108,    45,   115,    46,    47,    48,
      96,    49,    50,   172,    51,    52,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    65,    17,   278,    29,    29,   173,   228,   247,    85,
      43,    57,   111,   316,    29,    88,    17,   222,    72,    30,
     178,   217,   351,    65,   293,   340,   341,   225,   171,    62,
      60,   223,    63,    97,    97,    82,   347,    94,   354,    73,
     112,    25,   317,    29,   123,    25,    25,    65,   179,   110,
     352,   306,   294,   127,    29,    25,    20,   100,   152,    82,
      55,    55,   175,    26,    29,    74,   355,    26,    26,   320,
      20,   161,    65,    98,    98,    82,    61,    26,    92,   128,
     165,   129,   228,   126,    25,   132,   292,   137,   231,    77,
     228,   173,   188,   190,   290,    25,   208,   321,    63,    55,
      93,   147,   163,   239,   168,    25,    26,    78,   232,    79,
     120,    97,    97,    97,    97,    33,    34,    26,    80,    81,
     244,    29,   209,   157,   210,   125,    82,    26,   170,   101,
     204,   122,   180,    29,   193,   195,   197,   199,    68,    29,
      79,   148,    29,   238,   102,   103,   104,    75,   105,    80,
      81,    98,    98,    98,    98,   241,   285,    82,    69,   240,
     106,   107,    25,   149,   174,    70,   173,   173,   173,   173,
     247,   256,    87,    76,    25,   156,   286,   202,   181,   182,
      25,   242,   292,    25,    26,    29,   259,   261,   288,   289,
     291,   255,    32,    33,    34,   157,    26,   257,   263,    13,
     183,   158,    26,   162,   159,    26,    37,    38,    39,   251,
     266,   268,   260,   262,   314,   116,   117,    29,   152,   157,
     173,   173,   152,   152,   264,    29,    25,   166,   325,    29,
     252,   173,   157,    33,    34,   176,   267,   269,   345,   249,
     315,    55,   322,   323,   137,   137,   170,   203,    26,   174,
     300,   173,   173,   173,   326,  -179,  -179,  -179,    25,  -179,
    -179,  -179,   173,   177,   346,   173,    25,   250,   113,   114,
      25,   301,   113,   114,     8,     9,   295,    29,    29,   330,
      26,    29,   211,   310,   224,   120,  -103,    16,    26,   157,
      33,    34,    26,   157,    33,    34,    65,  -103,  -103,   302,
     342,    16,   296,   170,   303,   297,    29,   170,   334,    28,
    -103,    29,   212,   310,   118,   119,    65,   213,    25,    25,
     219,   220,    25,    28,   174,   174,   174,   174,   334,   334,
     343,   233,   234,   120,   202,   214,    89,   313,   253,   334,
      26,    26,   350,   218,    26,   309,   234,    25,    33,    34,
     130,   229,    25,    90,   246,   258,    32,    90,    91,   281,
      31,   170,   202,    13,   168,   283,   284,   313,   274,    26,
      32,    33,    34,   131,    26,    33,    34,    13,   174,   174,
     134,    33,    34,    36,    37,    38,    39,   299,   170,   174,
      31,   304,   236,   318,   170,   319,    79,   187,   272,   273,
      32,    33,    34,     8,     9,    80,    81,    13,   189,   174,
     174,   174,   237,    36,    37,    38,    39,    32,    33,    34,
     174,   324,   184,   174,    13,    95,   185,   186,    32,    33,
      34,    37,    38,    39,    99,    13,    32,    33,    34,   329,
     339,   167,    37,    38,    39,    32,    33,    34,   344,   192,
      67,   168,    13,   280,    32,    33,    34,   194,   348,    37,
     196,    13,    33,    34,     8,     9,   150,   169,    37,    32,
      33,    34,   349,   151,   353,   170,    13,    32,    33,    34,
      32,    33,    34,    37,    13,   198,   335,    13,     1,     2,
      86,    37,     3,     4,    37,     5,   207,     6,     7,   338,
       8,     9,   243,   245,   191,    32,    33,    34,     0,    10,
       0,     0,    13,    11,    12,     0,    13,    66,     2,    37,
       0,     3,     4,     0,     5,     0,     6,     7,     0,     8,
       9,     0,     0,     0,     0,  -179,  -179,  -179,    10,     0,
       0,     0,    11,    12,     0,    13,   226,   138,   113,   114,
       3,     4,     0,     5,     0,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,    10,     0,     0,
       0,   139,   227,     0,    13,   270,   138,     0,     0,     3,
       4,     0,     5,     0,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
     139,   271,     0,    13,   275,   138,     0,     0,     3,     4,
       0,     5,     0,     6,     7,   138,     8,     9,     3,     4,
       0,     5,     0,     6,     7,    10,     8,     9,     0,   139,
     276,     0,    13,     0,     0,    10,     0,     0,     0,   139,
     215,   138,    13,     0,     3,     4,     0,     5,     0,     6,
       7,   336,     8,     9,     3,     4,     0,     0,     0,     6,
       7,    10,     8,     9,     0,   139,   109,     0,    13,     3,
       4,    32,     0,     0,     6,     7,   337,     0,    13,   200,
       0,     0,     3,     4,     0,     0,    32,     6,     7,     0,
      54,     0,   254,    13,     0,     3,     4,     0,     0,    32,
       6,     7,     0,     0,   201,     0,    13,     0,     0,     0,
       0,     0,    32,    31,     8,     9,    54,    31,     0,    13,
       0,     0,     0,    32,    33,    34,     0,    32,    33,    34,
      13,     0,     0,     0,    35,    31,    36,    37,    38,    39,
      36,    37,    38,    39,     0,    32,    33,    34,     0,     3,
       4,     0,    59,    31,     6,     7,     0,     0,    36,    37,
      38,    39,     0,    32,    33,    34,    32,     0,     0,     0,
      13,     8,     9,    13,     0,     0,    36,    37,    38,    39,
      32,    33,    34,     3,     4,     0,     0,    13,     6,     7,
       0,     8,     9,    36,    37,    38,    39,     3,     4,     0,
      32,     0,     6,     7,     0,     3,     4,    13,     0,     0,
       6,     7,     0,     0,    32,     0,     0,     0,    54,     3,
       4,    13,    32,     0,     6,     7,   277,     3,     4,    13,
       0,     0,     6,     7,     0,     0,    32,     0,     0,     0,
       0,   307,     0,   308,    32,   330,     8,     9,     0,   327,
       0,   328,    32,    33,    34,   157,    33,    34,     0,    84,
       0,     0,     0,     0,     0,    36,    37,    38,    39,   170
};

static const yytype_int16 yycheck[] =
{
       0,    13,     0,   229,     4,     5,    83,   142,   168,    31,
       3,     5,     1,     1,    14,    36,    14,     1,    18,    27,
       1,   133,     1,    35,     1,   328,   329,   139,    83,    25,
       6,    15,    28,    38,    39,    38,   339,    37,     1,     1,
      29,     0,    30,    43,     8,     4,     5,    59,    29,    43,
      29,   277,    29,     1,    54,    14,     0,    39,    70,    38,
       4,     5,    84,     0,    64,    27,    29,     4,     5,     1,
      14,    71,    84,    38,    39,    38,    28,    14,    37,    27,
      80,    29,   217,    59,    43,    61,   246,    63,     1,     1,
     225,   168,   113,   114,     1,    54,     1,    29,    28,    43,
      37,    21,    78,     1,    11,    64,    43,    19,    21,    21,
      54,   116,   117,   118,   119,    22,    23,    54,    30,    31,
       1,   121,    27,    21,    29,     8,    38,    64,    35,     1,
     123,     6,   108,   133,   116,   117,   118,   119,     1,   139,
      21,    27,   142,   155,    16,    17,    18,     1,    20,    30,
      31,   116,   117,   118,   119,     1,     1,    38,    21,   159,
      32,    33,   121,    28,    83,    28,   243,   244,   245,   246,
     330,     1,     1,    27,   133,     1,    21,   121,     5,     6,
     139,    27,   342,   142,   121,   185,     1,     1,   243,   244,
     245,   185,    21,    22,    23,    21,   133,    27,     1,    28,
      27,    27,   139,    27,    30,   142,    35,    36,    37,     6,
       1,     1,    27,    27,     1,    36,    37,   217,   230,    21,
     297,   298,   234,   235,    27,   225,   185,    21,     1,   229,
      27,   308,    21,    22,    23,     1,    27,    27,     1,     1,
      27,   185,   297,   298,   220,   221,    35,    27,   185,   168,
       6,   328,   329,   330,    27,    21,    22,    23,   217,    21,
      22,    23,   339,    29,    27,   342,   225,    29,    34,    35,
     229,    27,    34,    35,    12,    13,     1,   277,   278,    11,
     217,   281,    27,   281,    27,   229,    11,     0,   225,    21,
      22,    23,   229,    21,    22,    23,   308,    22,    23,     1,
      28,    14,    27,    35,     6,    30,   306,    35,   308,     0,
      35,   311,    29,   311,    36,    37,   328,    29,   277,   278,
      29,    30,   281,    14,   243,   244,   245,   246,   328,   329,
     330,    29,    30,   277,   278,    29,     1,   281,    27,   339,
     277,   278,   342,    29,   281,    29,    30,   306,    22,    23,
       1,    29,   311,    22,    28,    27,    21,    22,    23,    25,
      11,    35,   306,    28,    11,   234,   235,   311,    21,   306,
      21,    22,    23,    24,   311,    22,    23,    28,   297,   298,
       1,    22,    23,    34,    35,    36,    37,    27,    35,   308,
      11,    27,     1,    30,    35,    30,    21,     1,   220,   221,
      21,    22,    23,    12,    13,    30,    31,    28,     1,   328,
     329,   330,    21,    34,    35,    36,    37,    21,    22,    23,
     339,    27,     1,   342,    28,     1,     5,     6,    21,    22,
      23,    35,    36,    37,     1,    28,    21,    22,    23,    28,
      28,     1,    35,    36,    37,    21,    22,    23,    29,     1,
      14,    11,    28,   230,    21,    22,    23,     1,    29,    35,
       1,    28,    22,    23,    12,    13,    14,    27,    35,    21,
      22,    23,    29,    21,    29,    35,    28,    21,    22,    23,
      21,    22,    23,    35,    28,     1,   309,    28,     0,     1,
      35,    35,     4,     5,    35,     7,   125,     9,    10,   311,
      12,    13,   164,   165,   115,    21,    22,    23,    -1,    21,
      -1,    -1,    28,    25,    26,    -1,    28,     0,     1,    35,
      -1,     4,     5,    -1,     7,    -1,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    21,    22,    23,    21,    -1,
      -1,    -1,    25,    26,    -1,    28,     0,     1,    34,    35,
       4,     5,    -1,     7,    -1,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    25,    26,    -1,    28,     0,     1,    -1,    -1,     4,
       5,    -1,     7,    -1,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    28,     0,     1,    -1,    -1,     4,     5,
      -1,     7,    -1,     9,    10,     1,    12,    13,     4,     5,
      -1,     7,    -1,     9,    10,    21,    12,    13,    -1,    25,
      26,    -1,    28,    -1,    -1,    21,    -1,    -1,    -1,    25,
      26,     1,    28,    -1,     4,     5,    -1,     7,    -1,     9,
      10,     1,    12,    13,     4,     5,    -1,    -1,    -1,     9,
      10,    21,    12,    13,    -1,    25,     1,    -1,    28,     4,
       5,    21,    -1,    -1,     9,    10,    26,    -1,    28,     1,
      -1,    -1,     4,     5,    -1,    -1,    21,     9,    10,    -1,
      25,    -1,     1,    28,    -1,     4,     5,    -1,    -1,    21,
       9,    10,    -1,    -1,    26,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    21,    11,    12,    13,    25,    11,    -1,    28,
      -1,    -1,    -1,    21,    22,    23,    -1,    21,    22,    23,
      28,    -1,    -1,    -1,    28,    11,    34,    35,    36,    37,
      34,    35,    36,    37,    -1,    21,    22,    23,    -1,     4,
       5,    -1,    28,    11,     9,    10,    -1,    -1,    34,    35,
      36,    37,    -1,    21,    22,    23,    21,    -1,    -1,    -1,
      28,    12,    13,    28,    -1,    -1,    34,    35,    36,    37,
      21,    22,    23,     4,     5,    -1,    -1,    28,     9,    10,
      -1,    12,    13,    34,    35,    36,    37,     4,     5,    -1,
      21,    -1,     9,    10,    -1,     4,     5,    28,    -1,    -1,
       9,    10,    -1,    -1,    21,    -1,    -1,    -1,    25,     4,
       5,    28,    21,    -1,     9,    10,    25,     4,     5,    28,
      -1,    -1,     9,    10,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    26,    -1,    28,    21,    11,    12,    13,    -1,    26,
      -1,    28,    21,    22,    23,    21,    22,    23,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     0,     1,     4,     5,     7,     9,    10,    12,    13,
      21,    25,    26,    28,    40,    41,    44,    49,    54,    62,
      63,    64,    65,    68,    74,    75,    79,    81,    84,   105,
      27,    11,    21,    22,    23,    28,    34,    35,    36,    37,
      75,    79,    90,    91,    92,    94,    96,    97,    98,   100,
     101,   103,   104,   105,    25,    63,    82,    82,    86,    28,
      90,    28,    25,    28,    42,    54,     0,    41,     1,    21,
      28,    52,   105,     1,    27,     1,    27,     1,    19,    21,
      30,    31,    38,    69,    28,    94,    92,     1,    96,     1,
      22,    23,    75,    79,   105,     1,    99,   100,   101,     1,
      99,     1,    16,    17,    18,    20,    32,    33,    93,     1,
      82,     1,    29,    34,    35,    95,    36,    37,    36,    37,
      63,    83,     6,     8,    85,     8,    90,     1,    27,    29,
       1,    24,    90,    45,     1,    76,    78,    90,     1,    25,
      43,    44,    47,    48,    49,    63,    84,    21,    27,    28,
      14,    21,    54,    55,    57,    58,     1,    21,    27,    30,
      53,   105,    27,    90,    70,   105,    21,     1,    11,    27,
      35,    88,   102,   103,   104,    94,     1,    29,     1,    29,
      90,     5,     6,    27,     1,     5,     6,     1,    96,     1,
      96,    97,     1,    99,     1,    99,     1,    99,     1,    99,
       1,    26,    63,    27,    91,    87,    91,    87,     1,    27,
      29,    27,    29,    29,    29,    26,    46,    47,    29,    29,
      30,    77,     1,    15,    27,    47,     0,    26,    48,    29,
      50,     1,    21,    29,    30,    56,     1,    21,    54,     1,
     105,     1,    27,    69,     1,    69,    28,   102,    72,     1,
      29,     6,    27,    27,     1,    82,     1,    27,    27,     1,
      27,     1,    27,     1,    27,    66,     1,    27,     1,    27,
       0,    26,    78,    78,    21,     0,    26,    25,    83,    51,
      55,    25,    59,    57,    57,     1,    21,    71,    88,    88,
       1,    88,   102,     1,    29,     1,    27,    30,    73,    27,
       6,    27,     1,     6,    27,    67,    83,    26,    28,    29,
      49,    60,    61,    63,     1,    27,     1,    30,    30,    30,
       1,    29,    88,    88,    27,     1,    27,    26,    28,    28,
      11,    80,    88,    89,   105,    59,     1,    26,    61,    28,
      80,    80,    28,   105,    29,     1,    27,    80,    29,    29,
     105,     1,    29,    29,     1,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    41,    41,    41,    42,
      41,    41,    41,    43,    43,    45,    44,    46,    46,    46,
      47,    47,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    49,    50,    49,    49,    49,    51,    51,    52,    52,
      53,    53,    53,    54,    54,    55,    55,    56,    55,    57,
      57,    57,    57,    57,    57,    57,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    64,    65,
      65,    65,    65,    66,    65,    67,    67,    68,    68,    68,
      68,    68,    69,    69,    69,    70,    69,    69,    69,    71,
      71,    72,    72,    73,    72,    74,    74,    74,    74,    75,
      75,    76,    76,    77,    76,    78,    78,    79,    79,    79,
      79,    80,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    82,    83,
      83,    84,    84,    85,    84,    86,    84,    87,    87,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    93,    94,    94,    94,    95,
      94,    94,    94,    94,    94,    96,    96,    97,    97,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   102,   102,   103,   103,   104,   105,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     2,     2,     0,     4,     2,     2,     1,
       1,     2,     1,     1,     1,     1,     3,     3,     2,     3,
       3,     3,     0,     5,     6,     6,     4,     4,     1,     2,
       2,     1,     2,     1,     1,     1,     3,     0,     3,     2,
       2,     1,     3,     3,     2,     2,     1,     3,     3,     1,
       2,     1,     1,     5,     5,     4,     3,     3,     4,     4,
       3,     1,     1,     1,     1,     1,     1,     4,     4,     5,
       5,     5,     5,     0,     6,     1,     0,     5,     5,     3,
       3,     3,     1,     5,     5,     0,     4,     4,     4,     2,
       2,     0,     3,     0,     3,     2,     2,     2,     2,     4,
       4,     1,     3,     0,     3,     3,     2,    10,     9,     9,
       8,     1,     1,     5,     5,     7,     7,     4,     6,     5,
       4,     6,     5,     7,     6,     4,     3,     4,     1,     1,
       2,     5,     5,     0,     4,     0,     4,     2,     2,     1,
       4,     4,     3,     3,     1,     4,     4,     3,     3,     1,
       4,     4,     3,     3,     3,     3,     2,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     0,
       3,     3,     3,     2,     2,     1,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     2,     1,     3
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
#line 83 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1540 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 87 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1548 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 7: /* global_statement: control_stmt  */
#line 91 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1556 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 9: /* $@1: %empty  */
#line 96 "include/syntax-analyzer/components/yacc.y"
    {
        addInvalidScope();
        announceSpecificError(MISSING_PROGRAM_NAME);
        checkProgramRedeclaration("");
    }
#line 1566 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: '}'  */
#line 103 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1574 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* global_statement: error ';'  */
#line 107 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1583 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* unnamed_program_tail: program_statements '}'  */
#line 115 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
    }
#line 1591 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* unnamed_program_tail: program_statements $end  */
#line 119 "include/syntax-analyzer/components/yacc.y"
    {
        removeScope();
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1600 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 15: /* $@2: %empty  */
#line 127 "include/syntax-analyzer/components/yacc.y"
    {
        const std::string s = (yyvsp[-1].sref)->symbol;
        checkProgramRedeclaration(s);
        if (updateSymbolAsProgram(s) == nullptr)
            addInvalidScope();
        else
            addScope(s);
    }
#line 1613 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 17: /* program_tail: program_statements '}'  */
#line 140 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PROGRAM");
        removeScope();
    }
#line 1622 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 18: /* program_tail: program_statements $end  */
#line 145 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        removeScope();
    }
#line 1631 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 19: /* program_tail: '}'  */
#line 150 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PROGRAM");
        removeScope();
    }
#line 1640 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* program_statement: program_head  */
#line 166 "include/syntax-analyzer/components/yacc.y"
    {
       announceSpecificError(INVALID_PROGRAM_NESTING);
    }
#line 1648 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* program_statement: '{' program_statements '}'  */
#line 170 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1656 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* program_statement: '{' program_statements $end  */
#line 174 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1665 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* program_statement: error ';'  */
#line 179 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1673 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type variable_list_head ';'  */
#line 188 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("VARIABLE DECLARATION");
    }
#line 1681 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* declarative_stmt: type error ';'  */
#line 192 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1690 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 31: /* declarative_stmt: type variable_list_head error  */
#line 197 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1699 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* $@3: %empty  */
#line 202 "include/syntax-analyzer/components/yacc.y"
    {
        const std::string s = (yyvsp[-1].sref)->symbol;
        upsertFunctionScope(s);
        addScope(s);
    }
#line 1709 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 34: /* declarative_stmt: type '(' formal_parameter_list ')' function_body ';'  */
#line 209 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_FUNCTION_NAME);
    }
#line 1717 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 35: /* declarative_stmt: type '(' formal_parameter_list ')' function_body error  */
#line 213 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1726 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 36: /* function_declaration_tail: formal_parameter_list ')' function_body ';'  */
#line 221 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION DECLARATION");
        removeScope();
    }
#line 1735 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* function_declaration_tail: formal_parameter_list ')' function_body error  */
#line 226 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
        removeScope();
    }
#line 1745 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 38: /* variable_list_head: variable  */
#line 237 "include/syntax-analyzer/components/yacc.y"
    {
        upsertVariableScope();
    }
#line 1753 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* variable_list_tail: ',' variable  */
#line 245 "include/syntax-analyzer/components/yacc.y"
    {
        upsertVariableScope();
    }
#line 1761 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* variable_list_tail: variable  */
#line 249 "include/syntax-analyzer/components/yacc.y"
    {
        upsertVariableScope();
        announceSpecificErrorWithSymbol(MISSING_COMMA);
    }
#line 1770 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* variable_list_tail: ',' error  */
#line 254 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1779 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* type: UINT  */
#line 262 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_TYPE = UINT;
    }
#line 1787 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 44: /* type: FLOAT  */
#line 266 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_TYPE = FLOAT;
        announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1796 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* $@4: %empty  */
#line 278 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 1804 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 50: /* formal_parameter: type error  */
#line 286 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1813 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 51: /* formal_parameter: IDENTIFIER  */
#line 291 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    }
#line 1821 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 53: /* formal_parameter: parameter_semantics type error  */
#line 296 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1830 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 54: /* formal_parameter: parameter_semantics error  */
#line 301 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;
    }
#line 1840 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 307 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    }
#line 1848 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* function_body: '{' function_statements error  */
#line 319 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 1857 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* return: RETURN '(' opt_trunc_expression ')' error  */
#line 338 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1866 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 65: /* return: RETURN '(' opt_trunc_expression error  */
#line 343 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1876 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 66: /* return: RETURN opt_trunc_expression ')'  */
#line 349 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
    }
#line 1885 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 67: /* return: RETURN opt_trunc_expression error  */
#line 354 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1895 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 68: /* return: RETURN '(' opt_trunc_expression ';'  */
#line 360 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_PARENTHESIS);
    }
#line 1903 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 69: /* return: RETURN opt_trunc_expression ')' ';'  */
#line 364 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 1911 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* return: RETURN opt_trunc_expression ';'  */
#line 368 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);
    }
#line 1919 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 77: /* assignment: variable ASSIGN_OP opt_trunc_expression ';'  */
#line 386 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("ASSIGNMENT");
    }
#line 1927 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 78: /* assignment: variable ASSIGN_OP opt_trunc_expression error  */
#line 390 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1936 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 79: /* print: PRINT '(' STRING_LITERAL ')' ';'  */
#line 398 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1944 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 80: /* print: PRINT '(' STRING_LITERAL ')' error  */
#line 402 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1953 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* print: PRINT '(' opt_trunc_expression ')' ';'  */
#line 407 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("PRINT");
    }
#line 1961 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 82: /* print: PRINT '(' opt_trunc_expression ')' error  */
#line 411 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1970 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* $@5: %empty  */
#line 416 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 1979 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 86: /* print_end: %empty  */
#line 426 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_SEMICOLON);
    }
#line 1987 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 436 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("MULTIPLE ASSIGNMENT");
    }
#line 1995 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 88: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 440 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2004 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 89: /* multiple_assignments: variable assignment_list ';'  */
#line 445 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_RIGHT_SIDE_VALUES);
    }
#line 2012 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* multiple_assignments: variable assignment_list error  */
#line 449 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2022 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 91: /* multiple_assignments: variable error ';'  */
#line 455 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;
    }
#line 2031 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 94: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 465 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_EQUALS);
    }
#line 2039 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* $@6: %empty  */
#line 469 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificErrorWithSymbol(MISSING_COMMA);
    }
#line 2047 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 474 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 2055 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 98: /* assignment_list: ',' variable assignment_list error  */
#line 478 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 2063 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 100: /* assignment_end: opt_trunc_constant error  */
#line 486 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 2072 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 103: /* $@7: %empty  */
#line 496 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 2080 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 106: /* invocation: function_invocation error  */
#line 506 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2089 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* invocation: lambda_invocation error  */
#line 512 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2098 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* function_invocation: IDENTIFIER '(' real_parameter_list ')'  */
#line 520 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("FUNCTION INVOCATION");
    }
#line 2106 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* function_invocation: IDENTIFIER '(' error ')'  */
#line 524 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 2115 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 113: /* $@8: %empty  */
#line 534 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_COMMA);
    }
#line 2123 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 116: /* real_parameter: opt_trunc_expression error  */
#line 542 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2132 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 117: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 552 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("LAMBDA");
    }
#line 2140 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 118: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 556 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 2148 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* lambda_invocation: '(' type IDENTIFIER ')' '{' executable_statements '(' lambda_real_parameter ')'  */
#line 560 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 2156 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* lambda_invocation: '(' type IDENTIFIER ')' executable_statements '(' lambda_real_parameter ')'  */
#line 564 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_BOTH_BRACKETS);
    }
#line 2164 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* if: IF condition executable_body ENDIF ';'  */
#line 578 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF");
    }
#line 2172 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 124: /* if: IF condition executable_body ENDIF error  */
#line 582 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2181 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 125: /* if: IF condition executable_body ELSE executable_body ENDIF ';'  */
#line 587 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("IF-ELSE");
    }
#line 2189 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* if: IF condition executable_body ELSE executable_body ENDIF error  */
#line 591 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2198 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* if: IF condition executable_body error  */
#line 596 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2207 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* if: IF condition executable_body ELSE executable_body error  */
#line 601 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2216 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 129: /* if: IF condition error ENDIF ';'  */
#line 606 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2225 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* if: IF condition error ';'  */
#line 611 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2235 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 131: /* if: IF condition error ELSE ENDIF ';'  */
#line 617 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2244 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 132: /* if: IF condition error ELSE ';'  */
#line 622 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2254 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* if: IF condition executable_body ELSE error ENDIF ';'  */
#line 628 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2263 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 134: /* if: IF condition executable_body ELSE error ';'  */
#line 633 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2273 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 135: /* if: ELSE executable_body ENDIF ';'  */
#line 639 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;
    }
#line 2282 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 137: /* executable_body: '{' executable_statements error ';'  */
#line 648 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 2291 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* control_stmt: DO executable_body WHILE condition ';'  */
#line 664 "include/syntax-analyzer/components/yacc.y"
    {
        logStructure("DO-WHILE");
    }
#line 2299 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 142: /* control_stmt: DO executable_body WHILE condition error  */
#line 668 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2308 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* $@9: %empty  */
#line 673 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE);
    }
#line 2316 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* $@10: %empty  */
#line 678 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
    }
#line 2324 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 148: /* end_while_statement: condition error  */
#line 687 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2333 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* opt_trunc_constant: TRUNC '(' numeric_constant error  */
#line 699 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2342 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 152: /* opt_trunc_constant: TRUNC numeric_constant ')'  */
#line 704 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2350 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 153: /* opt_trunc_constant: TRUNC numeric_constant error  */
#line 708 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2359 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* opt_trunc_variable: TRUNC '(' variable error  */
#line 718 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2368 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 157: /* opt_trunc_variable: TRUNC variable ')'  */
#line 723 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2376 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* opt_trunc_variable: TRUNC variable error  */
#line 727 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2385 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 161: /* opt_trunc_expression: TRUNC '(' expression error  */
#line 737 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2394 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 162: /* opt_trunc_expression: TRUNC expression ')'  */
#line 742 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2402 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 163: /* opt_trunc_expression: TRUNC expression error  */
#line 746 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    }
#line 2411 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 165: /* condition: '(' comparison error  */
#line 757 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2420 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* condition: comparison ')'  */
#line 762 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2428 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 167: /* condition: comparison error  */
#line 766 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    }
#line 2437 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 169: /* comparison: opt_trunc_expression error  */
#line 775 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;
    }
#line 2446 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 179: /* $@11: %empty  */
#line 795 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 2454 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 181: /* expression: expression '+' error  */
#line 799 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2463 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 182: /* expression: expression '-' error  */
#line 804 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    }
#line 2472 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* expression: '+' term  */
#line 809 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUM_OPERAND);
    }
#line 2480 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* expression: '+' error  */
#line 813 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;
    }
#line 2489 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* positive_term: positive_term '*' error  */
#line 829 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2498 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* positive_term: positive_term '/' error  */
#line 834 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2507 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 195: /* negative_term: negative_term '*' error  */
#line 845 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2516 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 196: /* negative_term: negative_term '/' error  */
#line 850 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    }
#line 2525 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 197: /* negative_term: '*' factor  */
#line 855 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_MUL_FACTOR);
    }
#line 2533 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 198: /* negative_term: '/' factor  */
#line 859 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_DIV_FACTOR);
    }
#line 2541 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 199: /* negative_term: '*' error  */
#line 863 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2550 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 200: /* negative_term: '/' error  */
#line 868 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    }
#line 2559 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 208: /* negative_factor: '-' UINTEGER_LITERAL  */
#line 889 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2567 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 209: /* negative_factor: '-' function_invocation  */
#line 893 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2575 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* negative_factor: '-' variable  */
#line 897 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2583 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 211: /* negative_factor: '-' lambda_invocation  */
#line 901 "include/syntax-analyzer/components/yacc.y"
    {
        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    }
#line 2591 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 212: /* negative_factor: '-' error  */
#line 905 "include/syntax-analyzer/components/yacc.y"
    {
        specifySyntaxError(MISSING_FLOAT_CONSTANT);
        yyerrok;
    }
#line 2600 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 215: /* positive_constant: UINTEGER_LITERAL  */
#line 918 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).type = LITERAL;
        (yyval.metadata).val.lref = (yyvsp[0].lref);
    }
#line 2609 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 216: /* positive_constant: FLOAT_LITERAL  */
#line 923 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).type = LITERAL;
        (yyval.metadata).val.lref = (yyvsp[0].lref);
    }
#line 2618 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 217: /* negative_constant: '-' FLOAT_LITERAL  */
#line 931 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).type = LITERAL;
        (yyval.metadata).val.lref = turnNegative((yyvsp[0].lref));
    }
#line 2627 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 218: /* variable: IDENTIFIER  */
#line 939 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_VARIABLE.prefix.clear();
        CURRENT_VARIABLE.name = (yyvsp[0].sref)->symbol;
    }
#line 2636 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 219: /* variable: variable '.' IDENTIFIER  */
#line 944 "include/syntax-analyzer/components/yacc.y"
    {
        CURRENT_VARIABLE.prefix.append(":").append(CURRENT_VARIABLE.name);
        CURRENT_VARIABLE.name = (yyvsp[0].sref)->symbol;
    }
#line 2645 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 2649 "src/syntax-analyzer/components/parser.cpp"

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

#line 950 "include/syntax-analyzer/components/yacc.y"


void yyerror(const char* s)
{
    announceSyntaxError();
}
