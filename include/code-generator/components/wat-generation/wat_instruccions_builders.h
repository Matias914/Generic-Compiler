#ifndef GC_WAT_INSTRUCCIONS_BUILDERS_H
#define GC_WAT_INSTRUCCIONS_BUILDERS_H

#include "code-generator/components/Triples.h"
#include "code-generator/components/wat-generation/WatSegmentGenerator.h"

#include <string>

namespace CodeGenerator::InstructionsGenerators
{
    struct Metadata
    {
        std::string& output;
        std::string& nesting;
        const int& type;
        const Triples::Operand& o1;
        const Triples::Operand& o2;
        const WatSegmentGenerator& segment;
    };
    using InstructionsGenerator = void (*) (const Metadata& metadata);

    void generatePrint(const Metadata& m);

    // Control
    void generateBranchTrue(const Metadata& m);
    void generateBranchFalse(const Metadata& m);
    void generateEndif(const Metadata& m);
    void generateDoWhile(const Metadata& m);

    // Comparators
    void generateEquals(const Metadata& m);
    void generateNotEquals(const Metadata& m);
    void generateGreaterOrEqual(const Metadata& m);
    void generateLessOrEqual(const Metadata& m);
    void generateGreaterThan(const Metadata& m);
    void generateLessThan(const Metadata& m);

    void generateAssignment(const Metadata& m);
    void generateAddition(const Metadata& m);
    void generateDivision(const Metadata& m);
    void generateSubstraction(const Metadata& m);
    void generateMultiplication(const Metadata& m);

    // Utility
    void generateOperand(std::string& mssg, const std::string& nesting, const Triples::Operand& op);
}

#endif //GC_WAT_INSTRUCCIONS_BUILDERS_H