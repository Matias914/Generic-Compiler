// Importa los archivos necesarios para el Header
%code requires
{
    #include "utils/SymbolTable.h"
    #include "utils/LiteralTable.h"
    #include "intermediate-code/Triples.h"

    #define NOTHING  (-1)
    #define SYMBOL    0
    #define LITERAL   1
    #define TRIPLE    2

    struct Metadata
    {
        struct Expression
        {
            int type;
            std::string* representation;
        } expression;
        struct Reference
        {
            int type;
            union
            {
                const SymbolTable::Entry*  sref;
                const LiteralTable::Entry* lref;
            };
        } reference;
    };
}

// Importa y declara lo necesario para el .cpp
%{
#include "utils/resources/macros.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "syntax-analyzer/components/semantic_actions.h"
#include "semantic-analyzer/semantic_analyzer.h"

void yyerror(const char* s);

using namespace SemanticAnalyzer;
using namespace SyntaxAnalyzer::SemanticActions;

#define yylex LexicalAnalyzer::yylex
%}

// Corrige la ruta del header en el .cpp
%define api.header.include {"syntax-analyzer/components/parser.h"}

%union
{
    const SymbolTable::Entry*  sref;
    const LiteralTable::Entry* lref;
    Metadata metadata;
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

%type <metadata> comparison
%type <metadata> function_invocation_head
%type <metadata> invocation_setup
%type <metadata> function_invocation_tail
%type <metadata> real_parameter_list
%type <metadata> real_parameter
%type <metadata> trunc_expression
%type <metadata> expression
%type <metadata> negative_constant
%type <metadata> positive_constant
%type <metadata> numeric_constant
%type <metadata> positive_factor
%type <metadata> negative_factor
%type <metadata> factor
%type <metadata> negative_term
%type <metadata> positive_term
%type <metadata> term

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
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    } // Error: Global Scope Statement
    | executable_stmt
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
    } // Error: Global Scope Statement
    | program_head
    | '{'
    {
        addInvalidScope();
        announceSpecificError(MISSING_PROGRAM_NAME);
        checkProgramRedeclaration("");
    } // Action: addInvalidScope + checkProgramRedeclaration + Error: Missing Program Name
    unnamed_program_tail
    | '}'
    {
        announceSpecificError(MISSING_OPENING_BRACKET);
    } // Error: Missing Opening Bracket and Program Name
    | error ';'
    {
        announceSpecificError(GLOBAL_SCOPE_STATEMENT);
        yyerrok;
    } // Error: General Error and Global Scope Statement
;

unnamed_program_tail:
    program_statements '}'
    {
        removeScope();
    } // Action: removeScope()
    | '}'
    {
        removeScope();
    } // Action: removeScope()
    | program_statements YYEOF
    {
        removeScope();
        announceSpecificError(MISSING_CLOSING_BRACKET);
    } // Action: removeScope() + Error: Missing Closing Bracket and Program Name
;

// =============================== Program Declaration ============================= //

program_head:
    IDENTIFIER '{'
    {
        const std::string s = $1->symbol;
        checkProgramRedeclaration(s);
        if (updateSymbolAsProgram(s) == nullptr)
            addInvalidScope();
        else
            addScope(s);
    } // Action: updateProgramSymbol() + checkProgramRedeclaration() + addScope()
    program_tail
;

program_tail:
    program_statements '}'
    {
        logStructure("PROGRAM");
        removeScope();
    } // Action: removeScope() + Log  : Program Structure
    | program_statements YYEOF
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        removeScope();
    } // Error: Missing Closing Bracket
    | '}'
    {
        logStructure("PROGRAM");
        removeScope();
    } // Action: removeScope() + Log  : Program Structure
;

// ================================ Program Statement ============================== //

program_statements:
    program_statement
    | program_statements program_statement
;

