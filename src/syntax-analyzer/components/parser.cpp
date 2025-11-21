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
  YYSYMBOL_INVALID_RWORD = 3,              /* INVALID_RWORD  */
  YYSYMBOL_INVALID_TOKEN = 4,              /* INVALID_TOKEN  */
  YYSYMBOL_WORD_IF = 5,                    /* WORD_IF  */
  YYSYMBOL_WORD_ELSE = 6,                  /* WORD_ELSE  */
  YYSYMBOL_WORD_ENDIF = 7,                 /* WORD_ENDIF  */
  YYSYMBOL_WORD_DO = 8,                    /* WORD_DO  */
  YYSYMBOL_WORD_WHILE = 9,                 /* WORD_WHILE  */
  YYSYMBOL_WORD_RETURN = 10,               /* WORD_RETURN  */
  YYSYMBOL_WORD_PRINT = 11,                /* WORD_PRINT  */
  YYSYMBOL_WORD_TRUNC = 12,                /* WORD_TRUNC  */
  YYSYMBOL_WORD_UINT = 13,                 /* WORD_UINT  */
  YYSYMBOL_WORD_FLOAT = 14,                /* WORD_FLOAT  */
  YYSYMBOL_WORD_CR = 15,                   /* WORD_CR  */
  YYSYMBOL_OP_POINTER = 16,                /* OP_POINTER  */
  YYSYMBOL_OP_EQUAL = 17,                  /* OP_EQUAL  */
  YYSYMBOL_OP_GE = 18,                     /* OP_GE  */
  YYSYMBOL_OP_LE = 19,                     /* OP_LE  */
  YYSYMBOL_OP_ASSIGN = 20,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_NOT_EQUAL = 21,              /* OP_NOT_EQUAL  */
  YYSYMBOL_IDENTIFIER = 22,                /* IDENTIFIER  */
  YYSYMBOL_LITERAL_FLOAT = 23,             /* LITERAL_FLOAT  */
  YYSYMBOL_LITERAL_UINT = 24,              /* LITERAL_UINT  */
  YYSYMBOL_LITERAL_STRING = 25,            /* LITERAL_STRING  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* '='  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_global = 41,                    /* global  */
  YYSYMBOL_global_statement = 42,          /* global_statement  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_unnamed_program_tail = 44,      /* unnamed_program_tail  */
  YYSYMBOL_program_head = 45,              /* program_head  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_program_tail = 47,              /* program_tail  */
  YYSYMBOL_program_statements = 48,        /* program_statements  */
  YYSYMBOL_program_statement = 49,         /* program_statement  */
  YYSYMBOL_declarative_stmt = 50,          /* declarative_stmt  */
  YYSYMBOL_51_3 = 51,                      /* $@3  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_variable_list = 53,             /* variable_list  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_unnamed_function_declaration_middle = 56, /* unnamed_function_declaration_middle  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_unnamed_function_declaration_tail = 58, /* unnamed_function_declaration_tail  */
  YYSYMBOL_function_declaration_middle = 59, /* function_declaration_middle  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_function_declaration_tail = 61, /* function_declaration_tail  */
  YYSYMBOL_formal_parameter_list = 62,     /* formal_parameter_list  */
  YYSYMBOL_63_8 = 63,                      /* $@8  */
  YYSYMBOL_formal_parameter = 64,          /* formal_parameter  */
  YYSYMBOL_parameter_semantics = 65,       /* parameter_semantics  */
  YYSYMBOL_function_body = 66,             /* function_body  */
  YYSYMBOL_return = 67,                    /* return  */
  YYSYMBOL_executable_stmt = 68,           /* executable_stmt  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_assignment_head = 70,           /* assignment_head  */
  YYSYMBOL_assignment_tail = 71,           /* assignment_tail  */
  YYSYMBOL_print = 72,                     /* print  */
  YYSYMBOL_73_9 = 73,                      /* $@9  */
  YYSYMBOL_print_end = 74,                 /* print_end  */
  YYSYMBOL_multiple_assignments = 75,      /* multiple_assignments  */
  YYSYMBOL_assignment_list = 76,           /* assignment_list  */
  YYSYMBOL_77_10 = 77,                     /* $@10  */
  YYSYMBOL_assignment_end = 78,            /* assignment_end  */
  YYSYMBOL_extra_numeric_constants = 79,   /* extra_numeric_constants  */
  YYSYMBOL_80_11 = 80,                     /* $@11  */
  YYSYMBOL_invocation = 81,                /* invocation  */
  YYSYMBOL_function_invocation_head = 82,  /* function_invocation_head  */
  YYSYMBOL_invocation_setup = 83,          /* invocation_setup  */
  YYSYMBOL_function_invocation_tail = 84,  /* function_invocation_tail  */
  YYSYMBOL_real_parameter_list = 85,       /* real_parameter_list  */
  YYSYMBOL_real_parameter_list_setup = 86, /* real_parameter_list_setup  */
  YYSYMBOL_real_parameter = 87,            /* real_parameter  */
  YYSYMBOL_lambda_invocation_head = 88,    /* lambda_invocation_head  */
  YYSYMBOL_89_12 = 89,                     /* $@12  */
  YYSYMBOL_lambda_invocation_middle = 90,  /* lambda_invocation_middle  */
  YYSYMBOL_91_13 = 91,                     /* $@13  */
  YYSYMBOL_92_14 = 92,                     /* $@14  */
  YYSYMBOL_lambda_invocation_tail = 93,    /* lambda_invocation_tail  */
  YYSYMBOL_lambda_real_parameter = 94,     /* lambda_real_parameter  */
  YYSYMBOL_if = 95,                        /* if  */
  YYSYMBOL_if_head = 96,                   /* if_head  */
  YYSYMBOL_condition_body_setup = 97,      /* condition_body_setup  */
  YYSYMBOL_condition_setup = 98,           /* condition_setup  */
  YYSYMBOL_then_body_setup = 99,           /* then_body_setup  */
  YYSYMBOL_do_while = 100,                 /* do_while  */
  YYSYMBOL_101_15 = 101,                   /* $@15  */
  YYSYMBOL_do_while_head = 102,            /* do_while_head  */
  YYSYMBOL_do_body = 103,                  /* do_body  */
  YYSYMBOL_104_16 = 104,                   /* $@16  */
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
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  264
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  402

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
      29,    31,    37,    35,    30,    36,    39,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      34,    32,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   127,   128,   132,   136,   140,   142,   141,
     150,   154,   162,   166,   170,   181,   180,   196,   201,   206,
     216,   217,   221,   225,   229,   236,   243,   250,   258,   268,
     272,   277,   283,   282,   292,   291,   307,   311,   316,   315,
     323,   331,   335,   346,   345,   354,   360,   373,   372,   383,
     394,   409,   410,   412,   411,   419,   425,   431,   439,   444,
     450,   457,   467,   477,   481,   485,   497,   511,   528,   546,
     563,   581,   597,   613,   629,   640,   641,   642,   643,   644,
     645,   646,   652,   675,   684,   701,   708,   721,   734,   747,
     760,   775,   774,   781,   789,   791,   799,   805,   813,   821,
     830,   837,   846,   857,   858,   862,   870,   869,   875,   882,
     891,   895,   905,   906,   908,   907,   917,   918,   923,   924,
     934,   955,   976,   994,  1002,  1012,  1016,  1022,  1032,  1040,
    1078,  1091,  1090,  1103,  1102,  1108,  1107,  1114,  1122,  1133,
    1188,  1189,  1195,  1199,  1206,  1214,  1223,  1248,  1268,  1288,
    1309,  1330,  1338,  1346,  1355,  1376,  1383,  1400,  1417,  1437,
    1444,  1459,  1481,  1486,  1485,  1494,  1505,  1518,  1534,  1543,
    1542,  1554,  1555,  1566,  1570,  1578,  1584,  1588,  1595,  1596,
    1602,  1606,  1613,  1620,  1630,  1639,  1652,  1667,  1674,  1694,
    1717,  1740,  1763,  1775,  1781,  1791,  1800,  1815,  1819,  1827,
    1834,  1845,  1868,  1876,  1883,  1887,  1891,  1895,  1899,  1903,
    1912,  1916,  1928,  1935,  1944,  1948,  1956,  1960,  1968,  1972,
    1976,  1983,  1994,  1998,  2005,  2009,  2013,  2017,  2021,  2025,
    2029,  2033,  2037,  2041,  2049,  2060,  2064,  2068,  2072,  2076,
    2080,  2088,  2096,  2103,  2110,  2119,  2133,  2137,  2144,  2159,
    2163,  2170,  2174,  2181,  2189,  2196,  2212,  2221,  2235,  2239,
    2246,  2251,  2259,  2270,  2277
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
  "\"end of file\"", "error", "\"invalid token\"", "INVALID_RWORD",
  "INVALID_TOKEN", "WORD_IF", "WORD_ELSE", "WORD_ENDIF", "WORD_DO",
  "WORD_WHILE", "WORD_RETURN", "WORD_PRINT", "WORD_TRUNC", "WORD_UINT",
  "WORD_FLOAT", "WORD_CR", "OP_POINTER", "OP_EQUAL", "OP_GE", "OP_LE",
  "OP_ASSIGN", "OP_NOT_EQUAL", "IDENTIFIER", "LITERAL_FLOAT",
  "LITERAL_UINT", "LITERAL_STRING", "'{'", "'}'", "';'", "'('", "','",
  "')'", "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'.'", "$accept",
  "global", "global_statement", "$@1", "unnamed_program_tail",
  "program_head", "$@2", "program_tail", "program_statements",
  "program_statement", "declarative_stmt", "$@3", "$@4", "variable_list",
  "$@5", "type", "unnamed_function_declaration_middle", "$@6",
  "unnamed_function_declaration_tail", "function_declaration_middle",
  "$@7", "function_declaration_tail", "formal_parameter_list", "$@8",
  "formal_parameter", "parameter_semantics", "function_body", "return",
  "executable_stmt", "assignment", "assignment_head", "assignment_tail",
  "print", "$@9", "print_end", "multiple_assignments", "assignment_list",
  "$@10", "assignment_end", "extra_numeric_constants", "$@11",
  "invocation", "function_invocation_head", "invocation_setup",
  "function_invocation_tail", "real_parameter_list",
  "real_parameter_list_setup", "real_parameter", "lambda_invocation_head",
  "$@12", "lambda_invocation_middle", "$@13", "$@14",
  "lambda_invocation_tail", "lambda_real_parameter", "if", "if_head",
  "condition_body_setup", "condition_setup", "then_body_setup", "do_while",
  "$@15", "do_while_head", "do_body", "$@16", "do_while_tail",
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

