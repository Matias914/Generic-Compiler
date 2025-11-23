#ifndef GC_WASM_GENERATION_H
#define GC_WASM_GENERATION_H

#include <filesystem>
#include <iostream>
#include <string>

static void invokeWat2Wasm(const std::string& wat_path) {
    std::filesystem::path wasm_path_obj(wat_path);
    wasm_path_obj.replace_extension(".wasm");
    const std::string wasm_path = wasm_path_obj.string();
    const std::string command = "wat2wasm \"" + wat_path + "\" -o \"" + wasm_path + "\"";

    std::cout << "\n[[ INFO ]] Ejecutando comando: " << command;

    if (const int result = std::system(command.c_str()); result != 0)
    {
        std::cerr << "\n[[ WARNING ]] No se pudo ejecutar 'wat2wasm'. El código de error fue: " << result << std::endl;
    }
    else
    {
        std::cout << "\n[[ EXITO ]] Wasm generado en: " << wasm_path << std::endl;
    }
}

#endif //GC_WASM_GENERATION_H