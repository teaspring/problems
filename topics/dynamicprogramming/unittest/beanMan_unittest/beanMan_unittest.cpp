#include "beanMan.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::beanMan(const vector<vector<int> >& pool)
 * int Solution::beanManII(const vector<vector<int> >& pool)
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

TEST(beanManIITest, Positive01){
    Solution s;

    const int rows = 3, cols = 3;
    int poolArr[][cols] ={
        {1, 0, 1},
        {1, 1, 0},
        {0, 0, 1}
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 5;
    EXPECT_EQ(expected, s.beanManII(pool));
}

TEST(beanManIITest, Positive02){
    Solution s;

    const int rows = 4, cols = 4;
    int poolArr[][cols] ={
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 0, 1, 0},
        {1, 0, 1, 1}
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 9;
    EXPECT_EQ(expected, s.beanManII(pool));
}

TEST(beanManIITest, Positive03){
    Solution s;

    const int rows = 4, cols = 4;
    int poolArr[][cols] ={
        {1, 0, 1, 0},
        {1, 1, 1, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 1}
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 10;
    EXPECT_EQ(expected, s.beanManII(pool));
}

TEST(beanManIITest, Positive04){
    Solution s;

    const int rows = 4, cols = 4;
    int poolArr[][cols] ={
        {1, 0, 1, 0},
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 1}
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 11;
    EXPECT_EQ(expected, s.beanManII(pool));
}

TEST(beanManIITest, Positive05){
    Solution s;

    const int rows = 4, cols = 4;
    int poolArr[][cols] ={
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 12;
    EXPECT_EQ(expected, s.beanManII(pool));
}

TEST(beanManIITest, Positive10){
    Solution s;

    const int rows = 5, cols = 5;
    int poolArr[][cols] ={
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 12;
    EXPECT_EQ(expected, s.beanManII(pool));
}

TEST(beanManIITest, Positive11){
    Solution s;

    const int rows = 5, cols = 5;
    int poolArr[][cols] ={
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 1, 1},
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 16;
    EXPECT_EQ(expected, s.beanManII(pool));
}

TEST(beanManIITest, Positive12){
    Solution s;

    const int rows = 5, cols = 5;
    int poolArr[][cols] ={
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 1, 1},
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 16;
    EXPECT_EQ(expected, s.beanManII(pool));
}

TEST(beanManIITest, Positive13){
    Solution s;

    const int rows = 5, cols = 5;
    int poolArr[][cols] ={
        {1, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 1, 1},
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 16;
    EXPECT_EQ(expected, s.beanManII(pool));
}

TEST(beanManIITest, Positive14){
    Solution s;

    const int rows = 5, cols = 5;
    int poolArr[][cols] ={
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    };

    vector<vector<int> > pool;
    for(int i = 0; i < rows; i++){
        pool.push_back(vector<int>(poolArr[i], poolArr[i] + cols));
    }

    int expected = 16;
    EXPECT_EQ(expected, s.beanManII(pool));
}
