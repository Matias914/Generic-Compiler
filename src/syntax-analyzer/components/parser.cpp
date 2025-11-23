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
  YYSYMBOL_if_word = 96,                   /* if_word  */
  YYSYMBOL_if_head = 97,                   /* if_head  */
  YYSYMBOL_condition_body_setup = 98,      /* condition_body_setup  */
  YYSYMBOL_condition_setup = 99,           /* condition_setup  */
  YYSYMBOL_then_body_setup = 100,          /* then_body_setup  */
  YYSYMBOL_do_while = 101,                 /* do_while  */
  YYSYMBOL_102_15 = 102,                   /* $@15  */
  YYSYMBOL_do_while_head = 103,            /* do_while_head  */
  YYSYMBOL_do_body = 104,                  /* do_body  */
  YYSYMBOL_105_16 = 105,                   /* $@16  */
  YYSYMBOL_do_while_tail = 106,            /* do_while_tail  */
  YYSYMBOL_executable_body = 107,          /* executable_body  */
  YYSYMBOL_executable_statements = 108,    /* executable_statements  */
  YYSYMBOL_opt_trunc_constant = 109,       /* opt_trunc_constant  */
  YYSYMBOL_trunc_constant = 110,           /* trunc_constant  */
  YYSYMBOL_opt_trunc_variable = 111,       /* opt_trunc_variable  */
  YYSYMBOL_trunc_variable = 112,           /* trunc_variable  */
  YYSYMBOL_trunc_expression = 113,         /* trunc_expression  */
  YYSYMBOL_condition = 114,                /* condition  */
  YYSYMBOL_comparison = 115,               /* comparison  */
  YYSYMBOL_comparison_operator = 116,      /* comparison_operator  */
  YYSYMBOL_expression = 117,               /* expression  */
  YYSYMBOL_expression_setup = 118,         /* expression_setup  */
  YYSYMBOL_term = 119,                     /* term  */
  YYSYMBOL_positive_term = 120,            /* positive_term  */
  YYSYMBOL_negative_term = 121,            /* negative_term  */
  YYSYMBOL_factor = 122,                   /* factor  */
  YYSYMBOL_positive_factor = 123,          /* positive_factor  */
  YYSYMBOL_negative_factor = 124,          /* negative_factor  */
  YYSYMBOL_numeric_constant = 125,         /* numeric_constant  */
  YYSYMBOL_positive_constant = 126,        /* positive_constant  */
  YYSYMBOL_negative_constant = 127,        /* negative_constant  */
  YYSYMBOL_variable = 128                  /* variable  */
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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1063

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  265
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  403

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
    1188,  1189,  1195,  1199,  1206,  1214,  1223,  1248,  1263,  1283,
    1303,  1324,  1345,  1353,  1361,  1370,  1391,  1398,  1415,  1432,
    1452,  1459,  1474,  1496,  1501,  1500,  1509,  1520,  1533,  1549,
    1558,  1557,  1569,  1570,  1581,  1585,  1593,  1599,  1603,  1610,
    1611,  1617,  1621,  1628,  1635,  1645,  1654,  1667,  1682,  1689,
    1709,  1732,  1755,  1778,  1790,  1796,  1806,  1815,  1830,  1834,
    1842,  1849,  1860,  1883,  1891,  1898,  1902,  1906,  1910,  1914,
    1918,  1927,  1931,  1943,  1950,  1959,  1963,  1971,  1975,  1983,
    1987,  1991,  1998,  2009,  2013,  2020,  2024,  2028,  2032,  2036,
    2040,  2044,  2048,  2052,  2056,  2064,  2075,  2079,  2083,  2087,
    2091,  2095,  2103,  2111,  2118,  2125,  2134,  2148,  2152,  2159,
    2174,  2178,  2185,  2189,  2196,  2204,  2211,  2227,  2236,  2250,
    2254,  2261,  2266,  2274,  2285,  2292
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
  "lambda_invocation_tail", "lambda_real_parameter", "if", "if_word",
  "if_head", "condition_body_setup", "condition_setup", "then_body_setup",
  "do_while", "$@15", "do_while_head", "do_body", "$@16", "do_while_tail",
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