#define YYPACT_NINF (-315)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-222)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     660,  -315,   -16,   269,  1114,   945,   395,    28,  -315,  -315,
     174,  -315,  -315,   263,   690,  -315,  -315,  -315,   148,  -315,
    -315,  -315,  1058,  -315,  -315,  -315,    16,  1036,    23,  -315,
      62,  -315,  1114,   207,  -315,    47,  1076,     1,  -315,  -315,
    1040,   453,   256,   220,   341,  -315,  -315,   460,  1114,    51,
     958,    75,   500,   685,  -315,    99,   303,  -315,  -315,  -315,
    -315,    41,   971,  -315,    88,    80,   133,   134,  1040,   525,
     156,   296,  -315,   377,   837,   166,  -315,  -315,   188,   191,
    -315,   233,    41,  -315,   557,  -315,  -315,  -315,  -315,   313,
    1058,  -315,   424,  -315,  -315,  -315,  -315,  -315,   219,   210,
     415,  -315,   229,  -315,   232,   531,    41,  -315,  1040,   565,
     112,  -315,    51,  -315,  -315,  -315,  -315,  -315,  -315,    41,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  1114,   984,  -315,
    -315,  -315,   475,   475,   323,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,   471,   491,   433,    99,   287,   585,
     610,   614,   231,  -315,  -315,  1006,  -315,  -315,  1080,  -315,
     540,  -315,  -315,   234,  -315,   253,   264,   374,   864,   271,
     243,   891,  -315,  -315,  -315,   720,  -315,  -315,  -315,   293,
    -315,  -315,   640,  -315,  -315,   244,   229,  -315,  -315,  1058,
    -315,  -315,  -315,   304,  1080,  1080,  -315,   307,    64,  -315,
    -315,   450,  -315,   331,   139,  -315,  -315,  -315,  -315,   508,
     582,  -315,  -315,  -315,  -315,    31,   246,   171,  -315,  -315,
    -315,  -315,   339,  -315,  -315,  -315,    51,  -315,  -315,    51,
    -315,  -315,   123,  -315,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,
     164,  -315,  -315,   189,  -315,  -315,   222,   224,  -315,  -315,
     750,  -315,  -315,  -315,   780,  -315,  -315,  -315,  -315,   640,
    -315,  -315,   338,  -315,   357,  -315,   381,  -315,    41,    41,
    -315,  -315,   239,  -315,  -315,   325,    69,   405,   113,  -315,
    -315,   325,   628,   325,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,   329,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  1122,  -315,   412,
    -315,  -315,   640,  -315,   640,  -315,  -315,   354,  -315,  -315,
     342,  -315,   344,   130,  -315,  -315,  -315,  -315,  -315,   325,
     325,  -315,    22,  -315,  -315,   670,  -315,  1014,  -315,  -315,
     333,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  1039,  -315,  -315,   333,   918,  -315,   240,  -315,
    -315,   355,  -315,   258,  -315,   810,  -315,  -315,   355,   291,
    -315,  -315,  -315,  -315,  -315,  -315,   368,   337,  -315,  -315,
    -315,    41,   392,   399,    25,  -315,  -315,    27,  -315,  -315,
    -315,  -315
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     4,     0,     0,     0,     0,     0,     0,    41,    42,
     263,     8,    10,     0,     0,     2,     7,     5,     0,    80,
       6,    75,     0,    79,    76,    77,     0,     0,     0,    78,
       0,    81,     0,     0,    11,     0,     0,   263,   261,   260,
       0,     0,     0,     0,     0,   250,   252,     0,     0,   218,
       0,     0,     0,     0,   210,   222,   223,   232,   239,   249,
     251,   248,     0,   176,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     1,     3,     0,   263,
      34,     0,    36,    82,     0,   117,   116,   124,   120,   128,
       0,   125,     0,   119,   118,   143,   142,   162,   169,     0,
       0,   263,     0,   103,     0,     0,   106,   144,     0,     0,
       0,   213,     0,   212,   257,   262,   253,   254,   256,   255,
     244,   242,   246,   247,   245,   243,   149,     0,     0,   147,
     159,   161,     0,     0,     0,   200,   199,   202,   204,   206,
     207,   205,   208,   209,     0,     0,     0,   211,     0,     0,
       0,     0,     0,   177,   178,     0,   155,   165,     0,    74,
       0,    70,    73,    69,    93,     0,     0,   221,     0,     0,
       0,     0,    13,     9,    24,     0,    20,    22,    23,     0,
      30,    32,     0,    31,    29,     0,     0,    86,    85,     0,
     123,   127,   130,     0,     0,     0,   102,     0,     0,   264,
     101,     0,   100,     0,     0,   181,   180,   258,   259,     0,
       0,   196,   195,   198,   197,     0,     0,     0,   229,   227,
     228,   226,   153,   151,   145,   215,   219,   214,   217,   220,
     216,   203,   221,   233,   231,   224,   234,   230,   225,   240,
     238,   235,   241,   237,   236,   175,   174,   173,   179,   164,
       0,    68,    71,     0,    72,    91,     0,     0,    19,    16,
       0,   121,    28,    25,     0,    14,    12,    21,   131,     0,
      62,    57,     0,    35,    53,    51,     0,    40,    37,    39,
     126,   129,     0,   170,    83,     0,     0,     0,     0,    97,
      96,     0,     0,     0,   194,   193,   158,   157,   154,   146,
     150,   156,   148,   152,   172,   171,    67,    66,    95,    88,
      87,    90,    89,    18,    17,    27,    26,     0,    33,    53,
      56,    55,     0,    43,     0,    60,    61,     0,   168,   167,
       0,   109,   108,     0,   185,   184,   112,    99,    98,     0,
       0,   107,     0,    94,    92,     0,   132,     0,    47,    52,
       0,    54,    59,    58,   105,   104,   183,   182,   113,   115,
     111,   110,     0,   138,   135,     0,     0,    44,     0,   137,
     133,     0,    48,     0,    64,     0,    46,    45,     0,     0,
     136,    50,    49,    65,    63,   134,     0,     0,   141,   140,
     187,   186,     0,     0,     0,   139,   192,     0,   191,   190,
     189,   188
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -315,  -315,   371,  -315,  -315,    35,  -315,  -315,  -161,  -173,
      71,  -315,  -315,  -315,  -315,    14,  -315,  -315,  -315,  -315,
    -315,  -315,   157,  -315,  -112,  -315,    84,  -315,    11,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,  -126,  -315,  -315,  -315,
    -315,  -315,     5,  -315,  -315,  -315,  -315,   -68,    36,  -315,
    -315,  -315,  -315,    86,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,   283,    29,  -314,   -67,  -315,
    -315,  -315,   -33,     3,   418,  -315,    33,  -315,   -25,   427,
    -315,    -3,     2,    82,  -180,  -104,   -92,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    14,    15,    74,   173,   174,   168,   259,   175,   176,
     177,   269,   182,    81,   186,    18,   273,   350,   367,   318,
     365,   372,   274,   324,   275,   276,   368,    19,   178,    21,
      22,    83,    23,   308,   344,    24,   105,   209,   341,   292,
     340,    25,    45,    27,    88,    89,    90,    91,    46,   317,
     346,   378,   371,   380,   387,    29,    30,    47,    48,   130,
      31,    66,    32,    97,   195,   249,    64,   155,   204,   205,
     389,   390,    49,   250,    51,   146,    52,    53,    54,    55,
      56,   121,    57,    58,   206,    59,    60,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   207,   267,   347,    33,    26,    50,   260,   112,    26,
     264,    20,    34,   208,    33,    63,   113,    85,    82,    26,
     112,   288,   191,   360,    93,    20,   398,    75,   400,    70,
      73,   362,    33,   106,   296,    16,    28,    26,   297,    69,
      28,   125,   119,    63,    86,   122,   122,   117,    33,    16,
      28,    94,   361,    26,    75,    84,   399,    71,   401,    63,
      92,    98,    33,    95,   104,   285,   104,    26,    28,   109,
     331,    17,   286,   154,    33,   107,   135,   131,   118,    26,
     104,   201,    75,   293,    28,    17,   101,   267,   132,   133,
      96,   267,    38,    39,   102,   156,   103,   207,    28,   218,
     220,   160,   198,   104,   167,   203,   136,   333,   157,   208,
      28,   226,   229,   213,   334,   234,   237,   240,   243,   227,
     230,   280,    75,    92,  -201,   123,   123,    33,    33,   219,
     221,   356,    26,    26,   122,   122,   148,   149,    63,    63,
     289,   210,   158,   214,   335,   235,   238,   241,   244,    78,
     122,   122,   122,   122,  -201,    33,   215,   217,   144,   145,
      26,   357,   159,    28,    28,   304,   248,   290,    33,   291,
      79,    33,   300,    26,   301,    33,    26,    80,   302,   232,
      26,   207,   207,   207,   164,   278,   279,   207,   179,   207,
     306,    28,   305,   208,   208,   208,   272,   282,   106,   208,
      72,   208,   267,    73,    28,   375,   288,    28,    99,   106,
     349,    28,   351,   333,   123,   123,   180,   307,   330,   332,
     181,   120,    92,   309,   336,   311,   342,   100,   194,   101,
     123,   123,   123,   123,   183,   207,   207,   102,   196,   103,
     328,   376,    37,    38,    39,   277,   104,   208,   208,    13,
     310,   101,   312,   298,   199,   -38,    42,   114,   245,   381,
      33,   184,   254,   185,    33,    26,   101,   329,   377,    26,
      35,   262,   358,   359,   299,   207,     8,     9,    37,   115,
     116,    36,   207,   272,   255,    13,   382,   208,   233,   207,
     327,    37,    38,    39,   208,   256,    28,   165,    40,    36,
      28,   208,   261,   386,    41,    42,    43,    44,    36,    37,
      38,    39,   388,   101,    38,    39,    13,    33,    37,    38,
      39,   166,    26,    42,   268,    13,   281,   203,   154,   222,
     223,    41,    42,    43,    44,   284,   272,   201,   272,   320,
     150,   151,   124,   189,   190,    33,   303,    33,    38,    39,
      26,   224,    26,    28,   115,   352,   154,   343,   248,   366,
     321,   203,    33,    37,    38,    39,    33,    26,   395,   392,
      13,    26,   354,   248,   355,    33,   353,    42,   169,   391,
      26,    28,   325,    28,   379,    77,   394,   322,   323,  -122,
     101,    38,    39,   397,     8,     9,    67,   393,    28,  -122,
    -122,  -122,    28,   326,   203,   257,  -122,    36,  -122,   144,
     145,    28,  -122,  -122,  -122,  -122,   197,    37,    38,    39,
     396,   101,    38,    39,    68,   192,   319,   -84,    38,    39,
      41,    42,    43,    44,   231,   203,  -221,   -84,   -84,   -84,
     193,   203,   322,   348,   -84,    36,  -221,  -221,  -221,   373,
     -84,   -84,   -84,   -84,   111,    37,    38,    39,   110,   144,
     145,   126,    13,   127,   385,    36,   128,   129,    41,    42,
      43,    44,   225,    38,    39,    37,    38,    39,   283,   287,
     147,     0,    13,    36,     0,     0,   203,    36,     0,    42,
      43,    44,   228,    37,    38,    39,     0,    37,    38,    39,
      13,   137,     0,    36,    13,     0,     0,    42,    43,    44,
       0,    42,  -221,    37,    38,    39,     0,   138,   139,   140,
      13,   141,  -221,  -221,  -221,     0,   161,    42,    43,    44,
     101,     0,   200,   142,   143,   144,   145,  -221,   102,     0,
     103,   251,     0,   201,     0,     0,     0,  -221,  -221,  -221,
       0,     0,  -221,   162,    38,    39,   163,     0,   187,   202,
     144,   145,  -221,  -221,  -221,     0,   211,   203,   252,  -221,
       0,   253,     0,     0,     0,   144,   145,  -221,     0,  -221,
    -221,  -221,     0,   294,     0,   188,   236,  -221,  -221,  -221,
       0,     0,   144,   145,  -221,     0,   212,    36,     0,     0,
     144,   145,     0,     0,  -221,  -221,  -221,    37,    38,    39,
       0,   239,     0,   295,    13,   242,     0,   144,   145,     0,
       0,    42,    36,     0,     0,     0,    36,     0,     0,   337,
       0,     0,    37,    38,    39,     0,    37,    38,    39,    13,
    -114,     0,     0,    13,     0,     0,    42,     0,     0,     0,
      42,  -114,  -114,     8,     9,   270,   338,     0,   339,     0,
       1,     2,   271,     0,  -114,     3,     4,     0,     5,     0,
       6,     7,     0,     8,     9,     3,     4,     0,     5,     0,
       6,     7,    10,     0,     0,     0,    11,    12,     0,    13,
      76,     2,    37,     0,     0,     3,     4,    36,     5,    13,
       6,     7,     0,     8,     9,     0,     0,    37,    38,    39,
       0,     0,    10,     0,     0,     0,    11,    12,     0,    13,
     265,   170,     0,     0,     0,     3,     4,     0,     5,     0,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   171,   266,     0,    13,
     313,   170,     0,     0,     0,     3,     4,     0,     5,     0,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   171,   314,     0,    13,
     315,   170,     0,     0,     0,     3,     4,     0,     5,     0,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   171,   316,     0,    13,
     383,   170,     0,     0,     0,     3,     4,     0,     5,     0,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   171,   384,   170,    13,
       0,     0,     3,     4,     0,     5,     0,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,   171,   172,   170,    13,     0,     0,     3,
       4,     0,     5,     0,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
     171,   258,   170,    13,     0,     0,     3,     4,     0,     5,
       0,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,   171,   263,   170,
      13,     0,     0,     3,     4,     0,     5,     0,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,   171,   374,    65,    13,     0,     0,
    -166,  -166,     0,  -166,  -163,  -166,  -166,     0,     0,   134,
       0,     0,     0,  -160,  -160,     0,  -160,  -166,  -160,  -160,
       0,  -166,   152,     0,  -166,     0,     3,     4,     0,     5,
    -160,     6,     7,     0,  -160,   216,     0,  -160,     0,     3,
       4,     0,     5,    37,     6,     7,     0,     0,   153,     0,
      13,     0,     0,     0,     0,     0,    37,   246,     0,     0,
      62,     3,     4,    13,     5,   363,     6,     7,     0,     3,
       4,     0,     5,     0,     6,     7,     0,     0,    37,     0,
       0,     0,     0,   247,     0,    13,    37,     0,     0,     0,
     369,   364,     0,    13,     3,     4,     0,     5,    36,     6,
       7,     0,    36,     8,     9,     0,     0,     0,    37,    38,
      39,    37,    37,    38,    39,    13,   370,    87,    13,    13,
      36,    41,    42,    43,    44,    41,    42,    43,    44,     0,
      37,    38,    39,     0,     0,     0,     0,    13,    36,     0,
       0,     0,    36,    41,    42,    43,    44,     0,    37,    38,
      39,     0,    37,    38,    39,   108,     0,     0,     0,    40,
       0,    41,    42,    43,    44,    41,    42,    43,    44,     3,
       4,     0,     5,     0,     6,     7,     0,     3,     4,     0,
       5,     0,     6,     7,     0,     0,    37,     0,     0,     0,
      62,     0,     0,    13,    37,     0,     0,     0,   345,     0,
       0,    13
};

