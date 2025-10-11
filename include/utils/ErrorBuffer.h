#ifndef TPE_ERRORBUFFER_H
#define TPE_ERRORBUFFER_H

#include "Log.h"
#include "ErrorHandler.h"

class ErrorBuffer
{
public:
    explicit ErrorBuffer(ErrorHandler* handler);

    bool buffer(const Log& log);
    bool commit();

    Log* get();

private:
    Log buffered;
    bool ocupied;

    ErrorHandler* handler;
    std::_List_iterator<Log> position;
};


#endif //TPE_ERRORBUFFER_H