#ifndef SYNTAXERROR_H
#define SYNTAXERROR_H

#include <exception>
#include <string>

class SyntaxError : public std::exception {
private:
    std::string message;
public:
    explicit SyntaxError(const std::string& message) : message(message) { }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // SYNTAXERROR_H
