// Importa los archivos necesarios para el Header
%code requires
{
    #include "utils/SymbolTable.h"
    #include "utils/LiteralTable.h"

    #define PR_NULL    (-1)
    #define PR_SYMBOL    0
    #define PR_LITERAL   1
    #define PR_TRIPLE    2

    struct Operator
    {
        char tid;
        int  pid;
    };

    struct Metadata
    {
        struct Expression
        {
            int type;
            int pid;
            bool assignable;
        } expression;
        struct Reference
        {
            int type;
            union
            {
                const SymbolTable::Entry*  sref;
                const LiteralTable::Entry* lref;
                int tref;
            };
        } reference;
    };
}

// Importa y declara lo necesario para el .cpp
%{
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

%}

// Corrige la ruta del header en el .cpp
%define api.header.include {"syntax-analyzer/components/parser.h"}

%union
{
    const SymbolTable::Entry*  sref;
    const LiteralTable::Entry* lref;
    Metadata metadata;
    int pid;
    Operator op;
    bool returnable;
}

%token INVALID_TOKEN
%token IF
%token ELSE
%token ENDIF
%token DO
%token WHILE
%token RETURN
%token PRINT
%token TRUNC
%token UINT
%token FLOAT
%token CR
%token POINTER_OP
%token EQUAL_OP
%token GE_OP
%token LE_OP
%token ASSIGN_OP
%token NOT_EQUAL_OP
%token <sref> IDENTIFIER
%token <lref> FLOAT_LITERAL
%token <lref> UINTEGER_LITERAL
%token <lref> STRING_LITERAL

%start global

// For Functions
%type <returnable> program_statements
%type <returnable> program_statement
%type <returnable> executable_body
%type <returnable> executable_statements
%type <returnable> executable_stmt
%type <returnable> function_body
%type <returnable> do_while
%type <returnable> do_body
%type <returnable> if
%type <returnable> condition_body_setup
%type <returnable> then_body_setup

// For Assignments
%type <sref> assignment_head

// For Arithmetic Expressions
%type <metadata> lambda_real_parameter assignment_tail function_invocation_head invocation_setup
%type <metadata> function_invocation_tail real_parameter_list real_parameter_list_setup real_parameter comparison
%type <metadata> opt_trunc_constant trunc_constant opt_trunc_variable trunc_variable expression expression_setup
%type <metadata> trunc_expression term positive_term negative_term factor positive_factor negative_factor
%type <metadata> numeric_constant positive_constant negative_constant
%type <op> comparison_operator
%type <pid> variable

%% // Rules ------------------------------------------

// ================================== Global Scope ================================= //

global:
    global_statement
    | global global_statement
    | YYEOF
;

global_statement:
    declarative_stmt
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    } // Error: Global Scope Statement
    | executable_stmt
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    } // Error: Global Scope Statement
    | program_head
    | '{'
    {
        SemanticAnalyzer::addInvalidScope();
        SemanticActions::announceSpecificError(MISSING_PROGRAM_NAME);

        SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration("");

    } // Action: SemanticAnalyzer::addInvalidScope + SemanticAnalyzer::checkProgramRedeclaration + Error: Missing Program Name
    unnamed_program_tail
    | '}'
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);
    } // Error: Missing Opening Bracket and Program Name
    | error ';'
    {
        SemanticActions::announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    } // Error: General Error and Global Scope Statement
;

unnamed_program_tail:
    program_statements '}'
    {
        SemanticAnalyzer::removeScope();
    } // Action: SemanticAnalyzer::removeScope()
    | '}'
    {
        SemanticAnalyzer::removeScope();
    } // Action: SemanticAnalyzer::removeScope()
    | program_statements YYEOF
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
    } // Action: SemanticAnalyzer::removeScope() + Error: Missing Closing Bracket and Program Name
;

// =============================== Program Declaration ============================= //

program_head:
    IDENTIFIER '{'
    {
        const std::string s = $1->symbol;
        auto entry = SemanticAnalyzer::CHK_PROGRAMS.checkProgramDeclaration(s);
        if (entry != nullptr)
        {
            SemanticAnalyzer::addScope(s);
            CodeGenerator::addIntermediateCodeBlock(entry);
        }
        else
            SemanticAnalyzer::addInvalidScope();
    } // Action: updateProgramSymbol() + SemanticAnalyzer::checkProgramRedeclaration() + SemanticAnalyzer::addScope()
    program_tail
;

program_tail:
    program_statements '}'
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    } // Action: SemanticAnalyzer::removeScope() + Log  : Program Structure
    | program_statements YYEOF
    {
        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticAnalyzer::removeScope();
    } // Error: Missing Closing Bracket
    | '}'
    {
        SemanticActions::logStructure("PROGRAM");
        SemanticAnalyzer::removeScope();
    } // Action: SemanticAnalyzer::removeScope() + Log  : Program Structure
;

// ================================ Program Statement ============================== //

program_statements:
    program_statement                      { $$ = $1;       }
    | program_statements program_statement { $$ = $1 || $2; }
;

