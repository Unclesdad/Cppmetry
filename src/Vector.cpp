#include "Vector.h"
#include <cmath>
#include "Angle.h"

Vector::Vector() : x(0), y(0) {}

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector::Vector(double magnitude, const Angle& angle) : x(magnitude * angle.cosine()), y(magnitude * angle.sine()) {}

double Vector::magnitude() const {
    return std::hypot(x, y);
}