#ifndef GC_WATCODEBLOCKGENERATOR_H
#define GC_WATCODEBLOCKGENERATOR_H

#include "utils/SymbolTable.h"
#include "code-generator/components/Triples.h"
#include "code-generator/components/CodeBlockGenerator.h"
#include "code-generator/components/wat-generation/wat_instruccions_builders.h"

#include <string>

namespace CodeGenerator
{
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