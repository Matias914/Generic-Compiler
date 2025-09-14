#ifndef TPE_ERRORHANDLER_H
#define TPE_ERRORHANDLER_H

#include "handler-macros/error_codes.h"
#include "handler-macros/warning_codes.h"

#include <string>
#include <vector>

#define WARNING 0
#define ERROR   1

class ErrorHandler
{
public:
    struct Log
    {
        unsigned int type;
        unsigned int line;
        unsigned int code;
        std::vector<std::string> content;
    };
    ErrorHandler();

    void add(const Log& log);
    int errorCount() const;
    void showLogs() const;
    const Log& getLastestLog() const;

    [[noreturn]] static void fatal();

private:
    std::vector<Log> logs;
    int error_count;

    static std::string   createErrorMssg(const int& code, const std::vector<std::string>& content);
    static std::string createWarningMssg(const int& code, const std::vector<std::string>& content);
};


#endif //TPE_ERRORHANDLER_H