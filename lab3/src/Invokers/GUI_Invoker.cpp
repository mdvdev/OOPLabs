#include <exception>

#include "GUI_Invoker.h"
#include "MainWindow.h"

void GUI_Invoker::handleEvent()
{
    try {
        execute();
        mainWindow.setErrorMsg("No errors.");
    } catch (const std::exception& e) {
        mainWindow.setErrorMsg(e.what());
    }
    mainWindow.updateUi();
}
