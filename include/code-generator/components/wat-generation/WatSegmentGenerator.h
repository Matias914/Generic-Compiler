#ifndef GC_WATSEGMENTGENERATOR_H
#define GC_WATSEGMENTGENERATOR_H

#include <map>

#include "code-generator/components/HeaderGenerator.h"
#include "utils/LiteralTable.h"

namespace CodeGenerator
{
    /*
     * @brief clase que genera el segmento de datos del archivo WAT generado.
     *
     * Para ello, utiliza las funcionalidades de tracing de la tabla de literales.
     * Además, incorpora mensajes de errores y lleva registro de sus offsets.
     */
    class WatSegmentGenerator final : public HeaderGenerator
    {
    public:
        explicit WatSegmentGenerator(std::string& output);
        ~WatSegmentGenerator() override = default;

        void generate() override;

        int getOffset(const LiteralTable::Entry* input) const;
        int getZeroDivisionOffset() const;
        int getNegativeUnsignedOffset() const;
        int getRecursionOffset() const;

    private:
        const int pageSize = 65536;
        int offset;
        std::map<const LiteralTable::Entry*, int> offsets;

        const LiteralTable::Entry* zeroDivision;
        const LiteralTable::Entry* negativeUnsigned;
        const LiteralTable::Entry* recursion;
    };
}

#endif //GC_WATSEGMENTGENERATOR_H