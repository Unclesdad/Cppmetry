#include "Shape.h"

Shape::Containment Shape::lineInside(const Line& line) const {
    if (intersectsPerimeter(line)) return Containment::PARTIAL;
    if (pointInside(line.p1)) return Containment::CONTAINED; // if no intersection and one point inside, both inside
    return Containment::SEPARATE;
}