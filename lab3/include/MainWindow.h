#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stack>

#include "InputWidgets.h"
#include "Expression.h"
#include "CalculatorEvalCommand.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    Ui::MainWindow* ui;
    InputWidgets inputWidgets;
    Expression expr;
    std::string errorMsg;
    std::stack<CalculatorEvalCommand> commands;
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void updateUi();
    void setErrorMsg(const std::string& errorMsg);
    void addEvalCommand(const CalculatorEvalCommand& command);
    CalculatorEvalCommand getEvalCommand();
    bool isCommandsEmpty() const;
private:
    friend class InputWidgets;
    void updateOutputLineEdit();
    void updateErrorLineEdit();
};
#endif // MAINWINDOW_H
