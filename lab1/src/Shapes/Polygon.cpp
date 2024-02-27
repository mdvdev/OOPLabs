#include "Polygon.h"

Polygon::Polygon(const std::string& name, const std::vector<Point>& vertices)
    : Shape(name), vertices(vertices)
{
}

ShapeType Polygon::getType() const
{
    return ShapeType::Polygon;
}

float Polygon::getPerimeter() const
{
    float sum = 0;
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        if (it + 1 != vertices.end()) {
            float distance = it->getDistance(*(it + 1));
            sum += distance;
        }
    }
    sum += vertices[0].getDistance(vertices[vertices.size() - 1]);
    return sum;
}


std::vector<Point> Polygon::getVertices() const
{
    return vertices;
}
