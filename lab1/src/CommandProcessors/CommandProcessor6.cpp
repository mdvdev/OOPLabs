#include "CommandProcessor6.h"
#include "InputHandler.h"
#include "SyntaxError.h"
#include "lib.h"

void CommandProcessor6::process(InputHandler& inputHandler, std::istream& inputStream)
{
    int index;
    if (!(inputStream >> index)) {
        throw SyntaxError("Syntax error");
    }
    inputHandler.removeShape(index);
    resetInputStream(inputStream);
}
