#ifndef GC_WATCODEBLOCKGENERATOR_H
#define GC_WATCODEBLOCKGENERATOR_H

#include <string>

#include "code-generator/components/CodeBlockGenerator.h"
#include "code-generator/components/Triples.h"
#include "code-generator/components/wat-generation/WatInstruccionsBuilders.h"
#include "utils/SymbolTable.h"

namespace CodeGenerator
{
    /*
     * @brief clase que se encarga de traducir los tercetos a código WAT ejecutable.
     *
     * Para ello utiliza los InstructionsBuilders y el generador de segmentos quién lleva
     * registro de los offsets de los mensajes de error.
     */
    class WatCodeBlockGenerator final : public CodeBlockGenerator
    {
    public:
        explicit WatCodeBlockGenerator(std::string& output, const WatSegmentGenerator& segment);
        ~WatCodeBlockGenerator() override = default;

        void generate(const SymbolTable::Entry& s, const Triples& triples) override;

    private:
        std::string nesting;
        const WatSegmentGenerator& segment;

        std::map<char, InstructionsGenerators::InstructionsGenerator> mapping = {
            {CODEOP_FTOI         , InstructionsGenerators::generateFloatToInteger },
            {CODEOP_BRANCH_TRUE  , InstructionsGenerators::generateBranchTrue     },
            {CODEOP_BRANCH_FALSE , InstructionsGenerators::generateBranchFalse    },
            {CODEOP_IF_START     , InstructionsGenerators::generateIf             },
            {CODEOP_IF_END       , InstructionsGenerators::generateEndif          },
            {CODEOP_DO_START     , InstructionsGenerators::generateDoWhile        },
            {CODEOP_CALL         , InstructionsGenerators::generateCall           },
            {CODEOP_RET          , InstructionsGenerators::generateReturn         },
            {CODEOP_PRINT        , InstructionsGenerators::generatePrint          },
            {CODEOP_ASSIGN       , InstructionsGenerators::generateAssignment     },
            {CODEOP_EQUAL        , InstructionsGenerators::generateEquals         },
            {CODEOP_NOT_EQUAL    , InstructionsGenerators::generateNotEquals      },
            {CODEOP_GE           , InstructionsGenerators::generateGreaterOrEqual },
            {CODEOP_LE           , InstructionsGenerators::generateLessOrEqual    },
            {CODEOP_GT           , InstructionsGenerators::generateGreaterThan    },
            {CODEOP_LT           , InstructionsGenerators::generateLessThan       },
            {CODEOP_SUM          , InstructionsGenerators::generateAddition       },
            {CODEOP_SUB          , InstructionsGenerators::generateSubstraction   },
            {CODEOP_MUL          , InstructionsGenerators::generateMultiplication },
            {CODEOP_DIV          , InstructionsGenerators::generateDivision       }
        };
    };
}

#endif //GC_WATCODEBLOCKGENERATOR_H