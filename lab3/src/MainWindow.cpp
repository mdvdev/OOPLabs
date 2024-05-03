#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "Calculator.h"
#include "EvalCommand.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , calculator(new Calculator)
    , savedValue(0.0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUi()
{
    updateOutputLineEdit();
}

void MainWindow::updateOutputLineEdit()
{
    ui->outputLineEdit->setText(QString::fromStdString(expr));
}

void MainWindow::onAddPushButtonClicked()
{
    expr += "+";
    updateUi();
}

void MainWindow::onSubtractPushButtonClicked()
{
    expr += "-";
    updateUi();
}

void MainWindow::onMultiplyPushButtonClicked()
{
    expr += "*";
    updateUi();
}

void MainWindow::onDividePushButtonClicked()
{
    expr += "/";
    updateUi();
}

void MainWindow::onEqualPushButtonClicked()
{
    calculator->setCommand(std::make_unique<EvalCommand>(expr));
    expr = calculator->execute();
    updateUi();
}

void MainWindow::onZeroPushButtonClicked()
{
    expr += "0";
    updateUi();
}

void MainWindow::onOnePushButtonClicked()
{
    expr += "1";
    updateUi();
}

void MainWindow::onTwoPushButtonClicked()
{
    expr += "2";
    updateUi();
}

void MainWindow::onThreePushButtonClicked()
{
    expr += "3";
    updateUi();
}

void MainWindow::onFourPushButtonClicked()
{
    expr += "4";
    updateUi();
}

void MainWindow::onFivePushButtonClicked()
{
    expr += "5";
    updateUi();
}

void MainWindow::onSixPushButtonClicked()
{
    expr += "6";
    updateUi();
}

void MainWindow::onSevenPushButtonClicked()
{
    expr += "7";
    updateUi();
}

void MainWindow::onEightPushButtonClicked()
{
    expr += "8";
    updateUi();
}

void MainWindow::onNinePushButtonClicked()
{
    expr += "9";
    updateUi();
}

void MainWindow::onDotPushButtonClicked()
{
    expr += ".";
    updateUi();
}

void MainWindow::onDeletePushButtonClicked()
{
}

void MainWindow::onClearPushButtonClicked()
{
    expr = "";
    updateUi();
}

void MainWindow::onOpenParenthesisPushButtonClicked()
{
    expr += "(";
    updateUi();
}

void MainWindow::onCloseParenthesisPushButtonClicked()
{
    expr += ")";
    updateUi();
}

void MainWindow::onSqrtPushButtonClicked()
{
}

void MainWindow::onInversePushButtonClicked()
{
}

void MainWindow::onSinPushButtonClicked()
{
}

void MainWindow::onCosPushButtonClicked()
{
}

void MainWindow::onTgPushButtonClicked()
{
}

void MainWindow::onCtgPushButtonClicked()
{
}

void MainWindow::onMemoryPlusPushButtonClicked()
{
}

void MainWindow::onMemoryMinusPushButtonClicked()
{
}

void MainWindow::onMemoryReadPushButtonClicked()
{
}

void MainWindow::onMemoryClearPushButtonClicked()
{
}
