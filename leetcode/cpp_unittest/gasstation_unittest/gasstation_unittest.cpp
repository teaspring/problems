#include "gasstation.cpp"
#include "gtest/gtest.h"

/* int Solution::gasstation(vector<int>& gas, vector<int>& cost) */

TEST(gasstationTest, Positive01){
    Solution s;

    int gasArr[]  = {1, 2, 3, 4, 5};
    vector<int> gas(gasArr, gasArr + sizeof(gasArr)/sizeof(int));
    int costArr[] = {3, 4, 5, 1, 2};
    vector<int> cost(costArr, costArr + sizeof(costArr)/sizeof(int));

    int expected = 3;
    EXPECT_EQ(expected, s.gasstation(gas, cost));

    gas.clear();
    cost.clear();
}

TEST(gasstationTest, Positive02){
    Solution s;

    int gasArr[]  = {1, 2};
    vector<int> gas(gasArr, gasArr + sizeof(gasArr)/sizeof(int));
    int costArr[] = {2, 1};
    vector<int> cost(costArr, costArr + sizeof(costArr)/sizeof(int));

    int expected = 1;
    EXPECT_EQ(expected, s.gasstation(gas, cost));

    gas.clear();
    cost.clear();
}

TEST(gasstationTest, Negative01){
    Solution s;

    int gasArr[]  = {1};
    vector<int> gas(gasArr, gasArr + sizeof(gasArr)/sizeof(int));
    int costArr[] = {2};
    vector<int> cost(costArr, costArr + sizeof(costArr)/sizeof(int));

    int expected = -1;
    EXPECT_EQ(expected, s.gasstation(gas, cost));

    gas.clear();
    cost.clear();
}

TEST(gasstationTest, Negative02){
    Solution s;

    int gasArr[]  = {1, 2, 3};
    vector<int> gas(gasArr, gasArr + sizeof(gasArr)/sizeof(int));
    int costArr[] = {3, 2, 3};
    vector<int> cost(costArr, costArr + sizeof(costArr)/sizeof(int));

    int expected = -1;
    EXPECT_EQ(expected, s.gasstation(gas, cost));

    gas.clear();
    cost.clear();
}
