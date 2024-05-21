#ifndef CALCULATOREVALCOMMAND_H
#define CALCULATOREVALCOMMAND_H

#include <string>
#include <stack>

#include "Command.h"
#include "LongFloat.h"

class CalculatorEvalCommand : public Command<LongFloat> {
private:
    std::string expr;
public:
    explicit CalculatorEvalCommand(const std::string& expr) : expr(expr) { }
    LongFloat execute() override;
    std::string getExpr() const { return expr; }
private:
    void evalAllOperators(std::stack<std::string>& operators, std::stack<LongFloat>& operands);
    void evalOperator(const std::string& op, std::stack<LongFloat>& operands);
};

#endif // CALCULATOREVALCOMMAND_H
