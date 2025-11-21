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
#line 35 "include/syntax-analyzer/components/yacc.y"

#include "syntax-analyzer/components/parser.h"
#include "syntax-analyzer/components/translator.h"
#include "syntax-analyzer/components/string_pool.h"
#include "syntax-analyzer/components/semantic_actions.h"

#include "utils/resources/codes.h"
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
char mapWithTripleOperator(const int op);
CodeGenerator::Triples::Operand mapWithOperand(const Metadata::Reference& ref);

// Avoids Code Repetition
void createMultipleAssignmentTriple(const Metadata& m);
void createTruncateTriple(Metadata& result, const Metadata& operand);
void createArithmeticTriple(Metadata& r, const Metadata& o1, const Metadata& o2, char op);


#line 105 "src/syntax-analyzer/components/parser.cpp"

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
  YYSYMBOL_WORD_IF = 4,                    /* WORD_IF  */
  YYSYMBOL_WORD_ELSE = 5,                  /* WORD_ELSE  */
  YYSYMBOL_WORD_ENDIF = 6,                 /* WORD_ENDIF  */
  YYSYMBOL_WORD_DO = 7,                    /* WORD_DO  */
  YYSYMBOL_WORD_WHILE = 8,                 /* WORD_WHILE  */
  YYSYMBOL_WORD_RETURN = 9,                /* WORD_RETURN  */
  YYSYMBOL_WORD_PRINT = 10,                /* WORD_PRINT  */
  YYSYMBOL_WORD_TRUNC = 11,                /* WORD_TRUNC  */
  YYSYMBOL_WORD_UINT = 12,                 /* WORD_UINT  */
  YYSYMBOL_WORD_FLOAT = 13,                /* WORD_FLOAT  */
  YYSYMBOL_WORD_CR = 14,                   /* WORD_CR  */
  YYSYMBOL_OP_POINTER = 15,                /* OP_POINTER  */
  YYSYMBOL_OP_EQUAL = 16,                  /* OP_EQUAL  */
  YYSYMBOL_OP_GE = 17,                     /* OP_GE  */
  YYSYMBOL_OP_LE = 18,                     /* OP_LE  */
  YYSYMBOL_OP_ASSIGN = 19,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_NOT_EQUAL = 20,              /* OP_NOT_EQUAL  */
  YYSYMBOL_IDENTIFIER = 21,                /* IDENTIFIER  */
  YYSYMBOL_LITERAL_FLOAT = 22,             /* LITERAL_FLOAT  */
  YYSYMBOL_LITERAL_UINT = 23,              /* LITERAL_UINT  */
  YYSYMBOL_LITERAL_STRING = 24,            /* LITERAL_STRING  */
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
#define YYLAST   1087

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  262
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  406

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
       0,   134,   134,   135,   136,   140,   144,   148,   150,   149,
     158,   162,   170,   174,   178,   189,   188,   204,   209,   214,
     224,   225,   229,   233,   237,   244,   251,   258,   266,   276,
     280,   285,   291,   290,   300,   299,   315,   319,   324,   323,
     331,   339,   343,   354,   353,   362,   368,   381,   380,   391,
     402,   417,   418,   420,   419,   427,   433,   439,   447,   452,
     458,   465,   475,   485,   489,   493,   505,   519,   536,   554,
     571,   589,   605,   621,   637,   648,   649,   650,   651,   652,
     653,   654,   660,   683,   692,   709,   716,   729,   742,   755,
     768,   783,   782,   789,   797,   799,   807,   813,   821,   829,
     838,   845,   854,   865,   866,   870,   878,   877,   883,   890,
     899,   903,   913,   914,   916,   915,   925,   926,   931,   932,
     942,   963,   984,  1002,  1010,  1020,  1024,  1030,  1040,  1048,
    1086,  1099,  1098,  1111,  1110,  1116,  1115,  1123,  1122,  1132,
    1131,  1143,  1198,  1199,  1205,  1225,  1246,  1266,  1287,  1308,
    1329,  1337,  1346,  1354,  1363,  1384,  1406,  1414,  1425,  1432,
    1447,  1469,  1474,  1473,  1482,  1493,  1506,  1522,  1531,  1530,
    1542,  1543,  1554,  1558,  1566,  1572,  1576,  1583,  1584,  1590,
    1594,  1601,  1608,  1618,  1627,  1640,  1655,  1662,  1682,  1705,
    1728,  1751,  1763,  1769,  1779,  1788,  1803,  1807,  1815,  1822,
    1833,  1856,  1867,  1871,  1875,  1879,  1883,  1887,  1896,  1900,
    1912,  1919,  1928,  1932,  1940,  1944,  1952,  1956,  1960,  1967,
    1978,  1982,  1989,  1993,  1997,  2001,  2005,  2009,  2013,  2017,
    2021,  2025,  2033,  2044,  2048,  2052,  2056,  2060,  2064,  2072,
    2080,  2087,  2094,  2103,  2117,  2121,  2128,  2143,  2147,  2154,
    2158,  2165,  2173,  2180,  2196,  2205,  2219,  2223,  2230,  2235,
    2243,  2254,  2261
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
  "\"end of file\"", "error", "\"invalid token\"", "INVALID_TOKEN",
  "WORD_IF", "WORD_ELSE", "WORD_ENDIF", "WORD_DO", "WORD_WHILE",
  "WORD_RETURN", "WORD_PRINT", "WORD_TRUNC", "WORD_UINT", "WORD_FLOAT",
  "WORD_CR", "OP_POINTER", "OP_EQUAL", "OP_GE", "OP_LE", "OP_ASSIGN",
  "OP_NOT_EQUAL", "IDENTIFIER", "LITERAL_FLOAT", "LITERAL_UINT",
  "LITERAL_STRING", "'{'", "'}'", "';'", "'('", "','", "')'", "'='", "'>'",
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

