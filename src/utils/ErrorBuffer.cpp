#include "utils/ErrorBuffer.h"
#include "utils/resources/codes.h"

ErrorBuffer::ErrorBuffer(ErrorHandler* handler)
{
    this->ocupied = false;
    this->handler = handler;
    this->buffered = Log();
}

bool ErrorBuffer::buffer(const Log& log)
{
    if (this->ocupied) return false;
    this->position = --this->handler->logs.end();
    this->buffered = log;
    this->ocupied = true;
    return true;
}

Log* ErrorBuffer::get()
{
    if (!this->ocupied) return nullptr;
    return &this->buffered;
}

bool ErrorBuffer::commit()
{
    if (!this->ocupied) return false;
    this->handler->logs.insert(std::next(position), buffered);
    if (this->buffered.type == ERROR)
        this->handler->error_count++;
    this->ocupied = false;
    return true;
}