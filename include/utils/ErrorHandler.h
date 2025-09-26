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
    bool updateLatestLog(const Log& log);

    int errorCount() const;
    int warningCount() const;

    const Log* getLastestLog() const;

    std::string getLogs() const;

private:
    std::list<Log> logs;
    int error_count;

    static std::string   createErrorMssg(const int& code, const std::vector<std::string>& content);
    static std::string createWarningMssg(const int& code, const std::vector<std::string>& content);
};


#endif //TPE_ERRORHANDLER_H