#define YYPACT_NINF (-295)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-220)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     627,  -295,    41,   381,  1029,   854,   409,    95,  -295,  -295,
     125,  -295,  -295,    64,   656,  -295,  -295,  -295,   120,  -295,
    -295,  -295,   973,  -295,  -295,  -295,   157,   969,   160,  -295,
    -295,  1029,    59,  -295,    65,   991,    55,  -295,  -295,   951,
     266,   621,   490,   589,  -295,  -295,   541,  1029,   274,   876,
       6,   487,   449,  -295,   343,   350,  -295,  -295,  -295,  -295,
      -3,   886,  -295,    92,    93,   114,   117,   951,   338,   150,
     307,  -295,   377,   782,   131,  -295,  -295,   156,   192,  -295,
     169,    -3,  -295,   241,  -295,  -295,  -295,  -295,   290,   973,
    -295,   418,  -295,  -295,  -295,   215,   202,   427,  -295,   217,
    -295,   220,   554,    -3,  -295,   951,   522,    15,  -295,   274,
    -295,  -295,  -295,  -295,  -295,  -295,    -3,  -295,  -295,  -295,
    -295,  -295,  -295,  -295,   901,   162,  -295,  -295,   263,   263,
     216,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,
     446,   464,   973,   343,   540,   563,   572,   581,   234,  -295,
    -295,   914,   251,  -295,  1009,  -295,   505,  -295,  -295,   269,
    -295,   277,   303,   519,   808,   310,   319,   818,  -295,  -295,
    -295,   685,  -295,  -295,  -295,   318,  -295,  -295,   481,  -295,
    -295,   148,   217,  -295,  -295,   973,  -295,  -295,  -295,   337,
    1009,  1009,  -295,   336,    33,  -295,  -295,   399,  -295,   282,
      58,  -295,  -295,  -295,  -295,    86,   537,  -295,  -295,  -295,
    -295,    57,    27,  -295,  -295,  -295,  -295,  -295,  -295,   208,
     340,  -295,  -295,   274,  -295,  -295,   274,  -295,   112,  -295,
    -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,
    -295,  -295,  -295,  -295,  -295,  -295,  -295,   173,  -295,  -295,
     185,  -295,  -295,   210,   212,  -295,  -295,   714,  -295,  -295,
    -295,   743,  -295,  -295,  -295,  -295,   481,  -295,  -295,   294,
    -295,   394,  -295,   311,  -295,    -3,    -3,  -295,  -295,   224,
    -295,  -295,   270,   455,   329,    36,  -295,  -295,   270,   205,
     270,  -295,  -295,   342,  -295,  -295,   232,   356,  -295,  -295,
    -295,  -295,  -295,  -295,   366,  -295,  -295,  -295,  -295,  -295,
    -295,  -295,  -295,  1051,  -295,   396,  -295,  -295,   481,  -295,
     481,  -295,  -295,   313,  -295,  -295,   348,  -295,   372,    37,
    -295,  -295,  -295,  -295,  -295,   270,   270,  -295,    14,  -295,
    -295,  -295,  -295,  -295,  -295,  1059,  -295,   927,  -295,  -295,
     410,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,
    -295,  -295,   940,  -295,  -295,   410,   844,  -295,   252,  -295,
    -295,   408,   408,  -295,   255,  -295,   772,  -295,  -295,   408,
     408,   315,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,
     598,   412,  -295,  -295,  -295,    -3,   452,   373,    56,  -295,
    -295,    71,  -295,  -295,  -295,  -295
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     4,     0,     0,     0,     0,     0,     0,    41,    42,
     261,     8,    10,     0,     0,     2,     7,     5,     0,    80,
       6,    75,     0,    79,    76,    77,     0,     0,     0,    78,
      81,     0,     0,    11,     0,     0,   261,   259,   258,     0,
       0,     0,     0,     0,   248,   250,     0,     0,   216,     0,
       0,     0,     0,   208,   220,   221,   230,   237,   247,   249,
     246,     0,   175,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     1,     3,     0,   261,    34,
       0,    36,    82,     0,   117,   116,   124,   120,   128,     0,
     125,     0,   119,   118,   161,   168,     0,     0,   261,     0,
     103,     0,     0,   106,   157,     0,     0,     0,   211,     0,
     210,   255,   260,   251,   252,   254,   253,   242,   240,   244,
     245,   243,   241,   148,     0,     0,   158,   160,     0,     0,
       0,   199,   198,   201,   202,   204,   205,   203,   206,   207,
       0,     0,     0,   209,     0,     0,     0,     0,     0,   176,
     177,     0,     0,   164,     0,    74,     0,    70,    73,    69,
      93,     0,     0,   219,     0,     0,     0,     0,    13,     9,
      24,     0,    20,    22,    23,     0,    30,    32,     0,    31,
      29,     0,     0,    86,    85,     0,   123,   127,   130,     0,
       0,     0,   102,     0,     0,   262,   101,     0,   100,     0,
       0,   180,   179,   256,   257,     0,     0,   195,   194,   197,
     196,     0,     0,   145,   144,   227,   225,   226,   224,     0,
       0,   151,   213,   217,   212,   215,   218,   214,   219,   231,
     229,   222,   232,   228,   223,   238,   236,   233,   239,   235,
     234,   174,   173,   172,   178,   156,   163,     0,    68,    71,
       0,    72,    91,     0,     0,    19,    16,     0,   121,    28,
      25,     0,    14,    12,    21,   131,     0,    62,    57,     0,
      35,    53,    51,     0,    40,    37,    39,   126,   129,     0,
     169,    83,     0,     0,     0,     0,    97,    96,     0,     0,
       0,   193,   192,     0,   155,   149,     0,     0,   153,   150,
     171,   170,    67,    66,    95,    88,    87,    90,    89,    18,
      17,    27,    26,     0,    33,    53,    56,    55,     0,    43,
       0,    60,    61,     0,   167,   166,     0,   109,   108,     0,
     184,   183,   112,    99,    98,     0,     0,   107,     0,   154,
     147,   146,   152,    94,    92,     0,   132,     0,    47,    52,
       0,    54,    59,    58,   105,   104,   182,   181,   113,   115,
     111,   110,     0,   139,   135,     0,     0,    44,     0,   137,
     133,     0,     0,    48,     0,    64,     0,    46,    45,     0,
       0,     0,   140,   136,    50,    49,    65,    63,   138,   134,
       0,     0,   143,   142,   186,   185,     0,     0,     0,   141,
     191,     0,   190,   189,   188,   187
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -295,  -295,   440,  -295,  -295,   236,  -295,  -295,  -162,  -168,
     283,  -295,  -295,  -295,  -295,     7,  -295,  -295,  -295,  -295,
    -295,  -295,   207,  -295,  -291,  -295,   111,  -295,    44,  -295,
    -295,  -295,  -295,  -295,  -295,  -295,   -80,  -295,  -295,  -295,
    -295,  -295,     8,  -295,  -295,  -295,  -295,   -83,     9,  -295,
    -295,  -295,  -295,  -295,  -295,    79,  -295,  -295,  -295,  -295,
    -295,  -295,  -295,  -295,  -295,  -295,   289,   -21,  -294,   -64,
    -295,  -295,  -295,   -10,    -2,   445,  -295,    73,  -295,    25,
     437,  -295,   102,   -18,    10,  -180,   -91,   -81,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    14,    15,    73,   169,   170,   164,   256,   171,   172,
     173,   266,   178,    80,   182,    18,   270,   350,   367,   314,
     365,   373,   271,   320,   272,   273,   368,    19,   174,    21,
      22,    82,    23,   304,   344,    24,   102,   205,   337,   289,
     336,    25,    44,    27,    87,    88,    89,    90,    45,   313,
     346,   380,   372,   379,   371,   382,   391,    29,    46,    47,
     126,    30,    65,    31,    94,   191,   246,    63,   151,   200,
     201,   393,   394,    48,   247,    50,   142,    51,    52,    53,
      54,    55,   118,    56,    57,   202,    58,    59,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    49,   257,   264,    32,   261,   187,   131,    26,    28,
      95,   203,    26,    28,    32,   360,   209,   285,    81,   347,
      74,   204,    26,    28,   119,   119,   127,   349,   295,   351,
     109,    32,   103,   296,   282,   101,   132,   330,   356,    26,
      28,   116,   109,   361,    20,   210,    74,    32,    62,   114,
     115,   362,   120,   120,    98,    26,    28,   402,    20,   286,
      96,    32,    99,   293,   100,   110,   331,   357,    33,    26,
      28,   101,   404,    32,    74,    62,     8,     9,    97,    68,
      98,    26,    28,    72,   294,   287,   403,   288,    99,   264,
     100,    62,   104,   264,   101,    83,    69,   101,   152,   194,
      91,   405,   277,   212,   329,   150,   203,    98,   106,   101,
     119,   119,    74,  -200,   283,    99,   204,   100,   215,   217,
     153,    77,   154,    70,    32,   290,   119,   119,   119,   119,
     223,   226,    26,    28,   230,   233,   236,   239,   120,   120,
     156,    78,  -200,   163,   155,   122,   140,   141,    79,   274,
      71,    32,   175,    72,   120,   120,   120,   120,    84,    26,
      28,    92,    91,   213,    32,   224,   227,    32,    62,    98,
     179,    32,    26,    28,   300,    26,    28,   160,   206,    26,
      28,   275,   276,   176,    85,   269,   302,    93,   279,   214,
     -38,   203,   203,   203,   103,   244,   180,   203,   181,   203,
     301,   204,   204,   204,   376,   103,   333,   204,   264,   204,
     285,   305,   303,   307,   297,   228,  -114,   329,   326,   328,
     177,   219,   220,   190,   332,   324,   338,  -114,  -114,   192,
     216,   218,   334,   340,   335,   298,    16,   306,    98,   308,
    -114,   195,   183,   221,   203,   203,   231,   234,   237,   240,
      16,   325,  -219,   377,   204,   204,   384,    32,    91,   341,
     241,    32,  -219,  -219,  -219,    26,    28,   108,   184,    26,
      28,   358,   359,   269,    35,   140,   141,    35,   245,   378,
     323,   197,   385,    17,    36,    37,    38,    36,    37,    38,
     203,    13,    37,    38,    13,   316,   251,    17,    41,   203,
     204,    41,    42,    43,   112,   199,   203,   252,   161,   204,
     128,   129,   321,    32,   352,   317,   204,   392,    35,   185,
     186,    26,    28,     8,     9,   269,   390,   269,    36,    37,
      38,   162,   322,   253,   353,    13,    98,    37,    38,   157,
     258,    40,    41,    42,    43,    32,   259,    32,   265,  -219,
     199,    37,    38,    26,    28,    26,    28,   150,   278,  -219,
    -219,  -219,    32,   281,   199,   158,    32,   299,   159,   339,
      26,    28,   140,   141,    26,    28,    32,   354,   165,   144,
     145,   395,    34,   342,    26,    28,   146,   147,  -122,   150,
     398,   244,    35,   343,    98,    37,    38,   401,  -122,  -122,
    -122,   355,    36,    37,    38,  -122,   244,  -122,   199,    39,
      66,  -122,  -122,  -122,  -122,    40,    41,    42,    43,   188,
      35,    37,    38,   318,   319,   318,   348,   284,   193,  -219,
      36,    37,    38,   189,   199,   366,   381,    67,   -84,  -219,
    -219,  -219,   399,    40,    41,    42,    43,   222,   -84,   -84,
     -84,   383,   140,   141,    76,   -84,   327,    35,   388,   389,
      35,   -84,   -84,   -84,   -84,   225,   197,    36,    37,    38,
      36,    37,    38,   315,    13,    35,   374,    37,    38,   400,
     280,    41,    42,    43,   107,    36,    37,    38,   133,   143,
     199,   117,    13,     8,     9,   267,     0,     0,  -219,    41,
      42,    43,   268,   134,   135,   136,   248,   137,  -219,  -219,
    -219,    36,    37,    38,     0,     0,  -219,     0,    13,   138,
     139,   140,   141,   207,     0,    41,  -219,  -219,  -219,     0,
       0,     0,   249,  -219,     0,   250,     0,     0,   291,   140,
     141,   229,   123,  -219,  -219,  -219,   124,   125,  -219,   254,
       0,    35,   208,   140,   141,   196,   140,   141,  -219,  -219,
    -219,    36,    37,    38,   232,   197,     0,   292,    13,     0,
       0,   140,   141,   235,    35,    41,    37,    38,     0,     0,
       0,   198,   238,    35,    36,    37,    38,     0,     0,   199,
     121,    13,    35,    36,    37,    38,     0,     0,    41,   396,
      13,     0,    36,    37,    38,     0,     0,    41,     0,    13,
      36,    37,    38,     0,     0,     0,    41,    13,     0,    98,
      37,    38,   111,     0,    41,     0,   397,     1,     2,     0,
       0,     3,     4,   199,     5,     0,     6,     7,     0,     8,
       9,     0,    36,   112,   113,     0,     0,     0,    10,    13,
       0,     0,    11,    12,     0,    13,    75,     2,     0,     0,
       3,     4,     0,     5,     0,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,    10,     0,     0,
       0,    11,    12,     0,    13,   262,   166,     0,     0,     3,
       4,     0,     5,     0,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
     167,   263,     0,    13,   309,   166,     0,     0,     3,     4,
       0,     5,     0,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,   167,
     310,     0,    13,   311,   166,     0,     0,     3,     4,     0,
       5,     0,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,   167,   312,
       0,    13,   386,   166,     0,     0,     3,     4,     0,     5,
       0,     6,     7,   166,     8,     9,     3,     4,     0,     5,
       0,     6,     7,    10,     8,     9,     0,   167,   387,     0,
      13,     0,     0,    10,     0,     0,     0,   167,   168,   166,
      13,     0,     3,     4,     0,     5,     0,     6,     7,   166,
       8,     9,     3,     4,     0,     5,     0,     6,     7,    10,
       8,     9,     0,   167,   255,     0,    13,     0,     0,    10,
       0,     0,     0,   167,   260,   166,    13,     0,     3,     4,
       0,     5,     0,     6,     7,    64,     8,     9,  -165,  -165,
       0,  -165,  -162,  -165,  -165,    10,     0,     0,     0,   167,
     375,     0,    13,     0,     0,  -165,     0,   130,     0,  -165,
    -159,  -159,  -165,  -159,     0,  -159,  -159,   148,     0,     0,
       3,     4,     0,     5,     0,     6,     7,  -159,     0,     0,
       0,  -159,   211,     0,  -159,     3,     4,    36,     5,     0,
       6,     7,   149,     0,    13,   242,     0,     0,     3,     4,
       0,     5,    36,     6,     7,     0,    61,     0,   363,    13,
       0,     3,     4,     0,     5,    36,     6,     7,     0,     0,
     243,   369,    13,     0,     3,     4,     0,     5,    36,     6,
       7,     0,     0,   364,     0,    13,     0,     0,     0,     0,
       0,    36,    35,     8,     9,     0,   370,     0,    13,     0,
       0,     0,    36,    37,    38,     0,     0,     0,     0,    13,
      35,     0,     0,     0,    35,    40,    41,    42,    43,     0,
      36,    37,    38,     0,    36,    37,    38,    13,     0,    86,
       0,    13,    35,    40,    41,    42,    43,    40,    41,    42,
      43,     0,    36,    37,    38,     0,     0,     0,     0,   105,
      35,     0,     0,     0,     0,    40,    41,    42,    43,     0,
      36,    37,    38,     3,     4,     0,     5,    39,     6,     7,
       0,     0,     0,    40,    41,    42,    43,     0,     0,     0,
      36,     0,     0,     0,    61,     3,     4,    13,     5,     0,
       6,     7,     0,     3,     4,     0,     5,     0,     6,     7,
       0,     0,    36,     0,     0,     0,   345,     0,     0,    13,
      36,     0,     0,     0,     0,     0,     0,    13
};