static const yytype_int16 yycheck[] =
{
       0,   105,   175,   317,     4,     0,     3,   168,    41,     4,
     171,     0,    28,   105,    14,     4,    41,     1,    18,    14,
      53,   201,    90,     1,     1,    14,     1,    13,     1,     1,
      29,   345,    32,    33,     3,     0,     0,    32,     7,     6,
       4,    44,    42,    32,    28,    43,    44,    42,    48,    14,
      14,    28,    30,    48,    40,    22,    31,    29,    31,    48,
      27,    32,    62,     1,    39,     1,    39,    62,    32,    36,
       1,     0,   198,    62,    74,    28,     1,    48,    42,    74,
      39,    12,    68,   209,    48,    14,    22,   260,    37,    38,
      28,   264,    23,    24,    30,     7,    32,   201,    62,   132,
     133,    68,   102,    39,    71,    36,    31,   287,    28,   201,
      74,   144,   145,     1,     1,   148,   149,   150,   151,   144,
     145,   189,   108,    90,     1,    43,    44,   127,   128,   132,
     133,     1,   127,   128,   132,   133,    37,    38,   127,   128,
       1,   108,     9,    31,    31,   148,   149,   150,   151,     1,
     148,   149,   150,   151,    31,   155,   127,   128,    35,    36,
     155,    31,    28,   127,   128,     1,   155,    28,   168,    30,
      22,   171,     1,   168,     3,   175,   171,    29,     7,   146,
     175,   285,   286,   287,    28,   185,   186,   291,    22,   293,
       1,   155,    28,   285,   286,   287,   182,   194,   198,   291,
      26,   293,   375,    29,   168,   366,   386,   171,     1,   209,
     322,   175,   324,   393,   132,   133,    28,    28,   285,   286,
      29,     1,   189,     1,   291,     1,   293,    20,     9,    22,
     148,   149,   150,   151,     1,   339,   340,    30,    28,    32,
       1,     1,    22,    23,    24,     1,    39,   339,   340,    29,
      28,    22,    28,     7,    22,    22,    36,     1,    27,     1,
     260,    28,    28,    30,   264,   260,    22,    28,    28,   264,
       1,    28,   339,   340,    28,   379,    13,    14,    22,    23,
      24,    12,   386,   269,    31,    29,    28,   379,     1,   393,
     276,    22,    23,    24,   386,    31,   260,     1,    29,    12,
     264,   393,    31,    12,    35,    36,    37,    38,    12,    22,
      23,    24,   379,    22,    23,    24,    29,   317,    22,    23,
      24,    25,   317,    36,    31,    29,    22,    36,   317,     6,
       7,    35,    36,    37,    38,    28,   322,    12,   324,     1,
      37,    38,     1,    30,    31,   345,     7,   347,    23,    24,
     345,    28,   347,   317,    23,     1,   345,    28,   347,    26,
      22,    36,   362,    22,    23,    24,   366,   362,    31,     1,
      29,   366,    30,   362,    30,   375,    22,    36,     1,   379,
     375,   345,     1,   347,    29,    14,   386,    30,    31,    12,
      22,    23,    24,   393,    13,    14,     1,    29,   362,    22,
      23,    24,   366,    22,    36,    31,    29,    12,    31,    35,
      36,   375,    35,    36,    37,    38,     1,    22,    23,    24,
      28,    22,    23,    24,    29,     1,   269,    12,    23,    24,
      35,    36,    37,    38,     1,    36,    12,    22,    23,    24,
      16,    36,    30,    31,    29,    12,    22,    23,    24,   365,
      35,    36,    37,    38,     1,    22,    23,    24,    40,    35,
      36,     1,    29,     3,   378,    12,     6,     7,    35,    36,
      37,    38,     1,    23,    24,    22,    23,    24,   195,    29,
      53,    -1,    29,    12,    -1,    -1,    36,    12,    -1,    36,
      37,    38,     1,    22,    23,    24,    -1,    22,    23,    24,
      29,     1,    -1,    12,    29,    -1,    -1,    36,    37,    38,
      -1,    36,    12,    22,    23,    24,    -1,    17,    18,    19,
      29,    21,    22,    23,    24,    -1,     1,    36,    37,    38,
      22,    -1,     1,    33,    34,    35,    36,    12,    30,    -1,
      32,     1,    -1,    12,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    12,    28,    23,    24,    31,    -1,     1,    28,
      35,    36,    22,    23,    24,    -1,     1,    36,    28,    12,
      -1,    31,    -1,    -1,    -1,    35,    36,    12,    -1,    22,
      23,    24,    -1,     1,    -1,    28,     1,    22,    23,    24,
      -1,    -1,    35,    36,    12,    -1,    31,    12,    -1,    -1,
      35,    36,    -1,    -1,    22,    23,    24,    22,    23,    24,
      -1,     1,    -1,    31,    29,     1,    -1,    35,    36,    -1,
      -1,    36,    12,    -1,    -1,    -1,    12,    -1,    -1,     1,
      -1,    -1,    22,    23,    24,    -1,    22,    23,    24,    29,
      12,    -1,    -1,    29,    -1,    -1,    36,    -1,    -1,    -1,
      36,    23,    24,    13,    14,    15,    28,    -1,    30,    -1,
       0,     1,    22,    -1,    36,     5,     6,    -1,     8,    -1,
      10,    11,    -1,    13,    14,     5,     6,    -1,     8,    -1,
      10,    11,    22,    -1,    -1,    -1,    26,    27,    -1,    29,
       0,     1,    22,    -1,    -1,     5,     6,    12,     8,    29,
      10,    11,    -1,    13,    14,    -1,    -1,    22,    23,    24,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    29,
       0,     1,    -1,    -1,    -1,     5,     6,    -1,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    29,
       0,     1,    -1,    -1,    -1,     5,     6,    -1,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    29,
       0,     1,    -1,    -1,    -1,     5,     6,    -1,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    29,
       0,     1,    -1,    -1,    -1,     5,     6,    -1,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,     1,    29,
      -1,    -1,     5,     6,    -1,     8,    -1,    10,    11,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,     1,    29,    -1,    -1,     5,
       6,    -1,     8,    -1,    10,    11,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,     1,    29,    -1,    -1,     5,     6,    -1,     8,
      -1,    10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,     1,
      29,    -1,    -1,     5,     6,    -1,     8,    -1,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,     1,    29,    -1,    -1,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,     1,
      -1,    -1,    -1,     5,     6,    -1,     8,    22,    10,    11,
      -1,    26,     1,    -1,    29,    -1,     5,     6,    -1,     8,
      22,    10,    11,    -1,    26,     1,    -1,    29,    -1,     5,
       6,    -1,     8,    22,    10,    11,    -1,    -1,    27,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    22,     1,    -1,    -1,
      26,     5,     6,    29,     8,     1,    10,    11,    -1,     5,
       6,    -1,     8,    -1,    10,    11,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    27,    -1,    29,    22,    -1,    -1,    -1,
       1,    27,    -1,    29,     5,     6,    -1,     8,    12,    10,
      11,    -1,    12,    13,    14,    -1,    -1,    -1,    22,    23,
      24,    22,    22,    23,    24,    29,    27,    31,    29,    29,
      12,    35,    36,    37,    38,    35,    36,    37,    38,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    29,    12,    -1,
      -1,    -1,    12,    35,    36,    37,    38,    -1,    22,    23,
      24,    -1,    22,    23,    24,    29,    -1,    -1,    -1,    29,
      -1,    35,    36,    37,    38,    35,    36,    37,    38,     5,
       6,    -1,     8,    -1,    10,    11,    -1,     5,     6,    -1,
       8,    -1,    10,    11,    -1,    -1,    22,    -1,    -1,    -1,
      26,    -1,    -1,    29,    22,    -1,    -1,    -1,    26,    -1,
      -1,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     0,     1,     5,     6,     8,    10,    11,    13,    14,
      22,    26,    27,    29,    41,    42,    45,    50,    55,    67,
      68,    69,    70,    72,    75,    81,    82,    83,    88,    95,
      96,   100,   102,   127,    28,     1,    12,    22,    23,    24,
      29,    35,    36,    37,    38,    82,    88,    97,    98,   112,
     113,   114,   116,   117,   118,   119,   120,   122,   123,   125,
     126,   127,    26,    68,   106,     1,   101,     1,    29,   116,
       1,    29,    26,    29,    43,    55,     0,    42,     1,    22,
      29,    53,   127,    71,   116,     1,    28,    31,    84,    85,
      86,    87,   116,     1,    28,     1,    28,   103,   106,     1,
      20,    22,    30,    32,    39,    76,   127,    28,    29,   116,
     114,     1,   112,   118,     1,    23,    24,    82,    88,   127,
       1,   121,   122,   123,     1,   121,     1,     3,     6,     7,
      99,   106,    37,    38,     1,     1,    31,     1,    17,    18,
      19,    21,    33,    34,    35,    36,   115,   119,    37,    38,
      37,    38,     1,    27,    68,   107,     7,    28,     9,    28,
     116,     1,    28,    31,    28,     1,    25,   116,    46,     1,
       1,    26,    27,    44,    45,    48,    49,    50,    68,    22,
      28,    29,    52,     1,    28,    30,    54,     1,    28,    30,
      31,    87,     1,    16,     9,   104,    28,     1,   127,    22,
       1,    12,    28,    36,   108,   109,   124,   125,   126,    77,
     116,     1,    31,     1,    31,   106,     1,   106,   112,   121,
     112,   121,     6,     7,    28,     1,   112,   118,     1,   112,
     118,     1,   116,     1,   112,   121,     1,   112,   121,     1,
     112,   121,     1,   112,   121,    27,     1,    27,    68,   105,
     113,     1,    28,    31,    28,    31,    31,    31,    27,    47,
      48,    31,    28,    27,    48,     0,    27,    49,    31,    51,
      15,    22,    55,    56,    62,    64,    65,     1,   127,   127,
      87,    22,   113,   105,    28,     1,    76,    29,   124,     1,
      28,    30,    79,    76,     1,    31,     3,     7,     7,    28,
       1,     3,     7,     7,     1,    28,     1,    28,    73,     1,
      28,     1,    28,     0,    27,     0,    27,    89,    59,    62,
       1,    22,    30,    31,    63,     1,    22,    55,     1,    28,
     108,     1,   108,   124,     1,    31,   108,     1,    28,    30,
      80,    78,   108,    28,    74,    26,    90,   107,    31,    64,
      57,    64,     1,    22,    30,    30,     1,    31,   108,   108,
       1,    30,   107,     1,    27,    60,    26,    58,    66,     1,
      27,    92,    61,    66,    27,    48,     1,    28,    91,    29,
      93,     1,    28,     0,    27,    93,    12,    94,   108,   110,
     111,   127,     1,    29,   127,    31,    28,   127,     1,    31,
       1,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    41,    42,    42,    42,    43,    42,
      42,    42,    44,    44,    44,    46,    45,    47,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    49,    50,
      50,    50,    51,    50,    52,    50,    53,    53,    54,    53,
      53,    55,    55,    57,    56,    58,    58,    60,    59,    61,
      61,    62,    62,    63,    62,    64,    64,    64,    64,    64,
      64,    64,    65,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    71,    71,    72,    72,    72,
      72,    73,    72,    72,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    76,    76,    76,    77,    76,    76,    76,
      78,    78,    79,    79,    80,    79,    81,    81,    81,    81,
      82,    82,    83,    84,    84,    85,    85,    85,    86,    87,
      87,    89,    88,    91,    90,    92,    90,    90,    90,    93,
      94,    94,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      98,    99,   100,   101,   100,   100,   102,   103,   103,   104,
     103,   105,   105,   106,   106,   106,   106,   106,   107,   107,
     108,   108,   109,   109,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   112,   112,   112,   112,   113,   113,   113,
     113,   114,   114,   114,   115,   115,   115,   115,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     122,   123,   123,   123,   123,   123,   123,   123,   124,   124,
     125,   125,   126,   127,   127
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
       2,     0,     6,     0,     5,     0,     4,     3,     2,     3,
       1,     1,     2,     2,     3,     4,     5,     3,     5,     3,
       5,     4,     5,     4,     5,     3,     5,     5,     5,     2,
       1,     1,     2,     0,     4,     3,     1,     4,     4,     0,
       3,     2,     2,     3,     3,     3,     1,     2,     1,     2,
       1,     1,     4,     4,     3,     3,     1,     1,     4,     4,
       3,     3,     3,     4,     4,     3,     3,     3,     3,     2,
       2,     3,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     3,     3,     3,     1,     3,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
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
  case 5: /* global_statement: declarative_stmt  */
#line 133 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1682 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 137 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1690 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 8: /* $@1: %empty  */
#line 142 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::addInvalidScope();
        SemanticActions::announceSpecificError(MISSING_PROGRAM_NAME);

        SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration("");

    }
