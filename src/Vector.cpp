#include "Vector.h"
#include <cmath>
#include "Angle.h"

Vector::Vector() : x(0), y(0) {}

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector::Vector(double magnitude, const Angle& angle) : x(magnitude * angle.cosine()), y(magnitude * angle.sine()) {}

double Vector::magnitude() const {
    return std::hypot(x, y);
}

Angle Vector::angle() const {
    return Angle(atan2(y, x));
}

Vector Vector::operator+(const Vector& rhs) const {
    return Vector(x + rhs.x, y + rhs.y);
}

Vector Vector::operator-(const Vector& rhs) const {
    return Vector(x - rhs.x, y - rhs.y);
}

Vector Vector::operator*(double rhs) const {
    return Vector(rhs * x, rhs * y);
}

Vector operator*(double lhs, const Vector& rhs) {
    return rhs * lhs;
}

bool Vector::operator==(const Vector& rhs) const {
    return x == rhs.x && y == rhs.y;
}

double Vector::dot(const Vector& other) const {
    return x * other.x + y * other.y;
}

double Vector::cross(const Vector& other) const {
    return x * other.y - y * other.x;
}