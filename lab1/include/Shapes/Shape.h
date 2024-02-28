#ifndef SHAPE_H
#define SHAPE_H

#include <string>

#include "ShapeType.h"

class Shape {
public:
    Shape(const std::string& name);

    const std::string& getName() const;
    virtual ShapeType getType() const = 0;
    virtual float getPerimeter() const = 0;
    // add method getParams as toStdString in Java

    virtual ~Shape();

private:
    std::string name;
};

#endif // SHAPE_H