#line 1702 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '}'  */
#line 151 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1710 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: error ';'  */
#line 155 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1719 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* unnamed_program_tail: program_statements '}'  */
#line 163 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1727 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* unnamed_program_tail: '}'  */
#line 167 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1735 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* unnamed_program_tail: program_statements $end  */
#line 171 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1744 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 15: /* $@2: %empty  */
#line 181 "include/syntax-analyzer/components/yacc.y"
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
#line 1760 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 17: /* program_tail: program_statements '}'  */
#line 197 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1769 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 18: /* program_tail: program_statements $end  */
#line 202 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticAnalyzer::removeScope();
    }
#line 1778 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 19: /* program_tail: '}'  */
#line 207 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1787 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statements: program_statement  */
#line 216 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 1793 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statements: program_statements program_statement  */
#line 217 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 1799 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: declarative_stmt  */
#line 222 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 1807 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* program_statement: executable_stmt  */
#line 226 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 1815 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* program_statement: program_head  */
#line 230 "include/syntax-analyzer/components/yacc.y"
    {
       (yyval.returnable) = false;

       SemanticActions::announceSpecificError(INVALID_PROGRAM_NESTING);

    }
#line 1826 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* program_statement: '{' '}'  */
#line 237 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1837 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* program_statement: '{' program_statements '}'  */
#line 244 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1848 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* program_statement: '{' program_statements $end  */
#line 251 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1860 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* program_statement: error ';'  */
#line 259 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;

    }
