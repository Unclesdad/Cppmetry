#pragma once

#include "Vector.h"

class Point {
public:
    /// @brief x-coordinate of the point.
    const double x;
    /// @brief y-coordinate of the point.
    const double y;

    /// @brief Constructs a point at (0,0).
    Point();

    /// @brief Constructs a point at (x,y).
    /// @param x The x-coordinate of the point.
    /// @param y The y-coordinate of the point.
    Point(double x, double y);

    /// @brief Constructs a point translated from the origin by a vector. 
    /// The set of points in two-space is isomorphic to R2 after all.
    /// @param vector The vector of translation from the origin.
    Point(const Vector& vector);

    /// @brief Finds the displacement between two points as a vector.
    /// @param rhs The starting point.
    /// @return The displacement between two points.
    Vector operator-(const Point& rhs) const;
};