#include "utils/LiteralTable.h"
#include "utils/SymbolTable.h"
#include "utils/resources/builders.h"
#include "syntax-analyzer/components/parser.h"

namespace StringBuilders::TableBuilders
{
    void symbolTableEntry(std::string& mssg, const SymbolTable::Entry& entry)
    {
        mssg.append("Type: ");
        switch (entry.type)
        {
        case UINT:
            mssg.append("Unsigned Int");
            break;
        default:
            mssg.append("Unsupported ");
        }
        mssg.append(" | ").append("Use: ");
        switch (entry.use)
        {
        case PROGRAM:
            mssg.append("  Program    ");
            break;
        case VARIABLE:
            mssg.append("  Variable   ");
            break;
        case FUNCTION:
            mssg.append("  Function   ");
            break;
        case PARAMETER:
            mssg.append("  Parameter  ");
            break;
        default:
            mssg.append(" Unsupported ");
        }
        mssg.append(" | ").append("Symbol: ").append(entry.symbol);
    }

    void symbolTableHeader(std::string& mssg)
    {
        mssg.append("=========================================== Symbol Table ============================================");
    }

    void literalTableEntry(std::string& mssg, const LiteralTable::Entry& entry)
    {
        mssg.append("Type: ");
        switch (entry.type)
        {
        case STRING_LITERAL:
            mssg.append("   String   ");
            break;
        case UINTEGER_LITERAL:
            mssg.append("Unsigned Int");
            break;
        case FLOAT_LITERAL:
            mssg.append("   Float    ");
            break;
        default:
            mssg.append("Unsupported ");
        }
        mssg.append(" | ")
            .append("Count: ")
            .append(std::to_string(entry.refcount))
            .append("\t | ")
            .append("Literal: ").append(entry.constant);
    }

    void literalTableHeader(std::string& mssg)
    {
        mssg.append("=========================================== Literal Table ===========================================");
    }
}
