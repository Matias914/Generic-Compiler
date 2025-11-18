#include "code-generator/code-generator.h"

#include <stack>
#include <stdexcept>

#include "utils/resources/builders.h"

#define RUNTIME_E1 "\nnotifyEndOfBlock(): block was marked as ended but no block was found"

namespace CodeGenerator
{
    struct IntermediateCodeBlock
    {
        const SymbolTable::Entry* ref;
        Triples* code;
    };

    Triples* INTERMEDIATE_CODE = nullptr;

    static auto POSITIONS = std::stack<int>();
    static auto ICODES = std::vector<IntermediateCodeBlock>();

    void addIntermediateCodeBlock(const SymbolTable::Entry* ref)
    {
        INTERMEDIATE_CODE = new Triples();
        POSITIONS.push(ICODES.size());
        ICODES.push_back({ref, INTERMEDIATE_CODE});
    }

    void notifyEndOfBlock()
    {
        if (POSITIONS.empty())
            throw std::runtime_error(RUNTIME_E1);
        POSITIONS.pop();
        INTERMEDIATE_CODE = ICODES[POSITIONS.top()].code;
    }

    std::string getIntermediateCode()
    {
        int line = 1;
        std::string mssg;
        using namespace StringBuilders::CodeBuilders;
        intermediateCodeHeader(mssg);
        mssg.append("\n");
        for (int i = ICODES.size() - 1; i >= 0; --i)
        {
            mssg.append("\n");
            intermediateCodeBlock(mssg, ICODES[i].ref, ICODES[i].code, line);
        }
        return mssg;
    }

}
