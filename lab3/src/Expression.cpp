#include "Expression.h"
#include "MathFunctions.h"

void Expression::push(const std::string& expr)
{
    if (MathFunctions::getInstance().isFunctionExist(expr)) {
        this->expr.insert(0, expr + "(");
        this->expr += ")";
    } else
        this->expr += expr;
}

void Expression::pop()
{
    for (const auto& [key, value] : MathFunctions::getInstance()) {
        if (key == expr.substr(0, key.size())) {
            // remove function name + '(' character
            expr.erase(0, key.size() + 1);
            break;
        }
    }
    // remove last character
    expr.pop_back();
 }
