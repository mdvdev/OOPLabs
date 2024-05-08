#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , inputWidgets(*this)
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
    //ui->outputLineEdit->setText(QString::fromStdString(expr));
}
