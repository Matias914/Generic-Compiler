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
#include "code-generator/code-generator.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"

#include <stack>

#define yylex LexicalAnalyzer::yylex

using namespace SyntaxAnalyzer;

// BackPatching

std::stack<int> STACK;

// Parser Functions

void yyerror(const char* s);
int mapWithCheckerType(const int type);
char mapWithTripleOperator(const int op);
CodeGenerator::Triples::Operand mapWithOperand(const Metadata::Reference& ref);

// Avoids Code Repetition
void createMultipleAssignmentTriple(const Metadata& m);
void createTruncateTriple(Metadata& result, const Metadata& operand);
void createArithmeticTriple(Metadata& r, const Metadata& o1, const Metadata& o2, const char op);


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
  YYSYMBOL_assignment = 68,                /* assignment  */
  YYSYMBOL_assignment_head = 69,           /* assignment_head  */
  YYSYMBOL_assignment_tail = 70,           /* assignment_tail  */
  YYSYMBOL_print = 71,                     /* print  */
  YYSYMBOL_72_9 = 72,                      /* $@9  */
  YYSYMBOL_print_end = 73,                 /* print_end  */
  YYSYMBOL_multiple_assignments = 74,      /* multiple_assignments  */
  YYSYMBOL_assignment_list = 75,           /* assignment_list  */
  YYSYMBOL_76_10 = 76,                     /* $@10  */
  YYSYMBOL_assignment_end = 77,            /* assignment_end  */
  YYSYMBOL_extra_numeric_constants = 78,   /* extra_numeric_constants  */
  YYSYMBOL_79_11 = 79,                     /* $@11  */
  YYSYMBOL_invocation = 80,                /* invocation  */
  YYSYMBOL_function_invocation_head = 81,  /* function_invocation_head  */
  YYSYMBOL_invocation_setup = 82,          /* invocation_setup  */
  YYSYMBOL_function_invocation_tail = 83,  /* function_invocation_tail  */
  YYSYMBOL_real_parameter_list = 84,       /* real_parameter_list  */
  YYSYMBOL_real_parameter_list_setup = 85, /* real_parameter_list_setup  */
  YYSYMBOL_real_parameter = 86,            /* real_parameter  */
  YYSYMBOL_lambda_invocation_head = 87,    /* lambda_invocation_head  */
  YYSYMBOL_88_12 = 88,                     /* $@12  */
  YYSYMBOL_lambda_invocation_middle = 89,  /* lambda_invocation_middle  */
  YYSYMBOL_90_13 = 90,                     /* $@13  */
  YYSYMBOL_91_14 = 91,                     /* $@14  */
  YYSYMBOL_92_15 = 92,                     /* $@15  */
  YYSYMBOL_93_16 = 93,                     /* $@16  */
  YYSYMBOL_lambda_invocation_tail = 94,    /* lambda_invocation_tail  */
  YYSYMBOL_lambda_real_parameter = 95,     /* lambda_real_parameter  */
  YYSYMBOL_if = 96,                        /* if  */
  YYSYMBOL_condition_body_setup = 97,      /* condition_body_setup  */
  YYSYMBOL_condition_setup = 98,           /* condition_setup  */
  YYSYMBOL_then_body_setup = 99,           /* then_body_setup  */
  YYSYMBOL_do_while = 100,                 /* do_while  */
  YYSYMBOL_101_17 = 101,                   /* $@17  */
  YYSYMBOL_do_while_head = 102,            /* do_while_head  */
  YYSYMBOL_do_body = 103,                  /* do_body  */
  YYSYMBOL_104_18 = 104,                   /* $@18  */
  YYSYMBOL_do_while_tail = 105,            /* do_while_tail  */
  YYSYMBOL_executable_body = 106,          /* executable_body  */
  YYSYMBOL_executable_statements = 107,    /* executable_statements  */
  YYSYMBOL_opt_trunc_constant = 108,       /* opt_trunc_constant  */
  YYSYMBOL_trunc_constant = 109,           /* trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 110,       /* opt_trunc_variable  */
  YYSYMBOL_trunc_variable = 111,           /* trunc_variable  */
  YYSYMBOL_trunc_expression = 112,         /* trunc_expression  */
  YYSYMBOL_condition = 113,                /* condition  */
  YYSYMBOL_comparison = 114,               /* comparison  */
  YYSYMBOL_comparison_operator = 115,      /* comparison_operator  */
  YYSYMBOL_expression = 116,               /* expression  */
  YYSYMBOL_expression_setup = 117,         /* expression_setup  */
  YYSYMBOL_term = 118,                     /* term  */
  YYSYMBOL_positive_term = 119,            /* positive_term  */
  YYSYMBOL_negative_term = 120,            /* negative_term  */
  YYSYMBOL_factor = 121,                   /* factor  */
  YYSYMBOL_positive_factor = 122,          /* positive_factor  */
  YYSYMBOL_negative_factor = 123,          /* negative_factor  */
  YYSYMBOL_numeric_constant = 124,         /* numeric_constant  */
  YYSYMBOL_positive_constant = 125,        /* positive_constant  */
  YYSYMBOL_negative_constant = 126,        /* negative_constant  */
  YYSYMBOL_variable = 127                  /* variable  */
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
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  260
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  404

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
       0,   143,   143,   144,   145,   149,   153,   157,   159,   158,
     167,   171,   179,   183,   187,   198,   197,   213,   218,   223,
     233,   234,   238,   242,   246,   253,   260,   267,   275,   285,
     289,   294,   300,   299,   309,   308,   324,   328,   333,   332,
     340,   348,   352,   363,   362,   371,   377,   390,   389,   400,
     411,   426,   427,   429,   428,   436,   442,   448,   456,   461,
     467,   474,   484,   494,   498,   510,   521,   535,   550,   564,
     579,   592,   605,   618,   629,   630,   631,   632,   633,   634,
     635,   641,   654,   663,   671,   678,   691,   701,   711,   721,
     733,   732,   739,   747,   749,   757,   763,   771,   779,   788,
     795,   804,   815,   816,   820,   828,   827,   833,   840,   849,
     853,   863,   864,   866,   865,   875,   876,   881,   882,   892,
     910,   931,   949,   957,   967,   971,   977,   987,   995,  1023,
    1036,  1035,  1048,  1047,  1053,  1052,  1060,  1059,  1069,  1068,
    1080,  1125,  1126,  1132,  1147,  1163,  1178,  1194,  1210,  1226,
    1234,  1243,  1251,  1260,  1276,  1293,  1301,  1312,  1319,  1333,
    1354,  1359,  1358,  1367,  1378,  1386,  1401,  1410,  1409,  1421,
    1422,  1433,  1437,  1445,  1451,  1458,  1459,  1465,  1469,  1476,
    1483,  1493,  1502,  1515,  1530,  1537,  1557,  1580,  1603,  1626,
    1638,  1644,  1654,  1663,  1678,  1679,  1684,  1688,  1696,  1716,
    1727,  1731,  1735,  1739,  1743,  1747,  1756,  1760,  1772,  1779,
    1788,  1792,  1800,  1804,  1812,  1816,  1820,  1827,  1838,  1842,
    1849,  1853,  1857,  1861,  1865,  1869,  1873,  1877,  1881,  1885,
    1893,  1904,  1908,  1912,  1916,  1920,  1924,  1932,  1940,  1947,
    1954,  1963,  1977,  1981,  1988,  2003,  2007,  2014,  2018,  2025,
    2033,  2040,  2056,  2065,  2079,  2083,  2090,  2095,  2103,  2114,
    2121
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
  "executable_stmt", "assignment", "assignment_head", "assignment_tail",
  "print", "$@9", "print_end", "multiple_assignments", "assignment_list",
  "$@10", "assignment_end", "extra_numeric_constants", "$@11",
  "invocation", "function_invocation_head", "invocation_setup",
  "function_invocation_tail", "real_parameter_list",
  "real_parameter_list_setup", "real_parameter", "lambda_invocation_head",
  "$@12", "lambda_invocation_middle", "$@13", "$@14", "$@15", "$@16",
  "lambda_invocation_tail", "lambda_real_parameter", "if",
  "condition_body_setup", "condition_setup", "then_body_setup", "do_while",
  "$@17", "do_while_head", "do_body", "$@18", "do_while_tail",
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