static const yytype_int16 yycheck[] =
{
       0,     3,   164,   171,     4,   167,    89,     1,     0,     0,
      31,   102,     4,     4,    14,     1,     1,   197,    18,   313,
      13,   102,    14,    14,    42,    43,    47,   318,     1,   320,
      40,    31,    32,     6,     1,    38,    30,     1,     1,    31,
      31,    41,    52,    29,     0,    30,    39,    47,     4,    41,
      41,   345,    42,    43,    21,    47,    47,     1,    14,     1,
       1,    61,    29,     6,    31,    40,    30,    30,    27,    61,
      61,    38,     1,    73,    67,    31,    12,    13,    19,     6,
      21,    73,    73,    28,    27,    27,    30,    29,    29,   257,
      31,    47,    27,   261,    38,    22,     1,    38,     6,    99,
      27,    30,   185,   124,   284,    61,   197,    21,    35,    38,
     128,   129,   105,     1,   194,    29,   197,    31,   128,   129,
      27,     1,     8,    28,   124,   205,   144,   145,   146,   147,
     140,   141,   124,   124,   144,   145,   146,   147,   128,   129,
      67,    21,    30,    70,    27,    43,    34,    35,    28,     1,
      25,   151,    21,    28,   144,   145,   146,   147,     1,   151,
     151,     1,    89,     1,   164,   140,   141,   167,   124,    21,
       1,   171,   164,   164,     1,   167,   167,    27,   105,   171,
     171,   181,   182,    27,    27,   178,     1,    27,   190,    27,
      21,   282,   283,   284,   194,   151,    27,   288,    29,   290,
      27,   282,   283,   284,   366,   205,     1,   288,   376,   290,
     390,     1,    27,     1,     6,   142,    11,   397,   282,   283,
      28,     5,     6,     8,   288,     1,   290,    22,    23,    27,
     128,   129,    27,     1,    29,    27,     0,    27,    21,    27,
      35,    21,     1,    27,   335,   336,   144,   145,   146,   147,
      14,    27,    11,     1,   335,   336,     1,   257,   185,    27,
      26,   261,    21,    22,    23,   257,   257,     1,    27,   261,
     261,   335,   336,   266,    11,    34,    35,    11,    27,    27,
     273,    11,    27,     0,    21,    22,    23,    21,    22,    23,
     381,    28,    22,    23,    28,     1,    27,    14,    35,   390,
     381,    35,    36,    37,    22,    35,   397,    30,     1,   390,
      36,    37,     1,   313,     1,    21,   397,   381,    11,    29,
      30,   313,   313,    12,    13,   318,    11,   320,    21,    22,
      23,    24,    21,    30,    21,    28,    21,    22,    23,     1,
      30,    34,    35,    36,    37,   345,    27,   347,    30,    11,
      35,    22,    23,   345,   345,   347,   347,   313,    21,    21,
      22,    23,   362,    27,    35,    27,   366,    27,    30,    27,
     362,   362,    34,    35,   366,   366,   376,    29,     1,    36,
      37,   381,     1,    27,   376,   376,    36,    37,    11,   345,
     390,   347,    11,    27,    21,    22,    23,   397,    21,    22,
      23,    29,    21,    22,    23,    28,   362,    30,    35,    28,
       1,    34,    35,    36,    37,    34,    35,    36,    37,     1,
      11,    22,    23,    29,    30,    29,    30,    28,     1,    11,
      21,    22,    23,    15,    35,    25,    28,    28,    11,    21,
      22,    23,    30,    34,    35,    36,    37,     1,    21,    22,
      23,   372,    34,    35,    14,    28,     1,    11,   379,   380,
      11,    34,    35,    36,    37,     1,    11,    21,    22,    23,
      21,    22,    23,   266,    28,    11,   365,    22,    23,    27,
     191,    35,    36,    37,    39,    21,    22,    23,     1,    52,
      35,     1,    28,    12,    13,    14,    -1,    -1,    11,    35,
      36,    37,    21,    16,    17,    18,     1,    20,    21,    22,
      23,    21,    22,    23,    -1,    -1,    11,    -1,    28,    32,
      33,    34,    35,     1,    -1,    35,    21,    22,    23,    -1,
      -1,    -1,    27,    11,    -1,    30,    -1,    -1,     1,    34,
      35,     1,     1,    21,    22,    23,     5,     6,    11,    30,
      -1,    11,    30,    34,    35,     1,    34,    35,    21,    22,
      23,    21,    22,    23,     1,    11,    -1,    30,    28,    -1,
      -1,    34,    35,     1,    11,    35,    22,    23,    -1,    -1,
      -1,    27,     1,    11,    21,    22,    23,    -1,    -1,    35,
       1,    28,    11,    21,    22,    23,    -1,    -1,    35,     1,
      28,    -1,    21,    22,    23,    -1,    -1,    35,    -1,    28,
      21,    22,    23,    -1,    -1,    -1,    35,    28,    -1,    21,
      22,    23,     1,    -1,    35,    -1,    28,     0,     1,    -1,
      -1,     4,     5,    35,     7,    -1,     9,    10,    -1,    12,
      13,    -1,    21,    22,    23,    -1,    -1,    -1,    21,    28,
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
       7,    -1,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,
      -1,    28,     0,     1,    -1,    -1,     4,     5,    -1,     7,
      -1,     9,    10,     1,    12,    13,     4,     5,    -1,     7,
      -1,     9,    10,    21,    12,    13,    -1,    25,    26,    -1,
      28,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,     1,
      28,    -1,     4,     5,    -1,     7,    -1,     9,    10,     1,
      12,    13,     4,     5,    -1,     7,    -1,     9,    10,    21,
      12,    13,    -1,    25,    26,    -1,    28,    -1,    -1,    21,
      -1,    -1,    -1,    25,    26,     1,    28,    -1,     4,     5,
      -1,     7,    -1,     9,    10,     1,    12,    13,     4,     5,
      -1,     7,     8,     9,    10,    21,    -1,    -1,    -1,    25,
      26,    -1,    28,    -1,    -1,    21,    -1,     1,    -1,    25,
       4,     5,    28,     7,    -1,     9,    10,     1,    -1,    -1,
       4,     5,    -1,     7,    -1,     9,    10,    21,    -1,    -1,
      -1,    25,     1,    -1,    28,     4,     5,    21,     7,    -1,
       9,    10,    26,    -1,    28,     1,    -1,    -1,     4,     5,
      -1,     7,    21,     9,    10,    -1,    25,    -1,     1,    28,
      -1,     4,     5,    -1,     7,    21,     9,    10,    -1,    -1,
      26,     1,    28,    -1,     4,     5,    -1,     7,    21,     9,
      10,    -1,    -1,    26,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    21,    11,    12,    13,    -1,    26,    -1,    28,    -1,
      -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      11,    -1,    -1,    -1,    11,    34,    35,    36,    37,    -1,
      21,    22,    23,    -1,    21,    22,    23,    28,    -1,    30,
      -1,    28,    11,    34,    35,    36,    37,    34,    35,    36,
      37,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      11,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    -1,
      21,    22,    23,     4,     5,    -1,     7,    28,     9,    10,
      -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    25,     4,     5,    28,     7,    -1,
       9,    10,    -1,     4,     5,    -1,     7,    -1,     9,    10,
      -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    28
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
      34,    35,   115,   119,    36,    37,    36,    37,     1,    26,
      67,   107,     6,    27,     8,    27,   116,     1,    27,    30,
      27,     1,    24,   116,    45,     1,     1,    25,    26,    43,
      44,    47,    48,    49,    67,    21,    27,    28,    51,     1,
      27,    29,    53,     1,    27,    29,    30,    86,     1,    15,
       8,   104,    27,     1,   127,    21,     1,    11,    27,    35,
     108,   109,   124,   125,   126,    76,   116,     1,    30,     1,
      30,     1,   106,     1,    27,   112,   121,   112,   121,     5,
       6,    27,     1,   112,   118,     1,   112,   118,   116,     1,
     112,   121,     1,   112,   121,     1,   112,   121,     1,   112,
     121,    26,     1,    26,    67,    27,   105,   113,     1,    27,
      30,    27,    30,    30,    30,    26,    46,    47,    30,    27,
      26,    47,     0,    26,    48,    30,    50,    14,    21,    54,
      55,    61,    63,    64,     1,   127,   127,    86,    21,   113,
     105,    27,     1,    75,    28,   124,     1,    27,    29,    78,
      75,     1,    30,     6,    27,     1,     6,     6,    27,    27,
       1,    27,     1,    27,    72,     1,    27,     1,    27,     0,
      26,     0,    26,    88,    58,    61,     1,    21,    29,    30,
      62,     1,    21,    54,     1,    27,   108,     1,   108,   124,
       1,    30,   108,     1,    27,    29,    79,    77,   108,    27,
       1,    27,    27,    27,    73,    25,    89,   107,    30,    63,
      56,    63,     1,    21,    29,    29,     1,    30,   108,   108,
       1,    29,   107,     1,    26,    59,    25,    57,    65,     1,
      26,    93,    91,    60,    65,    26,    47,     1,    27,    92,
      90,    28,    94,    94,     1,    27,     0,    26,    94,    94,
      11,    95,   108,   110,   111,   127,     1,    28,   127,    30,
      27,   127,     1,    30,     1,    30
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
      63,    63,    64,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    70,    70,    71,    71,    71,
      71,    72,    71,    71,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    75,    76,    75,    75,    75,
      77,    77,    78,    78,    79,    78,    80,    80,    80,    80,
      81,    81,    82,    83,    83,    84,    84,    84,    85,    86,
      86,    88,    87,    90,    89,    91,    89,    92,    89,    93,
      89,    94,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    98,
      99,   100,   101,   100,   100,   102,   103,   103,   104,   103,
     105,   105,   106,   106,   106,   106,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   110,   110,   111,   111,   111,
     111,   111,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   115,   115,   115,   115,   115,   115,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   117,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   121,   122,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   125,   125,
     126,   127,   127
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
       2,     2,     1,     3,     2,     3,     5,     5,     4,     3,
       3,     4,     4,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     2,     2,     2,     5,     5,     5,
       5,     0,     6,     3,     1,     0,     4,     4,     5,     5,
       3,     3,     3,     1,     5,     5,     0,     4,     4,     4,
       2,     2,     2,     3,     0,     3,     2,     2,     2,     2,
       2,     4,     2,     2,     1,     1,     3,     2,     1,     3,
       2,     0,     6,     0,     5,     0,     4,     0,     5,     0,
       4,     3,     1,     1,     4,     4,     6,     6,     3,     5,
       5,     4,     6,     5,     6,     5,     4,     3,     2,     1,
       1,     2,     0,     4,     3,     1,     4,     4,     0,     3,
       2,     2,     3,     3,     3,     1,     2,     1,     2,     1,
       1,     4,     4,     3,     3,     1,     1,     4,     4,     3,
       3,     3,     4,     4,     3,     3,     3,     3,     2,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     3,     3,     3,     1,     3,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
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
#line 141 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1667 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 145 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1675 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 8: /* $@1: %empty  */
#line 150 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::addInvalidScope();
        SemanticActions::announceSpecificError(MISSING_PROGRAM_NAME);

        SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration("");

    }
