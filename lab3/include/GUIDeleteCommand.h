#ifndef GUIDELETECOMMAND_H
#define GUIDELETECOMMAND_H

#include "Command.h"
#include "Expression.h"

class GUIDeleteCommand : public Command<void> {
private:
    Expression& savedExpr;
public:
    GUIDeleteCommand(Expression& savedExpr) : savedExpr(savedExpr) { }
    void execute() override {
        savedExpr.pop();
    }
};

#endif // GUIDELETECOMMAND_H
