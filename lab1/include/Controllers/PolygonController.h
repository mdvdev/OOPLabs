#ifndef POLYGONCONTROLLER_H
#define POLYGONCONTROLLER_H

#include "ShapeController.h"

class PolygonController : public ShapeController {
public:
    void printType() const override;
    void printParams(const Shape& shape) const override;
    void printPerimeter(const Shape& shape) const override;
};

#endif // POLYGONCONTROLLER_H