program_statement:
    declarative_stmt
    {
        $$ = false;
    }
    | executable_stmt
    {
        $$ = $1;
    }
    | program_head
    {
       $$ = false;

       SemanticActions::announceSpecificError(INVALID_PROGRAM_NESTING);

    } // Error: Invalid Nesting of Programs
    | '{' '}'
    {
        $$ = false;

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    } // Error: Invalid Nesting of Compounds Statements
    | '{' program_statements '}'
    {
        $$ = $2;

        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    } // Error: Invalid Nesting of Compounds Statements
    | '{' program_statements YYEOF
    {
        $$ = $2;

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);
        SemanticActions::announceSpecificError(INVALID_COMPOUND_NESTING);

    } // Error: Missing Closing Bracket and Invalid Nesting of Compounds Statements
    | error ';'
    {
        yyerrok;

    } // Error: General Error
;

// ============================= Declarative Statement ============================= //

declarative_stmt:
    type variable_list ';'
    {
        SemanticActions::logStructure("VARIABLE DECLARATION");
    } // Log  : Variable Declaration Structure
    | type error ';'
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    } // Error: Missing Variable
    | type variable_list error
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | type IDENTIFIER '('
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction (
            SemanticAnalyzer::ReturnChecker::Element({mapWithCheckerType(SemanticAnalyzer::TYPE), $2->symbol})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionName($2->symbol);

    } // Action: notifyFunctionName()
    function_declaration_middle
    | type '('
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction(
            SemanticAnalyzer::ReturnChecker::Element({mapWithCheckerType(SemanticAnalyzer::TYPE), "...()"})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionWithoutName();

        SemanticActions::announceSpecificError(MISSING_FUNCTION_NAME);

    } // Action: notifyUnnamedFunctionDeclaration() + Error: Missing Function Name
    unnamed_function_declaration_middle
;

// ============================== Variable Declaration ============================= //

variable_list:
    variable
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration()
    | variable_list ',' variable
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration()
    | variable_list
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration + Error: Missing Comma
    variable
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableDeclaration();
    }
    | variable_list ',' error
    {
        SemanticActions::specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    } // Error: Missing Variable
;

type:
    UINT
    {
        SemanticAnalyzer::TYPE = ST_UINT;
    } // Build: Current Type
    | FLOAT
    {
        SemanticAnalyzer::TYPE = ST_FLOAT;
        SemanticActions::announceSpecificError(NOT_YET_IMPLEMENTED);
    } // Error: Type not yet implemented + Build: Current Type
;

// ============================== Function Declaration ============================= //

unnamed_function_declaration_middle:
    formal_parameter_list ')'
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();

    } // Action: checkFunctionDeclaration()
    unnamed_function_declaration_tail
;

unnamed_function_declaration_tail:
    function_body ';'
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

    } // Action: SemanticAnalyzer::removeScope()
    | function_body error
    {
        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Action: SemanticAnalyzer::removeScope() + Error: Missing Semicolon
;

function_declaration_middle:
    formal_parameter_list ')'
    {
        auto entry = SemanticAnalyzer::CHK_FUNCTIONS.checkFunctionDeclaration();
        if (entry != nullptr)
            CodeGenerator::addIntermediateCodeBlock(entry);

    } // Action: checkFunctionDeclaration()
    function_declaration_tail
;

function_declaration_tail:
    function_body ';'
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn($1);
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::logStructure("FUNCTION DECLARATION");

    } // Action: SemanticAnalyzer::removeScope() + Log  : Function Declaration Structure
    | function_body error
    {
        CodeGenerator::notifyEndOfBlock();

        SemanticAnalyzer::removeScope();
        SemanticAnalyzer::CHK_RETURNS.checkIfHasReturn($1);
        SemanticAnalyzer::CHK_RETURNS.removeFunction();

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Action: SemanticAnalyzer::removeScope() + Error: Missing Semicolon
;

formal_parameter_list:
    formal_parameter 
    | formal_parameter_list ',' formal_parameter
    | formal_parameter_list
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    } // Error: Missing Comma
    formal_parameter
;

formal_parameter:
    type IDENTIFIER
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(ST_CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration($2->symbol);

    } // Build: Current Semantic + Action: checkParameterDeclaration()
    | type error
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    } // Error: Missing Parameter Name
    | IDENTIFIER
    {
        SemanticAnalyzer::TYPE = ST_UNSUPPORTED;
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(ST_CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration($1->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    } // Build: Current Type + Current Semantic + Action: checkParameterDeclaration() + Error: Missing Parameter Type
    | parameter_semantics type IDENTIFIER
    {
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration($3->symbol);

    } // Action: checkParameterDeclaration()
    | parameter_semantics type error
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    } // Error: Missing Parameter Name
    | parameter_semantics error
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        SemanticActions::announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;

    } // Error: Missing Parameter Type and Name
    | parameter_semantics IDENTIFIER
    {
        SemanticAnalyzer::TYPE = ST_UNSUPPORTED;
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration($2->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    } // Action: checkParameterDeclaration() + Error: Missing Parameter Type
;

parameter_semantics:
    CR
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(ST_CR);

    } // Build: Current Semantic
;

// =================================== Function Body =============================== //

function_body:
    '{' program_statements '}'
    {
        $$ = $2;
    }
    | '{' program_statements YYEOF
    {
        $$ = $2;

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    } // Error: Missing Closing Bracket
;

// ====================================== Return =================================== //

