#pragma once

#include "Shape.h"

class Circle : public Shape {
public:
    const Point center;
    const double radius;

    Circle(const Point& center, double radius);

    bool intersectsPerimeter(const Line& line) const override;

    bool isConvex() const override;
};