#ifndef INVOKER_H
#define INVOKER_H

#include <QObject>
#include <memory>

template<typename T, typename Command>
class Invoker : public QObject {
protected:
    std::shared_ptr<Command> command;
public:
    Invoker(std::shared_ptr<Command> command, QObject* parent = nullptr)
        : QObject(parent), command(command) { }

    void setCommand(std::shared_ptr<Command> command) {
        this->command = command;
    }

    virtual T execute() = 0;
};

#endif // INVOKER_H
