#ifndef GUIEVALCOMMAND_H
#define GUIEVALCOMMAND_H

#include "Command.h"
#include "Expression.h"
#include "CalculatorEvalCommand.h"
#include "Calculator.h"
#include "MainWindow.h"

class GUIEvalCommand : public Command<void> {
private:
    MainWindow& mainWindow;
    Expression& savedExpr;
public:
    GUIEvalCommand(MainWindow& mainWindow, Expression& savedExpr)
        : mainWindow(mainWindow), savedExpr(savedExpr) { }
    void execute() override {
        if (savedExpr.getExpr() == "") return;
        Calculator calculator(std::make_shared<CalculatorEvalCommand>(savedExpr.getExpr()));
        LongFloat result = calculator.execute();
        mainWindow.addEvalCommand(CalculatorEvalCommand(savedExpr.getExpr()));
        savedExpr.resetExpr();
        savedExpr.push(std::string(result));
    }
};

#endif // GUIEVALCOMMAND_H