#define YYPACT_NINF (-277)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-218)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     654,  -277,    10,   410,  1060,   881,   428,   194,  -277,  -277,
     157,  -277,  -277,   211,   683,  -277,  -277,  -277,   148,  -277,
    -277,  -277,  1004,  -277,  -277,  -277,   124,  1000,   127,  -277,
    -277,  1060,   178,  -277,    44,  1022,    -3,  -277,  -277,   982,
     465,   312,   320,   617,  -277,  -277,   473,  1060,   291,   903,
      62,   516,   413,  -277,   302,   383,  -277,  -277,  -277,  -277,
      55,   981,  -277,   142,   150,   175,   203,   982,   534,   230,
     295,  -277,   380,   809,   217,  -277,  -277,   244,   246,  -277,
     324,    55,  -277,   266,  -277,  -277,  -277,  -277,   461,  1004,
    -277,    79,  -277,  -277,  -277,   283,   276,   447,  -277,   288,
    -277,   301,    43,    55,  -277,   982,   355,    75,  -277,   291,
    -277,  -277,  -277,  -277,  -277,  -277,    55,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,   913,   224,  -277,  -277,     5,     5,
     159,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
     484,   488,  1004,   302,   262,   569,   592,   601,   337,  -277,
     935,   323,  -277,  1040,  -277,   551,  -277,  -277,   343,  -277,
     357,   363,   462,   835,   374,   348,   845,  -277,  -277,  -277,
     712,  -277,  -277,  -277,   393,  -277,  -277,   459,  -277,  -277,
      14,   288,  -277,  -277,  1004,  -277,  -277,  -277,   386,  1040,
    1040,  -277,   398,    22,  -277,  -277,   377,  -277,   405,   186,
    -277,  -277,  -277,  -277,   397,   566,  -277,  -277,  -277,  -277,
      77,    18,  -277,  -277,  -277,  -277,  -277,  -277,   102,   416,
    -277,  -277,   291,  -277,  -277,   291,  -277,   122,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,   225,  -277,  -277,   228,
    -277,  -277,   232,   234,  -277,  -277,   741,  -277,  -277,  -277,
     770,  -277,  -277,  -277,  -277,   459,  -277,  -277,   216,  -277,
     474,  -277,   385,  -277,    55,    55,  -277,  -277,   235,  -277,
    -277,   247,   361,   345,    81,  -277,  -277,   247,   608,   247,
    -277,  -277,   425,  -277,  -277,   239,   430,  -277,  -277,  -277,
    -277,  -277,  -277,   434,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  1082,  -277,   485,  -277,  -277,   459,  -277,   459,
    -277,  -277,   218,  -277,  -277,   408,  -277,   426,   115,  -277,
    -277,  -277,  -277,  -277,   247,   247,  -277,   109,  -277,  -277,
    -277,  -277,  -277,  -277,   271,  -277,   945,  -277,  -277,   442,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,   971,  -277,  -277,   442,   871,  -277,   309,  -277,  -277,
     449,   449,  -277,   310,   799,  -277,  -277,   449,   449,   419,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,   625,   464,
    -277,  -277,  -277,    55,   471,   336,    37,  -277,  -277,    58,
    -277,  -277,  -277,  -277
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     4,     0,     0,     0,     0,     0,     0,    41,    42,
     259,     8,    10,     0,     0,     2,     7,     5,     0,    79,
       6,    74,     0,    78,    75,    76,     0,     0,     0,    77,
      80,     0,     0,    11,     0,     0,   259,   257,   256,     0,
       0,     0,     0,     0,   246,   248,     0,     0,   214,     0,
       0,     0,     0,   206,   218,   219,   228,   235,   245,   247,
     244,     0,   174,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     1,     3,     0,   259,    34,
       0,    36,    81,     0,   116,   115,   123,   119,   127,     0,
     124,     0,   118,   117,   160,   167,     0,     0,   259,     0,
     102,     0,     0,   105,   156,     0,     0,     0,   209,     0,
     208,   253,   258,   249,   250,   252,   251,   240,   238,   242,
     243,   241,   239,   147,     0,     0,   157,   159,     0,     0,
       0,   197,   196,   199,   200,   202,   203,   201,   204,   205,
       0,     0,     0,   207,     0,     0,     0,     0,     0,   175,
       0,     0,   163,     0,    73,     0,    69,    72,    68,    92,
       0,     0,   217,     0,     0,     0,     0,    13,     9,    24,
       0,    20,    22,    23,     0,    30,    32,     0,    31,    29,
       0,     0,    85,    84,     0,   122,   126,   129,     0,     0,
       0,   101,     0,     0,   260,   100,     0,    99,     0,     0,
     178,   177,   254,   255,     0,     0,   193,   192,   195,   194,
       0,     0,   144,   143,   225,   223,   224,   222,     0,     0,
     150,   211,   215,   210,   213,   216,   212,   217,   229,   227,
     220,   230,   226,   221,   236,   234,   231,   237,   233,   232,
     173,   172,   171,   176,   155,   162,     0,    67,    70,     0,
      71,    90,     0,     0,    19,    16,     0,   120,    28,    25,
       0,    14,    12,    21,   130,     0,    62,    57,     0,    35,
      53,    51,     0,    40,    37,    39,   125,   128,     0,   168,
      82,     0,     0,     0,     0,    96,    95,     0,     0,     0,
     191,   190,     0,   154,   148,     0,     0,   152,   149,   170,
     169,    66,    65,    94,    87,    86,    89,    88,    18,    17,
      27,    26,     0,    33,    53,    56,    55,     0,    43,     0,
      60,    61,     0,   166,   165,     0,   108,   107,     0,   182,
     181,   111,    98,    97,     0,     0,   106,     0,   153,   146,
     145,   151,    93,    91,     0,   131,     0,    47,    52,     0,
      54,    59,    58,   104,   103,   180,   179,   112,   114,   110,
     109,     0,   138,   134,     0,     0,    44,     0,   136,   132,
       0,     0,    48,     0,     0,    46,    45,     0,     0,     0,
     139,   135,    50,    49,    64,    63,   137,   133,     0,     0,
     142,   141,   184,   183,     0,     0,     0,   140,   189,     0,
     188,   187,   186,   185
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -277,  -277,   494,  -277,  -277,   126,  -277,  -277,  -153,  -169,
     133,  -277,  -277,  -277,  -277,     7,  -277,  -277,  -277,  -277,
    -277,  -277,   248,  -277,  -233,  -277,   154,  -277,     3,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,   101,  -277,  -277,  -277,
    -277,  -277,     8,  -277,  -277,  -277,  -277,   -87,    48,  -277,
    -277,  -277,  -277,  -277,  -277,    82,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,   332,    -2,  -276,  -114,
    -277,  -277,  -277,   -10,     2,   487,  -277,    50,  -277,   -34,
     476,  -277,   103,    15,    99,  -185,   -93,   -81,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    14,    15,    73,   168,   169,   163,   255,   170,   171,
     172,   265,   177,    80,   181,    18,   269,   349,   366,   313,
     364,   372,   270,   319,   271,   272,   367,    19,   173,    21,
      22,    82,    23,   303,   343,    24,   102,   204,   336,   288,
     335,    25,    44,    27,    87,    88,    89,    90,    45,   312,
     345,   378,   371,   377,   370,   380,   389,    29,    46,    47,
     126,    30,    65,    31,    94,   190,   245,    63,   150,   199,
     200,   391,   392,    48,   246,    50,   142,    51,    52,    53,
      54,    55,   118,    56,    57,   201,    58,    59,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   263,   186,    20,    32,    49,   110,    62,    26,   202,
     256,   284,    26,   260,    32,   273,    35,    20,    81,   294,
      74,   203,    26,   281,   295,    72,    36,    37,    38,    95,
     109,    32,   103,    13,    62,    98,   346,    33,   400,    26,
      41,   116,   109,    98,   195,   127,    74,    32,    28,   114,
      62,    99,    28,   100,   196,    26,    68,   119,   119,   402,
     101,    32,    28,   131,   149,    37,    38,   401,   361,    26,
     197,   104,    83,    32,    74,   101,   208,    91,   198,    28,
     187,    26,   329,   292,   348,   106,   350,   263,   403,   115,
    -217,   263,   132,   101,   188,    28,   101,   276,   328,   193,
    -217,  -217,  -217,   202,   293,   209,   223,   226,   296,    28,
     359,   330,    74,   140,   141,   203,   355,   155,   214,   216,
     162,    28,   211,  -198,    32,    84,    16,    62,    92,   297,
     222,   225,    26,    17,   229,   232,   235,   238,   360,    91,
      16,   120,   120,   119,   119,   356,   122,    17,   151,    77,
      32,    85,  -198,   243,    93,   205,   140,   141,    26,   119,
     119,   119,   119,    32,   218,   219,    32,   325,   327,    78,
      32,    26,    28,   331,    26,   337,    79,   152,    26,    96,
     274,   275,    71,   153,   268,    72,   220,   285,   202,   202,
     202,   278,   227,   103,   202,    69,   202,    97,    28,    98,
     203,   203,   203,   284,   103,   263,   203,    99,   203,   100,
     328,    28,   374,   286,    28,   287,   101,   315,    28,   351,
     357,   358,    70,     8,     9,   212,   299,   120,   120,   301,
     154,   215,   217,   304,    91,   306,   323,   316,   174,   352,
     339,   202,   202,   120,   120,   120,   120,   230,   233,   236,
     239,   213,   300,   203,   203,   302,    32,   159,   196,   305,
      32,   307,   324,   228,    26,   390,   340,   182,    26,    37,
      38,   175,   268,    35,   176,     3,     4,  -217,     5,   322,
       6,     7,   198,    36,    37,    38,   202,  -217,  -217,  -217,
      13,   189,    36,   183,   282,   202,   160,    41,   203,    13,
     140,   141,   202,   191,    28,   289,    35,   203,    28,    98,
     375,   382,    32,   111,   203,   149,    36,    37,    38,   161,
      26,   117,   194,    13,   268,   178,   268,   128,   129,    40,
      41,    42,    43,    36,   112,   113,   376,   383,   144,   145,
      13,    36,    37,    38,    32,   -38,    32,   149,    13,   243,
     244,   179,    26,   180,    26,    41,   206,    98,    37,    38,
      28,    32,   326,   240,   243,    32,  -217,    37,    38,    26,
     250,   198,   196,    26,    32,   258,  -217,  -217,  -217,   393,
     198,   164,    26,    37,    38,   207,   320,   251,   396,   140,
     141,  -121,    28,   252,    28,   399,   198,     8,     9,    37,
      38,  -121,  -121,  -121,   257,   283,   321,   277,  -121,    28,
    -121,    34,   198,    28,  -121,  -121,  -121,  -121,    98,   146,
     147,    35,    28,   264,    35,   280,    99,   112,   100,    66,
     388,    36,    37,    38,    36,    37,    38,   353,    39,    35,
      98,    37,    38,   298,    40,    41,    42,    43,   192,    36,
      37,    38,   338,   381,   198,   354,    67,   341,   -83,   386,
     387,   342,    40,    41,    42,    43,   108,   365,   -83,   -83,
     -83,     8,     9,   266,   123,   -83,    35,   379,   124,   125,
     267,   -83,   -83,   -83,   -83,   221,    36,    37,    38,   224,
     184,   185,   253,    13,   397,    35,   140,   141,   398,    35,
      41,    42,    43,   317,   318,    36,    37,    38,    76,    36,
      37,    38,    13,   314,   317,   347,    13,   133,   373,    41,
      42,    43,   279,    41,    42,    43,   107,  -217,   143,     0,
       0,     0,   134,   135,   136,   156,   137,  -217,  -217,  -217,
       0,     0,     0,     0,     0,  -217,     0,     0,   138,   139,
     140,   141,   247,     0,     0,  -217,  -217,  -217,     0,     0,
       0,   157,  -217,     0,   158,     0,     0,   290,   140,   141,
     231,     0,  -217,  -217,  -217,     0,     0,  -217,   248,     0,
      35,   249,     0,     0,     0,   140,   141,  -217,  -217,  -217,
      36,    37,    38,   234,     0,     0,   291,    13,     0,     0,
     140,   141,   237,    35,    41,     0,     0,     0,     0,   332,
       0,     0,    35,    36,    37,    38,     0,     0,   121,  -113,
      13,     0,    36,    37,    38,     0,   394,    41,     0,    13,
    -113,  -113,     0,     0,     0,   333,    41,   334,    36,    37,
      38,     0,     0,  -113,     0,    13,    98,    37,    38,     0,
       0,     0,    41,   395,     1,     2,     0,     0,     3,     4,
     198,     5,     0,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,    11,
      12,     0,    13,    75,     2,     0,     0,     3,     4,     0,
       5,     0,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,    11,    12,
       0,    13,   261,   165,     0,     0,     3,     4,     0,     5,
       0,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,   166,   262,     0,
      13,   308,   165,     0,     0,     3,     4,     0,     5,     0,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   166,   309,     0,    13,
     310,   165,     0,     0,     3,     4,     0,     5,     0,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,   166,   311,     0,    13,   384,
     165,     0,     0,     3,     4,     0,     5,     0,     6,     7,
     165,     8,     9,     3,     4,     0,     5,     0,     6,     7,
      10,     8,     9,     0,   166,   385,     0,    13,     0,     0,
      10,     0,     0,     0,   166,   167,   165,    13,     0,     3,
       4,     0,     5,     0,     6,     7,   165,     8,     9,     3,
       4,     0,     5,     0,     6,     7,    10,     8,     9,     0,
     166,   254,     0,    13,     0,     0,    10,     0,     0,     0,
     166,   259,   165,    13,     0,     3,     4,     0,     5,     0,
       6,     7,    64,     8,     9,  -164,  -164,     0,  -164,  -161,
    -164,  -164,    10,     0,     0,     0,   166,     0,     0,    13,
       0,     0,  -164,     0,   130,     0,  -164,  -158,  -158,  -164,
    -158,     0,  -158,  -158,   210,     0,     0,     3,     4,     0,
       5,     0,     6,     7,  -158,     0,     0,     0,  -158,     0,
       0,  -158,     0,     0,    36,     0,   241,     0,    61,     3,
       4,    13,     5,     0,     6,     7,   362,     0,     0,     3,
       4,     0,     5,     0,     6,     7,    36,     0,     0,     0,
       0,   242,     0,    13,     0,     0,    36,     0,     0,     0,
       0,   363,   368,    13,     0,     3,     4,     0,     5,     0,
       6,     7,   148,     0,     0,     3,     4,     0,     5,     0,
       6,     7,    36,    35,     8,     9,     0,   369,     0,    13,
       0,     0,    36,    36,    37,    38,     0,     0,     0,    13,
      13,    35,     0,     0,     0,    35,    40,    41,    42,    43,
       0,    36,    37,    38,     0,    36,    37,    38,    13,     0,
      86,     0,    13,    35,    40,    41,    42,    43,    40,    41,
      42,    43,     0,    36,    37,    38,     0,     0,     0,     0,
     105,    35,     0,     0,     0,     0,    40,    41,    42,    43,
       0,    36,    37,    38,     3,     4,     0,     5,    39,     6,
       7,     0,     0,     0,    40,    41,    42,    43,     0,     0,
       0,    36,     0,     0,     0,    61,     3,     4,    13,     5,
       0,     6,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,   344,     0,     0,
      13
};

