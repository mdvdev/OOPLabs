#include <cmath>

#include "include/Point.h"

Point::Point(float x, float y)
    : x(x), y(y)
{
}

float Point::getX() const
{
    return x;
}

float Point::getY() const
{
    return y;
}

float Point::getDistance(const Point& point) const
{
    float xDist = point.x - x;
    float yDist = point.y - y;
    return std::sqrt(xDist * xDist + yDist * yDist);
}
