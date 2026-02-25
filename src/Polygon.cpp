#include "Polygon.h"
#include <functional>
#include <cmath>
#include "Angle.h"

std::vector<Line> linesFromPoints(std::vector<Point> pts) {
    std::vector<Line> lineList;
    for (size_t i = 0; i < pts.size(); i++) {
        lineList.push_back(Line(pts[i], pts[(i + 1) % pts.size()]));
    }
    return lineList;
}

Polygon::Polygon(std::initializer_list<Point> pts) : vertices(pts), lines(linesFromPoints(vertices)) {}

Polygon::Polygon(std::vector<Point> pts) : vertices(pts), lines(linesFromPoints(pts)) {}

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

        for (size_t j = i + 1; j < lines.size(); j++) {
            // assure no lines intersect
            if (lines[i].intersects(lines[j], true)) return false;
        }
    }
    return true;
}

double Polygon::area() const {
    double cumulative = 0;
    for (size_t i = 1; i < vertices.size() - 1; i++) {
        // shoelace theorem. crossing becomes area of parallelogram (double that of the triangle)
        cumulative += (vertices[i] - vertices[0]).cross(vertices[i+1] - vertices[0]);
    }
    return std::abs(cumulative / 2);
}

Shape* Polygon::rotateAround(const Point& p, const Angle& rotation) const {
    std::vector<Point> rotated;
    rotated.reserve(vertices.size());
    std::transform(vertices.begin(), vertices.end(), std::back_inserter(rotated), [&p, &rotation](const Point& vertex) { return p + (vertex - p).rotate(rotation); });
    return new Polygon(rotated);
}