#line 1687 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '}'  */
#line 159 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1695 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: error ';'  */
#line 163 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1704 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* unnamed_program_tail: program_statements '}'  */
#line 171 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1712 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* unnamed_program_tail: '}'  */
#line 175 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1720 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* unnamed_program_tail: program_statements $end  */
#line 179 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1729 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 15: /* $@2: %empty  */
#line 189 "include/syntax-analyzer/components/yacc.y"
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
#line 1745 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 17: /* program_tail: program_statements '}'  */
#line 205 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1754 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 18: /* program_tail: program_statements $end  */
#line 210 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticAnalyzer::removeScope();
    }
#line 1763 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 19: /* program_tail: '}'  */
#line 215 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1772 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statements: program_statement  */
#line 224 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 1778 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statements: program_statements program_statement  */
#line 225 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 1784 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: declarative_stmt  */
#line 230 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 1792 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* program_statement: executable_stmt  */
#line 234 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 1800 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* program_statement: program_head  */
#line 238 "include/syntax-analyzer/components/yacc.y"
    {
       (yyval.returnable) = false;

       SemanticActions::announceSpecificError(INVALID_PROGRAM_NESTING);

    }
#line 1811 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* program_statement: '{' '}'  */
#line 245 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1822 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* program_statement: '{' program_statements '}'  */
#line 252 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1833 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* program_statement: '{' program_statements $end  */
#line 259 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1845 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* program_statement: error ';'  */
#line 267 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;

    }
