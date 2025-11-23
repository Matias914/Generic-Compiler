// Importa los archivos necesarios para el Header
%code requires
{
    #include "utils/SymbolTable.h"
    #include "utils/LiteralTable.h"

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

#include "utils/resources/codes.h"
#include "code-generator/code-generator.h"
#include "lexical-analyzer/lexical_analyzer.h"
#include "semantic-analyzer/semantic_analyzer.h"

#include <stack>
#include <iostream>

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

%token INVALID_RWORD
%token INVALID_TOKEN
%token WORD_IF
%token WORD_ELSE
%token WORD_ENDIF
%token WORD_DO
%token WORD_WHILE
%token WORD_RETURN
%token WORD_PRINT
%token WORD_TRUNC
%token WORD_UINT
%token WORD_FLOAT
%token WORD_CR
%token OP_POINTER
%token OP_EQUAL
%token OP_GE
%token OP_LE
%token OP_ASSIGN
%token OP_NOT_EQUAL
%token <sref> IDENTIFIER
%token <lref> LITERAL_FLOAT
%token <lref> LITERAL_UINT
%token <lref> LITERAL_STRING

%start global

// For Functions
%type <returnable> program_statements program_statement executable_body executable_statements executable_stmt
%type <returnable> function_body do_while do_body if if_head condition_body_setup then_body_setup

// For Arithmetic Expressions
%type <metadata> lambda_real_parameter assignment_head assignment_tail function_invocation_head invocation_setup
%type <metadata> function_invocation_tail real_parameter_list real_parameter_list_setup real_parameter comparison
%type <metadata> opt_trunc_constant trunc_constant opt_trunc_variable trunc_variable expression expression_setup
%type <metadata> trunc_expression term positive_term negative_term factor positive_factor negative_factor
%type <metadata> numeric_constant positive_constant negative_constant condition
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
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, $2->symbol})
        );
        SemanticAnalyzer::CHK_FUNCTIONS.notifyFunctionName($2->symbol);

    } // Action: notifyFunctionName()
    function_declaration_middle
    | type '('
    {
        SemanticAnalyzer::CHK_RETURNS.bufferFunction(
            SemanticAnalyzer::ReturnChecker::Element({SemanticAnalyzer::TYPE, "...()"})
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
    WORD_UINT
    {
        SemanticAnalyzer::TYPE = UINT;
    } // Build: Current Type
    | WORD_FLOAT
    {
        SemanticAnalyzer::TYPE = FLOAT;
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
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration($2->symbol);

    } // Build: Current Semantic + Action: checkParameterDeclaration()
    | type error
    {
        SemanticActions::specifySyntaxError(MISSING_PARAMETER_NAME);
        yyerrok;

    } // Error: Missing Parameter Name
    | IDENTIFIER
    {
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CV);
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
        SemanticAnalyzer::TYPE = UNKNOWN;
        SemanticAnalyzer::CHK_FUNCTIONS.checkParameterDeclaration($2->symbol);
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_PARAMETER_TYPE);

    } // Action: checkParameterDeclaration() + Error: Missing Parameter Type
;

parameter_semantics:
    WORD_CR
    {
        SemanticAnalyzer::CHK_FUNCTIONS.notifyParameterSemantic(CR);

    } // Build: Current Semantic
;

// =================================== Function Body =============================== //

function_body:
    '{' program_statements '}'
    {
        $$ = $2;
    }
    | '{' '}'
    {
        $$ = false;
    }
    | '{' program_statements YYEOF
    {
        $$ = $2;

        SemanticActions::announceSpecificError(MISSING_CLOSING_BRACKET);

    } // Error: Missing Closing Bracket
;

// ====================================== Return =================================== //

