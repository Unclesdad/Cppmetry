#include <gtest/gtest.h>
#include "Circle.h"

TEST(CircleTests, PerimeterIntersection) {
    Point o{0,0};
    Point a{1,0};
    Point b{1,1};
    Point c{2,1};
    Point d{1,2}; 

    Point e{0.6+0.001, 0.8+0.001};

    Point f{0.25,1};
    Point g{1,0.25};

    Point h{-1,-1};


    Circle circle(Point(), 1);

    ASSERT_TRUE(circle.intersectsPerimeter(Line(o,b)));
    ASSERT_TRUE(circle.intersectsPerimeter(Line(a,b)));
    ASSERT_TRUE(circle.intersectsPerimeter(Line(f,g)));
    ASSERT_TRUE(circle.intersectsPerimeter(Line(h,b)));
    ASSERT_TRUE(circle.intersectsPerimeter(Line(h,e)));

    ASSERT_FALSE(circle.intersectsPerimeter(Line(c,d)));
    ASSERT_FALSE(circle.intersectsPerimeter(Line(b,e)));
    ASSERT_FALSE(circle.intersectsPerimeter(Line(e,b)));
    
}