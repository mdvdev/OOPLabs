#include "Operators.h"
#include "InvalidOperand.h"

Operators::Operators()
    : Functions<OperatorInfo>(), Singleton<Operators>()
{
    functions["+"] = OperatorInfo{.operation = [](double a, double b) { return a + b; },
                                  .assoc = ASSOC_LEFT,
                                  .preced = 5 };
    functions["-"] = OperatorInfo{.operation = [](double a, double b) { return a - b; },
                                  .assoc = ASSOC_LEFT,
                                  .preced = 5 };
    functions["*"] = OperatorInfo{.operation = [](double a, double b) { return a * b; },
                                  .assoc = ASSOC_LEFT,
                                  .preced = 8 };
    functions["/"] = OperatorInfo{.operation = [](double a, double b) {
                                      if (b == 0) throw InvalidOperand("Invalid operand.");
                                      return a / b;
                                  },
                                  .assoc = ASSOC_LEFT,
                                  .preced = 8 };
}