return:
    WORD_RETURN '(' expression ')' ';'
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $3.expression.type, *StringPool::get($3.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                $3.expression.type,
                mapWithOperand($3.reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

    }
    | WORD_RETURN '(' expression ')' error
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $3.expression.type, *StringPool::get($3.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                $3.expression.type,
                mapWithOperand($3.reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
    | WORD_RETURN '(' expression error
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $3.expression.type, *StringPool::get($3.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                $3.expression.type,
                mapWithOperand($3.reference),
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Closing Parenthesis and Semicolon
    | WORD_RETURN expression ')'
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $2.expression.type, *StringPool::get($2.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                $2.expression.type,
                mapWithOperand($2.reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);

    } // Error: Missing Opening Parenthesis and Semicolon
    | WORD_RETURN expression error
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $2.expression.type, *StringPool::get($2.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                $2.expression.type,
                mapWithOperand($2.reference),
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_RETURN);
        SemanticActions::announceSpecificError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Both Parenthesis and Semicolon
    | WORD_RETURN '(' expression ';'
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $3.expression.type, *StringPool::get($3.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                $3.expression.type, 
                mapWithOperand($3.reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::announceSpecificError(MISSING_CLOSING_PARENTHESIS);

    } // Error: Missing Closing Parenthesis
    | WORD_RETURN expression ')' ';'
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $2.expression.type, *StringPool::get($2.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET, 
                $2.expression.type,
                mapWithOperand($2.reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    } // Error: Missing Opening Parenthesis
    | WORD_RETURN expression ';'
    {
        SemanticAnalyzer::ReturnChecker::Element e = { $2.expression.type, *StringPool::get($2.expression.pid) };
        SemanticAnalyzer::CHK_RETURNS.checkReturnWithBuffered(e);

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_RET,
                $2.expression.type, 
                mapWithOperand($2.reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) 
            });

        SemanticActions::announceSpecificError(MISSING_BOTH_PARENTHESIS_RETURN);

    } // Error: Missing Both Parenthesis
    | WORD_RETURN error ';'
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
            SemanticAnalyzer::TypeChecker::Expression e1 = {
                $1.expression.type,
                *StringPool::get($1.expression.pid),
                $1.expression.assignable
            };
            SemanticAnalyzer::TypeChecker::Expression e2 = {
                $2.expression.type,
                *StringPool::get($2.expression.pid),
                $2.expression.assignable
            };

            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_ASSIGN,
                SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2),
                mapWithOperand($1.reference),
                mapWithOperand($2.reference)
            });
        }
    }
    | variable OP_ASSIGN error ';'
    {
        SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        yyerrok;

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope() + Error: General Error
;

assignment_head:
    variable OP_ASSIGN
    {
        $$.reference.sref = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if ($$.reference.sref != nullptr)
        {
            $$.reference.type = SYMBOL;
            $$.expression = { $$.reference.sref->type, $1, true };
        }
        else
        {
            $$.reference.type = NULLREF;
            $$.expression = { UNKNOWN, $1, false };
        }
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
    WORD_PRINT '(' LITERAL_STRING ')' ';'
    {
        SemanticActions::logStructure("PRINT");

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT, 
                STRING,
                CodeGenerator::Triples::Operand({ LITERAL, { .lref = $3 } }), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

    } // Log  : Print Structure
    | WORD_PRINT '(' LITERAL_STRING ')' error
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT, 
                STRING,
                CodeGenerator::Triples::Operand({ LITERAL, { .lref = $3 } }), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    } // Error: Missing Semicolon
    | WORD_PRINT '(' expression ')' ';'
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT, 
                $3.expression.type,
                mapWithOperand($3.reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::logStructure("PRINT");

    } // Log  : Print
    | WORD_PRINT '(' expression ')' error
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_PRINT,
                $3.expression.type, 
                mapWithOperand($3.reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr })
            });

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
    | WORD_PRINT '(' error ')'
    {
        SemanticActions::specifySyntaxError(MISSING_ARGUMENT);
        yyerrok;

    } // Error: Missing Argument
    print_end
    | WORD_PRINT error ';'
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
    | left_variable assignment_list assignment_end
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

left_variable:
    /* empty */
    {
        SemanticActions::announceSpecificErrorWithSymbol(MISSING_COMMA);
    } // Error: Missing Comma
    variable
; // HOW WORKS THIS SHI ????

