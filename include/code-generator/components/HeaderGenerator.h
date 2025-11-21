#ifndef GC_HEADERGENERATOR_H
#define GC_HEADERGENERATOR_H

namespace CodeGenerator
{
    class HeaderGenerator
    {
    public:
        explicit HeaderGenerator(std::string& output) : output(output) {};

        virtual void generate() = 0;
        virtual ~HeaderGenerator() = default;
    protected:
        std::string& output;
    };
}

#endif //GC_HEADERGENERATOR_H