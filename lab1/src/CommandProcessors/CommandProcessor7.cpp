#include "CommandProcessor7.h"
#include "InputHandler.h"
#include "Shape.h"
#include "SyntaxError.h"
#include "lib.h"

void CommandProcessor7::process(InputHandler& inputHandler, std::istream& inputStream)
{
    float perimeterMax;
    if (!(inputStream >> perimeterMax)) {
        throw SyntaxError("Syntax error");
    }
    size_t shapesSize = inputHandler.getShapesSize();
    for (size_t i = 0; i < shapesSize; ) {
        if (inputHandler.getShape(i)->getPerimeter() > perimeterMax) {
            inputHandler.removeShape(i);
            shapesSize--;
        } else {
            i++;
        }
    }
    resetInputStream(inputStream);
}