extra_numeric_constants:
    ',' opt_trunc_constant
    | /* empty */
    {
        SemanticActions::announceSpecificError(MISSING_COMMA);
    } // Error: Missing Comma
    opt_trunc_constant
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

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr && $1.reference.type != NULLREF)
        {
            $$.reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple ({ 
                CODEOP_CALL, 
                $1.expression.type,
                mapWithOperand($1.reference), 
                CodeGenerator::Triples::Operand({ NULLREF, nullptr }) }
            );
            CodeGenerator::INTERMEDIATE_CODE->commit();
            $$.reference.type = TRIPLE;
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
            $$.reference.type = SYMBOL;
            $$.expression.type = $$.reference.sref->type;
        }
        else
        {
            $$.reference.type = NULLREF;
            $$.expression.type = UNKNOWN;
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
            $$.reference.type = SYMBOL;
            $$.expression.type = $$.reference.sref->type;
        }
        else
        {
            $$.reference.type = NULLREF;
            $$.expression.type = UNKNOWN;
        }
    }
;

function_invocation_tail:
    real_parameter_list ')'
    {
        StringPool::append($1.expression.pid, ")");
        $$.expression.type = UNKNOWN;
        $$.expression.pid = $1.expression.pid;

        SemanticAnalyzer::CHK_INVOCATIONS.notifyInvocationEnd();
    }
    | ')'
    {
        $$.expression = { UNKNOWN, StringPool::create(")") };

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
        $$.expression.type = UNKNOWN;
        $$.expression.pid = $1.expression.pid;
    }
    | real_parameter_list_setup real_parameter
    {
        StringPool::append($1.expression.pid, " " + *StringPool::get($2.expression.pid));
        $$.expression.type = UNKNOWN;
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
    expression OP_POINTER IDENTIFIER
    {
        auto entry = SemanticAnalyzer::CHK_INVOCATIONS.checkParameterInScope($3->symbol);
        if (entry != nullptr)
        {
            SemanticAnalyzer::TypeChecker::Expression e1 = {
                $1.expression.type,
                *StringPool::get($1.expression.pid),
                $1.expression.assignable
            };
            SemanticAnalyzer::TypeChecker::Expression e2 = { entry->semantics, $3->symbol, true };
            int result = SemanticAnalyzer::CHK_TYPES.checkSemantics(e1, e2);

            e2.type = entry->type;
            if (result == CR && CodeGenerator::INTERMEDIATE_CODE != nullptr)
            { 
                int typeCR = SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2);
                CodeGenerator::INTERMEDIATE_CODE->addBuffer ({
                    CODEOP_ASSIGN,
                    typeCR,
                    mapWithOperand($1.reference), 
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
                    mapWithOperand($1.reference) 
                });
            }
        }
        StringPool::append($1.expression.pid, "->" + $3->symbol);
        $$.expression = { UNKNOWN, $1.expression.pid, false };
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
    | executable_statements error
    {
        SemanticAnalyzer::removeScope();

        SemanticActions::specifySyntaxError(MISSING_BOTH_BRACKETS);
        yyerrok;

    } // Action: SemanticAnalyzer::addScope() + Error: Missing Both Brackets
;

lambda_invocation_tail:
    '(' lambda_real_parameter ')'
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
            e2 = { $2.expression.type, *StringPool::get($2.expression.pid), $2.expression.assignable };
            int type = SemanticAnalyzer::CHK_TYPES.checkAssignment(e1, e2);

            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_ASSIGN,
                type,
                o1,
                mapWithOperand($2.reference)
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

    } // Log : Lambda Structure
;

lambda_real_parameter:
    opt_trunc_variable   { $$ = $1; }
    | opt_trunc_constant { $$ = $1; }
;

// ======================================= If ====================================== //

if:
    if_word if_head ';'
    {
        $$ = $2;
    }
    | if_word if_head error
    {
        $$ = $2;

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;
    }
    | if_word error ';'
    {
        $$ = false;

        SemanticActions::specifySyntaxError(IF_SYNTAX_ERROR);
        yyerrok;

    } // Error: If General Error
    | if_word condition error ';'
    {
        $$ = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    } // Error: Missing Exutable Body and WORD_ENDIF in WORD_IF
    | if_word condition_body_setup WORD_ELSE error ';'
    {
        $$ = $2;

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

    } // Error: Missing Executable Body in WORD_ELSE and WORD_ENDIF
;

if_word:
    WORD_IF
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
;