static const yytype_int16 yycheck[] =
{
       0,   170,    89,     0,     4,     3,    40,     4,     0,   102,
     163,   196,     4,   166,    14,     1,    11,    14,    18,     1,
      13,   102,    14,     1,     6,    28,    21,    22,    23,    31,
      40,    31,    32,    28,    31,    21,   312,    27,     1,    31,
      35,    41,    52,    21,     1,    47,    39,    47,     0,    41,
      47,    29,     4,    31,    11,    47,     6,    42,    43,     1,
      38,    61,    14,     1,    61,    22,    23,    30,   344,    61,
      27,    27,    22,    73,    67,    38,     1,    27,    35,    31,
       1,    73,     1,     6,   317,    35,   319,   256,    30,    41,
      11,   260,    30,    38,    15,    47,    38,   184,   283,    99,
      21,    22,    23,   196,    27,    30,   140,   141,     6,    61,
       1,    30,   105,    34,    35,   196,     1,    67,   128,   129,
      70,    73,   124,     1,   124,     1,     0,   124,     1,    27,
     140,   141,   124,     0,   144,   145,   146,   147,    29,    89,
      14,    42,    43,   128,   129,    30,    43,    14,     6,     1,
     150,    27,    30,   150,    27,   105,    34,    35,   150,   144,
     145,   146,   147,   163,     5,     6,   166,   281,   282,    21,
     170,   163,   124,   287,   166,   289,    28,    27,   170,     1,
     180,   181,    25,     8,   177,    28,    27,     1,   281,   282,
     283,   189,   142,   193,   287,     1,   289,    19,   150,    21,
     281,   282,   283,   388,   204,   374,   287,    29,   289,    31,
     395,   163,   365,    27,   166,    29,    38,     1,   170,     1,
     334,   335,    28,    12,    13,     1,     1,   128,   129,     1,
      27,   128,   129,     1,   184,     1,     1,    21,    21,    21,
       1,   334,   335,   144,   145,   146,   147,   144,   145,   146,
     147,    27,    27,   334,   335,    27,   256,    27,    11,    27,
     260,    27,    27,     1,   256,   379,    27,     1,   260,    22,
      23,    27,   265,    11,    28,     4,     5,    11,     7,   272,
       9,    10,    35,    21,    22,    23,   379,    21,    22,    23,
      28,     8,    21,    27,   193,   388,     1,    35,   379,    28,
      34,    35,   395,    27,   256,   204,    11,   388,   260,    21,
       1,     1,   312,     1,   395,   312,    21,    22,    23,    24,
     312,     1,    21,    28,   317,     1,   319,    36,    37,    34,
      35,    36,    37,    21,    22,    23,    27,    27,    36,    37,
      28,    21,    22,    23,   344,    21,   346,   344,    28,   346,
      27,    27,   344,    29,   346,    35,     1,    21,    22,    23,
     312,   361,     1,    26,   361,   365,    11,    22,    23,   361,
      27,    35,    11,   365,   374,    27,    21,    22,    23,   379,
      35,     1,   374,    22,    23,    30,     1,    30,   388,    34,
      35,    11,   344,    30,   346,   395,    35,    12,    13,    22,
      23,    21,    22,    23,    30,    28,    21,    21,    28,   361,
      30,     1,    35,   365,    34,    35,    36,    37,    21,    36,
      37,    11,   374,    30,    11,    27,    29,    22,    31,     1,
      11,    21,    22,    23,    21,    22,    23,    29,    28,    11,
      21,    22,    23,    27,    34,    35,    36,    37,     1,    21,
      22,    23,    27,   371,    35,    29,    28,    27,    11,   377,
     378,    27,    34,    35,    36,    37,     1,    25,    21,    22,
      23,    12,    13,    14,     1,    28,    11,    28,     5,     6,
      21,    34,    35,    36,    37,     1,    21,    22,    23,     1,
      29,    30,    30,    28,    30,    11,    34,    35,    27,    11,
      35,    36,    37,    29,    30,    21,    22,    23,    14,    21,
      22,    23,    28,   265,    29,    30,    28,     1,   364,    35,
      36,    37,   190,    35,    36,    37,    39,    11,    52,    -1,
      -1,    -1,    16,    17,    18,     1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    32,    33,
      34,    35,     1,    -1,    -1,    21,    22,    23,    -1,    -1,
      -1,    27,    11,    -1,    30,    -1,    -1,     1,    34,    35,
       1,    -1,    21,    22,    23,    -1,    -1,    11,    27,    -1,
      11,    30,    -1,    -1,    -1,    34,    35,    21,    22,    23,
      21,    22,    23,     1,    -1,    -1,    30,    28,    -1,    -1,
      34,    35,     1,    11,    35,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    11,    21,    22,    23,    -1,    -1,     1,    11,
      28,    -1,    21,    22,    23,    -1,     1,    35,    -1,    28,
      22,    23,    -1,    -1,    -1,    27,    35,    29,    21,    22,
      23,    -1,    -1,    35,    -1,    28,    21,    22,    23,    -1,
      -1,    -1,    35,    28,     0,     1,    -1,    -1,     4,     5,
      35,     7,    -1,     9,    10,    -1,    12,    13,    -1,    -1,
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
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    25,    26,    -1,    28,     0,
       1,    -1,    -1,     4,     5,    -1,     7,    -1,     9,    10,
       1,    12,    13,     4,     5,    -1,     7,    -1,     9,    10,
      21,    12,    13,    -1,    25,    26,    -1,    28,    -1,    -1,
      21,    -1,    -1,    -1,    25,    26,     1,    28,    -1,     4,
       5,    -1,     7,    -1,     9,    10,     1,    12,    13,     4,
       5,    -1,     7,    -1,     9,    10,    21,    12,    13,    -1,
      25,    26,    -1,    28,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,     1,    28,    -1,     4,     5,    -1,     7,    -1,
       9,    10,     1,    12,    13,     4,     5,    -1,     7,     8,
       9,    10,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,
      -1,    -1,    21,    -1,     1,    -1,    25,     4,     5,    28,
       7,    -1,     9,    10,     1,    -1,    -1,     4,     5,    -1,
       7,    -1,     9,    10,    21,    -1,    -1,    -1,    25,    -1,
      -1,    28,    -1,    -1,    21,    -1,     1,    -1,    25,     4,
       5,    28,     7,    -1,     9,    10,     1,    -1,    -1,     4,
       5,    -1,     7,    -1,     9,    10,    21,    -1,    -1,    -1,
      -1,    26,    -1,    28,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    26,     1,    28,    -1,     4,     5,    -1,     7,    -1,
       9,    10,     1,    -1,    -1,     4,     5,    -1,     7,    -1,
       9,    10,    21,    11,    12,    13,    -1,    26,    -1,    28,
      -1,    -1,    21,    21,    22,    23,    -1,    -1,    -1,    28,
      28,    11,    -1,    -1,    -1,    11,    34,    35,    36,    37,
      -1,    21,    22,    23,    -1,    21,    22,    23,    28,    -1,
      30,    -1,    28,    11,    34,    35,    36,    37,    34,    35,
      36,    37,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    11,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      -1,    21,    22,    23,     4,     5,    -1,     7,    28,     9,
      10,    -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    25,     4,     5,    28,     7,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,
      28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     0,     1,     4,     5,     7,     9,    10,    12,    13,
      21,    25,    26,    28,    40,    41,    44,    49,    54,    66,
      67,    68,    69,    71,    74,    80,    81,    82,    87,    96,
     100,   102,   127,    27,     1,    11,    21,    22,    23,    28,
      34,    35,    36,    37,    81,    87,    97,    98,   112,   113,
     114,   116,   117,   118,   119,   120,   122,   123,   125,   126,
     127,    25,    67,   106,     1,   101,     1,    28,   116,     1,
      28,    25,    28,    42,    54,     0,    41,     1,    21,    28,
      52,   127,    70,   116,     1,    27,    30,    83,    84,    85,
      86,   116,     1,    27,   103,   106,     1,    19,    21,    29,
      31,    38,    75,   127,    27,    28,   116,   114,     1,   112,
     118,     1,    22,    23,    81,    87,   127,     1,   121,   122,
     123,     1,   121,     1,     5,     6,    99,   106,    36,    37,
       1,     1,    30,     1,    16,    17,    18,    20,    32,    33,
      34,    35,   115,   119,    36,    37,    36,    37,     1,    67,
     107,     6,    27,     8,    27,   116,     1,    27,    30,    27,
       1,    24,   116,    45,     1,     1,    25,    26,    43,    44,
      47,    48,    49,    67,    21,    27,    28,    51,     1,    27,
      29,    53,     1,    27,    29,    30,    86,     1,    15,     8,
     104,    27,     1,   127,    21,     1,    11,    27,    35,   108,
     109,   124,   125,   126,    76,   116,     1,    30,     1,    30,
       1,   106,     1,    27,   112,   121,   112,   121,     5,     6,
      27,     1,   112,   118,     1,   112,   118,   116,     1,   112,
     121,     1,   112,   121,     1,   112,   121,     1,   112,   121,
      26,     1,    26,    67,    27,   105,   113,     1,    27,    30,
      27,    30,    30,    30,    26,    46,    47,    30,    27,    26,
      47,     0,    26,    48,    30,    50,    14,    21,    54,    55,
      61,    63,    64,     1,   127,   127,    86,    21,   113,   105,
      27,     1,    75,    28,   124,     1,    27,    29,    78,    75,
       1,    30,     6,    27,     1,     6,     6,    27,    27,     1,
      27,     1,    27,    72,     1,    27,     1,    27,     0,    26,
       0,    26,    88,    58,    61,     1,    21,    29,    30,    62,
       1,    21,    54,     1,    27,   108,     1,   108,   124,     1,
      30,   108,     1,    27,    29,    79,    77,   108,    27,     1,
      27,    27,    27,    73,    25,    89,   107,    30,    63,    56,
      63,     1,    21,    29,    29,     1,    30,   108,   108,     1,
      29,   107,     1,    26,    59,    25,    57,    65,     1,    26,
      93,    91,    60,    65,    47,     1,    27,    92,    90,    28,
      94,    94,     1,    27,     0,    26,    94,    94,    11,    95,
     108,   110,   111,   127,     1,    28,   127,    30,    27,   127,
       1,    30,     1,    30
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
      67,    68,    68,    69,    70,    70,    71,    71,    71,    71,
      72,    71,    71,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    75,    75,    75,    76,    75,    75,    75,    77,
      77,    78,    78,    79,    78,    80,    80,    80,    80,    81,
      81,    82,    83,    83,    84,    84,    84,    85,    86,    86,
      88,    87,    90,    89,    91,    89,    92,    89,    93,    89,
      94,    95,    95,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    98,    99,
     100,   101,   100,   100,   102,   103,   103,   104,   103,   105,
     105,   106,   106,   106,   106,   107,   107,   108,   108,   109,
     109,   109,   109,   110,   110,   111,   111,   111,   111,   111,
     112,   112,   112,   112,   113,   113,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   117,   118,   118,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   121,   121,   122,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   124,   124,   125,   125,   126,   127,
     127
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
       1,     2,     4,     2,     2,     2,     5,     5,     5,     5,
       0,     6,     3,     1,     0,     4,     4,     5,     5,     3,
       3,     3,     1,     5,     5,     0,     4,     4,     4,     2,
       2,     2,     3,     0,     3,     2,     2,     2,     2,     2,
       4,     2,     2,     1,     1,     3,     2,     1,     3,     2,
       0,     6,     0,     5,     0,     4,     0,     5,     0,     4,
       3,     1,     1,     4,     4,     6,     6,     3,     5,     5,
       4,     6,     5,     6,     5,     4,     3,     2,     1,     1,
       2,     0,     4,     3,     1,     4,     4,     0,     3,     2,
       2,     3,     3,     3,     1,     1,     2,     1,     1,     4,
       4,     3,     3,     1,     1,     4,     4,     3,     3,     3,
       4,     4,     3,     3,     3,     3,     2,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       3,     3,     3,     3,     1,     3,     3,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     1,
       3
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
#line 150 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1673 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 154 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1681 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 8: /* $@1: %empty  */
#line 159 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::addInvalidScope();
        SemanticActions::announceSpecificError(MISSING_PROGRAM_NAME);

        SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration("");

    }
