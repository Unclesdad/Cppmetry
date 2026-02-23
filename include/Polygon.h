#pragma once

#include "Shape.h"
#include <vector>
#include "Line.h"
#include <initializer_list>

class Polygon : public Shape {
public:
    /// @brief The vertices (corners) of the Polygon as an ORDERED list.
    const std::vector<Point> vertices;
    /// @brief The lines (sides) of the Polygon as an ORDERED list.
    const std::vector<Line> lines;

    /// @brief Constructs a Polygon.
    /// @param pts The vertices of the polygon, ordered.
    Polygon(std::initializer_list<Point> pts);

    bool intersectsPerimeter(const Line& line) const override;

    /// @brief Checks whether or not this Polygon is convex.
    /// This means that the concavity of the sides should not change signs. 
    /// If the any of the sides intersect with another side, then it is not convex.
    /// @return True if convex, false if none.
    bool isConvex() const;
};