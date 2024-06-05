#include "InputWidgets.h"
#include "GUISaveExprCommand.h"
#include "GUIEvalCommand.h"
#include "GUIDeleteCommand.h"
#include "GUIClearCommand.h"
#include "GUIMemoryPlusCommand.h"
#include "GUIMemoryMinusCommand.h"
#include "GUIMemoryReadCommand.h"
#include "GUIMemoryClearCommand.h"
#include "GUIBackCommand.h"
#include "MainWindow.h"

InputWidgets::InputWidgets(MainWindow& mainWindow)
    : mainWindow(mainWindow)
    , addPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "+"))
    , subtractPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "-"))
    , multiplyPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "*"))
    , dividePushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "/"))
    , equalPushButton(mainWindow, std::make_shared<GUIEvalCommand>(mainWindow, mainWindow.expr))

    , zeroPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "0"))
    , onePushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "1"))
    , twoPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "2"))
    , threePushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "3"))
    , fourPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "4"))
    , fivePushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "5"))
    , sixPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "6"))
    , sevenPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "7"))
    , eightPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "8"))
    , ninePushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "9"))
    , dotPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "."))

    , deletePushButton(mainWindow, std::make_shared<GUIDeleteCommand>(mainWindow.expr))
    , clearPushButton(mainWindow, std::make_shared<GUIClearCommand>(mainWindow.expr))

    , openParenthesisPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, "("))
    , closeParenthesisPushButton(mainWindow, std::make_shared<GUISaveExprCommand>(mainWindow.expr, ")"))

    , memoryPlusPushButton(mainWindow, std::make_shared<GUIMemoryPlusCommand>(mainWindow.expr))
    , memoryMinusPushButton(mainWindow, std::make_shared<GUIMemoryMinusCommand>(mainWindow.expr))
    , memoryReadPushButton(mainWindow, std::make_shared<GUIMemoryReadCommand>(mainWindow.expr))
    , memoryClearPushButton(mainWindow, std::make_shared<GUIMemoryClearCommand>(mainWindow.expr))

    , backPushButton(mainWindow, std::make_shared<GUIBackCommand>(mainWindow, mainWindow.expr))
{
}
