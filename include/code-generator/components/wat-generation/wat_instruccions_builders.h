#ifndef GC_WAT_INSTRUCCIONS_BUILDERS_H
#define GC_WAT_INSTRUCCIONS_BUILDERS_H

#include <string>

#include "code-generator/components/Triples.h"
#include "code-generator/components/wat-generation/WatSegmentGenerator.h"

/*
 * @brief namespace dedicado a incorporar builders que sepan realizar
 * la traducción a formato WAT de las instrucciones de código intermedio.
 *
 * Utiliza la estructura metadata como DTO, la cual consta con toda la información
 * útil.
 */
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

    // Coertions
    void generateFloatToInteger(const Metadata& m);

    // Control
    void generateBranchTrue(const Metadata& m);
    void generateBranchFalse(const Metadata& m);
    void generateEndif(const Metadata& m);
    void generateDoWhile(const Metadata& m);

    // Functions
    void generateCall(const Metadata& m);
    void generateReturn(const Metadata& m);

    // Comparators
    void generateEquals(const Metadata& m);
    void generateNotEquals(const Metadata& m);
    void generateGreaterOrEqual(const Metadata& m);
    void generateLessOrEqual(const Metadata& m);
    void generateGreaterThan(const Metadata& m);
    void generateLessThan(const Metadata& m);

    void generateAssignment(const Metadata& m);

    // Operations
    void generateAddition(const Metadata& m);
    void generateDivision(const Metadata& m);
    void generateSubstraction(const Metadata& m);
    void generateMultiplication(const Metadata& m);

    // Utility
    void generateOperand(std::string& mssg, const std::string& nesting, const Triples::Operand& op);
}

#endif //GC_WAT_INSTRUCCIONS_BUILDERS_H