cmake_minimum_required(VERSION 3.22.1)
project(gc)

set(CMAKE_CXX_STANDARD 17)

# Directorios de includes
include_directories(src)
include_directories(include)

# Ejecutable principal
add_executable(gc
        src/main.cpp
        # Utils
        src/utils/ErrorBuffer.cpp
        src/utils/SymbolTable.cpp
        src/utils/LiteralTable.cpp
        src/utils/ReportHandler.cpp
        src/utils/ErrorHandler.cpp
        src/utils/resources/dispatcher.cpp
        src/utils/resources/string_table_builders.cpp
        src/utils/resources/string_error_builders.cpp
        src/utils/resources/string_report_builders.cpp
        # Syntax Analyzer
        src/syntax-analyzer/syntax_analyzer.cpp
        src/syntax-analyzer/components/parser.cpp
        src/syntax-analyzer/components/translator.cpp
        src/syntax-analyzer/components/semantic_actions.cpp
        # Lexical Analyzer
        src/lexical-analyzer/lexical_analyzer.cpp
        src/lexical-analyzer/components/traps.cpp
        src/lexical-analyzer/components/states.cpp
        src/lexical-analyzer/components/translator.cpp
        src/lexical-analyzer/components/StateMachine.cpp
        src/lexical-analyzer/components/reserved_words.cpp
        src/lexical-analyzer/components/semantic_actions.cpp
        src/syntax-analyzer/components/traps.cpp
        src/intermediate-code/Triples.cpp
        src/semantic-analyzer/semantic_analyzer.cpp
        src/semantic-analyzer/functions.cpp
        src/semantic-analyzer/variables.cpp
        src/semantic-analyzer/programs.cpp
        src/semantic-analyzer/components/CoertionChecker.cpp
        include/semantic-analyzer/components/CoertionChecker.h
)

# =========================================================
# === CONFIGURACIÓN DE TESTING CON FETCHCONTENT
# =========================================================

# Habilitar la funcionalidad de testing
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

# Definir un ejecutable para tus tests
add_executable(gc_tests
        tests/main_tests.cpp
        # Utils
        src/utils/ErrorBuffer.cpp
        src/utils/SymbolTable.cpp
        src/utils/LiteralTable.cpp
        src/utils/ReportHandler.cpp
        src/utils/ErrorHandler.cpp
        src/utils/resources/dispatcher.cpp
        src/utils/resources/string_table_builders.cpp
        src/utils/resources/string_error_builders.cpp
        src/utils/resources/string_report_builders.cpp
        # Syntax Analyzer
        src/syntax-analyzer/syntax_analyzer.cpp
        src/syntax-analyzer/components/traps.cpp
        src/syntax-analyzer/components/parser.cpp
        src/syntax-analyzer/components/translator.cpp
        src/syntax-analyzer/components/semantic_actions.cpp
        # Lexical Analyzer
        src/lexical-analyzer/lexical_analyzer.cpp
        src/lexical-analyzer/components/traps.cpp
        src/lexical-analyzer/components/states.cpp
        src/lexical-analyzer/components/translator.cpp
        src/lexical-analyzer/components/StateMachine.cpp
        src/lexical-analyzer/components/reserved_words.cpp
        src/lexical-analyzer/components/semantic_actions.cpp
        #
        src/semantic-analyzer/semantic_analyzer.cpp
        # Tests
        tests/unit/utils/SymbolTable_test.cpp
        tests/unit/lexical-analyzer/fixture/TestLexicalAnalyzer.cpp
        tests/unit/lexical-analyzer/test-cases/numeric_constants_test.cpp
        tests/unit/lexical-analyzer/test-cases/reserved_words_test.cpp
        tests/unit/lexical-analyzer/test-cases/comments_test.cpp
        tests/unit/lexical-analyzer/test-cases/string_literals_test.cpp
        tests/unit/lexical-analyzer/components/states_test.cpp
        tests/unit/lexical-analyzer/components/semantic_actions_test.cpp
        tests/unit/lexical-analyzer/components/translator_test.cpp
        tests/unit/lexical-analyzer/test-cases/identifiers_test.cpp
        tests/unit/lexical-analyzer/test-cases/special_characters_test.cpp
        tests/integration/parser-lexer/test-cases/do_while_test.cpp
        tests/integration/parser-lexer/fixture/TestParserLexer.cpp
        tests/integration/parser-lexer/fixture/TestParserLexer.h
        tests/integration/parser-lexer/test-cases/if_else_test.cpp
        tests/integration/parser-lexer/test-cases/expressions_test.cpp
        tests/integration/parser-lexer/test-cases/assignments_test.cpp
        tests/integration/parser-lexer/test-cases/declarations_test.cpp
        tests/integration/parser-lexer/test-cases/invocations_test.cpp
        tests/integration/parser-lexer/test-cases/programs_test.cpp
)

# Vincular las bibliotecas necesarias. GTest::gtest y GTest::gtest_main
# son targets definidos automáticamente por el proceso de FetchContent.
target_link_libraries(gc_tests
      PRIVATE
      GTest::gtest
)

# Enlazar pthread solo en sistemas tipo UNIX (Linux, etc.)
if(UNIX AND NOT APPLE)
    target_link_libraries(gc_tests PRIVATE pthread)
endif()

target_compile_definitions(gc_tests PRIVATE "SOURCE_PATH=\"${CMAKE_SOURCE_DIR}\"")

# Define un único test llamado "RunAllWithArgs".
# CTest ejecutará el comando: gc_tests --input=../
add_test(
        NAME RunAllWithArgs
        COMMAND gc_tests --input=../ --verbose=../outputs
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
