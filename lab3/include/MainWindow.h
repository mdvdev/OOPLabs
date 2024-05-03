#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class Calculator;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    Ui::MainWindow* ui;
    std::unique_ptr<Calculator> calculator;
    std::string expr;
    double savedValue;
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private slots:
    void updateUi();
    void updateOutputLineEdit();

    // operator buttons
    void onAddPushButtonClicked();
    void onSubtractPushButtonClicked();
    void onMultiplyPushButtonClicked();
    void onDividePushButtonClicked();
    void onEqualPushButtonClicked();

    // number buttons
    void onZeroPushButtonClicked();
    void onOnePushButtonClicked();
    void onTwoPushButtonClicked();
    void onThreePushButtonClicked();
    void onFourPushButtonClicked();
    void onFivePushButtonClicked();
    void onSixPushButtonClicked();
    void onSevenPushButtonClicked();
    void onEightPushButtonClicked();
    void onNinePushButtonClicked();
    void onDotPushButtonClicked();

    // clear buttons
    void onDeletePushButtonClicked();
    void onClearPushButtonClicked();

    // parenthesis buttons
    void onOpenParenthesisPushButtonClicked();
    void onCloseParenthesisPushButtonClicked();

    // function buttons
    void onSqrtPushButtonClicked();
    void onInversePushButtonClicked();
    void onSinPushButtonClicked();
    void onCosPushButtonClicked();
    void onTgPushButtonClicked();
    void onCtgPushButtonClicked();

    // memory buttons
    void onMemoryPlusPushButtonClicked();
    void onMemoryMinusPushButtonClicked();
    void onMemoryReadPushButtonClicked();
    void onMemoryClearPushButtonClicked();
};
#endif // MAINWINDOW_H
