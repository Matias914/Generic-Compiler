#ifndef TPE_MAPPERS_H
#define TPE_MAPPERS_H

#include "utils/resources/builders.h"

using StringBuilder = std::string (*) (const std::vector<std::string>& content);

namespace StringBuilderDispatcher
{
    StringBuilder getStringBuilder(const int& type, const int& code);
}

#endif //TPE_MAPPERS_H
