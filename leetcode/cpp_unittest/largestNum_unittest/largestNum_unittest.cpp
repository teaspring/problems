#include "largestNum.cpp"
#include "gtest/gtest.h"

TEST(Function_Test, Positive01){
    Solution s;

    int arr[] = {3, 30, 34, 5, 9};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));

    string expected("9534330");
    string result = s.largestNumber(num);
    EXPECT_EQ(expected, result);

    num.clear();
}

TEST(Function_Test, Positive02){
    Solution s;

    int arr[] = {824, 8247};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));

    string expected("8248247");
    string result = s.largestNumber(num);
    EXPECT_EQ(expected, result);

    num.clear();
}

TEST(Function_Test, Positive03){
    Solution s;

    int arr[] = {12, 121};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));

    string expected("12121");
    string result = s.largestNumber(num);
    EXPECT_EQ(expected, result);

    num.clear();
}

TEST(Function_Test, Positive04){
    Solution s;

    int arr[] = {12, 121, 122};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));

    string expected("12212121");
    string result = s.largestNumber(num);
    EXPECT_EQ(expected, result);

    num.clear();
}

// very good unit test case which is not in scope of oj.leetcode judge :)
TEST(Function_Test, Positive05){
    Solution s;

    int arr[] = {121, 12113};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));

    string expected("12113121");
    string result = s.largestNumber(num);
    EXPECT_EQ(expected, result);

    num.clear();
}

// spawned case of Positive05
TEST(Function_Test, Positive06){
    Solution s;

    int arr[] = {121, 1211212};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));

    string expected("1211212121");
    string result = s.largestNumber(num);
    EXPECT_EQ(expected, result);

    num.clear();
}

TEST(Edge_Test, Zero){
    Solution s;

    int arr[] = {1, 2, 0, 0, 3};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));

    string expected("32100");
    string result = s.largestNumber(num);
    EXPECT_EQ(expected, result);

    num.clear();
}

TEST(Edge_Test, AllZero){
    Solution s;

    int arr[] = {0, 0, 0, 0};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));

    string expected("0");
    string result = s.largestNumber(num);
    EXPECT_EQ(expected, result);

    num.clear();
}

TEST(Edge_Test, MultiZero){
    Solution s;

    int arr[] = {0, 0, 0, 1, 0};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));

    string expected("10000");
    string result = s.largestNumber(num);
    EXPECT_EQ(expected, result);

    num.clear();
}
