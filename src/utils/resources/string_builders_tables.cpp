#include "utils/resources/builders.h"

#include "utils/LiteralTable.h"
#include "utils/SymbolTable.h"

namespace StringBuilders::TableBuilders
{
    void symbolTableHeader(std::string& mssg)
    {
        mssg.append("==============================================")
            .append(" Symbol Table ")
            .append("================================================");
    }

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
        mssg.append(" | ").append("Semantics: ");
        switch (entry.semantics)
        {
        case CR:
            mssg.append("    CR     ");
            break;
        case CV:
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
        mssg.append("==============================================")
            .append(" Literal Table ")
            .append("===============================================");
    }

    void literalTableEntry(std::string& mssg, const LiteralTable::Entry& entry)
    {
        mssg.append("Type: ");
        switch (entry.type)
        {
        case STRING:
            mssg.append("   String   ");
            break;
        case UINT:
            mssg.append("Unsigned Int");
            break;
        case FLOAT:
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
