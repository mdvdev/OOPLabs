#include <iostream>

#include "CommandProcessor.h"
#include "InputHandler.h"
#include "SyntaxError.h"
#include "InvalidParams.h"

int InputHandler::start()
{
    int retCode = 0;
    try {
        // TODO how to exit from loop normally?
        for (;;) {
            std::string input = readInput(std::cin);
            std::istringstream inputStream(input);
            inputStream.exceptions(std::ios::failbit);
            int opcode = getOpcode(inputStream);
            // TODO convert factory to static method
            CommandProcessor* processor = factory.createCommandProcessor(opcode);
            processor->process(*this, inputStream);
        }
    } catch (const SyntaxError& e) {
        std::cout << e.what() << std::endl;
        retCode = 1;
    } catch (const InvalidParams& e) {
        std::cout << e.what() << std::endl;
        retCode = 1;
    } catch (const std::exception& e) {
        std::cout << "Unknown error type" << std::endl;
        retCode = 1;
    }
    return retCode;
}

int InputHandler::getOpcode(std::istringstream& inputStream) const
{
    int opcode;
    inputStream >> opcode;
    return opcode;
}

std::string InputHandler::readInput(std::istream& stream) const
{
    try {
        std::string input;
        stream >> input;
        return input;
    } catch (const std::ios_base::failure& e) {
        throw SyntaxError("Syntax error");
    }
}


void InputHandler::addShape(Shape* shape)
{
    shapes.push_back(shape);
}

void InputHandler::removeShape(int index)
{
    shapes.erase(shapes.begin() + index);
}

const std::vector<Shape*>& InputHandler::getShapes() const
{
    return shapes;
}
