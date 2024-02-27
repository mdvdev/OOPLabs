#ifndef TRIANGLECONTROLLER_H
#define TRIANGLECONTROLLER_H

#include "ShapeController.h"

class TriangleController : public ShapeController {
public:
    void printType() const override;
    void printParams(const Shape& shape) const override;
    void printPerimeter(const Shape& shape) const override;
};

#endif // TRIANGLECONTROLLER_H
