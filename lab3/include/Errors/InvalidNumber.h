#ifndef INVALIDNUMBER_H
#define INVALIDNUMBER_H

#include <exception>
#include <string>

class InvalidNumber : public std::exception {
private:
    std::string message;
public:
    explicit InvalidNumber(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // INVALIDNUMBER_H
