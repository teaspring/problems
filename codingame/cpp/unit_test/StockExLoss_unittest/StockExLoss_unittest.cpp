#include "StockExLoss.cpp"
#include "gtest/gtest.h"

using namespace std;

/*------ max_loss_abs() ------*/
TEST(MaxLossAbsTest, TwiceDown)
{
    Solution s;
    int stock_vals[] = { 3, 2, 4, 2, 1, 5};
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(-3, s.max_loss_abs(stock_vals, size));
}
TEST(MaxLossAbsTest, NoDown)
{
    Solution s;
    int stock_vals[] = {3, 4, 7, 9, 10};
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(0, s.max_loss_abs(stock_vals, size));
}
/*------ max_drawdown_bp() ------*/
TEST(MaxDrawdownBpTest, Positive01)
{
    Solution s;
    float stock_vals[] = {
        10.12f, 10.23f, 10.91f, 10.11f, 9.61f, 10.20f, 10.98f, 11.35f, 11.81f, 11.53f, 10.91f, 10.51f, 10.76f
    };
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    // if std::round() is used instead of implicit convert, the result is -1192 instead of -1191
    EXPECT_EQ(-1192, s.max_drawdown_bp(stock_vals, size));
}
/*------ max_drawdown_duration() ------*/
TEST(MaxDrawdownDuraTest, NoDrawdown)
{
    Solution s;
    float stock_vals[] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(0, s.max_drawdown_duration(stock_vals, size));
}

TEST(MaxDrawdownDuraTest, SingleDrawdown)
{
    Solution s;
    float stock_vals[] = { 5.0f, 4.0f, 3.0f, 2.0f, 1.0f };
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(4, s.max_drawdown_duration(stock_vals, size));
}

TEST(MaxDrawdownDuraTest, MultiDrawdowns01)
{
    Solution s;
    float stock_vals[] = { 10.1f, 9.0f, 9.3f, 9.8f, 10.2f, 9.7f, 9.6f, 9.9f };
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(4, s.max_drawdown_duration(stock_vals, size)); // 10.1 -> 10.2
}

TEST(MaxDrawdownDuraTest, LongDrawdownNotAfterPeak)
{
    Solution s;
    float stock_vals[] = {
        10.12f, 10.23f, 10.91f, 10.11f, 9.61f, 10.20f, 10.54f, 10.81f, 11.15f, 11.41f, 11.33f, 10.91f, 10.51f, 10.76f
    };
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(6, s.max_drawdown_duration(stock_vals, size)); // 10.91 -> 11.15
}

TEST(MaxDrawdownDuraTest, SingleFlat)
{
    Solution s;
    float stock_vals[] = { 5.0f, 5.0f, 5.0f, 5.0f };
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(0, s.max_drawdown_duration(stock_vals, size));
}

TEST(MaxDrawdownDuraTest, DrawdownAtEnd)
{
    Solution s;
    float stock_vals[] = { 10.0f, 12.0f, 11.0f, 9.0f, 8.0f };
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(3, s.max_drawdown_duration(stock_vals, size)); // 12.0 -> 8.0
}

TEST(MaxDrawdownDuraTest, DrawdownWithFlatDays)
{
    Solution s;
    float stock_vals[] = {10.1f, 10.1f, 9.0f, 9.3f, 9.8f, 10.1f, 10.1f, 10.2f, 9.7f, 9.6f, 9.9f};
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(4, s.max_drawdown_duration(stock_vals, size)); // 10.1[1] -> 10.1[5]
}

/*------ total_profix_abs() ------*/
TEST(TotalProfitAbsTest, SingleIncrease)
{
    Solution s;
    float stock_vals[] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(4.0, s.total_profit_abs(stock_vals, size));
}

TEST(TotalProfitAbsTest, TwiceUp)
{
    Solution s;
    float stock_vals[] = { 10.1f, 9.0f, 9.3f, 9.8f, 10.2f, 9.7f, 9.6f, 9.9f };
    const int size = sizeof(stock_vals) / sizeof(stock_vals[0]);
    EXPECT_EQ(1.5f, s.total_profit_abs(stock_vals, size));
}