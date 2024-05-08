#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "InputWidgets.h"
#include "Expression.h"

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
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private:
    friend class InputWidgets;
    void updateUi();
    void updateOutputLineEdit();
};
#endif // MAINWINDOW_H
