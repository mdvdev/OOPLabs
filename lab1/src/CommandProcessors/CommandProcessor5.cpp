#include "CommandProcessor5.h"
#include "InputHandler.h"

void CommandProcessor5::process(InputHandler& inputHandler, std::istream& inputStream)
{
    inputHandler.sortShapes();
}
