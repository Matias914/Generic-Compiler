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
#line 40 "include/syntax-analyzer/components/yacc.y"

#include "syntax-analyzer/components/parser.h"
#include "syntax-analyzer/components/translator.h"
#include "syntax-analyzer/components/string_pool.h"
#include "syntax-analyzer/components/semantic_actions.h"

#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"
#include "code-generator/code-generator.h"

#define yylex LexicalAnalyzer::yylex

using namespace SyntaxAnalyzer;

// Parser Functions

void yyerror(const char* s);
int mapWithCheckerType(const int type);
char mapWithTripleOperator(const int op);
Triples::Operand mapWithOperand(const Metadata::Reference& ref);

// Avoids Code Repetition
void createArithmeticTriple(Metadata& r, const Metadata& o1, const Metadata& o2, const char op);


#line 98 "src/syntax-analyzer/components/parser.cpp"

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
  YYSYMBOL_return = 66,                    /* return  */
  YYSYMBOL_executable_stmt = 67,           /* executable_stmt  */
  YYSYMBOL_assignment_head = 68,           /* assignment_head  */
  YYSYMBOL_69_9 = 69,                      /* $@9  */
  YYSYMBOL_assignment_tail = 70,           /* assignment_tail  */
  YYSYMBOL_print = 71,                     /* print  */
  YYSYMBOL_72_10 = 72,                     /* $@10  */
  YYSYMBOL_print_end = 73,                 /* print_end  */
  YYSYMBOL_multiple_assignments = 74,      /* multiple_assignments  */
  YYSYMBOL_assignment_list = 75,           /* assignment_list  */
  YYSYMBOL_76_11 = 76,                     /* $@11  */
  YYSYMBOL_assignment_end = 77,            /* assignment_end  */
  YYSYMBOL_extra_numeric_constants = 78,   /* extra_numeric_constants  */
  YYSYMBOL_79_12 = 79,                     /* $@12  */
  YYSYMBOL_invocation = 80,                /* invocation  */
  YYSYMBOL_function_invocation_head = 81,  /* function_invocation_head  */
  YYSYMBOL_invocation_setup = 82,          /* invocation_setup  */
  YYSYMBOL_function_invocation_tail = 83,  /* function_invocation_tail  */
  YYSYMBOL_real_parameter_list = 84,       /* real_parameter_list  */
  YYSYMBOL_real_parameter_list_setup = 85, /* real_parameter_list_setup  */
  YYSYMBOL_real_parameter = 86,            /* real_parameter  */
  YYSYMBOL_lambda_invocation_head = 87,    /* lambda_invocation_head  */
  YYSYMBOL_88_13 = 88,                     /* $@13  */
  YYSYMBOL_lambda_invocation_tail = 89,    /* lambda_invocation_tail  */
  YYSYMBOL_lambda_real_parameter = 90,     /* lambda_real_parameter  */
  YYSYMBOL_if = 91,                        /* if  */
  YYSYMBOL_do_while_head = 92,             /* do_while_head  */
  YYSYMBOL_93_14 = 93,                     /* $@14  */
  YYSYMBOL_94_15 = 94,                     /* $@15  */
  YYSYMBOL_do_while_tail = 95,             /* do_while_tail  */
  YYSYMBOL_executable_body = 96,           /* executable_body  */
  YYSYMBOL_executable_statements = 97,     /* executable_statements  */
  YYSYMBOL_opt_trunc_constant = 98,        /* opt_trunc_constant  */
  YYSYMBOL_trunc_constant = 99,            /* trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 100,       /* opt_trunc_variable  */
  YYSYMBOL_trunc_variable = 101,           /* trunc_variable  */
  YYSYMBOL_trunc_expression = 102,         /* trunc_expression  */
  YYSYMBOL_condition = 103,                /* condition  */
  YYSYMBOL_comparison = 104,               /* comparison  */
  YYSYMBOL_comparison_operator = 105,      /* comparison_operator  */
  YYSYMBOL_expression = 106,               /* expression  */
  YYSYMBOL_expression_setup = 107,         /* expression_setup  */
  YYSYMBOL_term = 108,                     /* term  */
  YYSYMBOL_positive_term = 109,            /* positive_term  */
  YYSYMBOL_negative_term = 110,            /* negative_term  */
  YYSYMBOL_factor = 111,                   /* factor  */
  YYSYMBOL_positive_factor = 112,          /* positive_factor  */
  YYSYMBOL_negative_factor = 113,          /* negative_factor  */
  YYSYMBOL_numeric_constant = 114,         /* numeric_constant  */
  YYSYMBOL_positive_constant = 115,        /* positive_constant  */
  YYSYMBOL_negative_constant = 116,        /* negative_constant  */
  YYSYMBOL_variable = 117                  /* variable  */
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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1081

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  248
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  394

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
       0,   137,   137,   138,   139,   143,   147,   151,   153,   152,
     161,   165,   173,   177,   181,   192,   191,   206,   211,   216,
     226,   227,   231,   232,   233,   237,   241,   245,   250,   259,
     263,   268,   274,   273,   279,   278,   289,   293,   298,   297,
     305,   313,   317,   328,   327,   335,   339,   349,   348,   356,
     361,   370,   371,   373,   372,   380,   385,   390,   397,   401,
     406,   412,   421,   430,   431,   440,   441,   446,   452,   457,
     463,   467,   471,   475,   485,   486,   487,   488,   489,   490,
     491,   498,   497,   502,   510,   514,   524,   528,   533,   537,
     543,   542,   548,   556,   558,   566,   570,   575,   579,   585,
     593,   594,   595,   600,   599,   604,   608,   615,   616,   623,
     625,   627,   626,   636,   637,   642,   643,   653,   660,   681,
     699,   707,   717,   721,   727,   737,   745,   753,   766,   765,
     774,   779,   784,   789,   797,   798,   804,   808,   813,   817,
     822,   827,   832,   837,   843,   848,   854,   859,   865,   870,
     880,   884,   890,   889,   895,   894,   899,   907,   908,   918,
     919,   924,   928,   932,   933,   939,   940,   944,   959,   976,
     992,  1012,  1017,  1021,  1039,  1060,  1080,  1101,  1110,  1124,
    1142,  1159,  1182,  1183,  1188,  1192,  1200,  1217,  1228,  1232,
    1236,  1240,  1244,  1248,  1257,  1261,  1271,  1278,  1287,  1291,
    1299,  1303,  1311,  1315,  1319,  1326,  1337,  1341,  1348,  1352,
    1356,  1360,  1364,  1368,  1372,  1376,  1380,  1384,  1392,  1403,
    1407,  1411,  1415,  1419,  1423,  1431,  1439,  1446,  1453,  1462,
    1476,  1480,  1487,  1502,  1506,  1513,  1517,  1524,  1532,  1539,
    1555,  1564,  1578,  1582,  1589,  1594,  1602,  1613,  1620
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
  "formal_parameter", "parameter_semantics", "function_body", "return",
  "executable_stmt", "assignment_head", "$@9", "assignment_tail", "print",
  "$@10", "print_end", "multiple_assignments", "assignment_list", "$@11",
  "assignment_end", "extra_numeric_constants", "$@12", "invocation",
  "function_invocation_head", "invocation_setup",
  "function_invocation_tail", "real_parameter_list",
  "real_parameter_list_setup", "real_parameter", "lambda_invocation_head",
  "$@13", "lambda_invocation_tail", "lambda_real_parameter", "if",
  "do_while_head", "$@14", "$@15", "do_while_tail", "executable_body",
  "executable_statements", "opt_trunc_constant", "trunc_constant",
  "opt_trunc_variable", "trunc_variable", "trunc_expression", "condition",
  "comparison", "comparison_operator", "expression", "expression_setup",
  "term", "positive_term", "negative_term", "factor", "positive_factor",
  "negative_factor", "numeric_constant", "positive_constant",
  "negative_constant", "variable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-289)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-206)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     655,  -289,     8,   380,  1031,   882,   398,    10,  -289,  -289,
     176,  -289,  -289,   245,   684,  -289,  -289,  -289,   212,  -289,
    -289,  -289,  -289,  -289,  -289,    32,   971,   131,  -289,  -289,
      33,  -289,    47,   975,    38,  -289,  -289,   953,   435,   273,
     362,   611,  -289,  -289,   251,   904,    30,   486,   389,  -289,
     262,   358,  -289,  -289,  -289,  -289,    40,   942,  -289,    20,
      57,    82,    89,   118,   953,   504,   140,   255,  -289,   292,
     810,   178,  -289,  -289,   180,   133,  -289,   167,    40,  -289,
    -289,  -289,  -289,   444,   993,  -289,   296,  -289,  -289,   187,
     417,  -289,   218,  -289,   227,   224,  -289,   953,   536,    78,
    -289,   251,  -289,  -289,  -289,  -289,  -289,  -289,    40,  -289,
    -289,  -289,  -289,  -289,  -289,   402,   402,   400,   540,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,   454,   458,
     993,   262,   567,   582,   600,   608,   241,  -289,   914,   236,
    -289,  1011,  1011,  1011,  -289,   521,  -289,  -289,   246,  -289,
     250,   275,   519,   836,   303,   257,   846,  -289,  -289,  -289,
     713,  -289,  -289,  -289,   305,  -289,  -289,   429,  -289,  -289,
      64,   218,   993,  -289,  -289,  -289,   321,  -289,   320,   993,
     174,  -289,   126,  -289,  -289,   352,  -289,   327,  -289,  -289,
    -289,  -289,  -289,   539,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,   122,   331,  -289,  -289,   929,   136,  -289,   251,
    -289,  -289,   251,  -289,    80,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,   138,   150,  -289,  -289,  -289,   188,  -289,
    -289,   190,   197,  -289,  -289,   742,  -289,  -289,  -289,   771,
    -289,  -289,  -289,  -289,   429,  -289,  -289,   129,  -289,   494,
    -289,   551,  -289,    40,    40,  -289,  -289,  -289,  -289,   564,
     301,   301,   151,   316,    79,   615,  -289,  -289,   355,  -289,
    -289,   217,    66,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,   361,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    1053,  -289,   500,  -289,  -289,   429,  -289,   429,  -289,  -289,
     254,  -289,  -289,  -289,    24,   363,  -289,   369,   101,  -289,
    -289,  -289,  -289,   301,   301,  -289,   377,  -289,  -289,   199,
    -289,  -289,   336,  -289,   457,  -289,  -289,   397,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,   507,   401,   956,   397,   872,  -289,   215,   403,
     956,   344,   626,   414,  -289,  -289,  -289,    40,  -289,   237,
     800,  -289,  -289,   344,   419,   438,   461,   478,    39,  -289,
    -289,  -289,  -289,  -289,   462,  -289,  -289,  -289,    45,  -289,
    -289,  -289,  -289,  -289
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,     0,     0,     0,    41,    42,
     247,     8,    10,     0,     0,     2,     7,     5,     0,    79,
       6,    74,    78,    75,    76,     0,     0,     0,    77,    80,
       0,    11,     0,     0,   247,   245,   244,     0,     0,     0,
       0,     0,   234,   236,   202,     0,     0,     0,     0,   194,
     206,   207,   216,   223,   233,   235,   232,     0,   162,     0,
       0,     0,   152,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     1,     3,     0,   247,    34,     0,    36,   114,
     113,   121,   117,   125,     0,   122,     0,   116,   115,     0,
       0,   103,     0,   100,     0,     0,   149,     0,     0,     0,
     197,     0,   196,   241,   246,   237,   238,   240,   239,   228,
     226,   230,   231,   229,   227,     0,     0,     0,     0,   185,
     184,   187,   188,   190,   191,   189,   192,   193,     0,     0,
       0,   195,     0,     0,     0,     0,     0,   163,     0,     0,
     156,     0,     0,     0,    73,     0,    69,    72,    68,    92,
       0,     0,   205,     0,     0,     0,     0,    13,     9,    24,
       0,    20,    22,    23,     0,    30,    32,     0,    31,    29,
       0,     0,     0,   120,   124,   127,     0,    99,     0,     0,
       0,   247,     0,   248,    98,     0,    97,     0,   109,   166,
     165,   242,   243,     0,   181,   180,   183,   182,   213,   211,
     212,   210,     0,     0,   143,   140,     0,     0,   199,   203,
     198,   201,   204,   200,   205,   217,   215,   208,   218,   214,
     209,   224,   222,   219,   225,   221,   220,   161,   160,   159,
     164,   148,   155,     0,     0,   153,    67,    70,     0,    71,
      90,     0,     0,    19,    16,     0,   118,    28,    25,     0,
      14,    12,    21,   128,     0,    62,    57,     0,    35,    53,
      51,     0,    40,    37,    39,   123,   126,    83,    82,     0,
       0,     0,     0,     0,     0,     0,   179,   178,     0,   145,
     142,     0,     0,   137,   136,   158,   157,   151,   150,    66,
      65,    94,    87,    86,    89,    88,    18,    17,    27,    26,
       0,    33,    53,    56,    55,     0,    43,     0,    60,    61,
       0,    85,    84,   104,     0,     0,   106,   105,     0,   170,
     169,    96,    95,     0,     0,   144,     0,   147,   141,     0,
      93,    91,     0,   129,     0,    47,    52,     0,    54,    59,
      58,   108,   107,   102,   101,   168,   167,   110,   112,   146,
     139,   138,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,   135,   134,   172,   171,    48,     0,
       0,    46,    45,     0,     0,     0,     0,     0,     0,   133,
      50,    49,    64,    63,     0,   132,   131,   177,     0,   176,
     175,   130,   174,   173
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -289,  -289,   470,  -289,  -289,    13,  -289,  -289,  -147,  -158,
     134,  -289,  -289,  -289,  -289,    -1,  -289,  -289,  -289,  -289,
    -289,  -289,   242,  -289,  -288,  -289,   143,  -289,    44,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,    72,  -289,  -289,  -289,
    -289,  -289,    16,  -289,  -289,  -289,  -289,   -61,    37,  -289,
    -289,    87,  -289,  -289,  -289,  -289,   367,     2,  -276,   -87,
    -289,  -289,  -289,   -16,    -2,   499,  -289,    62,  -289,   -23,
     528,  -289,     9,   -12,    95,  -175,   -92,   -52,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    14,    15,    70,   158,   159,   153,   244,   160,   161,
     162,   254,   167,    77,   171,    18,   258,   337,   357,   301,
     355,   368,   259,   307,   260,   261,   358,    19,   163,    21,
     179,   268,    22,   291,   331,    23,    95,   180,   313,   275,
     324,    24,    42,    26,    82,    83,    84,    85,    43,   300,
     333,   363,    28,    29,   143,    61,   232,    59,   138,   364,
     189,   365,   366,    44,   233,    46,   130,    47,    48,    49,
      50,    51,   110,    52,    53,   190,    54,    55,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    45,   252,   191,    30,    30,   245,    62,   188,   249,
     274,    66,    71,    16,    30,   102,    25,   336,    78,   338,
      25,    25,   101,   174,   334,   341,   139,    16,   111,   111,
      25,   119,   101,    79,    89,    31,    71,    27,    67,   108,
     389,    27,    27,   192,    20,    30,   392,   118,    58,    58,
     114,    27,    90,   342,    91,   106,   352,    30,    20,    80,
     120,    25,    92,    71,    93,   262,    69,   328,    65,   390,
      30,    94,   329,    25,    96,   393,   107,    94,    94,   196,
     319,  -186,    27,    94,   140,   181,    25,   252,    86,    58,
     141,   252,   182,   191,    27,    98,    71,   142,   318,   198,
     200,   137,   345,   111,   111,   210,   213,    27,   197,   320,
    -186,   265,   209,   212,   128,   129,   216,   219,   222,   225,
     111,   111,   111,   111,   199,   201,   145,   271,   278,   152,
     303,   346,    87,   192,    17,   112,   112,   283,    30,   285,
     234,   217,   220,   223,   226,   144,    86,    91,    17,   279,
     304,   287,   316,    30,    25,    92,    30,    93,    88,   193,
      30,   166,   185,   284,    94,   286,   257,   149,   168,    25,
     263,   264,    25,    35,    36,    27,    25,   288,   191,   191,
     191,   191,   230,   314,   315,   317,   187,   274,   -38,   289,
      27,   292,   214,    27,   169,    91,   170,    27,   294,   164,
     350,    68,   318,    92,    69,    93,    30,   165,   282,   370,
     112,   112,   252,    74,   177,   290,   371,   293,   192,   192,
     192,   192,    25,   326,   295,   184,   351,   112,   112,   112,
     112,   191,   191,    75,    86,   185,   347,   348,   380,   181,
      76,   269,   372,    27,   327,    30,    35,    36,   183,    30,
      58,   186,   270,   257,   272,   339,   150,     8,     9,   187,
     310,    25,   191,   231,   381,    25,    33,   227,   191,   191,
     191,   192,   192,   239,   103,   340,    34,    35,    36,   151,
     240,   191,    27,    13,   247,   191,    27,   115,   116,    38,
      39,    40,    41,   154,    34,   104,   105,   175,   132,   133,
      30,    13,   192,  -119,   257,   241,   257,  -205,   192,   192,
     192,   176,   185,  -119,  -119,  -119,    25,  -205,  -205,  -205,
    -119,   192,  -119,    35,    36,   192,  -119,  -119,  -119,  -119,
     128,   129,    30,   246,    30,   253,   187,    27,    35,    36,
       3,     4,   266,     5,   137,     6,     7,   267,    25,   104,
      25,   187,    30,    71,   367,   362,    30,    34,   280,    71,
     367,   367,   378,   109,    13,   181,    35,    36,    25,    27,
      30,    27,    25,   367,    35,    36,   137,   388,   230,   187,
     273,    32,   325,    34,    35,    36,    25,   187,   330,    27,
      13,    33,   343,    27,   134,   135,   230,    39,   344,    63,
      33,    34,    35,    36,   349,   202,   203,    27,    37,    33,
      34,    35,    36,    33,    38,    39,    40,    41,   178,    34,
      35,    36,   356,    34,    35,    36,    64,   204,   -81,   361,
      13,   373,    38,    39,    40,    41,   100,    39,   -81,   -81,
     -81,     8,     9,   255,   379,   -81,    33,   374,   375,   385,
     256,   -81,   -81,   -81,   -81,   208,    34,    35,    36,   211,
     384,     3,     4,    13,     5,    33,     6,     7,   386,    33,
      39,    40,    41,   172,   173,    34,    35,    36,    34,    34,
      35,    36,    13,   353,    73,   354,    13,   121,   387,    39,
      40,    41,   391,    39,    40,    41,   302,  -205,   369,   181,
      35,    36,   122,   123,   124,   146,   125,  -205,  -205,  -205,
     235,     3,     4,   187,     5,  -205,     6,     7,   126,   127,
     128,   129,   236,   305,   306,  -205,  -205,  -205,    34,   305,
     335,   147,  -205,   359,   148,   360,    99,   194,   128,   129,
     276,   205,  -205,  -205,  -205,   206,   207,  -205,   237,   242,
    -205,   238,   308,   128,   129,   128,   129,  -205,  -205,  -205,
    -205,  -205,  -205,     8,     9,   311,   195,     0,   215,   277,
     128,   129,   309,   128,   129,  -205,   131,     0,    33,     0,
       0,     0,     0,   218,     0,  -205,  -205,  -205,    34,    35,
      36,   312,     0,    33,     0,    13,     0,     0,   128,   129,
       0,   221,    39,    34,    35,    36,     0,     0,     0,   224,
      13,    33,   113,     0,     0,     0,   321,    39,     0,    33,
       0,    34,    35,    36,     0,     0,  -111,   376,    13,    34,
      35,    36,    34,    35,    36,    39,    13,  -111,  -111,    13,
       0,     0,   322,    39,   323,     0,    39,   181,    35,    36,
    -111,     0,     0,     0,   377,     1,     2,     0,     0,     3,
       4,   187,     5,     0,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
      11,    12,     0,    13,    72,     2,     0,     0,     3,     4,
       0,     5,     0,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,    11,
      12,     0,    13,   250,   155,     0,     0,     3,     4,     0,
       5,     0,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,   156,   251,
       0,    13,   296,   155,     0,     0,     3,     4,     0,     5,
       0,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,   156,   297,     0,
      13,   298,   155,     0,     0,     3,     4,     0,     5,     0,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   156,   299,     0,    13,
     382,   155,     0,     0,     3,     4,     0,     5,     0,     6,
       7,   155,     8,     9,     3,     4,     0,     5,     0,     6,
       7,    10,     8,     9,     0,   156,   383,     0,    13,     0,
       0,    10,     0,     0,     0,   156,   157,   155,    13,     0,
       3,     4,     0,     5,     0,     6,     7,   155,     8,     9,
       3,     4,     0,     5,     0,     6,     7,    10,     8,     9,
       0,   156,   243,     0,    13,     0,     0,    10,     0,     0,
       0,   156,   248,   155,    13,     0,     3,     4,     0,     5,
       0,     6,     7,    60,     8,     9,     3,     4,     0,     5,
    -154,     6,     7,    10,     0,     0,     0,   156,     0,     0,
      13,     0,     0,    34,     0,   117,     0,    57,     3,     4,
      13,     5,     0,     6,     7,   228,     0,     0,     3,     4,
       0,     5,     0,     6,     7,    34,     0,     0,     0,    57,
     281,     0,    13,     3,     4,    34,     5,     0,     6,     7,
     229,     0,    13,   136,     0,     0,     3,     4,     0,     5,
      34,     6,     7,     0,    57,     0,     0,    13,     0,     0,
       0,     0,     0,    34,    33,     8,     9,   362,     8,     9,
      13,     0,     0,     0,    34,    35,    36,   181,    35,    36,
       0,    13,    33,     0,     0,     0,    33,    38,    39,    40,
      41,   187,    34,    35,    36,     0,    34,    35,    36,    13,
       0,    81,     0,    97,    33,    38,    39,    40,    41,    38,
      39,    40,    41,     0,    34,    35,    36,     0,     0,     0,
       0,    13,    33,     0,     0,     0,     0,    38,    39,    40,
      41,     0,    34,    35,    36,     3,     4,     0,     5,    37,
       6,     7,     0,     0,     0,    38,    39,    40,    41,     0,
       0,     0,    34,     0,     0,     0,    57,     3,     4,    13,
       5,     0,     6,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,   332,     0,
       0,    13
};

