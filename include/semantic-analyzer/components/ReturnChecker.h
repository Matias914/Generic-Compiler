#ifndef GC_RETURNCHECKER_H
#define GC_RETURNCHECKER_H

#include <stack>
#include <string>

namespace SemanticAnalyzer
{
    class ReturnChecker
    {
    public:
        struct Element
        {
            int type;
            std::string representation;
        };

        void bufferFunction(const Element& func);
        void removeFunction();

        int checkReturnWithBuffered(const Element& ret);
        bool checkIfHasReturn(const bool& returnable);

    private:
        std::stack<Element> functions;
    };
}

#endif //GC_RETURNCHECKER_H