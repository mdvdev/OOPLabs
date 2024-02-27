#include "Shape.h"

Shape::Shape(const std::string& name)
    : name(name)
{
}

const std::string& Shape::getName() const
{
    return name;
}