program_statement:
    declarative_stmt
    | executable_stmt
    | program_head
    {
       announceSpecificError(INVALID_PROGRAM_NESTING);
    } // Error: Invalid Nesting of Programs
    | '{' '}'
    {
        announceSpecificError(INVALID_COMPOUND_NESTING);
    } // Error: Invalid Nesting of Compounds Statements
    | '{' program_statements '}'
    {
        announceSpecificError(INVALID_COMPOUND_NESTING);
    } // Error: Invalid Nesting of Compounds Statements
    | '{' program_statements YYEOF
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
        announceSpecificError(INVALID_COMPOUND_NESTING);
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
        logStructure("VARIABLE DECLARATION");
    } // Log  : Variable Declaration Structure
    | type error ';'
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    } // Error: Missing Variable
    | type variable_list error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | type IDENTIFIER '('
    {
        CHK_FUNCTIONS.notifyFunctionName($2->symbol);
    } // Action: notifyFunctionName()
    function_declaration_middle
    | type '('
    {
        CHK_FUNCTIONS.notifyFunctionWithoutName();
        announceSpecificError(MISSING_FUNCTION_NAME);
    } // Action: notifyUnnamedFunctionDeclaration() + Error: Missing Function Name
    unnamed_function_declaration_middle
;

// ============================== Variable Declaration ============================= //

variable_list:
    variable
    {
        upsertVariableScope();
    } // Action: upsertVariableScope()
    | variable_list ',' variable
    {
        upsertVariableScope();
    } // Action: upsertVariableScope()
    | variable_list
    {
        announceSpecificError(MISSING_COMMA);
    } // Action: upsertVariableScope + Error: Missing Comma
    variable
    {
        upsertVariableScope();
    }
    | variable_list ',' error
    {
        specifySyntaxError(MISSING_VARIABLE);
        yyerrok;
    } // Error: Missing Variable
;

type:
    UINT
    {
        CURRENT_TYPE = ST_UINT;
    } // Build: Current Type
    | FLOAT
    {
        CURRENT_TYPE = ST_FLOAT;
        announceSpecificError(NOT_YET_IMPLEMENTED);
    } // Error: Type not yet implemented + Build: Current Type
;

// ============================== Function Declaration ============================= //

unnamed_function_declaration_middle:
    formal_parameter_list ')'
    {
        CHK_FUNCTIONS.checkFunctionDeclaration();
    } // Action: checkFunctionDeclaration()
    unnamed_function_declaration_tail
;

unnamed_function_declaration_tail:
    function_body ';'
    {
        removeScope();
    } // Action: removeScope()
    | function_body error
    {
        removeScope();
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Action: removeScope() + Error: Missing Semicolon
;

function_declaration_middle:
    formal_parameter_list ')'
    {
        CHK_FUNCTIONS.checkFunctionDeclaration();
    } // Action: checkFunctionDeclaration()
    function_declaration_tail
;

function_declaration_tail:
    function_body ';'
    {
        logStructure("FUNCTION DECLARATION");
        removeScope();
    } // Action: removeScope() + Log  : Function Declaration Structure
    | function_body error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
        removeScope();
    } // Action: removeScope() + Error: Missing Semicolon
;

formal_parameter_list:
    formal_parameter 
    | formal_parameter_list ',' formal_parameter
    | formal_parameter_list
    {
        announceSpecificError(MISSING_COMMA);
    } // Error: Missing Comma
    formal_parameter
;

formal_parameter:
    type IDENTIFIER
    {
        CHK_FUNCTIONS.notifyParameterSemantic(ST_CV);
        CHK_FUNCTIONS.checkParameterDeclaration($2->symbol);
    } // Build: Current Semantic + Action: checkParameterDeclaration()
    | type error
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    } // Error: Missing Parameter Name
    | IDENTIFIER
    {
        CURRENT_TYPE = ST_UNSUPPORTED;
        CHK_FUNCTIONS.notifyParameterSemantic(ST_CV);
        CHK_FUNCTIONS.checkParameterDeclaration($1->symbol);
        announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    } // Build: Current Type + Current Semantic + Action: checkParameterDeclaration() + Error: Missing Parameter Type
    | parameter_semantics type IDENTIFIER
    {
        CHK_FUNCTIONS.checkParameterDeclaration($3->symbol);
    } // Action: checkParameterDeclaration()
    | parameter_semantics type error
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;
    } // Error: Missing Parameter Name
    | parameter_semantics error
    {
        specifySyntaxError(MISSING_PARAMETER_NAME);
        announceSpecificError(MISSING_PARAMETER_TYPE);
        yyerrok;
    } // Error: Missing Parameter Type and Name
    | parameter_semantics IDENTIFIER
    {
        CURRENT_TYPE = ST_UNSUPPORTED;
        CHK_FUNCTIONS.checkParameterDeclaration($2->symbol);
        announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);
    } // Action: checkParameterDeclaration() + Error: Missing Parameter Type
