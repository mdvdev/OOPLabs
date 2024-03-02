#ifndef ENDOFFILEEXCEPTION_H
#define ENDOFFILEEXCEPTION_H

#include <exception>
#include <string>

class EndOfFileException : public std::exception {
public:
    EndOfFileException(const std::string& message);
    const char* what() const noexcept override;

private:
    std::string message;
};

#endif // ENDOFFILEEXCEPTION_H
