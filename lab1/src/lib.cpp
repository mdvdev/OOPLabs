#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

#include "lib.h"

std::string floatToString(float num)
{
    std::ostringstream os;
    os << std::fixed << std::setprecision(3) << num;
    std::string str = os.str();
    return str;
}

void resetInputStream(std::istream& is)
{
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
