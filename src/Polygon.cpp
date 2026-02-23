#include "Polygon.h"
#include <functional>
#include <cmath>

std::vector<Line> linesFromPoints(std::vector<Point> pts) {
    std::vector<Line> lineList;
    for (size_t i = 0; i < pts.size(); i++) {
        lineList.push_back(Line(pts[i], pts[(i + 1) % pts.size()]));
    }
    return lineList;
}

Polygon::Polygon(std::initializer_list<Point> pts) : vertices(pts), lines(linesFromPoints(vertices)) {}

bool Polygon::intersectsPerimeter(const Line& line) const {
    for (Line side : lines) {
        if (side.intersects(line)) return true;
    }
    return false;
}

int sign(double in) {
    if (in > 0) return 1;
    if (in < 0) return -1;
    return 0;
}

bool Polygon::isConvex() const {
    /// determines if two signs are different (false if either is zero, so zero is like a wildcard)
    std::function<bool(double, double)> signChange = [](double in1, double in2) {return std::abs(sign(in1) - sign(in2)) > 1;};
    double last = 0;
    for (size_t i = 0; i < lines.size(); i++) {
        double concavity = lines[i].toVector().cross(lines[(i+1) % lines.size()].toVector());
        if (signChange(concavity, last)) return false;
        last = concavity;
    }
    return true;
}