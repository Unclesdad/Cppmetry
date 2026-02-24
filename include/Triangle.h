#pragma once

#include "Point.h"
#include "Polygon.h"

class Triangle : public Polygon {
private:
    // Vectors representing the sides
    Vector v1;
    Vector v2;
public:
    Triangle(Point pt1, Point pt2, Point pt3);

    bool isConvex() const;
};