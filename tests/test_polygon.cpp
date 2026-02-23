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

TEST(PolygonTests, IsConvex) {
    Point o{0,0};
    Point a{0,1};
    Point b{1,1};
    Point c{1,0};
    Point d{0.5,0.5};

    Polygon g{o,a,b,c};
    Polygon h{o,d,b,a};
    Polygon i{o,d,a};
    Polygon j{o,c,b,a};

    Polygon k{o,d,a,b,c};
    Polygon l{o,b,a,c};
    Polygon m{o,d,a,b,d,c};
    Polygon n{o,d,b};

    ASSERT_TRUE(g.isConvex());
    ASSERT_TRUE(h.isConvex());
    ASSERT_TRUE(i.isConvex());
    ASSERT_TRUE(j.isConvex());

    ASSERT_FALSE(k.isConvex());
    ASSERT_FALSE(l.isConvex());
    ASSERT_FALSE(m.isConvex());
    ASSERT_FALSE(n.isConvex());
}