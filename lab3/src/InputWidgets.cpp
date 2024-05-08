#include "InputWidgets.h"
#include "GUISaveExprCommand.h"
#include "GUIEvalCommand.h"
#include "MainWindow.h"

InputWidgets::InputWidgets(MainWindow& mainWindow)
    : mainWindow(mainWindow)
    , addPushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "+"))
    , subtractPushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "-"))
    , multiplyPushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "*"))
    , dividePushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "/"))
    , equalPushButton(std::make_shared<GUIEvalCommand>(mainWindow.expr))

    , zeroPushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "0"))
    , onePushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "1"))
    , twoPushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "2"))
    , threePushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "3"))
    , fourPushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "4"))
    , fivePushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "5"))
    , sixPushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "6"))
    , sevenPushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "7"))
    , eightPushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "8"))
    , ninePushButton(std::make_shared<GUISaveExprCommand>(mainWindow.expr, "9"))

    //, deletePushButton()
{
}
