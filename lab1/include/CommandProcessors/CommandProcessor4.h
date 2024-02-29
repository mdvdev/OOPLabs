#ifndef COMMANDPROCESSOR4_H
#define COMMANDPROCESSOR4_H

#include "CommandProcessor.h"

class CommandProcessor4 : public CommandProcessor {
public:
    void process(InputHandler& inputHandler, std::istringstream& inputStream) override;
};

#endif // COMMANDPROCESSOR4_H
