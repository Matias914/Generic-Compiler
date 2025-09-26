#ifndef TPE_LOG_H
#define TPE_LOG_H

#include <string>
#include <vector>

/*
 * @brief es un DTO utilizado para la comunicacion entre el lexer/parser
 * y los handlers.
 */
struct Log
{
    int type;
    int code;
    unsigned int line;
    std::vector<std::string> content;
};

#endif //TPE_LOG_H