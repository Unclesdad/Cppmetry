#pragma once

class Angle;

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

    /// @return The angle of the vector with the horizontal.
    Angle angle() const;

    /// @brief Adds two vectors.
    /// @param rhs The vector to add to the vector on the left side of the addition sign.
    /// @return The sum of two vectors.
    Vector operator+(const Vector& rhs) const;

    /// @brief Subtracts two vectors.
    /// @param rhs The vector to subtract from the vector on the left of the addition sign.
    /// @return The difference of two vectors.
    Vector operator-(const Vector& rhs) const;

    /// @brief Multiplies a vector by a scalar.
    /// @param rhs The scalar multiple.
    /// @return The scalar multiplication of this vector.
    Vector operator*(double rhs) const;

    /// @brief Multiplies a vector by a scalar.
    /// @param lhs The scalar multiple.
    /// @param rhs The vector to scalar multiply.
    /// @return The scalar multiplication of a vector.
    friend Vector operator*(double lhs, const Vector& rhs);

    /// @return True if the two vectors are equal, false if they are not.
    bool operator==(const Vector& rhs) const;

    /// @brief Calculates the dot product of this vector with another.
    /// @param rhs The vector to dot with.
    /// @return The dot product of two vectors.
    double dot(const Vector& other) const;

    /// @brief Calculates the z-value of the cross product of this vector with another.
    /// @param rhs the vector to cross with.
    /// @return The signed value of the cross product of two vectors.
    double cross(const Vector& other) const;
};