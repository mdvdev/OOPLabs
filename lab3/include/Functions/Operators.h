#ifndef OPERATORS_H
#define OPERATORS_H

#include <functional>

#include "Functions.h"
#include "Singleton.h"

enum {ASSOC_NONE = 0, ASSOC_LEFT, ASSOC_RIGHT};

struct OperatorInfo {
    // only binary operators
    std::function<double(double, double)> operation;
    int preced;
    int assoc;
};

class Operators : public Functions<OperatorInfo>, public Singleton<Operators> {
protected:
    Operators();
};

#endif // OPERATORS_H
