#include "utils/LiteralTable.h"
#include "utils/SymbolTable.h"
#include "utils/resources/builders.h"
#include "syntax-analyzer/components/parser.h"

namespace StringBuilders::TableBuilders
{
    void symbolTableEntry(std::string& mssg, const SymbolTable::Entry& entry)
    {
        mssg.append("Symbol: ").append(entry.symbol);
    }

    void symbolTableHeader(std::string& mssg)
    {
        mssg.append("=========================================== Symbol Table ============================================");
    }

    void literalTableEntry(std::string& mssg, const LiteralTable::Entry& entry)
    {
        mssg.append("Count: ")
            .append(std::to_string(entry.refcount))
            .append("\t | ")
            .append("Type:  ");

        switch (entry.type)
        {
        case STRING_LITERAL:
            mssg.append("   String   ");
            break;
        case UINTEGER_LITERAL:
            mssg.append("Unsigned Int");
            break;
        default:
            mssg.append("    Float   ");
        }

        mssg.append(" | ").append("Literal: ").append(entry.constant);
    }

    void literalTableHeader(std::string& mssg)
    {
        mssg.append("=========================================== Literal Table ===========================================");
    }
}
