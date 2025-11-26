#include "gtest/gtest.h"
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <iostream>

#include "../integration/fixture/CompilerTest.h"

namespace fs = std::filesystem;

extern bool VERBOSE_OPTION;
extern std::string WORKING_DIRECTORY;

class EnvironmentTest : public ::testing::Test
{
protected:
    // Recibe un std::string y ejecuta el comando usando la utilidad std::system
    static int runCommand(const std::string& cmd) {
        return std::system(cmd.c_str());
    }

    // Bufferiza un archivo a un std::string usando ifstream
    static std::string readFile(const std::string& path) {
        std::ifstream t(path);
        if (!t.is_open()) return "";
        std::stringstream buffer;
        buffer << t.rdbuf();
        return buffer.str();
    }

    // Borra cualquier tipo de ruido del archivo para hacer una comparación justa
    static std::string normalize(std::string s) {
        s.erase(std::remove(s.begin(), s.end(), '\r'), s.end());
        s.erase(s.find_last_not_of(" \n\t") + 1);
        return s;
    }
};

TEST_F(EnvironmentTest, RunRuntimeCases)
{
    // Se ejecuta el comando que construye la imagen Docker
    const std::string buildCmd =
        "docker build -f " + WORKING_DIRECTORY + "/tests/environment/Dockerfile -t gc-test-env .";

    if (runCommand(buildCmd) != 0) {
        FAIL() << "Falló el 'docker build'.";
    }

    // Se crea una ruta que contiene los casos de prueba y otra que sirve para redirigir la salida de Docker
    const std::string filesDir = WORKING_DIRECTORY + "/tests/environment/files";
    const std::string tempOut  = WORKING_DIRECTORY + "/docker_temp.txt";

    if (!fs::exists(filesDir)) {
        std::cout << "\n[[ WARNING ]] No existe carpeta de casos: " << filesDir << "\n";
        FAIL() << "No existe carpeta de casos";
    }

    for (const auto& entry : fs::directory_iterator(filesDir)) {
        if (entry.path().extension() == ".txt") {

            // Por cada entrada del directorio de pruebas se guarda su nombre y se obtiene el archivo esperado
            // del mismo nombre
            const auto filename = entry.path().filename().string();
            std::filesystem::path expectedPath = entry.path();
            expectedPath.replace_extension(".expected");
            const auto expectedFile = expectedPath.string();

            // Archivos de posterior limpieza y generados durante el test (por el Script)
            std::filesystem::path watPath = entry.path();
            watPath.replace_extension(".wat");
            std::filesystem::path wasmPath = entry.path();
            wasmPath.replace_extension(".wasm");

            // Ruta relativa para Docker (dentro del contenedor /app)
            std::string relFilesPathInDocker  = "/app/tests/environment/files/" + filename;
            std::string relScriptPathInDocker = "/app/tests/environment/runner.sh";

            // Se crea comando que ejecuta el contenedor Docker redirigiendo la salida a un archivo temporal
            // (la salida de la ejecución). Se invoca bash explícitamente para evitar problemas de permisos
            // de ejecución en Windows
            std::string dockerCmd =
                "docker run --rm "
                "-v \"" + WORKING_DIRECTORY + ":/app\" "
                "gc-test-env "
                "bash -c \"sed -i 's/\\r$//' " + relScriptPathInDocker + " && "
                "bash " + relScriptPathInDocker + " " + relFilesPathInDocker + " &&" "\"";
            dockerCmd += " > \"" + tempOut + "\"";
            runCommand(dockerCmd);

            // Se lee el resultado del archivo temporal
            const std::string actual = readFile(tempOut);
            const std::string actualNorm = normalize(actual);

            // Se muestra el nombre del archivo de prueba y el contenido del archivo temporal
            std::cout << "---------------------------------------------------" << std::endl;
            std::cout << "[TEST] Archivo: " << filename << std::endl;
            std::cout << "[OUT ] Salida Real: " << actualNorm << std::endl;

            if (actualNorm == "SCRIPT_DETECTED_COMILATION_ERROR") {
                // Se elimina el archivo temporal de salida
                if (fs::exists(tempOut)) fs::remove(tempOut);
                FAIL() << "El compilador 'gc' falló al compilar " << filename;
            }
            if (actualNorm == "SCRIPT_DETECTED_WABT_ERROR") {
                // Se elimina el archivo temporal de salida
                if (fs::exists(tempOut)) fs::remove(tempOut);
                FAIL() << "El comando wat2wasm falló al ejecutarse " << filename;
            }

            // Se verifica que sean iguales (el temporal y el esperado)
            if (fs::exists(expectedFile)) {
                const std::string expected = readFile(expectedFile);
                const std::string expectedNorm = normalize(expected);
                EXPECT_EQ(actualNorm, expectedNorm) << "La salida no coincide con lo esperado.";
            } else {
                std::cout << "\n[[ WARNING ]] No hay archivo .expected. Verificación visual requerida.\n";
            }
            std::cout << "---------------------------------------------------" << std::endl;

            // Se limpian archivos generados
            if (!VERBOSE_OPTION)
            {
                if (fs::exists(watPath)) fs::remove(watPath);
                if (fs::exists(wasmPath)) fs::remove(wasmPath);
            }
        }
    }
    // Se elimina el archivo temporal de salida
    if (fs::exists(tempOut)) fs::remove(tempOut);

    // Se borra directorio build
    std::string cleanupCmd =
        "docker run --rm "
        "-v \"" + WORKING_DIRECTORY + ":/app\" "
        "gc-test-env "
        "rm -rf /app/build";
    runCommand(cleanupCmd);
}