;

parameter_semantics:
    CR
    {
        CHK_FUNCTIONS.notifyParameterSemantic(ST_CR);
    } // Build: Current Semantic
;

// =================================== Function Body =============================== //

function_body:
    '{' program_statements '}'
    | '{' program_statements YYEOF
    {
        announceSpecificError(MISSING_CLOSING_BRACKET);
    } // Error: Missing Closing Bracket
;

// ====================================== Return =================================== //

return:
    RETURN '(' expression ')' ';'
    | RETURN '(' expression ')' error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | RETURN '(' expression error
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Closing Parenthesis and Semicolon
    | RETURN expression ')'
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
        announceSpecificError(MISSING_SEMICOLON);
    } // Error: Missing Opening Parenthesis and Semicolon
    | RETURN expression error
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Both Parenthesis and Semicolon
    | RETURN '(' expression ';'
    {
        announceSpecificError(MISSING_CLOSING_PARENTHESIS);
    } // Error: Missing Closing Parenthesis
    | RETURN expression ')' ';'
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    } // Error: Missing Opening Parenthesis
    | RETURN expression ';'
    {
        announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);
    } // Error: Missing Both Parenthesis
    | RETURN error ';'
    {
        specifySyntaxError(RETURN_SYNTAX_ERROR);
        yyerrok;
    } // Error: Return General Error
;

// ============================== Executable Statement ============================= //

executable_stmt:
    assignment_head
    | multiple_assignments
    | invocation
    | if
    | print
    | return
    | do_while_head
;

// =================================== Assignment ================================== //

assignment_head:
    variable ASSIGN_OP
    {
        checkVariableExistanceInScope();
    } // Action: checkVariableExistanceInScope()
    assignment_tail
    | variable ASSIGN_OP error ';'
    {
        checkVariableExistanceInScope();
        yyerrok;
    } // Action: checkVariableExistanceInScope() + Error: General Error
;

assignment_tail:
    expression ';'
    {
        logStructure("ASSIGNMENT");
    } // Log  : Assignment Structure
    | expression error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
;

// ==================================== Print ====================================== //

print:
    PRINT '(' STRING_LITERAL ')' ';'
    {
        logStructure("PRINT");
    } // Log  : Print Structure
    | PRINT '(' STRING_LITERAL ')' error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | PRINT '(' expression ')' ';'
    {
        logStructure("PRINT");
    } // Log  : Print
    | PRINT '(' expression ')' error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | PRINT '(' error ')'
    {
        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    } // Error: Missing Argument
    print_end
    | PRINT error ';'
    {
        specifySyntaxError(PRINT_SYNTAX_ERROR);
        yyerrok;
    } // Error: Print General Error
;

print_end:
    ';'
    | /* empty */
    {
        announceSpecificError(MISSING_SEMICOLON);
    } // Error: Missing Argument and Semicolon
;

// ============================== Multiple Assignment ============================== //

