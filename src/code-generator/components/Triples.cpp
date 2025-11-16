#include "utils/resources/builders.h"
#include "code-generator/components/Triples.h"

Triples::Triples() : triples(std::vector<Triple>()) {}

int Triples::addTriple(const Triple& t)
{
    const int reference = triples.size();
    triples.push_back(t);
    return reference;
}

std::string Triples::toString(const bool withTab, int& line) const
{
    std::string mssg;
    const int offset = line;
    using namespace StringBuilders::TripleBuilders;
    for (auto t : triples)
    {
        if (withTab) mssg.append("\t");
        triple(mssg, t, offset);
        line++;
    }
    return mssg;
}


