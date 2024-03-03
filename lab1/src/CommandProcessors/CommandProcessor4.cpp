#include <iostream>

#include "CommandProcessor4.h"
#include "Shape.h"
#include "InputHandler.h"

void CommandProcessor4::process(InputHandler& inputHandler, std::istream& inputStream)
{
    size_t shapesSize = inputHandler.getShapesSize();
    float sum = 0;
    for (size_t i = 0; i < shapesSize; ++i) {
        sum += inputHandler.getShape(i)->getPerimeter();
    }
    std::cout << "Perimeter sum=" << sum << std::endl;
}