multiple_assignments:
    variable assignment_list opt_trunc_constant extra_numeric_constants ';'
    {
        logStructure("MULTIPLE ASSIGNMENT");
    } // Log  : Multiple Assignment Structure
    | variable assignment_list opt_trunc_constant extra_numeric_constants error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | variable assignment_list ';'
    {
        announceSpecificError(MISSING_RIGHT_SIDE_VALUES);
    } // Error: Missing Right Side Values
    | variable assignment_list error
    {
        specifySyntaxError(MISSING_RIGHT_SIDE_VALUES);
        announceSpecificError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Right Side Values and Semicolon
    | variable error ';'
    {
        specifySyntaxWarning(STATEMENT_INTERPRETED);
        yyerrok;
    } // Warning: Statement Interpreted
;

assignment_list:
    '='
    | ',' variable assignment_list opt_trunc_constant ','
    | ',' variable error opt_trunc_constant ','
    {
        specifySyntaxError(MISSING_EQUALS);
    } // Error: Missing Equals Operator
    | IDENTIFIER
    {
        announceSpecificErrorWithSymbol(MISSING_COMMA);
    } // Error: Missing Comma
    assignment_list assignment_end
    | ',' variable assignment_list opt_trunc_constant
    {
        announceSpecificError(MISSING_COMMA);
    } // Error: Missing Right Side Comma
    | ',' variable assignment_list error
    {
        yyerrok;
    } // Error: General Error
;

assignment_end:
    opt_trunc_constant ','
    | opt_trunc_constant error
    {
        specifySyntaxError(MISSING_COMMA);
        yyerrok;
    } // Error: Missing Comma
;

extra_numeric_constants:
    /* empty */
    | extra_numeric_constants ',' opt_trunc_constant
    | extra_numeric_constants
    {
        announceSpecificError(MISSING_COMMA);
    } // Error: Missing Comma
    opt_trunc_constant
;

// ================================== Invocation =================================== //

invocation:
    function_invocation_head ';'
    | function_invocation_head error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | lambda_invocation_head ';'
    | lambda_invocation_head error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
;

// ============================== Function Invocation ============================== //

function_invocation_head:
    invocation_setup function_invocation_tail
    {
        $$ = $1;
        $$.expression.representation->append($2.expression.representation);
        logStructure("FUNCTION INVOCATION");
    }
    | IDENTIFIER '(' error ')'
    {
        $$.expression.representation = new std::string;
        $$.expression.representation->append($1->symbol)
                                    .append("(...)");
        $$.reference.sref = CHK_INVOCATIONS.checkFunctionInScope($1->symbol);
        loadSymbolMetadata($$);

        specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;
    }
;

invocation_setup:
    IDENTIFIER '('
    {
        $$.expression.representation = new std::string;
        $$.expression.representation->append($1->symbol)
                                    .append("(");
        $$.reference.sref = CHK_INVOCATIONS.checkFunctionInScope($1->symbol);
        loadSymbolMetadata($$);
    }
;

function_invocation_tail:
    real_parameter_list ')'
    {
        $$.expression.representation = $1.expression.representation
        $$.expression.representation->append(")");
        $$.expression.type = TC_UNSUPPORTED;
        CHK_INVOCATIONS.notifyInvocationEnd();
    }
    | ')'
    {
        $$.expression.representation = ")";
        $$.expression.type = TC_UNSUPPORTED;
        CHK_INVOCATIONS.notifyInvocationEnd();
        announceSpecificError(MISSING_ARGUMENT);
    }
;

real_parameter_list:
    real_parameter
    {
        $$ = $1;
    }
    | real_parameter_list ',' real_parameter
    {
        $$.expression.representation = $1.expression.representation + ", " + $3.expression.representation;
        $$.expression.type = TC_UNSUPPORTED;
    }
;

real_parameter:
    expression POINTER_OP IDENTIFIER
    {
        $$.expression.representation = $1.expression.representation + "->" + $3->symbol;
        $$.expression.type = TC_UNSUPPORTED; // Type is validated by the checker
        CHK_INVOCATIONS.checkParameterInScope($3->symbol);
    }
    | expression
    {
        $$ = $1;

        announceSpecificError(MISSING_POINTED_PARAMETER);
    }
;

// =============================== Lambda Invocation =============================== //

lambda_invocation_head:
    '(' type IDENTIFIER ')'
    {
        addLambdaScope();
        CHK_FUNCTIONS.checkParameterDeclaration($3->symbol);
    } // Action: addScope()
    lambda_invocation_tail
;

lambda_invocation_tail:
    '{' executable_statements '}' '(' lambda_real_parameter ')'
    {
        removeScope();
        logStructure("LAMBDA");
    } // Action: addScope() + Log   : Lambda Structure
    | executable_statements '}' '(' lambda_real_parameter ')'
    {
        removeScope();
        announceSpecificError(MISSING_OPENING_BRACKET);
    } // Action: addScope() + Error: Missing Opening Bracket
    | '{' executable_statements '(' lambda_real_parameter ')'
    {
        removeScope();
        announceSpecificError(MISSING_CLOSING_BRACKET);
    } // Action: addScope() + Error: Missing Closing Bracket
    | executable_statements '(' lambda_real_parameter ')'
    {
        removeScope();
        announceSpecificError(MISSING_BOTH_BRACKETS);
    } // Action: addScope() + Error: Missing Both Brackets
;

lambda_real_parameter:
    opt_trunc_variable
    | opt_trunc_constant
;

// ======================================= If ====================================== //

if:
    IF condition executable_body ENDIF ';'
    {
        logStructure("IF");
    } // Log  : If
    | IF condition executable_body ENDIF error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | IF condition executable_body ELSE executable_body ENDIF ';'
    {
        logStructure("IF-ELSE");
    } // Log  : If-Else
    | IF condition executable_body ELSE executable_body ENDIF error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | IF condition executable_body error
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    } // Error: Missing ENDIF in IF
    | IF condition executable_body ELSE executable_body error
    {
        specifySyntaxError(MISSING_ENDIF);
        yyerrok;
    } // Error: Missing ENDIF in IF-ELSE
    | IF condition error ENDIF ';'
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;
    } // Error: Missing Executable Body in IF
    | IF condition error ';'
    {
        specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    } // Error: Missing Exutable Body and ENDIF in IF
    | IF condition error ELSE ENDIF ';'
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;
    } // Error: Missing Both Executable Body in IF-ELSE
    | IF condition error ELSE ';'
    {
        specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    } // Error: Missing Both Executable Body and ENDIF in IF-ELSE
    | IF condition executable_body ELSE error ENDIF ';'
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        yyerrok;
    } // Error: Missing Executable Body in ELSE
    | IF condition executable_body ELSE error ';'
    {
        specifySyntaxError(MISSING_ELSE_EXECUTABLE_BODY);
        announceSpecificError(MISSING_ENDIF);
        yyerrok;
    } // Error: Missing Executable Body in ELSE and ENDIF
    | ELSE executable_body ENDIF ';'
    {
        announceSpecificError(MISSING_IF_STATEMENT);
        yyerrok;
    } // Error: Missing IF Statement
    | IF error ';'
    {
        specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;
    } // Error: If General Error
