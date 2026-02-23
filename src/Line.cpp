#include "Line.h"
#include "Point.h"
#include <algorithm>

Line::Line() : p1(), p2() {}

Line::Line(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}

Line::Line(const Point& p1, const Vector& v): p1(p1), p2(p1 + v) {}

bool Line::intersects(const Line& other, bool exclusive) const {
    const double EPS = 1e-12; // tolerance

    Vector v(toVector()); // l1 = vt + p1
    Vector u(other.toVector()); // l2 = us + other.p1

    if (v.magnitude() < EPS || u.magnitude() < EPS) return false; // Return false if significantly short

    Vector w(other.p1 - p1);

    double rxu = v.cross(u);

    if (std::abs(rxu) >= EPS) { // Confirm not parallel
        // Find parameter values of intersection
        double t = w.cross(u) / rxu;
        double s = w.cross(v) / rxu;

        return exclusive ? t > 0 && t < 1 && s > 0 && s < 1 : t >= 0 && t <= 1 && s >= 0 && s <= 1; // Return true if intersection is on both lines
    }

    if (std::abs(w.cross(v)) > EPS) return false; // Return false if parallel but not colinear

    double vv(v.dot(v));
    double t0(v.dot(w) / vv); // where start of other line lands on this one (as a parameter)
    double t1(t0 + v.dot(u) / vv); // where end of other line lands on this one (as a parameter)

    return exclusive ? std::max(t0,t1) > 0 && std::min(t0,t1) < 1 : std::max(t0, t1) >= -EPS && std::min(t0, t1) <= 1 + EPS; // return whether the lines overlap
}

Vector Line::toVector() const {
    return p2 - p1;
}