static const yytype_int16 yycheck[] =
{
       0,     3,   160,    95,     4,     5,   153,     5,    95,   156,
     185,     1,    13,     0,    14,    38,     0,   305,    18,   307,
       4,     5,    38,    84,   300,     1,     6,    14,    40,    41,
      14,     1,    48,     1,     1,    27,    37,     0,    28,    39,
       1,     4,     5,    95,     0,    45,     1,    45,     4,     5,
      41,    14,    19,    29,    21,    39,   332,    57,    14,    27,
      30,    45,    29,    64,    31,     1,    28,     1,     6,    30,
      70,    38,     6,    57,    27,    30,    39,    38,    38,     1,
       1,     1,    45,    38,    27,    21,    70,   245,    26,    45,
       8,   249,    92,   185,    57,    33,    97,     8,   273,   115,
     116,    57,     1,   115,   116,   128,   129,    70,    30,    30,
      30,   172,   128,   129,    34,    35,   132,   133,   134,   135,
     132,   133,   134,   135,   115,   116,    64,     1,     6,    67,
       1,    30,     1,   185,     0,    40,    41,     1,   138,     1,
     142,   132,   133,   134,   135,    27,    84,    21,    14,    27,
      21,     1,     1,   153,   138,    29,   156,    31,    27,    97,
     160,    28,    11,    27,    38,    27,   167,    27,     1,   153,
     170,   171,   156,    22,    23,   138,   160,    27,   270,   271,
     272,   273,   138,   270,   271,   272,    35,   362,    21,     1,
     153,     1,   130,   156,    27,    21,    29,   160,     1,    21,
       1,    25,   377,    29,    28,    31,   206,    27,   206,   356,
     115,   116,   370,     1,    27,    27,     1,    27,   270,   271,
     272,   273,   206,     6,    27,     1,    27,   132,   133,   134,
     135,   323,   324,    21,   172,    11,   323,   324,     1,    21,
      28,   179,    27,   206,    27,   245,    22,    23,    21,   249,
     206,    27,   180,   254,   182,     1,     1,    12,    13,    35,
     261,   245,   354,    27,    27,   249,    11,    26,   360,   361,
     362,   323,   324,    27,     1,    21,    21,    22,    23,    24,
      30,   373,   245,    28,    27,   377,   249,    36,    37,    34,
      35,    36,    37,     1,    21,    22,    23,     1,    36,    37,
     300,    28,   354,    11,   305,    30,   307,    11,   360,   361,
     362,    15,    11,    21,    22,    23,   300,    21,    22,    23,
      28,   373,    30,    22,    23,   377,    34,    35,    36,    37,
      34,    35,   332,    30,   334,    30,    35,   300,    22,    23,
       4,     5,    21,     7,   300,     9,    10,    27,   332,    22,
     334,    35,   352,   354,   354,    11,   356,    21,    27,   360,
     360,   361,   362,     1,    28,    21,    22,    23,   352,   332,
     370,   334,   356,   373,    22,    23,   332,   377,   334,    35,
      28,     1,    27,    21,    22,    23,   370,    35,    27,   352,
      28,    11,    29,   356,    36,    37,   352,    35,    29,     1,
      11,    21,    22,    23,    27,     5,     6,   370,    28,    11,
      21,    22,    23,    11,    34,    35,    36,    37,     1,    21,
      22,    23,    25,    21,    22,    23,    28,    27,    11,    28,
      28,    28,    34,    35,    36,    37,     1,    35,    21,    22,
      23,    12,    13,    14,    30,    28,    11,   360,   361,    30,
      21,    34,    35,    36,    37,     1,    21,    22,    23,     1,
     373,     4,     5,    28,     7,    11,     9,    10,    30,    11,
      35,    36,    37,    29,    30,    21,    22,    23,    21,    21,
      22,    23,    28,    26,    14,    28,    28,     1,    27,    35,
      36,    37,    30,    35,    36,    37,   254,    11,   355,    21,
      22,    23,    16,    17,    18,     1,    20,    21,    22,    23,
     143,     4,     5,    35,     7,    11,     9,    10,    32,    33,
      34,    35,     1,    29,    30,    21,    22,    23,    21,    29,
      30,    27,    11,    26,    30,    28,    37,     1,    34,    35,
       1,     1,    21,    22,    23,     5,     6,    11,    27,    30,
      11,    30,     1,    34,    35,    34,    35,    21,    22,    23,
      21,    22,    23,    12,    13,     1,    30,    -1,     1,    30,
      34,    35,    21,    34,    35,    11,    48,    -1,    11,    -1,
      -1,    -1,    -1,     1,    -1,    21,    22,    23,    21,    22,
      23,    27,    -1,    11,    -1,    28,    -1,    -1,    34,    35,
      -1,     1,    35,    21,    22,    23,    -1,    -1,    -1,     1,
      28,    11,     1,    -1,    -1,    -1,     1,    35,    -1,    11,
      -1,    21,    22,    23,    -1,    -1,    11,     1,    28,    21,
      22,    23,    21,    22,    23,    35,    28,    22,    23,    28,
      -1,    -1,    27,    35,    29,    -1,    35,    21,    22,    23,
      35,    -1,    -1,    -1,    28,     0,     1,    -1,    -1,     4,
       5,    35,     7,    -1,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    28,     0,     1,    -1,    -1,     4,     5,
      -1,     7,    -1,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,
      26,    -1,    28,     0,     1,    -1,    -1,     4,     5,    -1,
       7,    -1,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,
      -1,    28,     0,     1,    -1,    -1,     4,     5,    -1,     7,
      -1,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    -1,
      28,     0,     1,    -1,    -1,     4,     5,    -1,     7,    -1,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    25,    26,    -1,    28,
       0,     1,    -1,    -1,     4,     5,    -1,     7,    -1,     9,
      10,     1,    12,    13,     4,     5,    -1,     7,    -1,     9,
      10,    21,    12,    13,    -1,    25,    26,    -1,    28,    -1,
      -1,    21,    -1,    -1,    -1,    25,    26,     1,    28,    -1,
       4,     5,    -1,     7,    -1,     9,    10,     1,    12,    13,
       4,     5,    -1,     7,    -1,     9,    10,    21,    12,    13,
      -1,    25,    26,    -1,    28,    -1,    -1,    21,    -1,    -1,
      -1,    25,    26,     1,    28,    -1,     4,     5,    -1,     7,
      -1,     9,    10,     1,    12,    13,     4,     5,    -1,     7,
       8,     9,    10,    21,    -1,    -1,    -1,    25,    -1,    -1,
      28,    -1,    -1,    21,    -1,     1,    -1,    25,     4,     5,
      28,     7,    -1,     9,    10,     1,    -1,    -1,     4,     5,
      -1,     7,    -1,     9,    10,    21,    -1,    -1,    -1,    25,
       1,    -1,    28,     4,     5,    21,     7,    -1,     9,    10,
      26,    -1,    28,     1,    -1,    -1,     4,     5,    -1,     7,
      21,     9,    10,    -1,    25,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    21,    11,    12,    13,    11,    12,    13,
      28,    -1,    -1,    -1,    21,    22,    23,    21,    22,    23,
      -1,    28,    11,    -1,    -1,    -1,    11,    34,    35,    36,
      37,    35,    21,    22,    23,    -1,    21,    22,    23,    28,
      -1,    30,    -1,    28,    11,    34,    35,    36,    37,    34,
      35,    36,    37,    -1,    21,    22,    23,    -1,    -1,    -1,
      -1,    28,    11,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    -1,    21,    22,    23,     4,     5,    -1,     7,    28,
       9,    10,    -1,    -1,    -1,    34,    35,    36,    37,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    25,     4,     5,    28,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    -1,
      -1,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     0,     1,     4,     5,     7,     9,    10,    12,    13,
      21,    25,    26,    28,    40,    41,    44,    49,    54,    66,
      67,    68,    71,    74,    80,    81,    82,    87,    91,    92,
     117,    27,     1,    11,    21,    22,    23,    28,    34,    35,
      36,    37,    81,    87,   102,   103,   104,   106,   107,   108,
     109,   110,   112,   113,   115,   116,   117,    25,    67,    96,
       1,    94,    96,     1,    28,   106,     1,    28,    25,    28,
      42,    54,     0,    41,     1,    21,    28,    52,   117,     1,
      27,    30,    83,    84,    85,    86,   106,     1,    27,     1,
      19,    21,    29,    31,    38,    75,    27,    28,   106,   104,
       1,   102,   108,     1,    22,    23,    81,    87,   117,     1,
     111,   112,   113,     1,   111,    36,    37,     1,    96,     1,
      30,     1,    16,    17,    18,    20,    32,    33,    34,    35,
     105,   109,    36,    37,    36,    37,     1,    67,    97,     6,
      27,     8,     8,    93,    27,   106,     1,    27,    30,    27,
       1,    24,   106,    45,     1,     1,    25,    26,    43,    44,
      47,    48,    49,    67,    21,    27,    28,    51,     1,    27,
      29,    53,    29,    30,    86,     1,    15,    27,     1,    69,
      76,    21,   117,    21,     1,    11,    27,    35,    98,    99,
     114,   115,   116,   106,     1,    30,     1,    30,   102,   111,
     102,   111,     5,     6,    27,     1,     5,     6,     1,   102,
     108,     1,   102,   108,   106,     1,   102,   111,     1,   102,
     111,     1,   102,   111,     1,   102,   111,    26,     1,    26,
      67,    27,    95,   103,   103,    95,     1,    27,    30,    27,
      30,    30,    30,    26,    46,    47,    30,    27,    26,    47,
       0,    26,    48,    30,    50,    14,    21,    54,    55,    61,
      63,    64,     1,   117,   117,    86,    21,    27,    70,   106,
      75,     1,    75,    28,   114,    78,     1,    30,     6,    27,
      27,     1,    96,     1,    27,     1,    27,     1,    27,     1,
      27,    72,     1,    27,     1,    27,     0,    26,     0,    26,
      88,    58,    61,     1,    21,    29,    30,    62,     1,    21,
      54,     1,    27,    77,    98,    98,     1,    98,   114,     1,
      30,     1,    27,    29,    79,    27,     6,    27,     1,     6,
      27,    73,    25,    89,    97,    30,    63,    56,    63,     1,
      21,     1,    29,    29,    29,     1,    30,    98,    98,    27,
       1,    27,    97,    26,    28,    59,    25,    57,    65,    26,
      28,    28,    11,    90,    98,   100,   101,   117,    60,    65,
      47,     1,    27,    28,    90,    90,     1,    28,   117,    30,
       1,    27,     0,    26,    90,    30,    30,    27,   117,     1,
      30,    30,     1,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    41,    41,    42,    41,
      41,    41,    43,    43,    43,    45,    44,    46,    46,    46,
      47,    47,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    49,    50,    49,    51,    49,    52,    52,    53,    52,
      52,    54,    54,    56,    55,    57,    57,    59,    58,    60,
      60,    61,    61,    62,    61,    63,    63,    63,    63,    63,
      63,    63,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    69,    68,    68,    70,    70,    71,    71,    71,    71,
      72,    71,    71,    73,    73,    74,    74,    74,    74,    74,
      75,    75,    75,    76,    75,    75,    75,    77,    77,    78,
      78,    79,    78,    80,    80,    80,    80,    81,    81,    82,
      83,    83,    84,    84,    84,    85,    86,    86,    88,    87,
      89,    89,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      92,    92,    93,    92,    94,    92,    92,    95,    95,    96,
      96,    96,    96,    97,    97,    98,    98,    99,    99,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   102,   102,
     102,   102,   103,   103,   103,   103,   104,   104,   105,   105,
     105,   105,   105,   105,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   107,   108,   108,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   115,   116,   117,   117
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
       2,     2,     1,     3,     3,     5,     5,     4,     3,     3,
       4,     4,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     4,     2,     2,     5,     5,     5,     5,
       0,     6,     3,     1,     0,     5,     5,     3,     3,     3,
       1,     5,     5,     0,     4,     4,     4,     2,     2,     0,
       3,     0,     3,     2,     2,     2,     2,     2,     4,     2,
       2,     1,     1,     3,     2,     1,     3,     2,     0,     6,
       6,     5,     5,     4,     1,     1,     5,     5,     7,     7,
       4,     6,     5,     4,     6,     5,     7,     6,     4,     3,
       5,     5,     0,     4,     0,     4,     3,     2,     2,     3,
       3,     3,     1,     1,     2,     1,     1,     4,     4,     3,
       3,     1,     1,     4,     4,     3,     3,     3,     4,     4,
       3,     3,     3,     3,     2,     2,     3,     2,     1,     1,
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
#line 144 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1636 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 148 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1644 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 8: /* $@1: %empty  */
#line 153 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::addInvalidScope();
        SemanticActions::announceSpecificError(MISSING_PROGRAM_NAME);

        SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration("");

    }
