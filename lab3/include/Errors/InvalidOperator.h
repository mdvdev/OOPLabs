#ifndef INVALIDOPERATOR_H
#define INVALIDOPERATOR_H

#include <exception>
#include <string>

class InvalidOperator : public std::exception {
private:
    std::string message;
public:
    explicit InvalidOperator(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // INVALIDOPERATOR_H
