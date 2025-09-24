#include "utils/ErrorHandler.h"
#include "utils/handler-resources/mappers.h"

#include <iostream>

ErrorHandler::ErrorHandler()
{
    this->logs = std::vector<Log>();
    this->error_count = 0;
}

void ErrorHandler::add(const Log& log)
{
    this->logs.push_back(log);
    if (log.type == ERROR)
        error_count++;
}

bool ErrorHandler::updateLatestLog(const Log& l)
{
    if (this->logs.empty())
        return false;
    this->logs[this->logs.size() - 1] = l;
    return true;
}

int ErrorHandler::errorCount() const
{
    return this->error_count;
}

int ErrorHandler::warningCount() const
{
    return this->logs.size() - this->error_count;
}

const ErrorHandler::Log* ErrorHandler::getLastestLog() const
{
    if (this->logs.empty())
        return nullptr;
    return &this->logs.back();
}

std::string ErrorHandler::getLogs() const
{
    const int n =  logs.size();
    std::string mssg;
    for (int i = 0; i < n; i++)
    {
        Builder builder;
        auto& [type, line, code, content] = this->logs[i];
        mssg += "Line " + std::to_string(line) + "\t - ";
        if (type == ERROR)
            builder = Mapper::getBuilderForErrors(code);
        else
            builder = Mapper::getBuilderForWarnings(code);
        mssg += builder(content);
        if (i + 1 != n)
            mssg += "\n";
    }
    return mssg;
}
