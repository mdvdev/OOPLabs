#ifndef UNKNOWNFUNCTIONNAME_H
#define UNKNOWNFUNCTIONNAME_H

#include <exception>
#include <string>

class UnknownFunctionName : public std::exception {
private:
    std::string message;
public:
    explicit UnknownFunctionName(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // UNKNOWNFUNCTIONNAME_H
