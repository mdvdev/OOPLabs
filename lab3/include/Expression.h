#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

#include "MathFunctions.h"

class Expression {
private:
    std::string expr;
    double savedValue{0.0};
public:
    explicit Expression(const std::string& expr) : expr(expr) { }
    Expression() = default;

    void push(const std::string& expr) {
        this->expr += expr;
    }

    void pop() {
        for (const auto& [key, value] : MathFunctions::getInstance())
            if (1) ;
    }

    std::string getExpr() const {
        return expr;
    }
};

#endif // EXPRESSION_H
