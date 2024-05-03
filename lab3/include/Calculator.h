#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <memory>

#include "Command.h"

class Calculator {
private:
    std::unique_ptr<Command> command;
public:
    void setCommand(std::unique_ptr<Command> command) {
        this->command = std::move(command);
    }

    int execute() const {
        return command->execute();
    }
};

#endif // CALCULATOR_H