return:
    RETURN '(' expression ')' ';'
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $3.expression.type, *StringPool::get($3.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand($3.reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

    }
    | RETURN '(' expression ')' error
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $3.expression.type, *StringPool::get($3.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand($3.reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
    | RETURN '(' expression error
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $3.expression.type, *StringPool::get($3.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand($3.reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Closing Parenthesis and Semicolon
    | RETURN expression ')'
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $2.expression.type, *StringPool::get($2.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand($2.reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);

    } // Error: Missing Opening Parenthesis and Semicolon
    | RETURN expression error
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $2.expression.type, *StringPool::get($2.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand($2.reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Both Parenthesis and Semicolon
    | RETURN '(' expression ';'
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $3.expression.type, *StringPool::get($3.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand($3.reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::announceSpecificError(MISSING_CLOSING_PARENTHESIS);

    } // Error: Missing Closing Parenthesis
    | RETURN expression ')' ';'
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $2.expression.type, *StringPool::get($2.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand($2.reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    } // Error: Missing Opening Parenthesis
    | RETURN expression ';'
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $2.expression.type, *StringPool::get($2.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_RET, mapWithOperand($2.reference), mapWithOperand({ PR_NULL, nullptr }) }
            );

        SemanticActions::announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);

    } // Error: Missing Both Parenthesis
    | RETURN error ';'
    {
        SemanticActions::specifySyntaxError(RETURN_SYNTAX_ERROR);
        yyerrok;

    } // Error: Return General Error
;

// ============================== Executable Statement ============================= //

executable_stmt:
    assignment             { $$ = false; }
    | multiple_assignments { $$ = false; }
    | invocation           { $$ = false; }
    | if                   { $$ = $1;    }
    | print                { $$ = false; }
    | return               { $$ = true;  }
    | do_while             { $$ = $1;    }
;

// =================================== Assignment ================================== //

assignment:
    assignment_head assignment_tail
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            Metadata::Reference ref;
            if ($1 != nullptr)
                ref = { PR_SYMBOL, $1 };
            else
                ref = { PR_NULL  , $1 };

            CodeGenerator::INTERMEDIATE_CODE->addTriple({'=', mapWithOperand(ref), mapWithOperand($2.reference)});
        }
    }
    | variable ASSIGN_OP error ';'
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope() + Error: General Error
;

assignment_head:
    variable ASSIGN_OP
    {
        $$ = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
    
    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope()
;

assignment_tail:
    expression ';'
    {
        $$ = $1;

        SemanticActions::logStructure("ASSIGNMENT");

    } // Log  : Assignment Structure
    | expression error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
;

// ==================================== Print ====================================== //

print:
    PRINT '(' STRING_LITERAL ')' ';'
    {
        SemanticActions::logStructure("PRINT");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple({
                TR_PRINT, mapWithOperand({ PR_LITERAL, { .lref = $3 } }), mapWithOperand({ PR_NULL, nullptr })
            });

    } // Log  : Print Structure
    | PRINT '(' STRING_LITERAL ')' error
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple({
                TR_PRINT, mapWithOperand({ PR_LITERAL, { .lref = $3 } }), mapWithOperand({ PR_NULL, nullptr })
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | PRINT '(' expression ')' ';'
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple({
                TR_PRINT, mapWithOperand($3.reference), mapWithOperand({ PR_NULL, nullptr })
            });

        SemanticActions::logStructure("PRINT");

    } // Log  : Print
    | PRINT '(' expression ')' error
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple({
                TR_PRINT, mapWithOperand($3.reference), mapWithOperand({ PR_NULL, nullptr })
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
    | PRINT '(' error ')'
    {
        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;

    } // Error: Missing Argument
    print_end
    | PRINT error ';'
    {
        SemanticActions::specifySyntaxError(PRINT_SYNTAX_ERROR);
        yyerrok;
    } // Error: Print General Error
;

print_end:
    ';'
    | /* empty */
    {
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
    } // Error: Missing Argument and Semicolon
;

// ============================== Multiple Assignment ============================== //

multiple_assignments:
    variable assignment_list opt_trunc_constant ';'
    {
        createMultipleAssignmentTriple($3);
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    } // Log  : Multiple Assignment Structure
    | variable assignment_list opt_trunc_constant error
    {
        createMultipleAssignmentTriple($3);

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
    | variable assignment_list opt_trunc_constant extra_numeric_constants ';'
    {
        createMultipleAssignmentTriple($3);

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::logStructure("MULTIPLE ASSIGNMENT");

    } // Log  : Multiple Assignment Structure
    | variable assignment_list opt_trunc_constant extra_numeric_constants error
    {
        createMultipleAssignmentTriple($3);

        SemanticActions::announceSpecificWarning(EXTRA_NUMERIC_CONSTANTS);
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
    | variable assignment_list ';'
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::announceSpecificError(MISSING_RIGHT_SIDE_VALUES);

    } // Error: Missing Right Side Values
    | variable assignment_list error
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Right Side Values and Semicolon
    | variable error ';'
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();

        SemanticActions::specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;

    } // Warning: Statement Interpreted
;

assignment_list:
    '='
    | ',' variable assignment_list opt_trunc_constant ','
    {
        createMultipleAssignmentTriple($4);
    }
    | ',' variable error opt_trunc_constant ','
    {
        createMultipleAssignmentTriple($4);

        SemanticActions::specifySyntaxError(MISSING_EQUALS);

    } // Error: Missing Equals Operator
    | variable
    {
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_COMMA);

    } // Error: Missing Comma
    assignment_list assignment_end
    | ',' variable assignment_list opt_trunc_constant
    {
        createMultipleAssignmentTriple($4);

        SemanticActions::announceSpecificError(MISSING_COMMA);

    } // Error: Missing Right Side Comma
    | ',' variable assignment_list error
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    } // Error: General Error
;

assignment_end:
    opt_trunc_constant ','
    {
        createMultipleAssignmentTriple($1);
    }
    | opt_trunc_constant error
    {
        createMultipleAssignmentTriple($1);

        SemanticActions::specifySyntaxError(MISSING_COMMA);
        yyerrok;
    } // Error: Missing Comma
;

extra_numeric_constants:
    ',' opt_trunc_constant
    | extra_numeric_constants ',' opt_trunc_constant
    | extra_numeric_constants
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    } // Error: Missing Comma
    opt_trunc_constant
;

// ================================== Invocation =================================== //

invocation:
    function_invocation_head ';'
    | function_invocation_head error
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | lambda_invocation_head ';'
    | lambda_invocation_head error
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
;

// ============================== Function Invocation ============================== //

function_invocation_head:
    invocation_setup function_invocation_tail
    {
        $$.expression = $1.expression;
        StringPool::append($$.expression.pid, *StringPool::get($2.expression.pid));

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr && $1.reference.type != PR_NULL)
        {
            $$.reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple (
                { TR_CALL, mapWithOperand($1.reference), mapWithOperand({ PR_NULL, nullptr }) }
            );
            CodeGenerator::INTERMEDIATE_CODE->commit();
            $$.reference.type = PR_TRIPLE;
        }
        else
            $$.reference = $1.reference;

        SemanticActions::logStructure("FUNCTION INVOCATION");
    }
    | IDENTIFIER '(' error ')'
    {
        $$.expression.pid = StringPool::create($1->symbol + "(...)");
        $$.reference.sref = SemanticAnalyzer::CHK_INVOCATIONS.checkFunctionInScope($1->symbol);
        if ($$.reference.sref != nullptr)
        {
            $$.reference.type = PR_SYMBOL;
            $$.expression.type = mapWithCheckerType($$.reference.sref->type);
        }
        else
        {
            $$.reference.type = PR_NULL;
            $$.expression.type = TC_UNSUPPORTED;
        }

        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
;

invocation_setup:
    IDENTIFIER '('
    {
        $$.expression.pid = StringPool::create($1->symbol + "(");
        $$.reference.sref = SemanticAnalyzer::CHK_INVOCATIONS.checkFunctionInScope($1->symbol);
        if ($$.reference.sref != nullptr)
        {
            $$.reference.type = PR_SYMBOL;
            $$.expression.type = mapWithCheckerType($$.reference.sref->type);
        }
        else
        {
            $$.reference.type = PR_NULL;
            $$.expression.type = TC_UNSUPPORTED;
        }
    }
;

function_invocation_tail:
    real_parameter_list ')'
    {
        StringPool::append($1.expression.pid, ")");
        $$.expression.type = TC_UNSUPPORTED;
        $$.expression.pid = $1.expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
    }
    | ')'
    {
        $$.expression = { TC_UNSUPPORTED, StringPool::create(")") };

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
        SemanticActions::announceSpecificError(MISSING_ARGUMENT);
    }
;

real_parameter_list:
    real_parameter
    {
        $$ = $1;
    }
    | real_parameter_list ',' real_parameter
    {
        StringPool::append($1.expression.pid, ", " + *StringPool::get($3.expression.pid));
        $$.expression.type = TC_UNSUPPORTED;
        $$.expression.pid = $1.expression.pid;
    }
    | real_parameter_list_setup real_parameter
    {
        StringPool::append($1.expression.pid, " " + *StringPool::get($2.expression.pid));
        $$.expression.type = TC_UNSUPPORTED;
        $$.expression.pid = $1.expression.pid;

    } // Error: Missing Comma
;

real_parameter_list_setup:
    real_parameter_list
    {
        $$ = $1;
        SemanticActions::announceSpecificError(MISSING_COMMA);
    }
;

real_parameter:
    expression POINTER_OP IDENTIFIER
    {
        auto entry = SemanticAnalyzer::CHK_INVOCATIONS.checkParameterInScope($3->symbol);
        if (entry != nullptr)
        {
            SemanticAnalyzer::TypeChecker::Expression e1 = {
                mapWithCheckerType($1.expression.type),
                *StringPool::get($1.expression.pid),
                $1.expression.assignable
            };
            SemanticAnalyzer::TypeChecker::Expression e2 = { mapWithCheckerType($3->type), $3->symbol, true };

            SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

            e2.type = entry->semantics;
            int result =  SemanticAnalyzer::CHK_TYPES.checkSemantics(e1, e2);
            if (result == ST_CR && CodeGenerator::INTERMEDIATE_CODE != nullptr)
                CodeGenerator::INTERMEDIATE_CODE->addBuffer(
                    { '=', mapWithOperand($1.reference), mapWithOperand({ PR_SYMBOL, entry }) }
                );
            else if (result == ST_CV && CodeGenerator::INTERMEDIATE_CODE != nullptr)
                CodeGenerator::INTERMEDIATE_CODE->addTriple (
                    { '=', mapWithOperand({ PR_SYMBOL, entry }), mapWithOperand($1.reference) }
                );
        }
        StringPool::append($1.expression.pid, "->" + $3->symbol);
        $$.expression = { TC_UNSUPPORTED, $1.expression.pid, false };
    }
    | expression error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_POINTED_PARAMETER);
        yyerrok;
    }
;

// =============================== Lambda Invocation =============================== //

lambda_invocation_head:
    '(' type IDENTIFIER ')'
    {
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclaration($3->symbol);
        CodeGenerator::addIntermediateCodeBlock (
              SemanticAnalyzer::CHK_LAMBDAS.getLambda().function
        );

    } // Action: SemanticAnalyzer::addScope()
    lambda_invocation_middle
;

lambda_invocation_middle:
    '{' executable_statements '}'
    {
        SemanticAnalyzer::removeScope();
    } // Action: SemanticAnalyzer::addScope()
    lambda_invocation_tail
    | executable_statements '}'
    {
        SemanticAnalyzer::removeScope();
        SemanticActions::announceSpecificError(MISSING_OPENING_BRACKET);

    } // Action: SemanticAnalyzer::addScope() + Error: Missing Opening Bracket
    lambda_invocation_tail
    | '{' executable_statements error
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    } // Action: SemanticAnalyzer::addScope() + Error: Missing Closing Bracket
    lambda_invocation_tail
    | executable_statements error
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_BOTH_BRACKETS);
        yyerrok;

    } // Action: SemanticAnalyzer::addScope() + Error: Missing Both Brackets
    lambda_invocation_tail
