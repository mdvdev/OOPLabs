#ifndef GUIEVALCOMMAND_H
#define GUIEVALCOMMAND_H

#include "Command.h"
#include "Expression.h"
#include "CalculatorEvalCommand.h"
#include "Calculator.h"
#include "GUISaveExprCommand.h"

class GUIEvalCommand : public Command<void> {
private:
    Expression& savedExpr;
public:
    GUIEvalCommand(Expression& savedExpr) : savedExpr(savedExpr) { }
    void execute() override {
        auto evalCommand = std::make_shared<CalculatorEvalCommand>(savedExpr.getExpr());
        Calculator calculator(evalCommand);
        auto saveExprCommand = std::make_shared<GUISaveExprCommand>(
            savedExpr, std::to_string(calculator.execute())
        );
        saveExprCommand->execute();
    }
};

#endif // GUIEVALCOMMAND_H
