#include "Vector.h"
#include <cmath>

Vector::Vector() : x(0), y(0) {}

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::magnitude() {
    return std::hypot(x, y);
}