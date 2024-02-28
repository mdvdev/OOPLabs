#include <iostream>

#include "PolygonController.h"
#include "Polygon.h"

void PolygonController::printType() const
{
    std::cout << "Type: Polygon" << std::endl;
}

void PolygonController::printParams(const Shape& shape) const
{
    const Polygon& polygon = dynamic_cast<const Polygon&>(shape);
    std::cout << "Name: " << polygon.getName() << std::endl;
    std::vector<Point> vertices = polygon.getVertices();
    for (const auto& vertex : vertices) {
        std::cout << "(" << vertex.getX() << ", " << vertex.getY() << ")" << std::endl;
    }
}

void PolygonController::printPerimeter(const Shape& shape) const
{
    const Polygon& polygon = dynamic_cast<const Polygon&>(shape);
    std::cout << "Perimeter: " << polygon.getPerimeter() << std::endl;
}
