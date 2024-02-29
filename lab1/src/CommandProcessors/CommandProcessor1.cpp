#include "CommandProcessor1.h"
#include "InputHandler.h"
#include "ShapeFactory.h"

void CommandProcessor1::process(InputHandler& inputHandler, std::istringstream& inputStream)
{
    std::string shapeType;
    inputStream >> shapeType;
    Shape* shape = ShapeFactory::createShape(shapeType, inputStream);
    inputHandler.addShape(shape);
}
