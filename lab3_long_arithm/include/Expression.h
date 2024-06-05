#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

#include "LongFloat.h"

class Expression {
private:
    std::string expr;
    LongFloat savedValue;
public:
    void push(const std::string& expr);
    void pop();

    void resetExpr() { expr = ""; }

    void resetSavedValue() { savedValue = 0.0; }

    std::string getExpr() const { return expr; }

    LongFloat getSavedValue() const { return savedValue; }

    void setSavedValue(const LongFloat& value) { savedValue = value; }
};

#endif // EXPRESSION_H