;

lambda_invocation_tail:
    '(' lambda_real_parameter ')'
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
            e2 = { $2.expression.type, *StringPool::get($2.expression.pid), $2.expression.assignable };
            SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                '=', mapWithOperand(rf), mapWithOperand($2.reference)
            });
            if (l.function != nullptr)
                CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                    TR_CALL, mapWithOperand({PR_SYMBOL, l.function}), mapWithOperand({PR_NULL, nullptr})
                });
        }
        SemanticAnalyzer::CHK_LAMBDAS.notifyDeclarationEnd();

        SemanticActions::logStructure("LAMBDA");

    } // Log : Lambda Structure
;

lambda_real_parameter:
    opt_trunc_variable   { $$ = $1; }
    | opt_trunc_constant { $$ = $1; }
;

// ======================================= If ====================================== //

if:
    IF condition_body_setup ENDIF ';'
    {
        $$ = $2;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::logStructure("IF");

    } // Log  : If
    | IF condition_body_setup ENDIF error
    {
        $$ = $2;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
    | IF condition_body_setup ELSE executable_body ENDIF ';'
    {
        $$ = $2;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::logStructure("IF-ELSE");

    } // Log  : If-Else
    | IF condition_body_setup ELSE executable_body ENDIF error
    {
        $$ = $2 || $4;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
    | IF condition_body_setup error
    {
        $$ = $2;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ENDIF);
        yyerrok;

    } // Error: Missing ENDIF in IF
    | IF condition_body_setup ELSE executable_body error
    {
        $$ = $2 || $4;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ENDIF);
        yyerrok;

    } // Error: Missing ENDIF in IF-ELSE
    | IF condition error ENDIF ';'
    {
        $$ = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    } // Error: Missing Executable Body in IF
    | IF condition error ';'
    {
        $$ = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    } // Error: Missing Exutable Body and ENDIF in IF
    | IF condition error ELSE ENDIF ';'
    {
        $$ = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;

    } // Error: Missing Both Executable Body in IF-ELSE
    | IF condition error ELSE ';'
    {
        $$ = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    } // Error: Missing Both Executable Body and ENDIF in IF-ELSE
    | IF condition_body_setup ELSE error ENDIF ';'
    {
        $$ = $2;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            CodeGenerator::INTERMEDIATE_CODE->updateTripleReference(
                STACK.top(), CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1
            );
            STACK.pop();
        }

        SemanticActions::specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;

    } // Error: Missing Executable Body in ELSE
    | IF condition_body_setup ELSE error ';'
    {
        $$ = $2;

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

    } // Error: Missing Executable Body in ELSE and ENDIF
    | ELSE executable_body ENDIF ';'
    {
        $$ = $2;

        SemanticActions::announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;

    } // Error: Missing IF Statement
    | IF error ';'
    {
        $$ = false;

        SemanticActions::specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;

    } // Error: If General Error
