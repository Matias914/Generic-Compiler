#ifndef GC_WATGLOBALSGENERATOR_H
#define GC_WATGLOBALSGENERATOR_H

#include "code-generator/components/HeaderGenerator.h"
#include "utils/SymbolTable.h"

namespace CodeGenerator
{
    /*
     * @brief clase que genera las variables globales del programa WAT.
     *
     * También es la encargada de crear variables auxiliares para la detección
     * de errores.
     */
    class WatGlobalsGenerator final : public HeaderGenerator
    {
    public:
        explicit WatGlobalsGenerator(std::string& output);
        ~WatGlobalsGenerator() override = default;

        void generate() override;

    private:
        static std::string determineInitializer(const SymbolTable::Entry& entry);
    };
}

#endif //GC_WATGLOBALSGENERATOR_H