#ifndef GUIMEMORYMINUSCOMMAND_H
#define GUIMEMORYMINUSCOMMAND_H

#include "GUIMemoryArithmeticCommand.h"

class GUIMemoryMinusCommand : public GUIMemoryArithmeticCommand {
public:
    GUIMemoryMinusCommand(Expression& savedExpr)
        : GUIMemoryArithmeticCommand(savedExpr) { }
private:
    void operation(double& op1, double op2) override {
        op1 -= op2;
    }
};

#endif // GUIMEMORYMINUSCOMMAND_H
