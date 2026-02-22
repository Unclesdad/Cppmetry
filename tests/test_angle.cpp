#include <gtest/gtest.h>
#include "Angle.h" 
#include <cmath>
#include "Vector.h"

TEST(AngleTests, AngleWrapping) {
    double TOLERANCE = 1e-15;

    Angle zero(0 + 1);
    Angle twopi(Angle::PI * 2 + 1);

    ASSERT_NEAR(zero.rads, twopi.rads, TOLERANCE);

    ASSERT_NEAR(zero.cosine(), twopi.cosine(), TOLERANCE);
    ASSERT_NEAR(zero.sine(), twopi.sine(), TOLERANCE);
}

TEST(AngleTests, Sine) {
    double TOLERANCE = 1e-15;

    Angle zero(0);
    Angle ninety(Angle::PI / 2);
    Angle twoSeventy(Angle::PI * 3 / 2);
    Angle fourtyFive(Angle::PI / 4);

    ASSERT_NEAR(zero.sine(), 0, TOLERANCE);
    ASSERT_NEAR(ninety.sine(), 1, TOLERANCE);
    ASSERT_NEAR(twoSeventy.sine(), -1, TOLERANCE);
    ASSERT_NEAR(fourtyFive.sine(), std::sqrt(2) / 2, TOLERANCE);
}

TEST(AngleTests, Cosine) {
    double TOLERANCE = 1e-15;

    Angle zero(0);
    Angle ninety(Angle::PI / 2);
    Angle oneEighty(Angle::PI);
    Angle fourtyFive(Angle::PI / 4);

    ASSERT_NEAR(zero.cosine(), 1, TOLERANCE);
    ASSERT_NEAR(ninety.cosine(), 0, TOLERANCE);
    ASSERT_NEAR(oneEighty.cosine(), -1, TOLERANCE);
    ASSERT_NEAR(fourtyFive.cosine(), std::sqrt(2) / 2, TOLERANCE);
}

TEST(AngleTests, Tangent) {
    double TOLERANCE = 1e-15;

    Angle zero(0);
    Angle ninety(Angle::PI / 2);
    Angle oneEighty(Angle::PI);
    Angle fourtyFive(Angle::PI / 4);

    ASSERT_NEAR(zero.tangent(), 0, TOLERANCE);
    ASSERT_NEAR(oneEighty.tangent(), 0, TOLERANCE);
    ASSERT_NEAR(fourtyFive.tangent(), 1, TOLERANCE);

    // test will fail if this crashes
    ASSERT_GT(ninety.tangent(), 1e10);
}

TEST(AngleTests, Arithmetic) {
    double TOLERANCE = 1e-15;

    Angle zero(0);
    Angle ninety(Angle::PI / 2);
    Angle fourtyFive(Angle::PI / 4);

    ASSERT_NEAR((ninety + zero).rads, ninety.rads, TOLERANCE);
    ASSERT_NEAR((ninety + fourtyFive).rads, Angle::PI * 3/4, TOLERANCE);
    ASSERT_NEAR((ninety * 5).rads, ninety.rads, TOLERANCE); // wrapping
    ASSERT_NEAR((fourtyFive * 3).rads, Angle::PI * 3/4, TOLERANCE);
}

TEST(AngleTests, UnitVector) {
    double TOLERANCE = 1e-15;
    double radTwoOverTwo = std::sqrt(2) / 2;

    Angle fourtyFive(Angle::PI / 4);
    Vector unit(fourtyFive.unit());

    ASSERT_NEAR(unit.magnitude(), 1, TOLERANCE);
    ASSERT_NEAR(unit.x, radTwoOverTwo, TOLERANCE);
    ASSERT_NEAR(unit.y, radTwoOverTwo, TOLERANCE);
}