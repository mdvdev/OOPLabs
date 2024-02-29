#include <sstream>

#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "SyntaxError.h"

Shape* ShapeFactory::createShape(const std::string& shapeType, std::istringstream& inputStream)
{
    if (shapeType == "Circle") {
        return createCircle(inputStream);
    } else if (shapeType == "Rectangle") {
        return createRectangle(inputStream);
    } else if (shapeType == "Triangle") {
        return createTriangle(inputStream);
    } else if (shapeType == "Polygon") {
        return createPolygon(inputStream);
    } else {
        throw SyntaxError("Syntax error");
    }
}

Circle* ShapeFactory::createCircle(std::istringstream& inputStream)
{
    try {
        std::string name;
        inputStream >> name;
        Point center;
        inputStream >> center;
        float radius;
        inputStream >> radius;
        return new Circle(name, center, radius);
    } catch (const std::ios_base::failure& e) {
        throw SyntaxError("Syntax error");
    }
}

Rectangle* ShapeFactory::createRectangle(std::istringstream& inputStream)
{
    try {
        std::string name;
        inputStream >> name;
        Point upperLeftAngle;
        inputStream >> upperLeftAngle;
        Point bottomRightPoint;
        inputStream >> bottomRightPoint;
        return new Rectangle(name, upperLeftAngle, bottomRightPoint);
    } catch (const std::ios_base::failure& e) {
        throw SyntaxError("Syntax error");
    }

}

Triangle* ShapeFactory::createTriangle(std::istringstream& inputStream)
{
    try {
        std::string name;
        inputStream >> name;
        Point vertex1;
        inputStream >> vertex1;
        Point vertex2;
        inputStream >> vertex2;
        Point vertex3;
        inputStream >> vertex3;
        return new Triangle(name, vertex1, vertex2, vertex3);
    } catch (const std::ios_base::failure& e) {
        throw SyntaxError("Syntax error");
    }
}

Polygon* ShapeFactory::createPolygon(std::istringstream& inputStream)
{
    try {
        std::string name;
        inputStream >> name;
        std::vector<Point> vertices;
        Point vertex;
        while (inputStream >> vertex) {
            vertices.push_back(vertex);
        }
        return new Polygon(name, vertices);
    } catch (const std::ios_base::failure& e) {
        throw SyntaxError("Syntax error");
    }
}
