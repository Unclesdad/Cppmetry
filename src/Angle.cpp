#include "Angle.h"
#include <cmath>
#include <numbers>
#include <limits>

const double Angle::PI = 3.14159265358979323846;

Angle::Angle() : rads(0), x(1), y(0) {}

Angle::Angle(double rads) : rads(std::fmod(rads, Angle::PI * 2)), x(cos(rads)), y(sin(rads)) {}

double Angle::sine() const {
    return y;
}

double Angle::cosine() const {
    return x;
}

double Angle::tangent() const {
    return x == 0 ? std::numeric_limits<double>::max() : y/x;
}

Angle Angle::operator+(const Angle& rhs) const {
    return Angle(rads + rhs.rads);
}

Angle Angle::operator-(const Angle& rhs) const {
    return Angle(rads - rhs.rads);
}

Angle Angle::operator*(double scalar) const {
    return Angle(rads * scalar);
}

Vector Angle::unit() const {
    return Vector(x, y);
}