#define YYPACT_NINF (-303)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-223)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     655,  -303,    33,  -303,   858,   438,    10,  -303,  -303,   -24,
    -303,  -303,   113,   675,  -303,  -303,  -303,    55,  -303,  -303,
    -303,   973,  -303,  -303,  -303,    14,   969,   130,  -303,   373,
    -303,   499,    25,  -303,    51,    -2,    59,   991,    89,  -303,
    -303,   951,   494,   316,   608,   617,  -303,  -303,   -13,   246,
     319,  -303,   346,   352,  -303,  -303,  -303,  -303,    81,   140,
     400,  -303,   418,   775,   166,  -303,  -303,   191,   210,  -303,
     116,    81,  -303,   284,  -303,  -303,  -303,  -303,   387,   973,
    -303,   447,  -303,  -303,   221,   499,   951,   142,   425,   499,
     871,    35,   541,   884,  -303,  -303,   242,   231,   456,  -303,
     243,  -303,   249,   182,    81,  -303,  1009,  -303,   951,   369,
     566,  -303,   -13,  -303,  -303,  -303,  -303,  -303,  -303,    81,
    -303,  -303,  -303,  -303,  -303,  -303,   422,   422,  -303,  -303,
     252,   514,   532,   346,   219,   335,   584,   599,  -303,   264,
     296,   299,   795,   322,   295,   815,  -303,  -303,  -303,   695,
    -303,  -303,  -303,   330,  -303,  -303,   558,  -303,  -303,    58,
     243,  -303,  -303,   973,  -303,  -303,  -303,   343,  -303,   365,
      45,  -303,  -303,  -303,   499,   897,  -303,  -303,  -303,   371,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,   476,
     348,  -303,  -303,   917,  1009,  1009,  -303,   370,   165,  -303,
    -303,   275,  -303,   383,   183,  -303,  -303,  -303,  -303,   100,
    -303,   164,   581,  -303,  -303,  -303,  -303,   175,  -303,  -303,
    -303,  -303,  -303,  -303,   -13,  -303,  -303,   -13,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,   207,   216,  -303,  -303,   715,  -303,  -303,  -303,
     735,  -303,  -303,  -303,  -303,   558,  -303,  -303,   151,  -303,
     390,  -303,   526,  -303,    81,    81,  -303,  -303,  -303,  -303,
    -303,   302,   209,   483,   426,  -303,  -303,  -303,   155,  -303,
    -303,  -303,  -303,   239,  -303,  -303,   909,   111,   265,    47,
    -303,  -303,   909,   332,   909,  -303,  -303,  -303,  -303,  -303,
    -303,   415,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    1014,  -303,   434,  -303,  -303,   558,  -303,   558,  -303,  -303,
     235,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,   436,  -303,   442,    73,  -303,  -303,  -303,  -303,  -303,
     909,   909,  -303,   149,  -303,  -303,   292,  -303,   930,  -303,
    -303,   455,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,   950,  -303,  -303,   455,   835,  -303,   244,
    -303,  -303,   423,  -303,   259,  -303,   755,  -303,  -303,   423,
    1027,  -303,  -303,  -303,  -303,  -303,  -303,   625,   458,  -303,
    -303,  -303,    81,   459,   391,    19,  -303,  -303,    29,  -303,
    -303,  -303,  -303
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     4,     0,   147,     0,     0,     0,    41,    42,   264,
       8,    10,     0,     0,     2,     7,     5,     0,    80,     6,
      75,     0,    79,    76,    77,     0,     0,     0,    78,     0,
      81,     0,     0,    11,     0,     0,     0,     0,   264,   262,
     261,     0,     0,     0,     0,     0,   251,   253,   219,     0,
       0,   211,   223,   224,   233,   240,   250,   252,   249,     0,
       0,    15,     0,     0,     0,     1,     3,     0,   264,    34,
       0,    36,    82,     0,   117,   116,   124,   120,   128,     0,
     125,     0,   119,   118,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   163,   170,     0,     0,   264,
       0,   103,     0,     0,   106,   166,     0,    74,     0,     0,
       0,   214,     0,   213,   258,   263,   254,   255,   257,   256,
     245,   243,   247,   248,   246,   244,     0,     0,    70,    73,
      69,     0,     0,   212,     0,     0,     0,     0,    93,     0,
       0,   222,     0,     0,     0,     0,    13,     9,    24,     0,
      20,    22,    23,     0,    30,    32,     0,    31,    29,     0,
       0,    86,    85,     0,   123,   127,   130,     0,   144,     0,
       0,   143,   142,   150,     0,     0,   148,   160,   162,     0,
     201,   200,   203,   205,   207,   208,   206,   209,   210,     0,
       0,   178,   179,     0,     0,     0,   102,     0,     0,   265,
     101,     0,   100,     0,     0,   182,   181,   259,   260,     0,
     165,     0,     0,   197,   196,    68,    71,     0,   230,   228,
     229,   227,    72,   216,   220,   215,   218,   221,   217,   234,
     232,   225,   235,   231,   226,   241,   239,   236,   242,   238,
     237,    91,     0,     0,    19,    16,     0,   121,    28,    25,
       0,    14,    12,    21,   131,     0,    62,    57,     0,    35,
      53,    51,     0,    40,    37,    39,   126,   129,   156,   199,
     198,     0,     0,     0,   154,   152,   145,   204,   222,   176,
     175,   174,   180,     0,   171,    83,     0,     0,     0,     0,
      97,    96,     0,     0,     0,   173,   172,   195,   194,    67,
      66,    95,    88,    87,    90,    89,    18,    17,    27,    26,
       0,    33,    53,    56,    55,     0,    43,     0,    60,    61,
       0,   159,   158,   155,   146,   151,   157,   149,   153,   169,
     168,     0,   109,   108,     0,   186,   185,   112,    99,    98,
       0,     0,   107,     0,    94,    92,     0,   132,     0,    47,
      52,     0,    54,    59,    58,   105,   104,   184,   183,   113,
     115,   111,   110,     0,   138,   135,     0,     0,    44,     0,
     137,   133,     0,    48,     0,    64,     0,    46,    45,     0,
       0,   136,    50,    49,    65,    63,   134,     0,     0,   141,
     140,   188,   187,     0,     0,     0,   139,   193,     0,   192,
     191,   190,   189
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -303,  -303,   484,  -303,  -303,   124,  -303,  -303,  -133,  -148,
     324,  -303,  -303,  -303,  -303,    11,  -303,  -303,  -303,  -303,
    -303,  -303,   241,  -303,  -250,  -303,   135,  -303,     3,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -136,  -303,  -303,  -303,
    -303,  -303,     6,  -303,  -303,  -303,  -303,   -69,    40,  -303,
    -303,  -303,  -303,   123,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,   308,   -67,  -302,  -259,
    -303,  -303,  -303,   -21,   -25,   433,  -303,    49,  -303,     9,
     470,  -303,    27,   127,   157,  -187,   -65,   -62,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    13,    14,    63,   147,   148,   142,   245,   149,   150,
     151,   255,   156,    70,   160,    17,   259,   351,   368,   311,
     366,   373,   260,   317,   261,   262,   369,    18,   152,    20,
      21,    72,    22,   301,   345,    23,   103,   209,   342,   293,
     341,    24,    46,    26,    77,    78,    79,    80,    47,   310,
     347,   379,   372,   381,   388,    28,    29,    87,    88,    89,
     177,    30,    35,    31,    95,   195,   210,    96,   193,   204,
     205,   390,   391,    48,   211,    91,   189,    92,    50,    51,
      52,    53,   121,    54,    55,   206,    56,    57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   253,    61,    19,    90,    62,    25,   106,   348,   246,
     165,    59,   250,    32,   289,    74,    19,    71,   169,    25,
     399,   112,   178,    64,   126,   127,    97,   331,   333,   112,
     401,    32,   104,   337,    94,   343,   180,    25,   207,    60,
      27,   208,    75,   119,   363,    98,   269,    99,   335,   117,
     400,   113,    64,    27,    49,   100,    67,   101,   102,   263,
     402,    33,   287,    32,   102,   350,   181,   352,   102,    25,
      73,    27,   125,   294,   357,    81,   270,    68,   336,   105,
      99,   359,   360,   118,    69,    32,   109,   107,    94,    32,
     110,    25,    94,    32,   266,    25,   192,    64,   253,    25,
     198,   334,   253,    27,   358,   218,   220,   271,   273,   141,
     224,   227,   332,   230,   233,   236,   239,   157,    62,    64,
     102,   389,    99,   201,    15,    27,     7,     8,    81,    27,
     100,    82,   101,    27,    39,    40,   207,    15,   -38,   208,
     225,   228,    32,   171,   158,    32,   159,   203,    25,    32,
     361,    25,   313,   219,   221,    25,  -202,   212,    83,   264,
     265,   231,   234,   237,   240,   295,   286,   258,   138,   283,
     172,   122,   122,   314,    32,    32,   299,    94,    94,   362,
      25,    25,    27,   200,   290,    27,  -202,    99,   153,    27,
     131,   132,   296,    32,   201,   100,   282,   101,   104,    25,
     289,   123,   123,   300,   102,    39,    40,   334,   302,   104,
     202,   291,    81,   292,    27,    27,   323,   304,   203,   154,
     229,   207,   207,   207,   208,   208,   208,   207,   253,   207,
     208,    37,   208,    27,   376,   303,   353,   324,   278,   155,
     329,    38,    39,    40,   305,   377,    32,   128,    12,   168,
      32,   194,    25,   122,   122,    43,    25,   354,  -222,   196,
     382,   122,   122,   122,   122,    99,   258,   330,  -222,  -222,
    -222,   199,   378,   320,   129,   207,   207,   130,   208,   208,
     222,   131,   132,   123,   123,   161,    27,   383,    39,    40,
      27,   123,   123,   123,   123,   241,  -222,     3,    39,    40,
       4,   203,     5,     6,   288,   321,  -222,  -222,  -222,   322,
      32,   203,   162,   192,    38,   207,    25,   114,   208,   131,
     132,    12,   207,   248,    16,   208,   258,   242,   258,   207,
     243,    37,   208,   338,   131,   132,   232,    16,    38,   115,
     116,    38,    39,    40,  -114,    12,    32,    37,    32,   192,
      27,   282,    25,   247,    25,  -114,  -114,    38,    39,    40,
     339,   254,   340,    32,    12,   267,   282,    32,  -114,    25,
     213,    43,   268,    25,    84,   279,    32,   274,   275,    85,
     392,  -222,    25,   134,   135,    37,    27,   395,    27,   136,
     137,  -222,  -222,  -222,   398,    38,    39,    40,   285,   276,
     214,   139,    86,    27,   131,   132,   115,    27,    42,    43,
      44,    45,    37,    99,    39,    40,    27,   163,   164,   143,
     315,   316,    38,    39,    40,   140,   173,   203,   174,    12,
    -122,   175,   176,   328,    37,    42,    43,    44,    45,    36,
    -122,  -122,  -122,   344,    38,    39,    40,  -122,   166,  -122,
      37,    12,   380,  -122,  -122,  -122,  -122,   197,    43,  -222,
      38,    39,    40,   167,   315,   349,   355,    41,   -84,  -222,
    -222,  -222,   356,    42,    43,    44,    45,   277,   -84,   -84,
     -84,   367,   131,   132,   325,   -84,   326,   397,    37,   396,
     327,   -84,   -84,   -84,   -84,   111,   312,    66,    38,    39,
      40,   374,   386,   284,     3,    12,    37,     4,     0,     5,
       6,    42,    43,    44,    45,   223,    38,    39,    40,   170,
     133,    38,     0,    12,     0,    93,    37,   318,    12,     0,
      43,    44,    45,   226,     0,     0,    38,    39,    40,     7,
       8,     0,   182,    12,    37,     0,     0,     0,   319,     0,
      43,    44,    45,  -222,    38,    39,    40,     0,   183,   184,
     185,    12,   186,  -222,  -222,  -222,     0,   215,    43,    44,
      45,     7,     8,   256,   187,   188,   131,   132,  -222,     0,
     257,     0,   297,     0,     0,   235,     0,     0,  -222,  -222,
    -222,     0,     0,  -222,   216,     0,    37,   217,     0,     0,
     238,   131,   132,  -222,  -222,  -222,    38,    39,    40,   120,
       0,    37,   298,    12,     0,     0,   131,   132,   124,     0,
      43,    38,    39,    40,     0,     0,   393,     0,    12,     0,
      38,    39,    40,     0,     0,    43,     0,    12,     0,    38,
      39,    40,     0,     0,    43,     0,    12,    99,    39,    40,
       0,     0,     0,    43,   394,     1,     2,     0,     0,     0,
       3,   203,     0,     4,     0,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,    65,     2,     9,     0,     0,
       3,    10,    11,     4,    12,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,   251,   144,     9,     0,     0,
       3,    10,    11,     4,    12,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,   306,   144,     9,     0,     0,
       3,   145,   252,     4,    12,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,   308,   144,     9,     0,     0,
       3,   145,   307,     4,    12,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,   384,   144,     9,     0,     0,
       3,   145,   309,     4,    12,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,     0,   144,     9,     0,     0,
       3,   145,   385,     4,    12,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,     0,   144,     9,     0,     0,
       3,   145,   146,     4,    12,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,     0,   144,     9,     0,     0,
       3,   145,   244,     4,    12,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,     0,   144,     9,     0,     0,
       3,   145,   249,     4,    12,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     9,     0,    34,
       0,   145,   375,  -167,    12,     0,  -167,  -164,  -167,  -167,
       0,     0,   179,     0,     0,     0,  -161,     0,     0,  -161,
    -167,  -161,  -161,     0,  -167,   190,     0,  -167,     0,     3,
       0,     0,     4,  -161,     5,     6,     0,  -161,   272,     0,
    -161,     0,     3,     0,     0,     4,    38,     5,     6,     0,
       0,   191,     0,    12,     0,     0,     0,     0,   280,    38,
       0,   201,     3,    93,     0,     4,    12,     5,     6,     0,
       0,   364,    39,    40,     0,     3,     0,     0,     4,    38,
       5,     6,     0,     0,   281,   203,    12,     0,     0,     0,
       0,   370,    38,     0,     0,     3,     0,   365,     4,    12,
       5,     6,     0,    37,     7,     8,     0,     0,     0,     0,
       0,     0,    38,    38,    39,    40,     0,   371,     0,    12,
      12,    37,     0,     0,     0,    37,    42,    43,    44,    45,
       0,    38,    39,    40,     0,    38,    39,    40,    12,     0,
      76,     0,    12,    37,    42,    43,    44,    45,    42,    43,
      44,    45,     0,    38,    39,    40,     0,     0,     0,     3,
     108,    37,     4,     0,     5,     6,    42,    43,    44,    45,
       0,    38,    39,    40,     0,     0,    38,     0,    86,   387,
     346,     0,     0,    12,    42,    43,    44,    45,     0,    99,
      39,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   203
};

