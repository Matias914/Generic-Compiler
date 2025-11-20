#include "utils/resources/builders.h"
#include "code-generator/code-generator.h"
#include "code-generator/components/wat-generation/WatSegmentGenerator.h"
#include "code-generator/components/wat-generation/WatGlobalsGenerator.h"

#include <stack>
#include <ostream>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "../../include/code-generator/components/wat-generation/WatCodeBlockGenerator.h"

#define RUNTIME_E1 "\nnotifyEndOfBlock(): block was marked as ended but no block was found"

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;

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

    bool generateWebAssembly()
    {
        std::ofstream file("../outputs/wa.wat");
        constexpr int page_size = 65536;

        // Creates Header
        std::string code =
        "\n(module\n"
            "\t(import \"console\" \"print_str\" (func $print_str (param i32)))\n"
            "\t(import \"console\" \"print_i32\" (func $print_i32 (param i32)))\n"
            "\t(import \"console\" \"print_f32\" (func $print_f32 (param f32)))\n"
            "\t(memory (export \"memory\") ";

        code.append(std::to_string (
            (LITERAL_TABLE.getStringCount() + LITERAL_TABLE.getCharactersCount()) / page_size + 1
        )).append(")\n\n");

        auto wsegment = WatSegmentGenerator(code);
        for (const auto& entry : LITERAL_TABLE)
            wsegment.generate(entry);

        code.append("\n");

        auto wglobals = WatGlobalsGenerator(code);
        for (const auto& entry : SYMBOL_TABLE )
            wglobals.generate(entry);

        code.append("\n");

        auto wcodeblock = WatCodeBlockGenerator(code, wsegment.getOffsets());
        for (auto it = ICODES.rbegin(); it != ICODES.rend(); ++it) {
            auto& [ref, code] = *it;
            wcodeblock.generate(*ref, *code);
        }

        code.append("\n)");

        file << code;
        file.close();
        return true;
    }
}
