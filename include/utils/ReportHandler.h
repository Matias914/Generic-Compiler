#ifndef GC_REPORTHANDLER_H
#define GC_REPORTHANDLER_H

#include <fstream>
#include <list>

#include "utils/Log.h"

/*
 * @brief maneja logs relacionados con la opción de VERBOSE (reporte)
 *
 * Mantiene una colección de Logs separados por su tipo. Estos podrían
 * tratarse de un reporte de token o estructura. Debe también manejar
 * la salida generada.
 */
class ReportHandler
{
public:
    ReportHandler();

    void add(const Log& log);
    void setOutput(const std::string& output);
    void generateReport() const;

    bool validOutput() const;

    // Útiles para Testing
    void clear();
    bool contains(const Log& log);
    
private:
    std::string output;
    std::list<Log> logs;

    // Mantiene un registro del ultimo token utilizado
    std::list<Log>::iterator last_token;
};

#endif //GC_REPORTHANDLER_H