#line 1854 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type variable_list ';'  */
#line 277 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("VARIABLE DECLARATION");
    }
#line 1862 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* declarative_stmt: type error ';'  */
#line 281 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1871 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 31: /* declarative_stmt: type variable_list error  */
#line 286 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1880 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* $@3: %empty  */
#line 291 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction (
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, (yyvsp[-1].sref)->symbol})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionName((yyvsp[-1].sref)->symbol);

    }
#line 1892 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 34: /* $@4: %empty  */
#line 300 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction(
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, "...()"})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionWithoutName();

        SemanticActions::announceSpecificError(MISSING_FUNCTION_NAME);

    }
#line 1906 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 36: /* variable_list: variable  */
#line 316 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1914 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* variable_list: variable_list ',' variable  */
#line 320 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1922 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 38: /* $@5: %empty  */
#line 324 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 1930 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 39: /* variable_list: variable_list $@5 variable  */
#line 328 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1938 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* variable_list: variable_list ',' error  */
#line 332 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1947 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* type: WORD_UINT  */
#line 340 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UINT;
    }
#line 1955 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* type: WORD_FLOAT  */
#line 344 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = FLOAT;
        SemanticActions::announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1964 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* $@6: %empty  */
#line 354 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();

    }
#line 1973 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* unnamed_function_declaration_tail: function_body ';'  */
#line 363 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

    }
#line 1983 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* unnamed_function_declaration_tail: function_body error  */
#line 369 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 1996 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* $@7: %empty  */
#line 381 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
        if (entry != nullptr)
            CodeGenerator::addIntermediateCodeBlock(entry);

    }
#line 2007 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 49: /* function_declaration_tail: function_body ';'  */
#line 392 "include/syntax-analyzer/components/yacc.y"
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn((yyvsp[-1].returnable));
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::logStructure("FUNCTION DECLARATION");

    }
#line 2022 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 50: /* function_declaration_tail: function_body error  */
#line 403 "include/syntax-analyzer/components/yacc.y"
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn((yyvsp[-1].returnable));
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2038 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 53: /* $@8: %empty  */
#line 420 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2046 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* formal_parameter: type IDENTIFIER  */
#line 428 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2056 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 56: /* formal_parameter: type error  */
#line 434 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2066 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* formal_parameter: IDENTIFIER  */
#line 440 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2078 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* formal_parameter: parameter_semantics type IDENTIFIER  */
#line 448 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2087 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* formal_parameter: parameter_semantics type error  */
#line 453 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2097 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* formal_parameter: parameter_semantics error  */
#line 459 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        SemanticActions::announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;

    }
#line 2108 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 466 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2119 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* parameter_semantics: WORD_CR  */
#line 476 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CR);

    }
#line 2128 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* function_body: '{' program_statements '}'  */
#line 486 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 2136 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* function_body: '{' '}'  */
#line 490 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 2144 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 65: /* function_body: '{' program_statements $end  */
#line 494 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    }
#line 2155 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 66: /* return: WORD_RETURN '(' expression ')' ';'  */
#line 506 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                (yyvsp[-2].metadata).expression.type,
                mapWithOperand((yyvsp[-2].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

    }
#line 2173 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 67: /* return: WORD_RETURN '(' expression ')' error  */
#line 520 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                (yyvsp[-2].metadata).expression.type,
                mapWithOperand((yyvsp[-2].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2194 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 68: /* return: WORD_RETURN '(' expression error  */
#line 537 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                (yyvsp[-1].metadata).expression.type,
                mapWithOperand((yyvsp[-1].metadata).reference),
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2216 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 69: /* return: WORD_RETURN expression ')'  */
#line 555 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                (yyvsp[-1].metadata).expression.type,
                mapWithOperand((yyvsp[-1].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);

    }
#line 2237 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* return: WORD_RETURN expression error  */
#line 572 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                (yyvsp[-1].metadata).expression.type,
                mapWithOperand((yyvsp[-1].metadata).reference),
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2259 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* return: WORD_RETURN '(' expression ';'  */
#line 590 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                (yyvsp[-1].metadata).expression.type, 
                mapWithOperand((yyvsp[-1].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::announceSpecificError(MISSING_CLOSING_PARENTHESIS);

    }
#line 2279 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* return: WORD_RETURN expression ')' ';'  */
#line 606 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                (yyvsp[-2].metadata).expression.type,
                mapWithOperand((yyvsp[-2].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 2299 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 73: /* return: WORD_RETURN expression ';'  */
#line 622 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::ReturnChecker::Element e = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                (yyvsp[-1].metadata).expression.type, 
                mapWithOperand((yyvsp[-1].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);

    }
#line 2319 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 74: /* return: WORD_RETURN error ';'  */
#line 638 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(RETURN_SYNTAX_ERROR);
        yyerrok;

    }
#line 2329 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* executable_stmt: assignment  */
#line 648 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2335 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* executable_stmt: multiple_assignments  */
#line 649 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2341 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 77: /* executable_stmt: invocation  */
#line 650 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2347 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 78: /* executable_stmt: if  */
#line 651 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2353 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 79: /* executable_stmt: print  */
#line 652 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2359 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 80: /* executable_stmt: return  */
#line 653 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = true;  }
#line 2365 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* executable_stmt: do_while  */
#line 654 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2371 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 82: /* assignment: assignment_head assignment_tail  */
#line 661 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        { 
            SemanticAnalyzer::TypeChecker::Expression e1 = {
                (yyvsp[-1].metadata).expression.type,
                *StringPool::get((yyvsp[-1].metadata).expression.pid),
                (yyvsp[-1].metadata).expression.assignable
            };
            SemanticAnalyzer::TypeChecker::Expression e2 = {
                (yyvsp[0].metadata).expression.type,
                *StringPool::get((yyvsp[0].metadata).expression.pid),
                (yyvsp[0].metadata).expression.assignable
            };

            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_ASSIGN,
                SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2),
                mapWithOperand((yyvsp[-1].metadata).reference),
                mapWithOperand((yyvsp[0].metadata).reference)
            });
        }
    }
#line 2398 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* assignment: variable OP_ASSIGN error ';'  */
#line 684 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2408 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 84: /* assignment_head: variable OP_ASSIGN  */
#line 693 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression = { (yyval.metadata).reference.sref->type, (yyvsp[-1].pid), true };
        }
        else
        {
            (yyval.metadata).reference.type = NULLREF;
            (yyval.metadata).expression = { UNKNOWN, (yyvsp[-1].pid), false };
        }
    }
#line 2426 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 85: /* assignment_tail: expression ';'  */
#line 710 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::logStructure("ASSIGNMENT");

    }
#line 2437 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 86: /* assignment_tail: expression error  */
#line 717 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2449 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* print: WORD_PRINT '(' LITERAL_STRING ')' ';'  */
#line 730 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("WORD_PRINT");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT, 
                STRING,
                CodeGenerator::Triples::Operand({ LITERAL, { .lref = (yyvsp[-2].lref) } }), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

    }
#line 2466 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 88: /* print: WORD_PRINT '(' LITERAL_STRING ')' error  */
#line 743 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT, 
                STRING,
                CodeGenerator::Triples::Operand({ LITERAL, { .lref = (yyvsp[-2].lref) } }), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2483 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 89: /* print: WORD_PRINT '(' expression ')' ';'  */
#line 756 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT, 
                (yyvsp[-2].metadata).expression.type,
                mapWithOperand((yyvsp[-2].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::logStructure("WORD_PRINT");

    }
#line 2500 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* print: WORD_PRINT '(' expression ')' error  */
#line 769 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT,
                (yyvsp[-2].metadata).expression.type, 
                mapWithOperand((yyvsp[-2].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2518 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 91: /* $@9: %empty  */
#line 783 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;

    }
#line 2528 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 93: /* print: WORD_PRINT error ';'  */
#line 790 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(PRINT_SYNTAX_ERROR);
        yyerrok;
    }
#line 2537 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* print_end: %empty  */
#line 799 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
    }
