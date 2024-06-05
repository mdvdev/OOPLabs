#include "Expression.h"

void Expression::push(const std::string& expr)
{
    this->expr += expr;
}

void Expression::pop()
{
    // remove last character
    expr.pop_back();
 }
