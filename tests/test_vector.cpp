#include <gtest/gtest.h>
#include "Vector.h"
#include <random>
#include "Angle.h"

TEST(VectorTests, Magnitude) {
    double EPS = 1e-15;

    Vector flat{1,0};
    Vector angled{3,4};
    Vector rotatedAngled{-4, 3};

    ASSERT_NEAR(flat.magnitude(), 1, EPS);
    ASSERT_NEAR(angled.magnitude(), 5, EPS);
    ASSERT_NEAR(angled.magnitude(), rotatedAngled.magnitude(), EPS);
}

TEST(VectorTests, Angles) {
    double EPS = 1e-15;

    Vector flat{1,0};
    Vector vertical{0,1};
    Vector angled{2,2};
    Vector biggerAngled{4,4};

    ASSERT_NEAR(flat.angle().rads, 0, EPS);
    ASSERT_NEAR(vertical.angle().rads, Angle::PI / 2, EPS);
    ASSERT_NEAR(angled.angle().rads, Angle::PI / 4, EPS);
    
    ASSERT_NEAR(angled.angle().rads, biggerAngled.angle().rads, EPS);
}

TEST(VectorTests, AdditionAndSubtraction) {
    Vector v{1,0};
    Vector u{0,2};
    Vector w{6,-7};

    ASSERT_EQ(v+u, Vector(1,2));

    ASSERT_EQ(u+w, Vector(6,-5));

    ASSERT_EQ(u-w, Vector(-6, 9));

    ASSERT_EQ(w+u,u+w);
    ASSERT_EQ(w-u, -1 * (u-w));

    ASSERT_EQ(w+(-1*u), w-u);

}

TEST(VectorTests, ScalarMultiplication) {
    Vector v{2,3};
    Vector u{-5,6};

    ASSERT_EQ(2 * v, v * 2);

    ASSERT_EQ(v * 3, Vector(6,9));

    ASSERT_EQ(10 * u, Vector(-50,60));
}

TEST(VectorTests, DotProduct) {
    double EPS = 1e-15;

    Vector v{1,2};
    Vector u{7,8};
    Vector w{-2, 1};

    ASSERT_NEAR(v.dot(u), u.dot(v), EPS);
    ASSERT_NEAR(v.dot(w), 0, EPS);

    ASSERT_NEAR(v.dot(u), 23, EPS);

    ASSERT_NEAR(w.dot(w), w.magnitude() * w.magnitude(), EPS);

    ASSERT_NEAR(u.dot(w), u.magnitude() * w.magnitude() * (u.angle() - w.angle()).cosine(), EPS);
}

TEST(VectorTests, CrossProduct) {
    double EPS = 1e-12;

    Vector v{1,2};
    Vector u{7,8};
    Vector w{-2, 1};

    ASSERT_NEAR(v.cross(u), -1 * u.cross(v), EPS);
    ASSERT_NEAR(v.cross(w), v.magnitude() * w.magnitude(), EPS);

    ASSERT_NEAR(v.cross(u), -6, EPS);

    ASSERT_NEAR(w.cross(w), 0, EPS);

    ASSERT_NEAR(u.cross(w), u.magnitude() * w.magnitude() * (w.angle() - u.angle()).sine(), EPS);
}

TEST(VectorTests, Projection) {
    Vector v{1,0};
    Vector u{1,1};
    Vector w{2,2};

    ASSERT_EQ(u.projectOnto(v), v);
    ASSERT_EQ(w.projectOnto(v), 2 * v);
    ASSERT_EQ(v.projectOnto(u), v.projectOnto(w));
}

TEST(VectorTests, UnitVectors) {
    double EPS = 1e-12;

    Vector v{1,0};
    Vector u{1,1};
    Vector w{-1,-1};
    Vector r{1,2};

    double sqrtTwoOverTwo = std::sqrt(2) / 2;

    ASSERT_EQ(v.unit(), v);
    ASSERT_NEAR((u.unit() - Vector(sqrtTwoOverTwo, sqrtTwoOverTwo)).magnitude(), 0, EPS);
    ASSERT_NEAR((w.unit() - Vector(-sqrtTwoOverTwo,-sqrtTwoOverTwo)).magnitude(), 0, EPS);
    ASSERT_EQ(r.unit(), (r * 4).unit());
}