#ifndef GUIMEMORYCLEARCOMMAND_H
#define GUIMEMORYCLEARCOMMAND_H

#include "Command.h"
#include "Expression.h"

class GUIMemoryClearCommand : public Command<void> {
private:
    Expression& savedExpr;
public:
    GUIMemoryClearCommand(Expression& savedExpr) : savedExpr(savedExpr) { }
    void execute() override {
        savedExpr.resetSavedValue();
    }
};

#endif // GUIMEMORYCLEARCOMMAND_H
