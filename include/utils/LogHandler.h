#ifndef TPE_LOGHANDLER_H
#define TPE_LOGHANDLER_H

#include "utils/Log.h"

#include <list>
#include <fstream>

const std::string output = "../examples/output.txt";

class LogHandler
{
public:
    void add(const Log& log);

    bool generateReport() const;
private:
    std::list<Log> logs;
};

#endif //TPE_LOGHANDLER_H