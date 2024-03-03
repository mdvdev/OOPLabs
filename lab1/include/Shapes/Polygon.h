#ifndef POLYGON_H
#define POLYGON_H

#include <vector>

#include "Shape.h"
#include "Point.h"

class Polygon : public Shape {
public:
    Polygon(const std::string& name, const std::vector<Point>& vertices);
    ~Polygon() = default;

    std::string toString() const override;
    float getPerimeter() const override;
    std::string getType() const override;

    std::vector<Point> getVertices() const;

private:
    constexpr static int minVertexNum = 3;
    std::vector<Point> vertices;
};

#endif // POLYGON_H