#line 2545 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* multiple_assignments: variable assignment_list opt_trunc_constant ';'  */
#line 808 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2555 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* multiple_assignments: variable assignment_list opt_trunc_constant error  */
#line 814 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2567 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 98: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 822 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2579 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 99: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 830 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2592 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 100: /* multiple_assignments: variable assignment_list ';'  */
#line 839 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::announceSpecificError(MISSING_RIGHT_SIDE_VALUES);

    }
#line 2603 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* multiple_assignments: variable assignment_list error  */
#line 846 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2616 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* multiple_assignments: variable error ';'  */
#line 855 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;

    }
#line 2628 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 104: /* assignment_list: ',' variable assignment_list opt_trunc_constant ','  */
#line 867 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2636 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 105: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 871 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_EQUALS);

    }
#line 2647 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 106: /* $@10: %empty  */
#line 878 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_COMMA);

    }
#line 2656 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 884 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[0].metadata));

        SemanticActions::announceSpecificError(MISSING_COMMA);

    }
#line 2667 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* assignment_list: ',' variable assignment_list error  */
#line 891 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2677 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* assignment_end: opt_trunc_constant ','  */
#line 900 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2685 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* assignment_end: opt_trunc_constant error  */
#line 904 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 2696 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 114: /* $@11: %empty  */
#line 916 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2704 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 117: /* invocation: function_invocation_head error  */
#line 927 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2713 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* invocation: lambda_invocation_head error  */
#line 933 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2722 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* function_invocation_head: invocation_setup function_invocation_tail  */
#line 943 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = (yyvsp[-1].metadata).expression;
        StringPool::append((yyval.metadata).expression.pid, *StringPool::get((yyvsp[0].metadata).expression.pid));

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr && (yyvsp[-1].metadata).reference.type != NULLREF)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_CALL, 
                (yyvsp[-1].metadata).expression.type,
                mapWithOperand((yyvsp[-1].metadata).reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) }
            );
            CodeGenerator::INTERMEDIATE_CODE->commit();
            (yyval.metadata).reference.type = TRIPLE;
        }
        else
            (yyval.metadata).reference = (yyvsp[-1].metadata).reference;

        SemanticActions::logStructure("FUNCTION INVOCATION");
    }
#line 2747 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 121: /* function_invocation_head: IDENTIFIER '(' error ')'  */
#line 964 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression.pid = StringPool::create((yyvsp[-3].sref)->symbol + "(...)");
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_INVOCATIONS.checkFunctionInScope((yyvsp[-3].sref)->symbol);
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression.type = (yyval.metadata).reference.sref->type;
        }
        else
        {
            (yyval.metadata).reference.type = NULLREF;
            (yyval.metadata).expression.type = UNKNOWN;
        }

        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
#line 2769 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* invocation_setup: IDENTIFIER '('  */
#line 985 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression.pid = StringPool::create((yyvsp[-1].sref)->symbol + "(");
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_INVOCATIONS.checkFunctionInScope((yyvsp[-1].sref)->symbol);
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression.type = (yyval.metadata).reference.sref->type;
        }
        else
        {
            (yyval.metadata).reference.type = NULLREF;
            (yyval.metadata).expression.type = UNKNOWN;
        }
    }
#line 2788 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* function_invocation_tail: real_parameter_list ')'  */
#line 1003 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, ")");
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
    }
#line 2800 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 124: /* function_invocation_tail: ')'  */
#line 1011 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = { UNKNOWN, StringPool::create(")") };

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
        SemanticActions::announceSpecificError(MISSING_ARGUMENT);
    }
#line 2811 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 125: /* real_parameter_list: real_parameter  */
#line 1021 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 2819 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* real_parameter_list: real_parameter_list ',' real_parameter  */
#line 1025 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].metadata).expression.pid, ", " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
    }
#line 2829 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* real_parameter_list: real_parameter_list_setup real_parameter  */
#line 1031 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

    }
#line 2840 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* real_parameter_list_setup: real_parameter_list  */
#line 1041 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2849 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 129: /* real_parameter: expression OP_POINTER IDENTIFIER  */
#line 1049 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_INVOCATIONS.checkParameterInScope((yyvsp[0].sref)->symbol);
        if (entry != nullptr)
        {
            SemanticAnalyzer::TypeChecker::Expression e1 = {
                (yyvsp[-2].metadata).expression.type,
                *StringPool::get((yyvsp[-2].metadata).expression.pid),
                (yyvsp[-2].metadata).expression.assignable
            };
            SemanticAnalyzer::TypeChecker::Expression e2 = { entry->semantics, (yyvsp[0].sref)->symbol, true };
            int result = SemanticAnalyzer::CHK_TYPES.checkSemantics(e1, e2);

            e2.type = entry->type;
            if (result == CR && CodeGenerator::INTERMEDIATE_CODE != nullptr)
            { 
                int typeCR = SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2);
                CodeGenerator::INTERMEDIATE_CODE->addBuffer ({
                    CODEOP_ASSIGN,
                    typeCR,
                    mapWithOperand((yyvsp[-2].metadata).reference), 
                    CodeGenerator::Triples::Operand({ SYMBOL, entry }) 
                });
            }
            else if (result == CV && CodeGenerator::INTERMEDIATE_CODE != nullptr)
            { 
                int typeCV = SemanticAnalyzer::CHK_TYPES.checkAssignment(e2, e1);
                CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                    CODEOP_ASSIGN,
                    typeCV,
                    CodeGenerator::Triples::Operand({ SYMBOL, entry }), 
                    mapWithOperand((yyvsp[-2].metadata).reference) 
                });
            }
        }
        StringPool::append((yyvsp[-2].metadata).expression.pid, "->" + (yyvsp[0].sref)->symbol);
        (yyval.metadata).expression = { UNKNOWN, (yyvsp[-2].metadata).expression.pid, false };
    }
#line 2891 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* real_parameter: expression error  */
#line 1087 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2902 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 131: /* $@12: %empty  */
#line 1099 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclaration((yyvsp[-1].sref)->symbol);
        CodeGenerator::addIntermediateCodeBlock (
              SemanticAnalyzer::CHK_LAMBDAS.getLambda().function
        );

    }
#line 2914 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* $@13: %empty  */
#line 1111 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 2922 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 135: /* $@14: %empty  */
#line 1116 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);

    }
#line 2932 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 137: /* $@15: %empty  */
#line 1123 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 2944 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 139: /* $@16: %empty  */
#line 1132 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_BOTH_BRACKETS);
        yyerrok;

    }
#line 2956 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* lambda_invocation_tail: '(' lambda_real_parameter ')'  */
#line 1144 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("LAMBDA");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_RET,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            });

        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::LambdaChecker::Lambda l = SemanticAnalyzer::CHK_LAMBDAS.getLambda();
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::Triples::Operand o1;
            SemanticAnalyzer::TypeChecker::Expression e1, e2;
            if (l.parameter != nullptr)
            {
                e1 = { l.parameter->type, l.pname, true };
                o1 = { SYMBOL, l.parameter };
            }
            else
            {
                e1 = { UNKNOWN, "...", false };
                o1 = { NULLREF, nullptr };
            }
            e2 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid), (yyvsp[-1].metadata).expression.assignable };
            int type = SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2);

            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_ASSIGN,
                type,
                o1,
                mapWithOperand((yyvsp[-1].metadata).reference)
            });

            if (l.function != nullptr)
                CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                    CODEOP_CALL,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({SYMBOL, l.function}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr})
                });
        }
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclarationEnd();

        SemanticActions::logStructure("LAMBDA");

    }
#line 3012 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 142: /* lambda_real_parameter: opt_trunc_variable  */
#line 1198 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3018 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* lambda_real_parameter: opt_trunc_constant  */
#line 1199 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3024 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* if: WORD_IF condition_body_setup WORD_ENDIF ';'  */
#line 1206 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::logStructure("WORD_IF");

    }
#line 3048 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* if: WORD_IF condition_body_setup WORD_ENDIF error  */
#line 1226 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3073 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 146: /* if: WORD_IF condition_body_setup WORD_ELSE executable_body WORD_ENDIF ';'  */
#line 1247 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-4].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::logStructure("WORD_IF-WORD_ELSE");

    }
#line 3097 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 147: /* if: WORD_IF condition_body_setup WORD_ELSE executable_body WORD_ENDIF error  */
#line 1267 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-4].returnable) || (yyvsp[-2].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3122 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 148: /* if: WORD_IF condition_body_setup error  */
#line 1288 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ENDIF);
        yyerrok;

    }
#line 3147 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* if: WORD_IF condition_body_setup WORD_ELSE executable_body error  */
#line 1309 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable) || (yyvsp[-1].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ENDIF);
        yyerrok;

    }
