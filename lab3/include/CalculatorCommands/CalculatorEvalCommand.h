#ifndef CALCULATOREVALCOMMAND_H
#define CALCULATOREVALCOMMAND_H

#include <string>
#include <stack>

#include "Command.h"

class CalculatorEvalCommand : public Command<double> {
private:
    std::string expr;
public:
    explicit CalculatorEvalCommand(const std::string& expr) : expr(expr) { }
    double execute() override;
    std::string getExpr() const {
        return expr;
    }
private:
    void evalAllOperators(std::stack<std::string>& operators, std::stack<double>& operands);
    void evalOperator(const std::string& op, std::stack<double>& operands);
    void evalFunction(const std::string& name, std::stack<double>& operands);
};

#endif // CALCULATOREVALCOMMAND_H