#line 1693 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '}'  */
#line 168 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1701 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: error ';'  */
#line 172 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1710 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* unnamed_program_tail: program_statements '}'  */
#line 180 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1718 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* unnamed_program_tail: '}'  */
#line 184 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1726 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* unnamed_program_tail: program_statements $end  */
#line 188 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1735 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 15: /* $@2: %empty  */
#line 198 "include/syntax-analyzer/components/yacc.y"
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
#line 1751 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 17: /* program_tail: program_statements '}'  */
#line 214 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1760 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 18: /* program_tail: program_statements $end  */
#line 219 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticAnalyzer::removeScope();
    }
#line 1769 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 19: /* program_tail: '}'  */
#line 224 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1778 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statements: program_statement  */
#line 233 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 1784 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statements: program_statements program_statement  */
#line 234 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 1790 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: declarative_stmt  */
#line 239 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 1798 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* program_statement: executable_stmt  */
#line 243 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 1806 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* program_statement: program_head  */
#line 247 "include/syntax-analyzer/components/yacc.y"
    {
       (yyval.returnable) = false;

       SemanticActions::announceSpecificError(INVALID_PROGRAM_NESTING);

    }
#line 1817 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* program_statement: '{' '}'  */
#line 254 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1828 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* program_statement: '{' program_statements '}'  */
#line 261 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1839 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* program_statement: '{' program_statements $end  */
#line 268 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1851 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* program_statement: error ';'  */
#line 276 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;

    }