;

// ==================================== Do-While =================================== //

do_while_head:
    DO executable_body WHILE condition ';'
    {
        logStructure("DO-WHILE");
    } // Log  : DO-WHILE
    | DO executable_body WHILE condition error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | DO executable_body
    {
        announceSpecificError(MISSING_WHILE);
    } // Error: Missing WHILE word
    do_while_tail
    | DO
    {
        announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);
    } // Error: Missing Executable Body
    WHILE do_while_tail
    | DO error ';'
    {
        specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;
    } // Error: Do-While General Error
;

do_while_tail:
    condition ';'
    | condition error
    {
        specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
;

// ================================ Executable Body ================================ //

executable_body:
    '{' executable_statements '}'
    | '{' executable_statements error
    {
        specifySyntaxError(MISSING_CLOSING_BRACKET);
        yyerrok;
    } // Missing Closing Bracket
    | '{' error '}'
    {
        yyerrok;
    }
    | executable_stmt
;

executable_statements:
    executable_stmt
    | executable_statements executable_stmt
;

// ===================================== Trunc ===================================== //

opt_trunc_constant:
    numeric_constant
    | trunc_constant
;

trunc_constant:
    TRUNC '(' numeric_constant ')'
    {
        CHK_COERTIONS.truncable($3.reference.lref->type);
    } // Action: truncable()
    | TRUNC '(' numeric_constant error
    {
        CHK_COERTIONS.truncable($3.reference.lref->type);

        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    } // Action: truncable() + Error: Missing Closing Parenthesis
    | TRUNC numeric_constant ')'
    {
        CHK_COERTIONS.truncable($2.reference.lref->type);

        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    } // Action: truncable() + Error: Missing Opening Parenthesis
    | TRUNC numeric_constant error
    {
        CHK_COERTIONS.truncable($2.reference.lref->type);

        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    } // Action: truncable() + Error: Missing Both Parenthesis
;

opt_trunc_variable:
    variable
    {
        checkVariableExistanceInScope();
    } // Action: checkVariableExistanceInScope()
    | trunc_variable
;

trunc_variable:
    TRUNC '(' variable ')'
    {
        checkVariableExistanceInScope();
    } // Action: checkVariableExistanceInScope()
    | TRUNC '(' variable error
    {
        checkVariableExistanceInScope();
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    } // Action: checkVariableExistanceInScope() + Error: Missing Closing Parenthesis
    | TRUNC variable ')'
    {
        checkVariableExistanceInScope();
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    } // Action: checkVariableExistanceInScope() + Error: Missing Opening Parenthesis
    | TRUNC variable error
    {
        checkVariableExistanceInScope();
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    } // Action: checkVariableExistanceInScope() + Error: Missing Both Parenthesis
    | TRUNC error ';'
    {
        specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;
    } // Error: Trunc General Error
;

trunc_expression:
    TRUNC '(' expression ')'
    {
        $$.expression = $3.expression;
    }
    | TRUNC '(' expression error
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    } // Error: Missing Closing Parenthesis
    | TRUNC expression ')'
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    } // Error: Missing Opening Parenthesis
    | TRUNC expression error
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;
    } // Error: Missing Both Parenthesis
