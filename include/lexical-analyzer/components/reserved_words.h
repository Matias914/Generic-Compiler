#ifndef TPE_RESERVEDWORDSTABLE_H
#define TPE_RESERVEDWORDSTABLE_H

#include <string>

/*
 * @brief permite obtener el número de token asociado
 * a cada palabra de la tabla. Si no existe, retorna -1.
 */
namespace LexicalAnalyzer::ReservedWordsTable
{
    int token(const std::string& word);
}

#endif //TPE_RESERVEDWORDSTABLE_H
