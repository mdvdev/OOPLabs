#include <cmath>

#include "Circle.h"
#include "InvalidParams.h"

Circle::Circle(const std::string& name, const Point& center, float radius)
    : Shape(name), center(center), radius(radius)
{
    if (!isValidParams(center, radius)) {
        throw InvalidParams("Error: invalid parameters");
    }
}

float Circle::getPerimeter() const
{
    return 2 * M_PI * radius;
}

bool Circle::isValidParams(const Point& center, float radius) const
{
    return radius > 0;
}

std::string Circle::toString() const
{
    return "Circle{"
           "name=" + name +
           ", center=" + center.toString() +
           ", radius=" + std::to_string(radius) +
           "}";
}

Point Circle::getCenter() const
{
    return center;
}

float Circle::getRadius() const
{
    return radius;
}

std::string Circle::getType() const
{
    return "Circle";
}
