#include "uniquePaths.cpp"
#include "gtest/gtest.h"

/*
 * int uniquePaths_01(int m, int n)
 * int uniquePaths_02(int m, int n)
 * */

/* ---------- solution 1 test cases ---------- */
TEST(uniquePaths01_Test, Positive01){
    Solution s;

    int m = 3, n = 3;

    int expected = 6;

    EXPECT_EQ(expected, s.uniquePaths_01(m, n));
}

TEST(uniquePaths01_Test, Positive02){
    Solution s;

    int m = 5, n = 4;

    int expected = 35;

    EXPECT_EQ(expected, s.uniquePaths_01(m, n));
}

/* ---------- solution 2 test cases ---------- */
TEST(uniquePaths02_Test, Positive01){
    Solution s;

    int m = 3, n = 3;

    int expected = 6;

    EXPECT_EQ(expected, s.uniquePaths_02(m, n));
}

TEST(uniquePaths02_Test, Positive02){
    Solution s;

    int m = 5, n = 4;

    int expected = 35;

    EXPECT_EQ(expected, s.uniquePaths_02(m, n));
}