#line 1656 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '}'  */
#line 162 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1664 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: error ';'  */
#line 166 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1673 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* unnamed_program_tail: program_statements '}'  */
#line 174 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1681 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* unnamed_program_tail: '}'  */
#line 178 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1689 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* unnamed_program_tail: program_statements $end  */
#line 182 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1698 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 15: /* $@2: %empty  */
#line 192 "include/syntax-analyzer/components/yacc.y"
    {
        const std::string s = (yyvsp[-1].sref)->symbol;
        if (SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration(s) != nullptr)
        {
            SemanticAnalyzer::addScope(s);
            CodeGenerator::addIntermediateCodeBlock(s);
        }
        else
            SemanticAnalyzer::addInvalidScope();
    }
#line 1713 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 17: /* program_tail: program_statements '}'  */
#line 207 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1722 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 18: /* program_tail: program_statements $end  */
#line 212 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticAnalyzer::removeScope();
    }
#line 1731 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 19: /* program_tail: '}'  */
#line 217 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1740 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* program_statement: program_head  */
#line 234 "include/syntax-analyzer/components/yacc.y"
    {
       SemanticActions::announceSpecificError(INVALID_PROGRAM_NESTING);
    }
#line 1748 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* program_statement: '{' '}'  */
#line 238 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1756 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* program_statement: '{' program_statements '}'  */
#line 242 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1764 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* program_statement: '{' program_statements $end  */
#line 246 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);
    }
