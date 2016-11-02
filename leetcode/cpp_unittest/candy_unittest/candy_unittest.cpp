#include "candy.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::candy_01(vector<int>&), candy_02(vector<int>&)
 * */
TEST(candyTest, Positive1_01){
    Solution s;
    int arr[]     = {1, 2, 4, 4, 4, 2, 2, 2, 1};
    int candies[] = {1, 2, 3, 1, 2, 1, 1, 2, 1};

    const int n = sizeof(arr) / sizeof(int);
    vector<int> ratings(arr, arr + n);
    int expected = 0;
    for(int i = 0; i < n; i++){
        expected += candies[i];
    }

    EXPECT_EQ(expected, s.candy_1(ratings));
    ratings.clear();
}

TEST(candyTest, Positive1_02){
    Solution s;
    int arr[]     = {4, 2, 3, 4, 1};
    int candies[] = {2, 1, 2, 3, 1};

    const int n = sizeof(arr) / sizeof(int);
    vector<int> ratings(arr, arr + n);
    int expected = 0;
    for(int i = 0; i < n; i++){
        expected += candies[i];
    }

    EXPECT_EQ(expected, s.candy_1(ratings));
    ratings.clear();
}

TEST(candyTest, Positive1_03){
    Solution s;
    int arr[]     = {2, 5, 4, 3, 4, 5, 3};
    int candies[] = {1, 3, 2, 1, 2, 3, 1};

    const int n = sizeof(arr) / sizeof(int);
    vector<int> ratings(arr, arr + n);
    int expected = 0;
    for(int i = 0; i < n; i++){
        expected += candies[i];
    }

    EXPECT_EQ(expected, s.candy_1(ratings));
    ratings.clear();
}

TEST(candyTest, Positive1_04){
    Solution s;
    int arr[]     = {2, 5, 2, 3, 1, 2};
    int candies[] = {1, 2, 1, 2, 1, 2};

    const int n = sizeof(arr) / sizeof(int);
    vector<int> ratings(arr, arr + n);
    int expected = 0;
    for(int i = 0; i < n; i++){
        expected += candies[i];
    }

    EXPECT_EQ(expected, s.candy_1(ratings));
    ratings.clear();
}

TEST(candyTest, Positive2_01){
    Solution s;
    int arr[]     = {1, 2, 4, 4, 4, 2, 2, 2, 1};
    int candies[] = {1, 2, 3, 1, 2, 1, 1, 2, 1};

    const int n = sizeof(arr) / sizeof(int);
    vector<int> ratings(arr, arr + n);
    int expected = 0;
    for(int i = 0; i < n; i++){
        expected += candies[i];
    }

    EXPECT_EQ(expected, s.candy_2(ratings));
    ratings.clear();
}

TEST(candyTest, Positive2_02){
    Solution s;
    int arr[]     = {4, 2, 3, 4, 1};
    int candies[] = {2, 1, 2, 3, 1};

    const int n = sizeof(arr) / sizeof(int);
    vector<int> ratings(arr, arr + n);
    int expected = 0;
    for(int i = 0; i < n; i++){
        expected += candies[i];
    }

    EXPECT_EQ(expected, s.candy_2(ratings));
    ratings.clear();
}

TEST(candyTest, Positive2_03){
    Solution s;
    int arr[]     = {2, 5, 4, 3, 4, 5, 3};
    int candies[] = {1, 3, 2, 1, 2, 3, 1};

    const int n = sizeof(arr) / sizeof(int);
    vector<int> ratings(arr, arr + n);
    int expected = 0;
    for(int i = 0; i < n; i++){
        expected += candies[i];
    }

    EXPECT_EQ(expected, s.candy_2(ratings));
    ratings.clear();
}

TEST(candyTest, Positive2_04){
    Solution s;
    int arr[]     = {2, 5, 2, 3, 1, 2};
    int candies[] = {1, 2, 1, 2, 1, 2};

    const int n = sizeof(arr) / sizeof(int);
    vector<int> ratings(arr, arr + n);
    int expected = 0;
    for(int i = 0; i < n; i++){
        expected += candies[i];
    }

    EXPECT_EQ(expected, s.candy_2(ratings));
    ratings.clear();
}

