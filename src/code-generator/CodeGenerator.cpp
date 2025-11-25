#include "code-generator/CodeGenerator.h"

#include <filesystem>
#include <fstream>
#include <ostream>
#include <stack>
#include <string>

#include "../../include/code-generator/components/wasm-generation/wasm_command.h"
#include "code-generator/components/wat-generation/WatCodeBlockGenerator.h"
#include "code-generator/components/wat-generation/WatGlobalsGenerator.h"
#include "code-generator/components/wat-generation/WatSegmentGenerator.h"
#include "utils/resources/StringBuilders.h"

#define WARNING_MSG(X) "\n[[ WARNING ]]: " X "."

extern SymbolTable  SYMBOL_TABLE;
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
            return;
        POSITIONS.pop();
        if (!POSITIONS.empty())
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

    bool generateWebAssembly(const std::string& output)
    {
        // --- Step 1: Generate .wat file ---
        std::ofstream file(output);

        if (!file.is_open())
            return false;

        // Creates Header
        std::string code =

        "(;\n"
            "\tEste código es generado por estudiantes de la Facultad de Ciencias Exactas de\n"
            "\tla Universidad del Centro de la Provincia de Buenos Aires. Consta de funciones\n"
            "\tde impresion al estilo C y se basa en un modelo estático de memoria para funcionar\n"
        ";)\n"

        "\n(module\n"
            "\t(import \"console\" \"print_str\" (func $print_str (param i32)))\n"
            "\t(import \"console\" \"print_i32\" (func $print_i32 (param i32)))\n"
            "\t(import \"console\" \"print_f32\" (func $print_f32 (param f32)))\n"
            "\n"
        ;

        auto wsegment = WatSegmentGenerator(code);
        wsegment.generate();

        code.append("\n");

        auto wglobals = WatGlobalsGenerator(code);
        wglobals.generate();

        code.append("\n");

        auto wcodeblock = WatCodeBlockGenerator(code, wsegment);
        for (auto it = ICODES.rbegin(); it != ICODES.rend(); ++it) {
            auto& [ref, code] = *it;
            wcodeblock.generate(*ref, *code);
        }

        code.append("\n)");

        file << code;
        file.close();

        // Step 2: Attempt to generate .wasm file
        invokeWat2Wasm(output);
        
        return true;
    }

    void clear()
    {
        while (!POSITIONS.empty())
            POSITIONS.pop();
        ICODES.clear();
    }
}