;

condition_body_setup:
    condition_setup then_body_setup
    {
        $$ = $2;
    }
;

condition_setup:
    condition
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
;

then_body_setup:
    executable_body
    {
        $$ = $1;

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
;

// ==================================== Do-While =================================== //

do_while:
    do_while_head do_body
    {
        $$ = $2;
    }
    | DO
    {
        SemanticActions::announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);

    } // Error: Missing Executable Body
    WHILE do_while_tail
    {
        $$ = false;
    }
    | DO error ';'
    {
        $$ = false;

        SemanticActions::specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;

    } // Error: Do-While General Error
;

do_while_head:
    DO
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->getLastTriple() + 1);
    }
;

do_body:
    executable_body WHILE condition ';'
    {
        $$ = $1;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple({
                TR_BRANCH_TRUE,
                mapWithOperand({ PR_TRIPLE, { .tref = CodeGenerator::INTERMEDIATE_CODE->getLastTriple() }}),
                mapWithOperand({ PR_TRIPLE, { .tref = STACK.top() }})
            });
        STACK.pop();

        SemanticActions::logStructure("DO-WHILE");

    } // Log  : DO-WHILE
    | executable_body WHILE condition error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
    | executable_body
    {
        SemanticActions::announceSpecificError(MISSING_WHILE);

    } // Error: Missing WHILE word
    do_while_tail
    {
        $$ = $1;
    }
