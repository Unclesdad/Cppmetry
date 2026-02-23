#include <gtest/gtest.h>

#include "Polygon.h"

TEST(PolygonTests, PerimeterIntersection) {
    Point a{1,1};
    Point b{1,2};
    Point c{2,2};
    Point d{2,1};

    Line l(Point(0, 1.5), Point(1.5,1.5));
    Line m(Point(0,0), Point(1.5,1.5));
    Line n(Point(1.25, 1.25), Point(1.75,1.75));
    Line o(Point(0,1), Point(1,3));

    Polygon p{a,b,c,d};

    ASSERT_TRUE(p.intersectsPerimeter(l));
    ASSERT_TRUE(p.intersectsPerimeter(m));
    ASSERT_FALSE(p.intersectsPerimeter(n));
    ASSERT_FALSE(p.intersectsPerimeter(o));
}