;

// ==================================== Condition ================================== //

condition:
    '(' comparison ')'
    | '(' comparison error
    {
        specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;
    } // Error: Missing Closing Parenthesis
    | comparison ')'
    {
        announceSpecificError(MISSING_OPENING_PARENTHESIS);
    } // Error: Missing Opening Parenthesis
    | comparison error
    {
        specifySyntaxError(MISSING_BOTH_PARENTHESIS);
        yyerrok;
    } // Error: Missing Both Parenthesis
;

comparison:
    expression comparison_operator expression
    {
        $$.expression.representation = "comparison(" + $1.expression.representation + ", " + $3.expression.representation + ")";
        $$.expression.type = CHK_TYPES.check($1.expression, $3.expression);
        if ($$.expression.type != TC_UNSUPPORTED) {
            $$.expression.type = TC_UINT; // Result of a comparison is a boolean-like integer.
        }
    }
    | expression error
    {
        specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;
    } // Error: Missing Comparison Operator
;

comparison_operator:
    EQUAL_OP
    | NOT_EQUAL_OP
    | GE_OP
    | LE_OP
    | '>'
    | '<'
;

// =================================== Expression ================================== //

expression:
    term
    {
        $$ = $1;
    }
    | expression
    {
        announceSpecificError(MISSING_EXPRESSION_OPERATOR);
    } // Error: Missing Expression Operator
    positive_term
    | '+' term
    {
        announceSpecificError(MISSING_LEFT_SUM_OPERAND);
    } // Error: Missing Left Operand
    | '+' error
    {
        specifySyntaxError(MISSING_BOTH_SUM_OPERANDS);
        yyerrok;
    } // Error: Missing Both Operands
    | expression '+' term
    {
        $$.expression.representation = $1.expression.representation + " + " + $3.expression.representation;
        $$.expression.type = CHK_TYPES.check($1.expression, $3.expression);
    }
    | expression '+' error
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    } // Error: Missing Right Operand
    | expression '-' term
    {
        $$.expression.representation = $1.expression.representation + " - " + $3.expression.representation;
        $$.expression.type = CHK_TYPES.check($1.expression, $3.expression);
    }
    | expression '-' error
    {
        specifySyntaxError(MISSING_RIGHT_OPERAND);
        yyerrok;
    } // Error: Missing Right Operand
    | trunc_expression
    | expression '+' trunc_expression
    | expression '-' trunc_expression
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
        $$.expression.representation = $1.expression.representation + " * " + $3.expression.representation;
        $$.expression.type = CHK_TYPES.check($1.expression, $3.expression);
    }
    | positive_term '/' factor
    {
        $$.expression.representation = $1.expression.representation + " / " + $3.expression.representation;
        $$.expression.type = CHK_TYPES.check($1.expression, $3.expression);
    }
    | positive_factor
    | positive_term '*' error
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    } // Error: Missing Right Factor
    | positive_term '/' error
    {
        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    } // Error: Missing Right Factor
;