;

do_while_tail:
    condition ';'
    | condition error
    {
        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
;

// ================================ Executable Body ================================ //

executable_body:
    '{' executable_statements '}'
    {
        $$ = $2;
    }
    | '{' executable_statements error
    {
        $$ = $2;

        SemanticActions::specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;

    } // Missing Closing Bracket
    | '{' error '}'
    {
        $$ = false;

        yyerrok;
    }
    | executable_stmt
    {
        $$ = $1;
    }
;

executable_statements:
    executable_stmt                         { $$ = $1;       }
    | executable_statements executable_stmt { $$ = $1 || $2; }
;

// ===================================== Trunc ===================================== //

opt_trunc_constant:
    numeric_constant
    {
        $$ = $1;
    }
    | trunc_constant
    {
        $$ = $1;
    }
;

trunc_constant:
    TRUNC '(' numeric_constant ')'
    {
        createTruncateTriple($$, $3);

        $$.expression.pid = StringPool::create("trunc(" + *StringPool::get($3.expression.pid) + ")");

    } // Action: truncable()
    | TRUNC '(' numeric_constant error
    {
        createTruncateTriple($$, $3);

        $$.expression.pid = StringPool::create("trunc(" + *StringPool::get($3.expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    } // Action: truncable() + Error: Missing Closing Parenthesis
    | TRUNC numeric_constant ')'
    {
        createTruncateTriple($$, $2);

        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($2.expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    } // Action: truncable() + Error: Missing Opening Parenthesis
    | TRUNC numeric_constant error
    {
        createTruncateTriple($$, $2);

        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($2.expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    } // Action: truncable() + Error: Missing Both Parenthesis
;

opt_trunc_variable:
    variable
    {
        $$.reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ($$.reference.sref != nullptr)
        {
            $$.reference.type = PR_SYMBOL;
            $$.expression = { mapWithCheckerType($$.reference.sref->type), $1, true };
        }
        else
        {
            $$.reference.type = PR_NULL;
            $$.expression = { TC_UNSUPPORTED, $1, true };
        }

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope()
    | trunc_variable
    {
        $$ = $1;
    }
;

trunc_variable:
    TRUNC '(' variable ')'
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            Metadata m;
            m.reference  = { PR_SYMBOL, entry };
            m.expression = { mapWithCheckerType(entry->type), $3, true };
            
            createTruncateTriple($$, m);
        }
        else
        {
            $$.reference  = { PR_NULL, nullptr };
            $$.expression.type = TC_UNSUPPORTED;
            $$.expression.assignable = false;
        }
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($3) + ")");

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope()
    | TRUNC '(' variable error
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            Metadata m;
            m.reference  = { PR_SYMBOL, entry };
            m.expression = { mapWithCheckerType(entry->type), $3, true };
            
            createTruncateTriple($$, m);
        }
        else
        {
            $$.reference  = { PR_NULL, nullptr };
            $$.expression.type = TC_UNSUPPORTED;
            $$.expression.assignable = false;
        }
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($3) + ")");

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope() + Error: Missing Closing Parenthesis
    | TRUNC variable ')'
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        { 
            Metadata m;
            m.reference  = { PR_SYMBOL, entry };
            m.expression = { mapWithCheckerType(entry->type), $2, true };
            
            createTruncateTriple($$, m);

        }
        else
        {
            $$.reference  = { PR_NULL, nullptr };
            $$.expression.type = TC_UNSUPPORTED;
            $$.expression.assignable = false;
        }
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($2) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope() + Error: Missing Opening Parenthesis
    | TRUNC variable error
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        { 
            Metadata m;
            m.reference  = { PR_SYMBOL, entry };
            m.expression = { mapWithCheckerType(entry->type), $2, true };
            
            createTruncateTriple($$, m);
        }
        else
        {
            $$.reference  = { PR_NULL, nullptr };
            $$.expression.type = TC_UNSUPPORTED;
            $$.expression.assignable = false;
        }
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($2) + ")");

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope() + Error: Missing Both Parenthesis
    | TRUNC error ';'
    {
        $$.reference  = { PR_NULL , nullptr };
        $$.expression = { TC_UNSUPPORTED, StringPool::create("trunc ..."), false };

        SemanticActions::specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;

    } // Error: Trunc General Error
;

trunc_expression:
    TRUNC '(' expression ')'
    {
        createTruncateTriple($$, $3);
        
        $$.expression.pid = StringPool::create("trunc(" + *StringPool::get($3.expression.pid) + ")");
    }
    | TRUNC '(' expression error
    {
        createTruncateTriple($$, $3);
        
        $$.expression.pid = StringPool::create("trunc(" + *StringPool::get($3.expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    } // Error: Missing Closing Parenthesis
    | TRUNC expression ')'
    {
        createTruncateTriple($$, $2);
        
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($2.expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    } // Error: Missing Opening Parenthesis
    | TRUNC expression error
    {
        createTruncateTriple($$, $2);
        
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($2.expression.pid));

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    } // Error: Missing Both Parenthesis
;

// ==================================== Condition ================================== //

condition:
    '(' comparison ')'
    | '(' comparison error
    {
        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    } // Error: Missing Closing Parenthesis
    | comparison ')'
    {
        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
    } // Error: Missing Opening Parenthesis
    | comparison error
    {
        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    } // Error: Missing Both Parenthesis
;

comparison:
    expression comparison_operator expression
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { $1.expression.type, *StringPool::get($1.expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { $3.expression.type, *StringPool::get($3.expression.pid) };
        $$.expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        $$.expression.pid = $1.expression.pid;
        StringPool::append($1.expression.pid, *StringPool::get($2.pid) + *StringPool::get($3.expression.pid));

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
        {
            $$.reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple(
                {$2.tid, mapWithOperand($1.reference), mapWithOperand($3.reference)}
            );
            $$.reference.type = PR_TRIPLE;
        }
        else
            $$.reference = { PR_NULL, nullptr };
        $$.expression.assignable = false;
    }
    | expression error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;

    } // Error: Missing Comparison Operator
;

comparison_operator:
    EQUAL_OP
    {
        $$ = { mapWithTripleOperator(EQUAL_OP), StringPool::create(Translator::translate(EQUAL_OP)) };
    }
    | NOT_EQUAL_OP
    {
        $$ = { mapWithTripleOperator(NOT_EQUAL_OP), StringPool::create(Translator::translate(NOT_EQUAL_OP)) };
    }
    | GE_OP
    {
        $$ = { mapWithTripleOperator(GE_OP), StringPool::create(Translator::translate(GE_OP)) };
    }
    | LE_OP
    {
        $$ = { mapWithTripleOperator(LE_OP), StringPool::create(Translator::translate(LE_OP)) };
    }
    | '>'
    {
        $$ = { mapWithTripleOperator('>'), StringPool::create(">") };
    }
    | '<'
    {
        $$ = { mapWithTripleOperator('<'), StringPool::create("<") };
    }
;

// =================================== Expression ================================== //

expression:
    term
    {
        $$ = $1;
    }
    | expression_setup positive_term
    {
        SemanticAnalyzer::TypeChecker::Expression e1 = { $1.expression.type, *StringPool::get($1.expression.pid) };
        SemanticAnalyzer::TypeChecker::Expression e2 = { $2.expression.type, *StringPool::get($2.expression.pid) };
        $$.expression.type = SemanticAnalyzer::CHK_TYPES.checkOperation(e1, e2);

        StringPool::append($1.expression.pid, " " + *StringPool::get($2.expression.pid));
        $$.expression.pid = $1.expression.pid;
        $$.reference = $1.reference;
        
        $$.expression.assignable = false;
    }
    | '+' term
    {
        $$ = $2;

        SemanticActions::announceSpecificError(MISSING_LEFT_SUM_OPERAND);

    } // Error: Missing Left Operand
    | '+' error
    {
        $$.reference  = { PR_NULL , nullptr };
        $$.expression = { TC_UNSUPPORTED, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;

    } // Error: Missing Both Operands
    | expression '+' term
    {
        createArithmeticTriple($$, $1, $3, '+');
    }
    | expression '+' error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    } // Error: Missing Right Operand
    | expression '-' term
    {
        createArithmeticTriple($$, $1, $3, '-');
    }
    | expression '-' error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;

    } // Error: Missing Right Operand
    | trunc_expression
    {
        $$ = $1;
    }
    | expression '+' trunc_expression
    {
        createArithmeticTriple($$, $1, $3, '+');
    }
    | expression '-' trunc_expression
    {
        createArithmeticTriple($$, $1, $3, '-');
    }
;

expression_setup:
    expression
    {
        $$ = $1;

        SemanticActions::announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    } // Error: Missing Expression Operator
;

// ====================================== Term ===================================== //

term:
    positive_term
    {
        $$ = $1;
    }
    | negative_term
    {
        $$ = $1;
    }
;

positive_term:
    positive_term '*' factor
    {
        createArithmeticTriple($$, $1, $3, '*');
    }
    | positive_term '/' factor
    {
        createArithmeticTriple($$, $1, $3, '/');
    }
    | trunc_expression '/' factor
    {
        createArithmeticTriple($$, $1, $3, '/');
    }
    | trunc_expression '*' factor
    {
        createArithmeticTriple($$, $1, $3, '*');
    }
    | trunc_expression '/' trunc_expression
    {
        createArithmeticTriple($$, $1, $3, '/');
    }
    | trunc_expression '*' trunc_expression
    {
        createArithmeticTriple($$, $1, $3, '*');
    }
    | positive_term '/' trunc_expression
    {
        createArithmeticTriple($$, $1, $3, '/');
    }
    | positive_term '*' trunc_expression
    {
        createArithmeticTriple($$, $1, $3, '*');
    }
    | positive_factor
    {
        $$ = $1;
    }
    | positive_term '*' error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    } // Error: Missing Right Factor
    | positive_term '/' error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    } // Error: Missing Right Factor
