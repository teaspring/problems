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

/*----- int getAllProfit(const vector<int>&, int&) -----*/
TEST(getAllProfitTest, Positive01) {
    Solution s;

    int arr[] = {1, 2, 4, 3, 1, 2, 3, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int expectedCount = 3;
    int expectedSum = 8; // [buy,0,sell,0,buy,0,sell,buy,sell]

    int cnt = 0;
    int sum = s.getAllProfit(prices, cnt);
    EXPECT_EQ(expectedCount, cnt);
    EXPECT_EQ(expectedSum, sum);

    prices.clear();
}

TEST(getAllProfitTest, Positive02) {
    Solution s;

    int arr[] = {3, 2, 2, 1, 1, 2, 4, 4, 3, 1, 2, 2, 3, 3, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int expectedCount = 3;
    int expectedSum = 8;

    int cnt = 0;
    int sum = s.getAllProfit(prices, cnt);
    EXPECT_EQ(expectedCount, cnt);
    EXPECT_EQ(expectedSum, sum);

    prices.clear();
}

/*----- int maxProfitIV_01(int, const vector<int>&) -----*/
TEST(maxstockprofitIV01_Test, Positive01) {
    Solution s;

    int arr[] = {3, 2, 2, 1, 1, 2, 4, 4, 3, 1, 2, 2, 3, 3, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 3;
    int expected = 8; // [buy,0,sell,0,buy,0,sell,buy,sell]
    EXPECT_EQ(expected, s.maxProfitIV_01(k, prices));

    k = 4;
    EXPECT_EQ(expected, s.maxProfitIV_01(k, prices));

    prices.clear();
}

TEST(maxstockprofitIV01_Test, Positive02) {
    Solution s;

    int arr[] = {3, 2, 1, 2, 2, 4, 3, 1, 2, 2, 3, 3, 2, 1, 2, 4, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 2;
    int expected = 7;
    EXPECT_EQ(expected, s.maxProfitIV_01(k, prices));

    prices.clear();
}

TEST(maxstockprofitIV01_Test, Positive03) {
    Solution s;

    int arr[] = {3, 2, 1, 2, 2, 4, 3, 1, 2, 2, 3, 3, 2, 1, 2, 4, 2, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 3;
    int expected = 9;
    EXPECT_EQ(expected, s.maxProfitIV_01(k, prices));

    prices.clear();
}

TEST(maxstockprofitIV01_Test, Positive04) {
    Solution s;

    int arr[] = {3, 2, 1, 2, 2, 4, 3, 1, 2, 2, 3, 3, 2, 1, 2, 4, 2, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 4;
    int expected = 11;
    EXPECT_EQ(expected, s.maxProfitIV_01(k, prices));

    prices.clear();
}

TEST(maxstockprofitIV01_Test, Positive05) {
    Solution s;

    int arr[] = {1,2,2,4,4,5,3,2,7,4,6,9,2,1,5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 1;
    int expected = 8;
    EXPECT_EQ(expected, s.maxProfitIV_01(k, prices));

    k = 2;
    expected = 12;
    EXPECT_EQ(expected, s.maxProfitIV_01(k, prices));

    k = 3;
    expected = 15;
    EXPECT_EQ(expected, s.maxProfitIV_01(k, prices));

    k = 4;
    expected = 18;
    EXPECT_EQ(expected, s.maxProfitIV_01(k, prices));

    k = 5;
    expected = 18;
    EXPECT_EQ(expected, s.maxProfitIV_01(k, prices));

    prices.clear();
}

/*----- int maxProfitIV_02(int, const vector<int>&) -----*/
TEST(maxstockprofitIV02_Test, Positive01) {
    Solution s;

    int arr[] = {3, 2, 2, 1, 1, 2, 4, 4, 3, 1, 2, 2, 3, 3, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 3;
    int expected = 8; // [buy,0,sell,0,buy,0,sell,buy,sell]
    EXPECT_EQ(expected, s.maxProfitIV_02(k, prices));

    k = 4;
    EXPECT_EQ(expected, s.maxProfitIV_02(k, prices));

    prices.clear();
}

TEST(maxstockprofitIV02_Test, Positive02) {
    Solution s;

    int arr[] = {3, 2, 1, 2, 2, 4, 3, 1, 2, 2, 3, 3, 2, 1, 2, 4, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 2;
    int expected = 7;
    EXPECT_EQ(expected, s.maxProfitIV_02(k, prices));

    prices.clear();
}

TEST(maxstockprofitIV02_Test, Positive03) {
    Solution s;

    int arr[] = {3, 2, 1, 2, 2, 4, 3, 1, 2, 2, 3, 3, 2, 1, 2, 4, 2, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 3;
    int expected = 9;
    EXPECT_EQ(expected, s.maxProfitIV_02(k, prices));

    prices.clear();
}

TEST(maxstockprofitIV02_Test, Positive04) {
    Solution s;

    int arr[] = {3, 2, 1, 2, 2, 4, 3, 1, 2, 2, 3, 3, 2, 1, 2, 4, 2, 2, 5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 4;
    int expected = 11;
    EXPECT_EQ(expected, s.maxProfitIV_02(k, prices));

    prices.clear();
}

TEST(maxstockprofitIV02_Test, Positive05) {
    Solution s;

    int arr[] = {1,2,2,4,4,5,3,2,7,4,6,9,2,1,5};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));

    int k = 1;
    int expected = 8;
    EXPECT_EQ(expected, s.maxProfitIV_02(k, prices));

    k = 2;
    expected = 12;
    EXPECT_EQ(expected, s.maxProfitIV_02(k, prices));

    k = 3;
    expected = 15;
    EXPECT_EQ(expected, s.maxProfitIV_02(k, prices));

    k = 4;
    expected = 18;
    EXPECT_EQ(expected, s.maxProfitIV_02(k, prices));

    k = 5;
    expected = 18;
    EXPECT_EQ(expected, s.maxProfitIV_02(k, prices));

    prices.clear();
}
