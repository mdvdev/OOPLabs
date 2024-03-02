#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <vector>

#include "CommandProcessorFactory.h"

class Shape;

class InputHandler {
public:
    int start();

    const std::vector<Shape*>& getShapes() const;

    void setShapes(const std::vector<Shape*>& shapes);

    void addShape(Shape* shape);
    void removeShape(int index);

private:
    std::vector<Shape*> shapes;
    CommandProcessorFactory factory;

    int getOpcode(std::istream& inputStream) const;
    void resetInputStream(std::istream& inputStream) const;
};

#endif // INPUTHANDLER_H