negative_term:
    negative_term '*' factor
    {
        $$.expression.representation = $1.expression.representation + " * " + $3.expression.representation;
        $$.expression.type = CHK_TYPES.check($1.expression, $3.expression);
    }
    | negative_term '/' factor
    {
        $$.expression.representation = $1.expression.representation + " / " + $3.expression.representation;
        $$.expression.type = CHK_TYPES.check($1.expression, $3.expression);
    }
    | negative_factor
    {
        $$ = $1;
    }
    | negative_term '*' error
    {
        $$ = $1;

        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    } // Error: Missing Right Factor
    | negative_term '/' error
    {
        $$ = $1;

        specifySyntaxError(MISSING_RIGHT_FACTOR);
        yyerrok;
    } // Error: Missing Right Factor
    | '*' factor
    {
        $$ = $2;

        announceSpecificError(MISSING_LEFT_MUL_FACTOR);
    } // Error: Missing Left Factor
    | '/' factor
    {
        $$ = $2;

        announceSpecificError(MISSING_LEFT_DIV_FACTOR);
    } // Error: Missing Left Factor
    | '*' error
    {
        $$.reference.type = NOTHING;
        $$.expression.type = TC_UNSUPPORTED;

        specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;
    } // Error: Missing Left and Right Factor
    | '/' error
    {
        $$.reference.type = NOTHING;
        $$.expression.type = TC_UNSUPPORTED;

        specifySyntaxError(MISSING_BOTH_FACTORS);
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
        $$.expression.representation = CURRENT_VARIABLE.name;
        $$.reference.sref = checkVariableExistanceInScope();
        loadSymbolMetadata($$);
    } // Action: checkVariableExistanceInScope()
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
        $$.reference.type  = NOTHING;
        $$.expression.type = TC_UNSUPPORTED;
        
        announceSpecificError(INVALID_LAMBDA_USE);
    } // Error: Invalid Lambda Use
    | '-' UINTEGER_LITERAL
    {
        $$.reference.type  = LITERAL;
        $$.reference.lref  = $2;
        $$.expression.type = TC_UINT;
        $$.expression.representation = $2->constant;

        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    } // Error: Missing Left Operand
    | '-' function_invocation_head
    {
        $$ = $2;

        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    } // Error: Missing Left Operand
    | '-' variable
    {
        $$.expression.representation = CURRENT_VARIABLE.name;
        $$.reference.sref = checkVariableExistanceInScope();
        loadSymbolMetadata($$);

        announceSpecificError(MISSING_LEFT_SUB_OPERAND);
    } // Action: checkVariableExistanceInScope() + Error: Missing Left Operand
    | '-' lambda_invocation_head
    {
        $$.reference.type = NOTHING;
        $$.expression.type = TC_UNSUPPORTED;

        announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        announceSpecificError(INVALID_LAMBDA_USE);
    } // Error: Missing Both Operands
    | '-' error
    {
        $$.reference.type  = NOTHING;
        $$.expression.type = TC_UNSUPPORTED;

        specifySyntaxError(MISSING_BOTH_SUB_OPERANDS);
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
        $$.reference.type = LITERAL;
        $$.reference.lref = $1;
        $$.expression.type = TC_UINT;
        $$.expression.representation = $$.reference.lref->constant;
    }
    | FLOAT_LITERAL
    {
        $$.reference.type = LITERAL;
        $$.reference.lref = $1;
        $$.expression.type = TC_FLOAT;
        $$.expression.representation = $$.reference.lref->constant;
    }
;

negative_constant:
    '-' FLOAT_LITERAL
    {
        $$.reference.type = LITERAL;
        $$.reference.lref = turnNegative($2);
        $$.expression.type = TC_FLOAT;
        $$.expression.representation = $$.reference.lref->constant;
    } // Action: turnNegative()
;

// ==================================== Variable =================================== //

variable:
    IDENTIFIER
    {
        CURRENT_VARIABLE.prefix.clear();
        CURRENT_VARIABLE.name = $1->symbol;
    } // Build: Variable Name
    | variable '.' IDENTIFIER
    {
        CURRENT_VARIABLE.prefix.append(":").append(CURRENT_VARIABLE.name);
        CURRENT_VARIABLE.name = $3->symbol;
    } // Build: Variable Prefix
;

%% // Codes ------------------------------------------

void yyerror(const char* s)
{
    announceSyntaxError();
}

void loadSymbolMetadata(Metadata& m)
{
    if (m.reference.lref == nullptr)
    {
        m.reference.type = NOTHING;
        m.expression.type = TC_UNSUPPORTED;
    }
    else
    {
        m.reference.type = SYMBOL;
        switch (m.reference.lref->type)
        {
        case ST_UINT:
            m.expression.type = TC_UINT;
            break;
        case ST_FLOAT:
            m.expression.type = TC_FLOAT;
            break;
        default:
            m.expression.type = TC_UNSUPPORTED;
        }
    }
}