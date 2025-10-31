#include "intermediate-code/Triples.h"

int Triples::addTriple(Triple t)
{
    const int reference = triples.size();
    triples.push_back(t);
    return reference;
}
