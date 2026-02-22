#include "Line.h"
#include "Point.h"

Line::Line() : p1(), p2() {}

Line::Line(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}

Line::Line(const Point& p1, const Vector& v): p1(p1), p2(p1 + v) {}

bool Line::intersects(const Line& other) const {
    
}

Vector Line::toVector() const {
    return p2 - p1;
}