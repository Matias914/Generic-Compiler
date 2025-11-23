#ifndef GC_HEADERGENERATOR_H
#define GC_HEADERGENERATOR_H

#include <string>

namespace CodeGenerator
{
    /*
     * @interfaz que define cómo debe ser una clase que genere el header
     * de un programa Assembler.
     */
    class HeaderGenerator
    {
    public:
        explicit HeaderGenerator(std::string& output) : output(output) {}

        virtual void generate() = 0;
        virtual ~HeaderGenerator() = default;
    protected:
        std::string& output;
    };
}

#endif //GC_HEADERGENERATOR_H