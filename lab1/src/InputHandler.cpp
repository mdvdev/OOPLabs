#include <iostream>
#include <limits>

#include "CommandProcessor.h"
#include "InputHandler.h"
#include "SyntaxError.h"
#include "InvalidParams.h"
#include "EndOfFileException.h"

int InputHandler::start()
{
    int retCode = 0;
    for (;;) {
        try {
            int opcode = getOpcode(std::cin);
            // TODO convert factory to static method
            CommandProcessor* processor = factory.createCommandProcessor(opcode);
            processor->process(*this, std::cin);
        } catch (const SyntaxError& e) {
            std::cout << e.what() << std::endl;
            resetInputStream(std::cin);
        } catch (const InvalidParams& e) {
            std::cout << e.what() << std::endl;
            resetInputStream(std::cin);
        } catch (const EndOfFileException& e) {
            std::cout << e.what() << std::endl;
            break;
        } catch (const std::exception& e) {
            std::cout << "Unknown error type" << std::endl;
            retCode = 1;
            break;
        }
    }

    return retCode;
}

int InputHandler::getOpcode(std::istream& inputStream) const
{
    int opcode;
    if (!(inputStream >> opcode)) {
        if (inputStream.eof()) {
            throw EndOfFileException("Bye!");
        } else {
            throw SyntaxError("Syntax error");
        }
    }
    return opcode;
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

void InputHandler::setShapes(const std::vector<Shape*>& shapes)
{
    this->shapes = shapes;
}

void InputHandler::resetInputStream(std::istream& inputStream) const
{
    inputStream.clear();
    inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
