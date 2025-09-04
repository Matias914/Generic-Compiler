#ifndef TPE_FILEREADER_H
#define TPE_FILEREADER_H

#include <fstream>

/*
 * @brief es un lector de archivos
 *
 * Lee caracter a caracter del archivo especificado. Incrementando
 * el contador de líneas.
 *
 */
class FileReader
{
public:
    // Lleva en cuenta el número de línea y sigue la convencion de Flex
    unsigned int yylineno;

    FileReader();

    void set(const char* filename);
    bool get(char& c);
    void unget();

private:
    std::ifstream file;
};

#endif //TPE_FILEREADER_H