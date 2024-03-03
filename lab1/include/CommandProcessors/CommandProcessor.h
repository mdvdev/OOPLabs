#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <iostream>

class InputHandler;

class CommandProcessor {
public:
    virtual void process(InputHandler& inputHandler, std::istream& inputStream) = 0;
};

#endif // COMMANDPROCESSOR_H
