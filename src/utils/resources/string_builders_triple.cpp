#include "utils/resources/builders.h"
#include "code-generator/components/Triples.h"

#include <string>
#include <sstream>
#include <iomanip>

using namespace CodeGenerator;

std::string getStringOperand(const Triples::Operand& o, const int line)
{
    switch (o.type)
    {
    case SYMBOL:
        return o.value.sref->symbol;
    case LITERAL:
        if (o.value.lref->constant.size() > 20)
            return o.value.lref->constant.substr(0, 17) + "...\"";
        return o.value.lref->constant;
    case TRIPLE:
        return "[" + std::to_string(line + o.value.tref) + "]";
    default:
        return "_";
    }
}

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
    case CODEOP_ASSIGN:
        return "=";
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
    case CODEOP_DO_START:
        return "dostart";
    case CODEOP_IF_END:
        return "endif";
    default:
        return std::string(1, op);
    }
}

namespace StringBuilders::TripleBuilders
{
    void triple(std::string& mssg, const Triples::Triple& t, const int line)
    {
        std::stringstream ss;
        ss << "( " << std::left << std::setw(8) << getStringOperator(t.codeop)
           << ", " << std::left << std::setw(22) << getStringOperand(t.o1, line)
           << ", " << std::left << std::setw(22) << getStringOperand(t.o2, line)
           << " ) => type: " << t.type << "\n";
        mssg.append(ss.str());
    }
}