if_head:
    condition_body_setup WORD_ENDIF
    {
        $$ = $1;

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

    } // Log  : If
    | condition_body_setup WORD_ELSE executable_body WORD_ENDIF
    {
        $$ = $1;

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

    } // Log  : If-Else
    | condition_body_setup error
    {
        $$ = $1;

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

    } // Error: Missing WORD_ENDIF in IF
    | condition_body_setup WORD_ELSE executable_body error
    {
        $$ = $1 || $3;

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

    } // Error: Missing WORD_ENDIF in IF-ELSE
    | condition error WORD_ENDIF
    {
        $$ = false;

        SemanticActions::specifySyntaxError(MISSING_IF_EXECUTABLE_BODY);
        yyerrok;

    } // Error: Missing Executable Body in IF
    | condition error WORD_ELSE WORD_ENDIF
    {
        $$ = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        yyerrok;

    } // Error: Missing Both Executable Body in IF-ELSE
    | condition error WORD_ELSE
    {
        $$ = false;

        SemanticActions::specifySyntaxError(MISSING_BOTH_EXECUTABLE_BODY);
        SemanticActions::announceSpecificError(MISSING_ENDIF);
        yyerrok;

    } // Error: Missing Both Executable Body and WORD_ENDIF in IF-ELSE
    | condition_body_setup WORD_ELSE error WORD_ENDIF
    {
        $$ = $1;

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

    } // Error: Missing Executable Body in WORD_ELSE
    | WORD_ELSE executable_body WORD_ENDIF
    {
        $$ = $2;

        SemanticActions::announceSpecificError(MISSING_IF_STATEMENT);

    } // Error: Missing IF Statement
    | condition_body_setup WORD_ELSE executable_body INVALID_RWORD
    {
        $$ = $1;

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
    } // Error: (Lexical) Invalid Endif
    | condition_body_setup INVALID_RWORD executable_body WORD_ENDIF
    {
        $$ = $1;

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
    } // Error: (Lexical) Invalid Else
    | condition_body_setup INVALID_RWORD executable_body INVALID_RWORD
    {
        $$ = $1;

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
    } // Error: (Lexical) Invalid Else and Endif
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
                CODEOP_BRANCH_FALSE,
                $1.expression.type,
                mapWithOperand($1.reference),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
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
;

// ==================================== Do-While =================================== //

do_while:
    do_while_head do_body
    {
        $$ = $2;
    }
    | WORD_DO
    {
        SemanticActions::announceSpecificError(MISSING_WHILE_EXECUTABLE_BODY);

    } // Error: Missing Executable Body
    WORD_WHILE do_while_tail
    {
        $$ = false;
    }
    | WORD_DO error ';'
    {
        $$ = false;

        SemanticActions::specifySyntaxError(DO_SYNTAX_ERROR);
        yyerrok;

    } // Error: Do-While General Error
;

do_while_head:
    WORD_DO
    {
        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            STACK.push(CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_DO_START,
                UNKNOWN,
                CodeGenerator::Triples::Operand({NULLREF, nullptr}),
                CodeGenerator::Triples::Operand({NULLREF, nullptr})
            }));
    }
;