static const yytype_int16 yycheck[] =
{
       0,   149,    26,     0,    29,    29,     0,     9,   310,   142,
      79,     1,   145,    13,   201,     1,    13,    17,    85,    13,
       1,    42,    89,    12,    37,    38,     1,   286,   287,    50,
       1,    31,    32,   292,    31,   294,     1,    31,   103,    29,
       0,   103,    28,    43,   346,    20,     1,    22,     1,    43,
      31,    42,    41,    13,     5,    30,     1,    32,    39,     1,
      31,    28,   198,    63,    39,   315,    31,   317,    39,    63,
      21,    31,    45,   209,     1,    26,    31,    22,    31,    28,
      22,   340,   341,    43,    29,    85,    37,    28,    85,    89,
      41,    85,    89,    93,   163,    89,    93,    86,   246,    93,
     100,   288,   250,    63,    31,   126,   127,   174,   175,    60,
     131,   132,     1,   134,   135,   136,   137,     1,    29,   108,
      39,   380,    22,    12,     0,    85,    13,    14,    79,    89,
      30,     1,    32,    93,    23,    24,   201,    13,    22,   201,
     131,   132,   142,     1,    28,   145,    30,    36,   142,   149,
       1,   145,     1,   126,   127,   149,     1,   108,    28,   159,
     160,   134,   135,   136,   137,     1,     1,   156,    28,   194,
      28,    44,    45,    22,   174,   175,     1,   174,   175,    30,
     174,   175,   142,     1,     1,   145,    31,    22,    22,   149,
      35,    36,    28,   193,    12,    30,   193,    32,   198,   193,
     387,    44,    45,    28,    39,    23,    24,   394,     1,   209,
      28,    28,   163,    30,   174,   175,     7,     1,    36,    28,
       1,   286,   287,   288,   286,   287,   288,   292,   376,   294,
     292,    12,   294,   193,   367,    28,     1,    28,   189,    29,
       1,    22,    23,    24,    28,     1,   246,     1,    29,    28,
     250,     9,   246,   126,   127,    36,   250,    22,    12,    28,
       1,   134,   135,   136,   137,    22,   255,    28,    22,    23,
      24,    22,    28,   262,    28,   340,   341,    31,   340,   341,
      28,    35,    36,   126,   127,     1,   246,    28,    23,    24,
     250,   134,   135,   136,   137,    31,    12,     5,    23,    24,
       8,    36,    10,    11,    29,     3,    22,    23,    24,     7,
     310,    36,    28,   310,    22,   380,   310,     1,   380,    35,
      36,    29,   387,    28,     0,   387,   315,    31,   317,   394,
      31,    12,   394,     1,    35,    36,     1,    13,    22,    23,
      24,    22,    23,    24,    12,    29,   346,    12,   348,   346,
     310,   348,   346,    31,   348,    23,    24,    22,    23,    24,
      28,    31,    30,   363,    29,    22,   363,   367,    36,   363,
       1,    36,     7,   367,     1,    27,   376,     6,     7,     6,
     380,    12,   376,    37,    38,    12,   346,   387,   348,    37,
      38,    22,    23,    24,   394,    22,    23,    24,    28,    28,
      31,     1,    29,   363,    35,    36,    23,   367,    35,    36,
      37,    38,    12,    22,    23,    24,   376,    30,    31,     1,
      30,    31,    22,    23,    24,    25,     1,    36,     3,    29,
      12,     6,     7,     7,    12,    35,    36,    37,    38,     1,
      22,    23,    24,    28,    22,    23,    24,    29,     1,    31,
      12,    29,    29,    35,    36,    37,    38,     1,    36,    12,
      22,    23,    24,    16,    30,    31,    30,    29,    12,    22,
      23,    24,    30,    35,    36,    37,    38,     1,    22,    23,
      24,    26,    35,    36,     1,    29,     3,    28,    12,    31,
       7,    35,    36,    37,    38,     1,   255,    13,    22,    23,
      24,   366,   379,   195,     5,    29,    12,     8,    -1,    10,
      11,    35,    36,    37,    38,     1,    22,    23,    24,    86,
      50,    22,    -1,    29,    -1,    26,    12,     1,    29,    -1,
      36,    37,    38,     1,    -1,    -1,    22,    23,    24,    13,
      14,    -1,     1,    29,    12,    -1,    -1,    -1,    22,    -1,
      36,    37,    38,    12,    22,    23,    24,    -1,    17,    18,
      19,    29,    21,    22,    23,    24,    -1,     1,    36,    37,
      38,    13,    14,    15,    33,    34,    35,    36,    12,    -1,
      22,    -1,     1,    -1,    -1,     1,    -1,    -1,    22,    23,
      24,    -1,    -1,    12,    28,    -1,    12,    31,    -1,    -1,
       1,    35,    36,    22,    23,    24,    22,    23,    24,     1,
      -1,    12,    31,    29,    -1,    -1,    35,    36,     1,    -1,
      36,    22,    23,    24,    -1,    -1,     1,    -1,    29,    -1,
      22,    23,    24,    -1,    -1,    36,    -1,    29,    -1,    22,
      23,    24,    -1,    -1,    36,    -1,    29,    22,    23,    24,
      -1,    -1,    -1,    36,    29,     0,     1,    -1,    -1,    -1,
       5,    36,    -1,     8,    -1,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,     0,     1,    22,    -1,    -1,
       5,    26,    27,     8,    29,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,     0,     1,    22,    -1,    -1,
       5,    26,    27,     8,    29,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,     0,     1,    22,    -1,    -1,
       5,    26,    27,     8,    29,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,     0,     1,    22,    -1,    -1,
       5,    26,    27,     8,    29,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,     0,     1,    22,    -1,    -1,
       5,    26,    27,     8,    29,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    22,    -1,    -1,
       5,    26,    27,     8,    29,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    22,    -1,    -1,
       5,    26,    27,     8,    29,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    22,    -1,    -1,
       5,    26,    27,     8,    29,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    22,    -1,    -1,
       5,    26,    27,     8,    29,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,     1,
      -1,    26,    27,     5,    29,    -1,     8,     9,    10,    11,
      -1,    -1,     1,    -1,    -1,    -1,     5,    -1,    -1,     8,
      22,    10,    11,    -1,    26,     1,    -1,    29,    -1,     5,
      -1,    -1,     8,    22,    10,    11,    -1,    26,     1,    -1,
      29,    -1,     5,    -1,    -1,     8,    22,    10,    11,    -1,
      -1,    27,    -1,    29,    -1,    -1,    -1,    -1,     1,    22,
      -1,    12,     5,    26,    -1,     8,    29,    10,    11,    -1,
      -1,     1,    23,    24,    -1,     5,    -1,    -1,     8,    22,
      10,    11,    -1,    -1,    27,    36,    29,    -1,    -1,    -1,
      -1,     1,    22,    -1,    -1,     5,    -1,    27,     8,    29,
      10,    11,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    22,    23,    24,    -1,    27,    -1,    29,
      29,    12,    -1,    -1,    -1,    12,    35,    36,    37,    38,
      -1,    22,    23,    24,    -1,    22,    23,    24,    29,    -1,
      31,    -1,    29,    12,    35,    36,    37,    38,    35,    36,
      37,    38,    -1,    22,    23,    24,    -1,    -1,    -1,     5,
      29,    12,     8,    -1,    10,    11,    35,    36,    37,    38,
      -1,    22,    23,    24,    -1,    -1,    22,    -1,    29,    12,
      26,    -1,    -1,    29,    35,    36,    37,    38,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     0,     1,     5,     8,    10,    11,    13,    14,    22,
      26,    27,    29,    41,    42,    45,    50,    55,    67,    68,
      69,    70,    72,    75,    81,    82,    83,    88,    95,    96,
     101,   103,   128,    28,     1,   102,     1,    12,    22,    23,
      24,    29,    35,    36,    37,    38,    82,    88,   113,   117,
     118,   119,   120,   121,   123,   124,   126,   127,   128,     1,
      29,    26,    29,    43,    55,     0,    42,     1,    22,    29,
      53,   128,    71,   117,     1,    28,    31,    84,    85,    86,
      87,   117,     1,    28,     1,     6,    29,    97,    98,    99,
     114,   115,   117,    26,    68,   104,   107,     1,    20,    22,
      30,    32,    39,    76,   128,    28,     9,    28,    29,   117,
     117,     1,   113,   119,     1,    23,    24,    82,    88,   128,
       1,   122,   123,   124,     1,   122,    37,    38,     1,    28,
      31,    35,    36,   120,    37,    38,    37,    38,    28,     1,
      25,   117,    46,     1,     1,    26,    27,    44,    45,    48,
      49,    50,    68,    22,    28,    29,    52,     1,    28,    30,
      54,     1,    28,    30,    31,    87,     1,    16,    28,   107,
     115,     1,    28,     1,     3,     6,     7,   100,   107,     1,
       1,    31,     1,    17,    18,    19,    21,    33,    34,   116,
       1,    27,    68,   108,     9,   105,    28,     1,   128,    22,
       1,    12,    28,    36,   109,   110,   125,   126,   127,    77,
     106,   114,   117,     1,    31,     1,    28,    31,   113,   122,
     113,   122,    28,     1,   113,   119,     1,   113,   119,     1,
     113,   122,     1,   113,   122,     1,   113,   122,     1,   113,
     122,    31,    31,    31,    27,    47,    48,    31,    28,    27,
      48,     0,    27,    49,    31,    51,    15,    22,    55,    56,
      62,    64,    65,     1,   128,   128,    87,    22,     7,     1,
      31,   107,     1,   107,     6,     7,    28,     1,   117,    27,
       1,    27,    68,   114,   106,    28,     1,    76,    29,   125,
       1,    28,    30,    79,    76,     1,    28,     1,    31,     1,
      28,    73,     1,    28,     1,    28,     0,    27,     0,    27,
      89,    59,    62,     1,    22,    30,    31,    63,     1,    22,
      55,     3,     7,     7,    28,     1,     3,     7,     7,     1,
      28,   109,     1,   109,   125,     1,    31,   109,     1,    28,
      30,    80,    78,   109,    28,    74,    26,    90,   108,    31,
      64,    57,    64,     1,    22,    30,    30,     1,    31,   109,
     109,     1,    30,   108,     1,    27,    60,    26,    58,    66,
       1,    27,    92,    61,    66,    27,    48,     1,    28,    91,
      29,    93,     1,    28,     0,    27,    93,    12,    94,   109,
     111,   112,   128,     1,    29,   128,    31,    28,   128,     1,
      31,     1,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
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
      94,    94,    95,    95,    95,    95,    95,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    99,   100,   101,   102,   101,   101,   103,   104,   104,
     105,   104,   106,   106,   107,   107,   107,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   110,   111,   111,   112,
     112,   112,   112,   112,   113,   113,   113,   113,   114,   114,
     114,   114,   115,   115,   115,   116,   116,   116,   116,   116,
     116,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   122,   122,   123,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   126,   126,   127,   128,   128
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
       1,     1,     3,     3,     3,     4,     5,     1,     2,     4,
       2,     4,     3,     4,     3,     4,     3,     4,     4,     4,
       2,     1,     1,     2,     0,     4,     3,     1,     4,     4,
       0,     3,     2,     2,     3,     3,     3,     1,     2,     1,
       2,     1,     1,     4,     4,     3,     3,     1,     1,     4,
       4,     3,     3,     3,     4,     4,     3,     3,     3,     3,
       2,     2,     3,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     3,     3,     3,     3,     1,
       3,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     1,     3
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
#line 1665 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 6: /* global_statement: executable_stmt  */
#line 137 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    }
#line 1673 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 8: /* $@1: %empty  */
#line 142 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::addInvalidScope();
        SemanticActions::announceSpecificError(MISSING_PROGRAM_NAME);

        SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration("");

    }