#line 1773 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* program_statement: error ';'  */
#line 251 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 1781 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type variable_list ';'  */
#line 260 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("VARIABLE DECLARATION");
    }
#line 1789 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* declarative_stmt: type error ';'  */
#line 264 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1798 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 31: /* declarative_stmt: type variable_list error  */
#line 269 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1807 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* $@3: %empty  */
#line 274 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionName((yyvsp[-1].sref)->symbol);
    }
#line 1815 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 34: /* $@4: %empty  */
#line 279 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionWithoutName();
        SemanticActions::announceSpecificError(MISSING_FUNCTION_NAME);
    }
#line 1824 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 36: /* variable_list: variable  */
#line 290 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1832 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* variable_list: variable_list ',' variable  */
#line 294 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1840 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 38: /* $@5: %empty  */
#line 298 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 1848 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 39: /* variable_list: variable_list $@5 variable  */
#line 302 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1856 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* variable_list: variable_list ',' error  */
#line 306 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1865 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* type: UINT  */
#line 314 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = ST_UINT;
    }
#line 1873 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* type: FLOAT  */
#line 318 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = ST_FLOAT;
        SemanticActions::announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1882 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* $@6: %empty  */
#line 328 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
    }
#line 1890 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* unnamed_function_declaration_tail: function_body ';'  */
#line 336 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1898 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* unnamed_function_declaration_tail: function_body error  */
#line 340 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1908 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* $@7: %empty  */
#line 349 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
    }