do_body:
    executable_body WORD_WHILE condition ';'
    {
        $$ = $1;

        if (CodeGenerator::INTERMEDIATE_CODE != nullptr)
            CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                CODEOP_BRANCH_TRUE,
                $3.expression.type,
                mapWithOperand($3.reference),
                CodeGenerator::Triples::Operand({ TRIPLE, { .tref = STACK.top() }})
            });
        STACK.pop();

        SemanticActions::logStructure("DO-WHILE");

    } // Log  : WORD_DO-WORD_WHILE
    | executable_body WORD_WHILE condition error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_SEMICOLON);
        yyerrok;

    } // Error: Missing Semicolon
    | executable_body
    {
        SemanticActions::announceSpecificError(MISSING_WHILE);

    } // Error: Missing WORD_WHILE word
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
    | '{' '}'
    {
        $$ = false;
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
    WORD_TRUNC '(' numeric_constant ')'
    {
        createTruncateTriple($$, $3);

        $$.expression.pid = StringPool::create("trunc(" + *StringPool::get($3.expression.pid) + ")");

    } // Action: truncable()
    | WORD_TRUNC '(' numeric_constant error
    {
        createTruncateTriple($$, $3);

        $$.expression.pid = StringPool::create("trunc(" + *StringPool::get($3.expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    } // Action: truncable() + Error: Missing Closing Parenthesis
    | WORD_TRUNC numeric_constant ')'
    {
        createTruncateTriple($$, $2);

        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($2.expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    } // Action: truncable() + Error: Missing Opening Parenthesis
    | WORD_TRUNC numeric_constant error
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
            $$.reference.type = SYMBOL;
            $$.expression = { $$.reference.sref->type, $1, true };
        }
        else
        {
            $$.reference.type = NULLREF;
            $$.expression = { UNKNOWN, $1, true };
        }

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope()
    | trunc_variable
    {
        $$ = $1;
    }
;

trunc_variable:
    WORD_TRUNC '(' variable ')'
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, $3, true };
            
            createTruncateTriple($$, m);
        }
        else
        {
            $$.reference  = { NULLREF, nullptr };
            $$.expression.type = UNKNOWN;
            $$.expression.assignable = false;
        }
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($3) + ")");

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope()
    | WORD_TRUNC '(' variable error
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        {
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, $3, true };
            
            createTruncateTriple($$, m);
        }
        else
        {
            $$.reference  = { NULLREF, nullptr };
            $$.expression.type = UNKNOWN;
            $$.expression.assignable = false;
        }
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($3) + ")");

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope() + Error: Missing Closing Parenthesis
    | WORD_TRUNC variable ')'
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        { 
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, $2, true };
            
            createTruncateTriple($$, m);

        }
        else
        {
            $$.reference  = { NULLREF, nullptr };
            $$.expression.type = UNKNOWN;
            $$.expression.assignable = false;
        }
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($2) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope() + Error: Missing Opening Parenthesis
    | WORD_TRUNC variable error
    {
        auto entry = SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope();
        if (entry != nullptr)
        { 
            Metadata m;
            m.reference  = { SYMBOL, entry };
            m.expression = { entry->type, $2, true };
            
            createTruncateTriple($$, m);
        }
        else
        {
            $$.reference  = { NULLREF, nullptr };
            $$.expression.type = UNKNOWN;
            $$.expression.assignable = false;
        }
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($2) + ")");

        SemanticActions::specifySyntaxError(MISSING_BOTH_PARENTHESIS_TRUNC);
        yyerrok;

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope() + Error: Missing Both Parenthesis
    | WORD_TRUNC error ';'
    {
        $$.reference  = { NULLREF , nullptr };
        $$.expression = { UNKNOWN, StringPool::create("trunc ..."), false };

        SemanticActions::specifySyntaxError(TRUNC_SYNTAX_ERROR);
        yyerrok;

    } // Error: Trunc General Error
;

trunc_expression:
    WORD_TRUNC '(' expression ')'
    {
        createTruncateTriple($$, $3);
        
        $$.expression.pid = StringPool::create("trunc(" + *StringPool::get($3.expression.pid) + ")");
    }
    | WORD_TRUNC '(' expression error
    {
        createTruncateTriple($$, $3);
        
        $$.expression.pid = StringPool::create("trunc(" + *StringPool::get($3.expression.pid));

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    } // Error: Missing Closing Parenthesis
    | WORD_TRUNC expression ')'
    {
        createTruncateTriple($$, $2);
        
        $$.expression.pid = StringPool::create("trunc " + *StringPool::get($2.expression.pid) + ")");

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    } // Error: Missing Opening Parenthesis
    | WORD_TRUNC expression error
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
    {
        $$ = $2;
    }
    | '(' comparison error
    {
        $$ = $2;

        SemanticActions::specifySyntaxError(MISSING_CLOSING_PARENTHESIS);
        yyerrok;

    } // Error: Missing Closing Parenthesis
    | comparison ')'
    {
        $$ = $1;

        SemanticActions::announceSpecificError(MISSING_OPENING_PARENTHESIS);

    } // Error: Missing Opening Parenthesis
    | comparison error
    {
        $$ = $1;

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
            $$.reference.tref = CodeGenerator::INTERMEDIATE_CODE->addTriple ({
                $2.tid,
                $$.expression.type,
                mapWithOperand($1.reference),
                mapWithOperand($3.reference)
            });
            $$.reference.type = TRIPLE;
        }
        else
            $$.reference = { NULLREF, nullptr };
        $$.expression.assignable = false;
    }
    | expression error
    {
        $$ = $1;

        SemanticActions::specifySyntaxError(MISSING_COMPARISON_OPERATOR);
        yyerrok;

    } // Error: Missing Comparison Operator
    | expression comparison_operator error
    {
        yyerrok;
    }
