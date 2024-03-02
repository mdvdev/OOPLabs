#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
public:
    Circle(const std::string& name, const Point& center, float radius);
    ~Circle() = default;

    std::string toString() const override;
    float getPerimeter() const override;
    std::string getType() const override;

    Point getCenter() const;
    float getRadius() const;

private:
    bool isValidParams(const Point& center, float radius) const;

    Point center;
    float radius;
};

#endif // CIRCLE_H
