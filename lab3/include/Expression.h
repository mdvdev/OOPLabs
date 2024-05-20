#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

class Expression {
private:
    std::string expr;
    double savedValue{0.0};
public:
    explicit Expression(const std::string& expr) : expr(expr) { }
    Expression() = default;

    void push(const std::string& expr);
    void pop();

    void resetExpr() {
        expr = "";
    }

    void resetSavedValue() {
        savedValue = 0.0;
    }

    std::string getExpr() const {
        return expr;
    }

    double getSavedValue() const {
        return savedValue;
    }

    void setSavedValue(double value) {
        savedValue = value;
    }
};

#endif // EXPRESSION_H
