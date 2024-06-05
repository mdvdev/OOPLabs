#ifndef INVALIDOPERATORERROR_H
#define INVALIDOPERATORERROR_H

#include <exception>
#include <string>

class InvalidOperatorError : public std::exception {
private:
    std::string message;
public:
    explicit InvalidOperatorError(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // INVALIDOPERATORERROR_H
