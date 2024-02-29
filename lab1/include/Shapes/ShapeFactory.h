#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <string>

class Shape;
class Circle;
class Rectangle;
class Triangle;
class Polygon;

class ShapeFactory {
public:
    static Shape* createShape(const std::string& shapeType, std::istringstream& inputStream);

private:
    static Circle* createCircle(std::istringstream& inputStream);
    static Rectangle* createRectangle(std::istringstream& inputStream);
    static Triangle* createTriangle(std::istringstream& inputStream);
    static Polygon* createPolygon(std::istringstream& inputStream);
};

#endif // SHAPEFACTORY_H