#line 1916 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 49: /* function_declaration_tail: function_body ';'  */
#line 357 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("FUNCTION DECLARATION");
        SemanticAnalyzer::removeScope();
    }
#line 1925 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 50: /* function_declaration_tail: function_body error  */
#line 362 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
        SemanticAnalyzer::removeScope();
    }
#line 1935 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 53: /* $@8: %empty  */
#line 373 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 1943 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* formal_parameter: type IDENTIFIER  */
#line 381 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(ST_CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
    }
#line 1952 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 56: /* formal_parameter: type error  */
#line 386 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1961 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* formal_parameter: IDENTIFIER  */
#line 391 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = ST_UNSUPPORTED;
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(ST_CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    }
#line 1972 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* formal_parameter: parameter_semantics type IDENTIFIER  */
#line 398 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
    }
#line 1980 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* formal_parameter: parameter_semantics type error  */
#line 402 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    }
#line 1989 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* formal_parameter: parameter_semantics error  */
#line 407 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        SemanticActions::announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;
    }
#line 1999 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 413 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = ST_UNSUPPORTED;
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    }
#line 2009 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* parameter_semantics: CR  */
#line 422 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(ST_CR);
    }
#line 2017 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* function_body: '{' program_statements $end  */
#line 432 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 2025 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 66: /* return: RETURN '(' expression ')' error  */
#line 442 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2034 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 67: /* return: RETURN '(' expression error  */
#line 447 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2044 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 68: /* return: RETURN expression ')'  */
#line 453 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
    }
