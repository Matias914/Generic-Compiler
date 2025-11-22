#include "code-generator/components/Triples.h"

#include "utils/resources/builders.h"

namespace CodeGenerator
{
    Triples::Triples():
        triples(std::vector<Triple>()),
        buffer(std::vector<Triple>()) {}

    int Triples::addTriple(const Triple& t)
    {
        const int reference = triples.size();
        triples.push_back(t);
        return reference;
    }

    int Triples::addBuffer(const Triple& t)
    {
        const int reference = buffer.size();
        buffer.push_back(t);
        return reference;
    }

    int Triples::getLastTriple() const
    {
        return triples.size() - 1;
    }

    bool Triples::updateTripleReference(const int id, const int ref)
    {
        if (id >= triples.size())
            return false;
        if (triples[id].o1.type == NULLREF)
        {
            triples[id].o1 = { TRIPLE, { .tref = ref }};
            return true;
        }
        if (triples[id].o2.type == NULLREF)
        {
            triples[id].o2 = { TRIPLE, { .tref = ref }};
            return true;
        }
        return false;
    }

    void Triples::commit()
    {
        if (!buffer.empty())
        {
            triples.insert(triples.end(), buffer.begin(), buffer.end());
            buffer.clear();
        }
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
}
