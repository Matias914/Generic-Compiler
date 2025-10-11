#ifndef TPE_REPORTHANDLER_H
#define TPE_REPORTHANDLER_H

#include "utils/Log.h"

#include <list>
#include <fstream>

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
    explicit ReportHandler(const std::string& output);

    void add(const Log& log);
    void generateReport() const;

    bool validOutput() const;
    
private:
    std::string output;
    std::list<Log> logs;

    // Mantiene un registro del ultimo token utilizado
    std::list<Log>::iterator last_token;
};

#endif //TPE_REPORTHANDLER_H