#ifndef INVALIDOPERANDERROR_H
#define INVALIDOPERANDERROR_H

#include <exception>
#include <string>

class InvalidOperandError : public std::exception {
private:
    std::string message;
public:
    explicit InvalidOperandError(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // INVALIDOPERANDERROR_H