#line 1860 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type variable_list ';'  */
#line 286 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("VARIABLE DECLARATION");
    }
#line 1868 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* declarative_stmt: type error ';'  */
#line 290 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1877 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 31: /* declarative_stmt: type variable_list error  */
#line 295 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1886 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* $@3: %empty  */
#line 300 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction (
            SemanticAnalyzer::ReturnChecker::Element({mapWithCheckerType(SemanticAnalyzer::TYPE), (yyvsp[-1].sref)->symbol})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionName((yyvsp[-1].sref)->symbol);

    }
#line 1898 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 34: /* $@4: %empty  */
#line 309 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction(
            SemanticAnalyzer::ReturnChecker::Element({mapWithCheckerType(SemanticAnalyzer::TYPE), "...()"})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionWithoutName();

        SemanticActions::announceSpecificError(MISSING_FUNCTION_NAME);

    }
#line 1912 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 36: /* variable_list: variable  */
#line 325 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1920 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* variable_list: variable_list ',' variable  */
#line 329 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1928 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 38: /* $@5: %empty  */
#line 333 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 1936 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 39: /* variable_list: variable_list $@5 variable  */
#line 337 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1944 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* variable_list: variable_list ',' error  */
#line 341 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1953 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* type: UINT  */
#line 349 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = ST_UINT;
    }
#line 1961 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* type: FLOAT  */
#line 353 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = ST_FLOAT;
        SemanticActions::announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1970 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* $@6: %empty  */
#line 363 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();

    }
#line 1979 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* unnamed_function_declaration_tail: function_body ';'  */
#line 372 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

    }
#line 1989 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* unnamed_function_declaration_tail: function_body error  */
#line 378 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2002 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* $@7: %empty  */
#line 390 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
        if (entry != nullptr)
            CodeGenerator::addIntermediateCodeBlock(entry);

    }
#line 2013 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 49: /* function_declaration_tail: function_body ';'  */
#line 401 "include/syntax-analyzer/components/yacc.y"
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn((yyvsp[-1].returnable));
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::logStructure("FUNCTION DECLARATION");

    }
#line 2028 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 50: /* function_declaration_tail: function_body error  */
#line 412 "include/syntax-analyzer/components/yacc.y"
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn((yyvsp[-1].returnable));
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2044 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 53: /* $@8: %empty  */
#line 429 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2052 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* formal_parameter: type IDENTIFIER  */
#line 437 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(ST_CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2062 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 56: /* formal_parameter: type error  */
#line 443 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2072 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* formal_parameter: IDENTIFIER  */
#line 449 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = ST_UNSUPPORTED;
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(ST_CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2084 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* formal_parameter: parameter_semantics type IDENTIFIER  */
#line 457 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2093 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* formal_parameter: parameter_semantics type error  */
#line 462 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2103 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* formal_parameter: parameter_semantics error  */
#line 468 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        SemanticActions::announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;

    }
#line 2114 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 475 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = ST_UNSUPPORTED;
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2125 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* parameter_semantics: CR  */
#line 485 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(ST_CR);

    }
#line 2134 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* function_body: '{' program_statements '}'  */
#line 495 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 2142 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* function_body: '{' program_statements $end  */
#line 499 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    }
#line 2153 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 65: /* return: RETURN '(' expression ')' ';'  */
#line 511 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand((yyvsp[-2].metadata).reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

    }
#line 2168 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 66: /* return: RETURN '(' expression ')' error  */
#line 522 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand((yyvsp[-2].metadata).reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2186 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 67: /* return: RETURN '(' expression error  */
#line 536 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2205 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 68: /* return: RETURN expression ')'  */
#line 551 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);

    }
#line 2223 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 69: /* return: RETURN expression error  */
#line 565 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2242 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* return: RETURN '(' expression ';'  */
#line 580 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::announceSpecificError(MISSING_CLOSING_PARENTHESIS);

    }
#line 2259 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* return: RETURN expression ')' ';'  */
#line 593 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand((yyvsp[-2].metadata).reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 2276 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* return: RETURN expression ';'  */
#line 606 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);

    }
#line 2293 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 73: /* return: RETURN error ';'  */
#line 619 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(RETURN_SYNTAX_ERROR);
        yyerrok;

    }
#line 2303 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 74: /* executable_stmt: assignment  */
#line 629 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2309 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* executable_stmt: multiple_assignments  */
#line 630 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2315 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* executable_stmt: invocation  */
#line 631 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2321 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 77: /* executable_stmt: if  */
#line 632 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2327 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 78: /* executable_stmt: print  */
#line 633 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2333 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 79: /* executable_stmt: return  */
#line 634 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = true;  }
#line 2339 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 80: /* executable_stmt: do_while  */
#line 635 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2345 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* assignment: assignment_head assignment_tail  */
#line 642 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            Metadata::Reference ref;
            if ((yyvsp[-1].sref) != nullptr)
                ref = { PR_SYMBOL, (yyvsp[-1].sref) };
            else
                ref = { PR_NULL  , (yyvsp[-1].sref) };

            CodeGenerator::INTERMEDIATE_CODE->addTriple({'=', mapWithOperand(ref), mapWithOperand((yyvsp[0].metadata).reference)});
        }
    }
