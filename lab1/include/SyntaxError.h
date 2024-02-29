#ifndef SYNTAXERROR_H
#define SYNTAXERROR_H

#include <exception>
#include <string>

class SyntaxError : public std::exception {
public:
    SyntaxError(const std::string& message);
    const char* what() const noexcept override;

private:
    std::string message;
};

#endif // SYNTAXERROR_H