#line 2053 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 69: /* return: RETURN expression error  */
#line 458 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2063 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* return: RETURN '(' expression ';'  */
#line 464 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_PARENTHESIS);
    }
#line 2071 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* return: RETURN expression ')' ';'  */
#line 468 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2079 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* return: RETURN expression ';'  */
#line 472 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);
    }
#line 2087 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 73: /* return: RETURN error ';'  */
#line 476 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(RETURN_SYNTAX_ERROR);
        yyerrok;
    }
#line 2096 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* $@9: %empty  */
#line 498 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
    }
#line 2104 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* assignment_head: variable ASSIGN_OP error ';'  */
#line 503 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;
    }
#line 2113 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 84: /* assignment_tail: expression ';'  */
#line 511 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("ASSIGNMENT");
    }
#line 2121 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 85: /* assignment_tail: expression error  */
#line 515 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2130 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 86: /* print: PRINT '(' STRING_LITERAL ')' ';'  */
#line 525 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PRINT");
    }
#line 2138 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* print: PRINT '(' STRING_LITERAL ')' error  */
#line 529 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2147 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 88: /* print: PRINT '(' expression ')' ';'  */
#line 534 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PRINT");
    }
#line 2155 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 89: /* print: PRINT '(' expression ')' error  */
#line 538 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2164 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* $@10: %empty  */
#line 543 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 2173 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 92: /* print: PRINT error ';'  */
#line 549 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(PRINT_SYNTAX_ERROR);
        yyerrok;
    }
#line 2182 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 94: /* print_end: %empty  */
#line 558 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
    }
#line 2190 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 567 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");
    }
#line 2198 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 571 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2207 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* multiple_assignments: variable assignment_list ';'  */
#line 576 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_RIGHT_SIDE_VALUES);
    }
#line 2215 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 98: /* multiple_assignments: variable assignment_list error  */
#line 580 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2225 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 99: /* multiple_assignments: variable error ';'  */
#line 586 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;
    }
#line 2234 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 596 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_EQUALS);
    }
#line 2242 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 103: /* $@11: %empty  */
#line 600 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_COMMA);
    }
#line 2250 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 105: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 605 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2258 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 106: /* assignment_list: ',' variable assignment_list error  */
#line 609 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 2266 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* assignment_end: opt_trunc_constant error  */
#line 617 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 2275 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* $@12: %empty  */
#line 627 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2283 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 114: /* invocation: function_invocation_head error  */
#line 638 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2292 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 116: /* invocation: lambda_invocation_head error  */
#line 644 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2301 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 117: /* function_invocation_head: invocation_setup function_invocation_tail  */
#line 654 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);
        StringPool::append((yyval.metadata).expression.pid, *StringPool::get((yyvsp[0].metadata).expression.pid));

        SemanticActions::logStructure("FUNCTION INVOCATION");
    }
#line 2312 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 118: /* function_invocation_head: IDENTIFIER '(' error ')'  */
#line 661 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression.pid = StringPool::create((yyvsp[-3].sref)->symbol + "(...)");
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_INVOCATIONS.checkFunctionInScope((yyvsp[-3].sref)->symbol);
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = PR_SYMBOL;
            (yyval.metadata).expression.type = mapWithCheckerType((yyval.metadata).reference.sref->type);
        }
        else
        {
            (yyval.metadata).reference.type = PR_NULL;
            (yyval.metadata).expression.type = TC_UNSUPPORTED;
        }

        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 2334 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* invocation_setup: IDENTIFIER '('  */
#line 682 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression.pid = StringPool::create((yyvsp[-1].sref)->symbol + "(");
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_INVOCATIONS.checkFunctionInScope((yyvsp[-1].sref)->symbol);
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = PR_SYMBOL;
            (yyval.metadata).expression.type = mapWithCheckerType((yyval.metadata).reference.sref->type);
        }
        else
        {
            (yyval.metadata).reference.type = PR_NULL;
            (yyval.metadata).expression.type = TC_UNSUPPORTED;
        }
    }
#line 2353 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* function_invocation_tail: real_parameter_list ')'  */
#line 700 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, ")");
        (yyval.metadata).expression.type = TC_UNSUPPORTED;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
    }
#line 2365 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 121: /* function_invocation_tail: ')'  */
#line 708 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create(")") };

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
        SemanticActions::announceSpecificError(MISSING_ARGUMENT);
    }
#line 2376 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* real_parameter_list: real_parameter  */
#line 718 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 2384 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* real_parameter_list: real_parameter_list ',' real_parameter  */
#line 722 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].metadata).expression.pid, ", " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = TC_UNSUPPORTED;
        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
    }
#line 2394 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 124: /* real_parameter_list: real_parameter_list_setup real_parameter  */
#line 728 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = TC_UNSUPPORTED;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

    }
#line 2405 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 125: /* real_parameter_list_setup: real_parameter_list  */
#line 738 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2414 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* real_parameter: expression POINTER_OP IDENTIFIER  */
#line 746 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].metadata).expression.pid, "->" + (yyvsp[0].sref)->symbol);
        (yyval.metadata).expression.type = TC_UNSUPPORTED;
        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.checkParameterInScope((yyvsp[0].sref)->symbol);
    }
#line 2426 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* real_parameter: expression error  */
#line 754 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2437 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* $@13: %empty  */
#line 766 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::addLambdaScope();
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[-1].sref)->symbol);
    }
#line 2446 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* lambda_invocation_tail: '{' executable_statements '}' '(' lambda_real_parameter ')'  */
#line 775 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::logStructure("LAMBDA");
    }
#line 2455 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 131: /* lambda_invocation_tail: executable_statements '}' '(' lambda_real_parameter ')'  */
#line 780 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 2464 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 132: /* lambda_invocation_tail: '{' executable_statements '(' lambda_real_parameter ')'  */
#line 785 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 2473 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* lambda_invocation_tail: executable_statements '(' lambda_real_parameter ')'  */
#line 790 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_BOTH_BRACKETS);
    }
#line 2482 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 136: /* if: IF condition executable_body ENDIF ';'  */
#line 805 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("IF");
    }
#line 2490 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 137: /* if: IF condition executable_body ENDIF error  */
#line 809 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2499 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* if: IF condition executable_body ELSE executable_body ENDIF ';'  */
#line 814 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("IF-ELSE");
    }
#line 2507 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 139: /* if: IF condition executable_body ELSE executable_body ENDIF error  */
#line 818 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2516 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 140: /* if: IF condition executable_body error  */
#line 823 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2525 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* if: IF condition executable_body ELSE executable_body error  */
#line 828 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    }
#line 2534 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 142: /* if: IF condition error ENDIF ';'  */
#line 833 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2543 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* if: IF condition error ';'  */
#line 838 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2553 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* if: IF condition error ELSE ENDIF ';'  */
#line 844 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2562 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* if: IF condition error ELSE ';'  */
#line 849 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2572 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 146: /* if: IF condition executable_body ELSE error ENDIF ';'  */
#line 855 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;
    }
#line 2581 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 147: /* if: IF condition executable_body ELSE error ';'  */
#line 860 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;
    }