#line 2362 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 82: /* assignment: variable ASSIGN_OP error ';'  */
#line 655 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2372 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* assignment_head: variable ASSIGN_OP  */
#line 664 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.sref) = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
    
    }
#line 2381 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 84: /* assignment_tail: expression ';'  */
#line 672 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::logStructure("ASSIGNMENT");

    }
#line 2392 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 85: /* assignment_tail: expression error  */
#line 679 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2404 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 86: /* print: PRINT '(' STRING_LITERAL ')' ';'  */
#line 692 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PRINT");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple({
                TR_PRINT, mapWithOperand({ PR_LITERAL, { .lref = (yyvsp[-2].lref) } }), mapWithOperand({ PR_NULL, nullptr })
            });

    }
#line 2418 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* print: PRINT '(' STRING_LITERAL ')' error  */
#line 702 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple({
                TR_PRINT, mapWithOperand({ PR_LITERAL, { .lref = (yyvsp[-2].lref) } }), mapWithOperand({ PR_NULL, nullptr })
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2432 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 88: /* print: PRINT '(' expression ')' ';'  */
#line 712 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple({
                TR_PRINT, mapWithOperand((yyvsp[-2].metadata).reference), mapWithOperand({ PR_NULL, nullptr })
            });

        SemanticActions::logStructure("PRINT");

    }
#line 2446 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 89: /* print: PRINT '(' expression ')' error  */
#line 722 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple({
                TR_PRINT, mapWithOperand((yyvsp[-2].metadata).reference), mapWithOperand({ PR_NULL, nullptr })
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2461 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* $@9: %empty  */
#line 733 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;

    }
#line 2471 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 92: /* print: PRINT error ';'  */
#line 740 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(PRINT_SYNTAX_ERROR);
        yyerrok;
    }
#line 2480 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 94: /* print_end: %empty  */
#line 749 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
    }
#line 2488 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* multiple_assignments: variable assignment_list opt_trunc_constant ';'  */
#line 758 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2498 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* multiple_assignments: variable assignment_list opt_trunc_constant error  */
#line 764 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2510 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 772 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2522 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 98: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 780 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2535 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 99: /* multiple_assignments: variable assignment_list ';'  */
#line 789 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::announceSpecificError(MISSING_RIGHT_SIDE_VALUES);

    }
#line 2546 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 100: /* multiple_assignments: variable assignment_list error  */
#line 796 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2559 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* multiple_assignments: variable error ';'  */
#line 805 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;

    }
#line 2571 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 103: /* assignment_list: ',' variable assignment_list opt_trunc_constant ','  */
#line 817 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2579 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 104: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 821 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_EQUALS);

    }
#line 2590 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 105: /* $@10: %empty  */
#line 828 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_COMMA);

    }
#line 2599 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 107: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 834 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[0].metadata));

        SemanticActions::announceSpecificError(MISSING_COMMA);

    }
#line 2610 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* assignment_list: ',' variable assignment_list error  */
#line 841 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2620 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* assignment_end: opt_trunc_constant ','  */
#line 850 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2628 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* assignment_end: opt_trunc_constant error  */
#line 854 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 2639 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 113: /* $@11: %empty  */
#line 866 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2647 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 116: /* invocation: function_invocation_head error  */
#line 877 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2656 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 118: /* invocation: lambda_invocation_head error  */
#line 883 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2665 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* function_invocation_head: invocation_setup function_invocation_tail  */
#line 893 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = (yyvsp[-1].metadata).expression;
        StringPool::append((yyval.metadata).expression.pid, *StringPool::get((yyvsp[0].metadata).expression.pid));

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr && (yyvsp[-1].metadata).reference.type != PR_NULL)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_CALL, mapWithOperand((yyvsp[-1].metadata).reference), mapWithOperand({ PR_NULL, nullptr }) }
            );
            CodeGenerator::INTERMEDIATE_CODE->commit();
            (yyval.metadata).reference.type = PR_TRIPLE;
        }
        else
            (yyval.metadata).reference = (yyvsp[-1].metadata).reference;

        SemanticActions::logStructure("FUNCTION INVOCATION");
    }
#line 2687 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* function_invocation_head: IDENTIFIER '(' error ')'  */
#line 911 "include/syntax-analyzer/components/yacc.y"
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
#line 2709 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 121: /* invocation_setup: IDENTIFIER '('  */
#line 932 "include/syntax-analyzer/components/yacc.y"
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
#line 2728 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* function_invocation_tail: real_parameter_list ')'  */
#line 950 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, ")");
        (yyval.metadata).expression.type = TC_UNSUPPORTED;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
    }
#line 2740 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* function_invocation_tail: ')'  */
#line 958 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create(")") };

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
        SemanticActions::announceSpecificError(MISSING_ARGUMENT);
    }
#line 2751 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 124: /* real_parameter_list: real_parameter  */
#line 968 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 2759 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 125: /* real_parameter_list: real_parameter_list ',' real_parameter  */
#line 972 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].metadata).expression.pid, ", " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = TC_UNSUPPORTED;
        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
    }
#line 2769 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* real_parameter_list: real_parameter_list_setup real_parameter  */
#line 978 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = TC_UNSUPPORTED;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

    }
#line 2780 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* real_parameter_list_setup: real_parameter_list  */
#line 988 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2789 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* real_parameter: expression POINTER_OP IDENTIFIER  */
#line 996 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_INVOCATIONS.checkParameterInScope((yyvsp[0].sref)->symbol);
        if (entry != nullptr)
        {
            SemanticAnalyzer::TypeChecker::Expression e1 = {
                mapWithCheckerType((yyvsp[-2].metadata).expression.type),
                *StringPool::get((yyvsp[-2].metadata).expression.pid),
                (yyvsp[-2].metadata).expression.assignable
            };
            SemanticAnalyzer::TypeChecker::Expression e2 = { mapWithCheckerType((yyvsp[0].sref)->type), (yyvsp[0].sref)->symbol, true };

            SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

            e2.type = entry->semantics;
            int result =  SemanticAnalyzer::CHK_TYPES.checkSemantics(e1, e2);
            if (result == ST_CR && CodeGenerator::INTERMEDIATE_CODE != nullptr)
                CodeGenerator::INTERMEDIATE_CODE->addBuffer(
                    { '=', mapWithOperand((yyvsp[-2].metadata).reference), mapWithOperand({ PR_SYMBOL, entry }) }
                );
            else if (result == ST_CV && CodeGenerator::INTERMEDIATE_CODE != nullptr)
                CodeGenerator::INTERMEDIATE_CODE->addTriple (
                    { '=', mapWithOperand({ PR_SYMBOL, entry }), mapWithOperand((yyvsp[-2].metadata).reference) }
                );
        }
        StringPool::append((yyvsp[-2].metadata).expression.pid, "->" + (yyvsp[0].sref)->symbol);
        (yyval.metadata).expression = { TC_UNSUPPORTED, (yyvsp[-2].metadata).expression.pid, false };
    }
#line 2821 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 129: /* real_parameter: expression error  */
#line 1024 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2832 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* $@12: %empty  */
#line 1036 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclaration((yyvsp[-1].sref)->symbol);
        CodeGenerator::addIntermediateCodeBlock (
              SemanticAnalyzer::CHK_LAMBDAS.getLambda().function
        );

    }
#line 2844 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 132: /* $@13: %empty  */
#line 1048 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 2852 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 134: /* $@14: %empty  */
#line 1053 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);

    }
#line 2862 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 136: /* $@15: %empty  */
#line 1060 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 2874 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* $@16: %empty  */
#line 1069 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_BOTH_BRACKETS);
        yyerrok;

    }
#line 2886 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 140: /* lambda_invocation_tail: '(' lambda_real_parameter ')'  */
#line 1081 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("LAMBDA");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                TR_RET, mapWithOperand({PR_NULL, nullptr}), mapWithOperand({PR_NULL, nullptr})
            });

        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::LambdaChecker::Lambda l = SemanticAnalyzer::CHK_LAMBDAS.getLambda();
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            Metadata::Reference rf;
            SemanticAnalyzer::TypeChecker::Expression e1, e2;
            if (l.parameter != nullptr)
            {
                e1 = { mapWithCheckerType(l.parameter->type), l.pname, true};
                rf = { PR_SYMBOL, l.parameter };
            }
            else
            {
                e1 = { TC_UNSUPPORTED, "...", false };
                rf = { PR_NULL, nullptr };
            }
            e2 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid), (yyvsp[-1].metadata).expression.assignable };
            SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                '=', mapWithOperand(rf), mapWithOperand((yyvsp[-1].metadata).reference)
            });
            if (l.function != nullptr)
                CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                    TR_CALL, mapWithOperand({PR_SYMBOL, l.function}), mapWithOperand({PR_NULL, nullptr})
                });
        }
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclarationEnd();

        SemanticActions::logStructure("LAMBDA");

    }
