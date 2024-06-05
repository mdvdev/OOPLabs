#ifndef GUIBACKCOMMAND_H
#define GUIBACKCOMMAND_H

#include "Command.h"
#include "Expression.h"
#include "MainWindow.h"

class GUIBackCommand : public Command<void> {
private:
    MainWindow& mainWindow;
    Expression& savedExpr;
public:
    GUIBackCommand(MainWindow& mainWindow, Expression& savedExpr)
        : mainWindow(mainWindow), savedExpr(savedExpr) { }
    void execute() override {
        if (mainWindow.isCommandsEmpty()) return;
        std::string expr = mainWindow.getEvalCommand().getExpr();
        savedExpr.resetExpr();
        savedExpr.push(expr);
    }
};

#endif // GUIBACKCOMMAND_H
