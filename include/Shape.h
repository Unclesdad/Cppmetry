#pragma once

#include "Line.h"

class Shape {
public:
    virtual ~Shape() {}

    /// @brief Checks whether or not a line segment intersects the perimeter of this Shape. 
    /// @param line The line to check.
    /// @return True if there is an intersection, False if none.
    virtual bool intersectsPerimeter(const Line& line) const = 0;

    /// @brief Checks whether or not this Shape is convex.
    /// @return True if convex, false if none.
    virtual bool isConvex() const = 0;
};