#line 2591 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 148: /* if: ELSE executable_body ENDIF ';'  */
#line 866 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;
    }
#line 2600 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* if: IF error ';'  */
#line 871 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;
    }
#line 2609 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 150: /* do_while_head: DO executable_body WHILE condition ';'  */
#line 881 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("DO-WHILE");
    }
#line 2617 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* do_while_head: DO executable_body WHILE condition error  */
#line 885 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2626 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 152: /* $@14: %empty  */
#line 890 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE);
    }
#line 2634 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 154: /* $@15: %empty  */
#line 895 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
    }
#line 2642 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* do_while_head: DO error ';'  */
#line 900 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;
    }
#line 2651 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* do_while_tail: condition error  */
#line 909 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2660 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* executable_body: '{' executable_statements error  */
#line 920 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    }
#line 2669 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 161: /* executable_body: '{' error '}'  */
#line 925 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 2677 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 167: /* trunc_constant: TRUNC '(' numeric_constant ')'  */
#line 945 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_TYPES.checkTruncate(e);

         if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
         {
             (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                 {TR_FTOI, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr })}
             );
             (yyval.metadata).reference.type = PR_TRIPLE;
         }


    }
#line 2696 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 168: /* trunc_constant: TRUNC '(' numeric_constant error  */
#line 960 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_TYPES.checkTruncate(e);

         if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
         {
             (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                 {TR_FTOI, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr })}
             );
             (yyval.metadata).reference.type = PR_TRIPLE;
         }

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 2717 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 169: /* trunc_constant: TRUNC numeric_constant ')'  */
#line 977 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_TYPES.checkTruncate(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                {TR_FTOI, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr })}
            );
            (yyval.metadata).reference.type = PR_TRIPLE;
        }

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 2737 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 170: /* trunc_constant: TRUNC numeric_constant error  */
#line 993 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_TYPES.checkTruncate(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                {TR_FTOI, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr })}
            );
            (yyval.metadata).reference.type = PR_TRIPLE;
        }

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 2758 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 171: /* opt_trunc_variable: variable  */
#line 1013 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

    }
#line 2767 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* trunc_variable: TRUNC '(' variable ')'  */
#line 1022 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            SemanticAnalyzer::TypeChecker::Expression e = { mapWithCheckerType(entry->type), *StringPool::get((yyvsp[-1].pid)) };
            SemanticAnalyzer::CHK_TYPES.checkTruncate(e);

            if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            {
                (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                    {TR_FTOI, mapWithOperand({ PR_SYMBOL, entry }), mapWithOperand({ PR_NULL, nullptr })}
                );
                (yyval.metadata).reference.type = PR_TRIPLE;
            }
        }

    }
#line 2789 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* trunc_variable: TRUNC '(' variable error  */
#line 1040 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            SemanticAnalyzer::TypeChecker::Expression e = { mapWithCheckerType(entry->type), *StringPool::get((yyvsp[-1].pid)) };
            SemanticAnalyzer::CHK_TYPES.checkTruncate(e);

            if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            {
                (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                    {TR_FTOI, mapWithOperand({ PR_SYMBOL, entry }), mapWithOperand({ PR_NULL, nullptr })}
                );
                (yyval.metadata).reference.type = PR_TRIPLE;
            }
        }

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 2814 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* trunc_variable: TRUNC variable ')'  */
#line 1061 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            SemanticAnalyzer::TypeChecker::Expression e = { mapWithCheckerType(entry->type), *StringPool::get((yyvsp[-1].pid)) };
            SemanticAnalyzer::CHK_TYPES.checkTruncate(e);

            if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            {
                (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                    {TR_FTOI, mapWithOperand({ PR_SYMBOL, entry }), mapWithOperand({ PR_NULL, nullptr })}
                );
                (yyval.metadata).reference.type = PR_TRIPLE;
            }
        }

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 2838 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 176: /* trunc_variable: TRUNC variable error  */
#line 1081 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            SemanticAnalyzer::TypeChecker::Expression e = { mapWithCheckerType(entry->type), *StringPool::get((yyvsp[-1].pid)) };
            SemanticAnalyzer::CHK_TYPES.checkTruncate(e);

            if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            {
                (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                    {TR_FTOI, mapWithOperand({ PR_SYMBOL, entry }), mapWithOperand({ PR_NULL, nullptr })}
                );
                (yyval.metadata).reference.type = PR_TRIPLE;
            }
        }

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 2863 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* trunc_variable: TRUNC error ';'  */
#line 1102 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;

    }
#line 2873 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 178: /* trunc_expression: TRUNC '(' expression ')'  */
#line 1111 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkTruncate(e);
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                {TR_FTOI, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr })}
            );
            (yyval.metadata).reference.type = PR_TRIPLE;
        }
    }
#line 2891 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 179: /* trunc_expression: TRUNC '(' expression error  */
#line 1125 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkTruncate(e);
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                {TR_FTOI, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr })}
            );
            (yyval.metadata).reference.type = PR_TRIPLE;
        }

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 2913 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 180: /* trunc_expression: TRUNC expression ')'  */
#line 1143 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkTruncate(e);
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                {TR_FTOI, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr })}
            );
            (yyval.metadata).reference.type = PR_TRIPLE;
        }

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 2934 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 181: /* trunc_expression: TRUNC expression error  */
#line 1160 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkTruncate(e);
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                {TR_FTOI, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr })}
            );
            (yyval.metadata).reference.type = PR_TRIPLE;
        }

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 2956 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* condition: '(' comparison error  */
#line 1184 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 2965 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* condition: comparison ')'  */
#line 1189 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 2973 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 185: /* condition: comparison error  */
#line 1193 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    }
#line 2982 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 186: /* comparison: expression comparison_operator expression  */
#line 1201 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
        StringPool::append((yyvsp[-2].metadata).expression.pid, *StringPool::get((yyvsp[-1].op).pid) + *StringPool::get((yyvsp[0].metadata).expression.pid));

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                {(yyvsp[-1].op).tid, mapWithOperand((yyvsp[-2].metadata).reference), mapWithOperand((yyvsp[0].metadata).reference)}
            );
            (yyval.metadata).reference.type = PR_TRIPLE;
        }
    }
#line 3003 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 187: /* comparison: expression error  */
#line 1218 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;

    }
#line 3015 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 188: /* comparison_operator: EQUAL_OP  */
#line 1229 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator(EQUAL_OP), StringPool::create(Translator::translate(EQUAL_OP)) };
    }
#line 3023 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 189: /* comparison_operator: NOT_EQUAL_OP  */
#line 1233 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator(NOT_EQUAL_OP), StringPool::create(Translator::translate(NOT_EQUAL_OP)) };
    }
#line 3031 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* comparison_operator: GE_OP  */
#line 1237 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator(GE_OP), StringPool::create(Translator::translate(GE_OP)) };
    }
#line 3039 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* comparison_operator: LE_OP  */
#line 1241 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator(LE_OP), StringPool::create(Translator::translate(LE_OP)) };
    }
#line 3047 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* comparison_operator: '>'  */
#line 1245 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator('>'), StringPool::create(">") };
    }
#line 3055 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* comparison_operator: '<'  */
#line 1249 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator('<'), StringPool::create("<") };
    }
#line 3063 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 194: /* expression: term  */
#line 1258 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3071 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 195: /* expression: expression_setup positive_term  */
#line 1262 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;
        (yyval.metadata).reference = (yyvsp[-1].metadata).reference;
    }
#line 3085 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 196: /* expression: '+' term  */
#line 1272 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUM_OPERAND);

    }
#line 3096 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 197: /* expression: '+' error  */
#line 1279 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("...") };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;

    }
