#ifndef GUIMEMORYPLUSCOMMAND_H
#define GUIMEMORYPLUSCOMMAND_H

#include "GUIMemoryArithmeticCommand.h"

class GUIMemoryPlusCommand : public GUIMemoryArithmeticCommand {
public:
    GUIMemoryPlusCommand(Expression& savedExpr)
        : GUIMemoryArithmeticCommand(savedExpr) { }
private:
    void operation(LongFloat& op1, const LongFloat& op2) override {
        op1 += op2;
    }
};

#endif // GUIMEMORYPLUSCOMMAND_H
