#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    Shape(const std::string& name);
    virtual ~Shape() = default;

    virtual std::string toString() const = 0;
    virtual float getPerimeter() const = 0;
    virtual std::string getType() const = 0;


protected:
    std::string name;
};

#endif // SHAPE_H
