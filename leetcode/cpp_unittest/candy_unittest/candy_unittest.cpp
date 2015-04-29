#include "candy.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::candy(vector<int>&)
 * */

TEST(candyTest, Positive01){
    Solution s;

    int arr[]     = {1, 2, 4, 4, 4, 2, 2, 2, 1};
    int candies[] = {1, 2, 3, 1, 2, 1, 1, 2, 1};

    const int n = sizeof(arr) / sizeof(int);

    vector<int> ratings(arr, arr + n);

    int expected = 0;
    for(int i = 0; i < n; i++){
        expected += candies[i];
    }

    EXPECT_EQ(expected, s.candy(ratings));

    ratings.clear();
}
