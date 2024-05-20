#ifndef INVALIDARGUMENT_H
#define INVALIDARGUMENT_H

#include <exception>
#include <string>

class InvalidArgument : public std::exception {
private:
    std::string message;
public:
    explicit InvalidArgument(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};


#endif // INVALIDARGUMENT_H
