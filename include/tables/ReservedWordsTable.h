#ifndef TPE_RESERVEDWORDSTABLE_H
#define TPE_RESERVEDWORDSTABLE_H

#include <string>

namespace ReservedWordsTable
{
    /*
     * @brief permite obtener el número de token asociado
     * a cada palabra de la tabla. Si no existe, retorna -1.
     */
    int getToken(const std::string& word);
};


#endif //TPE_RESERVEDWORDSTABLE_H