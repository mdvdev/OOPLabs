#include "Triangle.h"
#include "InvalidParams.h"

Triangle::Triangle(const std::string& name, const Point& vertex1, const Point& vertex2, const Point& vertex3)
    : Shape(name), vertex1(vertex1), vertex2(vertex2), vertex3(vertex3)
{
    if (!isValidParams(vertex1, vertex2, vertex3)) {
        throw InvalidParams("Invalid parameters");
    }
}

float Triangle::getPerimeter() const
{
    float a = vertex1.getDistance(vertex2);
    float b = vertex1.getDistance(vertex3);
    float c = vertex2.getDistance(vertex3);
    return a + b + c;
}

Point Triangle::getVertex1() const
{
    return vertex1;
}

Point Triangle::getVertex2() const
{
    return vertex2;
}

Point Triangle::getVertex3() const
{
    return vertex3;
}

bool Triangle::isValidParams(const Point& vertex1, const Point& vertex2, const Point& vertex3)
{
    return !(vertex1.getY() == vertex2.getY() && vertex1.getY() == vertex3.getY()) &&
           isValidTriangleInequality(vertex1, vertex2, vertex3);
}

bool Triangle::isValidTriangleInequality(const Point& vertex1, const Point& vertex2, const Point& vertex3)
{
    float a = vertex1.getDistance(vertex2);
    float b = vertex1.getDistance(vertex3);
    float c = vertex2.getDistance(vertex3);
    return c < a + b && b < a + c && a < b + c;
}

std::string Triangle::toString() const
{
    return "Triangle{"
           "name=" + name +
           ", vertex1=" + vertex1.toString() +
           ", vertex2=" + vertex2.toString() +
           ", vertex3=" + vertex3.toString() +
           "}";
}

std::string Triangle::getType() const
{
    return "Triangle";
}
