#ifndef ZERODIVISIONERROR_H
#define ZERODIVISIONERROR_H

#include <exception>
#include <string>

class ZeroDivisionError : public std::exception {
private:
    std::string message;
public:
    explicit ZeroDivisionError(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // ZERODIVISIONERROR_H
