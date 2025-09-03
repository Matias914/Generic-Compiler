#include "lexical-analyzer/FileReader.h"

FileReader::FileReader()
{
    yylineno = 1;
}

void FileReader::set(const char* filename)
{
    file = std::ifstream(filename);
    if (!file) {
        throw std::runtime_error("\nError al abrir el archivo");
    }
}

// Devuelve False si la operacion no fue exitosa.
bool FileReader::get(char& c)
{
    const bool valid = static_cast<bool>(file.get(c));
    if (valid && c == '\n')
        yylineno++;
    return valid;
}
