#ifndef GUI_INVOKER_H
#define GUI_INVOKER_H

#include "Invoker.h"
#include "Command.h"

class MainWindow;

using NotReturnInvoker = Invoker<void, Command<void>>;

class GUI_Invoker : public NotReturnInvoker {
    Q_OBJECT
private:
    MainWindow& mainWindow;
public:
    GUI_Invoker(MainWindow& mainWindow, std::shared_ptr<Command<void>> command, QObject* parent = nullptr)
        : NotReturnInvoker(command, parent), mainWindow(mainWindow) { }

    void execute() override {
        NotReturnInvoker::command->execute();
    }
public slots:
    void handleEvent();
};

#endif // GUI_INVOKER_H
