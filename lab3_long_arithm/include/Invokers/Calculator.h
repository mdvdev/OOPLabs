#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <memory>

#include "Invoker.h"
#include "Command.h"
#include "LongFloat.h"

using LongFloatReturnInvoker = Invoker<LongFloat, Command<LongFloat>>;

class Calculator : public LongFloatReturnInvoker {
public:
    Calculator(std::shared_ptr<Command<LongFloat>> command, QObject* parent = nullptr)
        : LongFloatReturnInvoker(command, parent) { }

    LongFloat execute() override {
        return LongFloatReturnInvoker::command->execute();
    }
};

#endif // CALCULATOR_H
