#include <vector>
#include <iostream>

#include "CommandProcessor3.h"
#include "Shape.h"
#include "InputHandler.h"

void CommandProcessor3::process(InputHandler& inputHandler, std::istringstream& inputStream)
{
    const std::vector<Shape*>& shapes = inputHandler.getShapes();
}