#line 3172 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 150: /* if: WORD_IF condition error WORD_ENDIF ';'  */
#line 1330 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3184 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* if: WORD_IF condition error ';'  */
#line 1338 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3197 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 152: /* if: WORD_IF condition error WORD_ELSE WORD_ENDIF ';'  */
#line 1347 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3209 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 153: /* if: WORD_IF condition error WORD_ELSE ';'  */
#line 1355 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3222 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 154: /* if: WORD_IF condition_body_setup WORD_ELSE error WORD_ENDIF ';'  */
#line 1364 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-4].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3247 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 155: /* if: WORD_IF condition_body_setup WORD_ELSE error ';'  */
#line 1385 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference (
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->addTriple({
                    CODEOP_IF_END,
                    UNKNOWN,
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                    CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                })
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3273 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* if: WORD_ELSE executable_body WORD_ENDIF ';'  */
#line 1407 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);

        SemanticActions::announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;

    }
#line 3285 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 157: /* if: WORD_IF error ';'  */
#line 1415 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;

    }
#line 3297 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* condition_body_setup: condition_setup then_body_setup  */
#line 1426 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3305 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 159: /* condition_setup: condition  */
#line 1433 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_BRANCH_FALSE,
                (yyvsp[0].metadata).expression.type,
                mapWithOperand((yyvsp[0].metadata).reference),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            }));
        }
    }
#line 3321 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* then_body_setup: executable_body  */
#line 1448 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            int triple = CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_BRANCH_TRUE,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            });
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(STACK.top(), triple + 1);
            STACK.pop();
            STACK.push(triple);
        }
    }
#line 3342 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 161: /* do_while: do_while_head do_body  */
#line 1470 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3350 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 162: /* $@17: %empty  */
#line 1474 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);

    }
#line 3359 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 163: /* do_while: WORD_DO $@17 WORD_WHILE do_while_tail  */
#line 1479 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3367 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 164: /* do_while: WORD_DO error ';'  */
#line 1483 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;

    }
#line 3379 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 165: /* do_while_head: WORD_DO  */
#line 1494 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_DO_START,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            }));
    }
#line 3393 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* do_body: executable_body WORD_WHILE condition ';'  */
#line 1507 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_BRANCH_TRUE,
                (yyvsp[-1].metadata).expression.type,
                mapWithOperand((yyvsp[-1].metadata).reference),
                CodeGenerator::Triples::Operand({ TRIPLE, { .tref = STACK.top() }})
            });
        STACK.pop();

        SemanticActions::logStructure("WORD_DO-WORD_WHILE");

    }
#line 3413 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 167: /* do_body: executable_body WORD_WHILE condition error  */
#line 1523 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3425 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 168: /* $@18: %empty  */
#line 1531 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE);

    }
#line 3434 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 169: /* do_body: executable_body $@18 do_while_tail  */
#line 1536 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);
    }
#line 3442 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 171: /* do_while_tail: condition error  */
#line 1544 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3452 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* executable_body: '{' executable_statements '}'  */
#line 1555 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3460 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* executable_body: '{' executable_statements error  */
#line 1559 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 3472 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* executable_body: '{' error '}'  */
#line 1567 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        yyerrok;
    }
#line 3482 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* executable_body: executable_stmt  */
#line 1573 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3490 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 176: /* executable_body: '{' '}'  */
#line 1577 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3498 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* executable_statements: executable_stmt  */
#line 1583 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 3504 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 178: /* executable_statements: executable_statements executable_stmt  */
#line 1584 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 3510 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 179: /* opt_trunc_constant: numeric_constant  */
#line 1591 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3518 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 180: /* opt_trunc_constant: trunc_constant  */
#line 1595 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3526 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 181: /* trunc_constant: WORD_TRUNC '(' numeric_constant ')'  */
#line 1602 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

    }
#line 3537 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 182: /* trunc_constant: WORD_TRUNC '(' numeric_constant error  */
#line 1609 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3551 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* trunc_constant: WORD_TRUNC numeric_constant ')'  */
#line 1619 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3564 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* trunc_constant: WORD_TRUNC numeric_constant error  */
#line 1628 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3578 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 185: /* opt_trunc_variable: variable  */
#line 1641 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression = { (yyval.metadata).reference.sref->type, (yyvsp[0].pid), true };
        }
        else
        {
            (yyval.metadata).reference.type = NULLREF;
            (yyval.metadata).expression = { UNKNOWN, (yyvsp[0].pid), true };
        }

    }
#line 3597 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 186: /* opt_trunc_variable: trunc_variable  */
#line 1656 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3605 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 187: /* trunc_variable: WORD_TRUNC '(' variable ')'  */
#line 1663 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);
        }
        else
        {
            (yyval.metadata).reference  = { NULLREF, nullptr };
            (yyval.metadata).expression.type = UNKNOWN;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

    }
#line 3629 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 188: /* trunc_variable: WORD_TRUNC '(' variable error  */
#line 1683 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);
        }
        else
        {
            (yyval.metadata).reference  = { NULLREF, nullptr };
            (yyval.metadata).expression.type = UNKNOWN;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3656 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 189: /* trunc_variable: WORD_TRUNC variable ')'  */
#line 1706 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        { 
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);

        }
        else
        {
            (yyval.metadata).reference  = { NULLREF, nullptr };
            (yyval.metadata).expression.type = UNKNOWN;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3683 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* trunc_variable: WORD_TRUNC variable error  */
#line 1729 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        { 
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, (yyvsp[-1].pid), true };
            
            createTruncateTriple((yyval.metadata), m);
        }
        else
        {
            (yyval.metadata).reference  = { NULLREF, nullptr };
            (yyval.metadata).expression.type = UNKNOWN;
            (yyval.metadata).expression.assignable = false;
        }
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].pid)) + ")");

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3710 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* trunc_variable: WORD_TRUNC error ';'  */
#line 1752 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("trunc ..."), false };

        SemanticActions::specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;

    }
#line 3723 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* trunc_expression: WORD_TRUNC '(' expression ')'  */
#line 1764 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");
    }
#line 3733 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* trunc_expression: WORD_TRUNC '(' expression error  */
#line 1770 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3747 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 194: /* trunc_expression: WORD_TRUNC expression ')'  */
#line 1780 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3760 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 195: /* trunc_expression: WORD_TRUNC expression error  */
#line 1789 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3774 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 196: /* condition: '(' comparison ')'  */
#line 1804 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);
    }
#line 3782 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 197: /* condition: '(' comparison error  */
#line 1808 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3794 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 198: /* condition: comparison ')'  */
#line 1816 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3805 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 199: /* condition: comparison error  */
#line 1823 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;

    }
#line 3817 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 200: /* comparison: expression comparison_operator expression  */
#line 1834 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-2].metadata).expression.type, *StringPool::get((yyvsp[-2].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
        StringPool::append((yyvsp[-2].metadata).expression.pid, *StringPool::get((yyvsp[-1].op).pid) + *StringPool::get((yyvsp[0].metadata).expression.pid));

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            (yyval.metadata).reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                (yyvsp[-1].op).tid,
                (yyval.metadata).expression.type,
                mapWithOperand((yyvsp[-2].metadata).reference),
                mapWithOperand((yyvsp[0].metadata).reference)
            });
            (yyval.metadata).reference.type = TRIPLE;
        }
        else
            (yyval.metadata).reference = { NULLREF, nullptr };
        (yyval.metadata).expression.assignable = false;
    }
#line 3844 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 201: /* comparison: expression error  */
#line 1857 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;

    }
#line 3856 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 202: /* comparison_operator: OP_EQUAL  */
#line 1868 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_EQUAL, StringPool::create(Translator::translate(OP_EQUAL)) };
    }
#line 3864 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 203: /* comparison_operator: OP_NOT_EQUAL  */
#line 1872 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_NOT_EQUAL, StringPool::create(Translator::translate(OP_NOT_EQUAL)) };
    }
#line 3872 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 204: /* comparison_operator: OP_GE  */
#line 1876 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GE, StringPool::create(Translator::translate(OP_GE)) };
    }
#line 3880 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 205: /* comparison_operator: OP_LE  */
#line 1880 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LE, StringPool::create(Translator::translate(OP_LE)) };
    }
#line 3888 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 206: /* comparison_operator: '>'  */
#line 1884 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GT, StringPool::create(">") };
    }
#line 3896 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 207: /* comparison_operator: '<'  */
#line 1888 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LT, StringPool::create("<") };
    }
#line 3904 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 208: /* expression: term  */
#line 1897 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3912 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 209: /* expression: expression_setup positive_term  */
#line 1901 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;
        (yyval.metadata).reference = (yyvsp[-1].metadata).reference;
        
        (yyval.metadata).expression.assignable = false;
    }