#line 1869 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type variable_list ';'  */
#line 269 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("VARIABLE DECLARATION");
    }
#line 1877 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* declarative_stmt: type error ';'  */
#line 273 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1886 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 31: /* declarative_stmt: type variable_list error  */
#line 278 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1895 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* $@3: %empty  */
#line 283 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction (
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, (yyvsp[-1].sref)->symbol})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionName((yyvsp[-1].sref)->symbol);

    }
#line 1907 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 34: /* $@4: %empty  */
#line 292 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction(
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, "...()"})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionWithoutName();

        SemanticActions::announceSpecificError(MISSING_FUNCTION_NAME);

    }
#line 1921 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 36: /* variable_list: variable  */
#line 308 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1929 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* variable_list: variable_list ',' variable  */
#line 312 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1937 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 38: /* $@5: %empty  */
#line 316 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 1945 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 39: /* variable_list: variable_list $@5 variable  */
#line 320 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1953 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* variable_list: variable_list ',' error  */
#line 324 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1962 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* type: WORD_UINT  */
#line 332 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UINT;
    }
#line 1970 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* type: WORD_FLOAT  */
#line 336 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = FLOAT;
        SemanticActions::announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1979 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* $@6: %empty  */
#line 346 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();

    }
#line 1988 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* unnamed_function_declaration_tail: function_body ';'  */
#line 355 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

    }
