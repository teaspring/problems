#include "maxstockprofit.cpp"
#include "gtest/gtest.h"

/* int Solution::maxProfitIII(const vector<int>& prices) */

TEST(maxstockprofitTest, Positive01){
    Solution s;

    int arr[] = {1, 2, 4, 3, 1, 2, 3, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr) / sizeof(int));

    int expected = 7;
    EXPECT_EQ(expected, s.maxProfitIII(prices));
}
