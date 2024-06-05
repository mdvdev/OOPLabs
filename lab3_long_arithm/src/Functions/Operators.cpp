#include "Operators.h"

Operators::Operators()
    : Functions<OperatorInfo>(), Singleton<Operators>()
{
    functions["+"] = OperatorInfo{.operation = [](const LongFloat& a, const LongFloat& b) { return a + b; },
                                  .assoc = ASSOC_LEFT,
                                  .preced = 5 };
    functions["-"] = OperatorInfo{.operation = [](const LongFloat& a, const LongFloat& b) { return a - b; },
                                  .assoc = ASSOC_LEFT,
                                  .preced = 5 };
    functions["*"] = OperatorInfo{.operation = [](const LongFloat& a, const LongFloat& b) { return a * b; },
                                  .assoc = ASSOC_LEFT,
                                  .preced = 8 };
    functions["/"] = OperatorInfo{.operation = [](const LongFloat& a, const LongFloat& b) { return a / b; },
                                  .assoc = ASSOC_LEFT,
                                  .preced = 8 };
}
