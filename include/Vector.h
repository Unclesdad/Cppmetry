#pragma once

#include <initializer_list>

/// @brief Vector in two-space
class Vector {
public:
    /// @brief X component (first entry) of the vector.
    const double x;
    /// @brief Y component (second entry) of the vector.
    const double y;

    /// @brief Constructs the zero vector in two-space.
    Vector();

    /// @brief Constructs a two-dimensional vector.
    /// @param x The x component of the vector.
    /// @param y The y component of the vector.
    Vector(double x, double y);

    /// @brief Constructs a two-dimensional vector.
    /// @param magnitude The magnitude (length) of the vector.
    /// @param angle The angle of the vector to the horizontal.
    Vector(double magnitude, const Angle& angle);

    /// @return The magnitude (or length) of the vector.
    double magnitude() const;
};