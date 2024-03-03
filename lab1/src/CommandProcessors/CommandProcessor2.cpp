#include <iostream>

#include "CommandProcessor2.h"
#include "Shape.h"
#include "InputHandler.h"

void CommandProcessor2::process(InputHandler& inputHandler, std::istream& inputStream)
{
    size_t shapesSize = inputHandler.getShapesSize();
    for (size_t i = 0; i < shapesSize; ++i) {
        std::cout << i << " " << inputHandler.getShape(i)->toString() << std::endl;
    }
}
