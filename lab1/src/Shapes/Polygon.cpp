#include "Polygon.h"
#include "InvalidParams.h"

Polygon::Polygon(const std::string& name, const std::vector<Point>& vertices)
    : Shape(name), vertices(vertices)
{
    if (vertices.size() < minVertexNum) {
        throw InvalidParams("Invalid parameters");
    }
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
    string += name + ", vertices=";
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        string += it->toString();
        if (it + 1 != vertices.end()) {
            string += " ";
        }
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
