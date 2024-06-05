#ifndef GUISAVEEXPRCOMMAND_H
#define GUISAVEEXPRCOMMAND_H

#include "Command.h"
#include "Expression.h"

class GUISaveExprCommand : public Command<void> {
private:
    Expression& savedExpr;
    std::string expr;
public:
    GUISaveExprCommand(Expression& savedExpr, const std::string& expr)
        : savedExpr(savedExpr), expr(expr) { }
    void execute() override {
        savedExpr.push(expr);
    }
};

#endif // GUISAVEEXPRCOMMAND_H