#line 3109 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 198: /* expression: expression '+' term  */
#line 1288 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 3117 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 199: /* expression: expression '+' error  */
#line 1292 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 3129 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 200: /* expression: expression '-' term  */
#line 1300 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 3137 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 201: /* expression: expression '-' error  */
#line 1304 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 3149 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 202: /* expression: trunc_expression  */
#line 1312 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3157 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 203: /* expression: expression '+' trunc_expression  */
#line 1316 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 3165 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 204: /* expression: expression '-' trunc_expression  */
#line 1320 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 3173 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 205: /* expression_setup: expression  */
#line 1327 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 3183 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 206: /* term: positive_term  */
#line 1338 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3191 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 207: /* term: negative_term  */
#line 1342 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3199 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 208: /* positive_term: positive_term '*' factor  */
#line 1349 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3207 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 209: /* positive_term: positive_term '/' factor  */
#line 1353 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3215 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* positive_term: trunc_expression '/' factor  */
#line 1357 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3223 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 211: /* positive_term: trunc_expression '*' factor  */
#line 1361 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3231 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 212: /* positive_term: trunc_expression '/' trunc_expression  */
#line 1365 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3239 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 213: /* positive_term: trunc_expression '*' trunc_expression  */
#line 1369 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3247 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 214: /* positive_term: positive_term '/' trunc_expression  */
#line 1373 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3255 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 215: /* positive_term: positive_term '*' trunc_expression  */
#line 1377 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3263 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 216: /* positive_term: positive_factor  */
#line 1381 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3271 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 217: /* positive_term: positive_term '*' error  */
#line 1385 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 3283 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 218: /* positive_term: positive_term '/' error  */
#line 1393 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 3295 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 219: /* negative_term: negative_term '*' factor  */
#line 1404 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3303 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 220: /* negative_term: negative_term '/' factor  */
#line 1408 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3311 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 221: /* negative_term: negative_term '/' trunc_expression  */
#line 1412 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3319 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 222: /* negative_term: negative_term '*' trunc_expression  */
#line 1416 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3327 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 223: /* negative_term: negative_factor  */
#line 1420 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3335 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 224: /* negative_term: negative_term '*' error  */
#line 1424 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 3347 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 225: /* negative_term: negative_term '/' error  */
#line 1432 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 3359 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 226: /* negative_term: '*' factor  */
#line 1440 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_MUL_FACTOR);

    }
#line 3370 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 227: /* negative_term: '/' factor  */
#line 1447 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_DIV_FACTOR);

    }
#line 3381 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 228: /* negative_term: '*' error  */
#line 1454 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("...") };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 3394 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 229: /* negative_term: '/' error  */
#line 1463 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("...") };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 3407 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 230: /* factor: positive_factor  */
#line 1477 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3415 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 231: /* factor: negative_factor  */
#line 1481 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3423 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 232: /* positive_factor: variable  */
#line 1488 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = PR_SYMBOL;
            (yyval.metadata).expression = { mapWithCheckerType((yyval.metadata).reference.sref->type), (yyvsp[0].pid) };
        }
        else
        {
            (yyval.metadata).reference.type = PR_NULL;
            (yyval.metadata).expression = { TC_UNSUPPORTED, (yyvsp[0].pid) };
        }

    }
#line 3442 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 233: /* positive_factor: positive_constant  */
#line 1503 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3450 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 234: /* positive_factor: function_invocation_head  */
#line 1507 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3458 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 235: /* negative_factor: negative_constant  */
#line 1514 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3466 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 236: /* negative_factor: lambda_invocation_head  */
#line 1518 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("...") };
        
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);
    }
#line 3477 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 237: /* negative_factor: '-' UINTEGER_LITERAL  */
#line 1525 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { TC_UINT, StringPool::create((yyvsp[0].lref)->constant) };

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 3489 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 238: /* negative_factor: '-' function_invocation_head  */
#line 1533 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 3500 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 239: /* negative_factor: '-' variable  */
#line 1540 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = PR_SYMBOL;
            (yyval.metadata).expression = { mapWithCheckerType((yyval.metadata).reference.sref->type), (yyvsp[0].pid) };
        }
        else
        {
            (yyval.metadata).reference.type = PR_NULL;
            (yyval.metadata).expression = { TC_UNSUPPORTED, (yyvsp[0].pid) };
        }
        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 3520 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 240: /* negative_factor: '-' lambda_invocation_head  */
#line 1556 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("...") };

        SemanticActions::announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);

    }
#line 3533 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 241: /* negative_factor: '-' error  */
#line 1565 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("...") };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUB_OPERANDS);
        yyerrok;

    }
#line 3546 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 242: /* numeric_constant: positive_constant  */
#line 1579 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3554 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 243: /* numeric_constant: negative_constant  */
#line 1583 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3562 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 244: /* positive_constant: UINTEGER_LITERAL  */
#line 1590 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { TC_UINT, StringPool::create((yyvsp[0].lref)->constant) };
    }
#line 3571 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 245: /* positive_constant: FLOAT_LITERAL  */
#line 1595 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { TC_FLOAT, StringPool::create((yyvsp[0].lref)->constant) };
    }
#line 3580 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 246: /* negative_constant: '-' FLOAT_LITERAL  */
#line 1603 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_LITERAL , .lref = SemanticActions::turnNegative((yyvsp[0].lref)) };
        (yyval.metadata).expression = { TC_FLOAT, StringPool::create((yyvsp[0].lref)->constant) };

    }
#line 3590 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 247: /* variable: IDENTIFIER  */
#line 1614 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.pid) = StringPool::create((yyvsp[0].sref)->symbol);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariableName((yyvsp[0].sref)->symbol);

    }
#line 3601 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 248: /* variable: variable '.' IDENTIFIER  */
#line 1621 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].pid), "." + (yyvsp[0].sref)->symbol);
        (yyval.pid) = (yyvsp[-2].pid);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariablePrefix((yyvsp[0].sref)->symbol);

    }
#line 3613 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 3617 "src/syntax-analyzer/components/parser.cpp"

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

#line 1630 "include/syntax-analyzer/components/yacc.y"
 // Codes ------------------------------------------

void yyerror(const char* s)
{
    SemanticActions::announceSyntaxError();
}

int mapWithCheckerType(const int type)
{
    switch (type)
    {
    case ST_UINT:
        return TC_UINT;
    case ST_FLOAT:
        return TC_FLOAT;
    default:
        return TC_UNSUPPORTED;
    }
}

char mapWithTripleOperator(const int op)
{
    switch (op)
    {
    case EQUAL_OP:
        return TR_EQUAL_OP;
    case NOT_EQUAL_OP:
        return TR_NOT_EQUAL_OP;
    case GE_OP:
        return TR_GE_OP;
    case LE_OP:
        return TR_LE_OP;
    default:
        return op;
    }
}

Triples::Operand mapWithOperand(const Metadata::Reference& ref)
{
    switch (ref.type)
    {
    case PR_SYMBOL:
        return { TR_SYMBOL , { .sref = ref.sref } };
    case PR_LITERAL:
        return { TR_LITERAL, { .lref = ref.lref } };
    case PR_TRIPLE:
        return { TR_TRIPLE , { .tref = ref.tref } };
    default:
        return { TR_NULL   , { .sref = nullptr  } };
    }
}

void createArithmeticTriple(Metadata& r, const Metadata& o1, const Metadata& o2, const char op)
{
    SemanticAnalyzer::TypeChecker::Expression e1 = { o1.expression.type, *StringPool::get(o1.expression.pid) };
    SemanticAnalyzer::TypeChecker::Expression e2 = { o2.expression.type, *StringPool::get(o2.expression.pid) };
    r.expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

    r.expression.pid = o1.expression.pid;
    StringPool::append(o1.expression.pid, " " + std::string(1, op) + " " + *StringPool::get(o2.expression.pid));

    if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
    {
        r.reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
            {op, mapWithOperand(o1.reference), mapWithOperand(o2.reference)}
        );
        r.reference.type = PR_TRIPLE;
    }
}