#line 1685 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 10: /* global_statement: '}'  */
#line 151 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);
    }
#line 1693 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 11: /* global_statement: error ';'  */
#line 155 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    }
#line 1702 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 12: /* unnamed_program_tail: program_statements '}'  */
#line 163 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1710 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 13: /* unnamed_program_tail: '}'  */
#line 167 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 1718 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 14: /* unnamed_program_tail: program_statements $end  */
#line 171 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    }
#line 1727 "src/syntax-analyzer/components/parser.cpp"
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
#line 1743 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 17: /* program_tail: program_statements '}'  */
#line 197 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1752 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 18: /* program_tail: program_statements $end  */
#line 202 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticAnalyzer::removeScope();
    }
#line 1761 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 19: /* program_tail: '}'  */
#line 207 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    }
#line 1770 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 20: /* program_statements: program_statement  */
#line 216 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 1776 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 21: /* program_statements: program_statements program_statement  */
#line 217 "include/syntax-analyzer/components/yacc.y"
                                           { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 1782 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 22: /* program_statement: declarative_stmt  */
#line 222 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 1790 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 23: /* program_statement: executable_stmt  */
#line 226 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 1798 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 24: /* program_statement: program_head  */
#line 230 "include/syntax-analyzer/components/yacc.y"
    {
       (yyval.returnable) = false;

       SemanticActions::announceSpecificError(INVALID_PROGRAM_NESTING);

    }
#line 1809 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 25: /* program_statement: '{' '}'  */
#line 237 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1820 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 26: /* program_statement: '{' program_statements '}'  */
#line 244 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1831 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 27: /* program_statement: '{' program_statements $end  */
#line 251 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    }
#line 1843 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 28: /* program_statement: error ';'  */
#line 259 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;

    }
