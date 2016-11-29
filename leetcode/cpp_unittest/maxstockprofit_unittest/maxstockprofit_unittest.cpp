#include "maxstockprofit.cpp"
#include "gtest/gtest.h"

/*----- int maxProfitIII(const vector<int>&) -----*/
TEST(maxstockprofitIIITest, Positive01){
    Solution s;

    int arr[] = {1, 2, 4, 3, 1, 2, 3, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int expected = 7; //[buy,0,sell,0,buy,0,0,0,sell]
    EXPECT_EQ(expected, s.maxProfitIII(prices));

    prices.clear();
}

/*----- int getAllAvailableProfit(const vector<int>&, int&) -----*/
TEST(getAllAvailableProfitTest, Positive01) {
    Solution s;

    int arr[] = {1, 2, 4, 3, 1, 2, 3, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int expectedCount = 3;
    int expectedSum = 8; // [buy,0,sell,0,buy,0,sell,buy,sell]

    int cnt = 0;
    int sum = s.getAllAvailableProfit(prices, cnt);
    EXPECT_EQ(expectedCount, cnt);
    EXPECT_EQ(expectedSum, sum);

    prices.clear();
}

TEST(getAllAvailableProfitTest, Positive02) {
    Solution s;

    int arr[] = {3, 2, 2, 1, 1, 2, 4, 4, 3, 1, 2, 2, 3, 3, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int expectedCount = 3;
    int expectedSum = 8;

    int cnt = 0;
    int sum = s.getAllAvailableProfit(prices, cnt);
    EXPECT_EQ(expectedCount, cnt);
    EXPECT_EQ(expectedSum, sum);

    prices.clear();
}

/*----- int maxProfitIV(int, const vector<int>&) -----*/
TEST(maxstockprofitIVTest, Positive01) {
    Solution s;

    int arr[] = {3, 2, 2, 1, 1, 2, 4, 4, 3, 1, 2, 2, 3, 3, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 3;
    int expected = 8; // [buy,0,sell,0,buy,0,sell,buy,sell]
    EXPECT_EQ(expected, s.maxProfitIV(k, prices));

    k = 4;
    EXPECT_EQ(expected, s.maxProfitIV(k, prices));

    prices.clear();
}

TEST(maxstockprofitIVTest, Positive02) {
    Solution s;

    int arr[] = {3, 2, 1, 2, 2, 4, 3, 1, 2, 2, 3, 3, 2, 1, 2, 4, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 2;
    int expected = 7;
    EXPECT_EQ(expected, s.maxProfitIV(k, prices));

    prices.clear();
}

TEST(maxstockprofitIVTest, Positive03) {
    Solution s;

    int arr[] = {3, 2, 1, 2, 2, 4, 3, 1, 2, 2, 3, 3, 2, 1, 2, 4, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 3;
    int expected = 9;
    EXPECT_EQ(expected, s.maxProfitIV(k, prices));

    prices.clear();
}