;

comparison_operator:
    OP_EQUAL
    {
        $$ = { CODEOP_EQUAL, StringPool::create(Translator::translate(OP_EQUAL)) };
    }
    | OP_NOT_EQUAL
    {
        $$ = { CODEOP_NOT_EQUAL, StringPool::create(Translator::translate(OP_NOT_EQUAL)) };
    }
    | OP_GE
    {
        $$ = { CODEOP_GE, StringPool::create(Translator::translate(OP_GE)) };
    }
    | OP_LE
    {
        $$ = { CODEOP_LE, StringPool::create(Translator::translate(OP_LE)) };
    }
    | '>'
    {
        $$ = { CODEOP_GT, StringPool::create(">") };
    }
    | '<'
    {
        $$ = { CODEOP_LT, StringPool::create("<") };
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
        $$.reference  = { NULLREF , nullptr };
        $$.expression = { UNKNOWN, StringPool::create("..."), false };

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
        $$.reference  = { NULLREF , nullptr };
        $$.expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::specifySyntaxError(MISSING_BOTH_FACTORS);
        yyerrok;

    } // Error: Missing Left and Right Factor
    | '/' error
    {
        $$.reference  = { NULLREF , nullptr };
        $$.expression = { UNKNOWN, StringPool::create("..."), false };

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
            $$.reference.type = SYMBOL;
            $$.expression = { $$.reference.sref->type, $1, true };
        }
        else
        {
            $$.reference.type = NULLREF;
            $$.expression = { UNKNOWN, $1, true };
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
        $$.reference  = { NULLREF , nullptr };
        $$.expression = { UNKNOWN, StringPool::create("..."), false };
        
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);
    } // Error: Invalid Lambda Use
    | '-' LITERAL_UINT
    {
        $$.reference  = { LITERAL, .lref = $2 };
        $$.expression = { UINT, StringPool::create($2->constant), false };

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
            $$.reference.type = SYMBOL;
            $$.expression = { $$.reference.sref->type, $2, false };
        }
        else
        {
            $$.reference = { NULLREF, nullptr };
            $$.expression = { UNKNOWN, $2, false };
        }
        SemanticActions::announceSpecificError(MISSING_LEFT_SUB_OPERAND);

    } // Action: SemanticAnalyzer::CHK_VARIABLES.checkVariableExistanceInScope() + Error: Missing Left Operand
    | '-' lambda_invocation_head
    {
        $$.reference  = { NULLREF , nullptr };
        $$.expression = { UNKNOWN, StringPool::create("..."), false };

        SemanticActions::announceSpecificError(MISSING_BOTH_SUB_OPERANDS);
        SemanticActions::announceSpecificError(INVALID_LAMBDA_USE);

    } // Error: Missing Both Operands
    | '-' error
    {
        $$.reference  = { NULLREF , nullptr };
        $$.expression = { UNKNOWN, StringPool::create("..."), false };

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
    LITERAL_UINT
    {
        $$.reference  = { LITERAL, .lref = $1 };
        $$.expression = { UINT, StringPool::create($1->constant), false };
    }
    | LITERAL_FLOAT
    {
        $$.reference  = { LITERAL, .lref = $1 };
        $$.expression = { FLOAT, StringPool::create($1->constant), false };
    }
;

negative_constant:
    '-' LITERAL_FLOAT
    {
        $$.reference  = { LITERAL , .lref = SemanticActions::turnNegative($2) };
        $$.expression = { FLOAT, StringPool::create($2->constant), false };

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