;

negative_term:
    negative_term '*' factor
    {
        createArithmeticTriple($$, $1, $3, '*');
    }
    | negative_term '/' factor
    {
        createArithmeticTriple($$, $1, $3, '/');
    }
    | negative_term '/' trunc_expression
    {
        createArithmeticTriple($$, $1, $3, '/');
    }
    | negative_term '*' trunc_expression
    {
        createArithmeticTriple($$, $1, $3, '*');
    }
    | negative_factor
    {
        $$ = $1;
    }
    | negative_term '*' error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    } // Error: Missing Right Factor
    | negative_term '/' error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;

    } // Error: Missing Right Factor
    | '*' factor
    {
        $$ = $2;

        SemanticActions::announceSpecificError(MISSING_LEFT_MUL_FACTOR);

    } // Error: Missing Left Factor
    | '/' factor
    {
        $$ = $2;

        SemanticActions::announceSpecificError(MISSING_LEFT_DIV_FACTOR);

    } // Error: Missing Left Factor
    | '*' error
    {
        $$.reference  = { PR_NULL , nullptr };
        $$.expression = { TC_UNSUPPORTED, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    } // Error: Missing Left and Right Factor
    | '/' error
    {
        $$.reference  = { PR_NULL , nullptr };
        $$.expression = { TC_UNSUPPORTED, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    } // Error: Missing Left and Right Factor
;

// ===================================== Factor ==================================== //

factor:
    positive_factor
    {
        $$ = $1;
    }
    | negative_factor
    {
        $$ = $1;
    }
;

positive_factor:
    variable
    {
        $$.reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ($$.reference.sref != nullptr)
        {
            $$.reference.type = PR_SYMBOL;
            $$.expression = { mapWithCheckerType($$.reference.sref->type), $1, true };
        }
        else
        {
            $$.reference.type = PR_NULL;
            $$.expression = { TC_UNSUPPORTED, $1, true };
        }

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope()
    | positive_constant
    {
        $$ = $1;
    }
    | function_invocation_head
    {
        $$ = $1;
    }
;

negative_factor:
    negative_constant
    {
        $$ = $1;
    }
    | lambda_invocation_head
    {
        $$.reference  = { PR_NULL , nullptr };
        $$.expression = { TC_UNSUPPORTED, StringPool::create("..."), false };
        
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);
    } // Error: Invalid Lambda Use
    | '-' UINTEGER_LITERAL
    {
        $$.reference  = { PR_LITERAL, .lref = $2 };
        $$.expression = { TC_UINT, StringPool::create($2->constant), false };

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    } // Error: Missing Left Operand
    | '-' function_invocation_head
    {
        $$ = $2;

        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    } // Error: Missing Left Operand
    | '-' variable
    {
        $$.reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ($$.reference.sref != nullptr)
        {
            $$.reference.type = PR_SYMBOL;
            $$.expression = { mapWithCheckerType($$.reference.sref->type), $2, false };
        }
        else
        {
            $$.reference = { PR_NULL, nullptr };
            $$.expression = { TC_UNSUPPORTED, $2, false };
        }
        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope() + Error: Missing Left Operand
    | '-' lambda_invocation_head
    {
        $$.reference  = { PR_NULL , nullptr };
        $$.expression = { TC_UNSUPPORTED, StringPool::create("..."), false };

        SemanticActions::announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);

    } // Error: Missing Both Operands
    | '-' error
    {
        $$.reference  = { PR_NULL , nullptr };
        $$.expression = { TC_UNSUPPORTED, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_SUB_OPERANDS);
        yyerrok;

    } // Error: Missing Both Operands
;

// ==================================== Constant =================================== //

numeric_constant:
    positive_constant
    {
        $$ = $1;
    }
    | negative_constant
    {
        $$ = $1;
    }
;

positive_constant:
    UINTEGER_LITERAL
    {
        $$.reference  = { PR_LITERAL, .lref = $1 };
        $$.expression = { TC_UINT, StringPool::create($1->constant), false };
    }
    | FLOAT_LITERAL
    {
        $$.reference  = { PR_LITERAL, .lref = $1 };
        $$.expression = { TC_FLOAT, StringPool::create($1->constant), false };
    }
;

negative_constant:
    '-' FLOAT_LITERAL
    {
        $$.reference  = { PR_LITERAL , .lref = SemanticActions::turnNegative($2) };
        $$.expression = { TC_FLOAT, StringPool::create($2->constant), false };

    } // Action: turnNegative()
;

// ==================================== Variable =================================== //

variable:
    IDENTIFIER
    {
        $$ = StringPool::create($1->symbol);

        SemanticAnalyzer::CHK_VARIABLES.notifyVariableName($1->symbol);

    } // Action: notifyVariableName()
    | variable '.' IDENTIFIER
    {
        StringPool::append($1, "." + $3->symbol);
        $$ = $1;

        SemanticAnalyzer::CHK_VARIABLES.notifyVariablePrefix($3->symbol);

    } // Action: notifyVariablePrefix()
;

%% // Codes ------------------------------------------

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