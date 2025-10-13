#include "utils/resources/builders.h"
#include "syntax-analyzer/components/parser.h"

namespace StringBuilders::ReportBuilders
{
    std::string generateTokenHeader()
    {
        return "=============== Process Of Tokens =================";
    }

    std::string generateStructureHeader()
    {
        return "============== Process Of Structures ==============";
    }

    std::string generateTokenReport(const int& code, const std::vector<std::string>& content)
    {
        switch (code)
        {
        case YYEOF:
            return "End of File was processed as a token.";
        case INVALID_TOKEN:
            return "INVALID token was processed: " + content[0] + ".";
        default:
            return "TOKEN found: \t\t'" + content[0] + "'.";
        }
    }

    std::string generateStructureReport(const std::vector<std::string>& content)
    {
        return "STRUCTURE found:\t'" + content[0] + "'.";
    }
}
