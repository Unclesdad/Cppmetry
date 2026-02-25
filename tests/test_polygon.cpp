#include <gtest/gtest.h>

#include "Polygon.h"
#include "Angle.h"

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

TEST(PolygonTests, Area) {
    Point o(0,0);
    Point a(2,0);
    Point b(3,5);
    Point c(1,1);
    Point d(2,1);
    Point e(0,2);
    Point f(2,2);

    Polygon square{o,a,f,e};
    ASSERT_EQ(square.area(), 4);

    Polygon pointy{o,a,b,c,d,e};
    ASSERT_EQ(pointy.area(), 5.5);

    Polygon invertedPointy{o,e,d,c,b,a};
    ASSERT_EQ(invertedPointy.area(), 5.5);

    // translation
    Vector v(5,5);

    Polygon translatedPointy{o+v, a+v, b+v, c+v, d+v, e+v};
    ASSERT_EQ(translatedPointy.area(), 5.5);

    Polygon basicallyALine{o,c,f};
    ASSERT_EQ(basicallyALine.area(), 0);

    Polygon multipleSamePoint{o,o,a,f,f,e};
    ASSERT_EQ(multipleSamePoint.area(), 4);
}

TEST(PolygonTests, Rotation) {
    double EPS = 1e-12;
    Polygon square{Point(1,1), Point(1,2), Point(2,2), Point(2,1)};

    Polygon* theSame(square.rotateAround(Point(1.5,1.5), Angle(Angle::PI / 2)));
    for (size_t i = 0; i < 4; i++) {
        // index is off by 1 but the shape remains the same
        ASSERT_NEAR(square.vertices[i].x, theSame->vertices[(i+1) % 4].x, EPS);
        ASSERT_NEAR(square.vertices[i].y, theSame->vertices[(i+1) % 4].y, EPS);
    }
    delete theSame;

    Polygon* aboutOrigin(square.rotateAround(Point(), Angle(Angle::PI)));
    for (size_t i = 0; i < 4; i++) {
        ASSERT_NEAR(square.vertices[i].x, -aboutOrigin->vertices[i].x, EPS);
        ASSERT_NEAR(square.vertices[i].y, -aboutOrigin->vertices[i].y, EPS);
    }
    delete aboutOrigin;

    // crazy shape
    Polygon something{Point(20,2), Point(-2,4), Point(4,-7), Point(3, 3), Point(2, -10), Point(2,4)};
    Polygon* somethingRotated(something.rotateAround(Point(),Angle(5)));
    // rotation should not change area
    ASSERT_NEAR(something.area(), somethingRotated->area(), EPS);
    delete somethingRotated;
}