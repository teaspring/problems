#include "kthPermutation.cpp"
#include "gtest/gtest.h"

/*
 * n is in [1, 9], k is 1-based and in [1, n!]
 *
 * string Solution::getPermutation(int n, int k)
 * */

TEST(kthPermutationTest, Positive01){
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
        EXPECT_STREQ(expected.c_str(), s.getPermutation(n, k).c_str());
    }
}
