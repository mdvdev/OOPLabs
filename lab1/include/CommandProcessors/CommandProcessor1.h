#ifndef COMMANDPROCESSOR1_H
#define COMMANDPROCESSOR1_H

#include "CommandProcessor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Polygon.h"

class CommandProcessor1 : public CommandProcessor {
public:
    void process(InputHandler& inputHandler, std::istream& inputStream) override;

private:
    Circle* createCircle(std::istringstream& inputStream);
    Rectangle* createRectangle(std::istringstream& inputStream);
    Triangle* createTriangle(std::istringstream& inputStream);
    Polygon* createPolygon(std::istringstream& inputStream);
};

#endif // COMMANDPROCESSOR1_H
