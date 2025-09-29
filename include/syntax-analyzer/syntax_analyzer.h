#ifndef TPE_SYNTAX_ANALYZER_H
#define TPE_SYNTAX_ANALYZER_H

#include "utils/ErrorBuffer.h"

namespace SyntaxAnalyzer
{
    extern ErrorBuffer BUFFER;

    void yyparsewrapper();
}

#endif //TPE_SYNTAX_ANALYZER_H