#ifndef COMMANDPROCESSOR2_H
#define COMMANDPROCESSOR2_H

#include "CommandProcessor.h"

class CommandProcessor2 : public CommandProcessor {
public:
    void process(InputHandler& inputHandler, std::istringstream& inputStream) override;
};

#endif // COMMANDPROCESSOR2_H
