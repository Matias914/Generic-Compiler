#include "code-generator/code-generator.h"

#include <stack>

#include "utils/resources/builders.h"

namespace CodeGenerator
{
    struct IntermediateCodeBlock
    {
        const std::string name;
        Triples* code;
    };

    Triples* INTERMEDIATE_CODE = nullptr;

    static auto POSITIONS = std::stack<int>();
    static auto ICODES = std::vector<IntermediateCodeBlock>();

    void addIntermediateCodeBlock(const std::string& name)
    {
        INTERMEDIATE_CODE = new Triples();
        ICODES.push_back({name, INTERMEDIATE_CODE});
        POSITIONS.push(ICODES.size());
    }

    void notifyEndOfBlock()
    {
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
            intermediateCodeBlock(mssg, ICODES[i].name, ICODES[i].code, line);
            line++;
        }
        return mssg;
    }

}
