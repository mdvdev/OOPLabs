#ifndef RECTANGLECONTROLLER_H
#define RECTANGLECONTROLLER_H

#include "ShapeController.h"

class RectangleController : public ShapeController {
public:
    void printType() const override;
    void printParams(const Shape& shape) const override;
    void printPerimeter(const Shape& shape) const override;
};

#endif // RECTANGLECONTROLLER_H
