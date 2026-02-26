#pragma once

#include "Line.h"

class Shape {
public:
    enum Containment {SEPARATE, CONTAINED, PARTIAL};

    virtual ~Shape() {}

    /// @brief Checks whether or not a line segment intersects the perimeter of this Shape. 
    /// @param line The line to check.
    /// @return True if there is an intersection, False if none.
    virtual bool intersectsPerimeter(const Line& line) const = 0;

    /// @return The area of the Shape.
    virtual double area() const = 0;

    /// @brief Rotates this Shape around a point.
    /// @param p The point to rotate around.
    /// @param rotation The amount to rotate.
    /// @return A pointer to the rotated Shape in memory.
    virtual Shape* rotateAround(const Point& p, const Angle& rotation) const = 0;

    /// @brief Finds whether or not a point is inside the area of this Shape.
    /// @param p The point to check.
    /// @return True if the point is inside, false if not.
    virtual bool pointInside(const Point& p) const = 0;
    
    /// @brief Finds whether or not a line is fully contained within the area of this Shape.
    /// @param line The line to check.
    /// @return True if the line is inside, false if not.
    Containment lineInside(const Line& line) const;
};