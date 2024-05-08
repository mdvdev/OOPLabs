#ifndef CALCULATOREVALCOMMAND_H
#define CALCULATOREVALCOMMAND_H

#include <string>

#include "Command.h"

class CalculatorEvalCommand : public Command<double> {
private:
    std::string expr;
public:
    explicit CalculatorEvalCommand(const std::string& expr) : expr(expr) { }
    double execute() override;
};

#endif // CALCULATOREVALCOMMAND_H
