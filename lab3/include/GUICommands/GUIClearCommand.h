#ifndef GUICLEARCOMMAND_H
#define GUICLEARCOMMAND_H

#include "Command.h"
#include "Expression.h"

class GUIClearCommand : public Command<void> {
private:
    Expression& savedExpr;
public:
    GUIClearCommand(Expression& savedExpr) : savedExpr(savedExpr) { }
    void execute() override {
        savedExpr.resetExpr();
    }
};

#endif // GUICLEARCOMMAND_H
