#ifndef SHAPECONTROLLER_H
#define SHAPECONTROLLER_H

#include "Shape.h"

class ShapeController {
public:
    virtual void printType() const = 0;
    virtual void printParams(const Shape& shape) const = 0;
    virtual void printPerimeter(const Shape& shape) const = 0;

    virtual ~ShapeController();
};

#endif // SHAPECONTROLLER_H
