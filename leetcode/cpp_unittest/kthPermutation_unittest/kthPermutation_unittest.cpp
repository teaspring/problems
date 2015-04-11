#include "kthPermutation.cpp"
#include "gtest/gtest.h"

/*
 * n is in [1, 9], k is 1-based and in [1, n!]
 *
 * string Solution::getPermutation_1(int n, int k)
 * string Solution::getPermutation_2(int n, int k)
 * */

TEST(solution1_Test, Positive01){
    Solution s;

    int n = 3;
    string answers[] = {
        "123",
        "132",
        "213",
        "231",
        "312",
        "321"};

    for(int k = 1; k < 7; k++){
        string expected = answers[k-1];
        EXPECT_STREQ(expected.c_str(), s.getPermutation_1(n, k).c_str());
    }
}

TEST(solution2_Test, Positive01){
    Solution s;

    int n = 3;
    string answers[] = {
        "123",
        "132",
        "213",
        "231",
        "312",
        "321"};

    for(int k = 1; k < 7; k++){
        string expected = answers[k-1];
        EXPECT_STREQ(expected.c_str(), s.getPermutation_2(n, k).c_str());
    }
}

TEST(solution2_Test, Positive02){
    Solution s;

    int n = 7;
    const int maxK = s.nFactorial(n) + 1;

    for(int k = 1; k < maxK; k++){
        string expected = s.getPermutation_1(n, k);
        string result   = s.getPermutation_2(n, k);
        EXPECT_STREQ(expected.c_str(), result.c_str());
    }
}
