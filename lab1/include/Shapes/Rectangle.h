#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape {
public:
    Rectangle(const std::string& name, const Point& upperLeftPoint, const Point& bottomRightPoint);

    std::string toString() const override;
    float getPerimeter() const override;

    Point getUpperLeftAngle() const;
    Point getBottomRightAngle() const;

private:
    bool isValidParams(const Point& upperLeftPoint, const Point& bottomRightPoint) const;

    Point upperLeftPoint;
    Point bottomRightPoint;
};

#endif // RECTANGLE_H
