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
    static Shape* createShape(const std::string& shapeType, std::istream& inputStream);

private:
    static Circle* createCircle(std::istream& inputStream);
    static Rectangle* createRectangle(std::istream& inputStream);
    static Triangle* createTriangle(std::istream& inputStream);
    static Polygon* createPolygon(std::istream& inputStream);
};

#endif // SHAPEFACTORY_H
