#include "lexical-analyzer/FileReader.h"

FileReader::FileReader()
{
    // Todavia no hay archivo
    yylineno = 0;
}

void FileReader::set(const char* filename)
{
    file = std::ifstream(filename);
    if (!file) {
        throw std::runtime_error("\nError al abrir el archivo");
    }
    yylineno = 1;
}

/*
 * @brief lee el proximo caracter del archivo y avanza el puntero del mismo.
 * Devuelve un boolean que indica si se leyo EOF.
 *
 */
bool FileReader::get(char& c)
{
    const bool valid = static_cast<bool>(file.get(c));
    if (valid && c == '\n')
        yylineno++;
    return valid;
}

/*
 * @brief mueve la posicion del puntero del archivo un caracter hacia atras,
 * restando el número de línea si es que se trataba de un salto de línea.
 *
 */
void FileReader::unget()
{
    bool valid = static_cast<bool>(file.unget());
    if (!valid)
    {
        file.clear();
        valid = static_cast<bool>(file.unget());
    }
    if (valid && file.peek() == '\n')
        yylineno--;
}
