#include "CommandProcessor7.h"
#include "InputHandler.h"
#include "Shape.h"
#include "SyntaxError.h"

void CommandProcessor7::process(InputHandler& inputHandler, std::istream& inputStream)
{
    const std::vector<Shape*>& shapes = inputHandler.getShapes();
    float perimeterMax;
    if (!(inputStream >> perimeterMax)) {
        throw SyntaxError("Syntax error");
    }
    for (size_t i = 0; i < shapes.size(); ++i) {
        if (shapes[i]->getPerimeter() > perimeterMax) {
            inputHandler.removeShape(i);
        }
    }
}
