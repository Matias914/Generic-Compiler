#include "utils/ErrorBuffer.h"

ErrorBuffer::ErrorBuffer(ErrorHandler* handler)
{
    this->buffer_ocupied = false;
    this->handler = handler;
    this->buffered = Log();
}

bool ErrorBuffer::buffer(const Log& log)
{
    if (this->buffer_ocupied) return false;
    this->position = --this->handler->logs.end();
    this->buffered = log;
    this->buffer_ocupied = true;
    return true;
}

Log* ErrorBuffer::get()
{
    if (!this->buffer_ocupied) return nullptr;
    return &this->buffered;
}

bool ErrorBuffer::commit()
{
    if (!this->buffer_ocupied) return false;
    this->handler->logs.insert(std::next(position), buffered);
    this->buffer_ocupied = false;
    return true;
}