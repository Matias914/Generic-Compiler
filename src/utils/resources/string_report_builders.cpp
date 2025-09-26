#include "utils/resources/builders.h"

namespace StringBuilders
{
    std::string reportToken(const std::vector<std::string>& content)
    {
        return "TOKEN found: \t\t'" + content[0] + "'.";
    }

    std::string reportEndOfFile(const std::vector<std::string>& content)
    {
        return "End of File was processed as a token.";
    }

    std::string reportInvalidToken(const std::vector<std::string>& content)
    {
        return "INVALID token found (" + content[0] + ").";
    }

    std::string reportStructure(const std::vector<std::string>& content)
    {
        return "STRUCTURE found:\t'" + content[0] + "'.";
    }
}