#line 1852 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 29: /* declarative_stmt: type variable_list ';'  */
#line 269 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("VARIABLE DECLARATION");
    }
#line 1860 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 30: /* declarative_stmt: type error ';'  */
#line 273 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1869 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 31: /* declarative_stmt: type variable_list error  */
#line 278 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 1878 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 32: /* $@3: %empty  */
#line 283 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction (
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, (yyvsp[-1].sref)->symbol})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionName((yyvsp[-1].sref)->symbol);

    }
#line 1890 "src/syntax-analyzer/components/parser.cpp"
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
#line 1904 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 36: /* variable_list: variable  */
#line 308 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1912 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 37: /* variable_list: variable_list ',' variable  */
#line 312 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1920 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 38: /* $@5: %empty  */
#line 316 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 1928 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 39: /* variable_list: variable_list $@5 variable  */
#line 320 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
#line 1936 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 40: /* variable_list: variable_list ',' error  */
#line 324 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    }
#line 1945 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 41: /* type: WORD_UINT  */
#line 332 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UINT;
    }
#line 1953 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 42: /* type: WORD_FLOAT  */
#line 336 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = FLOAT;
        SemanticActions::announceSpecificError(NOT_YET_IMPLEMENTED);
    }
#line 1962 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 43: /* $@6: %empty  */
#line 346 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();

    }
#line 1971 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 45: /* unnamed_function_declaration_tail: function_body ';'  */
#line 355 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

    }
#line 1981 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 46: /* unnamed_function_declaration_tail: function_body error  */
#line 361 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 1994 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 47: /* $@7: %empty  */
#line 373 "include/syntax-analyzer/components/yacc.y"
    {
        auto entry = SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
        if (entry != nullptr)
            CodeGenerator::addIntermediateCodeBlock(entry);

    }
#line 2005 "src/syntax-analyzer/components/parser.cpp"
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
#line 2020 "src/syntax-analyzer/components/parser.cpp"
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
#line 2036 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 53: /* $@8: %empty  */
#line 412 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2044 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 55: /* formal_parameter: type IDENTIFIER  */
#line 420 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2054 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 56: /* formal_parameter: type error  */
#line 426 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2064 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 57: /* formal_parameter: IDENTIFIER  */
#line 432 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2076 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 58: /* formal_parameter: parameter_semantics type IDENTIFIER  */
#line 440 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);

    }
#line 2085 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 59: /* formal_parameter: parameter_semantics type error  */
#line 445 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    }
#line 2095 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 60: /* formal_parameter: parameter_semantics error  */
#line 451 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        SemanticActions::announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;

    }
#line 2106 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 61: /* formal_parameter: parameter_semantics IDENTIFIER  */
#line 458 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration((yyvsp[0].sref)->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    }
#line 2117 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 62: /* parameter_semantics: WORD_CR  */
#line 468 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CR);

    }
#line 2126 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 63: /* function_body: '{' program_statements '}'  */
#line 478 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 2134 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 64: /* function_body: '{' '}'  */
#line 482 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 2142 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 65: /* function_body: '{' program_statements $end  */
#line 486 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    }
#line 2153 "src/syntax-analyzer/components/parser.cpp"
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
#line 2171 "src/syntax-analyzer/components/parser.cpp"
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
#line 2192 "src/syntax-analyzer/components/parser.cpp"
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
#line 2214 "src/syntax-analyzer/components/parser.cpp"
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
#line 2235 "src/syntax-analyzer/components/parser.cpp"
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
#line 2257 "src/syntax-analyzer/components/parser.cpp"
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
#line 2277 "src/syntax-analyzer/components/parser.cpp"
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
#line 2297 "src/syntax-analyzer/components/parser.cpp"
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
#line 2317 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 74: /* return: WORD_RETURN error ';'  */
#line 630 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(RETURN_SYNTAX_ERROR);
        yyerrok;

    }
#line 2327 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 75: /* executable_stmt: assignment  */
#line 640 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2333 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 76: /* executable_stmt: multiple_assignments  */
#line 641 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2339 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 77: /* executable_stmt: invocation  */
#line 642 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2345 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 78: /* executable_stmt: if  */
#line 643 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2351 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 79: /* executable_stmt: print  */
#line 644 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = false; }
#line 2357 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 80: /* executable_stmt: return  */
#line 645 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = true;  }
#line 2363 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 81: /* executable_stmt: do_while  */
#line 646 "include/syntax-analyzer/components/yacc.y"
                           { (yyval.returnable) = (yyvsp[0].returnable);    }
