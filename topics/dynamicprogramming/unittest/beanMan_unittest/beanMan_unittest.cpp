#include "beanMan.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::beanMan(vector<vector<int> >& pool)
 *
 * */
TEST(beanManTest, Positive01){
    Solution s;

    const int rows = 6, cols = 6;
    int poolArr[][cols] ={
        {1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 1},
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 0}
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 8;
    EXPECT_EQ(expected, s.beanMan(pool));
}
