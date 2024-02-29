#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
public:
    Point(float x, float y);
    Point();

    std::string toString() const;

    float getX() const;
    void setX(float x);

    float getY() const;
    void setY(float y);

    float getDistance(const Point& point) const;

private:
    float x;
    float y;
};

#endif // POINT_H

std::istream& operator>>(std::istream& is, Point& point);
