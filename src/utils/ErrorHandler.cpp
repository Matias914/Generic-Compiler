#include "utils/ErrorHandler.h"
#include "utils/resources/macros.h"
#include "utils/resources/string_builder_dispatcher.h"

#include <iostream>

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
        mssg.append("Line ").append(std::to_string(line)).append("\t - ");
        const StringBuilder builder = getStringBuilder(type, code);
        mssg.append(builder(content));
    }
    return mssg;
}