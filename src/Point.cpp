#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Vector& vector) : x(vector.x), y(vector.y) {}

Vector Point::operator-(const Point& rhs) const {
    return Vector(x - rhs.x, y - rhs.y);
}