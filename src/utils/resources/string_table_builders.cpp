#include "utils/resources/builders.h"

namespace StringBuilders
{
    std::string symbolTableEntry(const std::vector<std::string>& content)
    {
        std::string mssg;
        mssg.reserve(32);
        mssg.append("Symbol: ").append(content[0]);
        return mssg;
    }

    std::string symbolTableHeader(const std::vector<std::string>& content)
    {
        return "================== Symbol Table ==================";
    }

    std::string literalTableEntry(const std::vector<std::string>& content)
    {
        std::string mssg;
        mssg.reserve(256);
        mssg.append("Count: ").append(content[2]).append("\t | ");
        mssg.append("Type:  ").append(content[1]).append(" | ");
        mssg.append("Literal: ").append(content[0]);
        return mssg;
    }

    std::string literalTableHeader(const std::vector<std::string>& content)
    {
        return "================== Literal Table ===================";
    }
}
