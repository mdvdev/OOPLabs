#ifndef COMMANDPROCESSOR7_H
#define COMMANDPROCESSOR7_H

#include "CommandProcessor.h"

class CommandProcessor7 : public CommandProcessor {
public:
    void process(InputHandler& inputHandler, std::istream& inputStream) override;
};

#endif // COMMANDPROCESSOR7_H
