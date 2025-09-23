cmake_minimum_required(VERSION 3.22.1)
project(TPE)

set(CMAKE_CXX_STANDARD 17)

# Directorios de includes
include_directories(src)
include_directories(include)

# Ejecutable principal
add_executable(TPE
        src/main.cpp
        src/utils/SymbolTable.cpp
        src/utils/LiteralTable.cpp
        src/utils/ErrorHandler.cpp
        src/syntax-analyzer/Parser.cpp
        src/lexical-analyzer/lexical_analyzer.cpp
        src/lexical-analyzer/components/traps.cpp
        src/lexical-analyzer/components/states.cpp
        src/lexical-analyzer/components/translator.cpp
        src/lexical-analyzer/components/StateMachine.cpp
        src/lexical-analyzer/components/reserved_words.cpp
        src/lexical-analyzer/components/semantic_actions.cpp
        src/utils/handler-resources/message_builder.cpp
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
add_executable(my_tests
        src/utils/SymbolTable.cpp
        src/utils/LiteralTable.cpp
        src/utils/ErrorHandler.cpp
        src/syntax-analyzer/Parser.cpp
        src/lexical-analyzer/lexical_analyzer.cpp
        src/lexical-analyzer/components/traps.cpp
        src/lexical-analyzer/components/states.cpp
        src/lexical-analyzer/components/translator.cpp
        src/lexical-analyzer/components/StateMachine.cpp
        src/lexical-analyzer/components/reserved_words.cpp
        src/lexical-analyzer/components/semantic_actions.cpp
        tests/unit/utils/SymbolTable_test.cpp
        tests/unit/utils/ErrorHandler_test.cpp
        tests/unit/utils/LiteralTable_test.cpp
        tests/unit/lexical-analyzer/lexical_analyzer_test.cpp
        tests/unit/lexical-analyzer/components/states_test.cpp
        tests/unit/lexical-analyzer/components/translator_test.cpp
        tests/unit/lexical-analyzer/components/semantic_actions_test.cpp
        include/lexical-analyzer/components/mapping.h
        src/utils/handler-resources/message_builder.cpp
        # Agrega otros archivos de test aquí, si los tienes
)

# Vincular las bibliotecas necesarias. GTest::gtest y GTest::gtest_main
# son targets definidos automáticamente por el proceso de FetchContent.
target_link_libraries(my_tests
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        pthread  # Sigue siendo necesario para la ejecución de tests multihilo
)

# Descubrir y registrar los tests para CTest/CLion
# Esto le dice a CLion que el ejecutable 'my_tests' contiene tests.
include(GoogleTest)
gtest_discover_tests(my_tests)