#ifndef TPE_LOGHANDLER_H
#define TPE_LOGHANDLER_H

#include "utils/Log.h"

#include <list>
#include <fstream>

class LogHandler
{
public:
    explicit LogHandler(const std::string& output);

    void add(const Log& log);
    void generateReport() const;

    bool validOutput() const;
private:
    std::string output;
    std::list<Log> logs;
};

#endif //TPE_LOGHANDLER_H