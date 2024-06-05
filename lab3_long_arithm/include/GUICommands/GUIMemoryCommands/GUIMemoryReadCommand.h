#ifndef GUIMEMORYREADCOMMAND_H
#define GUIMEMORYREADCOMMAND_H

#include "Command.h"
#include "Expression.h"

class GUIMemoryReadCommand : public Command<void> {
private:
    Expression& savedExpr;
public:
    GUIMemoryReadCommand(Expression& savedExpr) : savedExpr(savedExpr) { }
    void execute() override {
        savedExpr.resetExpr();
        savedExpr.push(std::string(savedExpr.getSavedValue()));
    }
};

#endif // GUIMEMORYREADCOMMAND_H
