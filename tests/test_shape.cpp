#include <gtest/gtest.h>
#include "Circle.h"
#include "Polygon.h"

TEST(ShapeTests, CircleLineContainment) {
    Point o{0,0};
    Point a{-1,1};
    Point b1{0.99,0};
    Point b2{1.01,0};
    Point c{0.25,0.25};
    Point d{0,2};
    Point e{0,3};

    Circle circle(o, 1);

    ASSERT_EQ(circle.lineInside(Line(o,a)), Shape::PARTIAL);
    ASSERT_EQ(circle.lineInside(Line(o,b2)), Shape::PARTIAL);
    ASSERT_EQ(circle.lineInside(Line(o,c)), Shape::CONTAINED);
    ASSERT_EQ(circle.lineInside(Line(a,b2)), Shape::PARTIAL);
    ASSERT_EQ(circle.lineInside(Line(a,d)), Shape::SEPARATE);
    ASSERT_EQ(circle.lineInside(Line(d,e)), Shape::SEPARATE);
}

TEST(ShapeTests, PolygonLineContainment) {
    Point o{0,0};
    Point a{4,0};
    Point b{0.5,0.5};
    Point c{4,1};
    Point d{0,1};

    Polygon poly{o,a,b,c,d};

    Point e{0.75,0.5};
    Point f{3,0.5};
    ASSERT_EQ(poly.lineInside(Line(e,f)), Shape::SEPARATE);

    Point g{3.9,0.25};
    Point h{3.9, 0.75};
    ASSERT_EQ(poly.lineInside(Line(g,h)), Shape::SEPARATE);

    Point i{-1,-1};
    Point j{0.25,0.25};
    ASSERT_EQ(poly.lineInside(Line(i,j)), Shape::PARTIAL);

    Point k{0.25, 0.5};
    ASSERT_EQ(poly.lineInside(Line(j,k)), Shape::CONTAINED);

    Point l{0.75, 0.25};
    ASSERT_EQ(poly.lineInside(Line(j,l)), Shape::CONTAINED);

    Point m{1,-0.5};
    Point n{1, 1.5};
    ASSERT_EQ(poly.lineInside(Line(m,n)), Shape::PARTIAL);

    Point p{3,-1};
    Point q{1,-1};
    ASSERT_EQ(poly.lineInside(Line(p,q)), Shape::SEPARATE);
}