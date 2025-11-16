#include "utils/LiteralTable.h"
#include "utils/SymbolTable.h"
#include "utils/resources/builders.h"

namespace StringBuilders::TableBuilders
{
    void symbolTableHeader(std::string& mssg)
    {
        mssg.append("================================================")
            .append(" Symbol Table ")
            .append("================================================");
    }

    void symbolTableEntry(std::string& mssg, const SymbolTable::Entry& entry)
    {
        mssg.append("Type: ");
        switch (entry.type)
        {
        case ST_UINT:
            mssg.append("Unsigned Int");
            break;
        default:
            mssg.append("Unsupported ");
        }
        mssg.append(" | ").append("Use: ");
        switch (entry.use)
        {
        case ST_PROGRAM:
            mssg.append("  Program    ");
            break;
        case ST_VARIABLE:
            mssg.append("  Variable   ");
            break;
        case ST_FUNCTION:
            mssg.append("  Function   ");
            break;
        case ST_PARAMETER:
            mssg.append("  Parameter  ");
            break;
        default:
            mssg.append(" Unsupported ");
        }
        mssg.append(" | ").append("Semantics: ");
        switch (entry.semantics)
        {
        case ST_CR:
            mssg.append("    CR     ");
            break;
        case ST_CV:
            mssg.append("    CV     ");
            break;
        default:
            mssg.append("Unsupported");
        }
        mssg.append(" | ")
            .append("Parameters: ")
            .append(std::to_string(entry.params))
            .append("\t")
            .append(" | ")
            .append("Symbol: ")
            .append(entry.symbol);
    }

    void literalTableHeader(std::string& mssg)
    {
        mssg.append("================================================")
            .append(" Literal Table ")
            .append("================================================");
    }

    void literalTableEntry(std::string& mssg, const LiteralTable::Entry& entry)
    {
        mssg.append("Type: ");
        switch (entry.type)
        {
        case LT_STRING:
            mssg.append("   String   ");
            break;
        case LT_UINT:
            mssg.append("Unsigned Int");
            break;
        case LT_FLOAT:
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
}
