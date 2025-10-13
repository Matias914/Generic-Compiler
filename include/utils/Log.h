#ifndef GC_LOG_H
#define GC_LOG_H

#include <string>
#include <vector>

/*
 * @brief es un DTO utilizado para la comunicacion entre
 * las etapas de la compilación y los handlers.
 *
 * Type: indica el tipo de log (error, warning, log de token, etc.).
 * Code: una especialización de 'type' que da más detalle.
 * Line: número de línea.
 * Content: sirve para pasar parámetros e información de utilidad.
 */
struct Log
{
    int type;
    int code;
    unsigned int line;
    std::vector<std::string> content;

    // Util para los tests
    bool operator==(const Log& other) const {
        return type == other.type
            && code == other.code
            && line == other.line
            && content == other.content;
    }
};

#endif //GC_LOG_H