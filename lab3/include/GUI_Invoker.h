#ifndef GUI_INVOKER_H
#define GUI_INVOKER_H

#include "Invoker.h"
#include "Command.h"

using NotReturnInvoker = Invoker<void, Command<void>>;

class GUI_Invoker : public NotReturnInvoker {
    Q_OBJECT
public:
    GUI_Invoker(std::shared_ptr<Command<void>> command, QObject* parent = nullptr)
        : NotReturnInvoker(command, parent) { }

    void execute() override {
        NotReturnInvoker::command->execute();
    }
public slots:
    void handleEvent() {
        execute();
    }
};

#endif // GUI_INVOKER_H
