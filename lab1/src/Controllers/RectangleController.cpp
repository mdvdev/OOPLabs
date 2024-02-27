#include <iostream>

#include "include/Controllers/RectangleController.h"
#include "include/Shapes/Rectangle.h"

void RectangleController::printType() const
{
    std::cout << "Type: Rectangle" << std::endl;
}

void RectangleController::printParams(const Shape& shape) const
{
    const Rectangle& rectangle = dynamic_cast<const Rectangle&>(shape);
    std::cout << "Name: " << rectangle.getName() << std::endl;
    std::cout << "Upper left angle: (" <<
        rectangle.getUpperLeftAngle().getX() << ", " << rectangle.getUpperLeftAngle().getY() << ")" << std::endl;
    std::cout << "Bottom right angle: (" <<
        rectangle.getBottomRightAngle().getX() << ", " << rectangle.getBottomRightAngle().getY() << ")" << std::endl;
}

void RectangleController::printPerimeter(const Shape& shape) const
{
    const Rectangle& rectangle = dynamic_cast<const Rectangle&>(shape);
    std::cout << "Perimeter: " << rectangle.getPerimeter() << std::endl;
}