#line 2369 "src/syntax-analyzer/components/parser.cpp"
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
#line 2396 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 83: /* assignment: variable OP_ASSIGN error ';'  */
#line 676 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2406 "src/syntax-analyzer/components/parser.cpp"
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
#line 2424 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 85: /* assignment_tail: expression ';'  */
#line 702 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::logStructure("ASSIGNMENT");

    }
#line 2435 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 86: /* assignment_tail: expression error  */
#line 709 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2447 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 87: /* print: WORD_PRINT '(' LITERAL_STRING ')' ';'  */
#line 722 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::logStructure("PRINT");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT, 
                STRING,
                CodeGenerator::Triples::Operand({ LITERAL, { .lref = (yyvsp[-2].lref) } }), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

    }
#line 2464 "src/syntax-analyzer/components/parser.cpp"
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
#line 2481 "src/syntax-analyzer/components/parser.cpp"
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

        SemanticActions::logStructure("PRINT");

    }
#line 2498 "src/syntax-analyzer/components/parser.cpp"
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
#line 2516 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 91: /* $@9: %empty  */
#line 775 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;

    }
#line 2526 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 93: /* print: WORD_PRINT error ';'  */
#line 782 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(PRINT_SYNTAX_ERROR);
        yyerrok;
    }
#line 2535 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 95: /* print_end: %empty  */
#line 791 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
    }
#line 2543 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 96: /* multiple_assignments: variable assignment_list opt_trunc_constant ';'  */
#line 800 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2553 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 97: /* multiple_assignments: variable assignment_list opt_trunc_constant error  */
#line 806 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2565 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 98: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants ';'  */
#line 814 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    }
#line 2577 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 99: /* multiple_assignments: variable assignment_list opt_trunc_constant extra_numeric_constants error  */
#line 822 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-2].metadata));

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2590 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 100: /* multiple_assignments: variable assignment_list ';'  */
#line 831 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::announceSpecificError(MISSING_RIGHT_SIDE_VALUES);

    }
#line 2601 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 101: /* multiple_assignments: variable assignment_list error  */
#line 838 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 2614 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 102: /* multiple_assignments: variable error ';'  */
#line 847 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;

    }
#line 2626 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 104: /* assignment_list: ',' variable assignment_list opt_trunc_constant ','  */
#line 859 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2634 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 105: /* assignment_list: ',' variable error opt_trunc_constant ','  */
#line 863 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_EQUALS);

    }
#line 2645 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 106: /* $@10: %empty  */
#line 870 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_COMMA);

    }
#line 2654 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 108: /* assignment_list: ',' variable assignment_list opt_trunc_constant  */
#line 876 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[0].metadata));

        SemanticActions::announceSpecificError(MISSING_COMMA);

    }
#line 2665 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 109: /* assignment_list: ',' variable assignment_list error  */
#line 883 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    }
#line 2675 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 110: /* assignment_end: opt_trunc_constant ','  */
#line 892 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));
    }
#line 2683 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 111: /* assignment_end: opt_trunc_constant error  */
#line 896 "include/syntax-analyzer/components/yacc.y"
    {
        createMultipleAssignmentTriple((yyvsp[-1].metadata));

        SemanticActions::specifySyntaxError(MISSING_COMMA);
        yyerrok;
    }
#line 2694 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 114: /* $@11: %empty  */
#line 908 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2702 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 117: /* invocation: function_invocation_head error  */
#line 919 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2711 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 119: /* invocation: lambda_invocation_head error  */
#line 925 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 2720 "src/syntax-analyzer/components/parser.cpp"
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
#line 2745 "src/syntax-analyzer/components/parser.cpp"
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
#line 2767 "src/syntax-analyzer/components/parser.cpp"
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
#line 2786 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 123: /* function_invocation_tail: real_parameter_list ')'  */
#line 995 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, ")");
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
    }
#line 2798 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 124: /* function_invocation_tail: ')'  */
#line 1003 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).expression = { UNKNOWN, StringPool::create(")") };

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
        SemanticActions::announceSpecificError(MISSING_ARGUMENT);
    }
#line 2809 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 125: /* real_parameter_list: real_parameter  */
#line 1013 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 2817 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 126: /* real_parameter_list: real_parameter_list ',' real_parameter  */
#line 1017 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].metadata).expression.pid, ", " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-2].metadata).expression.pid;
    }
#line 2827 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 127: /* real_parameter_list: real_parameter_list_setup real_parameter  */
#line 1023 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.type = UNKNOWN;
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;

    }
#line 2838 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 128: /* real_parameter_list_setup: real_parameter_list  */
#line 1033 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
#line 2847 "src/syntax-analyzer/components/parser.cpp"
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
#line 2889 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 130: /* real_parameter: expression error  */
#line 1079 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
#line 2900 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 131: /* $@12: %empty  */
#line 1091 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclaration((yyvsp[-1].sref)->symbol);
        CodeGenerator::addIntermediateCodeBlock (
              SemanticAnalyzer::CHK_LAMBDAS.getLambda().function
        );

    }
#line 2912 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 133: /* $@13: %empty  */
#line 1103 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
    }
#line 2920 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 135: /* $@14: %empty  */
#line 1108 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);

    }
#line 2930 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 137: /* lambda_invocation_middle: '{' executable_statements error  */
#line 1115 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 2942 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 138: /* lambda_invocation_middle: executable_statements error  */
#line 1123 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_BOTH_BRACKETS);
        yyerrok;

    }
#line 2954 "src/syntax-analyzer/components/parser.cpp"
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
#line 3010 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 140: /* lambda_real_parameter: opt_trunc_variable  */
#line 1188 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3016 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 141: /* lambda_real_parameter: opt_trunc_constant  */
#line 1189 "include/syntax-analyzer/components/yacc.y"
                         { (yyval.metadata) = (yyvsp[0].metadata); }
#line 3022 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 142: /* if: if_word if_head ';'  */
#line 1196 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3030 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 143: /* if: if_word if_head error  */
#line 1200 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
#line 3041 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 144: /* if: if_word error ';'  */
#line 1207 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;

    }
#line 3053 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 145: /* if: if_word condition error ';'  */
#line 1215 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3066 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 146: /* if: if_word condition_body_setup WORD_ELSE error ';'  */
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
#line 3092 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 147: /* if_word: WORD_IF  */
#line 1249 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_IF_START,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
            });
        }
    }
#line 3108 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 148: /* if_head: condition_body_setup WORD_ENDIF  */
#line 1264 "include/syntax-analyzer/components/yacc.y"
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

        SemanticActions::logStructure("IF");

    }
#line 3132 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 149: /* if_head: condition_body_setup WORD_ELSE executable_body WORD_ENDIF  */
#line 1284 "include/syntax-analyzer/components/yacc.y"
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

        SemanticActions::logStructure("IF-ELSE");

    }
#line 3156 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 150: /* if_head: condition_body_setup error  */
#line 1304 "include/syntax-analyzer/components/yacc.y"
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
#line 3181 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 151: /* if_head: condition_body_setup WORD_ELSE executable_body error  */
#line 1325 "include/syntax-analyzer/components/yacc.y"
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
#line 3206 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 152: /* if_head: condition error WORD_ENDIF  */
#line 1346 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3218 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 153: /* if_head: condition error WORD_ELSE WORD_ENDIF  */
#line 1354 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;

    }
