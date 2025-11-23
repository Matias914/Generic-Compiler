#include "utils/ReportHandler.h"

#include <algorithm>

#include "code-generator/CodeGenerator.h"
#include "utils/LiteralTable.h"
#include "utils/SymbolTable.h"
#include "utils/resources/StringBuilders.h"
#include "utils/resources/codes.h"

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;

ReportHandler::ReportHandler()
{
    this->output = "output.txt";
    this->logs = std::list<Log>();
    this->last_token = this->logs.end();
}

void ReportHandler::add(const Log& log)
{
    if (log.type != TOKEN)
        this->logs.push_back(log);
    else if (last_token == this->logs.end())
        last_token = this->logs.insert(this->logs.begin(), log);
    else
        last_token = this->logs.insert(std::next(last_token), log);
}

void ReportHandler::setOutput(const std::string& output)
{
    this->output = output;
}

bool ReportHandler::validOutput() const
{
    std::ofstream file(this->output);
    if (!file.is_open()) return false;
    file.close();
    return true;
}

void ReportHandler::generateReport() const
{
    std::ofstream file(this->output);
    std::string mssg = "";
    mssg.reserve(256 * this->logs.size());
    using namespace StringBuilders::ReportBuilders;

    file << CodeGenerator::getIntermediateCode() << "\n\n"
         << SYMBOL_TABLE.toString()              << "\n\n"
         << LITERAL_TABLE.toString()             << "\n\n";

    mssg.append(generateTokenHeader());
    // Se recorren los tokens
    for (auto it = this->logs.begin(); it != this->last_token; ++it) {
        mssg.append("\n")
            .append("Line ")
            .append(std::to_string(it->line))
            .append(" - ")
            .append(generateTokenReport(it->code, it->content));
    }
    // Se recorren Estructuras
    mssg.append("\n\n").append(generateStructureHeader());
    for (auto it = std::next(this->last_token); it != this->logs.end(); ++it) {
        mssg.append("\n")
            .append("Line ")
            .append(std::to_string(it->line))
            .append(" - ")
            .append(generateStructureReport(it->content));
    }
    file << mssg;
    file.close();
}

void ReportHandler::clear()
{
    this->logs.clear();
    this->last_token = this->logs.end();
}

bool ReportHandler::contains(const Log& log)
{
    const auto it = std::find(this->logs.begin(), this->logs.end(), log);
    return (it != this->logs.end());
}