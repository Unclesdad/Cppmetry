#pragma once

#include "Point.h"
#include "Vector.h"

class Line {
public:
    const Point& p1;
    const Point& p2;

    Line();

    Line(const Point& p1, const Point& p2);

    Line(const Point& p1, const Vector& v);

    bool intersects(const Line& other);

    Vector toVector();
};