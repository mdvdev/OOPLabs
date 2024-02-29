#ifndef INVALIDPARAMS_H
#define INVALIDPARAMS_H

#include <exception>
#include <string>

class InvalidParams : public std::exception {
public:
    InvalidParams(const std::string& message);
    const char* what() const noexcept override;

private:
    std::string message;
};

#endif // INVALIDPARAMS_H
