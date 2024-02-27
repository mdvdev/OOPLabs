#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "include/Point.h"

class Rectangle : public Shape {
public:
    Rectangle(const std::string& name, const Point& upperLeftAngle, const Point& bottomRightAngle);

    ShapeType getType() const override;
    float getPerimeter() const override;

    Point getUpperLeftAngle() const;
    Point getBottomRightAngle() const;

private:
    bool isValidParams(const Point& upperLeftAngle, const Point& bottomRightAngle) const;

    Point upperLeftAngle;
    Point bottomRightAngle;
};

#endif // RECTANGLE_H
