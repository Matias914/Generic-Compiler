#include "utils/ErrorHandler.h"

#include <algorithm>
#include <iostream>

#include "utils/resources/codes.h"
#include "utils/resources/StringBuilderDispatcher.h"

ErrorHandler::ErrorHandler()
{
    this->logs = std::list<Log>();
    this->error_count = 0;
}

void ErrorHandler::add(const Log& log)
{
    this->logs.push_back(log);
    if (log.type == ERROR)
        error_count++;
}

int ErrorHandler::errorCount() const
{
    return this->error_count;
}

int ErrorHandler::warningCount() const
{
    return this->logs.size() - this->error_count;
}

const Log* ErrorHandler::getLastestLog() const
{
    if (this->logs.empty())
        return nullptr;
    return &this->logs.back();
}

std::string ErrorHandler::getLogs() const
{
    std::string mssg;
    mssg.reserve(256 * logs.size());
    using namespace StringBuilderDispatcher;
    bool first = true;
    for (const auto& [type, code, line, content] : logs)
    {
        if (!first) mssg.append("\n");
        first = false;
        mssg.append("Line ").append(std::to_string(line)).append(" - ");
        const StringBuilder builder = getStringBuilder(type, code);
        mssg.append(builder(content));
    }
    return mssg;
}

void ErrorHandler::clear()
{
    this->logs.clear();
    this->error_count = 0;
}

bool ErrorHandler::contains(const Log& log)
{
    const auto it = std::find(this->logs.begin(), this->logs.end(), log);
    return (it != this->logs.end());
}