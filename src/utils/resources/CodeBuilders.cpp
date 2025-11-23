#include "code-generator/components/Triples.h"

#include <string>

using namespace CodeGenerator;

namespace StringBuilders::CodeBuilders
{
    void intermediateCodeHeader(std::string& mssg)
    {
        mssg.append("===================================")
            .append(" Intermediate Code ")
            .append("===================================");
    }

    void intermediateCodeBlock(std::string& mssg, const SymbolTable::Entry* ref, const Triples* t, int& line)
    {
        mssg.append(ref->symbol)
            .append(":\n")
            .append(t->toString(true, line));
    }
}
