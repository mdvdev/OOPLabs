#include <vector>
#include <iostream>

#include "CommandProcessor2.h"
#include "Shape.h"
#include "InputHandler.h"

void CommandProcessor2::process(InputHandler& inputHandler, std::istream& inputStream)
{
    const std::vector<Shape*>& shapes = inputHandler.getShapes();
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << i << " " << shapes[i]->toString() << std::endl;
    }
}