#line 3928 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* expression: '+' term  */
#line 1913 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUM_OPERAND);

    }
#line 3939 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 211: /* expression: '+' error  */
#line 1920 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;

    }
#line 3952 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 212: /* expression: expression '+' term  */
#line 1929 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 3960 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 213: /* expression: expression '+' error  */
#line 1933 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 3972 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 214: /* expression: expression '-' term  */
#line 1941 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 3980 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 215: /* expression: expression '-' error  */
#line 1945 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 3992 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 216: /* expression: trunc_expression  */
#line 1953 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4000 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 217: /* expression: expression '+' trunc_expression  */
#line 1957 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4008 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 218: /* expression: expression '-' trunc_expression  */
#line 1961 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4016 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 219: /* expression_setup: expression  */
#line 1968 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 4026 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 220: /* term: positive_term  */
#line 1979 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4034 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 221: /* term: negative_term  */
#line 1983 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4042 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 222: /* positive_term: positive_term '*' factor  */
#line 1990 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4050 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 223: /* positive_term: positive_term '/' factor  */
#line 1994 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4058 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 224: /* positive_term: trunc_expression '/' factor  */
#line 1998 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4066 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 225: /* positive_term: trunc_expression '*' factor  */
#line 2002 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4074 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 226: /* positive_term: trunc_expression '/' trunc_expression  */
#line 2006 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4082 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 227: /* positive_term: trunc_expression '*' trunc_expression  */
#line 2010 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4090 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 228: /* positive_term: positive_term '/' trunc_expression  */
#line 2014 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4098 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 229: /* positive_term: positive_term '*' trunc_expression  */
#line 2018 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4106 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 230: /* positive_term: positive_factor  */
#line 2022 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4114 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 231: /* positive_term: positive_term '*' error  */
#line 2026 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4126 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 232: /* positive_term: positive_term '/' error  */
#line 2034 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4138 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 233: /* negative_term: negative_term '*' factor  */
#line 2045 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4146 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 234: /* negative_term: negative_term '/' factor  */
#line 2049 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4154 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 235: /* negative_term: negative_term '/' trunc_expression  */
#line 2053 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4162 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 236: /* negative_term: negative_term '*' trunc_expression  */
#line 2057 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4170 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 237: /* negative_term: negative_factor  */
#line 2061 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4178 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 238: /* negative_term: negative_term '*' error  */
#line 2065 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4190 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 239: /* negative_term: negative_term '/' error  */
#line 2073 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4202 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 240: /* negative_term: '*' factor  */
#line 2081 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_MUL_FACTOR);

    }
#line 4213 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 241: /* negative_term: '/' factor  */
#line 2088 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_DIV_FACTOR);

    }
#line 4224 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 242: /* negative_term: '*' error  */
#line 2095 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4237 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 243: /* negative_term: '/' error  */
#line 2104 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4250 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 244: /* factor: positive_factor  */
#line 2118 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4258 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 245: /* factor: negative_factor  */
#line 2122 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4266 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 246: /* positive_factor: variable  */
#line 2129 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression = { (yyval.metadata).reference.sref->type, (yyvsp[0].pid), true };
        }
        else
        {
            (yyval.metadata).reference.type = NULLREF;
            (yyval.metadata).expression = { UNKNOWN, (yyvsp[0].pid), true };
        }

    }
#line 4285 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 247: /* positive_factor: positive_constant  */
#line 2144 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4293 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 248: /* positive_factor: function_invocation_head  */
#line 2148 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4301 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 249: /* negative_factor: negative_constant  */
#line 2155 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4309 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 250: /* negative_factor: lambda_invocation_head  */
#line 2159 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };
        
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);
    }
#line 4320 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 251: /* negative_factor: '-' LITERAL_UINT  */
#line 2166 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4332 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 252: /* negative_factor: '-' function_invocation_head  */
#line 2174 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4343 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 253: /* negative_factor: '-' variable  */
#line 2181 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ((yyval.metadata).reference.sref != nullptr)
        {
            (yyval.metadata).reference.type = SYMBOL;
            (yyval.metadata).expression = { (yyval.metadata).reference.sref->type, (yyvsp[0].pid), false };
        }
        else
        {
            (yyval.metadata).reference = { NULLREF, nullptr };
            (yyval.metadata).expression = { UNKNOWN, (yyvsp[0].pid), false };
        }
        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4363 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 254: /* negative_factor: '-' lambda_invocation_head  */
#line 2197 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);

    }
#line 4376 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 255: /* negative_factor: '-' error  */
#line 2206 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUB_OPERANDS);
        yyerrok;

    }
#line 4389 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 256: /* numeric_constant: positive_constant  */
#line 2220 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4397 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 257: /* numeric_constant: negative_constant  */
#line 2224 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4405 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 258: /* positive_constant: LITERAL_UINT  */
#line 2231 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4414 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 259: /* positive_constant: LITERAL_FLOAT  */
#line 2236 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4423 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 260: /* negative_constant: '-' LITERAL_FLOAT  */
#line 2244 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL , .lref = SemanticActions::turnNegative((yyvsp[0].lref)) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };

    }
#line 4433 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 261: /* variable: IDENTIFIER  */
#line 2255 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.pid) = StringPool::create((yyvsp[0].sref)->symbol);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariableName((yyvsp[0].sref)->symbol);

    }
#line 4444 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 262: /* variable: variable '.' IDENTIFIER  */
#line 2262 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].pid), "." + (yyvsp[0].sref)->symbol);
        (yyval.pid) = (yyvsp[-2].pid);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariablePrefix((yyvsp[0].sref)->symbol);

    }
#line 4456 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 4460 "src/syntax-analyzer/components/parser.cpp"

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

#line 2271 "include/syntax-analyzer/components/yacc.y"
 // Codes ------------------------------------------

void yyerror(const char* s)
{
    SemanticActions::announceSyntaxError();
}

CodeGenerator::Triples::Operand mapWithOperand(const Metadata::Reference& ref)
{
    switch (ref.type)
    {
    case SYMBOL:
        return { SYMBOL , { .sref = ref.sref } };
    case LITERAL:
        return { LITERAL, { .lref = ref.lref } };
    case TRIPLE:
        return { TRIPLE , { .tref = ref.tref } };
    default:
        return { NULLREF, { .sref = nullptr  }};
    }
}

void createMultipleAssignmentTriple(const Metadata& m)
{
    SemanticAnalyzer::TypeChecker::Expression e1 = {
        UNKNOWN,
        SemanticAnalyzer::CHK_VARIABLES.getCurrentVariableName()
    };

    auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
    if (entry != nullptr)
    {
        e1.type = entry->type;

        SemanticAnalyzer::TypeChecker::Expression e2 = { m.expression.type, *StringPool::get(m.expression.pid) };
        int result = SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_ASSIGN,
                result,
                CodeGenerator::Triples::Operand({SYMBOL, entry}),
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
        result.reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple ({
            CODEOP_FTOI,
            result.expression.type,
            mapWithOperand(operand.reference),
            CodeGenerator::Triples::Operand({ NULLREF, nullptr })
        });
        result.reference.type = TRIPLE;
    }
    else
        result.reference = { NULLREF, nullptr };
    
    result.expression.assignable = false;
}

void createArithmeticTriple(Metadata& r, const Metadata& o1, const Metadata& o2, const char op)
{
    SemanticAnalyzer::TypeChecker::Expression e1 = { o1.expression.type, *StringPool::get(o1.expression.pid) };
    SemanticAnalyzer::TypeChecker::Expression e2 = { o2.expression.type, *StringPool::get(o2.expression.pid) };
    r.expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

    r.expression.pid = o1.expression.pid;
    StringPool::append(o1.expression.pid, " " + std::string(1, op) + " " + *StringPool::get(o2.expression.pid));

    int codeop;
    switch (op)
    {
    case '+':
        codeop = CODEOP_SUM;
        break;
    case '-':
        codeop = CODEOP_SUB;
        break;
    case '*':
        codeop = CODEOP_MUL;
        break;
    case '/':
        codeop = CODEOP_DIV;
        break;
    default:
        codeop = UNKNOWN;
    }

    if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
    {
        r.reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple ({
            codeop,
            r.expression.type,
            mapWithOperand(o1.reference),
            mapWithOperand(o2.reference)
        });
        r.reference.type = TRIPLE;
    }
    else
        r.reference = { NULLREF, nullptr };
    
    r.expression.assignable = false;
}
