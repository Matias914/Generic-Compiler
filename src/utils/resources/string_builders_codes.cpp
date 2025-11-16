#include "code-generator/components/Triples.h"

#include <string>

namespace StringBuilders::CodeBuilders
{
    void intermediateCodeHeader(std::string& mssg)
    {
        mssg.append("==============================================")
            .append(" Intermediate Code ")
            .append("==============================================");
    }

    void intermediateCodeBlock(std::string& mssg, const std::string& name, const Triples* t, int& line)
    {
        mssg.append(name)
            .append(":\n")
            .append(t->toString(true, line));
    }
}
