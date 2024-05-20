#ifndef INVALIDOPERAND_H
#define INVALIDOPERAND_H

#include <exception>
#include <string>

class InvalidOperand : public std::exception {
private:
    std::string message;
public:
    explicit InvalidOperand(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // INVALIDOPERAND_H
