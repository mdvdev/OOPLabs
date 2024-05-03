#ifndef EVALCOMMAND_H
#define EVALCOMMAND_H

#include <string>

#include "Command.h"

class EvalCommand : public Command {
private:
    std::string expr;
public:
    EvalCommand(const std::string& expr) : expr(expr) { }
    int execute() override;
};

#endif // EVALCOMMAND_H
