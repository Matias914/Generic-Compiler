#ifndef GC_RETURNCHECKER_H
#define GC_RETURNCHECKER_H

#include <stack>
#include <string>

namespace SemanticAnalyzer
{
    /*
     * @brief clase que se encarga de verificar la integridad de las sentencias de return
     *
     * Verifica que el return pertenezca a una función y que concuerde el tipo retornado con la
     * firma de la función. Además determina, según la función actual si necesita o no sentencia
     * de retorno.
     */
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