#ifndef CIRCLECONTROLLER_H
#define CIRCLECONTROLLER_H

#include "ShapeController.h"

class CircleController : public ShapeController {
public:
    void printType() const override;
    void printParams(const Shape& shape) const override;
    void printPerimeter(const Shape& shape) const override;
};

#endif // CIRCLECONTROLLER_H
