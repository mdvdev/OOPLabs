#include "EndOfFileException.h"

EndOfFileException::EndOfFileException(const std::string& message)
    : message(message)
{
}

const char* EndOfFileException::what() const noexcept
{
    return message.c_str();
}
