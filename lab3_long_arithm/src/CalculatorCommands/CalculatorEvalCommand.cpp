#include <stack>
#include <string>
#include <sstream>
#include <cassert>

#include "CalculatorEvalCommand.h"
#include "Operators.h"

#include "InvalidOperatorError.h"
#include "InvalidOperandError.h"
#include "SyntaxError.h"

// Shunting yard algorithm implementation
LongFloat CalculatorEvalCommand::execute()
{
    assert(expr != "");

    std::stack<std::string> operators;
    std::stack<LongFloat> operands;
    std::istringstream is{ expr };
    LongFloat num;
    char c;
    bool minusAsOperator = false;

    while (is >> c) {
        std::string input;
        input += c;
        if ((input == "-" && !minusAsOperator && (operands.empty() ||
            (!operators.empty() && operators.top() == "("))) ||
            std::isdigit(c))
        {
            if (std::isdigit(c) && !operators.empty() && operators.top() == "(")
                minusAsOperator = true;
            is.unget();
            is >> num;
            operands.push(num);
        } else if (c == '(') {
            operators.push("(");
        } else if (c == ')') {
            std::string op;
            if (operators.empty()) throw SyntaxError("Error: mismatched parentheses.");
            while (!(op = operators.top()).empty() && Operators::getInstance().isFunctionExist(op) && op != "(") {
                if (operators.empty()) throw SyntaxError("Error: mismatched parentheses.");
                operators.pop();
                evalOperator(op, operands);
            }
            if (operators.top() != "(") throw SyntaxError("Error: mismatched parentheses.");
            operators.pop();
        } else if (Operators::getInstance().isFunctionExist(input)) {
            if (input == "-" && minusAsOperator) minusAsOperator = false;
            std::string op;
            while (!operators.empty() && (op = operators.top()) != "(" &&
                   Operators::getInstance().isFunctionExist(op) &&
                   ((Operators::getInstance().getFunction(input).preced <
                    Operators::getInstance().getFunction(op).preced) ||
                   (Operators::getInstance().getFunction(op).preced ==
                    Operators::getInstance().getFunction(input).preced &&
                    Operators::getInstance().getFunction(input).assoc == ASSOC_LEFT)))
            {
                operators.pop();
                evalOperator(op, operands);
            }
            operators.push(input);
        } else
            throw InvalidOperatorError("Error: invalid operator.");
    }

    evalAllOperators(operators, operands);

    if (operands.empty()) throw SyntaxError("Error: invalid syntax.");

    return operands.top();
}

void CalculatorEvalCommand::evalOperator(const std::string& op, std::stack<LongFloat>& operands)
{
    if (operands.empty()) throw InvalidOperandError("Error: invalid operand.");

    LongFloat operand2 = operands.top();
    operands.pop();

    if (operands.empty()) throw InvalidOperandError("Error: invalid operand.");

    LongFloat operand1 = operands.top();
    operands.pop();
    operands.push(Operators::getInstance().getFunction(op).operation(operand1, operand2));
}

void CalculatorEvalCommand::evalAllOperators(std::stack<std::string>& operators,
                                             std::stack<LongFloat>& operands)
{
    if (!operands.empty() && operands.size() > 1 && operators.empty())
        throw SyntaxError("Error: operator needed between operands.");

    std::string op;
    while (!operators.empty()) {
        op = operators.top();
        operators.pop();
        if (op == "(") throw SyntaxError("Error: mismatched parentheses.");
        if (Operators::getInstance().isFunctionExist(op))
            evalOperator(op, operands);
        else
            throw InvalidOperatorError("Error: invalid operator.");
    }
}
