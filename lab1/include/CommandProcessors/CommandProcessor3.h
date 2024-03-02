#ifndef COMMANDPROCESSOR3_H
#define COMMANDPROCESSOR3_H

#include "CommandProcessor.h"

class CommandProcessor3 : public CommandProcessor {
public:
    void process(InputHandler& inputHandler, std::istream& inputStream) override;
};

#endif // COMMANDPROCESSOR3_H
