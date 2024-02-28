#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Point.h"

class Triangle : public Shape {
public:
    Triangle(const std::string& name, const Point& vertex1, const Point& vertex2, const Point& vertex3);

    ShapeType getType() const override;
    float getPerimeter() const override;

    Point getVertex1() const;
    Point getVertex2() const;
    Point getVertex3() const;

private:
    bool isValidParams(const Point& vertex1, const Point& vertex2, const Point& vertex3);
    bool isValidTriangleInequality(const Point& vertex1, const Point& vertex2, const Point& vertex3);

    Point vertex1;
    Point vertex2;
    Point vertex3;
};

#endif // TRIANGLE_H
