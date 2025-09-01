#include "StockExLoss.cpp"
#include "gtest/gtest.h"

using namespace std;

TEST(StockExLossTest, Positive01)
{
    Solution s;
    int stock_vals[] = {
        3, 2, 4, 2, 1, 5
    };
    int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(-3, s.process1(stock_vals, size));
}

TEST(StockExLossTest, Positive02)
{
    Solution s;
    int stock_vals[] = {
        3, 2, 10, 7, 15, 14
    };
    int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(-3, s.process1(stock_vals, size));
}

TEST(StockExLossTest, Negative01)
{
    Solution s;
    int stock_vals[] = {
        3, 4, 7, 9, 10
    };
    int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(0, s.process1(stock_vals, size));
}