#line 1998 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* unnamed_function_declaration_tail: function_body error  */
#line 361 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2011 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* $@7: %empty  */
#line 373 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
        if (entry != nullptr)
            CodeGenerator::addIntermediateCodeBlock(entry);

    }
#line 2022 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 49: /* function_declaration_tail: function_body ';'  */
#line 384 "include/syntax-analyzer/components/yacc.y"
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn((yyvsp[-1].returnable));
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::logStructure("FUNCTION DECLARATION");

    }
#line 2037 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 50: /* function_declaration_tail: function_body error  */
#line 395 "include/syntax-analyzer/components/yacc.y"
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn((yyvsp[-1].returnable));
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2053 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 53: /* $@8: %empty  */
#line 412 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2061 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* formal_parameter: type IDENTIFIER  */
#line 420 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2071 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 56: /* formal_parameter: type error  */
#line 426 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2081 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* formal_parameter: IDENTIFIER  */
#line 432 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2093 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* formal_parameter: parameter_semantics type IDENTIFIER  */
#line 440 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2102 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* formal_parameter: parameter_semantics type error  */
#line 445 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2112 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* formal_parameter: parameter_semantics error  */
#line 451 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        SemanticActions::announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;

    }
#line 2123 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 458 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2134 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* parameter_semantics: WORD_CR  */
#line 468 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CR);

    }
#line 2143 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* function_body: '{' program_statements '}'  */
#line 478 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 2151 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* function_body: '{' '}'  */
#line 482 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 2159 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 65: /* function_body: '{' program_statements $end  */
#line 486 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    }
#line 2170 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 66: /* return: WORD_RETURN '(' expression ')' ';'  */
#line 498 "include/syntax-analyzer/components/yacc.y"
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
#line 2188 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 67: /* return: WORD_RETURN '(' expression ')' error  */
#line 512 "include/syntax-analyzer/components/yacc.y"
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
#line 2209 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 68: /* return: WORD_RETURN '(' expression error  */
#line 529 "include/syntax-analyzer/components/yacc.y"
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
#line 2231 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 69: /* return: WORD_RETURN expression ')'  */
#line 547 "include/syntax-analyzer/components/yacc.y"
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
#line 2252 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 70: /* return: WORD_RETURN expression error  */
#line 564 "include/syntax-analyzer/components/yacc.y"
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
#line 2274 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 71: /* return: WORD_RETURN '(' expression ';'  */
#line 582 "include/syntax-analyzer/components/yacc.y"
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
#line 2294 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 72: /* return: WORD_RETURN expression ')' ';'  */
#line 598 "include/syntax-analyzer/components/yacc.y"
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
#line 2314 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 73: /* return: WORD_RETURN expression ';'  */
#line 614 "include/syntax-analyzer/components/yacc.y"
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
#line 2334 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 74: /* return: WORD_RETURN error ';'  */
#line 630 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(RETURN_SYNTAX_ERROR);
        yyerrok;

    }
#line 2344 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* executable_stmt: assignment  */
#line 640 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2350 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* executable_stmt: multiple_assignments  */
#line 641 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2356 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 77: /* executable_stmt: invocation  */
#line 642 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2362 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 78: /* executable_stmt: if  */
#line 643 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2368 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 79: /* executable_stmt: print  */
#line 644 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2374 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 80: /* executable_stmt: return  */
#line 645 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = true;  }
#line 2380 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* executable_stmt: do_while  */
#line 646 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2386 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 82: /* assignment: assignment_head assignment_tail  */
#line 653 "include/syntax-analyzer/components/yacc.y"
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
#line 2413 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* assignment: variable OP_ASSIGN error ';'  */
#line 676 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2423 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 84: /* assignment_head: variable OP_ASSIGN  */
#line 685 "include/syntax-analyzer/components/yacc.y"
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
#line 2441 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 85: /* assignment_tail: expression ';'  */
#line 702 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::logStructure("ASSIGNMENT");

    }
#line 2452 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 86: /* assignment_tail: expression error  */
#line 709 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2464 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* print: WORD_PRINT '(' LITERAL_STRING ')' ';'  */
#line 722 "include/syntax-analyzer/components/yacc.y"
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
#line 2481 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 88: /* print: WORD_PRINT '(' LITERAL_STRING ')' error  */
#line 735 "include/syntax-analyzer/components/yacc.y"
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
#line 2498 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 89: /* print: WORD_PRINT '(' expression ')' ';'  */
#line 748 "include/syntax-analyzer/components/yacc.y"
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
#line 2515 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 90: /* print: WORD_PRINT '(' expression ')' error  */
#line 761 "include/syntax-analyzer/components/yacc.y"
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
#line 2533 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 91: /* $@9: %empty  */
#line 775 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;

    }
#line 2543 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 93: /* print: WORD_PRINT error ';'  */
#line 782 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(PRINT_SYNTAX_ERROR);
        yyerrok;
    }
#line 2552 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* print_end: %empty  */
#line 791 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
    }
#line 2560 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* multiple_assignments: variable assignment_list opt_trunc_constant ';'  */
#line 800 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2570 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* multiple_assignments: variable assignment_list opt_trunc_constant error  */
#line 806 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2582 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 98: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 814 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2594 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 99: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 822 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2607 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 100: /* multiple_assignments: variable assignment_list ';'  */
#line 831 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::announceSpecificError(MISSING_RIGHT_SIDE_VALUES);

    }
#line 2618 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* multiple_assignments: variable assignment_list error  */
#line 838 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2631 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* multiple_assignments: variable error ';'  */
#line 847 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;

    }
#line 2643 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 104: /* assignment_list: ',' variable assignment_list opt_trunc_constant ','  */
#line 859 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2651 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 105: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 863 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_EQUALS);

    }
#line 2662 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 106: /* $@10: %empty  */
#line 870 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_COMMA);

    }
#line 2671 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 876 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[0].metadata));

        SemanticActions::announceSpecificError(MISSING_COMMA);

    }
#line 2682 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* assignment_list: ',' variable assignment_list error  */
#line 883 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2692 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* assignment_end: opt_trunc_constant ','  */
#line 892 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2700 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* assignment_end: opt_trunc_constant error  */
#line 896 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 2711 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 114: /* $@11: %empty  */
#line 908 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2719 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 117: /* invocation: function_invocation_head error  */
#line 919 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2728 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* invocation: lambda_invocation_head error  */
#line 925 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2737 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 120: /* function_invocation_head: invocation_setup function_invocation_tail  */
#line 935 "include/syntax-analyzer/components/yacc.y"
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
#line 2762 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 121: /* function_invocation_head: IDENTIFIER '(' error ')'  */
#line 956 "include/syntax-analyzer/components/yacc.y"
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
#line 2784 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 122: /* invocation_setup: IDENTIFIER '('  */
#line 977 "include/syntax-analyzer/components/yacc.y"
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
#line 2803 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* function_invocation_tail: real_parameter_list ')'  */
#line 995 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, ")");
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
    }
