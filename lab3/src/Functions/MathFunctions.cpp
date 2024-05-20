#include "MathFunctions.h"
#include "InvalidArgument.h"

MathFunctions::MathFunctions()
    : Functions<std::function<double(double)>>(), Singleton<MathFunctions>()
{
    functions["sin"] = [](double x) { return std::sin(x); };
    functions["cos"] = [](double x) { return std::cos(x); };
    functions["tg"] = [](double x) { return std::tan(x); };
    functions["ctg"] = [](double x) { return 1.0 / std::tan(x); };
    functions["sqrt"] = [](double x) {
        if (x < 0) throw InvalidArgument("Invalid argument.");
        return std::sqrt(x);
    };
    functions["inverse"] = [](double x) {
        if (x == 0) throw InvalidArgument("Invalid argument.");
        return 1.0 / x;
    };
}
