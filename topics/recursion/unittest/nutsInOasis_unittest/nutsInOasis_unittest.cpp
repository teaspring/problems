#include "nutsInOasis.cpp"
#include "gtest/gtest.h"

/*
 * double Solution::getMaxNuts_01(double Nuts(N), double Destination(D), double Capacity(C), double Feed(F))
 *
 * double Solution::getMaxNuts_02(double Nuts(N), double Destination(D), double Capacity(C), double Feed(F))
 * */

static const double eps = 1e-2; // this method keep precision to 0.01

TEST(nutsInOasisTest, Function01){
    Solution s;

    double N = 3000, D = 1000, C = 1000, F = 1;
    double expected = 533.33;

    double result2 = s.getMaxNuts_2(N, D, C, F);
    EXPECT_TRUE(abs(expected - result2) < eps);

    double result1 = s.getMaxNuts_1(N, D, C, F);
    EXPECT_TRUE(abs(expected - result1) < eps);
}

TEST(nutsInOasis_Test, Function02){
    Solution s;

    double N = 3200, D = 1000, C = 1000, F = 1;
    double expected = 561.90;

    double result2 = s.getMaxNuts_2(N, D, C, F);
    EXPECT_FALSE(abs(expected - result2) < eps);

    double result1 = s.getMaxNuts_1(N, D, C, F);
    EXPECT_TRUE(abs(expected - result1) < eps);
}

TEST(nutsInOasis_Test, Function03){
    Solution s;

    double N = 3500, D = 1000, C = 1000, F = 1;
    double expected = 604.76;

    double result2 = s.getMaxNuts_2(N, D, C, F);
    EXPECT_FALSE(abs(expected - result2) < eps);

    double result1 = s.getMaxNuts_1(N, D, C, F);
    EXPECT_TRUE(abs(expected - result1) < eps);
}
