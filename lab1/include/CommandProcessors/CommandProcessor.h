#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <sstream>

class InputHandler;

class CommandProcessor {
public:
    virtual void process(InputHandler& inputHandler, std::istringstream& inputStream) = 0;
};

#endif // COMMANDPROCESSOR_H
