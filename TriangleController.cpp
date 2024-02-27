#include <iostream>

#include "TriangleController.h"
#include "Triangle.h"

void TriangleController::printType() const
{
    std::cout << "Type: Triangle" << std::endl;
}

void TriangleController::printParams(const Shape& shape) const
{
    const Triangle& triangle = dynamic_cast<const Triangle&>(shape);
    std::cout << "Name: " << triangle.getName() << std::endl;
    std::cout << "Vertex1: (" <<
        triangle.getVertex1().getX() << ", " << triangle.getVertex1().getY() << ")" << std::endl;
    std::cout << "Vertex2: (" <<
        triangle.getVertex2().getX() << ", " << triangle.getVertex2().getY() << ")" << std::endl;
    std::cout << "Vertex3: (" <<
        triangle.getVertex3().getX() << ", " << triangle.getVertex3().getY() << ")" << std::endl;
}

void TriangleController::printPerimeter(const Shape& shape) const
{
    const Triangle& triangle = dynamic_cast<const Triangle&>(shape);
    std::cout << "Perimeter: " << triangle.getPerimeter() << std::endl;
}