#line 3230 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 154: /* if_head: condition error WORD_ELSE  */
#line 1362 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    }
#line 3243 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 155: /* if_head: condition_body_setup WORD_ELSE error WORD_ENDIF  */
#line 1371 "include/syntax-analyzer/components/yacc.y"
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
#line 3268 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 156: /* if_head: WORD_ELSE executable_body WORD_ENDIF  */
#line 1392 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::announceSpecificError(MISSING_IF_STATEMENT);

    }
#line 3279 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 157: /* if_head: condition_body_setup WORD_ELSE executable_body INVALID_RWORD  */
#line 1399 "include/syntax-analyzer/components/yacc.y"
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
#line 3300 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 158: /* if_head: condition_body_setup INVALID_RWORD executable_body WORD_ENDIF  */
#line 1416 "include/syntax-analyzer/components/yacc.y"
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
#line 3321 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 159: /* if_head: condition_body_setup INVALID_RWORD executable_body INVALID_RWORD  */
#line 1433 "include/syntax-analyzer/components/yacc.y"
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
#line 3342 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 160: /* condition_body_setup: condition_setup then_body_setup  */
#line 1453 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3350 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 161: /* condition_setup: condition  */
#line 1460 "include/syntax-analyzer/components/yacc.y"
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
#line 3366 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 162: /* then_body_setup: executable_body  */
#line 1475 "include/syntax-analyzer/components/yacc.y"
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
#line 3387 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 163: /* do_while: do_while_head do_body  */
#line 1497 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3395 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 164: /* $@15: %empty  */
#line 1501 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);

    }
#line 3404 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 165: /* do_while: WORD_DO $@15 WORD_WHILE do_while_tail  */
#line 1506 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3412 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 166: /* do_while: WORD_DO error ';'  */
#line 1510 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        SemanticActions::specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;

    }
#line 3424 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 167: /* do_while_head: WORD_DO  */
#line 1521 "include/syntax-analyzer/components/yacc.y"
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_DO_START,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            }));
    }
#line 3438 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 168: /* do_body: executable_body WORD_WHILE condition ';'  */
#line 1534 "include/syntax-analyzer/components/yacc.y"
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

        SemanticActions::logStructure("DO-WHILE");

    }
#line 3458 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 169: /* do_body: executable_body WORD_WHILE condition error  */
#line 1550 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-3].returnable);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3470 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 170: /* $@16: %empty  */
#line 1558 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::announceSpecificError(MISSING_WHILE);

    }
#line 3479 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 171: /* do_body: executable_body $@16 do_while_tail  */
#line 1563 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-2].returnable);
    }
#line 3487 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 173: /* do_while_tail: condition error  */
#line 1571 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    }
#line 3497 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 174: /* executable_body: '{' executable_statements '}'  */
#line 1582 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);
    }
#line 3505 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 175: /* executable_body: '{' executable_statements error  */
#line 1586 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[-1].returnable);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    }
#line 3517 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 176: /* executable_body: '{' error '}'  */
#line 1594 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;

        yyerrok;
    }
#line 3527 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 177: /* executable_body: executable_stmt  */
#line 1600 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = (yyvsp[0].returnable);
    }
#line 3535 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 178: /* executable_body: '{' '}'  */
#line 1604 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.returnable) = false;
    }
#line 3543 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 179: /* executable_statements: executable_stmt  */
#line 1610 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[0].returnable);       }
#line 3549 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 180: /* executable_statements: executable_statements executable_stmt  */
#line 1611 "include/syntax-analyzer/components/yacc.y"
                                            { (yyval.returnable) = (yyvsp[-1].returnable) || (yyvsp[0].returnable); }
#line 3555 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 181: /* opt_trunc_constant: numeric_constant  */
#line 1618 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3563 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 182: /* opt_trunc_constant: trunc_constant  */
#line 1622 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3571 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 183: /* trunc_constant: WORD_TRUNC '(' numeric_constant ')'  */
#line 1629 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

    }
#line 3582 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 184: /* trunc_constant: WORD_TRUNC '(' numeric_constant error  */
#line 1636 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3596 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 185: /* trunc_constant: WORD_TRUNC numeric_constant ')'  */
#line 1646 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3609 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 186: /* trunc_constant: WORD_TRUNC numeric_constant error  */
#line 1655 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));

        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3623 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 187: /* opt_trunc_variable: variable  */
#line 1668 "include/syntax-analyzer/components/yacc.y"
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
#line 3642 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 188: /* opt_trunc_variable: trunc_variable  */
#line 1683 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3650 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 189: /* trunc_variable: WORD_TRUNC '(' variable ')'  */
#line 1690 "include/syntax-analyzer/components/yacc.y"
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
#line 3674 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 190: /* trunc_variable: WORD_TRUNC '(' variable error  */
#line 1710 "include/syntax-analyzer/components/yacc.y"
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
#line 3701 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 191: /* trunc_variable: WORD_TRUNC variable ')'  */
#line 1733 "include/syntax-analyzer/components/yacc.y"
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
#line 3728 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 192: /* trunc_variable: WORD_TRUNC variable error  */
#line 1756 "include/syntax-analyzer/components/yacc.y"
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
#line 3755 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 193: /* trunc_variable: WORD_TRUNC error ';'  */
#line 1779 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("trunc ..."), false };

        SemanticActions::specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;

    }
#line 3768 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 194: /* trunc_expression: WORD_TRUNC '(' expression ')'  */
#line 1791 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");
    }
#line 3778 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 195: /* trunc_expression: WORD_TRUNC '(' expression error  */
#line 1797 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc(" + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3792 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 196: /* trunc_expression: WORD_TRUNC expression ')'  */
#line 1807 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3805 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 197: /* trunc_expression: WORD_TRUNC expression error  */
#line 1816 "include/syntax-analyzer/components/yacc.y"
    {
        createTruncateTriple((yyval.metadata), (yyvsp[-1].metadata));
        
        (yyval.metadata).expression.pid = StringPool::create("trunc " + *StringPool::get((yyvsp[-1].metadata).expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    }
#line 3819 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 198: /* condition: '(' comparison ')'  */
#line 1831 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);
    }
#line 3827 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 199: /* condition: '(' comparison error  */
#line 1835 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    }
#line 3839 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 200: /* condition: comparison ')'  */
#line 1843 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    }
#line 3850 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 201: /* condition: comparison error  */
#line 1850 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;

    }
#line 3862 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 202: /* comparison: expression comparison_operator expression  */
#line 1861 "include/syntax-analyzer/components/yacc.y"
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
#line 3889 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 203: /* comparison: expression error  */
#line 1884 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-1].metadata);

        SemanticActions::specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;

    }
#line 3901 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 204: /* comparison: expression comparison_operator error  */
#line 1892 "include/syntax-analyzer/components/yacc.y"
    {
        yyerrok;
    }
#line 3909 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 205: /* comparison_operator: OP_EQUAL  */
#line 1899 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_EQUAL, StringPool::create(Translator::translate(OP_EQUAL)) };
    }
#line 3917 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 206: /* comparison_operator: OP_NOT_EQUAL  */
#line 1903 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_NOT_EQUAL, StringPool::create(Translator::translate(OP_NOT_EQUAL)) };
    }
#line 3925 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 207: /* comparison_operator: OP_GE  */
#line 1907 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GE, StringPool::create(Translator::translate(OP_GE)) };
    }
