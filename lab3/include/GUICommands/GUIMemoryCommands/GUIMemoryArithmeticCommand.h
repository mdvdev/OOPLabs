#ifndef GUIMEMORYARITHMETICCOMMAND_H
#define GUIMEMORYARITHMETICCOMMAND_H

#include "Command.h"
#include "Expression.h"
#include "Calculator.h"
#include "CalculatorEvalCommand.h"

class GUIMemoryArithmeticCommand : public Command<void> {
private:
    Expression& savedExpr;
public:
    GUIMemoryArithmeticCommand(Expression& savedExpr) : savedExpr(savedExpr) { }
    void execute() override {
        if (savedExpr.getExpr() == "") return;

        Calculator calculator(std::make_shared<CalculatorEvalCommand>(savedExpr.getExpr()));
        double res = calculator.execute();
        double savedValue = savedExpr.getSavedValue();

        operation(savedValue, res);

        savedExpr.resetSavedValue();
        savedExpr.setSavedValue(savedValue);
    }
private:
    virtual void operation(double& op1, double op2) = 0;
};

#endif // GUIMEMORYARITHMETICCOMMAND_H
