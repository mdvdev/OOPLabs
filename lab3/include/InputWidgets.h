#ifndef INPUTWIDGETS_H
#define INPUTWIDGETS_H

#include "GUI_Invoker.h"

class MainWindow;

class InputWidgets {
private:
    MainWindow& mainWindow;

    GUI_Invoker addPushButton;
    GUI_Invoker subtractPushButton;
    GUI_Invoker multiplyPushButton;
    GUI_Invoker dividePushButton;
    GUI_Invoker equalPushButton;

    GUI_Invoker zeroPushButton;
    GUI_Invoker onePushButton;
    GUI_Invoker twoPushButton;
    GUI_Invoker threePushButton;
    GUI_Invoker fourPushButton;
    GUI_Invoker fivePushButton;
    GUI_Invoker sixPushButton;
    GUI_Invoker sevenPushButton;
    GUI_Invoker eightPushButton;
    GUI_Invoker ninePushButton;
    GUI_Invoker dotPushButton;

    GUI_Invoker deletePushButton;
    GUI_Invoker clearPushButton;

    GUI_Invoker openParenthesisPushButton;
    GUI_Invoker closeParenthesisPushButton;

    GUI_Invoker sqrtPushButton;
    GUI_Invoker inversePushButton;
    GUI_Invoker sinPushButton;
    GUI_Invoker cosPushButton;
    GUI_Invoker tgPushButton;
    GUI_Invoker ctgPushButton;

    GUI_Invoker memoryPlusPushButton;
    GUI_Invoker memoryMinusPushButton;
    GUI_Invoker memoryReadPushButton;
    GUI_Invoker memoryClearPushButton;
public:
    explicit InputWidgets(MainWindow& mainWindow);
};

#endif // INPUTWIDGETS_H
