#include "Circle.h"

Circle::Circle(const Point& center, double radius) : center(center), radius(radius) {}

bool Circle::intersectsPerimeter(const Line& line) const {
    // check if one endpoint is on inside and one is on outside
    if (((line.p1 - center).magnitude() > radius) != ((line.p2 - center).magnitude() > radius)) return true;
    
    // check if line is a secant and intersects circle edge. nearest dist to line should be less than or eq to radius
    Vector endpointDisplacement = line.p2 - center;
    return (endpointDisplacement - endpointDisplacement.projectOnto(line.toVector())).magnitude() <= radius;
}