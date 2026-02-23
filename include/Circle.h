#pragma once

#include "Shape.h"

class Circle : public Shape {
public:
    /// @brief The center point of the circle.
    const Point center;
    /// @brief The radius of the circle.
    const double radius;

    /// @brief Constructs a Circle.
    /// @param center The center point of the circle.
    /// @param radius The radius of the circle.
    Circle(const Point& center, double radius);

    bool intersectsPerimeter(const Line& line) const override;
};