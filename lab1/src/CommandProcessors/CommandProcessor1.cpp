#include "CommandProcessor1.h"
#include "InputHandler.h"
#include "ShapeFactory.h"
#include "SyntaxError.h"

void CommandProcessor1::process(InputHandler& inputHandler, std::istream& inputStream)
{
    std::string shapeType;
    if (!(inputStream >> shapeType)) {
        throw SyntaxError("Syntax error");
    }
    Shape* shape = ShapeFactory::createShape(shapeType, inputStream);
    inputHandler.addShape(shape);
}
