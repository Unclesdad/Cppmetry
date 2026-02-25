#include "Circle.h"
#include "Angle.h"

Circle::Circle(const Point& center, double radius) : center(center), radius(radius) {}

bool Circle::intersectsPerimeter(const Line& line) const {
    // check if one endpoint is on inside and one is on outside
    Vector endpointDisplacement(line.p1 - center);
    Vector lineVector(line.toVector());

    if (((endpointDisplacement).magnitude() > radius) != ((line.p2 - center).magnitude() > radius)) return true;
    if ((endpointDisplacement).magnitude() < radius) return false; // both are same side; if one is inside circle then both are
    
    // Both endpoints are outside circle
    // calculate parameter t on line where closest to center of circle
    double t(lineVector.dot(center - line.p1) / lineVector.dot(lineVector));

    // check if closest point is on line, then check if closest point is within circle
    return t >= 0 && t <= 1 && ((line.p1 + (t * lineVector)) - center).magnitude() <= radius;
}

double Circle::area() const {
    // A = pi r^2
    return Angle::PI * radius * radius;
}

Circle* Circle::rotateAround(const Point& p, const Angle& rotation) const {
    return new Circle(p + (center - p).rotate(rotation), radius);
}