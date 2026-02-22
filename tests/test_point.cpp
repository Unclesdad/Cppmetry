#include <gtest/gtest.h>
#include "Point.h"

TEST(PointTests, Subtraction) {
    Point pt1{1, 0};
    Point pt2{0, 2};

    Vector diff(pt2 - pt1);

    ASSERT_EQ(diff.x, -1);
    ASSERT_EQ(diff.y, 2);
}

TEST(PointTests, Addition) {
    Point pt1{1, 2};
    Vector v{5, 7};

    Point result = pt1 + v;

    ASSERT_EQ(result.x, 6);
    ASSERT_EQ(result.y, 9);
}