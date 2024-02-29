#ifndef COMMANDPROCESSOR6_H
#define COMMANDPROCESSOR6_H

#include "CommandProcessor.h"

class CommandProcessor6 : public CommandProcessor {
public:
    void process(InputHandler& inputHandler, std::istringstream& inputStream) override;
};

#endif // COMMANDPROCESSOR6_H
