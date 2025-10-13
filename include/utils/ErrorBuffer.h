#ifndef GC_ERRORBUFFER_H
#define GC_ERRORBUFFER_H

#include "Log.h"
#include "ErrorHandler.h"

/*
 * @brief maneja el buffering de logs del ErrorHandler
 *
 * Es capaz de guardar logs temporalmente hasta que se decidan
 * commitear. Para ello, guarda también la posicion en la que
 * debería haber estado el log dentro del ErrorHandler, permitiendo
 * en caso de commit, que no se pierda la semántica del orden de
 * los errores.
 */
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


#endif //GC_ERRORBUFFER_H