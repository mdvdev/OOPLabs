#include <vector>
#include <iostream>

#include "CommandProcessor4.h"
#include "Shape.h"
#include "InputHandler.h"

void CommandProcessor4::process(InputHandler& inputHandler, std::istream& inputStream)
{
    const std::vector<Shape*>& shapes = inputHandler.getShapes();
    float sum = 0;
    for (const auto& shape : shapes) {
        sum += shape->getPerimeter();
    }
    std::cout << "Perimeter sum=" << sum << std::endl;
}

