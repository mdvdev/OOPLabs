#ifndef OPERATORS_H
#define OPERATORS_H

#include <functional>

#include "Functions.h"
#include "Singleton.h"
#include "LongFloat.h"

enum {ASSOC_NONE = 0, ASSOC_LEFT, ASSOC_RIGHT};

struct OperatorInfo {
    // only binary operators
    std::function<LongFloat(const LongFloat&, const LongFloat&)> operation;
    int preced;
    int assoc;
};

class Operators : public Functions<OperatorInfo>, public Singleton<Operators> {
protected:
    Operators();
};

#endif // OPERATORS_H
