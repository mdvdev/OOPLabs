#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <vector>

class Shape;

class InputHandler {
public:
    ~InputHandler();

    int start();

    size_t getShapesSize() const;

    void sortShapes();
    void addShape(Shape* shape);
    void removeShape(size_t index);
    const Shape* getShape(size_t index) const;

private:
    std::vector<Shape*> shapes;

    int getOpcode(std::istream& inputStream) const;
    void printMenu() const;
};

#endif // INPUTHANDLER_H
