#ifndef TPE_ERRORHANDLER_H
#define TPE_ERRORHANDLER_H

#include "Log.h"
#include "resources/builders.h"

#include <list>

class ErrorHandler
{
public:
    ErrorHandler();

    void add(const Log& log);

    int errorCount() const;
    int warningCount() const;

    const Log* getLastestLog() const;

    std::string getLogs() const;

private:
    std::list<Log> logs;
    int error_count;

    friend class ErrorBuffer;
};


#endif //TPE_ERRORHANDLER_H