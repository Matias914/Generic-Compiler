#include "utils/resources/builders.h"
#include "code-generator/components/Triples.h"

#include <string>
#include <sstream>
#include <iomanip>

// Helper function to get the string representation of an operand
std::string getStringOperand(const Triples::Operand& o, const int line)
{
    switch (o.type)
    {
    case TR_SYMBOL:
        return o.value.sref->symbol;
    case TR_LITERAL:
        return o.value.lref->constant;
    case TR_TRIPLE:
        return "[" + std::to_string(line + o.value.tref) + "]";
    default:
        return "_";
    }
}

// Helper function to get the string representation of an operator
std::string getStringOperator(const char op)
{
    switch (op)
    {
    case TR_FTOI:
        return "ftoi";
    case TR_BRANCH_TRUE:
        return "BT";
    case TR_BRANCH_FALSE:
        return "BF";
    case TR_BRANCH_FUNCTION:
        return "JUMP";
    default:
        return std::string(1, op);
    }
}

namespace StringBuilders::TripleBuilders
{
    void triple(std::string& mssg, const Triples::Triple& t, const int line)
    {
        std::stringstream ss;
        ss << "( "
           << std::left << std::setw(5) << getStringOperator(t.op) << ", "
           << std::left << std::setw(15) << getStringOperand(t.o1, line) << ", "
           << std::left << std::setw(15) << getStringOperand(t.o2, line) << " )" << "\n";
        mssg.append(ss.str());
    }
}