#pragma once

#include "Shape.h"
#include <vector>
#include "Line.h"
#include <initializer_list>

class Polygon : public Shape {
public:
    const std::vector<Point> vertices;
    const std::vector<Line> lines;

    Polygon(std::initializer_list<Point> pts);

    bool intersectsPerimeter(const Line& line) const override;

    bool isConvex() const override;
};