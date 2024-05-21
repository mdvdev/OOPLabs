#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "StackEmptyError.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , inputWidgets(*this)
    , errorMsg("No errors.")
{
    ui->setupUi(this);

    connect(ui->addPushButton, &QPushButton::clicked, &inputWidgets.addPushButton, &GUI_Invoker::handleEvent);
    connect(ui->subtractPushButton, &QPushButton::clicked, &inputWidgets.subtractPushButton, &GUI_Invoker::handleEvent);
    //connect(ui->multiplyPushButton, &QPushButton::clicked, &inputWidgets.multiplyPushButton, &GUI_Invoker::handleEvent);
    //connect(ui->dividePushButton, &QPushButton::clicked, &inputWidgets.dividePushButton, &GUI_Invoker::handleEvent);
    connect(ui->equalPushButton, &QPushButton::clicked, &inputWidgets.equalPushButton, &GUI_Invoker::handleEvent);

    connect(ui->zeroPushButton, &QPushButton::clicked, &inputWidgets.zeroPushButton, &GUI_Invoker::handleEvent);
    connect(ui->onePushButton, &QPushButton::clicked, &inputWidgets.onePushButton, &GUI_Invoker::handleEvent);
    connect(ui->twoPushButton, &QPushButton::clicked, &inputWidgets.twoPushButton, &GUI_Invoker::handleEvent);
    connect(ui->threePushButton, &QPushButton::clicked, &inputWidgets.threePushButton, &GUI_Invoker::handleEvent);
    connect(ui->fourPushButton, &QPushButton::clicked, &inputWidgets.fourPushButton, &GUI_Invoker::handleEvent);
    connect(ui->fivePushButton, &QPushButton::clicked, &inputWidgets.fivePushButton, &GUI_Invoker::handleEvent);
    connect(ui->sixPushButton, &QPushButton::clicked, &inputWidgets.sixPushButton, &GUI_Invoker::handleEvent);
    connect(ui->sevenPushButton, &QPushButton::clicked, &inputWidgets.sevenPushButton, &GUI_Invoker::handleEvent);
    connect(ui->eightPushButton, &QPushButton::clicked, &inputWidgets.eightPushButton, &GUI_Invoker::handleEvent);
    connect(ui->ninePushButton, &QPushButton::clicked, &inputWidgets.ninePushButton, &GUI_Invoker::handleEvent);
    connect(ui->dotPushButton, &QPushButton::clicked, &inputWidgets.dotPushButton, &GUI_Invoker::handleEvent);

    connect(ui->deletePushButton, &QPushButton::clicked, &inputWidgets.deletePushButton, &GUI_Invoker::handleEvent);
    connect(ui->clearPushButton, &QPushButton::clicked, &inputWidgets.clearPushButton, &GUI_Invoker::handleEvent);

    connect(ui->openParenthesisPushButton, &QPushButton::clicked, &inputWidgets.openParenthesisPushButton, &GUI_Invoker::handleEvent);
    connect(ui->closeParenthesisPushButton, &QPushButton::clicked, &inputWidgets.closeParenthesisPushButton, &GUI_Invoker::handleEvent);

    connect(ui->memoryPlusPushButton, &QPushButton::clicked, &inputWidgets.memoryPlusPushButton, &GUI_Invoker::handleEvent);
    connect(ui->memoryMinusPushButton, &QPushButton::clicked, &inputWidgets.memoryMinusPushButton, &GUI_Invoker::handleEvent);
    connect(ui->memoryReadPushButton, &QPushButton::clicked, &inputWidgets.memoryReadPushButton, &GUI_Invoker::handleEvent);
    connect(ui->memoryClearPushButton, &QPushButton::clicked, &inputWidgets.memoryClearPushButton, &GUI_Invoker::handleEvent);

    connect(ui->backPushButton, &QPushButton::clicked, &inputWidgets.backPushButton, &GUI_Invoker::handleEvent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUi()
{
    updateOutputLineEdit();
    updateErrorLineEdit();
}

void MainWindow::updateOutputLineEdit()
{
    ui->outputLineEdit->setText(QString::fromStdString(expr.getExpr()));
}

void MainWindow::updateErrorLineEdit()
{
    ui->errorLineEdit->setText(QString::fromStdString(errorMsg));
}

void MainWindow::setErrorMsg(const std::string& errorMsg)
{
    this->errorMsg = errorMsg;
}

void MainWindow::addEvalCommand(const CalculatorEvalCommand& command)
{
    commands.push(command);
}

CalculatorEvalCommand MainWindow::getEvalCommand()
{
    if (commands.empty()) throw StackEmptyError("Error: stack is empty.");
    CalculatorEvalCommand command = commands.top();
    commands.pop();
    return command;
}

bool MainWindow::isCommandsEmpty() const
{
    return commands.empty();
}