#line 2932 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* lambda_real_parameter: opt_trunc_variable  */
#line 1125 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 2938 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 142: /* lambda_real_parameter: opt_trunc_constant  */
#line 1126 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 2944 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* if: IF condition_body_setup ENDIF ';'  */
#line 1133 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::logStructure("IF");

    }
#line 2963 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* if: IF condition_body_setup ENDIF error  */
#line 1148 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2983 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* if: IF condition_body_setup ELSE executable_body ENDIF ';'  */
#line 1164 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-4].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::logStructure("IF-ELSE");

    }
#line 3002 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 146: /* if: IF condition_body_setup ELSE executable_body ENDIF error  */
#line 1179 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-4].returnable) || (yyvsp[-2].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3022 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 147: /* if: IF condition_body_setup error  */
#line 1195 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ENDIF);
        yyerrok;

    }
#line 3042 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 148: /* if: IF condition_body_setup ELSE executable_body error  */
#line 1211 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable) || (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ENDIF);
        yyerrok;

    }
#line 3062 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* if: IF condition error ENDIF ';'  */
#line 1227 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3074 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 150: /* if: IF condition error ';'  */
#line 1235 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3087 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* if: IF condition error ELSE ENDIF ';'  */
#line 1244 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3099 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 152: /* if: IF condition error ELSE ';'  */
#line 1252 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3112 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 153: /* if: IF condition_body_setup ELSE error ENDIF ';'  */
#line 1261 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-4].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3132 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 154: /* if: IF condition_body_setup ELSE error ';'  */
#line 1277 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3153 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 155: /* if: ELSE executable_body ENDIF ';'  */
#line 1294 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);

        SemanticActions::announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;

    }
#line 3165 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* if: IF error ';'  */
#line 1302 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;

    }
#line 3177 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 157: /* condition_body_setup: condition_setup then_body_setup  */
#line 1313 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3185 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* condition_setup: condition  */
#line 1320 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                TR_BRANCH_FALSE,
                mapWithOperand({PR_TRIPLE, { .tref = CodeGenerator::INTERMEDIATE_CODE->getLastTriple()}}),
                mapWithOperand({PR_NULL, nullptr})
            }));
        }
    }
#line 3200 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 159: /* then_body_setup: executable_body  */
#line 1334 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            int triple = CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                TR_BRANCH_TRUE,
                mapWithOperand({PR_NULL, nullptr}),
                mapWithOperand({PR_NULL, nullptr})
            });
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(STACK.top(), triple + 1);
            STACK.pop();
            STACK.push(triple);
        }
    }
#line 3220 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* do_while: do_while_head do_body  */
#line 1355 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3228 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 161: /* $@17: %empty  */
#line 1359 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);

    }
#line 3237 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 162: /* do_while: DO $@17 WHILE do_while_tail  */
#line 1364 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3245 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 163: /* do_while: DO error ';'  */
#line 1368 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;

    }
#line 3257 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 164: /* do_while_head: DO  */
#line 1379 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1);
    }
#line 3266 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 165: /* do_body: executable_body WHILE condition ';'  */
#line 1387 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple({
                TR_BRANCH_TRUE,
                mapWithOperand({ PR_TRIPLE, { .tref = CodeGenerator::INTERMEDIATE_CODE->getLastTriple() }}),
                mapWithOperand({ PR_TRIPLE, { .tref = STACK.top() }})
            });
        STACK.pop();

        SemanticActions::logStructure("DO-WHILE");

    }
#line 3285 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* do_body: executable_body WHILE condition error  */
#line 1402 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3297 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 167: /* $@18: %empty  */
#line 1410 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE);

    }
#line 3306 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 168: /* do_body: executable_body $@18 do_while_tail  */
#line 1415 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);
    }
#line 3314 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 170: /* do_while_tail: condition error  */
#line 1423 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3324 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 171: /* executable_body: '{' executable_statements '}'  */
#line 1434 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3332 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* executable_body: '{' executable_statements error  */
#line 1438 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 3344 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* executable_body: '{' error '}'  */
#line 1446 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        yyerrok;
    }
#line 3354 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* executable_body: executable_stmt  */
#line 1452 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3362 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* executable_statements: executable_stmt  */
#line 1458 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 3368 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 176: /* executable_statements: executable_statements executable_stmt  */
#line 1459 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 3374 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* opt_trunc_constant: numeric_constant  */
#line 1466 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3382 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 178: /* opt_trunc_constant: trunc_constant  */
#line 1470 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3390 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 179: /* trunc_constant: TRUNC '(' numeric_constant ')'  */
#line 1477 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

    }
#line 3401 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 180: /* trunc_constant: TRUNC '(' numeric_constant error  */
#line 1484 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3415 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 181: /* trunc_constant: TRUNC numeric_constant ')'  */
#line 1494 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3428 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 182: /* trunc_constant: TRUNC numeric_constant error  */
#line 1503 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3442 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* opt_trunc_variable: variable  */
#line 1516 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = PR_SYMBOL;
            (yyval.metadata).expression = { mapWithCheckerType((yyval.metadata).reference.sref->type), (yyvsp[0].pid), true };
        }
        else
        {
            (yyval.metadata).reference.type = PR_NULL;
            (yyval.metadata).expression = { TC_UNSUPPORTED, (yyvsp[0].pid), true };
        }

    }
#line 3461 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* opt_trunc_variable: trunc_variable  */
#line 1531 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3469 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 185: /* trunc_variable: TRUNC '(' variable ')'  */
#line 1538 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            Metadata m;
            m.reference  = { PR_SYMBOL, entry };
            m.expression = { mapWithCheckerType(entry->type), (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);
        }
        else
        {
            (yyval.metadata).reference  = { PR_NULL, nullptr };
            (yyval.metadata).expression.type = TC_UNSUPPORTED;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

    }
#line 3493 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 186: /* trunc_variable: TRUNC '(' variable error  */
#line 1558 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            Metadata m;
            m.reference  = { PR_SYMBOL, entry };
            m.expression = { mapWithCheckerType(entry->type), (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);
        }
        else
        {
            (yyval.metadata).reference  = { PR_NULL, nullptr };
            (yyval.metadata).expression.type = TC_UNSUPPORTED;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3520 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 187: /* trunc_variable: TRUNC variable ')'  */
#line 1581 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        { 
            Metadata m;
            m.reference  = { PR_SYMBOL, entry };
            m.expression = { mapWithCheckerType(entry->type), (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);

        }
        else
        {
            (yyval.metadata).reference  = { PR_NULL, nullptr };
            (yyval.metadata).expression.type = TC_UNSUPPORTED;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3547 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 188: /* trunc_variable: TRUNC variable error  */
#line 1604 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        { 
            Metadata m;
            m.reference  = { PR_SYMBOL, entry };
            m.expression = { mapWithCheckerType(entry->type), (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);
        }
        else
        {
            (yyval.metadata).reference  = { PR_NULL, nullptr };
            (yyval.metadata).expression.type = TC_UNSUPPORTED;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3574 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 189: /* trunc_variable: TRUNC error ';'  */
#line 1627 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("trunc ..."), false };

        SemanticActions::specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;

    }
#line 3587 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* trunc_expression: TRUNC '(' expression ')'  */
#line 1639 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");
    }
#line 3597 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* trunc_expression: TRUNC '(' expression error  */
#line 1645 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3611 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* trunc_expression: TRUNC expression ')'  */
#line 1655 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3624 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* trunc_expression: TRUNC expression error  */
#line 1664 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3638 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 195: /* condition: '(' comparison error  */
#line 1680 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    }
#line 3647 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 196: /* condition: comparison ')'  */
#line 1685 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
    }
#line 3655 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 197: /* condition: comparison error  */
#line 1689 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    }
#line 3664 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 198: /* comparison: expression comparison_operator expression  */
#line 1697 "include/syntax-analyzer/components/yacc.y"
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
        else
            (yyval.metadata).reference = { PR_NULL, nullptr };
        (yyval.metadata).expression.assignable = false;
    }
#line 3688 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 199: /* comparison: expression error  */
#line 1717 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;

    }
#line 3700 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 200: /* comparison_operator: EQUAL_OP  */
#line 1728 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator(EQUAL_OP), StringPool::create(Translator::translate(EQUAL_OP)) };
    }
#line 3708 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 201: /* comparison_operator: NOT_EQUAL_OP  */
#line 1732 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator(NOT_EQUAL_OP), StringPool::create(Translator::translate(NOT_EQUAL_OP)) };
    }
