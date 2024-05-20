#ifndef STACKEMPTYERROR_H
#define STACKEMPTYERROR_H

#include <exception>
#include <string>

class StackEmptyError : public std::exception {
private:
    std::string message;
public:
    explicit StackEmptyError(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // STACKEMPTYERROR_H
