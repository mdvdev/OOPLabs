#include <math.h>

#include "Circle.h"
#include "Exception.h"

Circle::Circle(const std::string& name, const Point& center, float radius)
    : Shape(name)
{
    if (!isValidParams(center, radius)) {
        throw InvalidParams();
    }
    this->center = center;
    this->radius = radius;
}

ShapeType Circle::getType() const
{
    return ShapeType::Circle;
}

float Circle::getPerimeter() const
{
    return 2 * M_PI * radius;
}

bool Circle::isValidParams(const Point& center, float radius) const
{
    return radius > 0;
}
