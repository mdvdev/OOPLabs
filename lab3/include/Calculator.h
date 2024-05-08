#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <memory>

#include "Invoker.h"
#include "Command.h"

using DoubleReturnInvoker = Invoker<double, Command<double>>;

class Calculator : public DoubleReturnInvoker {
public:
    Calculator(std::shared_ptr<Command<double>> command, QObject* parent = nullptr)
        : DoubleReturnInvoker(command, parent) { }

    double execute() override {
        return DoubleReturnInvoker::command->execute();
    }
};

#endif // CALCULATOR_H
