#include "Triangle.h"

Triangle::Triangle(Point pt1, Point pt2, Point pt3) : Polygon{pt1,pt2,pt3}, v1(pt2-pt1), v2(pt3-pt1) {}

bool Triangle::isConvex() const {
    return v1.cross(v2) != 0;
}