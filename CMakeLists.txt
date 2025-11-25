cmake_minimum_required(VERSION 3.22.1)
project(gc)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(include)
include_directories(vendor)

# =========================================================
# DEFINICIÓN DE FUENTES
# =========================================================

set(COMPILER_SOURCES
        # Utils
        src/utils/ErrorBuffer.cpp
        src/utils/SymbolTable.cpp
        src/utils/LiteralTable.cpp
        src/utils/ReportHandler.cpp
        src/utils/ErrorHandler.cpp
        src/utils/resources/CodeBuilders.cpp
        src/utils/resources/ErrorBuilders.cpp
        src/utils/resources/ReportBuilders.cpp
        src/utils/resources/TableBuilders.cpp
        src/utils/resources/TripleBuilders.cpp
        src/utils/resources/StringBuilderDispatcher.cpp
        # Syntax Analyzer
        src/syntax-analyzer/SyntaxAnalyzer.cpp
        src/syntax-analyzer/components/Traps.cpp
        src/syntax-analyzer/components/Parser.cpp
        src/syntax-analyzer/components/Translator.cpp
        src/syntax-analyzer/components/StringPool.cpp
        src/syntax-analyzer/components/SemanticActions.cpp
        # Lexical Analyzer
        src/lexical-analyzer/LexicalAnalyzer.cpp
        src/lexical-analyzer/components/Traps.cpp
        src/lexical-analyzer/components/States.cpp
        src/lexical-analyzer/components/Translator.cpp
        src/lexical-analyzer/components/StateMachine.cpp
        src/lexical-analyzer/components/ReservedWordsTable.cpp
        src/lexical-analyzer/components/SemanticActions.cpp
        # Semantic Analyzer
        src/semantic-analyzer/SemanticAnalyzer.cpp
        src/semantic-analyzer/components/TypeChecker.cpp
        src/semantic-analyzer/components/ReturnChecker.cpp
        src/semantic-analyzer/components/LambdaChecker.cpp
        src/semantic-analyzer/components/ProgramChecker.cpp
        src/semantic-analyzer/components/FunctionChecker.cpp
        src/semantic-analyzer/components/VariableChecker.cpp
        src/semantic-analyzer/components/InvocationChecker.cpp
        # Code Generation
        src/code-generator/CodeGenerator.cpp
        src/code-generator/components/Triples.cpp
        src/code-generator/components/wat-generation/WatTranslatator.cpp
        src/code-generator/components/wat-generation/WatSegmentGenerator.cpp
        src/code-generator/components/wat-generation/WatGlobalsGenerator.cpp
        src/code-generator/components/wat-generation/WatCodeBlockGenerator.cpp
        src/code-generator/components/wat-generation/builders/PrintBuilders.cpp
        src/code-generator/components/wat-generation/builders/AssignmentBuilders.cpp
        src/code-generator/components/wat-generation/builders/MulDivBuilders.cpp
        src/code-generator/components/wat-generation/builders/OperandBuilders.cpp
        src/code-generator/components/wat-generation/builders/AddSubBuilders.cpp
        src/code-generator/components/wat-generation/builders/ComparisonBuilders.cpp
        src/code-generator/components/wat-generation/builders/ControlBuilders.cpp
        src/code-generator/components/wat-generation/builders/CallRetBuilders.cpp
        src/code-generator/components/wat-generation/builders/CoertionsBuilders.cpp
)

set(TEST_SOURCES
        tests/main_tests.cpp
        src/utils/CompilerState.cpp
        # Fixtures
        tests/integration/fixture/CompilerTest.cpp
        tests/unit/lexical-analyzer/fixture/TestLexicalAnalyzer.cpp
        # Unit Tests
        tests/unit/utils/test_symbol_table.cpp
        tests/unit/lexical-analyzer/test-cases/lexical_test_numeric_constants.cpp
        tests/unit/lexical-analyzer/test-cases/lexical_test_reserved_words.cpp
        tests/unit/lexical-analyzer/test-cases/lexical_test_comments.cpp
        tests/unit/lexical-analyzer/test-cases/lexical_test_string_literals.cpp
        tests/unit/lexical-analyzer/components/test_states.cpp
        tests/unit/lexical-analyzer/components/test_semantic_actions.cpp
        tests/unit/lexical-analyzer/components/test_translator.cpp
        tests/unit/lexical-analyzer/test-cases/lexical_test_identifiers.cpp
        tests/unit/lexical-analyzer/test-cases/lexical_test_special_characters.cpp
        # Integration Tests
        tests/integration/parser-lexer/test-cases/syntax_test_do_while.cpp
        tests/integration/parser-lexer/test-cases/syntax_test_if_else.cpp
        tests/integration/parser-lexer/test-cases/syntax_test_expressions.cpp
        tests/integration/parser-lexer/test-cases/syntax_test_assignments.cpp
        tests/integration/parser-lexer/test-cases/syntax_test_declarations.cpp
        tests/integration/parser-lexer/test-cases/syntax_test_invocations.cpp
        tests/integration/parser-lexer/test-cases/syntax_test_programs.cpp
        tests/integration/semantic-analysis/test-cases/semantic_test_functions.cpp
        tests/integration/semantic-analysis/test-cases/semantic_test_variables.cpp
)

# =========================================================
# DEFINICIÓN DE EJECUTABLES
# =========================================================

add_executable(gc src/main.cpp ${COMPILER_SOURCES})
add_executable(gc_tests ${COMPILER_SOURCES} ${TEST_SOURCES})

# =========================================================
# CONFIGURACIÓN DE TESTING CON FETCHCONTENT
# =========================================================

enable_testing()

# Descargar y configurar Google Test usando FetchContent
# Esto es más robusto que find_package porque garantiza que la librería
# esté siempre disponible en cualquier entorno (incluyendo Docker).
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Vincular las bibliotecas necesarias. GTest::gtest y GTest::gtest_main
# son targets definidos automáticamente por el proceso de FetchContent.
target_link_libraries(gc_tests
      PRIVATE
      GTest::gtest
)

if(UNIX AND NOT APPLE)
    target_link_libraries(gc_tests PRIVATE pthread)
endif()

target_compile_definitions(gc_tests PRIVATE "SOURCE_PATH=\"${CMAKE_SOURCE_DIR}\"")

# Único test llamado "RunAllWithArgs".
# CTest ejecutará el comando: gc_tests --input=../
add_test(
        NAME RunAllWithArgs
        COMMAND gc_tests --input=../ --verbose=../outputs/tests
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
