#include <cmath>

#include "MathFunctions.h"

double MathFunctions::ctg(double n)
{
    return 1.0 / tan(n);
}

double MathFunctions::inverse(double n)
{
    return 1.0 / n;
}

MathFunctions::MathFunctions()
{
    functions["sin"] = &sin;
    functions["cos"] = &cos;
    functions["tg"] = &tan;
    functions["ctg"] = &ctg;
    functions["sqrt"] = &sqrt;
    functions["inverse"] = &inverse;
}
