#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <functional>

#include "Functions.h"
#include "Singleton.h"

// simple case: functions with only 1 parameter
class MathFunctions : public Functions<std::function<double(double)>>, public Singleton<MathFunctions> {
protected:
    MathFunctions();
};

#endif // MATHFUNCTIONS_H
