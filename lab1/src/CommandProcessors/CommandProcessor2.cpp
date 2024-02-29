#include <vector>
#include <iostream>

#include "CommandProcessor2.h"
#include "Shape.h"
#include "InputHandler.h"

void CommandProcessor2::process(InputHandler& inputHandler, std::istringstream& inputStream)
{
    const std::vector<Shape*>& shapes = inputHandler.getShapes();
    for (const auto& shape : shapes) {
        std::cout << shape->toString() << std::endl;
    }
}
