#include "utils/resources/builders.h"
#include "code-generator/components/Triples.h"

#include <string>
#include <sstream>
#include <iomanip>

using namespace CodeGenerator;

// Helper function to get the string representation of an operand
std::string getStringOperand(const Triples::Operand& o, const int line)
{
    switch (o.type)
    {
    case SYMBOL:
        return o.value.sref->symbol;
    case LITERAL:
        return o.value.lref->constant;
    case TRIPLE:
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
    case CODEOP_FTOI:
        return "ftoi";
    case CODEOP_BRANCH_TRUE:
        return "BT";
    case CODEOP_BRANCH_FALSE:
        return "BF";
    case CODEOP_CALL:
        return "CALL";
    case CODEOP_RET:
        return "RET";
    case CODEOP_PRINT:
        return "PRINT";
    case CODEOP_EQUAL:
        return "==";
    case CODEOP_NOT_EQUAL:
        return "!=";
    case CODEOP_GE:
        return ">=";
    case CODEOP_LE:
        return "<=";
    case CODEOP_GT:
        return ">";
    case CODEOP_LT:
        return "<";
    case CODEOP_SUM:
        return "+";
    case CODEOP_SUB:
        return "-";
    case CODEOP_MUL:
        return "*";
    case CODEOP_DIV:
        return "/";
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
            << std::left << std::setw(6) << getStringOperator(t.codeop) << ", "
            << std::left << std::setw(30) << getStringOperand(t.o1, line) << ", "
            << std::left << std::setw(30) << getStringOperand(t.o2, line) << " )" << "\n";
        mssg.append(ss.str());
    }
}
