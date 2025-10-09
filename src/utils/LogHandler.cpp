#include "utils/LogHandler.h"
#include "utils/LiteralTable.h"
#include "utils/SymbolTable.h"
#include "utils/resources/macros.h"
#include "utils/resources/dispatcher.h"

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;

LogHandler::LogHandler(const std::string& output)
{
    this->output = output;
    this->logs = std::list<Log>();
    this->last_token = this->logs.end();
}

void LogHandler::add(const Log& log)
{
    if (log.type != TOKEN)
        this->logs.push_back(log);
    else if (last_token == this->logs.end())
        last_token = this->logs.insert(this->logs.begin(), log);
    else
        last_token = this->logs.insert(std::next(last_token), log);
}

bool LogHandler::validOutput() const
{
    std::ofstream file(this->output);
    if (!file.is_open()) return false;
    file.close();
    return true;
}

void LogHandler::generateReport() const
{
    std::ofstream file(this->output);
    std::string mssg = "";
    using namespace StringBuilderDispatcher;
    bool first = true;
    for (const auto& [type, code, line, content] : this->logs) {
        if (!first) mssg.append("\n");
        first = false;
        const StringBuilder builder = getStringBuilder(type, code);
        mssg.append("Line ").append(std::to_string(line));
        mssg.append(" - ").append(builder(content));
    }
    file << mssg << "\n\n";
    file << SYMBOL_TABLE.toString() << "\n\n";
    file << LITERAL_TABLE.toString() << "\n\n";
    file.close();
}