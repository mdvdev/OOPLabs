#include <iostream>
#include <algorithm>

#include "InputHandler.h"

#include "CommandProcessorFactory.h"
#include "CommandProcessor.h"

#include "SyntaxError.h"
#include "InvalidParams.h"
#include "EndOfFileException.h"

#include "Shape.h"
#include "lib.h"

int InputHandler::start()
{
    int retCode = 0;
    for (;;) {
        try {
            int opcode = getOpcode(std::cin);
            CommandProcessor* processor = CommandProcessorFactory::createCommandProcessor(opcode);
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

void InputHandler::removeShape(size_t index)
{
    shapes.erase(shapes.begin() + index);
}

InputHandler::~InputHandler()
{
    for (auto& shape : shapes) {
        delete shape;
    }
}

size_t InputHandler::getShapesSize() const
{
    return shapes.size();
}

const Shape* InputHandler::getShape(size_t index) const
{
    return shapes.at(index);
}

void InputHandler::sortShapes()
{
    std::sort(shapes.begin(), shapes.end(),
        [](const Shape* a, const Shape* b) -> bool
        {
            return a->getPerimeter() < b->getPerimeter();
        });
}
