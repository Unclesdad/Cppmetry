#include "Angle.h"
#include <cmath>
#include <numbers>
#include <limits>

Angle::Angle() : rads(0), x(1), y(0) {}

Angle::Angle(double rads) : rads(std::fmod(rads, Angle::PI * 2)), x(cos(rads)), y(sin(rads)) {}

double Angle::sine() {
    return y;
}

double Angle::cosine() {
    return x;
}

double Angle::tangent() {
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