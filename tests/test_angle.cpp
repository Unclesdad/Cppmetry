#include <gtest/gtest.h>
#include "Angle.h" 
#include <cmath>
#include "Vector.h"

TEST(AngleTests, AngleWrapping) {
    double EPS = 1e-15;

    Angle zero(0 + 1);
    Angle twopi(Angle::PI * 2 + 1);

    ASSERT_NEAR(zero.rads, twopi.rads, EPS);

    ASSERT_NEAR(zero.cosine(), twopi.cosine(), EPS);
    ASSERT_NEAR(zero.sine(), twopi.sine(), EPS);
}

TEST(AngleTests, Sine) {
    double EPS = 1e-15;

    Angle zero(0);
    Angle ninety(Angle::PI / 2);
    Angle twoSeventy(Angle::PI * 3 / 2);
    Angle fourtyFive(Angle::PI / 4);

    ASSERT_NEAR(zero.sine(), 0, EPS);
    ASSERT_NEAR(ninety.sine(), 1, EPS);
    ASSERT_NEAR(twoSeventy.sine(), -1, EPS);
    ASSERT_NEAR(fourtyFive.sine(), std::sqrt(2) / 2, EPS);
}

TEST(AngleTests, Cosine) {
    double EPS = 1e-15;

    Angle zero(0);
    Angle ninety(Angle::PI / 2);
    Angle oneEighty(Angle::PI);
    Angle fourtyFive(Angle::PI / 4);

    ASSERT_NEAR(zero.cosine(), 1, EPS);
    ASSERT_NEAR(ninety.cosine(), 0, EPS);
    ASSERT_NEAR(oneEighty.cosine(), -1, EPS);
    ASSERT_NEAR(fourtyFive.cosine(), std::sqrt(2) / 2, EPS);
}

TEST(AngleTests, Tangent) {
    double EPS = 1e-15;

    Angle zero(0);
    Angle ninety(Angle::PI / 2);
    Angle oneEighty(Angle::PI);
    Angle fourtyFive(Angle::PI / 4);

    ASSERT_NEAR(zero.tangent(), 0, EPS);
    ASSERT_NEAR(oneEighty.tangent(), 0, EPS);
    ASSERT_NEAR(fourtyFive.tangent(), 1, EPS);

    // test will fail if this crashes
    ASSERT_GT(ninety.tangent(), 1e10);
}

TEST(AngleTests, Arithmetic) {
    double EPS = 1e-15;

    Angle zero(0);
    Angle ninety(Angle::PI / 2);
    Angle fourtyFive(Angle::PI / 4);

    ASSERT_NEAR((ninety + zero).rads, ninety.rads, EPS);
    ASSERT_NEAR((ninety + fourtyFive).rads, Angle::PI * 3/4, EPS);
    ASSERT_NEAR((ninety * 5).rads, ninety.rads, EPS); // wrapping
    ASSERT_NEAR((fourtyFive * 3).rads, Angle::PI * 3/4, EPS);
}

TEST(AngleTests, UnitVector) {
    double EPS = 1e-15;
    double radTwoOverTwo = std::sqrt(2) / 2;

    Angle fourtyFive(Angle::PI / 4);
    Vector unit(fourtyFive.unit());

    ASSERT_NEAR(unit.magnitude(), 1, EPS);
    ASSERT_NEAR(unit.x, radTwoOverTwo, EPS);
    ASSERT_NEAR(unit.y, radTwoOverTwo, EPS);
}