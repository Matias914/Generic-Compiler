#ifndef GC_ERRORHANDLER_H
#define GC_ERRORHANDLER_H

#include <list>

#include "Log.h"

/*
 * @brief maneja logs relacionados con los Errores y Warnings
 *
 * Mantiene una colección de Logs. Estos podrían tratarse de un
 * error o warning. Debe también manejar la salida generada, aunque
 * no conoce los detalles de Impresion. Se divide en una subclase
 * ErrorBuffer que maneja el buffering de errores necesario para
 * tratar ciertos errores sintacticos.
 */
class ErrorHandler
{
public:
    ErrorHandler();

    void add(const Log& log);

    int errorCount() const;
    int warningCount() const;

    const Log* getLastestLog() const;

    std::string getLogs() const;

    // Útiles para Testing
    void clear();
    bool contains(const Log& log);

private:
    std::list<Log> logs;
    int error_count;

    // ErrorBuffer no es mas que una extension de ErrorHandler
    friend class ErrorBuffer;
};


#endif //GC_ERRORHANDLER_H