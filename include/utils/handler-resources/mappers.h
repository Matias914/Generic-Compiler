#ifndef TPE_MAPPERS_H
#define TPE_MAPPERS_H

#include "utils/handler-resources/builders.h"

namespace Mapper
{
    Builder getBuilderForErrors(const int& code);
    Builder getBuilderForWarnings(const int& code);
}

#endif //TPE_MAPPERS_H
