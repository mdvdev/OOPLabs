#ifndef INVALIDNUMBERERROR_H
#define INVALIDNUMBERERROR_H

#include <exception>
#include <string>

class InvalidNumberError : public std::exception {
private:
    std::string message;
public:
    explicit InvalidNumberError(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // INVALIDNUMBERERROR_H
