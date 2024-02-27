#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(float x, float y);

    float getX() const;
    float getY() const;

    float getDistance(const Point& point) const;

private:
    float x;
    float y;
};

#endif // POINT_H
