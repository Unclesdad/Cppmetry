#include "Circle.h"

Circle::Circle(const Point& center, double radius) : center(center), radius(radius) {}

bool Circle::intersectsPerimeter(const Line& line) const {
    return ((line.p1 - center).magnitude() > radius) != ((line.p2 - center).magnitude() > radius);
}

bool Circle::isConvex() const {
    return true;
}