#line 3933 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 208: /* comparison_operator: OP_LE  */
#line 1911 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LE, StringPool::create(Translator::translate(OP_LE)) };
    }
#line 3941 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 209: /* comparison_operator: '>'  */
#line 1915 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_GT, StringPool::create(">") };
    }
#line 3949 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 210: /* comparison_operator: '<'  */
#line 1919 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.op) = { CODEOP_LT, StringPool::create("<") };
    }
#line 3957 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 211: /* expression: term  */
#line 1928 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 3965 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 212: /* expression: expression_setup positive_term  */
#line 1932 "include/syntax-analyzer/components/yacc.y"
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { (yyvsp[-1].metadata).expression.type, *StringPool::get((yyvsp[-1].metadata).expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { (yyvsp[0].metadata).expression.type, *StringPool::get((yyvsp[0].metadata).expression.pid) };
        (yyval.metadata).expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        StringPool::append((yyvsp[-1].metadata).expression.pid, " " + *StringPool::get((yyvsp[0].metadata).expression.pid));
        (yyval.metadata).expression.pid = (yyvsp[-1].metadata).expression.pid;
        (yyval.metadata).reference = (yyvsp[-1].metadata).reference;
        
        (yyval.metadata).expression.assignable = false;
    }
#line 3981 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 213: /* expression: '+' term  */
#line 1944 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUM_OPERAND);

    }
#line 3992 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 214: /* expression: '+' error  */
#line 1951 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;

    }
#line 4005 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 215: /* expression: expression '+' term  */
#line 1960 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4013 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 216: /* expression: expression '+' error  */
#line 1964 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 4025 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 217: /* expression: expression '-' term  */
#line 1972 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4033 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 218: /* expression: expression '-' error  */
#line 1976 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    }
#line 4045 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 219: /* expression: trunc_expression  */
#line 1984 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4053 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 220: /* expression: expression '+' trunc_expression  */
#line 1988 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '+');
    }
#line 4061 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 221: /* expression: expression '-' trunc_expression  */
#line 1992 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '-');
    }
#line 4069 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 222: /* expression_setup: expression  */
#line 1999 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    }
#line 4079 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 223: /* term: positive_term  */
#line 2010 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4087 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 224: /* term: negative_term  */
#line 2014 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4095 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 225: /* positive_term: positive_term '*' factor  */
#line 2021 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4103 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 226: /* positive_term: positive_term '/' factor  */
#line 2025 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4111 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 227: /* positive_term: trunc_expression '/' factor  */
#line 2029 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4119 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 228: /* positive_term: trunc_expression '*' factor  */
#line 2033 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4127 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 229: /* positive_term: trunc_expression '/' trunc_expression  */
#line 2037 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4135 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 230: /* positive_term: trunc_expression '*' trunc_expression  */
#line 2041 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4143 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 231: /* positive_term: positive_term '/' trunc_expression  */
#line 2045 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4151 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 232: /* positive_term: positive_term '*' trunc_expression  */
#line 2049 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4159 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 233: /* positive_term: positive_factor  */
#line 2053 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4167 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 234: /* positive_term: positive_term '*' error  */
#line 2057 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4179 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 235: /* positive_term: positive_term '/' error  */
#line 2065 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4191 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 236: /* negative_term: negative_term '*' factor  */
#line 2076 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4199 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 237: /* negative_term: negative_term '/' factor  */
#line 2080 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4207 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 238: /* negative_term: negative_term '/' trunc_expression  */
#line 2084 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '/');
    }
#line 4215 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 239: /* negative_term: negative_term '*' trunc_expression  */
#line 2088 "include/syntax-analyzer/components/yacc.y"
    {
        createArithmeticTriple((yyval.metadata), (yyvsp[-2].metadata), (yyvsp[0].metadata), '*');
    }
#line 4223 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 240: /* negative_term: negative_factor  */
#line 2092 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4231 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 241: /* negative_term: negative_term '*' error  */
#line 2096 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4243 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 242: /* negative_term: negative_term '/' error  */
#line 2104 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[-2].metadata);

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    }
#line 4255 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 243: /* negative_term: '*' factor  */
#line 2112 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_MUL_FACTOR);

    }
#line 4266 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 244: /* negative_term: '/' factor  */
#line 2119 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_DIV_FACTOR);

    }
#line 4277 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 245: /* negative_term: '*' error  */
#line 2126 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4290 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 246: /* negative_term: '/' error  */
#line 2135 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    }
#line 4303 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 247: /* factor: positive_factor  */
#line 2149 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4311 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 248: /* factor: negative_factor  */
#line 2153 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4319 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 249: /* positive_factor: variable  */
#line 2160 "include/syntax-analyzer/components/yacc.y"
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
#line 4338 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 250: /* positive_factor: positive_constant  */
#line 2175 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4346 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 251: /* positive_factor: function_invocation_head  */
#line 2179 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4354 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 252: /* negative_factor: negative_constant  */
#line 2186 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4362 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 253: /* negative_factor: lambda_invocation_head  */
#line 2190 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };
        
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);
    }
#line 4373 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 254: /* negative_factor: '-' LITERAL_UINT  */
#line 2197 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4385 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 255: /* negative_factor: '-' function_invocation_head  */
#line 2205 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    }
#line 4396 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 256: /* negative_factor: '-' variable  */
#line 2212 "include/syntax-analyzer/components/yacc.y"
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
#line 4416 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 257: /* negative_factor: '-' lambda_invocation_head  */
#line 2228 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);

    }
#line 4429 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 258: /* negative_factor: '-' error  */
#line 2237 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { NULLREF , nullptr };
        (yyval.metadata).expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUB_OPERANDS);
        yyerrok;

    }
#line 4442 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 259: /* numeric_constant: positive_constant  */
#line 2251 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4450 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 260: /* numeric_constant: negative_constant  */
#line 2255 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata) = (yyvsp[0].metadata);
    }
#line 4458 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 261: /* positive_constant: LITERAL_UINT  */
#line 2262 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { UINT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4467 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 262: /* positive_constant: LITERAL_FLOAT  */
#line 2267 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL, .lref = (yyvsp[0].lref) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };
    }
#line 4476 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 263: /* negative_constant: '-' LITERAL_FLOAT  */
#line 2275 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.metadata).reference  = { LITERAL , .lref = SemanticActions::turnNegative((yyvsp[0].lref)) };
        (yyval.metadata).expression = { FLOAT, StringPool::create((yyvsp[0].lref)->constant), false };

    }
#line 4486 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 264: /* variable: IDENTIFIER  */
#line 2286 "include/syntax-analyzer/components/yacc.y"
    {
        (yyval.pid) = StringPool::create((yyvsp[0].sref)->symbol);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariableName((yyvsp[0].sref)->symbol);

    }
#line 4497 "src/syntax-analyzer/components/parser.cpp"
    break;

  case 265: /* variable: variable '.' IDENTIFIER  */
#line 2293 "include/syntax-analyzer/components/yacc.y"
    {
        StringPool::append((yyvsp[-2].pid), "." + (yyvsp[0].sref)->symbol);
        (yyval.pid) = (yyvsp[-2].pid);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariablePrefix((yyvsp[0].sref)->symbol);

    }
#line 4509 "src/syntax-analyzer/components/parser.cpp"
    break;


#line 4513 "src/syntax-analyzer/components/parser.cpp"

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

#line 2302 "include/syntax-analyzer/components/yacc.y"
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
