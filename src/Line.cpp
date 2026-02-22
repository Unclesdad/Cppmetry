#include "Line.h"

Line::Line() : p1(Point()), p2(Point()) {}

Line::Line(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}

Line::Line(const Point& p1, const Vector& v): p1(p1), p2(p1 + v) {}

bool Line::intersects(const Line& other) {
    return false; // TODO will do later
}

Vector Line::toVector() {
    return p2 - p1;
}