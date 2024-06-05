#include <stack>
#include <string>
#include <sstream>
#include <cassert>

#include "CalculatorEvalCommand.h"
#include "Operators.h"
#include "MathFunctions.h"

#include "UnknownFunctionName.h"
#include "InvalidOperand.h"
#include "SyntaxError.h"

// Shunting yard algorithm implementation
double CalculatorEvalCommand::execute()
{
    assert(expr != "");

    std::stack<std::string> operators;
    std::stack<double> operands;
    std::istringstream is{ expr };
    char c;
    double num;
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
            if (!(is >> num)) throw SyntaxError("Invalid number.");
            operands.push(num);
        } else if (c == '(') {
            operators.push("(");
        } else if (c == ')') {
            std::string op;
            if (operators.empty()) throw SyntaxError("Mismatched parentheses.");
            while (!(op = operators.top()).empty() && Operators::getInstance().isFunctionExist(op) && op != "(") {
                if (operators.empty()) throw SyntaxError("Mismatched parentheses.");
                operators.pop();
                evalOperator(op, operands);
            }
            if (operators.top() != "(") throw SyntaxError("Mismatched parentheses.");
            operators.pop();
            if (!operators.empty()) {
                op = operators.top();
                if (MathFunctions::getInstance().isFunctionExist(op)) {
                    operators.pop();
                    evalFunction(op, operands);
                }
            }
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
        } else {
            is.unget();
            std::getline(is >> std::ws, input, '(');
            is.unget();
            if (MathFunctions::getInstance().isFunctionExist(input))
                operators.push(input);
            else
                throw UnknownFunctionName("Unknown function name.");
        }
    }

    evalAllOperators(operators, operands);

    if (operands.empty()) throw SyntaxError("Error: invalid syntax.");

    return operands.top();
}

void CalculatorEvalCommand::evalOperator(const std::string& op, std::stack<double>& operands)
{
    if (operands.empty()) throw InvalidOperand("Invalid operand.");

    double operand2 = operands.top();
    operands.pop();

    if (operands.empty()) throw InvalidOperand("Invalid operand.");

    double operand1 = operands.top();
    operands.pop();
    operands.push(Operators::getInstance().getFunction(op).operation(operand1, operand2));
}

void CalculatorEvalCommand::evalFunction(const std::string& name, std::stack<double>& operands)
{
    if (operands.empty()) throw InvalidOperand("Invalid argument.");

    double operand = operands.top();
    operands.pop();

    operands.push(MathFunctions::getInstance().getFunction(name)(operand));
}

void CalculatorEvalCommand::evalAllOperators(std::stack<std::string>& operators, std::stack<double>& operands)
{
    if (!operands.empty() && operands.size() > 1 && operators.empty())
        throw SyntaxError("Operator needed between operands.");

    std::string op;
    while (!operators.empty()) {
        op = operators.top();
        operators.pop();
        if (op == "(") throw SyntaxError("Mismatched parentheses.");
        if (Operators::getInstance().isFunctionExist(op))
            evalOperator(op, operands);
        else
            evalFunction(op, operands);
    }
}
