#include <iostream>

#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Polygon.h"

#include "SyntaxError.h"

Shape* ShapeFactory::createShape(const std::string& shapeType, std::istream& inputStream)
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

Circle* ShapeFactory::createCircle(std::istream& inputStream)
{
    std::ios::iostate savedStreamState = inputStream.exceptions();
    inputStream.exceptions(std::istream::failbit);
    try {
        std::string name;
        inputStream >> name;
        Point center;
        inputStream >> center;
        float radius;
        inputStream >> radius;
        inputStream.exceptions(savedStreamState);
        return new Circle(name, center, radius);
    } catch (const std::ios_base::failure& fail) {
        inputStream.exceptions(savedStreamState);
        throw SyntaxError("Syntax error");
    } catch (const SyntaxError& e) {
        inputStream.exceptions(savedStreamState);
        throw e;
    }
}

Rectangle* ShapeFactory::createRectangle(std::istream& inputStream)
{
    std::ios::iostate savedStreamState = inputStream.exceptions();
    inputStream.exceptions(std::istream::failbit);
    try {
        std::string name;
        inputStream >> name;
        Point upperLeftAngle;
        inputStream >> upperLeftAngle;
        Point bottomRightPoint;
        inputStream >> bottomRightPoint;
        inputStream.exceptions(savedStreamState);
        return new Rectangle(name, upperLeftAngle, bottomRightPoint);
    } catch (const std::ios_base::failure& fail) {
        inputStream.exceptions(savedStreamState);
        throw SyntaxError("Syntax error");
    }
}

Triangle* ShapeFactory::createTriangle(std::istream& inputStream)
{
    std::ios::iostate savedStreamState = inputStream.exceptions();
    inputStream.exceptions(std::istream::failbit);
    try {
        std::string name;
        inputStream >> name;
        Point vertex1;
        inputStream >> vertex1;
        Point vertex2;
        inputStream >> vertex2;
        Point vertex3;
        inputStream >> vertex3;
        inputStream.exceptions(savedStreamState);
        return new Triangle(name, vertex1, vertex2, vertex3);
    } catch (const std::ios_base::failure& fail) {
        inputStream.exceptions(savedStreamState);
        throw SyntaxError("Syntax error");
    }
}

Polygon* ShapeFactory::createPolygon(std::istream& inputStream)
{
    std::ios::iostate savedStreamState = inputStream.exceptions();
    inputStream.exceptions(std::istream::failbit);
    try {
        std::string name;
        inputStream >> name;
        size_t verticesSize;
        inputStream >> verticesSize;
        std::vector<Point> vertices;
        for (size_t i = 0; i < verticesSize; ++i) {
            Point vertex;
            inputStream >> vertex;
            vertices.push_back(vertex);
        }
        inputStream.exceptions(savedStreamState);
        return new Polygon(name, vertices);
    } catch (const std::ios_base::failure& fail) {
        inputStream.exceptions(savedStreamState);
        throw SyntaxError("Syntax error");
    }
}