#line 3716 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 202: /* comparison_operator: GE_OP  */
#line 1736 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator(GE_OP), StringPool::create(Translator::translate(GE_OP)) };
    }
#line 3724 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 203: /* comparison_operator: LE_OP  */
#line 1740 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator(LE_OP), StringPool::create(Translator::translate(LE_OP)) };
    }
#line 3732 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 204: /* comparison_operator: '>'  */
#line 1744 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator('>'), StringPool::create(">") };
    }
#line 3740 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 205: /* comparison_operator: '<'  */
#line 1748 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { mapWithTripleOperator('<'), StringPool::create("<") };
    }
#line 3748 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 206: /* expression: term  */
#line 1757 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3756 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 207: /* expression: expression_setup positive_term  */
#line 1761 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;
        (yyval.metadata).reference = (yyvsp[-1].metadata).reference;
        
        (yyval.metadata).expression.assignable = false;
    }
#line 3772 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 208: /* expression: '+' term  */
#line 1773 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUM_OPERAND);

    }
#line 3783 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 209: /* expression: '+' error  */
#line 1780 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;

    }
#line 3796 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* expression: expression '+' term  */
#line 1789 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 3804 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 211: /* expression: expression '+' error  */
#line 1793 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 3816 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 212: /* expression: expression '-' term  */
#line 1801 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 3824 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 213: /* expression: expression '-' error  */
#line 1805 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 3836 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 214: /* expression: trunc_expression  */
#line 1813 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3844 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 215: /* expression: expression '+' trunc_expression  */
#line 1817 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 3852 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 216: /* expression: expression '-' trunc_expression  */
#line 1821 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 3860 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 217: /* expression_setup: expression  */
#line 1828 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 3870 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 218: /* term: positive_term  */
#line 1839 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3878 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 219: /* term: negative_term  */
#line 1843 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3886 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 220: /* positive_term: positive_term '*' factor  */
#line 1850 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3894 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 221: /* positive_term: positive_term '/' factor  */
#line 1854 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3902 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 222: /* positive_term: trunc_expression '/' factor  */
#line 1858 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3910 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 223: /* positive_term: trunc_expression '*' factor  */
#line 1862 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3918 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 224: /* positive_term: trunc_expression '/' trunc_expression  */
#line 1866 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3926 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 225: /* positive_term: trunc_expression '*' trunc_expression  */
#line 1870 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3934 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 226: /* positive_term: positive_term '/' trunc_expression  */
#line 1874 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3942 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 227: /* positive_term: positive_term '*' trunc_expression  */
#line 1878 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3950 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 228: /* positive_term: positive_factor  */
#line 1882 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3958 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 229: /* positive_term: positive_term '*' error  */
#line 1886 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 3970 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 230: /* positive_term: positive_term '/' error  */
#line 1894 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 3982 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 231: /* negative_term: negative_term '*' factor  */
#line 1905 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 3990 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 232: /* negative_term: negative_term '/' factor  */
#line 1909 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 3998 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 233: /* negative_term: negative_term '/' trunc_expression  */
#line 1913 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4006 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 234: /* negative_term: negative_term '*' trunc_expression  */
#line 1917 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4014 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 235: /* negative_term: negative_factor  */
#line 1921 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4022 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 236: /* negative_term: negative_term '*' error  */
#line 1925 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4034 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 237: /* negative_term: negative_term '/' error  */
#line 1933 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4046 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 238: /* negative_term: '*' factor  */
#line 1941 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_MUL_FACTOR);

    }
#line 4057 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 239: /* negative_term: '/' factor  */
#line 1948 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_DIV_FACTOR);

    }
#line 4068 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 240: /* negative_term: '*' error  */
#line 1955 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4081 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 241: /* negative_term: '/' error  */
#line 1964 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4094 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 242: /* factor: positive_factor  */
#line 1978 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4102 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 243: /* factor: negative_factor  */
#line 1982 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4110 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 244: /* positive_factor: variable  */
#line 1989 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = PR_SYMBOL;
            (yyval.metadata).expression = { mapWithCheckerType((yyval.metadata).reference.sref->type), (yyvsp[0].pid), true };
        }
        else
        {
            (yyval.metadata).reference.type = PR_NULL;
            (yyval.metadata).expression = { TC_UNSUPPORTED, (yyvsp[0].pid), true };
        }

    }
#line 4129 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 245: /* positive_factor: positive_constant  */
#line 2004 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4137 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 246: /* positive_factor: function_invocation_head  */
#line 2008 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4145 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 247: /* negative_factor: negative_constant  */
#line 2015 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4153 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 248: /* negative_factor: lambda_invocation_head  */
#line 2019 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("..."), false };
        
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);
    }
#line 4164 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 249: /* negative_factor: '-' UINTEGER_LITERAL  */
#line 2026 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { TC_UINT, StringPool::create((yyvsp[0].lref)->constant), false };

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4176 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 250: /* negative_factor: '-' function_invocation_head  */
#line 2034 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4187 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 251: /* negative_factor: '-' variable  */
#line 2041 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = PR_SYMBOL;
            (yyval.metadata).expression = { mapWithCheckerType((yyval.metadata).reference.sref->type), (yyvsp[0].pid), false };
        }
        else
        {
            (yyval.metadata).reference = { PR_NULL, nullptr };
            (yyval.metadata).expression = { TC_UNSUPPORTED, (yyvsp[0].pid), false };
        }
        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4207 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 252: /* negative_factor: '-' lambda_invocation_head  */
#line 2057 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("..."), false };

        SemanticActions::announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);

    }
#line 4220 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 253: /* negative_factor: '-' error  */
#line 2066 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_NULL , nullptr };
        (yyval.metadata).expression = { TC_UNSUPPORTED, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUB_OPERANDS);
        yyerrok;

    }
#line 4233 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 254: /* numeric_constant: positive_constant  */
#line 2080 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4241 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 255: /* numeric_constant: negative_constant  */
#line 2084 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4249 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 256: /* positive_constant: UINTEGER_LITERAL  */
#line 2091 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { TC_UINT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4258 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 257: /* positive_constant: FLOAT_LITERAL  */
#line 2096 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { TC_FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4267 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 258: /* negative_constant: '-' FLOAT_LITERAL  */
#line 2104 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { PR_LITERAL , .lref = SemanticActions::turnNegative((yyvsp[0].lref)) };
        (yyval.metadata).expression = { TC_FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };

    }
#line 4277 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 259: /* variable: IDENTIFIER  */
#line 2115 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.pid) = StringPool::create((yyvsp[0].sref)->symbol);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariableName((yyvsp[0].sref)->symbol);

    }
#line 4288 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 260: /* variable: variable '.' IDENTIFIER  */
#line 2122 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].pid), "." + (yyvsp[0].sref)->symbol);
        (yyval.pid) = (yyvsp[-2].pid);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariablePrefix((yyvsp[0].sref)->symbol);

    }
#line 4300 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 4304 "src/syntax-analyzer/components/parser.cpp"

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

#line 2131 "include/syntax-analyzer/components/yacc.y"
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

CodeGenerator::Triples::Operand mapWithOperand(const Metadata::Reference& ref)
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

void createMultipleAssignmentTriple(const Metadata& m)
{
    SemanticAnalyzer::TypeChecker::Expression e1 = {
        TC_UNSUPPORTED,
        SemanticAnalyzer::CHK_VARIABLES.getCurrentVariableName()
    };

    auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
    if (entry != nullptr)
    {
        e1.type = mapWithCheckerType(entry->type);

        SemanticAnalyzer::TypeChecker::Expression e2 = { m.expression.type, *StringPool::get(m.expression.pid) };
        SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                '=',
                mapWithOperand({PR_SYMBOL, entry}),
                mapWithOperand(m.reference)
            });
        }
    }
}

void createTruncateTriple(Metadata& result, const Metadata& operand)
{
    SemanticAnalyzer::TypeChecker::Expression e = { operand.expression.type, *StringPool::get(operand.expression.pid) };
    result.expression.type = SemanticAnalyzer::CHK_TYPES.checkTruncate(e);

    if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
    {
        result.reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
            {TR_FTOI, mapWithOperand(operand.reference), mapWithOperand({ PR_NULL, nullptr })}
        );
        result.reference.type = PR_TRIPLE;
    }
    else
        result.reference = { PR_NULL, nullptr };
    
    result.expression.assignable = false;
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
    else
        r.reference = { PR_NULL, nullptr };
    
    r.expression.assignable = false;
}
