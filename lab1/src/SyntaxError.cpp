#include "SyntaxError.h"

SyntaxError::SyntaxError(const std::string& message)
    : message(message)
{
}

const char* SyntaxError::what() const noexcept
{
    return message.c_str();
}
