cmake_minimum_required(VERSION 3.22.1)
project(TPE)

set(CMAKE_CXX_STANDARD 14)

# Directorios de includes
include_directories(src)
include_directories(include)

# Ejecutable principal
add_executable(TPE
        src/main.cpp
        src/files/FileReader.cpp
        src/lexical-analyzer/state-machine/States.cpp
        src/lexical-analyzer/translator/Translator.cpp
        src/tables/SymbolTable.cpp
        src/lexical-analyzer/LexicalAnalyzer.cpp
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
        src/files/FileReader.cpp
        src/lexical-analyzer/translator/Translator.cpp
        tests/files/TestFileReader.cpp
        tests/translator/TestTranslator.cpp
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