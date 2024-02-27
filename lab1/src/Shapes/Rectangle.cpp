#include "include/Shapes/Rectangle.h"
#include "include/Exception.h"

Rectangle::Rectangle(const std::string& name, const Point& upperLeftAngle, const Point& bottomRightAngle)
    : Shape(name), upperLeftAngle(upperLeftAngle), bottomRightAngle(bottomRightAngle)
{
    if (!isValidParams(upperLeftAngle, bottomRightAngle)) {
        throw InvalidParams();
    }
}

bool Rectangle::isValidParams(const Point& upperLeftAngle, const Point& bottomRightAngle) const
{
    return upperLeftAngle.getX() < bottomRightAngle.getX() &&
           upperLeftAngle.getY() > bottomRightAngle.getY();
}

ShapeType Rectangle::getType() const
{
    return ShapeType::Rectangle;
}

float Rectangle::getPerimeter() const
{
    Point point(upperLeftAngle.getX(), bottomRightAngle.getY());
    float height = upperLeftAngle.getDistance(point);
    float width = bottomRightAngle.getDistance(point);
    return 2 * (height + width);
}

Point Rectangle::getUpperLeftAngle() const
{
    return upperLeftAngle;
}

Point Rectangle::getBottomRightAngle() const
{
    return bottomRightAngle;
}
