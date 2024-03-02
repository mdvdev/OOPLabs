#include "Polygon.h"

Polygon::Polygon(const std::string& name, const std::vector<Point>& vertices)
    : Shape(name), vertices(vertices)
{
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

std::string Polygon::toString() const
{
    std::string string = "Polygon{name=";
    string += name + ", ";
    for (const auto& vertex : vertices) {
        string += vertex.toString() + " ";
    }
    string += "}";
    return string;
}

std::vector<Point> Polygon::getVertices() const
{
    return vertices;
}

std::string Polygon::getType() const
{
    return "Polygon";
}
