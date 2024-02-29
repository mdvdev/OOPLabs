#include <cmath>
#include <iostream>

#include "Point.h"
#include "SyntaxError.h"

Point::Point(float x, float y)
    : x(x), y(y)
{
}

Point::Point()
    : x(0), y(0)
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

std::string Point::toString() const
{
    return "Point{"
           "x=" + std::to_string(x) +
           ", y=" + std::to_string(y) +
           "}";
}

void Point::setX(float x)
{
    this->x = x;
}

void Point::setY(float y)
{
    this->y = y;
}

std::istream& operator>>(std::istream& is, Point& point)
{
    try {
        std::string string;

        std::getline(is, string, '/');
        float x = std::stof(string);

        std::getline(is, string);
        float y = std::stof(string);

        point.setX(x);
        point.setY(y);

        return is;

    } catch (const std::invalid_argument& e) {
        throw SyntaxError("Syntax error");
    } catch (const std::out_of_range& e) {
        throw SyntaxError("Syntax error");
    }
}
