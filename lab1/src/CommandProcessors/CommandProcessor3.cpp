#include <iostream>

#include "CommandProcessor3.h"
#include "Shape.h"
#include "InputHandler.h"

#include "lib.h"

void CommandProcessor3::process(InputHandler& inputHandler, std::istream& inputStream)
{
    size_t shapesSize = inputHandler.getShapesSize();
    for (size_t i = 0; i < shapesSize; ++i) {
        std::cout << i << " " << inputHandler.getShape(i)->getType() <<
            " Perimeter=" << floatToString(inputHandler.getShape(i)->getPerimeter()) << std::endl;
    }
}
