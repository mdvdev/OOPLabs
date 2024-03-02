#ifndef COMMANDPROCESSOR5_H
#define COMMANDPROCESSOR5_H

#include "CommandProcessor.h"

class CommandProcessor5 : public CommandProcessor {
public:
    void process(InputHandler& inputHandler, std::istream& inputStream) override;
};

#endif // COMMANDPROCESSOR5_H
