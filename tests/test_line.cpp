#include <gtest/gtest.h>
#include "Line.h"

TEST(LineTests, Intersection) {
    Point o(0,0);
    Point a(1,1);
    Point b(2,2);
    Point c(5,5);
    Point d(1,0);
    Point e(0,1);
    Point f(2,1);

    Point g(0.25, 0.5);
    Point h(0.75, 1);

    Point d2(5,0);
    Point e2(0,5);

    ASSERT_TRUE(Line(a,b).intersects(Line(o,c)));
    ASSERT_TRUE(Line(o,b).intersects(Line(a,c)));
    ASSERT_TRUE(Line(o,a).intersects(Line(a,f)));
    ASSERT_TRUE(Line(o,a).intersects(Line(d,e)));
    ASSERT_TRUE(Line(o,f).intersects(Line(d,a)));

    ASSERT_FALSE(Line(d,f).intersects(Line(o,a)));
    ASSERT_FALSE(Line(g,h).intersects(Line(o,c)));
    ASSERT_FALSE(Line(o,a).intersects(Line(b,c)));
    ASSERT_FALSE(Line(d2,e2).intersects(Line(o,a)));
}

TEST(LineTests, ToVector) {
    Point p{1,1};
    Vector v{5,5};

    Line l(p,v);

    ASSERT_EQ(v, l.toVector());
}