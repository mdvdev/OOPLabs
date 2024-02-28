#include <iostream>

#include "CircleController.h"
#include "Circle.h"

void CircleController::printType() const
{
    std::cout << "Type: Circle" << std::endl;
}

void CircleController::printParams(const Shape& shape) const
{
    const Circle& circle = dynamic_cast<const Circle&>(shape);
    std::cout << "Name: " << circle.getName() << std::endl;
    std::cout << "Center: (" << circle.getCenter().getX() << ", " << circle.getCenter().getY() << ")" << std::endl;
    std::cout << "Radius: " << circle.getRadius() << std::endl;
}

void CircleController::printPerimeter(const Shape& shape) const
{
    const Circle& circle = dynamic_cast<const Circle&>(shape);
    std::cout << "Perimeter: " << circle.getPerimeter() << std::endl;
}
