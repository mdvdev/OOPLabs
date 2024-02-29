#include "InvalidParams.h"

InvalidParams::InvalidParams(const std::string& message)
    : message(message)
{
}

const char* InvalidParams::what() const noexcept
{
    return message.c_str();
}
