#include "Rectangle.h"
#include "InvalidParams.h"

Rectangle::Rectangle(const std::string& name, const Point& upperLeftPoint, const Point& bottomRightAngle)
    : Shape(name), upperLeftPoint(upperLeftPoint), bottomRightPoint(bottomRightAngle)
{
    if (!isValidParams(upperLeftPoint, bottomRightAngle)) {
        throw InvalidParams("Invalid parameters");
    }
}

bool Rectangle::isValidParams(const Point& upperLeftPoint, const Point& bottomRightPoint) const
{
    return upperLeftPoint.getX() < bottomRightPoint.getX() &&
           upperLeftPoint.getY() > bottomRightPoint.getY();
}

float Rectangle::getPerimeter() const
{
    Point point(upperLeftPoint.getX(), bottomRightPoint.getY());
    float height = upperLeftPoint.getDistance(point);
    float width = bottomRightPoint.getDistance(point);
    return 2 * (height + width);
}

Point Rectangle::getUpperLeftAngle() const
{
    return upperLeftPoint;
}

Point Rectangle::getBottomRightAngle() const
{
    return bottomRightPoint;
}

std::string Rectangle::toString() const
{
    return "Rectangle{"
           "name=" + name +
           ", upperLeftAngle=" + upperLeftPoint.toString() +
           ", bottomRightAngle=" + bottomRightPoint.toString() +
           "}";
}

std::string Rectangle::getType() const
{
    return "Rectangle";
}
