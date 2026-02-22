#pragma once

#include "Vector.h"

class Angle {
public:
    /// @brief The beloved circumference / diameter
    const static double PI;

    /// @brief The radian value of the angle. Always limited to [0, 2PI).
    const double rads; 

private:
    /// @brief cos, calculated in advance
    const double x;
    /// @brief sin, calculated in advance
    const double y;

public:
    /// @brief Constructs an angle of zero radians (x=1, y=0).
    Angle();

    /// @brief Constructs an Angle with the given amount of radians.
    /// @param rads The angle, in radians.
    Angle(double rads);

    /// @return The sine of the angle.
    double sine() const;

    /// @return The cosine of the angle.
    double cosine() const;

    /// @return The tangent of the angle. If undefined, returns the maximum double value.
    double tangent() const;

    /// @brief Adds another angle on top of this one.
    /// @param rhs The angle to add.
    /// @return The sum of the two rotations.
    Angle operator+(const Angle& rhs) const;

    /// @brief Subtracts an angle from this one.
    /// @param rhs The angle to subtract.
    /// @return This rotation minus the subtracted rotation.
    Angle operator-(const Angle& rhs) const;

    /// @brief Multiplies this angle by a scalar multiple.
    /// @param scalar The scalar for this angle.
    /// @return 
    Angle operator*(double scalar) const;

    /// @return Returns the unit vector of this angle
    Vector unit() const;
};