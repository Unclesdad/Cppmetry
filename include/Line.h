#pragma once

#include "Point.h"
#include "Vector.h"

/// @brief A line segment in 2d space.
class Line {
public:
    /// @brief Starting point of the line segment.
    const Point& p1;
    /// @brief Ending point of the line segment.
    const Point& p2;

    /// @brief Constructs a line with both endpoints at (0,0).
    Line();

    /// @brief Constructs a line with two endpoints.
    /// @param p1 The starting point.
    /// @param p2 The ending point.
    Line(const Point& p1, const Point& p2);

    /// @brief Constructs a line from a starting point and a vector.
    /// @param p1 The starting point.
    /// @param v The vector to translate the starting point by.
    Line(const Point& p1, const Vector& v);

    /// @brief Finds whether or not this line segment intersects another line segment.
    /// @param other The other line segment to compare to.
    /// @return True if the two line segments intersect, false if they don't.
    bool intersects(const Line& other);

    /// @return A vector representing the displacement between the two endpoints.
    Vector toVector();
};