#line 2815 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 124: /* function_invocation_tail: ')'  */
#line 1003 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = { UNKNOWN, StringPool::create(")") };

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
        SemanticActions::announceSpecificError(MISSING_ARGUMENT);
    }
#line 2826 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 125: /* real_parameter_list: real_parameter  */
#line 1013 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 2834 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* real_parameter_list: real_parameter_list ',' real_parameter  */
#line 1017 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].metadata).expression.pid, ", " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
    }
#line 2844 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* real_parameter_list: real_parameter_list_setup real_parameter  */
#line 1023 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

    }
#line 2855 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* real_parameter_list_setup: real_parameter_list  */
#line 1033 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2864 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 129: /* real_parameter: expression OP_POINTER IDENTIFIER  */
#line 1041 "include/syntax-analyzer/components/yacc.y"
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
#line 2906 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* real_parameter: expression error  */
#line 1079 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2917 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 131: /* $@12: %empty  */
#line 1091 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclaration((yyvsp[-1].sref)->symbol);
        CodeGenerator::addIntermediateCodeBlock (
              SemanticAnalyzer::CHK_LAMBDAS.getLambda().function
        );

    }
#line 2929 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* $@13: %empty  */
#line 1103 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 2937 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 135: /* $@14: %empty  */
#line 1108 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);

    }
#line 2947 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 137: /* lambda_invocation_middle: '{' executable_statements error  */
#line 1115 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 2959 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* lambda_invocation_middle: executable_statements error  */
#line 1123 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_BOTH_BRACKETS);
        yyerrok;

    }
#line 2971 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 139: /* lambda_invocation_tail: '(' lambda_real_parameter ')'  */
#line 1134 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("LAMBDA");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_RET,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            });

            CodeGenerator::notifyEndOfBlock();

            SemanticAnalyzer::TypeChecker::Expression e1, e2;
            SemanticAnalyzer::LambdaChecker::Lambda l = SemanticAnalyzer::CHK_LAMBDAS.getLambda();

            CodeGenerator::Triples::Operand o1;
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
#line 3027 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 140: /* lambda_real_parameter: opt_trunc_variable  */
#line 1188 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3033 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* lambda_real_parameter: opt_trunc_constant  */
#line 1189 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3039 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 142: /* if: if_head ';'  */
#line 1196 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3047 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* if: if_head error  */
#line 1200 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 3058 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* if: WORD_IF error ';'  */
#line 1207 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;

    }
#line 3070 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* if: WORD_IF condition error ';'  */
#line 1215 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3083 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 146: /* if: WORD_IF condition_body_setup WORD_ELSE error ';'  */
#line 1224 "include/syntax-analyzer/components/yacc.y"
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
#line 3109 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 147: /* if_head: WORD_IF condition_body_setup WORD_ENDIF  */
#line 1249 "include/syntax-analyzer/components/yacc.y"
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

        SemanticActions::logStructure("WORD_IF");

    }
#line 3133 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 148: /* if_head: WORD_IF condition_body_setup WORD_ELSE executable_body WORD_ENDIF  */
#line 1269 "include/syntax-analyzer/components/yacc.y"
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

        SemanticActions::logStructure("WORD_IF-WORD_ELSE");

    }
#line 3157 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* if_head: WORD_IF condition_body_setup error  */
#line 1289 "include/syntax-analyzer/components/yacc.y"
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
#line 3182 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 150: /* if_head: WORD_IF condition_body_setup WORD_ELSE executable_body error  */
#line 1310 "include/syntax-analyzer/components/yacc.y"
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
#line 3207 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* if_head: WORD_IF condition error WORD_ENDIF  */
#line 1331 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3219 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 152: /* if_head: WORD_IF condition error WORD_ELSE WORD_ENDIF  */
#line 1339 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3231 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 153: /* if_head: WORD_IF condition error WORD_ELSE  */
#line 1347 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3244 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 154: /* if_head: WORD_IF condition_body_setup WORD_ELSE error WORD_ENDIF  */
#line 1356 "include/syntax-analyzer/components/yacc.y"
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
        yyerrok;

    }
#line 3269 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 155: /* if_head: WORD_ELSE executable_body WORD_ENDIF  */
#line 1377 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_IF_STATEMENT);

    }
#line 3280 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* if_head: WORD_IF condition_body_setup WORD_ELSE executable_body INVALID_RWORD  */
#line 1384 "include/syntax-analyzer/components/yacc.y"
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
    }
#line 3301 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 157: /* if_head: WORD_IF condition_body_setup INVALID_RWORD executable_body WORD_ENDIF  */
#line 1401 "include/syntax-analyzer/components/yacc.y"
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
    }
#line 3322 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* if_head: WORD_IF condition_body_setup INVALID_RWORD executable_body INVALID_RWORD  */
#line 1418 "include/syntax-analyzer/components/yacc.y"
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
    }
#line 3343 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 159: /* condition_body_setup: condition_setup then_body_setup  */
#line 1438 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3351 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* condition_setup: condition  */
#line 1445 "include/syntax-analyzer/components/yacc.y"
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
#line 3367 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 161: /* then_body_setup: executable_body  */
#line 1460 "include/syntax-analyzer/components/yacc.y"
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
#line 3388 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 162: /* do_while: do_while_head do_body  */
#line 1482 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3396 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 163: /* $@15: %empty  */
#line 1486 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);

    }
#line 3405 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 164: /* do_while: WORD_DO $@15 WORD_WHILE do_while_tail  */
#line 1491 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3413 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 165: /* do_while: WORD_DO error ';'  */
#line 1495 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;

    }
#line 3425 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* do_while_head: WORD_DO  */
#line 1506 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_DO_START,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            }));
    }
#line 3439 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 167: /* do_body: executable_body WORD_WHILE condition ';'  */
#line 1519 "include/syntax-analyzer/components/yacc.y"
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
#line 3459 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 168: /* do_body: executable_body WORD_WHILE condition error  */
#line 1535 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3471 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 169: /* $@16: %empty  */
#line 1543 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE);

    }
#line 3480 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 170: /* do_body: executable_body $@16 do_while_tail  */
#line 1548 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);
    }
#line 3488 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 172: /* do_while_tail: condition error  */
#line 1556 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3498 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* executable_body: '{' executable_statements '}'  */
#line 1567 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3506 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* executable_body: '{' executable_statements error  */
#line 1571 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 3518 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* executable_body: '{' error '}'  */
#line 1579 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        yyerrok;
    }
#line 3528 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 176: /* executable_body: executable_stmt  */
#line 1585 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3536 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* executable_body: '{' '}'  */
#line 1589 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3544 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 178: /* executable_statements: executable_stmt  */
#line 1595 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 3550 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 179: /* executable_statements: executable_statements executable_stmt  */
#line 1596 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 3556 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 180: /* opt_trunc_constant: numeric_constant  */
#line 1603 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3564 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 181: /* opt_trunc_constant: trunc_constant  */
#line 1607 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3572 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 182: /* trunc_constant: WORD_TRUNC '(' numeric_constant ')'  */
#line 1614 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

    }
#line 3583 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* trunc_constant: WORD_TRUNC '(' numeric_constant error  */
#line 1621 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3597 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* trunc_constant: WORD_TRUNC numeric_constant ')'  */
#line 1631 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3610 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 185: /* trunc_constant: WORD_TRUNC numeric_constant error  */
#line 1640 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3624 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 186: /* opt_trunc_variable: variable  */
#line 1653 "include/syntax-analyzer/components/yacc.y"
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
#line 3643 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 187: /* opt_trunc_variable: trunc_variable  */
#line 1668 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3651 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 188: /* trunc_variable: WORD_TRUNC '(' variable ')'  */
#line 1675 "include/syntax-analyzer/components/yacc.y"
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
#line 3675 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 189: /* trunc_variable: WORD_TRUNC '(' variable error  */
#line 1695 "include/syntax-analyzer/components/yacc.y"
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
#line 3702 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* trunc_variable: WORD_TRUNC variable ')'  */
#line 1718 "include/syntax-analyzer/components/yacc.y"
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
#line 3729 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* trunc_variable: WORD_TRUNC variable error  */
#line 1741 "include/syntax-analyzer/components/yacc.y"
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
#line 3756 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* trunc_variable: WORD_TRUNC error ';'  */
#line 1764 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("trunc ..."), false };

        SemanticActions::specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;

    }
