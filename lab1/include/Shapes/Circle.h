#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "include/Point.h"

class Circle : public Shape {
public:
    Circle(const std::string& name, const Point& center, float radius);

    ShapeType getType() const override;
    float getPerimeter() const override;

    Point getCenter() const;
    float getRadius() const;

private:
    bool isValidParams(const Point& center, float radius) const;

    Point center;
    float radius;
};

#endif // CIRCLE_H
