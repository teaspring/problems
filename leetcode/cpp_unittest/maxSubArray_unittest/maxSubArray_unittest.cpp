#include "maxSubArray.cpp"
#include "gtest/gtest.h"

/*
 * int maxSubArray_01(int[], int n)
 * int maxSubArray_02(int[], int n)
 * int maxSubArray_03(int[], int n)
 * int maxSubArray_04(int[], int n)
 * */

/* ------------ maxSubArray_01() test cases ------------ */
TEST(maxSubArray01_Test, Positive01){
    Solution s;

    int arr[] = {-1};
    const int n = sizeof(arr) / sizeof(int);

    int expected = -1;

    EXPECT_EQ(expected, s.maxSubArray_01(arr, n));
}

TEST(maxSubArray01_Test, Positive02){
    Solution s;

    int arr[] = {-2, -3, -4, -1, -2};
    const int n = sizeof(arr) / sizeof(int);

    int expected = -1;

    EXPECT_EQ(expected, s.maxSubArray_01(arr, n));
}

TEST(maxSubArray01_Test, Positive03){
    Solution s;

    int arr[] = {-1, 4, -2, 3, 1, -2};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 6;

    EXPECT_EQ(expected, s.maxSubArray_01(arr, n));
}

TEST(maxSubArray01_Test, Positive04){
    Solution s;

    int arr[] = {2, 2, -4, 1, 2, -1};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 4;

    EXPECT_EQ(expected, s.maxSubArray_01(arr, n));
}

/* ------------ maxSubArray_02() test cases ------------ */
TEST(maxSubArray02_Test, Positive01){
    Solution s;

    int arr[] = {-1};
    const int n = sizeof(arr) / sizeof(int);

    int expected = -1;

    EXPECT_EQ(expected, s.maxSubArray_02(arr, n));
}

TEST(maxSubArray02_Test, Positive02){
    Solution s;

    int arr[] = {-2, -3, -4, -1, -2};
    const int n = sizeof(arr) / sizeof(int);

    int expected = -1;

    EXPECT_EQ(expected, s.maxSubArray_02(arr, n));
}

TEST(maxSubArray02_Test, Positive03){
    Solution s;

    int arr[] = {-1, 4, -2, 3, 1, -2};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 6;

    EXPECT_EQ(expected, s.maxSubArray_02(arr, n));
}

TEST(maxSubArray02_Test, Positive04){
    Solution s;

    int arr[] = {2, 2, -4, 1, 2, -1};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 4;

    EXPECT_EQ(expected, s.maxSubArray_02(arr, n));
}

/* ------------ maxSubArray_03() test cases ------------ */
TEST(maxSubArray03_Test, Positive01){
    Solution s;

    int arr[] = {-1};
    const int n = sizeof(arr) / sizeof(int);

    int expected = -1;

    EXPECT_EQ(expected, s.maxSubArray_03(arr, n));
}

TEST(maxSubArray03_Test, Positive02){
    Solution s;

    int arr[] = {-2, -3, -4, -1, -2};
    const int n = sizeof(arr) / sizeof(int);

    int expected = -1;

    EXPECT_EQ(expected, s.maxSubArray_03(arr, n));
}

TEST(maxSubArray03_Test, Positive03){
    Solution s;

    int arr[] = {-1, 4, -2, 3, 1, -2};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 6;

    EXPECT_EQ(expected, s.maxSubArray_03(arr, n));
}

TEST(maxSubArray03_Test, Positive04){
    Solution s;

    int arr[] = {2, 2, -4, 1, 2, -1};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 4;

    EXPECT_EQ(expected, s.maxSubArray_03(arr, n));
}

/* ------------ maxSubArray_04() test cases ------------ */
TEST(maxSubArray04_Test, Positive01){
    Solution s;

    int arr[] = {-1};
    const int n = sizeof(arr) / sizeof(int);

    int expected = -1;

    EXPECT_EQ(expected, s.maxSubArray_04(arr, n));
}

TEST(maxSubArray04_Test, Positive02){
    Solution s;

    int arr[] = {-2, -3, -4, -1, -2};
    const int n = sizeof(arr) / sizeof(int);

    int expected = -1;

    EXPECT_EQ(expected, s.maxSubArray_04(arr, n));
}

TEST(maxSubArray04_Test, Positive03){
    Solution s;

    int arr[] = {-1, 4, -2, 3, 1, -2};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 6;

    EXPECT_EQ(expected, s.maxSubArray_04(arr, n));
}

TEST(maxSubArray04_Test, Positive04){
    Solution s;

    int arr[] = {2, 2, -4, 1, 2, -1};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 4;

    EXPECT_EQ(expected, s.maxSubArray_04(arr, n));
}