#line 3769 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* trunc_expression: WORD_TRUNC '(' expression ')'  */
#line 1776 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");
    }
#line 3779 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 194: /* trunc_expression: WORD_TRUNC '(' expression error  */
#line 1782 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3793 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 195: /* trunc_expression: WORD_TRUNC expression ')'  */
#line 1792 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3806 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 196: /* trunc_expression: WORD_TRUNC expression error  */
#line 1801 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3820 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 197: /* condition: '(' comparison ')'  */
#line 1816 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);
    }
#line 3828 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 198: /* condition: '(' comparison error  */
#line 1820 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3840 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 199: /* condition: comparison ')'  */
#line 1828 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3851 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 200: /* condition: comparison error  */
#line 1835 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;

    }
#line 3863 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 201: /* comparison: expression comparison_operator expression  */
#line 1846 "include/syntax-analyzer/components/yacc.y"
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
#line 3890 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 202: /* comparison: expression error  */
#line 1869 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;

    }
#line 3902 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 203: /* comparison: expression comparison_operator error  */
#line 1877 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 3910 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 204: /* comparison_operator: OP_EQUAL  */
#line 1884 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_EQUAL, StringPool::create(Translator::translate(OP_EQUAL)) };
    }
#line 3918 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 205: /* comparison_operator: OP_NOT_EQUAL  */
#line 1888 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_NOT_EQUAL, StringPool::create(Translator::translate(OP_NOT_EQUAL)) };
    }
#line 3926 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 206: /* comparison_operator: OP_GE  */
#line 1892 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GE, StringPool::create(Translator::translate(OP_GE)) };
    }
#line 3934 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 207: /* comparison_operator: OP_LE  */
#line 1896 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LE, StringPool::create(Translator::translate(OP_LE)) };
    }
#line 3942 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 208: /* comparison_operator: '>'  */
#line 1900 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GT, StringPool::create(">") };
    }
#line 3950 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 209: /* comparison_operator: '<'  */
#line 1904 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LT, StringPool::create("<") };
    }
#line 3958 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* expression: term  */
#line 1913 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3966 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 211: /* expression: expression_setup positive_term  */
#line 1917 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;
        (yyval.metadata).reference = (yyvsp[-1].metadata).reference;
        
        (yyval.metadata).expression.assignable = false;
    }
#line 3982 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 212: /* expression: '+' term  */
#line 1929 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUM_OPERAND);

    }
#line 3993 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 213: /* expression: '+' error  */
#line 1936 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;

    }
#line 4006 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 214: /* expression: expression '+' term  */
#line 1945 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4014 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 215: /* expression: expression '+' error  */
#line 1949 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 4026 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 216: /* expression: expression '-' term  */
#line 1957 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4034 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 217: /* expression: expression '-' error  */
#line 1961 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 4046 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 218: /* expression: trunc_expression  */
#line 1969 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4054 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 219: /* expression: expression '+' trunc_expression  */
#line 1973 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4062 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 220: /* expression: expression '-' trunc_expression  */
#line 1977 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4070 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 221: /* expression_setup: expression  */
#line 1984 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 4080 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 222: /* term: positive_term  */
#line 1995 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4088 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 223: /* term: negative_term  */
#line 1999 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4096 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 224: /* positive_term: positive_term '*' factor  */
#line 2006 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4104 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 225: /* positive_term: positive_term '/' factor  */
#line 2010 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4112 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 226: /* positive_term: trunc_expression '/' factor  */
#line 2014 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4120 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 227: /* positive_term: trunc_expression '*' factor  */
#line 2018 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4128 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 228: /* positive_term: trunc_expression '/' trunc_expression  */
#line 2022 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4136 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 229: /* positive_term: trunc_expression '*' trunc_expression  */
#line 2026 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4144 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 230: /* positive_term: positive_term '/' trunc_expression  */
#line 2030 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4152 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 231: /* positive_term: positive_term '*' trunc_expression  */
#line 2034 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4160 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 232: /* positive_term: positive_factor  */
#line 2038 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4168 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 233: /* positive_term: positive_term '*' error  */
#line 2042 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4180 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 234: /* positive_term: positive_term '/' error  */
#line 2050 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4192 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 235: /* negative_term: negative_term '*' factor  */
#line 2061 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4200 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 236: /* negative_term: negative_term '/' factor  */
#line 2065 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4208 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 237: /* negative_term: negative_term '/' trunc_expression  */
#line 2069 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4216 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 238: /* negative_term: negative_term '*' trunc_expression  */
#line 2073 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4224 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 239: /* negative_term: negative_factor  */
#line 2077 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4232 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 240: /* negative_term: negative_term '*' error  */
#line 2081 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4244 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 241: /* negative_term: negative_term '/' error  */
#line 2089 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4256 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 242: /* negative_term: '*' factor  */
#line 2097 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_MUL_FACTOR);

    }
#line 4267 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 243: /* negative_term: '/' factor  */
#line 2104 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_DIV_FACTOR);

    }
#line 4278 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 244: /* negative_term: '*' error  */
#line 2111 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4291 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 245: /* negative_term: '/' error  */
#line 2120 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4304 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 246: /* factor: positive_factor  */
#line 2134 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4312 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 247: /* factor: negative_factor  */
#line 2138 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4320 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 248: /* positive_factor: variable  */
#line 2145 "include/syntax-analyzer/components/yacc.y"
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
#line 4339 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 249: /* positive_factor: positive_constant  */
#line 2160 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4347 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 250: /* positive_factor: function_invocation_head  */
#line 2164 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4355 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 251: /* negative_factor: negative_constant  */
#line 2171 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4363 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 252: /* negative_factor: lambda_invocation_head  */
#line 2175 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };
        
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);
    }
#line 4374 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 253: /* negative_factor: '-' LITERAL_UINT  */
#line 2182 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4386 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 254: /* negative_factor: '-' function_invocation_head  */
#line 2190 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4397 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 255: /* negative_factor: '-' variable  */
#line 2197 "include/syntax-analyzer/components/yacc.y"
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
#line 4417 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 256: /* negative_factor: '-' lambda_invocation_head  */
#line 2213 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);

    }
#line 4430 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 257: /* negative_factor: '-' error  */
#line 2222 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUB_OPERANDS);
        yyerrok;

    }
#line 4443 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 258: /* numeric_constant: positive_constant  */
#line 2236 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4451 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 259: /* numeric_constant: negative_constant  */
#line 2240 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4459 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 260: /* positive_constant: LITERAL_UINT  */
#line 2247 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4468 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 261: /* positive_constant: LITERAL_FLOAT  */
#line 2252 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4477 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 262: /* negative_constant: '-' LITERAL_FLOAT  */
#line 2260 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL , .lref = SemanticActions::turnNegative((yyvsp[0].lref)) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };

    }
#line 4487 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 263: /* variable: IDENTIFIER  */
#line 2271 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.pid) = StringPool::create((yyvsp[0].sref)->symbol);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariableName((yyvsp[0].sref)->symbol);

    }
#line 4498 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 264: /* variable: variable '.' IDENTIFIER  */
#line 2278 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].pid), "." + (yyvsp[0].sref)->symbol);
        (yyval.pid) = (yyvsp[-2].pid);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariablePrefix((yyvsp[0].sref)->symbol);

    }
#line 4510 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 4514 "src/syntax-analyzer/components/parser.cpp"

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

#line 2287 "include/syntax-analyzer/components/yacc.y"
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

    if (SemanticAnalyzer::CHK_TYPES.truncateNecessary(e))
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            result.expression.type = SemanticAnalyzer::CHK_TYPES.checkTruncate(e);
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
    } else
        result = operand;
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
