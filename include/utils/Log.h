#ifndef TPE_LOG_H
#define TPE_LOG_H

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
};

#endif //TPE_LOG_H