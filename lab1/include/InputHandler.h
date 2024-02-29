#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <vector>
#include <sstream>

#include "CommandProcessorFactory.h"

class Shape;

class InputHandler {
public:
    int start();

    const std::vector<Shape*>& getShapes() const;

    void addShape(Shape* shape);
    void removeShape(int index);

private:
    std::vector<Shape*> shapes;
    CommandProcessorFactory factory;

    std::string readInput(std::istream& stream) const;
    int getOpcode(std::istringstream& inputStream) const;
};

#endif // INPUTHANDLER_H
