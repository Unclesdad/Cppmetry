#include <gtest/gtest.h>
#include "Shape.h"
#include "Circle.h"

TEST(ShapeTests, CircleLineContainment) {
    Point o{0,0};
    Point a{-1,1};
    Point b1{0.99,0};
    Point b2{1.01,0};
    Point c{0.25,0.25};
    Point d{0,2};
    Point e{0,3};

    Circle circle(Point(), 1);

    ASSERT_EQ(circle.lineInside(Line(o,a)), Shape::PARTIAL);
    ASSERT_EQ(circle.lineInside(Line(o,b2)), Shape::PARTIAL);
    ASSERT_EQ(circle.lineInside(Line(o,c)), Shape::CONTAINED);
    ASSERT_EQ(circle.lineInside(Line(a,b2)), Shape::PARTIAL);
    ASSERT_EQ(circle.lineInside(Line(a,d)), Shape::SEPARATE);
    ASSERT_EQ(circle.lineInside(Line(d,e)), Shape::SEPARATE);
}